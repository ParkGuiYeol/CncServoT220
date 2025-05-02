/*
 * Define_Header.h
 *
 * C/C++ source code generated on : Thu Jan 11 10:09:04 2024
 * Created by: System Research Team
 * Code generated on : Sat Mar 15 00:16:24 2025
 *
 */

#ifndef DEFINE_HEADER_H_
#define DEFINE_HEADER_H_

#include "DSP2834x_Device.h"				// DSP2834x Register & Data Type Define.(Supported by TI)
#include "Define_SysCtrl.h"					// System Clock Define.
#include "Define_Prototypes.h"				// Define Extern Function(ProtoTypes).
#include "Define_Pin.h"

#include <math.h>

#define     BOUND(val, max, min)            ((val > max) ? max : ((val < min) ? min : val))
// ========================================================= PWM ========================================================== //
#define     M1_PHASE_ABC                    1               // UVW Wire turn
#define     M1_PHASE_CBA                    0               // WVU Wire turn

#define 	PWM1_DB_PERIOD					1020					// 3.333[us] = 3.333[ns] x 1000
#define 	PWM2_DB_PERIOD					1000
#define 	PWM3_DB_PERIOD					0
#define		TIMEBASE1_PERIOD 				15000
#define		TIMEBASE2_PERIOD 				15000
#define		TIMEBASE1_PERIOD_HALF 			7500
#define		TIMEBASE2_PERIOD_HALF 			7500

#define 	TIMEBASE3_PERIOD				10						// 300[Mhz]/(2*10) = 15[Mhz]
#define 	TIMEBASE3_PERIOD_HALF			5

//#define 	TIMER0_PERIOD					19200					// Watch Cat (SYSCLKOUT(300[MHz]) / 19200 = 15.625[kHz] = 64 [usec])
//																	// Switch Frequency 8 [kHz] Interrupt interval: 1/8000 =   125 [usec] / 2 =  62.5 [usec]
//																	// Switch Frequency 14[kHz] Interrupt interval: 1/14000 = 71.4 [usec] / 2 =  35.7 [usec]
//                                                                    // 62.5 ~ 71.4 [usec]  ̳    Ÿ ̸  ī   ͸      
//																	// M1, M1    ͷ Ʈ     ϳ     ߻               35.7 x 2 = 71.4 usec        ġ         ȵ 
//																	// M1, M1    ͷ Ʈ     ϳ     ߻               62.5 x 2 = 125  usec        ġ         ȵ 

#define 	TIMEBASE1_SAMPLING_TIME			100e-6F
#define 	TIMEBASE2_SAMPLING_TIME			200e-6F
#define 	INV_TIMEBASE2_SAMPLING_TIME		5.0e3F
#define 	INV_TIMEBASE1_SAMPLING_TIME		10e3F

// =================================================== Parallel Communication ============================================= //
#define 	ADC_ADDR						((volatile Uint16 *)(0x004000))
#define 	ADC_BASE_ADDRESS				0x004000
#define 	ADC_Send(AD_data)				(*(Uint16*)(ADC_BASE_ADDRESS)) = AD_data
//#define 	ADC_Receive(AD_addr)			(*(Uint16*)(ADC_BASE_ADDRESS + AD_addr))

#define 	FPGA_BASE_ADDRESS				0x100000
#define 	FPGA_Send(addr, data)			(*(Uint16*)(FPGA_BASE_ADDRESS + addr)) = data
#define 	FPGA_Receive(addr)				(*(Uint16*)(FPGA_BASE_ADDRESS + addr))

// ========================================================= ADC ========================================================== //
#define 	ADC_SHIFT						4

//// ============================================================ DAC =========================================================== //
// Address Mapping (FPGA_Send)
#define		ADDF_DA_CH1						0x06
#define		ADDF_DA_CH2						0x07
#define		ADDF_DA_CH3						0x08
#define		ADDF_DA_CH4						0x09

// =========================================================== cMode ========================================================== //
#define     MENU_Main                       0x00
#define     Mode_Select                     0x01
#define     Define_Change                   0x02
#define     Auto_Align                      0x03

#define     ABS(val)                        ((val > 0) ? val : -val)

// ============================================================ FND ========================================================== //
#define     MODE_KEY                        0x0001
#define     UP_KEY                          0x0002
#define     DOWN_KEY                        0x0004
#define     UP_DOUN_KEY                     0x0006
#define     SET_KEY                         0x0008
#define     UP_SET_KEY                      0x000A
#define     DOWN_SET_KEY                    0x000C
#define     MODE_SET_KEY                    0x0009

//// FND
typedef union {
    uint16_T  all;
    struct {
        uint16_T  FND_P0:1;
        uint16_T  FND_P1:1;
        uint16_T  FND_P2:1;
        uint16_T  FND_P3:1;
        uint16_T  FND_P4:1;
        uint16_T  FND_P5:1;
        uint16_T  FND_P6:1;
        uint16_T  FND_P7:1;
    } bit;
} S_FND;

// =========================================================== Fault ========================================================= //
typedef union {
    uint32_T  all;
    struct {
        uint16_T  F00_FltStat:1;
        uint16_T  F01_EstopSwitchFlt:1;
        uint16_T  F02_IgptShrtFlt:1;
        uint16_T  F03_HvdcOvrVolFlt:1;
        uint16_T  F04_HvdcUdrVolFlt:1;
        uint16_T  F05_CrtSnsrFlt:1;
        uint16_T  F06_CrtSnsrOfsFlt:1;
        uint16_T  F07_CrtStallFlt:1;
        uint16_T  F08_CrtOvrFlt:1;
        uint16_T  F09_IvtTempSnsrFlt:1;
        uint16_T  F010_IvtTempOvrFlt:1;
        uint16_T  F11_MtrTempSnsrFlt:1;
        uint16_T  F12_MtrTempOvrFlt:1;
        uint16_T  F13_MtrSpdFlt:1;
        uint16_T  F14_MtrLineOpnFlt:1;
        uint16_T  F15_CommFlt:1;
        uint16_T  F16_InitNvRam:1;
    } bit;
} S_FLT;

#endif // DEFINE_HEADER_H_
