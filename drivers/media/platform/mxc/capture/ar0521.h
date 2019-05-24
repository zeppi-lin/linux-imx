#define AR0521_Reset {0x0103, 0x01, 0x0, 100, 1}

#define AR0521_Native_Full_32FPS_2600x1952_12bit \
				AR0521_Reset, \
				AR0521_stream_5M_32fps_12bit

#define AR0521_Native_Full_30FPS_2600x1952_12bit  \
				AR0521_Reset, \
				AR0521_stream_5M_32fps_12bit, \
				{0x300A, 0x09C8, 0x0, 0x0, 2}

#define AR0521_Native_Full_60FPS_2600x1952_10bit   \
				AR0521_Reset, \
				AR0521_stream_5M_60fps_10bit

// #define AR0521_Native_Full_60FPS_2600x1952_10bit_Hispi \
				// AR0521_Reset, \
				// AR0521_stream_5M_60fps_10bit_Hispi


#define AR0521_Native_Full_60FPS_2560x1440_10bit \
				AR0521_Reset, \
				AR0521_stream_quadHD_60fps_10bit

#define AR0521_Native_Full_30FPS_2560x1440_10bit \
				AR0521_Reset, \
				AR0521_stream_quadHD_60fps_10bit, \
				{0x300A, 0x11B8, 0, 0, 2}  /* FRAME_LENGTH_LINES_ */
				
#define AR0521_Native_Full_90FPS_1288x728_10bit   \
				AR0521_Reset, \
				AR0521_stream_720p_90fps_10bit, \
				{0x3012, 0x05E4, 0, 0, 2}, /* COARSE_INTEGRATION_TIME_ */ \
				{0x300A, 0x05EA, 0, 0, 2}, /* FRAME_LENGTH_LINES_*/ \
				{0x300C, 0x0BE0, 0, 0, 2} /* LINE_LENGTH_PCK_*/

#define AR0521_Native_Full_120FPS_VGA_mode_10bit   \
				AR0521_Reset, \
				AR0521_stream_VGA_120fps_10bit, \
				{0x300A, 0x046F, 0, 0, 2}, /* FRAME_LENGTH_LINES_*/ \
				{0x3012, 0x046B, 0, 0, 2}, /* COARSE_INTEGRATION_TIME_*/ \
				{0x300C, 0x0BE0, 0, 0, 2} /* LINE_LENGTH_PCK_*/

#define AR0521_Native_Full_51p2FPS_2560x1440_12bit \
				AR0521_Reset, \
				AR0521_stream_quadHD_60fps_12bit, \
				{0x300A, 0x05BC, 0, 0, 2} /* FRAME_LENGTH_LINES_*/

#define AR0521_Native_Full_30FPS_2560x1440_12bit \
				AR0521_Reset, \
				AR0521_stream_quadHD_60fps_12bit, \
				{0x300A, 0x09C8, 0, 0, 2} /* FRAME_LENGTH_LINES_*/
				
#define AR0521_Native_Full_86FPS_1288x728_12bit \
				AR0521_Reset, \
				AR0521_stream_720p_90fps_12bit, \
				{0x300C, 0x1178, 0, 0, 2}, /* LINE_LENGTH_PCK_*/ \
				{0x300A, 0x0368, 0, 0, 2}, /* FRAME_LENGTH_LINES_*/ \
				{0x3012, 0x0364, 0, 0, 2}  /* COARSE_INTEGRATION_TIME_*/

#define AR0521_Native_Full_120FPS_VGA_mode_12bit \
				AR0521_Reset, \
				AR0521_stream_VGA_120fps_12bit, \
				{0x300C, 0x1178, 0, 0, 2} /* LINE_LENGTH_PCK_*/

#define AR0521_Native_Full_16FPS_2600x1952_12bit_HDR_MIPI_VC \
				AR0521_Reset, \
				AR0521_disable_streaming, \
				AR0521_analog_setup_recommended_1080p_12bit_HDR, \
				AR0521_HDR_mode, \
				{0x3400, 0x012A, 0, 0, 2},  /*T1_T2_INTERVAL*/ \
				{0x3012, 0x0271, 0, 0, 2},  /*COARSE_INTEGRATION_TIME 625*/ \
				{0x3088, 0x009C, 0, 0, 2},  /*COARSE_INTEGRATION2_TIME 156*/ \
				{0x3220, 0x002C, 0, 0, 2}, \
				AR0521_enable_streaming			
				
#define AR0521_Native_Full_30FPS_2600x1952_10bit_HDR_MIPI_VC \
				AR0521_Reset, \
				AR0521_stream_5M_60fps_10bit, \
				AR0521_disable_streaming, \
				AR0521_analog_setup_recommended_1080p_12bit_HDR, \
				AR0521_analog_setup_recommended_10bit, \
				AR0521_HDR_mode, \
				{0x3400, 0x0120, 0, 0, 2},  /*T1_T2_INTERVAL*/ \
				{0x3012, 0x046D, 0, 0, 2},  /*COARSE_INTEGRATION_TIME 1133*/ \
				{0x3088, 0x011B, 0, 0, 2},  /*COARSE_INTEGRATION2_TIME 283*/ \
				{0x3220, 0x002B, 0, 0, 2}, \
				AR0521_enable_streaming


#define AR0521_Native_1080p_60FPS_1928x1088_12bit \
				AR0521_Reset, \
				AR0521_stream_1080p_60fps_12bit


#define AR0521_Native_1080p_60FPS_1928x1088_10bit \
				AR0521_Reset, \
				AR0521_stream_1080p_60fps_10bit 
				
#define AR0521_Native_1080p_30FPS_1928x1088_12bit_HDR_MIPI_VC \
				AR0521_Reset, \
				AR0521_stream_1080p_60fps_12bit, \
				AR0521_disable_streaming, \
				AR0521_analog_setup_recommended_12bit_HDR, \
				AR0521_HDR_mode, \
				{0x3400, 0x0088, 0, 0, 2},  /*T1_T2_INTERVAL*/ \
				{0x3012, 0x0271, 0, 0, 2},  /*COARSE_INTEGRATION_TIME */ \
				{0x3088, 0x009C, 0, 0, 2},  /*COARSE_INTEGRATION2_TIME */ \
				{0x3220, 0x002C, 0, 0, 2}, \
				AR0521_enable_streaming


#define AR0521_Native_1080p_30FPS_1928x1088_10bit_HDR_MIPI_VC \
				AR0521_Reset, \
				AR0521_stream_1080p_60fps_10bit, \
				AR0521_disable_streaming, \
				AR0521_analog_setup_recommended_12bit_HDR, \
				AR0521_analog_setup_recommended_10bit, \
				AR0521_HDR_mode, \
				{0x3400, 0x0120, 0, 0, 2},  /*T1_T2_INTERVAL*/ \
				{0x3012, 0x046D, 0, 0, 2},  /*COARSE_INTEGRATION_TIME 1133*/ \
				{0x3088, 0x011B, 0, 0, 2},  /*COARSE_INTEGRATION2_TIME 283*/ \
				{0x3220, 0x002B, 0, 0, 2}, \
				AR0521_enable_streaming



//[=== Demo3 ==]
#define AR0521_Native_Full_27FPS_2600x1952_12bit \
				AR0521_Reset, \
				AR0521_stream_5M_27fps_12bit


#define AR0521_Native_Full_50FPS_2600x1952_10bit \
				AR0521_Reset, \
				AR0521_stream_5M_50fps_10bit

#define AR0521_Native_Full_50FPS_2600x1952_8bit \
				AR0521_Reset, \
				{0x3012, 0x0489, 0, 0, 2},  /*COARSE_INTEGRATION_TIME 1133*/ \
				AR0521_stream_5M_50fps_8bit

#define AR0521_Native_Full_27FPS_2560x1440_8bit \
				AR0521_Reset, \
				AR0521_stream_quadHD_27fps_8bit

#define AR0521_Native_Full_27FPS_1280x720_8bit \
				AR0521_Reset, \
				AR0521_stream_720p_27fps_8bit
				
#define AR0521_Native_Full_27FPS_1288x728_8bit \
				AR0521_Reset, \
				AR0521_stream_720p_27fps_8bit
				
#define AR0521_Native_Full_27FPS_VGA_mode_8bit \
				AR0521_Reset, \
				AR0521_stream_VGA_27fps_8bit
				
#define AR0521_Native_1080p_27FPS_1928x1088_8bit \
				AR0521_Reset, \
				AR0521_stream_1080p_27fps_8bit 				
				
#define AR0521_Native_Full_13FPS_2600x1952_12bit_HDR_MIPI_VC \
				AR0521_Reset, \
				AR0521_stream_5M_27fps_12bit, \
				AR0521_disable_streaming, \
				AR0521_analog_setup_recommended_1080p_12bit_HDR, \
				AR0521_HDR_mode, \
				{0x3400, 0x012A, 0, 0, 2}, /*T1_T2_INTERVAL*/ \
				{0x3012, 0x0271, 0, 0, 2}, /*COARSE_INTEGRATION_TIME 625*/ \
				{0x3088, 0x009C, 0, 0, 2}, /*COARSE_INTEGRATION2_TIME 156*/ \
				{0x3220, 0x002C, 0, 0, 2}, \
				AR0521_enable_streaming


#define AR0521_Native_Full_25FPS_2600x1952_10bit_HDR_MIPI_VC \
				AR0521_Reset, \
				AR0521_stream_5M_50fps_10bit, \
				AR0521_disable_streaming, \
				AR0521_HDR_mode, \
				{0x3400, 0x0120, 0, 0, 2},  /*T1_T2_INTERVAL*/ \
				{0x3012, 0x046D, 0, 0, 2}, /*COARSE_INTEGRATION_TIME 1133*/ \
				{0x3088, 0x011B, 0, 0, 2},  /*COARSE_INTEGRATION2_TIME 283*/ \
				{0x3220, 0x002B, 0, 0, 2}, \
				AR0521_enable_streaming


#define AR0521_Native_1080p_56FPS_1928x1088_12bit\
				AR0521_Reset, \
				AR0521_stream_1080p_56fps_12bit


#define AR0521_Native_1080p_60FPS_1928x1088_10bit_2 \
				AR0521_Reset, \
				AR0521_stream_1080p_60fps_10bit_2

