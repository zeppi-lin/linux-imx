/*
 * Copyright (C) 2011-2015 Freescale Semiconductor, Inc. All Rights Reserved.
 */

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/ctype.h>
#include <linux/types.h>
#include <linux/delay.h>
#include <linux/clk.h>
#include <linux/of_device.h>
#include <linux/i2c.h>
#include <linux/of_gpio.h>
#include <linux/pinctrl/consumer.h>
#include <linux/regulator/consumer.h>
#include <linux/fsl_devices.h>
#include <linux/mipi_csi2.h>
#include <media/v4l2-chip-ident.h>
#include "v4l2-int-device.h"
#include "mxc_v4l2_capture.h"
#include "ar0521.h"


#define AR0521_VOLTAGE_ANALOG               2800000
#define AR0521_VOLTAGE_DIGITAL_CORE         1500000
#define AR0521_VOLTAGE_DIGITAL_IO           2800000

#define MIN_FPS 15
#define MAX_FPS 60
#define DEFAULT_FPS 27

#define AR0521_XCLK_MIN 27000000
#define AR0521_XCLK_MAX 27000000

#define AR0521_CHIP_ID_HIGH_BYTE	0x0000
#define AR0521_CHIP_ID_LOW_BYTE		0x0001



enum ar0521_mode {
	ar0521_mode_MIN = 0,
	ar0521_mode_VGA = 0,
	ar0521_mode_1280x720 = 1,
	ar0521_mode_1928x1088 = 2,
	ar0521_mode_2560x1440 = 3,
	ar0521_mode_2600x1952 = 4,




	// ar0521_mode_320x240 = 2,						 

	ar0521_mode_MAX = 4,
	ar0521_mode_INIT = 0xff, /*only for sensor init*/
};

enum ar0521_frame_rate {
	//ar0521_27_fps,
	//ar0521_30_fps,
	// ar0521_50_fps,
	//ar0521_60_fps,
	// ar0521_90_fps,
	// ar0521_120_fps,
	// ar0521_13_fps,
	// ar0521_16_fps,
	 ar0521_27_fps,
	// ar0521_28_fps,
	// ar0521_32_fps,
	// ar0521_51p2_fps,
	// ar0521_56_fps,
	// ar0521_86_fps
};



static int ar0521_framerates[] = {
//	[ar0521_25_fps] = 25,
	//[ar0521_30_fps] = 30,
//	[ar0521_50_fps] = 50,
	//[ar0521_60_fps] = 60,
	// [ar0521_90_fps] = 90,
	// [ar0521_120_fps] = 120,
	// [ar0521_13_fps] = 13,
	// [ar0521_16_fps] = 16,
	[ar0521_27_fps] = 27,
	// [ar0521_28_fps] = 28,
	// [ar0521_32_fps] = 32,
	// [ar0521_51p2_fps] = 51,
	// [ar0521_56_fps] = 56,
	// [ar0521_86_fps] = 86,
}; 

struct reg_value {
	u16 u16RegAddr;
	u16 u16Val;
	u16 u16Mask;
	u32 u32Delay_ms;
	u16 u16Bytes;
};

//#include "vga-60fps-4lanes.h"

struct ar0521_mode_info {
	enum ar0521_mode mode;
	u32 width;
	u32 height;
	struct reg_value *init_data_ptr;
	u32 init_data_size;
};

/*!
 * Maintains the information on the current state of the sensor.
 */
 
 static int             mytest = 0;
 
module_param(mytest, int , 0);
MODULE_PARM_DESC(mytest, "This byte sets test bars.");

// static int             mylanes = 4;
 
//module_param(mylanes, int , 0);
//MODULE_PARM_DESC(mylanes, "This byte sets mipi lanes.");

 static int             mycapmode = 0;
 
module_param(mycapmode, int , 0);
MODULE_PARM_DESC(mycapmode, "This byte sets capturemode.");

 static int             myred = 0;
 
module_param(myred, int , 0);
MODULE_PARM_DESC(myred, "This byte sets red color.");
 static int             myblue = 0;
 
module_param(myblue, int , 0);
MODULE_PARM_DESC(myblue, "This byte sets blue color.");
 static int             mygreenr = 0;
 
module_param(mygreenr, int , 0);
MODULE_PARM_DESC(mygreenr, "This byte sets green red color.");
 static int             mygreenb = 0;
 
module_param(mygreenb, int , 0);
MODULE_PARM_DESC(mygreenb, "This byte sets green blue color.");
 
static struct sensor_data ar0521_data;
static int pwn_gpio, rst_gpio;

// static struct reg_value ar0521_init_setting_120fps_VGA[] = {
// AR0521_Native_Full_120FPS_VGA_mode_10bit 
// };


// static struct reg_value ar0521_setting_50FPS_2600x1952_10bit[] = {
	// AR0521_Native_Full_50FPS_2600x1952_10bit
// };
// static struct reg_value ar0521_setting_60FPS_1928x1088_10bit_2[] = {
	// AR0521_Native_1080p_60FPS_1928x1088_10bit_2
// };
// static struct reg_value ar0521_setting_60FPS_1928x1088_10bit[] = {
	// AR0521_Native_1080p_60FPS_1928x1088_10bit
// };
// static struct reg_value ar0521_setting_60FPS_2560x1440_10bit[] = {
	// AR0521_Native_Full_60FPS_2560x1440_10bit
// };
// static struct reg_value ar0521_setting_60FPS_2600x1952_10bit[] = {
	// AR0521_Native_Full_60FPS_2600x1952_10bit
// };	

static struct reg_value ar0521_setting_27FPS_2600x1952_8bit[] = {
	AR0521_Native_Full_50FPS_2600x1952_8bit
};			
static struct reg_value ar0521_setting_27FPS_2560x1440_8bit[] = {
	AR0521_Native_Full_27FPS_2560x1440_8bit
};	
static struct reg_value ar0521_setting_27FPS_1280x720_8bit[] = {
	AR0521_Native_Full_27FPS_1280x720_8bit
};	
static struct reg_value ar0521_setting_27FPS_VGA_mode_8bit[] = {
	AR0521_Native_Full_27FPS_VGA_mode_8bit
};	
static struct reg_value ar0521_setting_27FPS_1928x1088_8bit[] = {
	AR0521_Native_1080p_27FPS_1928x1088_8bit
};		

		
// static struct reg_value ar0521_setting_90FPS_1288x728_10bit[] = {
	// AR0521_Native_Full_90FPS_1288x728_10bit
// };
// static struct reg_value ar0521_setting_120FPS_VGA_mode_10bit[] = {
	// AR0521_Native_Full_120FPS_VGA_mode_10bit
// };

// static struct reg_value ar0521_setting_27FPS_2600x1952_12bit[] = {
	// AR0521_Native_Full_27FPS_2600x1952_12bit
// };

// static struct reg_value ar0521_setting_30FPS_2560x1440_12bit[] = {
	// AR0521_Native_Full_30FPS_2560x1440_12bit
// };
// static struct reg_value ar0521_setting_30FPS_2600x1952_12bit[] = {
	// AR0521_Native_Full_30FPS_2600x1952_12bit
// };
// static struct reg_value ar0521_setting_32FPS_2600x1952_12bit[] = {
	// AR0521_Native_Full_32FPS_2600x1952_12bit
// };
// static struct reg_value ar0521_setting_51p2FPS_2560x1440_12bit[] = {
	// AR0521_Native_Full_51p2FPS_2560x1440_12bit
// };
// static struct reg_value ar0521_setting_56FPS_1928x1088_12bit[] = {
	// AR0521_Native_1080p_56FPS_1928x1088_12bit
// };
// static struct reg_value ar0521_setting_60FPS_1928x1088_12bit[] = {
	// AR0521_Native_1080p_60FPS_1928x1088_12bit
// };
// static struct reg_value ar0521_setting_86FPS_1288x728_12bit[] = {
	// AR0521_Native_Full_86FPS_1288x728_12bit
// };
// static struct reg_value ar0521_setting_120FPS_VGA_mode_12bit[] = {
	// AR0521_Native_Full_120FPS_VGA_mode_12bit
// };
	


static struct ar0521_mode_info ar0521_mode_info_data[1][ar0521_mode_MAX + 1] = {
	// {

