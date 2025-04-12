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
#define 	TIMEBASE3_PERIOD				10
#define 	TIMEBASE3_PERIOD_HALF			5
//#define 	TIMER0_PERIOD					19200					// Watch Cat (SYSCLKOUT(300[MHz]) / 19200 = 15.625[kHz] = 64 [usec])
//																	// Switch Frequency 8 [kHz] Interrupt interval: 1/8000 =   125 [usec] / 2 =  62.5 [usec]
//																	// Switch Frequency 14[kHz] Interrupt interval: 1/14000 = 71.4 [usec] / 2 =  35.7 [usec]
//                                                                    // 62.5 ~ 71.4 [usec] 이내에 타이머 카운터를 리셋
//																	// M1, M1 인터럽트 중 하나가 발생하지 않을 경우 35.7 x 2 = 71.4 usec 동안 와치켓 리엣 안됨
//																	// M1, M1 인터럽트 중 하나가 발생하지 않을 경우 62.5 x 2 = 125  usec 동안 와치켓 리엣 안됨

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

#endif // DEFINE_HEADER_H_