#define AR0521_Native_1080p_28FPS_1928x1088_12bit_HDR_MIPI_VC \
				AR0521_Reset, \
				AR0521_stream_1080p_56fps_12bit, \
				AR0521_disable_streaming, \
				AR0521_analog_setup_recommended_12bit_HDR, \
				AR0521_HDR_mode, \
				{0x3400, 0x0088, 0, 0, 2}, /*T1_T2_INTERVAL*/ \
				{0x3012, 0x0271, 0, 0, 2}, /*COARSE_INTEGRATION_TIME */ \
				{0x3088, 0x009C, 0, 0, 2}, /*COARSE_INTEGRATION2_TIME */ \
				{0x3220, 0x002C, 0, 0, 2}, \
				AR0521_enable_streaming


#define AR0521_Native_1080p_30FPS_1928x1088_10bit_2_HDR_MIPI_VC \
				AR0521_Reset, \
				AR0521_stream_1080p_60fps_10bit_2, \
				AR0521_disable_streaming, \
				AR0521_analog_setup_recommended_12bit_HDR, \
				AR0521_analog_setup_recommended_10bit, \
				AR0521_HDR_mode, \
				{0x3400, 0x0120, 0, 0, 2}, /*T1_T2_INTERVAL*/ \
				{0x3012, 0x046D, 0, 0, 2}, /*COARSE_INTEGRATION_TIME 1133*/ \
				{0x3088, 0x011B, 0, 0, 2}, /*COARSE_INTEGRATION2_TIME 283*/ \
				{0x3220, 0x002B, 0, 0, 2}, \
				AR0521_enable_streaming

#define AR0521_powerup \
				AR0521_Reset
//XMCLK=27000000	
//STATE=Sensor Reset, 1
//STATE=Sensor Reset, 0
//DELAY=100

#define AR0521_pll_setup_max_12bit \
				{0x0304, 0x0303, 0, 0, 2}, /*pre_pll_clk_div*/ \
				{0x0306, 0x7059, 0, 0, 2}, /*pll_multiplier*/ \
				{0x0302, 0x0001, 0, 0, 2}, /*vt_sys_clk_div*/ \
				{0x030A, 0x0001, 0, 0, 2}, /*op_sys_clk_div*/ \
				{0x0300, 0x0006, 0, 0, 2}, /*vt_pix_clk_div*/ \
				{0x0308, 0x000C, 0, 0, 2}, /*op_pix_clk_div*/ \
				{0x3016, 0x0111, 0, 0, 2} /*op/pc speed??*/ 

#define AR0521_pll_setup_max_10bit \
				{0x0304, 0x0303, 0, 0, 2}, /*pre_pll_clk_div*/ \
				{0x0306, 0x7359, 0, 0, 2}, /*pll_multiplier*/ \
				{0x0302, 0x0001, 0, 0, 2}, /*vt_sys_clk_div*/ \
				{0x030A, 0x0001, 0, 0, 2}, /*op_sys_clk_div*/ \
				{0x0300, 0x0005, 0, 0, 2}, /*vt_pix_clk_div*/ \
				{0x0308, 0x000A, 0, 0, 2}, /*op_pix_clk_div*/ \
				{0x3016, 0x0101, 0, 0, 2} /*op/pc speed*/ 

#define AR0521_pll_setup_max_8bit \
				{0x0304, 0x0303, 0, 0, 2}, /*pre_pll_clk_div*/ \
				{0x0306, 0x5C59, 0, 0, 2}, /*pll_multiplier*/ \
				{0x0302, 0x0001, 0, 0, 2}, /*vt_sys_clk_div*/ \
				{0x030A, 0x0001, 0, 0, 2}, /*op_sys_clk_div*/ \
				{0x0300, 0x0004, 0, 0, 2}, /*vt_pix_clk_div*/ \
				{0x0308, 0x0008, 0, 0, 2}, /*op_pix_clk_div*/ \
				{0x3016, 0x0101, 0, 0, 2} /*op/pc speed*/ 

#define AR0521_pll_setup_max_8bit \
				{0x0304, 0x0303, 0, 0, 2}, /*pre_pll_clk_div*/ \
				{0x0306, 0x5C59, 0, 0, 2}, /*pll_multiplier*/ \
				{0x0302, 0x0001, 0, 0, 2}, /*vt_sys_clk_div*/ \
				{0x030A, 0x0001, 0, 0, 2}, /*op_sys_clk_div*/ \
				{0x0300, 0x0004, 0, 0, 2}, /*vt_pix_clk_div*/ \
				{0x0308, 0x0008, 0, 0, 2}, /*op_pix_clk_div*/ \
				{0x3016, 0x0101, 0, 0, 2} /*op/pc speed*/ 

#define AR0521_pll_setup_846Mhz_12bit \
				{0x0300, 0x0006, 0, 0, 2}, /*VT_PIX_CLK_DIV=6*/ \
				{0x0302, 0x0001, 0, 0, 2}, /*VT_SYS_CLK_DIV=1*/ \
				{0x0304, 0x0303, 0, 0, 2}, /*PRE_PLL_CLK_DIV2=3// PRE_PLL_CLK_DIV1=3*/ \
				{0x0306, 0x5E48, 0, 0, 2}, /*PLL_MULTIPLIER2=94// PLL_MULTIPLIER1=72*/ \
				{0x0308, 0x000C, 0, 0, 2}, /*OP_PIX_CLK_DIV=12*/ \
				{0x030A, 0x0001, 0, 0, 2}, /*OP_SYS_CLK_DIV=1*/ \
				{0x3016, 0x0111, 0, 0, 2} /*op/pc speed*/ 

#define AR0521_pll_setup_846Mhz_10bit \
				{0x0300, 0x0005, 0, 0, 2}, /*VT_PIX_CLK_DIV=5*/ \
				{0x0302, 0x0001, 0, 0, 2}, /*VT_SYS_CLK_DIV=1*/ \
				{0x0304, 0x0303, 0, 0, 2}, /*PRE_PLL_CLK_DIV2=3// PRE_PLL_CLK_DIV1=3*/ \
				{0x0306, 0x5E48, 0, 0, 2}, /*PLL_MULTIPLIER2=94// PLL_MULTIPLIER1=72*/ \
				{0x0308, 0x000A, 0, 0, 2}, /*OP_PIX_CLK_DIV=10*/ \
				{0x030A, 0x0001, 0, 0, 2}, /*OP_SYS_CLK_DIV=1*/ \
				{0x3016, 0x0101, 0, 0, 2} /*op/pc speed*/ 

#define AR0521_pll_setup_846Mhz_8bit \
				{0x0300, 0x0004, 0, 0, 2}, /*VT_PIX_CLK_DIV=5*/ \
				{0x0302, 0x0001, 0, 0, 2}, /*VT_SYS_CLK_DIV=1*/ \
				{0x0304, 0x0303, 0, 0, 2}, /*PRE_PLL_CLK_DIV2=3// PRE_PLL_CLK_DIV1=3*/ \
				{0x0306, 0x5C59, 0, 0, 2}, /*PLL_MULTIPLIER2=94// PLL_MULTIPLIER1=72*/ \
				{0x0308, 0x0008, 0, 0, 2}, /*OP_PIX_CLK_DIV=10*/ \
				{0x030A, 0x0001, 0, 0, 2}, /*OP_SYS_CLK_DIV=1*/ \
				{0x3016, 0x0101, 0, 0, 2} /*op/pc speed*/ 

#define AR0521_analog_setup_recommended_12bit \
				{0x3EB6, 0x004C, 0, 0, 2}, /*ECL*/ \
				{0x3EBA, 0xAAAA, 0, 0, 2}, \
				{0x3EBC, 0x0086, 0, 0, 2}, /*Bias currents for FSC/ECL*/ \
				{0x3EC0, 0x1E00, 0, 0, 2}, /*SFbin/SH mode settings*/ \
				{0x3EC2, 0x100B, 0, 0, 2}, /*CLK divider for ramp for 12bit 400MHz mode only*/ \
				{0x3EC4, 0x3300, 0, 0, 2}, /*FSC clamps for HDR mode and adc comp power down co*/ \
				{0x3EC6, 0xEA44, 0, 0, 2}, /*VLN and clk gating controls*/ \
				{0x3EC8, 0x6F6F, 0, 0, 2}, /*Txl0 and Txlo1 settings for normal mode*/ \
				{0x3ECA, 0x2F4A, 0, 0, 2}, /*CDAC/Txlo2/RSTGHI/RSTGLO settings*/ \
				{0x3ECC, 0x0506, 0, 0, 2}, /*RSTDHI/RSTDLO/CDAC/TXHI settings*/ \
				{0x3ECE, 0x203B, 0, 0, 2}, /*Ramp buffer settings and Booster enable (bits 0-5)*/ \
				{0x3ED0, 0x13F0, 0, 0, 2}, /*TXLO from atest/sf bin settings*/ \
				{0x3ED2, 0x9A3D, 0, 0, 2}, /*Booster settings for reference rows/columns*/ \
				{0x3ED4, 0x862F, 0, 0, 2}, /*TXLO open loop/row driver settings*/ \
				{0x3ED6, 0x4081, 0, 0, 2}, /*Txlatch fr cfpn rows/vln bias*/ \
				{0x3ED8, 0x4003, 0, 0, 2}, /*Ramp step setting for 12bit 400 Mhz mode*/ \
				{0x3EDA, 0x9A80, 0, 0, 2}, /*ramp offset for T1/normal and rst under range*/ \
				{0x3EDC, 0xC000, 0, 0, 2}, /*over range for rst and under range for sig*/ \
				{0x3EDE, 0xC103, 0, 0, 2}, /*over range for sig and col dec clk settings*/ \
				{0x3426, 0x1600, 0, 0, 2}, /*ADC offset distribution pulse*/ \
				{0x342A, 0x0038, 0, 0, 2}, /*pulse_config*/ \
				{0x3F3E, 0x0001, 0, 0, 2}, /*Switch ADC from 10bit to 12bit mode*/ \
				{0x341A, 0x6051, 0, 0, 2}, \
				{0x3420, 0x6051, 0, 0, 2}