		// {ar0521_mode_30FPS_1928x1088_10bit_2_HDR_MIPI_VC, 1928,  1088,
		// ar0521_setting_30FPS_1928x1088_10bit_2_HDR_MIPI_VC,
		// ARRAY_SIZE(ar0521_setting_30FPS_1928x1088_10bit_2_HDR_MIPI_VC)},
		// {ar0521_mode_1928x1088_10bit, 1928,  1088,
		// ar0521_setting_30FPS_1928x1088_10bit_HDR_MIPI_VC,
		// ARRAY_SIZE(ar0521_setting_30FPS_1928x1088_10bit_HDR_MIPI_VC)},
		// {ar0521_mode_2560x1440_10bit, 2560, 1440,
		// ar0521_setting_30FPS_2560x1440_10bit,
		// ARRAY_SIZE(ar0521_setting_30FPS_2560x1440_10bit)},
		// {ar0521_mode_2600x1952_10bit, 2600, 1952,
		// ar0521_setting_30FPS_2600x1952_10bit_HDR_MIPI_VC,
		// ARRAY_SIZE(ar0521_setting_30FPS_2600x1952_10bit_HDR_MIPI_VC)},

	// },
	{

		// {ar0521_mode_60FPS_1928x1088_10bit_2, 1928,  1088,
		// ar0521_setting_60FPS_1928x1088_10bit_2,
		// ARRAY_SIZE(ar0521_setting_60FPS_1928x1088_10bit_2)},
		{ar0521_mode_VGA, 648, 488,
		ar0521_setting_27FPS_VGA_mode_8bit,
		ARRAY_SIZE(ar0521_setting_27FPS_VGA_mode_8bit)},
		{ar0521_mode_1280x720, 1280, 720,
		ar0521_setting_27FPS_1280x720_8bit,
		ARRAY_SIZE(ar0521_setting_27FPS_1280x720_8bit)},
		{ar0521_mode_1928x1088, 1928,  1088,
		ar0521_setting_27FPS_1928x1088_8bit,
		ARRAY_SIZE(ar0521_setting_27FPS_1928x1088_8bit)},
		{ar0521_mode_2560x1440, 2560, 1440,
		ar0521_setting_27FPS_2560x1440_8bit,
		ARRAY_SIZE(ar0521_setting_27FPS_2560x1440_8bit)},
		{ar0521_mode_2600x1952, 2600, 1952,
		ar0521_setting_27FPS_2600x1952_8bit,
		ARRAY_SIZE(ar0521_setting_27FPS_2600x1952_8bit)},
		// {ar0521_mode_VGA, 320, 240,
		// ar0521_setting_120FPS_VGA_mode_10bit,
		// ARRAY_SIZE(ar0521_setting_120FPS_VGA_mode_10bit)},							 												
	},
}; 

static struct regulator *io_regulator;
static struct regulator *core_regulator;
static struct regulator *analog_regulator;
static struct regulator *gpo_regulator;

static int ar0521_probe(struct i2c_client *adapter,
				const struct i2c_device_id *device_id);
static int ar0521_remove(struct i2c_client *client);

static s32 ar0521_read_reg(u16 reg, u8 *val);
static s32 ar0521_write_reg(u16 reg, u8 val);
static s32 ar0521_read_reg16(u16 reg, u16 *val);
static s32 ar0521_write_reg16(u16 reg, u16 val);

static const struct i2c_device_id ar0521_id[] = {
	{"ar0521_mipi", 0},
	{},
};

MODULE_DEVICE_TABLE(i2c, ar0521_id);

static struct i2c_driver ar0521_i2c_driver = {
	.driver = {
		  .owner = THIS_MODULE,
		  .name  = "ar0521_mipi",
		  },
	.probe  = ar0521_probe,
	.remove = ar0521_remove,
	.id_table = ar0521_id,
};

static void ar0521_standby(s32 enable)
{
		pr_info("%s = %d\n",__func__, enable);
//	if (enable)
//		gpio_set_value(pwn_gpio, 0);
//	else
//		gpio_set_value(pwn_gpio, 1);

	// if (enable)
		// ar0521_write_reg(0x0100, 0x00); //sw standby streaming off
	// else
		// ar0521_write_reg(0x0100, 0x01);//sw standby off streaming on

	msleep(100);
}

static void ar0521_reset(void)
{
		pr_info("%s\n",__func__);
	/* camera reset */
	gpio_set_value(rst_gpio, 1);

	/* camera power down */
	//gpio_set_value(pwn_gpio, 0);
	//msleep(5);

	//gpio_set_value(pwn_gpio, 1);
	//msleep(5);

	gpio_set_value(rst_gpio, 0);
	msleep(1);

	gpio_set_value(rst_gpio, 1);
	msleep(5);

	//gpio_set_value(pwn_gpio, 0);
}

static int ar0521_power_on(struct device *dev)
{
	int ret = 0;

		pr_info("%s\n",__func__);
#if 0	
	io_regulator = devm_regulator_get(dev, "DOVDD");
	if (!IS_ERR(io_regulator)) {
		regulator_set_voltage(io_regulator,
				      AR0521_VOLTAGE_DIGITAL_IO,
				      AR0521_VOLTAGE_DIGITAL_IO);
		ret = regulator_enable(io_regulator);
		if (ret) {
			pr_err("%s:io set voltage error\n", __func__);
			return ret;
		} else {
			dev_dbg(dev,
				"%s:io set voltage ok\n", __func__);
		}
	} else {
		pr_err("%s: cannot get io voltage error\n", __func__);
		io_regulator = NULL;
	}

	core_regulator = devm_regulator_get(dev, "DVDD");
	if (!IS_ERR(core_regulator)) {
		regulator_set_voltage(core_regulator,
				      AR0521_VOLTAGE_DIGITAL_CORE,
				      AR0521_VOLTAGE_DIGITAL_CORE);
		ret = regulator_enable(core_regulator);
		if (ret) {
			pr_err("%s:core set voltage error\n", __func__);
			return ret;
		} else {
			dev_dbg(dev,
				"%s:core set voltage ok\n", __func__);
		}
	} else {
		core_regulator = NULL;
		pr_err("%s: cannot get core voltage error\n", __func__);
	}

	analog_regulator = devm_regulator_get(dev, "AVDD");
	if (!IS_ERR(analog_regulator)) {
		regulator_set_voltage(analog_regulator,
				      AR0521_VOLTAGE_ANALOG,
				      AR0521_VOLTAGE_ANALOG);
		ret = regulator_enable(analog_regulator);
		if (ret) {
			pr_err("%s:analog set voltage error\n",
				__func__);
			return ret;
		} else {
			dev_dbg(dev,
				"%s:analog set voltage ok\n", __func__);
		}
	} else {
		analog_regulator = NULL;
		pr_err("%s: cannot get analog voltage error\n", __func__);
	}
#endif
	return ret;
}

static s32 ar0521_write_reg(u16 reg, u8 val)
{
	u8 au8Buf[3] = {0};

	au8Buf[0] = reg >> 8;
	au8Buf[1] = reg & 0xff;
	au8Buf[2] = val;

	if (i2c_master_send(ar0521_data.i2c_client, au8Buf, 3) < 0) {
		pr_err("%s:write reg error:reg=%x,val=%x\n",
			__func__, reg, val);
		return -1;
	}
		//pr_info("%s- %04x:%02x\n",
		//	__func__, reg, val);
	return 0;
}

static s32 ar0521_read_reg(u16 reg, u8 *val)
{
	u8 au8RegBuf[2] = {0};
	u8 u8RdVal = 0;

	au8RegBuf[0] = reg >> 8;
	au8RegBuf[1] = reg & 0xff;

	if (2 != i2c_master_send(ar0521_data.i2c_client, au8RegBuf, 2)) {
		pr_err("%s:write reg error:reg=%x\n",
				__func__, reg);
		return -1;
	}

	if (1 != i2c_master_recv(ar0521_data.i2c_client, &u8RdVal, 1)) {
		pr_err("%s:read reg error:reg=%x,val=%x\n",
				__func__, reg, u8RdVal);
		return -1;
	}

	*val = u8RdVal;
//	pr_info("%s- %04x:%02x\n",__func__, reg, u8RdVal);
	return u8RdVal;
}

static s32 ar0521_write_reg16(u16 reg, u16 val)
{
	u8 au8Buf[4] = {0};

	au8Buf[0] = reg >> 8;
	au8Buf[1] = reg & 0xff;
	au8Buf[2] = val >> 8;
	au8Buf[3] = val & 0xff;
	u16 val2;

	if (i2c_master_send(ar0521_data.i2c_client, au8Buf, 4) < 0) {
		pr_err("%s:write reg error:reg=%x,val=%x\n",
			__func__, reg, val);
		return -1;
	}
		//pr_info("%s- %04x:%04x\n",
		//	__func__, reg, val);
//	ar0521_read_reg16(reg, &val2);
//	if (val2 != val)
//		pr_info("write failed\n");
	return 0;
}

static s32 ar0521_read_reg16(u16 reg, u16 *val)
{
	u8 au8RegBuf[2] = {0};
	u8 u8RdValBuf[2] = {0};
	u16 u16RdVal = 0;
	
	au8RegBuf[0] = reg >> 8;
	au8RegBuf[1] = reg & 0xff;

	if (2 != i2c_master_send(ar0521_data.i2c_client, au8RegBuf, 2)) {
		pr_err("%s:write reg error:reg=%x\n",
				__func__, reg);
		return -1;
	}

	if (2 != i2c_master_recv(ar0521_data.i2c_client, u8RdValBuf, 2)) {
		pr_err("%s:read reg error:reg=%x,val=%x\n",
				__func__, reg, *(u16*)u8RdValBuf);
		return -1;
	}
	u16RdVal = (u8RdValBuf[0]<<8) | u8RdValBuf[1];
	*val = u16RdVal;

//	pr_info("%s- %04x:%04x\n",__func__, reg, u16RdVal);
	
	return u16RdVal;
}

static int ar0521_set_reg(struct reg_value *pModeSetting)
{
	register u32 Delay_ms = 0;
	register u16 RegAddr = 0;
	register u16 Mask = 0;
	register u16 Val = 0;
	u16 RegVal = 0;
	u8 Val8 = 0;
	u8 RegVal8 = 0;
	int i, retval = 0;

	//pr_info("%s\n",__func__);
	
	Delay_ms = pModeSetting->u32Delay_ms;
	RegAddr = pModeSetting->u16RegAddr;
	Val = pModeSetting->u16Val;
	Mask = pModeSetting->u16Mask;

	if (pModeSetting->u16Bytes ==1) {
		if (Mask) {
			retval = ar0521_read_reg(RegAddr, &RegVal8);
			if (retval < 0)
				goto err;

			RegVal &= ~(u8)Mask;
			Val &= Mask;
			Val |= RegVal;
		}
	
		retval = ar0521_write_reg(RegAddr, Val8);
	}
	else {
		if (Mask) {
			retval = ar0521_read_reg16(RegAddr, &RegVal);
			if (retval < 0)
				goto err;

			RegVal &= ~(u8)Mask;
			Val &= Mask;
			Val |= RegVal;
		}

		retval = ar0521_write_reg16(RegAddr, Val);
	}
	if (retval < 0)
		goto err;

	if (Delay_ms)
		msleep(Delay_ms);

err:
	return retval;
}

								 
static int AE_Target = 52;

static void AR0521_stream_on(void)
{


	u8 temp;
	struct reg_value reg = AR0521_enable_streaming;
	
	pr_info("%s\n",__func__);
//	temp = ar0521_read_reg(0x301B, &temp);
//	ar0521_write_reg(0x301B, temp | 0x4);

	ar0521_set_reg(&reg);

}

static void AR0521_stream_off(void)
{

	u8 temp;
	struct reg_value reg = AR0521_disable_streaming;
	
	pr_info("%s\n",__func__);
//	temp = ar0521_read_reg(0x301B, &temp);
//	ar0521_write_reg(0x301B, temp & ~0x4);

	ar0521_set_reg(&reg);

}



static int AR0521_set_AE_target(int target)//ahp revisit
{
	/* stable in high */
//	int fast_high, fast_low;
//	AE_low = target * 23 / 25;	/* 0.92 */
//	AE_high = target * 27 / 25;	/* 1.08 */
//
//	fast_high = AE_high<<1;
//	if (fast_high > 255)
//		fast_high = 255;
//
//	fast_low = AE_low >> 1;
//
//	ar0521_write_reg(0x3a0f, AE_high);
//	ar0521_write_reg(0x3a10, AE_low);
//	ar0521_write_reg(0x3a1b, AE_high);
//	ar0521_write_reg(0x3a1e, AE_low);
//	ar0521_write_reg(0x3a11, fast_high);
//	ar0521_write_reg(0x3a1f, fast_low);
    pr_info("%s\n",__func__);
	return 0;
}

static void AR0521_turn_on_AE_AG(int enable) //ahp revisit
{
//	u8 ae_ag_ctrl;

//	ar0521_read_reg(0x3503, &ae_ag_ctrl);
//	if (enable) {
//		/* turn on auto AE/AG */
//		ae_ag_ctrl = ae_ag_ctrl & ~(0x03);
//	} else {
//		/* turn off AE/AG */
//		ae_ag_ctrl = ae_ag_ctrl | 0x03;
//	}
//	ar0521_write_reg(0x3503, ae_ag_ctrl);
pr_info("%s = %d\n",__func__, enable);

}

static void ar0521_set_virtual_channel(int channel) //ahp revisit
{
	u8 channel_id;

	pr_info("%s channel=%d\n",__func__, channel);
	
	//ar0521_read_reg(0x0110, &channel_id);
	//channel_id &= ~(3 << 6);
	channel_id = channel & 0x07;
	ar0521_write_reg(0x0110, channel_id);
}

/* download ar0521 settings to sensor through i2c */
static int ar0521_download_firmware(struct reg_value *pModeSetting, s32 ArySize) //ahp revisit
{
	register u32 Delay_ms = 0;
	register u16 RegAddr = 0;
	register u16 Mask = 0;
	register u16 Val = 0;
	u16 RegVal = 0;
	u8 Val8 = 0;
	u8 RegVal8 = 0;
	int i, retval = 0;

	pr_info("%s\n",__func__);
	
	for (i = 0; i < ArySize; ++i, ++pModeSetting) {
		Delay_ms = pModeSetting->u32Delay_ms;
		RegAddr = pModeSetting->u16RegAddr;
		Val = pModeSetting->u16Val;
		Mask = pModeSetting->u16Mask;

		if (pModeSetting->u16Bytes ==1) {
			if (Mask) {
				retval = ar0521_read_reg(RegAddr, &RegVal8);
				if (retval < 0)
					goto err;

				RegVal &= ~(u8)Mask;
				Val &= Mask;
				Val |= RegVal;
			}
		
			retval = ar0521_write_reg(RegAddr, Val8);
		}
		else {
			if (Mask) {
				retval = ar0521_read_reg16(RegAddr, &RegVal);
				if (retval < 0)
					goto err;

				RegVal &= ~(u8)Mask;
				Val &= Mask;
				Val |= RegVal;
			}

			retval = ar0521_write_reg16(RegAddr, Val);
		}
		if (retval < 0)
			goto err;

		if (Delay_ms)
			msleep(Delay_ms);
	}
err:
	return retval;
}


/* if sensor changes inside scaling or subsampling
 * change mode directly
 * */
static int ar0521_change_mode_direct(enum ar0521_frame_rate frame_rate,
				enum ar0521_mode mode) //ahp revisit
{
	struct reg_value *pModeSetting = NULL;
	s32 ArySize = 0;
	int retval = 0;

	pr_info("%s w=%d h=%d\n",__func__,
							ar0521_mode_info_data[frame_rate][mode].width,
							ar0521_mode_info_data[frame_rate][mode].height);
	
	/* check if the input mode and frame rate is valid */
	pModeSetting =
		ar0521_mode_info_data[frame_rate][mode].init_data_ptr;
	ArySize =
		ar0521_mode_info_data[frame_rate][mode].init_data_size;

	ar0521_data.pix.width =
		ar0521_mode_info_data[frame_rate][mode].width;
	ar0521_data.pix.height =
		ar0521_mode_info_data[frame_rate][mode].height;

	if (ar0521_data.pix.width == 0 || ar0521_data.pix.height == 0 ||
		pModeSetting == NULL || ArySize == 0)
		return -EINVAL;

	/* turn off AE/AG */
	AR0521_turn_on_AE_AG(0);