#define AR0521_analog_setup_recommended_12bit_HDR \
				{0x3EB6, 0x004C, 0, 0, 2}, /*ECL*/ \
				{0x3EBA, 0xAAAA, 0, 0, 2}, \
				{0x3EBC, 0x0086, 0, 0, 2}, \
				{0x3EBE, 0x0080, 0, 0, 2}, \
				{0x3EC0, 0x1E00, 0, 0, 2}, \
				{0x3EC2, 0x100B, 0, 0, 2}, \
				{0x3EC4, 0x3300, 0, 0, 2}, \
				{0x3EC6, 0xEA06, 0, 0, 2}, \
				{0x3EC8, 0x6F6F, 0, 0, 2}, \
				{0x3ECA, 0x2F4A, 0, 0, 2}, \
				{0x3ECC, 0x0506, 0, 0, 2}, \
				{0x3ECE, 0x203F, 0, 0, 2}, \
				{0x3ED0, 0x13F0, 0, 0, 2}, \
				{0x3ED2, 0x9A3D, 0, 0, 2}, \
				{0x3ED4, 0x862F, 0, 0, 2}, \
				{0x3ED6, 0x4081, 0, 0, 2}, \
				{0x3ED8, 0x4003, 0, 0, 2}, \
				{0x3EDA, 0x9A80, 0, 0, 2}, \
				{0x3EDC, 0xC000, 0, 0, 2}, \
				{0x3EDE, 0xC103, 0, 0, 2}, \
				{0x3EE0, 0x0000, 0, 0, 2}, \
				{0x341A, 0x6051, 0, 0, 2}, \
				{0x3420, 0x6051, 0, 0, 2}, \
				{0x3426, 0x1600, 0, 0, 2}, \
				{0x342A, 0x0038, 0, 0, 2}, \
				{0x3F3E, 0x0001, 0, 0, 2}

#define AR0521_analog_setup_recommended_1080p_12bit_HDR \
				{0x3EB6, 0x004C, 0, 0, 2}, \
				{0x3EBA, 0xAAAA, 0, 0, 2}, \
				{0x3EBC, 0x0086, 0, 0, 2}, \
				{0x3EBE, 0x0080, 0, 0, 2}, \
				{0x3EC0, 0x1E00, 0, 0, 2}, \
				{0x3EC2, 0x100B, 0, 0, 2}, \
				{0x3EC4, 0x3300, 0, 0, 2}, \
				{0x3EC6, 0xEA06, 0, 0, 2}, \
				{0x3EC8, 0x6F6F, 0, 0, 2}, \
				{0x3ECA, 0x2F4A, 0, 0, 2}, \
				{0x3ECC, 0x0506, 0, 0, 2}, \
				{0x3ECE, 0x203F, 0, 0, 2}, \
				{0x3ED0, 0x13F0, 0, 0, 2}, \
				{0x3ED2, 0x9A3D, 0, 0, 2}, \
				{0x3ED4, 0x862F, 0, 0, 2}, \
				{0x3ED6, 0x4081, 0, 0, 2}, \
				{0x3ED8, 0x4003, 0, 0, 2}, \
				{0x3EDA, 0x9A80, 0, 0, 2}, \
				{0x3EDC, 0xC000, 0, 0, 2}, \
				{0x3EDE, 0xC103, 0, 0, 2}, \
				{0x3EE0, 0x0000, 0, 0, 2}, \
				{0x341A, 0x6051, 0, 0, 2}, \
				{0x3420, 0x6051, 0, 0, 2}, \
				{0x3426, 0x1600, 0, 0, 2}, \
				{0x342A, 0x0038, 0, 0, 2}, \
				{0x3F3E, 0x0001, 0, 0, 2} 



#define AR0521_analog_setup_recommended_10bit \
				{0x3EC2, 0x100A, 0, 0, 2}, /*CLK divider for ramp for 10bit 400MH*/ \
				{0x3ED8, 0x8003, 0, 0, 2}, /*Ramp step setting for 10bit 400 Mhz*/ \
				{0x341A, 0x4735, 0, 0, 2}, /*Samp &Hold pulse in ADC*/ \
				{0x3420, 0x4735, 0, 0, 2}, /*Samp &Hold pulse in ADC*/ \
				{0x3426, 0x8A1A, 0, 0, 2}, /*ADC offset distribution pulse*/ \
				{0x342A, 0x0018, 0, 0, 2}, /*pulse_config*/ \
				{0x3ED2, 0xA53D, 0, 0, 2}, /*Ramp offset*/ \
				{0x3EDA, 0xA580, 0, 0, 2}, /*Ramp Offset*/ \
				{0x3EBA, 0xAAAD, 0, 0, 2}, \
				{0x3EB6, 0x004C, 0, 0, 2}, \
				{0x3F3E, 0x0000, 0, 0, 2} /*Switch ADC from 12bit to 10bit mode*/ 

#define AR0521_corrections_recommended    AR0521_corrections_recommended_mono
//IF_REG = 0x31FE, 0x0070, == 2, 				AR0521_corrections_recommended_mono, ELSE				AR0521_corrections_recommended_bayer

#define AR0521_corrections_recommended_bayer \
				{0x3042, 0x0004, 0, 0, 2}, /*RNC:enable b/w rnc mode*/ \
				{0x3044, 0x4580, 0, 0, 2}, /*RNC:enable row noise correction*/ \
				{0x30EE, 0x1136, 0, 0, 2}, /*RNC:rnc scaling factor-->inital recommended settin*/ \
				{0x3120, 0x0001, 0, 0, 2}, /*recommended setting for dither*/ \
				{0x3F2C, 0x442E, 0, 0, 2}, /*GTH_THRES_RTN: 7max,7min filtered out of every 46*/ \
				{0x30D2, 0x0000, 0, 0, 2}, /*CRM/CC: enable crm on Visible and CC rows*/ \
				{0x30D4, 0x0000, 0, 0, 2}, /*CC: CC enabled with 16 samples per column*/ \
				{0x30D6, 0x2FFF, 0, 0, 2}, /*CC: bw mode enabled/12bit data resolution/bw mode*/ \
				{0x30DA, 0x0FFF, 0, 0, 2}, /*CC: column correction clip level 2 is 0*/ \
				{0x30DC, 0x0FFF, 0, 0, 2}, /*CC: column correction clip level 3 is 0*/ \
				{0x30DE, 0x0000, 0, 0, 2}, /*CC: Group FPN correction*/ \
				{0x31E0, 0x0781, 0, 0, 2}, /*Fuse/2DDC: enable 2ddc*/ \
				{0x3180, 0x9434, 0, 0, 2}, /*FDOC:fdoc settings with fdoc every frame turned of*/ \
				{0x3172, 0x0206, 0, 0, 2}, /*txlo clk divider options*/ \
				{0x3F00, 0x0017, 0, 0, 2}, /*BM_T0*/ \
				{0x3F02, 0x02DD, 0, 0, 2}, /*BM_T1*/ \
				{0x3F04, 0x0020, 0, 0, 2}, /*if Ana_gain less than 2, use noise_floor0, multipl*/ \
				{0x3F06, 0x0040, 0, 0, 2}, /*if Ana_gain between 4 and 7, use noise_floor2 and*/ \
				{0x3F08, 0x0070, 0, 0, 2}, /*if Ana_gain between 4 and 7, use noise_floor2 and*/ \
				{0x3F0A, 0x0101, 0, 0, 2}, /*Define noise_floor0(low address) and noise_floor1*/ \
				{0x3F0C, 0x0302, 0, 0, 2}, /*Define noise_floor2 and noise_floor3*/ \
				{0x3F1E, 0x0022, 0, 0, 2}, \
				{0x3F1A, 0x01FF, 0, 0, 2}, /*cross factor 2*/ \
				{0x3F14, 0x0505, 0, 0, 2}, /*single k factor 2*/ \
				{0x3F44, 0x0707, 0, 0, 2}, /*couple k factor 2*/ \
				{0x3F18, 0x01FF, 0, 0, 2}, /*cross factor 1*/ \
				{0x3F12, 0x0505, 0, 0, 2}, /*single k factor 1*/ \
				{0x3F42, 0x1511, 0, 0, 2}, /*couple k factor 1*/ \
				{0x3F16, 0x01FF, 0, 0, 2}, /*cross factor 0*/ \
				{0x3F10, 0x0505, 0, 0, 2}, /*single k factor 0*/ \
				{0x3F40, 0x1511, 0, 0, 2} /*couple k factor 0*/ 
				
#define AR0521_corrections_recommended_mono \
				{0x3042, 0x0004, 0, 0, 2}, /*RNC:enable b/w rnc mode*/ \
				{0x3044, 0x4580, 0, 0, 2}, /*RNC:enable row noise correction*/ \
				{0x30EE, 0x1136, 0, 0, 2}, /*RNC:rnc scaling factor-->inital recommended settin*/ \
				{0x3120, 0x0001, 0, 0, 2}, /*recommended setting for dither*/ \
				{0x3F2C, 0x442E, 0, 0, 2}, /*GTH_THRES_RTN: 7max,7min filtered out of every 46*/ \
				{0x30D2, 0x0000, 0, 0, 2}, /*CRM/CC: enable crm on Visible and CC rows*/ \
				{0x30D4, 0x0000, 0, 0, 2}, /*CC: CC enabled with 16 samples per column*/ \
				{0x30D6, 0x2FFF, 0, 0, 2}, /*CC: bw mode enabled/12bit data resolution/bw mode*/ \
				{0x30DA, 0x0FFF, 0, 0, 2}, /*CC: column correction clip level 2 is 0*/ \
				{0x30DC, 0x0FFF, 0, 0, 2}, /*CC: column correction clip level 3 is 0*/ \
				{0x30DE, 0x0000, 0, 0, 2}, /*CC: Group FPN correction*/ \
				{0x31E0, 0x0781, 0, 0, 2}, /*Fuse/2DDC: enable 2ddc*/ \
				{0x3180, 0x9434, 0, 0, 2}, /*FDOC:fdoc settings with fdoc every frame turned of*/ \
				{0x3172, 0x0206, 0, 0, 2}, /*txlo clk divider options*/ \
				{0x3F00, 0x0017, 0, 0, 2}, /*BM_T0*/ \
				{0x3F02, 0x02DD, 0, 0, 2}, /*BM_T1*/ \
				{0x3F04, 0x0020, 0, 0, 2}, /*if Ana_gain less than 2, use noise_floor0, multipl*/ \
				{0x3F06, 0x0040, 0, 0, 2}, /*if Ana_gain between 4 and 7, use noise_floor2 and*/ \
				{0x3F08, 0x0070, 0, 0, 2}, /*if Ana_gain between 4 and 7, use noise_floor2 and*/ \
				{0x3F0A, 0x0101, 0, 0, 2}, /*Define noise_floor0(low address) and noise_floor1*/ \
				{0x3F0C, 0x0302, 0, 0, 2}, /*Define noise_floor2 and noise_floor3*/ \
				{0x3F1E, 0x0022, 0, 0, 2}, \
				{0x3F1A, 0x0103, 0, 0, 2}, /*cross factor 2*/ \
				{0x3F14, 0x0505, 0, 0, 2}, /*single k factor 2*/ \
				{0x3F44, 0x1515, 0, 0, 2}, /*couple k factor 2*/ \
				{0x3F18, 0x0103, 0, 0, 2}, /*cross factor 1*/ \
				{0x3F12, 0x0505, 0, 0, 2}, /*single k factor 1*/ \
				{0x3F42, 0x1515, 0, 0, 2}, /*couple k factor 1*/ \
				{0x3F16, 0x0103, 0, 0, 2}, /*cross factor 0*/ \
				{0x3F10, 0x0505, 0, 0, 2}, /*single k factor 0*/ \
				{0x3F40, 0x1515, 0, 0, 2} /*couple k factor 0*/ 