	AR0521_stream_off();

	
	//		pModeSetting = ar0521_init_setting_120fps_VGA;
	//	ArySize = ARRAY_SIZE(ar0521_init_setting_120fps_VGA);
		
	/* Write capture setting */
	retval = ar0521_download_firmware(pModeSetting, ArySize);
	if (retval < 0)
		goto err;

	//AR0521_stream_on();

	AR0521_turn_on_AE_AG(1);

err:
	return retval;
}

static int ar0521_init_mode(enum ar0521_frame_rate frame_rate,
			    enum ar0521_mode mode, enum ar0521_mode orig_mode) //ahp revisit
{
	struct reg_value *pModeSetting = NULL;
	s32 ArySize = 0;
	int retval = 0;
	void *mipi_csi2_info;
	u32 mipi_reg, msec_wait4stable = 0;
	//enum ar0521_downsize_mode dn_mode, orig_dn_mode;
pr_info("ar0521_init_mode\n");
	if ((mode > ar0521_mode_MAX || mode < ar0521_mode_MIN)
		&& (mode != ar0521_mode_INIT)) {
		pr_err("Wrong ar0521 mode detected!\n");
		return -1;
	}

	mipi_csi2_info = mipi_csi2_get_info();

	/* initial mipi dphy */
	if (!mipi_csi2_info) {
		printk(KERN_ERR "%s() in %s: Fail to get mipi_csi2_info!\n",
		       __func__, __FILE__);
		return -1;
	}

	if (!mipi_csi2_get_status(mipi_csi2_info))
		mipi_csi2_enable(mipi_csi2_info);

	if (!mipi_csi2_get_status(mipi_csi2_info)) {
		pr_err("Can not enable mipi csi2 driver!\n");
		return -1;
	}

	mipi_csi2_set_lanes(mipi_csi2_info);

	/*Only reset MIPI CSI2 HW at sensor initialize*/
	if (mode == ar0521_mode_INIT)
		mipi_csi2_reset(mipi_csi2_info);

	if (ar0521_data.pix.pixelformat == V4L2_PIX_FMT_UYVY)
		//mipi_csi2_set_datatype(mipi_csi2_info, MIPI_DT_RAW8);
		mipi_csi2_set_datatype(mipi_csi2_info, MIPI_DT_YUV422);
	else if (ar0521_data.pix.pixelformat == V4L2_PIX_FMT_RGB565)
		mipi_csi2_set_datatype(mipi_csi2_info, MIPI_DT_RGB565);
	else if (ar0521_data.pix.pixelformat == V4L2_PIX_FMT_GREY)
		mipi_csi2_set_datatype(mipi_csi2_info, MIPI_DT_RAW8);
	else if (ar0521_data.pix.pixelformat == V4L2_PIX_FMT_Y10)
		mipi_csi2_set_datatype(mipi_csi2_info, MIPI_DT_RAW10);
	else
		pr_err("currently this sensor format can not be supported!\n");

	// dn_mode = ar0521_mode_info_data[frame_rate][mode].dn_mode;
	// orig_dn_mode = ar0521_mode_info_data[frame_rate][orig_mode].dn_mode;
	if (mode == ar0521_mode_INIT) {
		//pr_info("ar0521_init_mode mode==INIT\n");
		//pModeSetting = ar0521_mode_30FPS_2560x1440_10bit;
		//ArySize = ARRAY_SIZE(ar0521_mode_30FPS_2560x1440_10bit);
	ar0521_data.pix.width = 
		ar0521_mode_info_data[0][mycapmode].width; //640;//2560;//1928;
	ar0521_data.pix.height = 
		ar0521_mode_info_data[0][mycapmode].height;//480;//1440;//1088;
		//ar0521_data.pix.width = 640;//2560;//1928;
		//ar0521_data.pix.height = 480;//1440;//1088;
		//retval = ar0521_download_firmware(pModeSetting, ArySize);
	//	if (retval < 0)
	//		goto err;

		pModeSetting = ar0521_mode_info_data[0][mycapmode].init_data_ptr; //ar0521_setting_60FPS_VGA_10bit;
		ArySize = ar0521_mode_info_data[0][mycapmode].init_data_size;//ARRAY_SIZE(ar0521_setting_60FPS_VGA_10bit);
		pr_info("ar0521_init_mode mode==INIT w=%d h=%d\n", ar0521_data.pix.width,
															ar0521_data.pix.height);
		retval = ar0521_download_firmware(pModeSetting, ArySize);

	//	pModeSetting = ar0521_init_setting_120fps_VGA;
	//	ArySize = ARRAY_SIZE(ar0521_init_setting_120fps_VGA);
	//	retval = ar0521_download_firmware(pModeSetting, ArySize);
		
	} 
	// else if ((dn_mode == SUBSAMPLING && orig_dn_mode == SCALING) ||
			// (dn_mode == SCALING && orig_dn_mode == SUBSAMPLING)) {
		// /* change between subsampling and scaling
		 // * go through exposure calculation */
		// retval = ar0521_change_mode_exposure_calc(frame_rate, mode);
	 else {
		/* change inside subsampling or scaling
		 * download firmware directly */
		retval = ar0521_change_mode_direct(frame_rate, mode);
	}

	if (retval < 0)
		goto err;
	if (mytest > 0 && mytest <7) {
		ar0521_write_reg16(0x3070, mytest);
		ar0521_write_reg16(0x3072, myred);
		ar0521_write_reg16(0x3074, mygreenr);
		ar0521_write_reg16(0x3076, myblue);
		ar0521_write_reg16(0x3078, mygreenb);
	}
	else
		ar0521_write_reg16(0x3070, 0x0000);
	// if (mylanes ==4)
		// ar0521_write_reg16(0x31AE, 0x0204);
	// else if (mylanes ==2) 
		// ar0521_write_reg16(0x31AE, 0x0202);
	
	pr_info("ar0521_init_mode - no error so far\n");
	
	
//	msleep(100);

	AR0521_set_AE_target(AE_Target);
	//ar0521_get_light_freq();
	//ar0521_set_bandingfilter();
	ar0521_set_virtual_channel(ar0521_data.csi);

	ar0521_standby(0);
	/* add delay to wait for sensor stable */
	// if (mode == ar0521_mode_QSXGA_2592_1944) {
		// /* dump the first two frames: 1/7.5*2
		 // * the frame rate of QSXGA is 7.5fps */
		// msec_wait4stable = 267;
	// } else if (frame_rate == ar0521_15_fps) {
		// /* dump the first nine frames: 1/15*9 */
		 msec_wait4stable = 600;
	// } else if (frame_rate == ar0521_30_fps) {
		// /* dump the first nine frames: 1/30*9 */
		// msec_wait4stable = 300;
	// }
	msleep(msec_wait4stable);

	if (mipi_csi2_info) {
		unsigned int i;
#if 1
		i = 0;

		/* wait for mipi sensor ready */
		mipi_reg = mipi_csi2_dphy_status(mipi_csi2_info);
		while ((mipi_reg == 0x200) && (i < 50)) {
			mipi_reg = mipi_csi2_dphy_status(mipi_csi2_info);
			i++;
			msleep(10);
		}
		mipi_csi2_info = mipi_csi2_get_info();
pr_info("   dphy_status_reg =  %08x \n", mipi_reg);
		if (i >= 50) {
			pr_err("mipi csi2 can not receive sensor clk!\n");
			//return -1;
		}
#endif
		i = 0;

		/* wait for mipi stable */
		mipi_reg = mipi_csi2_get_error1(mipi_csi2_info);
		while ((mipi_reg != 0x0) && (i < 10)) {
			mipi_reg = mipi_csi2_get_error1(mipi_csi2_info);
			i++;
			msleep(10);
		}
pr_info("   error1_reg =  %08x \n", mipi_reg);
		if (i >= 10) {
			pr_err("mipi csi2 can not receive data correctly!\n");
			//return -1;
		}

		i = 0;

		/* wait for mipi stable */
		mipi_reg = mipi_csi2_get_error2(mipi_csi2_info);
		while ((mipi_reg != 0x0) && (i < 10)) {
			mipi_reg = mipi_csi2_get_error2(mipi_csi2_info);
			i++;
			msleep(10);
		}
pr_info("   error2_reg =  %08x \n", mipi_reg);
		if (i >= 10) {
			pr_err("mipi csi2 can not receive data correctly!\n");
			//return -1;
		}		
		
	}
err:
	return retval;
}