#define AR0521_corrections_disable \
				{0x301A, 0x0210, 0, 0, 2}, /*unlock reg*/ \
				{0x304A, 0x0038, 0, 0, 2}, /*Trigger automatic OTPM read sequence*/ \
				{0x3044, 0x4180, 0, 0, 2}, /*RNC: disable rnc correction*/ \
				{0x30D2, 0x0001, 0, 0, 2}, /*CRM:disable crm*/ \
				{0x30D4, 0x0000, 0, 0, 2}, /*CC:disable cfpn correction*/ \
				{0x31E0, 0x0000, 0, 0, 2}, /*Fuse/2DDC:disable fuse tagging and correction*/ \
				{0x3180, 0x00FF, 0, 0, 2}, /*FDOC:disable fdoc correction*/ \
				{0x301E, 0x0000, 0, 0, 2}, /*PEDESTAL:pedestal=0*/ \
				{0x30DE, 0x0000, 0, 0, 2}, /*clear group fpn?*/ \
				{0x3120, 0x0000, 0, 0, 2} /*Disable dither*/ 
				
#define AR0521_new_RNC_12bit \
				{0x30EE, 0x1136, 0, 0, 2}, /* RNC:rnc scaling factor=*54/64 (32/38*64=53.9)*/ \
				{0x3F2C, 0x442E, 0, 0, 2}, /* GTH_THRES_RTN: 4max,4min filtered out of every 46 samples and becomes 38 samples.*/ \
											/*for 12bit mode*/ \
				{0x301A, 0x0210, 0, 0, 2}, \
				{0x301E, 0x0000, 0, 0, 2}, /* PEDESTAL was 0x00a8*/ \
				{0x301A, 0x0218, 0, 0, 2}, \
				{0x3120, 0x0001, 0, 0, 2} /* p1 dither enabled for 12bit mode*/ 
				
#define AR0521_new_RNC_10bit \
				{0x30EE, 0x1136, 0, 0, 2}, /* RNC:rnc scaling factor=*54/64 (32/38*64=53.9)*/ \
				{0x3F2C, 0x442E, 0, 0, 2}, /* GTH_THRES_RTN: 4max,4min filtered out of every 46 samples and */ \
											/*for 10bit mode*/ \
				{0x301A, 0x0210, 0, 0, 2}, \
				{0x301E, 0x0000, 0, 0, 2}, /* was 0x00aa PEDESTAL+2 :+2 is a workaround for 10bit mode +0.5 Rounding*/ \
				{0x301A, 0x0218, 0, 0, 2}, \
				{0x3120, 0x0005, 0, 0, 2} /* p1 dither enabled for 10bit mode*/ \

#define AR0521_Defect_correction_12bit \
				{0x3F00, 0x0024, 0, 0, 2}, /*BM_T0, 66ms@2x Again.*/ \
				{0x3F02, 0x0139, 0, 0, 2}, /*BM_T1, 66ms@8x Again.*/ \
				{0x3F04, 0x0020, 0, 0, 2}, /*if Ana_gain less than 2, use noise_floor0, multipl*/ \
				{0x3F06, 0x0040, 0, 0, 2}, /*if Ana_gain between 4 and 7, use noise_floor2 and*/ \
				{0x3F08, 0x0070, 0, 0, 2}, /*if Ana_gain between 4 and 7, use noise_floor2 and*/ \
				{0x3F0A, 0x0201, 0, 0, 2}, /*Define noise_floor0(low address) and noise_floor1*/ \
				{0x3F0C, 0x0804, 0, 0, 2}, /*Define noise_floor2 and noise_floor3*/ \
				{0x3F1E, 0x0022, 0, 0, 2}, \
				{0x3F1A, 0x01FF, 0, 0, 2}, /*cross factor 2*/ \
				{0x3F14, 0x0505, 0, 0, 2}, /*single k factor 2*/ \
				{0x3F44, 0x0707, 0, 0, 2}, /*couple k factor 2*/ \
				{0x3F18, 0x01FF, 0, 0, 2}, /*cross factor 1*/ \
				{0x3F12, 0x0505 , 0, 0, 2}, /*single k factor 1*/ \
				{0x3F42, 0x1511, 0, 0, 2}, /*couple k factor 1*/ \
				{0x3F16, 0x01FF, 0, 0, 2}, /*cross factor 0*/ \
				{0x3F10, 0x0505, 0, 0, 2}, /*single k factor 0*/ \
				{0x3F40, 0x1511, 0, 0, 2} /*couple k factor 0*/ 
 
#define AR0521_pixel_timing_recommended \
				{0x3D00, 0x043E, 0, 0, 2}, \
				{0x3D02, 0x4760, 0, 0, 2}, \
				{0x3D04, 0xFFFF, 0, 0, 2}, \
				{0x3D06, 0xFFFF, 0, 0, 2}, \
				{0x3D08, 0x8000, 0, 0, 2}, \
				{0x3D0A, 0x0510, 0, 0, 2}, \
				{0x3D0C, 0xAF08, 0, 0, 2}, \
				{0x3D0E, 0x0252, 0, 0, 2}, \
				{0x3D10, 0x486F, 0, 0, 2}, \
				{0x3D12, 0x5D5D, 0, 0, 2}, \
				{0x3D14, 0x8056, 0, 0, 2}, \
				{0x3D16, 0x8313, 0, 0, 2}, \
				{0x3D18, 0x0087, 0, 0, 2}, \
				{0x3D1A, 0x6A48, 0, 0, 2}, \
				{0x3D1C, 0x6982, 0, 0, 2}, \
				{0x3D1E, 0x0280, 0, 0, 2}, \
				{0x3D20, 0x8359, 0, 0, 2}, \
				{0x3D22, 0x8D02, 0, 0, 2}, \
				{0x3D24, 0x8020, 0, 0, 2}, \
				{0x3D26, 0x4882, 0, 0, 2}, \
				{0x3D28, 0x4269, 0, 0, 2}, \
				{0x3D2A, 0x6A95, 0, 0, 2}, \
				{0x3D2C, 0x5988, 0, 0, 2}, \
				{0x3D2E, 0x5A83, 0, 0, 2}, \
				{0x3D30, 0x5885, 0, 0, 2}, \
				{0x3D32, 0x6280, 0, 0, 2}, \
				{0x3D34, 0x6289, 0, 0, 2}, \
				{0x3D36, 0x6097, 0, 0, 2}, \
				{0x3D38, 0x5782, 0, 0, 2}, \
				{0x3D3A, 0x605C, 0, 0, 2}, \
				{0x3D3C, 0xBF18, 0, 0, 2}, \
				{0x3D3E, 0x0961, 0, 0, 2}, \
				{0x3D40, 0x5080, 0, 0, 2}, \
				{0x3D42, 0x2090, 0, 0, 2}, \
				{0x3D44, 0x4390, 0, 0, 2}, \
				{0x3D46, 0x4382, 0, 0, 2}, \
				{0x3D48, 0x5F8A, 0, 0, 2}, \
				{0x3D4A, 0x5D5D, 0, 0, 2}, \
				{0x3D4C, 0x9C63, 0, 0, 2}, \
				{0x3D4E, 0x8063, 0, 0, 2}, \
				{0x3D50, 0xA960, 0, 0, 2}, \
				{0x3D52, 0x9757, 0, 0, 2}, \
				{0x3D54, 0x8260, 0, 0, 2}, \
				{0x3D56, 0x5CFF, 0, 0, 2}, \
				{0x3D58, 0xBF10, 0, 0, 2}, \
				{0x3D5A, 0x1681, 0, 0, 2}, \
				{0x3D5C, 0x0802, 0, 0, 2}, \
				{0x3D5E, 0x8000, 0, 0, 2}, \
				{0x3D60, 0x141C, 0, 0, 2}, \
				{0x3D62, 0x6000, 0, 0, 2}, \
				{0x3D64, 0x6022, 0, 0, 2}, \
				{0x3D66, 0x4D80, 0, 0, 2}, \
				{0x3D68, 0x5C97, 0, 0, 2}, \
				{0x3D6A, 0x6A69, 0, 0, 2}, \
				{0x3D6C, 0xAC6F, 0, 0, 2}, \
				{0x3D6E, 0x4645, 0, 0, 2}, \
				{0x3D70, 0x4400, 0, 0, 2}, \
				{0x3D72, 0x0513, 0, 0, 2}, \
				{0x3D74, 0x8069, 0, 0, 2}, \
				{0x3D76, 0x6AC6, 0, 0, 2}, \
				{0x3D78, 0x5F95, 0, 0, 2}, \
				{0x3D7A, 0x5F70, 0, 0, 2}, \
				{0x3D7C, 0x8040, 0, 0, 2}, \
				{0x3D7E, 0x4A81, 0, 0, 2}, \
				{0x3D80, 0x0300, 0, 0, 2}, \
				{0x3D82, 0xE703, 0, 0, 2}, \
				{0x3D84, 0x0088, 0, 0, 2}, \
				{0x3D86, 0x4A83, 0, 0, 2}, \
				{0x3D88, 0x40FF, 0, 0, 2}, \
				{0x3D8A, 0xFFFF, 0, 0, 2}, \
				{0x3D8C, 0xFD70, 0, 0, 2}, \
				{0x3D8E, 0x8040, 0, 0, 2}, \
				{0x3D90, 0x4A85, 0, 0, 2}, \
				{0x3D92, 0x4FA8, 0, 0, 2}, \
				{0x3D94, 0x4F8C, 0, 0, 2}, \
				{0x3D96, 0x0070, 0, 0, 2}, \
				{0x3D98, 0xBE47, 0, 0, 2}, \
				{0x3D9A, 0x8847, 0, 0, 2}, \
				{0x3D9C, 0xBC78, 0, 0, 2}, \
				{0x3D9E, 0x6B89, 0, 0, 2}, \
				{0x3DA0, 0x6A80, 0, 0, 2}, \
				{0x3DA2, 0x6986, 0, 0, 2}, \
				{0x3DA4, 0x6B8E, 0, 0, 2}, \
				{0x3DA6, 0x6B80, 0, 0, 2}, \
				{0x3DA8, 0x6980, 0, 0, 2}, \
				{0x3DAA, 0x6A88, 0, 0, 2}, \
				{0x3DAC, 0x7C9F, 0, 0, 2}, \
				{0x3DAE, 0x866B, 0, 0, 2}, \
				{0x3DB0, 0x8765, 0, 0, 2}, \
				{0x3DB2, 0x46FF, 0, 0, 2}, \
				{0x3DB4, 0xE365, 0, 0, 2}, \
				{0x3DB6, 0xA679, 0, 0, 2}, \
				{0x3DB8, 0x4A40, 0, 0, 2}, \
				{0x3DBA, 0x4580, 0, 0, 2}, \
				{0x3DBC, 0x44BC, 0, 0, 2}, \
				{0x3DBE, 0x7000, 0, 0, 2}, \
				{0x3DC0, 0x8040, 0, 0, 2}, \
				{0x3DC2, 0x0802, 0, 0, 2}, \
				{0x3DC4, 0x10EF, 0, 0, 2}, \
				{0x3DC6, 0x0104, 0, 0, 2}, \
				{0x3DC8, 0x3860, 0, 0, 2}, \
				{0x3DCA, 0x5D5D, 0, 0, 2}, \
				{0x3DCC, 0x5682, 0, 0, 2}, \
				{0x3DCE, 0x1300, 0, 0, 2}, \
				{0x3DD0, 0x8648, 0, 0, 2}, \
				{0x3DD2, 0x8202, 0, 0, 2}, \
				{0x3DD4, 0x8082, 0, 0, 2}, \
				{0x3DD6, 0x598A, 0, 0, 2}, \
				{0x3DD8, 0x0280, 0, 0, 2}, \
				{0x3DDA, 0x2048, 0, 0, 2}, \
				{0x3DDC, 0x3060, 0, 0, 2}, \
				{0x3DDE, 0x8042, 0, 0, 2}, \
				{0x3DE0, 0x9259, 0, 0, 2}, \
				{0x3DE2, 0x865A, 0, 0, 2}, \
				{0x3DE4, 0x8258, 0, 0, 2}, \
				{0x3DE6, 0x8562, 0, 0, 2}, \
				{0x3DE8, 0x8062, 0, 0, 2}, \
				{0x3DEA, 0x8560, 0, 0, 2}, \
				{0x3DEC, 0x9257, 0, 0, 2}, \
				{0x3DEE, 0x8221, 0, 0, 2}, \
				{0x3DF0, 0x10FF, 0, 0, 2}, \
				{0x3DF2, 0xB757, 0, 0, 2}, \
				{0x3DF4, 0x9361, 0, 0, 2}, \
				{0x3DF6, 0x1019, 0, 0, 2}, \
				{0x3DF8, 0x8020, 0, 0, 2}, \
				{0x3DFA, 0x9043, 0, 0, 2}, \
				{0x3DFC, 0x8E43, 0, 0, 2}, \
				{0x3DFE, 0x845F, 0, 0, 2}, \
				{0x3E00, 0x835D, 0, 0, 2}, \
				{0x3E02, 0x805D, 0, 0, 2}, \
				{0x3E04, 0x8163, 0, 0, 2}, \
				{0x3E06, 0x8063, 0, 0, 2}, \
				{0x3E08, 0xA060, 0, 0, 2}, \
				{0x3E0A, 0x9157, 0, 0, 2}, \
				{0x3E0C, 0x8260, 0, 0, 2}, \
				{0x3E0E, 0x5CFF, 0, 0, 2}, \
				{0x3E10, 0xFFFF, 0, 0, 2}, \
				{0x3E12, 0xFFE5, 0, 0, 2}, \
				{0x3E14, 0x1016, 0, 0, 2}, \
				{0x3E16, 0x2048, 0, 0, 2}, \
				{0x3E18, 0x0802, 0, 0, 2}, \
				{0x3E1A, 0x1C60, 0, 0, 2}, \
				{0x3E1C, 0x0014, 0, 0, 2}, \
				{0x3E1E, 0x0060, 0, 0, 2}, \
				{0x3E20, 0x2205, 0, 0, 2}, \
				{0x3E22, 0x8120, 0, 0, 2}, \
				{0x3E24, 0x908F, 0, 0, 2}, \
				{0x3E26, 0x6A80, 0, 0, 2}, \
				{0x3E28, 0x6982, 0, 0, 2}, \
				{0x3E2A, 0x5F9F, 0, 0, 2}, \
				{0x3E2C, 0x6F46, 0, 0, 2}, \
				{0x3E2E, 0x4544, 0, 0, 2}, \
				{0x3E30, 0x0005, 0, 0, 2}, \
				{0x3E32, 0x8013, 0, 0, 2}, \
				{0x3E34, 0x8069, 0, 0, 2}, \
				{0x3E36, 0x6A80, 0, 0, 2}, \
				{0x3E38, 0x7000, 0, 0, 2}, \
				{0x3E3A, 0x0000, 0, 0, 2}, \
				{0x3E3C, 0x0000, 0, 0, 2}, \
				{0x3E3E, 0x0000, 0, 0, 2}, \
				{0x3E40, 0x0000, 0, 0, 2}, \
				{0x3E42, 0x0000, 0, 0, 2}, \
				{0x3E44, 0x0000, 0, 0, 2}, \
				{0x3E46, 0x0000, 0, 0, 2}, \
				{0x3E48, 0x0000, 0, 0, 2}, \
				{0x3E4A, 0x0000, 0, 0, 2}, \
				{0x3E4C, 0x0000, 0, 0, 2}, \
				{0x3E4E, 0x0000, 0, 0, 2}, \
				{0x3E50, 0x0000, 0, 0, 2}, \
				{0x3E52, 0x0000, 0, 0, 2}, \
				{0x3E54, 0x0000, 0, 0, 2}, \
				{0x3E56, 0x0000, 0, 0, 2}, \
				{0x3E58, 0x0000, 0, 0, 2}, \
				{0x3E5A, 0x0000, 0, 0, 2}, \
				{0x3E5C, 0x0000, 0, 0, 2}, \
				{0x3E5E, 0x0000, 0, 0, 2}, \
				{0x3E60, 0x0000, 0, 0, 2}, \
				{0x3E62, 0x0000, 0, 0, 2}, \
				{0x3E64, 0x0000, 0, 0, 2}, \
				{0x3E66, 0x0000, 0, 0, 2}, \
				{0x3E68, 0x0000, 0, 0, 2}, \
				{0x3E6A, 0x0000, 0, 0, 2}, \
				{0x3E6C, 0x0000, 0, 0, 2}, \
				{0x3E6E, 0x0000, 0, 0, 2}, \
				{0x3E70, 0x0000, 0, 0, 2}, \
				{0x3E72, 0x0000, 0, 0, 2}, \
				{0x3E74, 0x0000, 0, 0, 2}, \
				{0x3E76, 0x0000, 0, 0, 2}, \
				{0x3E78, 0x0000, 0, 0, 2}, \
				{0x3E7A, 0x0000, 0, 0, 2}, \
				{0x3E7C, 0x0000, 0, 0, 2}, \
				{0x3E7E, 0x0000, 0, 0, 2}, \
				{0x3E80, 0x0000, 0, 0, 2}, \
				{0x3E82, 0x0000, 0, 0, 2}, \
				{0x3E84, 0x0000, 0, 0, 2}, \
				{0x3E86, 0x0000, 0, 0, 2}, \
				{0x3E88, 0x0000, 0, 0, 2}, \
				{0x3E8A, 0x0000, 0, 0, 2}, \
				{0x3E8C, 0x0000, 0, 0, 2}, \
				{0x3E8E, 0x0000, 0, 0, 2}, \
				{0x3E90, 0x0000, 0, 0, 2}, \
				{0x3E92, 0x0000, 0, 0, 2}, \
				{0x3E94, 0x0000, 0, 0, 2}, \
				{0x3E96, 0x0000, 0, 0, 2}, \
				{0x3E98, 0x0000, 0, 0, 2}, \
				{0x3E9A, 0x0000, 0, 0, 2}, \
				{0x3E9C, 0x0000, 0, 0, 2}, \
				{0x3E9E, 0x0000, 0, 0, 2}, \
				{0x3EA0, 0x0000, 0, 0, 2}, \
				{0x3EA2, 0x0000, 0, 0, 2}, \
				{0x3EA4, 0x0000, 0, 0, 2}, \
				{0x3EA6, 0x0000, 0, 0, 2}, \
				{0x3EA8, 0x0000, 0, 0, 2}, \
				{0x3EAA, 0x0000, 0, 0, 2}, \
				{0x3EAC, 0x0000, 0, 0, 2}, \
				{0x3EAE, 0x0000, 0, 0, 2}, \
				{0x3EB0, 0x0000, 0, 0, 2}, \
				{0x3EB2, 0x0000, 0, 0, 2}, \
				{0x3EB4, 0x0000, 0, 0, 2}