/* --------------- IOCTL functions from v4l2_int_ioctl_desc --------------- */

static int ioctl_g_ifparm(struct v4l2_int_device *s, struct v4l2_ifparm *p) //ahp revisit
{
	pr_info("%s\n",__func__);
	if (s == NULL) {
		pr_err("   ERROR!! no slave device set!\n");
		return -1;
	}

	memset(p, 0, sizeof(*p));
	p->u.bt656.clock_curr = ar0521_data.mclk;
//	p->u.bt656.clock_curr = 0;
	pr_info("   clock_curr=mclk=%d\n", ar0521_data.mclk);
	p->if_type = V4L2_IF_TYPE_BT656;
	p->u.bt656.mode = V4L2_IF_TYPE_BT656_MODE_NOBT_8BIT;
	p->u.bt656.clock_min = AR0521_XCLK_MIN;
	p->u.bt656.clock_max = AR0521_XCLK_MAX;
	p->u.bt656.bt_sync_correct = 0;  /* Indicate external vsync */
	
	p->u.bt656.nobt_vs_inv = 1;
	p->u.bt656.nobt_hs_inv = 0;
	p->u.bt656.nobt_dataen_inv = 1;	

	return 0;
}

/*!
 * ioctl_s_power - V4L2 sensor interface handler for VIDIOC_S_POWER ioctl
 * @s: pointer to standard V4L2 device structure
 * @on: indicates power mode (on or off)
 *
 * Turns the power on or off, depending on the value of on and returns the
 * appropriate error code.
 */
static int ioctl_s_power(struct v4l2_int_device *s, int on)
{
	struct sensor_data *sensor = s->priv;

	pr_info("%s\n",__func__);
	
	if (on && !sensor->on) {
		if (io_regulator)
			if (regulator_enable(io_regulator) != 0)
				return -EIO;
		if (core_regulator)
			if (regulator_enable(core_regulator) != 0)
				return -EIO;
		if (gpo_regulator)
			if (regulator_enable(gpo_regulator) != 0)
				return -EIO;
		if (analog_regulator)
			if (regulator_enable(analog_regulator) != 0)
				return -EIO;
		/* Make sure power on */
		ar0521_standby(0);
	} else if (!on && sensor->on) {
		if (analog_regulator)
			regulator_disable(analog_regulator);
		if (core_regulator)
			regulator_disable(core_regulator);
		if (io_regulator)
			regulator_disable(io_regulator);
		if (gpo_regulator)
			regulator_disable(gpo_regulator);

		ar0521_standby(1);
	}

	sensor->on = on;

	return 0;
}

/*!
 * ioctl_g_parm - V4L2 sensor interface handler for VIDIOC_G_PARM ioctl
 * @s: pointer to standard V4L2 device structure
 * @a: pointer to standard V4L2 VIDIOC_G_PARM ioctl structure
 *
 * Returns the sensor's video CAPTURE parameters.
 */
static int ioctl_g_parm(struct v4l2_int_device *s, struct v4l2_streamparm *a)//ahp revisit
{
	struct sensor_data *sensor = s->priv;
	struct v4l2_captureparm *cparm = &a->parm.capture;
	int ret = 0;

	pr_info("%s\n",__func__);
	
	switch (a->type) {
	/* This is the only case currently handled. */
	case V4L2_BUF_TYPE_VIDEO_CAPTURE:
		memset(a, 0, sizeof(*a));
		a->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
		cparm->capability = sensor->streamcap.capability;
		cparm->timeperframe = sensor->streamcap.timeperframe;
		cparm->capturemode = sensor->streamcap.capturemode;
		cparm->readbuffers = 4; //huh?
		ret = 0;
		break;

	/* These are all the possible cases. */
	case V4L2_BUF_TYPE_VIDEO_OUTPUT:
	case V4L2_BUF_TYPE_VIDEO_OVERLAY:
	case V4L2_BUF_TYPE_VBI_CAPTURE:
	case V4L2_BUF_TYPE_VBI_OUTPUT:
	case V4L2_BUF_TYPE_SLICED_VBI_CAPTURE:
	case V4L2_BUF_TYPE_SLICED_VBI_OUTPUT:
		ret = -EINVAL;
		break;

	default:
		pr_info("   type is unknown - %d\n", a->type);
		ret = -EINVAL;
		break;
	}

	return ret;
}

/*!
 * ioctl_s_parm - V4L2 sensor interface handler for VIDIOC_S_PARM ioctl
 * @s: pointer to standard V4L2 device structure
 * @a: pointer to standard V4L2 VIDIOC_S_PARM ioctl structure
 *
 * Configures the sensor to use the input parameters, if possible.  If
 * not possible, reverts to the old parameters and returns the
 * appropriate error code.
 */
static int ioctl_s_parm(struct v4l2_int_device *s, struct v4l2_streamparm *a) //ahp revisit
{
	struct sensor_data *sensor = s->priv;
	struct v4l2_fract *timeperframe = &a->parm.capture.timeperframe;
	u32 tgt_fps;	/* target frames per second */
	enum ar0521_frame_rate frame_rate;
	enum ar0521_mode orig_mode;
	int ret = 0;

	pr_info("%s\n",__func__);
	
	/* Make sure power on */
	ar0521_standby(0);

	switch (a->type) {
	/* This is the only case currently handled. */
	case V4L2_BUF_TYPE_VIDEO_CAPTURE:
		/* Check that the new frame rate is allowed. */
		if ((timeperframe->numerator == 0) ||
		    (timeperframe->denominator == 0)) {
			timeperframe->denominator = DEFAULT_FPS;
			timeperframe->numerator = 1;
		}

		tgt_fps = timeperframe->denominator /
			  timeperframe->numerator;

		if (tgt_fps > MAX_FPS) {
			timeperframe->denominator = MAX_FPS;
			timeperframe->numerator = 1;
		} else if (tgt_fps < MIN_FPS) {
			timeperframe->denominator = MIN_FPS;
			timeperframe->numerator = 1;
		}

		/* Actual frame rate we use */
		tgt_fps = timeperframe->denominator /
			  timeperframe->numerator;

		// if (tgt_fps == 30)
			// frame_rate = ar0521_30_fps;
		// else 
		 if (tgt_fps == 27)
			 frame_rate = ar0521_27_fps;
		 else {
			 pr_err(" The camera frame rate is not supported!\n");
			 return -EINVAL;
		 }

		orig_mode = sensor->streamcap.capturemode;
		ret = ar0521_init_mode(frame_rate,
				(u32)a->parm.capture.capturemode, orig_mode);
		if (ret < 0)
			return ret;

		sensor->streamcap.timeperframe = *timeperframe;
		sensor->streamcap.capturemode = 
				(u32)a->parm.capture.capturemode;

		break;

	/* These are all the possible cases. */
	case V4L2_BUF_TYPE_VIDEO_OUTPUT:
	case V4L2_BUF_TYPE_VIDEO_OVERLAY:
	case V4L2_BUF_TYPE_VBI_CAPTURE:
	case V4L2_BUF_TYPE_VBI_OUTPUT:
	case V4L2_BUF_TYPE_SLICED_VBI_CAPTURE:
	case V4L2_BUF_TYPE_SLICED_VBI_OUTPUT:
		pr_info("   type is not " \
			"V4L2_BUF_TYPE_VIDEO_CAPTURE but %d\n",
			a->type);
		ret = -EINVAL;
		break;

	default:
		pr_info("   type is unknown - %d\n", a->type);
		ret = -EINVAL;
		break;
	}

	return ret;
}

/*!
 * ioctl_g_fmt_cap - V4L2 sensor interface handler for ioctl_g_fmt_cap
 * @s: pointer to standard V4L2 device structure
 * @f: pointer to standard V4L2 v4l2_format structure
 *
 * Returns the sensor's current pixel format in the v4l2_format
 * parameter.
 */