#define AR0521_mipi_timing_recommended_12bit \
				{0x31B0, 0x0058, 0, 0, 2}, /*Frame preamble*/ \
				{0x31B2, 0x002C, 0, 0, 2}, /*Line preamble*/ \
				{0x31B4, 0x23D2, 0, 0, 2}, /*MIPI timing0*/ \
				{0x31B6, 0x13E9, 0, 0, 2}, /*MIPI timing1*/ \
				{0x31B8, 0x2413, 0, 0, 2}, /*MIPI timing2*/ \
				{0x31BA, 0x1C68, 0, 0, 2}, /*MIPI timing3*/ \
				{0x31BC, 0xA60B, 0, 0, 2}, /*MIPI timing4*/ \
				{0x0112, 0x0C0C, 0, 0, 2}

#define AR0521_mipi_timing_recommended_10bit \
				{0x31B0, 0x0058, 0, 0, 2}, /*Frame preamble*/ \
				{0x31B2, 0x002C, 0, 0, 2}, /*Line preamble*/ \
				{0x31B4, 0x23D2, 0, 0, 2}, /*MIPI timing0*/ \
				{0x31B6, 0x13E9, 0, 0, 2}, /*MIPI timing1*/ \
				{0x31B8, 0x2413, 0, 0, 2}, /*MIPI timing2*/ \
				{0x31BA, 0x1C68, 0, 0, 2}, /*MIPI timing3*/ \
				{0x31BC, 0xA60B, 0, 0, 2}, /*MIPI timing4*/ \
				{0x0110, 0x00, 0, 0, 1}, /*ccp2 channel mode*/ \
				{0x0111, 0x00, 0, 0, 1}, /*ccp2 signaling mode*/ \
				{0x0112, 0x0808, 0, 0, 2} /* was 0A0A */

#define AR0521_mipi_timing_recommended_8bit \
				{0x31AE, 0x0202, 0, 0, 2}, /*2 lane*/ \
				{0x31B0, 0x006E, 0, 0, 2}, /*Frame preamble*/ \
				{0x31B2, 0x0048, 0, 0, 2}, /*Line preamble*/ \
				{0x31B4, 0x2310, 0, 0, 2}, /*MIPI timing0*/ \
				{0x31B6, 0x1308, 0, 0, 2}, /*MIPI timing1*/ \
				{0x31B8, 0x1C12, 0, 0, 2}, /*MIPI timing2*/ \
				{0x31BA, 0x185B, 0, 0, 2}, /*MIPI timing3*/ \
				{0x31BC, 0x8509, 0, 0, 2}, /*MIPI timing4*/ \
				{0x0110, 0x00, 0, 0, 1}, /*ccp2 channel mode*/ \
				{0x0111, 0x00, 0, 0, 1}, /*ccp2 signaling mode*/ \
				{0x0112, 0x0808, 0, 0, 2} /* was 0A0A */		
				
#define AR0521_mipi_timing_846Mhz_12bit \
				{0x31B0, 0x004E, 0, 0, 2}, /*Frame preamble 4E*/ \
				{0x31B2, 0x0028, 0, 0, 2}, /*Line preamble 28*/ \
				{0x31B4, 0x2310, 0, 0, 2}, /*MIPI timing0 2310*/ \
				{0x31B6, 0x1328, 0, 0, 2}, /*MIPI timing1 1328*/ \
				{0x31B8, 0x1C12, 0, 0, 2}, /*MIPI timing2 1C12*/ \
				{0x31BA, 0x185B, 0, 0, 2}, /*MIPI timing3 185B*/ \
				{0x31BC, 0xA509, 0, 0, 2}, /*MIPI timing4 8509*/ \
				{0x0112, 0x0C0C, 0, 0, 2}

#define AR0521_mipi_timing_846Mhz_10bit \
				{0x31B0, 0x004E, 0, 0, 2}, /*Frame preamble 4E*/ \
				{0x31B2, 0x0028, 0, 0, 2}, /*Line preamble 28*/ \
				{0x31B4, 0x2310, 0, 0, 2}, /*MIPI timing0 2310*/ \
				{0x31B6, 0x1328, 0, 0, 2}, /*MIPI timing1 1328*/ \
				{0x31B8, 0x1C12, 0, 0, 2}, /*MIPI timing2 1C12*/ \
				{0x31BA, 0x185B, 0, 0, 2}, /*MIPI timing3 185B*/ \
				{0x31BC, 0xA509, 0, 0, 2}, /*MIPI timing4 8509*/ \
				{0x0110, 0x00, 0, 0, 1}, /*ccp2 channel mode*/ \
				{0x0111, 0x00, 0, 0, 1}, /*ccp2 signaling mode*/ \
				{0x0112, 0x0808, 0, 0, 2} 

#define AR0521_mipi_timing_846Mhz_8bit \
				{0x31AE, 0x0202, 0, 0, 2}, /* 2 lane */ \
				{0x31B0, 0x006E, 0, 0, 2}, /*Frame preamble 4E*/ \
				{0x31B2, 0x0048, 0, 0, 2}, /*Line preamble 28*/ \
				{0x31B4, 0x2310, 0, 0, 2}, /*MIPI timing0 2310*/ \
				{0x31B6, 0x1308, 0, 0, 2}, /*MIPI timing1 1328*/ \
				{0x31B8, 0x1C12, 0, 0, 2}, /*MIPI timing2 1C12*/ \
				{0x31BA, 0x185B, 0, 0, 2}, /*MIPI timing3 185B*/ \
				{0x31BC, 0x8509, 0, 0, 2}, /*MIPI timing4 8509*/ \
				{0x0110, 0x00, 0, 0, 1}, /*ccp2 channel mode*/ \
				{0x0111, 0x00, 0, 0, 1}, /*ccp2 signaling mode*/ \
				{0x0112, 0x0808, 0, 0, 2}
				
// #define AR0521_mipi_timing_846Mhz_8bit \
				// {0x31B0, 0x004E, 0, 0, 2}, /*Frame preamble 4E*/ \
				// {0x31B2, 0x0028, 0, 0, 2}, /*Line preamble 28*/ \
				// {0x31B4, 0x2310, 0, 0, 2}, /*MIPI timing0 2310*/ \
				// {0x31B6, 0x1328, 0, 0, 2}, /*MIPI timing1 1328*/ \
				// {0x31B8, 0x1C12, 0, 0, 2}, /*MIPI timing2 1C12*/ \
				// {0x31BA, 0x185B, 0, 0, 2}, /*MIPI timing3 185B*/ \
				// {0x31BC, 0xA509, 0, 0, 2}, /*MIPI timing4 8509*/ \
				// {0x0112, 0x0808, 0, 0, 2}
				
#define AR0521_Data_pedestal_12bit \
				{0x301A, 0x0210, 0, 0, 2}, \
				{0x301E, 0x0000, 0, 0, 2}, /* was 0x00a8*/ \
				{0x301A, 0x0218, 0, 0, 2}

#define AR0521_enable_streaming \
				{0x301A, 0x021C, 0, 0, 2}

#define AR0521_disable_streaming \
				{0x301A, 0x0218, 0, 0, 2}

#define AR0521_5M60fps_array_setup_2600_1960_skip1 \
				{0x3004, 0x0004, 0, 0, 2}, /*x_addr_start*/ \
				{0x3008, 0x0A2B, 0, 0, 2}, /*x_addr_end*/ \
				{0x3002, 0x0004, 0, 0, 2}, /*y_addr_start*/ \
				{0x3006, 0x07A3, 0, 0, 2}, /*y_addr_end*/ \
				{0x3040, 0x0041, 0, 0, 2}, /*read_mode*/ \
				{0x317A, 0x416E, 0, 0, 2}, /*sfbin_enable*/ \
				{0x3F3C, 0x0003, 0, 0, 2}, /*bin4*/ \
				{0x034C, 0x0A28, 0, 0, 2}, /*x_output_size*/ \
				{0x034E, 0x07A0, 0, 0, 2}, /*y_output_size*/ \
				{0x300C, 0x1648, 0, 0, 2}, /*line_length_pck 0x1178*/ \
				{0x300A, 0x0A4E, 0, 0, 2} /*frame_length_lines 0x092A*/ 

#define AR0521_5M60fps_array_setup_2560_1440_skip1 \
				{0x3004, 0x0018, 0, 0, 2}, /*x_addr_start*/ \
				{0x3008, 0x0A17, 0, 0, 2}, /*x_addr_end*/ \
				{0x3002, 0x0104, 0, 0, 2}, /*y_addr_start*/ \
				{0x3006, 0x06A3, 0, 0, 2}, /*y_addr_end*/ \
				{0x3040, 0x0041, 0, 0, 2}, /*read_mode*/ \
				{0x317A, 0x416E, 0, 0, 2}, /*sfbin_enable*/ \
				{0x3F3C, 0x0003, 0, 0, 2}, /*bin4*/ \
				{0x034C, 0x0A00, 0, 0, 2}, /*x_output_size*/ \
				{0x034E, 0x05A0, 0, 0, 2}, /*y_output_size*/ \
				{0x300C, 0x1178, 0, 0, 2}, /*line_length_pck*/ \
				{0x300A, 0x092A, 0, 0, 2} /*frame_length_lines*/ 


#define AR0521_720p_90fps_array_setup_2576_1456_skip2 \
				{0x3004, 0x0018, 0, 0, 2}, /*x_addr_start*/ \
				{0x3008, 0x0A15, 0, 0, 2}, /*x_addr_end*/ \
				{0x3002, 0x0104, 0, 0, 2}, /*y_addr_start*/ \
				{0x3006, 0x06A1, 0, 0, 2}, /*y_addr_end*/ \
				{0x3040, 0x00C3, 0, 0, 2}, /*read_mode*/ \
				{0x317A, 0x516E, 0, 0, 2}, /*sfbin_enable*/ \
				{0x3F3C, 0x0003, 0, 0, 2}, /*bin4*/ \
				{0x034C, 0x0500, 0, 0, 2}, /*x_output_size*/ \
				{0x034E, 0x02D0, 0, 0, 2}, /*y_output_size*/ \
				{0x300C, 0x0BF8, 0, 0, 2}, /*line_length_pck*/ \
				{0x300A, 0x1330, 0, 0, 2} /*frame_length_lines*/ 