static int ioctl_g_fmt_cap(struct v4l2_int_device *s, struct v4l2_format *f) //ahp revisit
{
	struct sensor_data *sensor = s->priv;

	//pr_info("%s\n",__func__);
	
	//f->fmt.pix = sensor->pix;
     pr_info("%s: %x\n", __func__, f->type);	
	
	switch (f->type) {
	case V4L2_BUF_TYPE_VIDEO_CAPTURE:
		f->fmt.pix = sensor->pix;
        f->fmt.pix.pixelformat =V4L2_PIX_FMT_GREY;		
		f->fmt.pix.colorspace = V4L2_COLORSPACE_RAW;
		pr_info("%s: %dx%d\n", __func__, sensor->pix.width, sensor->pix.height);
		break;

/*	case V4L2_BUF_TYPE_SENSOR:
		pr_info("%s: left=%d, top=%d, %dx%d\n", __func__,
			sensor->pix.left, sensor->pix.top,
			sensor->pix.width, sensor->pix.height);
		f->fmt.spix = sensor->pix;
                f->fmt.pix.pixelformat =V4L2_PIX_FMT_GREY;				
		break;
*/
	// case V4L2_BUF_TYPE_PRIVATE:
                // f->fmt.pix.pixelformat =V4L2_PIX_FMT_GREY;		
	        // break;
	default:
	        // f->fmt.pix = sensor->pix;
                // f->fmt.pix.pixelformat =V4L2_PIX_FMT_GREY;	
		return -EINVAL;
		break;
	}

        pr_info("%s: %x %x\n", __func__, f->type,f->fmt.pix.pixelformat);		
	

	return 0;
}

/*!
 * ioctl_g_ctrl - V4L2 sensor interface handler for VIDIOC_G_CTRL ioctl
 * @s: pointer to standard V4L2 device structure
 * @vc: standard V4L2 VIDIOC_G_CTRL ioctl structure
 *
 * If the requested control is supported, returns the control's current
 * value from the video_control[] array.  Otherwise, returns -EINVAL
 * if the control is not supported.
 */
static int ioctl_g_ctrl(struct v4l2_int_device *s, struct v4l2_control *vc) //ahp revisit
{
	int ret = 0;

	pr_info("%s\n",__func__);
	
	switch (vc->id) {
	case V4L2_CID_BRIGHTNESS:
		vc->value = ar0521_data.brightness;
		break;
	case V4L2_CID_HUE:
		vc->value = ar0521_data.hue;
		break;
	case V4L2_CID_CONTRAST:
		vc->value = ar0521_data.contrast;
		break;
	case V4L2_CID_SATURATION:
		vc->value = ar0521_data.saturation;
		break;
	case V4L2_CID_RED_BALANCE:
		vc->value = ar0521_data.red;
		break;
	case V4L2_CID_BLUE_BALANCE:
		vc->value = ar0521_data.blue;
		break;
	case V4L2_CID_EXPOSURE:
		vc->value = ar0521_data.ae_mode;
		break;
	default:
		ret = -EINVAL;
	}

	return ret;
}

/*!
 * ioctl_s_ctrl - V4L2 sensor interface handler for VIDIOC_S_CTRL ioctl
 * @s: pointer to standard V4L2 device structure
 * @vc: standard V4L2 VIDIOC_S_CTRL ioctl structure
 *
 * If the requested control is supported, sets the control's current
 * value in HW (and updates the video_control[] array).  Otherwise,
 * returns -EINVAL if the control is not supported.
 */
static int ioctl_s_ctrl(struct v4l2_int_device *s, struct v4l2_control *vc) //ahp revisit
{
	int retval = 0;

	pr_info("In ar0521:ioctl_s_ctrl %d\n",
		 vc->id);

	switch (vc->id) {
	case V4L2_CID_BRIGHTNESS:
		break;
	case V4L2_CID_CONTRAST:
		break;
	case V4L2_CID_SATURATION:
		break;
	case V4L2_CID_HUE:
		break;
	case V4L2_CID_AUTO_WHITE_BALANCE:
		break;
	case V4L2_CID_DO_WHITE_BALANCE:
		break;
	case V4L2_CID_RED_BALANCE:
		break;
	case V4L2_CID_BLUE_BALANCE:
		break;
	case V4L2_CID_GAMMA:
		break;
	case V4L2_CID_EXPOSURE:
		break;
	case V4L2_CID_AUTOGAIN:
		break;
	case V4L2_CID_GAIN:
		break;
	case V4L2_CID_HFLIP:
		break;
	case V4L2_CID_VFLIP:
		break;
	default:
		retval = -EINVAL; //-EPERM;
		break;
	}

	return retval;
}

/*!
 * ioctl_enum_framesizes - V4L2 sensor interface handler for
 *			   VIDIOC_ENUM_FRAMESIZES ioctl
 * @s: pointer to standard V4L2 device structure
 * @fsize: standard V4L2 VIDIOC_ENUM_FRAMESIZES ioctl structure
 *
 * struct v4l2_frmsizeenum
 *__u32	index	 	 IN:  Index of the given frame size in the enumeration.
 *__u32	pixel_format IN:  Pixel format for which the frame sizes are enumerated.
 *__u32	type	 	 OUT: Frame size type the device supports.
 *union	 	 	 	 OUT: Frame size with the given index.
 * 	struct v4l2_frmsize_discrete	discrete	 
 * 	struct v4l2_frmsize_stepwise	stepwise	 
 *__u32	reserved[2]	 	Reserved space for future use. Must be zeroed by drivers and applications.

 * Return 0 if successful, otherwise -EINVAL.
 */
static int ioctl_enum_framesizes(struct v4l2_int_device *s,
				 struct v4l2_frmsizeenum *fsize)//ahp revisit
{
	pr_info("%s\n",__func__);
	
	if (fsize->index > ar0521_mode_MAX)
	//if (fsize->index > 1)
		return -EINVAL;
	if (fsize->pixel_format != ar0521_data.pix.pixelformat)
		return -EINVAL;
	fsize->type = V4L2_FRMSIZE_TYPE_DISCRETE;
	//fsize->pixel_format = ar0521_data.pix.pixelformat;
	fsize->discrete.width = ar0521_mode_info_data[0][fsize->index].width; //,
			//ar0521_mode_info_data[1][fsize->index].width);
	//fsize->discrete.width = 1280;//1920;
	fsize->discrete.height =
		ar0521_mode_info_data[0][fsize->index].height;
			//ar0521_mode_info_data[1][fsize->index].height);
	//fsize->discrete.height = 720;//1080;
	// fsize->discrete.width =
			// max(ar0521_mode_info_data[0][fsize->index].width,
			    // ar0521_mode_info_data[1][fsize->index].width);
	// fsize->discrete.height =
			// max(ar0521_mode_info_data[0][fsize->index].height,
			    // ar0521_mode_info_data[1][fsize->index].height);
	pr_info("h=%d, w=%d, pixfmt=%x", fsize->discrete.height,fsize->discrete.width,
			fsize->pixel_format);
	return 0;
}

/*!
 * ioctl_enum_frameintervals - V4L2 sensor interface handler for
 *			       VIDIOC_ENUM_FRAMEINTERVALS ioctl
 * @s: pointer to standard V4L2 device structure
 * @fival: standard V4L2 VIDIOC_ENUM_FRAMEINTERVALS ioctl structure
 *
 * struct v4l2_frmivalenum
 *__u32	index	 	 IN:  Index of the given frame interval in the enumeration.
 *__u32	pixel_format IN:  Pixel format for which the frame intervals are enumerated.
 *__u32	width	 	 IN:  Frame width for which the frame intervals are enumerated.
 *__u32	height	 	 IN:  Frame height for which the frame intervals are enumerated.
 *__u32	type	 	 OUT: Frame interval type the device supports.
 *union	 	 		 OUT: Frame interval with the given index.
 * 	struct v4l2_fract	discrete	Frame interval [s].
 * 	struct v4l2_frmival_stepwise	stepwise	 
 *__u32	reserved[2]	 	Reserved space for future use. Must be zeroed by drivers and applications.
 
 
 * Return 0 if successful, otherwise -EINVAL.
 */
static int ioctl_enum_frameintervals(struct v4l2_int_device *s,
					 struct v4l2_frmivalenum *fival)//ahp revisit
{
	int i, j, count = 0;

	pr_info("%s - w=%d,h=%d,pf=%x\n", __func__, fival->width,
			fival->height, fival->pixel_format);
	
	// if (fival->index < 0 || fival->index > ar0521_mode_MAX)
		// return -EINVAL;

	// if (fival->width == 0 || fival->height == 0 ||
	    // fival->pixel_format == 0) {
		// pr_warning("Please assign pixelformat, width and height.\n");
		// return -EINVAL;
	// }
	