#define AR0521_VGA_120fps_array_setup_2592_1952_skip4 \
				{0x3004, 0x0008, 0, 0, 2}, /*x_addr_start*/ \
				{0x3008, 0x0A25, 0, 0, 2}, /*x_addr_end*/ \
				{0x3002, 0x0004, 0, 0, 2}, /*y_addr_start*/ \
				{0x3006, 0x079D, 0, 0, 2}, /*y_addr_end*/ \
				{0x3040, 0x18c7, 0, 0, 2},  /*read_mode was 0x18c7*/ \
				{0x317A, 0x516E, 0, 0, 2},  /*sfbin_enable*/ \
				{0x3F3C, 0x0003, 0, 0, 2},  /*bin4*/ \
				{0x034C, 0x0288, 0, 0, 2}, /*x_output_size*/ \
				{0x034E, 0x01E8, 0, 0, 2}, /*y_output_size*/ \
				{0x300C, 0x0CA0, 0, 0, 2}, /*line_length_pck*/ \
				{0x300A, 0x05E8, 0, 0, 2} /*frame_length_lines*/ 
				
#define AR0521_1080p60fps_array_setup_1928_1088_skip1 \
				{0x3004, 0x0154, 0, 0, 2}, /*x_addr_start 340*/ \
				{0x3008, 0x08DB, 0, 0, 2}, /*x_addr_end 2267*/ \
				{0x3002, 0x01B4, 0, 0, 2}, /*y_addr_start 436*/ \
				{0x3006, 0x05F3, 0, 0, 2}, /*y_addr_end 1523*/ \
				{0x3040, 0x0041, 0, 0, 2}, /*read_mode x_odd_inc1, y_odd_inc1*/ \
				{0x3172, 0x0206, 0, 0, 2}, /*digbin_enable txlo_clk setting 2:vt_pix_clk_freq/*/ \
				{0x317A, 0x416E, 0, 0, 2}, /*sfbin_enable SF Binning Configuration check*/ \
				{0x3F3C, 0x0003, 0, 0, 2}, /*bin4 analog block en*/ \
				{0x034C, 0x0788, 0, 0, 2}, /*x_output_size 1928*/ \
				{0x034E, 0x0440, 0, 0, 2}, /*y_output_size 1088*/ \
				{0x300C, 0x1178, 0, 0, 2}, /*line_length_pck */ \
				{0x300A, 0x04E4, 0, 0, 2} /*frame_length_lines */ 

#define AR0521_stream_5M_60fps_10bit \
				AR0521_powerup, \
				AR0521_corrections_recommended, \
				AR0521_pixel_timing_recommended, \
				AR0521_analog_setup_recommended_12bit, \
				AR0521_analog_setup_recommended_10bit, \
				AR0521_mipi_timing_recommended_10bit, \
				AR0521_pll_setup_max_10bit, \
				AR0521_5M60fps_array_setup_2600_1960_skip1, \
				AR0521_Data_pedestal_12bit, \
				AR0521_new_RNC_10bit, \
				{0x300C, 0x0BE0, 0, 0, 2}, /*line_length_pck*/ \
				{0x300A, 0x08DC, 0, 0, 2}, /*frame_length_lines*/ \
				{0x3012, 0x08DC, 0, 0, 2}, /*COARSE_INTEGRATION_TIME*/ \
				AR0521_enable_streaming

// #define AR0521_stream_5M_60fps_10bit_Hispi \
				// AR0521_powerup, \
				// AR0521_corrections_recommended, \
				// AR0521_pixel_timing_recommended, \
				// AR0521_analog_setup_recommended_12bit, \
				// AR0521_analog_setup_recommended_10bit, \
				// AR0521_mipi_timing_recommended_10bit, \
				// AR0521_pll_setup_max_10bit, \
				// AR0521_5M60fps_array_setup_2600_1960_skip1, \
				// AR0521_Data_pedestal_12bit, \
				// AR0521_new_RNC_10bit, \
				// {0x31AE, 0x0304, 0, 0, 2}, /*serial format*/ \
				// {0x0110, 0x00, 0, 0, 1}, /*ccp2 channel mode*/ \
				// {0x3220, 0x002B, 0, 0, 2}, /*mipi interleave control*/ \
				// {0x300C, 0x0BE0, 0, 0, 2}, /*line_length_pck*/ \
				// {0x300A, 0x08DC, 0, 0, 2}, /*frame_length_lines*/ \
				// {0x3012, 0x08DC, 0, 0, 2}, /*COARSE_INTEGRATION_TIME*/ \
				// {0x3494, 0x0000, 0, 0, 2}, /*Hispi padding data disabled*/ \
				// AR0521_hispi, \
				// AR0521_enable_streaming

#define AR0521_stream_quadHD_60fps_10bit \
				AR0521_powerup, \
				AR0521_corrections_recommended, \
				AR0521_pixel_timing_recommended, \
				AR0521_analog_setup_recommended_12bit, \
				AR0521_analog_setup_recommended_10bit, \
				AR0521_mipi_timing_recommended_10bit, \
				AR0521_pll_setup_max_10bit, \
				{0x3012, 0x0210, 0, 0, 2}, \
				AR0521_5M60fps_array_setup_2560_1440_skip1, \
				AR0521_Data_pedestal_12bit, \
				AR0521_new_RNC_10bit, \
				{0x300C, 0x0BE0, 0, 0, 2}, /*line_length_pck*/ \
				{0x300A, 0x08DC, 0, 0, 2}, /*frame_length_lines*/ \
				{0x3012, 0x08DC, 0, 0, 2}, /*COARSE_INTEGRATION_TIME*/ \
				AR0521_enable_streaming

#define AR0521_stream_quadHD_27fps_8bit \
				AR0521_powerup, \
				AR0521_corrections_recommended, \
				AR0521_pixel_timing_recommended, \
				AR0521_analog_setup_recommended_12bit, \
				AR0521_analog_setup_recommended_10bit, \
				AR0521_mipi_timing_recommended_8bit, \
				AR0521_pll_setup_max_8bit, \
				{0x3012, 0x0499, 0, 0, 2}, \
				AR0521_5M60fps_array_setup_2560_1440_skip1, \
				AR0521_Data_pedestal_12bit, \
				AR0521_new_RNC_10bit, \
				{0x300C, 0x15F8, 0, 0, 2}, /*line_length_pck*/ \
				{0x300A, 0x0A74, 0, 0, 2}, /*frame_length_lines*/ \
				{0x3012, 0x0499, 0, 0, 2}, /*COARSE_INTEGRATION_TIME*/ \
				AR0521_enable_streaming

#define AR0521_stream_720p_90fps_10bit \
				AR0521_powerup, \
				AR0521_corrections_recommended, \
				AR0521_pixel_timing_recommended, \
				AR0521_analog_setup_recommended_12bit, \
				AR0521_analog_setup_recommended_10bit, \
				AR0521_mipi_timing_recommended_10bit, \
				AR0521_pll_setup_max_10bit , \
				AR0521_720p_90fps_array_setup_2576_1456_skip2, \
				AR0521_Data_pedestal_12bit, \
				AR0521_new_RNC_10bit, \
				{0x300C, 0x0CA0, 0, 0, 2}, /*line_length_pck*/ \
				{0x300A, 0x05E8, 0, 0, 2}, /*frame_length_lines*/ \
				{0x3012, 0x08DC, 0, 0, 2}, /*COARSE_INTEGRATION_TIME*/ \
				AR0521_enable_streaming

#define AR0521_stream_720p_27fps_8bit \
				AR0521_powerup, \
				AR0521_corrections_recommended, \
				AR0521_pixel_timing_recommended, \
				AR0521_analog_setup_recommended_12bit, \
				AR0521_analog_setup_recommended_10bit, \
				AR0521_mipi_timing_recommended_8bit, \
				AR0521_pll_setup_max_8bit , \
				AR0521_720p_90fps_array_setup_2576_1456_skip2, \
				AR0521_Data_pedestal_12bit, \
				AR0521_new_RNC_10bit, \
				{0x300C, 0x0BF8, 0, 0, 2}, /*line_length_pck*/ \
				{0x300A, 0x1330, 0, 0, 2}, /*frame_length_lines*/ \
				{0x3012, 0x0540, 0, 0, 2}, /*COARSE_INTEGRATION_TIME*/ \
				AR0521_enable_streaming

#define AR0521_stream_VGA_120fps_10bit \
				AR0521_powerup, \
				AR0521_corrections_recommended, \
				AR0521_pixel_timing_recommended, \
				AR0521_analog_setup_recommended_12bit, \
				AR0521_analog_setup_recommended_10bit, \
				AR0521_mipi_timing_recommended_10bit, \
				AR0521_pll_setup_max_10bit , \
				AR0521_VGA_120fps_array_setup_2592_1952_skip4, \
				AR0521_Data_pedestal_12bit, \
				AR0521_new_RNC_10bit, \
				{0x300C, 0x0CA0, 0, 0, 2}, /*line_length_pck*/ \
				{0x300A, 0x05E8, 0, 0, 2}, /*frame_length_lines*/ \
				{0x3012, 0x08DC, 0, 0, 2}, /*COARSE_INTEGRATION_TIME*/ \
				AR0521_enable_streaming

#define AR0521_stream_VGA_27fps_8bit \
				AR0521_powerup, \
				AR0521_corrections_recommended, \
				AR0521_pixel_timing_recommended, \
				AR0521_analog_setup_recommended_12bit, \
				AR0521_analog_setup_recommended_10bit, \
				AR0521_mipi_timing_recommended_8bit, \
				AR0521_pll_setup_max_8bit , \
				AR0521_VGA_120fps_array_setup_2592_1952_skip4, \
				AR0521_Data_pedestal_12bit, \
				AR0521_new_RNC_10bit, \
				{0x300C, 0x0BE0, 0, 0, 2}, /*line_length_pck*/ \
				{0x300A, 0x1358, 0, 0, 2}, /*frame_length_lines*/ \
				{0x3012, 0x0B41, 0, 0, 2}, /* was 0x0441 COARSE_INTEGRATION_TIME*/ \
				AR0521_enable_streaming

#define AR0521_stream_quadHD_60fps_12bit \
				AR0521_powerup, \
				AR0521_corrections_recommended, \
				AR0521_pixel_timing_recommended, \
				AR0521_analog_setup_recommended_12bit, \
				AR0521_mipi_timing_recommended_12bit, \
				AR0521_pll_setup_max_12bit , \
				{0x3012, 0x0210, 0, 0, 2}, \
				AR0521_5M60fps_array_setup_2560_1440_skip1, \
				AR0521_Data_pedestal_12bit, \
				AR0521_new_RNC_12bit, \
				AR0521_enable_streaming


#define AR0521_stream_720p_90fps_12bit \
				AR0521_powerup, \
				AR0521_corrections_recommended, \
				AR0521_pixel_timing_recommended, \
				AR0521_analog_setup_recommended_12bit, \
				AR0521_mipi_timing_recommended_12bit, \
				AR0521_pll_setup_max_12bit , \
				AR0521_720p_90fps_array_setup_2576_1456_skip2, \
				AR0521_Data_pedestal_12bit, \
				AR0521_new_RNC_12bit, \
				{0x300C, 0x1178, 0, 0, 2}, /*line_length_pck*/ \
				{0x300A, 0x0368, 0, 0, 2}, /*frame_length_lines*/ \
				AR0521_enable_streaming


#define AR0521_stream_VGA_120fps_12bit \
				AR0521_powerup, \
				AR0521_corrections_recommended, \
				AR0521_pixel_timing_recommended, \
				AR0521_analog_setup_recommended_12bit, \
				AR0521_mipi_timing_recommended_12bit, \
				AR0521_pll_setup_max_12bit , \
				AR0521_VGA_120fps_array_setup_2592_1952_skip4, \
				AR0521_Data_pedestal_12bit, \
				AR0521_new_RNC_12bit, \
				{0x300C, 0x1178, 0, 0, 2}, /*line_length_pck*/ \
				{0x300A, 0x0272, 0, 0, 2}, /*frame_length_lines*/ \
				AR0521_enable_streaming

#define AR0521_stream_5M_32fps_12bit \
				AR0521_powerup, \
				AR0521_corrections_recommended, \
				AR0521_pixel_timing_recommended, \
				AR0521_analog_setup_recommended_12bit, \
				AR0521_mipi_timing_recommended_12bit, \
				AR0521_pll_setup_max_12bit , \
				AR0521_5M60fps_array_setup_2600_1960_skip1, \
				AR0521_Data_pedestal_12bit, \
				AR0521_new_RNC_12bit, \
				AR0521_enable_streaming

#define AR0521_stream_5M_50fps_10bit \
				AR0521_powerup, \
				AR0521_corrections_recommended, \
				AR0521_pixel_timing_recommended, \
				AR0521_analog_setup_recommended_12bit, \
				AR0521_analog_setup_recommended_10bit, \
				AR0521_mipi_timing_846Mhz_10bit, \
				AR0521_pll_setup_846Mhz_10bit , \
				AR0521_5M60fps_array_setup_2600_1960_skip1, \
				AR0521_Data_pedestal_12bit, \
				AR0521_new_RNC_10bit, \
				{0x300C, 0x0BE0, 0, 0, 2}, /*line_length_pck*/ \
				{0x300A, 0x08DC, 0, 0, 2}, /*frame_length_lines*/ \
				AR0521_enable_streaming

#define AR0521_stream_5M_50fps_8bit \
				AR0521_powerup, \
				AR0521_corrections_recommended, \
				AR0521_pixel_timing_recommended, \
				AR0521_analog_setup_recommended_12bit, \
				AR0521_analog_setup_recommended_10bit, \
				AR0521_mipi_timing_846Mhz_8bit, \
				AR0521_pll_setup_846Mhz_8bit , \
				AR0521_5M60fps_array_setup_2600_1960_skip1, \
				AR0521_Data_pedestal_12bit, \
				AR0521_new_RNC_10bit, \
				{0x300C, 0x1648, 0, 0, 2}, /*line_length_pck*/ \
				{0x300A, 0x1B20, 0, 0, 2}, /*frame_length_lines*/ \
				AR0521_enable_streaming


#define AR0521_stream_5M_27fps_12bit \
				AR0521_powerup, \
				AR0521_corrections_recommended, \
				AR0521_pixel_timing_recommended, \
				AR0521_analog_setup_recommended_12bit, \
				AR0521_mipi_timing_846Mhz_12bit, \
				AR0521_pll_setup_846Mhz_12bit , \
				AR0521_5M60fps_array_setup_2600_1960_skip1, \
				AR0521_Data_pedestal_12bit, \
				AR0521_new_RNC_12bit, \
				AR0521_enable_streaming

#define AR0521_stream_1080p_60fps_10bit \
				AR0521_powerup, \
				AR0521_corrections_recommended, \
				AR0521_pixel_timing_recommended, \
				AR0521_analog_setup_recommended_12bit, \
				AR0521_analog_setup_recommended_10bit, \
				AR0521_mipi_timing_recommended_10bit, \
				AR0521_pll_setup_max_10bit , \
				AR0521_1080p60fps_array_setup_1928_1088_skip1, \
				AR0521_Data_pedestal_12bit, \
				AR0521_new_RNC_10bit, \
				{0x300C, 0xBE0, 0, 0, 2}, /*line_length_pck */ \
				{0x300A, 0x8DC, 0, 0, 2}, /*frame_length_lines*/ \
				AR0521_enable_streaming
				
#define AR0521_stream_1080p_27fps_8bit \
				AR0521_powerup, \
				AR0521_corrections_recommended, \
				AR0521_pixel_timing_recommended, \
				AR0521_analog_setup_recommended_12bit, \
				AR0521_analog_setup_recommended_10bit, \
				AR0521_mipi_timing_recommended_8bit, \
				AR0521_pll_setup_max_8bit , \
				AR0521_1080p60fps_array_setup_1928_1088_skip1, \
				AR0521_Data_pedestal_12bit, \
				AR0521_new_RNC_10bit, \
				{0x300C, 0x1108, 0, 0, 2}, /*line_length_pck */ \
				{0x300A, 0x0D7C, 0, 0, 2}, /*frame_length_lines*/ \
				{0x3012, 0x05EF, 0, 0, 2}, /*COARSE_INTEGRATION_TIME*/ \
				AR0521_enable_streaming
				

#define AR0521_stream_1080p_60fps_12bit \
				AR0521_powerup, \
				AR0521_corrections_recommended, \
				AR0521_pixel_timing_recommended, \
				AR0521_analog_setup_recommended_12bit, \
				AR0521_mipi_timing_recommended_12bit, \
				AR0521_pll_setup_max_12bit , \
				AR0521_1080p60fps_array_setup_1928_1088_skip1, \
				AR0521_Data_pedestal_12bit, \
				AR0521_new_RNC_12bit, \
				AR0521_enable_streaming

#define AR0521_stream_1080p_60fps_10bit_2 \
				AR0521_powerup, \
				AR0521_corrections_recommended, \
				AR0521_pixel_timing_recommended, \
				AR0521_analog_setup_recommended_12bit, \
				AR0521_analog_setup_recommended_10bit, \
				AR0521_mipi_timing_846Mhz_10bit, \
				AR0521_pll_setup_846Mhz_10bit , \
				AR0521_1080p60fps_array_setup_1928_1088_skip1, \
				AR0521_Data_pedestal_12bit, \
				AR0521_new_RNC_10bit, \
				{0x300C, 0x0BE0, 0, 0, 2}, /*line_length_pck */ \
				{0x300A, 0x082F, 0, 0, 2}, /*FRAME_LENGTH_LINES 2095*/ \
				{0x3012, 0x073D, 0, 0, 2}, /*COARSE_INTEGRATION_TIME 1853*/ \
				AR0521_enable_streaming

#define AR0521_stream_1080p_56fps_12bit \
				AR0521_powerup, \
				AR0521_corrections_recommended, \
				AR0521_pixel_timing_recommended, \
				AR0521_analog_setup_recommended_12bit, \
				AR0521_mipi_timing_846Mhz_12bit, \
				AR0521_pll_setup_846Mhz_12bit , \
				AR0521_1080p60fps_array_setup_1928_1088_skip1, \
				AR0521_Data_pedestal_12bit, \
				AR0521_new_RNC_12bit, \
				{0x300A, 0x0458, 0, 0, 2}, /*FRAME_LENGTH_LINES 1112*/ \
				{0x3012, 0x0419, 0, 0, 2}, /*COARSE_INTEGRATION_TIME 1049*/ \
				AR0521_enable_streaming


#define AR0521_HDR_mode \
				{0x31AE, 0x0204, 0, 0, 2}, /*serial format 0204*/ \
				{0x303E, 0x0001, 0, 0, 2}, /*read style 0001*/ \
				{0x0110, 0x01, 0, 0, 1} /*ccp2 channel mode set for VC*/ 
				
#define AR0521_HDR_mode_MIPI_VC \
				{0x0110, 0x01, 0, 0, 1} /*ccp2 channel mode set for VC*/ 
				
#define AR0521_HDR_mode_MIPI_DT \
				{0x0110, 0x00, 0, 0, 1}, /*ccp2 channel mode set for DT*/ \
				{0x3220, 0x002C, 0, 0, 2}  /* MIPI_INTERLEAVE_CONTROL2 - [3:19:12.900]*/ 
	
	
// #define AR0521_hispi \
				// {0x0100, 0x00, 0, 200, 1}, /*serial interface Configuration*/ \
				// {0x31AE, 0x0304, 0, 0, 2}, /*serial format 0304*/ \
				// {0x31C6, 0x8400, 0, 0, 2},  /* HISPI_CONTROL_STATUS*/ \
				// {0x0100, 0x01, 0, 0, 1}

/*
[Slave/trigger GRR]
				{0x0100, 0x0, 0, 0, 2}, //stop stream
				{0x30F8, 0x2, 0, 0, 2}, //enable GPIO 1,disable GPIO 0
BITFIELD=0x301A,0x0100,1 //Enable GPIO
				{0x3026, 0xFD70, 0, 0, 2}, //Assign GPIO 0 as VD input signal
				{0x3158, 0xA000, 0, 0, 2}, //Enable slave mode
BITFIELD=0x315E, 0x0001, 1 //Enable GRR mode
				{0x0100, 0x1, 0, 0, 2}, //start stream
[FDOC 4x threshold]
				{0x3180, 0x94D0, 0, 0, 2}, \
*/