	fival->type = V4L2_FRMIVAL_TYPE_DISCRETE;
	fival->discrete.numerator = 1;
	
	// if (fival->pixel_format == ar0521_data.pix.pixelformat
	 // && fival->width == 1280
	 // && fival->height == 720
	 // && fival->index == count++){
		 
		// fival->discrete.denominator = 90;//60;
		// return 0; 
		// }
		
		
	for (i = 0; i < ARRAY_SIZE(ar0521_mode_info_data); i++)
		for (j = 0; j < (ar0521_mode_MAX + 1); j++) {
			if (fival->pixel_format == ar0521_data.pix.pixelformat
			 && fival->width == ar0521_mode_info_data[i][j].width
			 && fival->height == ar0521_mode_info_data[i][j].height
			 && ar0521_mode_info_data[i][j].init_data_ptr != NULL
			 && fival->index == count++) {
			 // && ar0521_mode_info_data[i][j].init_data_ptr != NULL){
				// count++;
			// }
			 // if (fival->index == (count)) {
				fival->discrete.denominator = ar0521_framerates[i];
				pr_info("frame rate %d\n", ar0521_framerates[i]);
				return 0;
			}
		}
	// for (i = 0; i < ARRAY_SIZE(ar0521_mode_info_data); i++)
		// for (j = 0; j < (ar0521_mode_MAX + 1); j++)
			// if (fival->pixel_format == ar0521_data.pix.pixelformat
			 // && fival->width == ar0521_mode_info_data[i][j].width
			 // && fival->height == ar0521_mode_info_data[i][j].height
			 // && ar0521_mode_info_data[i][j].init_data_ptr != NULL
			 // && fival->index == count++) {
				// fival->discrete.denominator =
						// ar0521_framerates[i];
				// pr_info("frame rate %d\n", ar0521_framerates[i]);
				// return 0;
			// }

	return -EINVAL;
}

/*!
 * ioctl_g_chip_ident - V4L2 sensor interface handler for
 *			VIDIOC_DBG_G_CHIP_IDENT ioctl
 * @s: pointer to standard V4L2 device structure
 * @id: pointer to int
 *
 * Return 0.
 */
static int ioctl_g_chip_ident(struct v4l2_int_device *s, int *id)//ahp revisit
{
	pr_info("%s\n",__func__);
	
	((struct v4l2_dbg_chip_ident *)id)->match.type =
					V4L2_CHIP_MATCH_I2C_DRIVER;
	strcpy(((struct v4l2_dbg_chip_ident *)id)->match.name,
		"ov5645_mipi_camera"); //was "ar0521_mipi_camera"

	return 0;
}

/*!
 * ioctl_g_register - V4L2 sensor interface handler for
 *			VIDIOC_DBG_G_REGISTER ioctl
 * @s: pointer to standard V4L2 device structure
 * @id: pointer to int
 *
 * Return 0.
 */
static int ioctl_g_register(struct v4l2_int_device *s, int *reg)
{
	pr_info("%s\n",__func__);
	u16 val;
	
	ar0521_read_reg16(((struct v4l2_dbg_register *)reg)->reg, &val);
	((struct v4l2_dbg_register *)reg)->val=val;
					
	return 0;
}

/*!
 * ioctl_S_register - V4L2 sensor interface handler for
 *			VIDIOC_DBG_S_REGISTER ioctl
 * @s: pointer to standard V4L2 device structure
 * @id: pointer to int
 *
 * Return 0.
 */
static int ioctl_s_register(struct v4l2_int_device *s, int *reg)
{
	pr_info("%s\n",__func__);
	u16 val;
	
	val = ((struct v4l2_dbg_register *)reg)->val;
	ar0521_write_reg16(((struct v4l2_dbg_register *)reg)->reg, val);
			
	return 0;
}



/*!
 * ioctl_init - V4L2 sensor interface handler for VIDIOC_INT_INIT
 * @s: pointer to standard V4L2 device structure
 */
static int ioctl_init(struct v4l2_int_device *s)//ahp revisit
{

	return 0;
}

/*!
 * ioctl_enum_fmt_cap - V4L2 sensor interface handler for VIDIOC_ENUM_FMT
 * @s: pointer to standard V4L2 device structure
 * @fmt: pointer to standard V4L2 fmt description structure
 *
 * Return 0.
 */
static int ioctl_enum_fmt_cap(struct v4l2_int_device *s,
			      struct v4l2_fmtdesc *fmt)//ahp revisit
{
	pr_info("%s\n",__func__);
	
	//if (fmt->index > ar0521_mode_MAX)
	if (fmt->index > 0) // we only do GREY
		return -EINVAL;
	if (fmt->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
		return -EINVAL;

	fmt->pixelformat = ar0521_data.pix.pixelformat;
	fmt->description[0]='G';
	fmt->description[1]='R';
	fmt->description[2]='A';
	fmt->description[3]='Y';
	fmt->description[4]='8';

	return 0;
}

/*!
 * ioctl_dev_init - V4L2 sensor interface handler for vidioc_int_dev_init_num
 * @s: pointer to standard V4L2 device structure
 *
 * Initialize the device when slave attaches to the master.
 */
static int ioctl_dev_init(struct v4l2_int_device *s)//ahp revisit
{
	struct sensor_data *sensor = s->priv;
	u32 tgt_xclk;	/* target xclk */
	u32 tgt_fps;	/* target frames per second */
	int ret;
	enum ar0521_frame_rate frame_rate;
	void *mipi_csi2_info;

	pr_info("%s\n",__func__);
	
	ar0521_data.on = true;

	/* mclk */
	tgt_xclk = ar0521_data.mclk;
	tgt_xclk = min(tgt_xclk, (u32)AR0521_XCLK_MAX);
	tgt_xclk = max(tgt_xclk, (u32)AR0521_XCLK_MIN);
	ar0521_data.mclk = tgt_xclk;

	pr_info("   Setting mclk to %d MHz\n", tgt_xclk / 1000000);

	/* Default camera frame rate is set in probe */
	tgt_fps = sensor->streamcap.timeperframe.denominator /
		  sensor->streamcap.timeperframe.numerator;
	pr_info("   denom %d, num %d\n", sensor->streamcap.timeperframe.denominator,
		  sensor->streamcap.timeperframe.numerator);
		  
	// if (tgt_fps == 30)
		// frame_rate = ar0521_30_fps;
	// else 
		if (tgt_fps == 27)
		frame_rate = ar0521_27_fps;
	else
		return -EINVAL; /* Only support 15fps or 30fps now. */

	mipi_csi2_info = mipi_csi2_get_info();

	/* enable mipi csi2 */
	if (mipi_csi2_info)
		mipi_csi2_enable(mipi_csi2_info);
	else {
		printk(KERN_ERR "%s() in %s: Fail to get mipi_csi2_info!\n",
		       __func__, __FILE__);
		return -EPERM;
	}

	ret = ar0521_init_mode(frame_rate, ar0521_mode_INIT, ar0521_mode_INIT);

	return ret;
}

/*!
 * ioctl_dev_exit - V4L2 sensor interface handler for vidioc_int_dev_exit_num
 * @s: pointer to standard V4L2 device structure
 *
 * Delinitialize the device when slave detaches to the master.
 */
static int ioctl_dev_exit(struct v4l2_int_device *s)//ahp revisit
{
	void *mipi_csi2_info;

	pr_info("%s\n",__func__);
	
	mipi_csi2_info = mipi_csi2_get_info();

	/* disable mipi csi2 */
	if (mipi_csi2_info)
		if (mipi_csi2_get_status(mipi_csi2_info))
			mipi_csi2_disable(mipi_csi2_info);

	return 0;
}

/*!
 * This structure defines all the ioctls for this module and links them to the
 * enumeration.
 */
static struct v4l2_int_ioctl_desc ar0521_ioctl_desc[] = {
	{vidioc_int_dev_init_num, (v4l2_int_ioctl_func *) ioctl_dev_init},
	{vidioc_int_dev_exit_num, ioctl_dev_exit},
	{vidioc_int_s_power_num, (v4l2_int_ioctl_func *) ioctl_s_power},
	{vidioc_int_g_ifparm_num, (v4l2_int_ioctl_func *) ioctl_g_ifparm},
/*	{vidioc_int_g_needs_reset_num,
				(v4l2_int_ioctl_func *)ioctl_g_needs_reset}, */
/*	{vidioc_int_reset_num, (v4l2_int_ioctl_func *)ioctl_reset}, */
	{vidioc_int_init_num, (v4l2_int_ioctl_func *) ioctl_init},
	{vidioc_int_enum_fmt_cap_num,
				(v4l2_int_ioctl_func *) ioctl_enum_fmt_cap},
/*	{vidioc_int_try_fmt_cap_num,
				(v4l2_int_ioctl_func *)ioctl_try_fmt_cap}, */
	{vidioc_int_g_fmt_cap_num, (v4l2_int_ioctl_func *) ioctl_g_fmt_cap},
/*	{vidioc_int_s_fmt_cap_num, (v4l2_int_ioctl_func *) ioctl_s_fmt_cap}, */
	{vidioc_int_g_parm_num, (v4l2_int_ioctl_func *) ioctl_g_parm},
	{vidioc_int_s_parm_num, (v4l2_int_ioctl_func *) ioctl_s_parm},
/*	{vidioc_int_queryctrl_num, (v4l2_int_ioctl_func *)ioctl_queryctrl}, */
	{vidioc_int_g_ctrl_num, (v4l2_int_ioctl_func *) ioctl_g_ctrl},
	{vidioc_int_s_ctrl_num, (v4l2_int_ioctl_func *) ioctl_s_ctrl},
	{vidioc_int_enum_framesizes_num,
				(v4l2_int_ioctl_func *) ioctl_enum_framesizes},
	{vidioc_int_enum_frameintervals_num,
			(v4l2_int_ioctl_func *) ioctl_enum_frameintervals},
	{vidioc_int_g_chip_ident_num,
				(v4l2_int_ioctl_func *) ioctl_g_chip_ident},
	{vidioc_int_g_register_num,
				(v4l2_int_ioctl_func *) ioctl_g_register},	
	{vidioc_int_s_register_num,
				(v4l2_int_ioctl_func *) ioctl_s_register},				
};

static struct v4l2_int_slave ar0521_slave = {
	.ioctls = ar0521_ioctl_desc,
	.num_ioctls = ARRAY_SIZE(ar0521_ioctl_desc),
};

static struct v4l2_int_device ar0521_int_device = {
	.module = THIS_MODULE,
	.name = "ar0521",
	.type = v4l2_int_type_slave,
	.u = {
		.slave = &ar0521_slave,
	},
};

/*!
 * ar0521 I2C probe function
 *
 * @param adapter            struct i2c_adapter *
 * @return  Error code indicating success or failure
 */
static int ar0521_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	int retval;
	u8 chip_id_high, chip_id_low;
	u16 chip_id;

	pr_info("%s\n",__func__);
	
	/* request power down pin */
#if 0
	pwn_gpio = of_get_named_gpio(dev->of_node, "pwn-gpios", 0);
	if (!gpio_is_valid(pwn_gpio)) {
		dev_warn(dev, "no sensor pwdn pin available");
		return -EINVAL;
	}
	retval = devm_gpio_request_one(dev, pwn_gpio, GPIOF_OUT_INIT_HIGH,
					"ar0521_mipi_pwdn");
	if (retval < 0)
		return retval;
#endif 
#if 1
	/* request reset pin */
	rst_gpio = of_get_named_gpio(dev->of_node, "rst-gpios", 0);
	if (!gpio_is_valid(rst_gpio)) {
		dev_warn(dev, "no sensor reset pin available");
		return -EINVAL;
	}
	retval = devm_gpio_request_one(dev, rst_gpio, GPIOF_OUT_INIT_HIGH,
					"ar0521_mipi_reset");
	if (retval < 0)
		return retval;
#endif
	/* Set initial values for the sensor struct. */
	memset(&ar0521_data, 0, sizeof(ar0521_data));
#if 1
	ar0521_data.sensor_clk = devm_clk_get(dev, "csi_mclk");
	if (IS_ERR(ar0521_data.sensor_clk)) {
		/* assuming clock enabled by default */
		ar0521_data.sensor_clk = NULL;
		dev_err(dev, "clock-frequency missing or invalid\n");
		return PTR_ERR(ar0521_data.sensor_clk);
	}
#endif 

	retval = of_property_read_u32(dev->of_node, "mclk",
					&(ar0521_data.mclk));
	if (retval) {
		dev_err(dev, "mclk missing or invalid\n");
		return retval;
	}

	retval = of_property_read_u32(dev->of_node, "mclk_source",
					(u32 *) &(ar0521_data.mclk_source));
	if (retval) {
		dev_err(dev, "mclk_source missing or invalid\n");
		return retval;
	}

	retval = of_property_read_u32(dev->of_node, "csi_id",
					&(ar0521_data.csi));
	if (retval) {
		dev_err(dev, "csi id missing or invalid\n");
		return retval;
	}

	//clk_prepare_enable(ar0521_data.sensor_clk);
	ar0521_data.streamcap.capturemode = mycapmode;
	
	ar0521_data.io_init = ar0521_reset;
	ar0521_data.i2c_client = client;
	ar0521_data.pix.pixelformat = V4L2_PIX_FMT_GREY;//V4L2_PIX_FMT_UYVY;
	ar0521_data.pix.width = 
		ar0521_mode_info_data[0][mycapmode].width; //640;//2560;//1928;
	ar0521_data.pix.height = 
		ar0521_mode_info_data[0][mycapmode].height;//480;//1440;//1088;
	ar0521_data.streamcap.capability = V4L2_MODE_HIGHQUALITY |
					   V4L2_CAP_TIMEPERFRAME;
	
	ar0521_data.streamcap.timeperframe.denominator = DEFAULT_FPS;
	ar0521_data.streamcap.timeperframe.numerator = 1;

	ar0521_power_on(dev);

	ar0521_reset();

	ar0521_standby(0);

	retval = ar0521_read_reg16(AR0521_CHIP_ID_HIGH_BYTE, &chip_id);
	if (retval < 0 || chip_id != 0x0457) {
		pr_warning("camera ar0521_mipi is not found %04x\n", chip_id);
		//clk_disable_unprepare(ar0521_data.sensor_clk);
		return -ENODEV;
	}
//	ar0521_read_reg16(0x0004, &chip_id);
//	pr_info("should be 0A = %04x\n", chip_id);
//		ar0521_read_reg(0x0004, &chip_id_high);
//	pr_info("should be 0A = %02x\n", chip_id_high);
	
	ar0521_standby(1);

	ar0521_int_device.priv = &ar0521_data;
	retval = v4l2_int_device_register(&ar0521_int_device);

	//clk_disable_unprepare(ar0521_data.sensor_clk);

	pr_info("camera ar0521_mipi is found\n");
	return retval;
}

/*!
 * ar0521 I2C detach function
 *
 * @param client            struct i2c_client *
 * @return  Error code indicating success or failure
 */
static int ar0521_remove(struct i2c_client *client)
{
	pr_info("%s\n",__func__);
	
	v4l2_int_device_unregister(&ar0521_int_device);

	if (gpo_regulator)
		regulator_disable(gpo_regulator);

	if (analog_regulator)
		regulator_disable(analog_regulator);

	if (core_regulator)
		regulator_disable(core_regulator);

	if (io_regulator)
		regulator_disable(io_regulator);

	return 0;
}

/*!
 * ar0521 init function
 * Called by insmod ar0521_camera.ko.
 *
 * @return  Error code indicating success or failure
 */
static __init int ar0521_init(void)
{
	u8 err;

	pr_info("%s\n",__func__);
	
	err = i2c_add_driver(&ar0521_i2c_driver);
	if (err != 0)
		pr_err("%s:driver registration failed, error=%d\n",
			__func__, err);

	return err;
}

/*!
 * ar0521 cleanup function
 * Called on rmmod ar0521_camera.ko
 *
 * @return  Error code indicating success or failure
 */
static void __exit ar0521_clean(void)
{
	pr_info("%s\n",__func__);
	
	i2c_del_driver(&ar0521_i2c_driver);
}



module_init(ar0521_init);
module_exit(ar0521_clean);

MODULE_AUTHOR("Viavi");
MODULE_DESCRIPTION("AR0521 MIPI Camera Driver");
MODULE_LICENSE("GPL");
MODULE_VERSION("1.0");
MODULE_ALIAS("CSI");

