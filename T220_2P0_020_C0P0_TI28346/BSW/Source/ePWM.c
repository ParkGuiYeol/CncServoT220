/*
 *	ePWM.c
 *
 * C/C++ source code generated on : Thu Jan 11 10:09:04 2024
 * Created by: System Research Team
 * Code generated on : Sat Mar 15 00:16:24 2025
 *
 */

#include "Define_Header.h"
#include "Define_ePWM.h"

void Init_PWM(void)
{
	//-------------------------------------------------------------------------------------------------//
	//--------------------------------------------ePWM Set1--------------------------------------------//
	//-------------------------------------------------------------------------------------------------//
	// Emulation Mode
	EPwm1Regs.TBCTL.bit.FREE_SOFT = EMUMODE_FREE;
	EPwm2Regs.TBCTL.bit.FREE_SOFT = EMUMODE_FREE;
	EPwm3Regs.TBCTL.bit.FREE_SOFT = EMUMODE_FREE;

	// Clock Pre-scale											// TBCLK = SYSCLKOUT/(HSPCLKDIV x CLKDIV), HISPCP 4.6875[MHz](SYSCLKOUT/64)
	EPwm1Regs.TBCTL.bit.CLKDIV = TB_DIV1;						// /1
	EPwm2Regs.TBCTL.bit.CLKDIV = TB_DIV1;
	EPwm3Regs.TBCTL.bit.CLKDIV = TB_DIV1;
	EPwm1Regs.TBCTL.bit.HSPCLKDIV = TB_HSPDIV1;					// /1
	EPwm2Regs.TBCTL.bit.HSPCLKDIV = TB_HSPDIV1;
	EPwm3Regs.TBCTL.bit.HSPCLKDIV = TB_HSPDIV1;

	// Configure Time Base
	EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;				// Up-Down Counter
	EPwm2Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;
	EPwm3Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;
	EPwm1Regs.TBCTL.bit.PRDLD = TB_IMMEDIATE;					// Shadow Disable
	EPwm2Regs.TBCTL.bit.PRDLD = TB_IMMEDIATE;
	EPwm3Regs.TBCTL.bit.PRDLD = TB_IMMEDIATE;
	EPwm1Regs.TBPRD = TIMEBASE1_PERIOD;							// Period(10[kHz] = 300[MHz]/(2*15000))
	EPwm2Regs.TBPRD = TIMEBASE1_PERIOD;
	EPwm3Regs.TBPRD = TIMEBASE1_PERIOD;

	// Counter Compare
	EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
	EPwm2Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
	EPwm3Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
	EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
	EPwm2Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
	EPwm3Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
	EPwm1Regs.CMPA.half.CMPA = TIMEBASE1_PERIOD_HALF;
	EPwm2Regs.CMPA.half.CMPA = TIMEBASE1_PERIOD_HALF;
	EPwm3Regs.CMPA.half.CMPA = TIMEBASE1_PERIOD_HALF;

	// Action Qualifier
	EPwm1Regs.AQCTLA.bit.CAU = AQ_CLEAR;
	EPwm2Regs.AQCTLA.bit.CAU = AQ_CLEAR;
	EPwm3Regs.AQCTLA.bit.CAU = AQ_CLEAR;
	EPwm1Regs.AQCTLA.bit.CAD = AQ_SET;
	EPwm2Regs.AQCTLA.bit.CAD = AQ_SET;
	EPwm3Regs.AQCTLA.bit.CAD = AQ_SET;

	// Dead Band Generator
	EPwm1Regs.DBCTL.bit.IN_MODE = DBA_ALL;
	EPwm2Regs.DBCTL.bit.IN_MODE = DBA_ALL;
	EPwm3Regs.DBCTL.bit.IN_MODE = DBA_ALL;
	EPwm1Regs.DBCTL.bit.POLSEL = DB_ACTV_LOC;
	EPwm2Regs.DBCTL.bit.POLSEL = DB_ACTV_LOC;
	EPwm3Regs.DBCTL.bit.POLSEL = DB_ACTV_LOC;
	EPwm1Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
	EPwm2Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
	EPwm3Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
	EPwm1Regs.DBRED = PWM1_DB_PERIOD;
	EPwm2Regs.DBRED = PWM1_DB_PERIOD;
	EPwm3Regs.DBRED = PWM1_DB_PERIOD;
	EPwm1Regs.DBFED = PWM1_DB_PERIOD;
	EPwm2Regs.DBFED = PWM1_DB_PERIOD;
	EPwm3Regs.DBFED = PWM1_DB_PERIOD;

	// Configure Synchronization
	EPwm1Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;					// Synchronization Signal Generation(Time Base Reference)
	EPwm2Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;					// Synchronization Signal Receive from upper ePWM Module
	EPwm3Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;
	EPwm1Regs.TBCTL.bit.PHSDIR = TB_UP;							// Up Count after SYNCHRONIZATION
	EPwm2Regs.TBCTL.bit.PHSDIR = TB_UP;
	EPwm3Regs.TBCTL.bit.PHSDIR = TB_UP;
	EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE;						// Time Base Reference, Epwm1을 마스터로 설정하여 동기화
	EPwm2Regs.TBCTL.bit.PHSEN = TB_ENABLE;						// Time Base Receive
	EPwm3Regs.TBCTL.bit.PHSEN = TB_ENABLE;
	EPwm1Regs.TBPHS.half.TBPHS = TB_BPHS_0DELAY;				// 2xSYSCLKOUT delay is needed to recognition in each ePWM Module passed.
	EPwm2Regs.TBPHS.half.TBPHS = TB_BPHS_0DELAY;
	EPwm3Regs.TBPHS.half.TBPHS = TB_BPHS_0DELAY;

	EPwm1Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;
	EPwm2Regs.ETSEL.bit.INTSEL = ET_CTR_PRD;
	// 0x0 : Disable
	// 0x1 : 1st Event
	// 0x2 : 2nd Event
	// 0x3 : 3rd Event

	EPwm1Regs.ETPS.bit.INTPRD = ET_1ST;
	EPwm2Regs.ETPS.bit.INTPRD = ET_1ST;
	// 0x0 : Interrupt Disable
	// 0x1 : Interrupt Enable

	EPwm1Regs.ETSEL.bit.INTEN = ET_ENABLE;
	EPwm2Regs.ETSEL.bit.INTEN = ET_ENABLE;

	//-------------------------------------------------------------------------------------------------//
	//--------------------------------------------ePWM Set2--------------------------------------------//
	//-------------------------------------------------------------------------------------------------//
	// Emulation Mode
	EPwm4Regs.TBCTL.bit.FREE_SOFT = EMUMODE_FREE;
//	EPwm5Regs.TBCTL.bit.FREE_SOFT = EMUMODE_FREE;
//	EPwm6Regs.TBCTL.bit.FREE_SOFT = EMUMODE_FREE;

	// Clock Pre-scale											// TBCLK = SYSCLKOUT/(HSPCLKDIV x CLKDIV)
	EPwm4Regs.TBCTL.bit.CLKDIV = TB_DIV1;						// /1
//	EPwm5Regs.TBCTL.bit.CLKDIV = TB_DIV1;
//	EPwm6Regs.TBCTL.bit.CLKDIV = TB_DIV1;
	EPwm4Regs.TBCTL.bit.HSPCLKDIV = TB_HSPDIV1;					// /1
//	EPwm5Regs.TBCTL.bit.HSPCLKDIV = TB_HSPDIV1;
//	EPwm6Regs.TBCTL.bit.HSPCLKDIV = TB_HSPDIV1;

	// Configure Time Base
	EPwm4Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;				// Up-Down Counter
//	EPwm5Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;
//	EPwm6Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;
	EPwm4Regs.TBCTL.bit.PRDLD = TB_IMMEDIATE;					// Shadow Disable
//	EPwm5Regs.TBCTL.bit.PRDLD = TB_IMMEDIATE;
//	EPwm6Regs.TBCTL.bit.PRDLD = TB_IMMEDIATE;
	EPwm4Regs.TBPRD = TIMEBASE3_PERIOD;							// Period(10[kHz] = 300[MHz]/(2*15000))
//	EPwm5Regs.TBPRD = TIMEBASE2_PERIOD;
//	EPwm6Regs.TBPRD = TIMEBASE2_PERIOD;

	// Counter Compare
	EPwm4Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
//	EPwm5Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
//	EPwm6Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
	EPwm4Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
//	EPwm5Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
//	EPwm6Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
	EPwm4Regs.CMPA.half.CMPA = TIMEBASE3_PERIOD_HALF;
//	EPwm5Regs.CMPA.half.CMPA = TIMEBASE2_PERIOD_HALF;
//	EPwm6Regs.CMPA.half.CMPA = TIMEBASE2_PERIOD_HALF;

	// Action Qualifier
	EPwm4Regs.AQCTLA.bit.CAU = AQ_CLEAR;
//	EPwm5Regs.AQCTLA.bit.CAU = AQ_CLEAR;
//	EPwm6Regs.AQCTLA.bit.CAU = AQ_CLEAR;
	EPwm4Regs.AQCTLA.bit.CAD = AQ_SET;
//	EPwm5Regs.AQCTLA.bit.CAD = AQ_SET;
//	EPwm6Regs.AQCTLA.bit.CAD = AQ_SET;

	// Dead Band Generator
	EPwm4Regs.DBCTL.bit.IN_MODE = DBA_ALL;
//	EPwm5Regs.DBCTL.bit.IN_MODE = DBA_ALL;
//	EPwm6Regs.DBCTL.bit.IN_MODE = DBA_ALL;
	EPwm4Regs.DBCTL.bit.POLSEL = DB_ACTV_LOC;
//	EPwm5Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
//	EPwm6Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
	EPwm4Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
//	EPwm5Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
//	EPwm6Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
	EPwm4Regs.DBRED = PWM3_DB_PERIOD;
//	EPwm5Regs.DBRED = PWM2_DB_PERIOD;
//	EPwm6Regs.DBRED = PWM2_DB_PERIOD;
	EPwm4Regs.DBFED = PWM3_DB_PERIOD;
//	EPwm5Regs.DBFED = PWM2_DB_PERIOD;
//	EPwm6Regs.DBFED = PWM2_DB_PERIOD;

	// Configure Synchronization
	EPwm4Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;					// Synchronization Signal Generation(Time Base Reference)
//	EPwm5Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;					// Synchronization Signal Receive from upper ePWM Module
//	EPwm6Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;
	EPwm4Regs.TBCTL.bit.PHSDIR = TB_UP;							// Up Count after SYNCHRONIZATION
//	EPwm5Regs.TBCTL.bit.PHSDIR = TB_UP;
//	EPwm6Regs.TBCTL.bit.PHSDIR = TB_UP;
	EPwm4Regs.TBCTL.bit.PHSEN = TB_DISABLE;						// Time Base Reference
//	EPwm5Regs.TBCTL.bit.PHSEN = TB_ENABLE;						// Time Base Receive
//	EPwm6Regs.TBCTL.bit.PHSEN = TB_ENABLE;
	EPwm4Regs.TBPHS.half.TBPHS = TB_BPHS_0DELAY;				// 2xSYSCLKOUT delay is needed to recognition in each ePWM Module passed.
//	EPwm5Regs.TBPHS.half.TBPHS = TB_BPHS_0DELAY;
//	EPwm6Regs.TBPHS.half.TBPHS = TB_BPHS_0DELAY;

//-------------------------------------------------------------------------------------------------//
//--------------------------------------------ePWM Set3--------------------------------------------//
//-------------------------------------------------------------------------------------------------//
/*
	// Emulation Mode
	EPwm7Regs.TBCTL.bit.FREE_SOFT = EMUMODE_FREE;
    EPwm8Regs.TBCTL.bit.FREE_SOFT = EMUMODE_FREE;
    EPwm9Regs.TBCTL.bit.FREE_SOFT = EMUMODE_FREE;

	// Clock Pre-scale											// TBCLK = SYSCLKOUT/(HSPCLKDIV x CLKDIV)
	EPwm7Regs.TBCTL.bit.CLKDIV = TB_DIV1;						// /1
	EPwm8Regs.TBCTL.bit.CLKDIV = TB_DIV1;
	EPwm9Regs.TBCTL.bit.CLKDIV = TB_DIV1;
	EPwm7Regs.TBCTL.bit.HSPCLKDIV = TB_HSPDIV1;				// /1
	EPwm8Regs.TBCTL.bit.HSPCLKDIV = TB_HSPDIV1;
  	EPwm9Regs.TBCTL.bit.HSPCLKDIV = TB_HSPDIV1;

	// Configure Time Base
	EPwm7Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;			// Up-Down Counter
	EPwm8Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;
	EPwm9Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;
	EPwm7Regs.TBCTL.bit.PRDLD = TB_IMMEDIATE;					// Shadow Disable
	EPwm8Regs.TBCTL.bit.PRDLD = TB_IMMEDIATE;
	EPwm9Regs.TBCTL.bit.PRDLD = TB_IMMEDIATE;
	EPwm7Regs.TBPRD = TIMEBASE3_PERIOD;						// Period(10[kHz] = 300[MHz]/(2*30) = 5 [Mhz]
	EPwm8Regs.TBPRD = TIMEBASE3_PERIOD;
	EPwm9Regs.TBPRD = TIMEBASE3_PERIOD;

	// Counter Compare
	EPwm7Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
	EPwm8Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
	EPwm9Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
	EPwm7Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
	EPwm8Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
	EPwm9Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
	EPwm7Regs.CMPA.half.CMPA = TIMEBASE3_PERIOD_HALF;
	EPwm8Regs.CMPA.half.CMPA = TIMEBASE3_PERIOD_HALF;
	EPwm9Regs.CMPA.half.CMPA = TIMEBASE3_PERIOD_HALF;

	// Action Qualifier
	EPwm7Regs.AQCTLA.bit.CAU = AQ_CLEAR;
	EPwm8Regs.AQCTLA.bit.CAU = AQ_CLEAR;
	EPwm9Regs.AQCTLA.bit.CAU = AQ_CLEAR;
	EPwm7Regs.AQCTLA.bit.CAD = AQ_SET;
	EPwm8Regs.AQCTLA.bit.CAD = AQ_SET;
	EPwm9Regs.AQCTLA.bit.CAD = AQ_SET;

	// Dead Band Generator
	EPwm7Regs.DBCTL.bit.IN_MODE = DBA_ALL;
	EPwm8Regs.DBCTL.bit.IN_MODE = DBA_ALL;
	EPwm9Regs.DBCTL.bit.IN_MODE = DBA_ALL;
	EPwm7Regs.DBCTL.bit.POLSEL = DB_ACTV_LOC;
	EPwm8Regs.DBCTL.bit.POLSEL = DB_ACTV_LOC;
	EPwm9Regs.DBCTL.bit.POLSEL = DB_ACTV_LOC;
	EPwm7Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
	EPwm8Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
	EPwm9Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
	EPwm7Regs.DBRED = PWM3_DB_PERIOD;
	EPwm8Regs.DBRED = PWM3_DB_PERIOD;
	EPwm9Regs.DBRED = PWM3_DB_PERIOD;
	EPwm7Regs.DBFED = PWM3_DB_PERIOD;
	EPwm8Regs.DBFED = PWM3_DB_PERIOD;
	EPwm9Regs.DBFED = PWM3_DB_PERIOD;

	// Configure Synchronization

	EPwm7Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;					// Synchronization Signal Generation(Time Base Reference)
	EPwm8Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;					// Synchronization Signal Receive from upper ePWM Module
	EPwm9Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;
	EPwm7Regs.TBCTL.bit.PHSDIR = TB_UP;							// Up Count after SYNCHRONIZATION
	EPwm8Regs.TBCTL.bit.PHSDIR = TB_UP;
	EPwm9Regs.TBCTL.bit.PHSDIR = TB_UP;
	EPwm7Regs.TBCTL.bit.PHSEN = TB_DISABLE;						// Time Base Reference
	EPwm8Regs.TBCTL.bit.PHSEN = TB_ENABLE;						// Time Base Receive
	EPwm9Regs.TBCTL.bit.PHSEN = TB_ENABLE;
	EPwm7Regs.TBPHS.half.TBPHS = TB_BPHS_0DELAY;				// 2xSYSCLKOUT delay is needed to recognition in each ePWM Module passed.
	EPwm8Regs.TBPHS.half.TBPHS = TB_BPHS_0DELAY;
	EPwm9Regs.TBPHS.half.TBPHS = TB_BPHS_0DELAY;
*/
	return;
}

void Start_PWM(void)
{
	EALLOW;
	SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;
	EDIS;

	return;
}


void PWM_SetDuty(real32_T _aref, real32_T _bref, real32_T _cref, real32_T _invdc)
{
    real32_T temp1;
    int COMP1 = 0, COMP2 = 0, COMP3 = 0;

    temp1 = (real32_T)TIMEBASE1_PERIOD * _invdc;

    #if (M1_PHASE_ABC)
        COMP1 = (int)(_aref * temp1);
        COMP2 = (int)(_bref * temp1);
        COMP3 = (int)(_cref * temp1);
    #elif (M1_PHASE_CBA)
        COMP1 = (int)(_cref * temp1);
        COMP2 = (int)(_bref * temp1);
        COMP3 = (int)(_cref * temp1);
    #endif

    EPwm1Regs.CMPA.half.CMPA = BOUND(COMP1, TIMEBASE1_PERIOD_HALF, -TIMEBASE1_PERIOD_HALF) + TIMEBASE1_PERIOD_HALF;
    EPwm2Regs.CMPA.half.CMPA = BOUND(COMP2, TIMEBASE1_PERIOD_HALF, -TIMEBASE1_PERIOD_HALF) + TIMEBASE1_PERIOD_HALF;
    EPwm3Regs.CMPA.half.CMPA = BOUND(COMP3, TIMEBASE1_PERIOD_HALF, -TIMEBASE1_PERIOD_HALF) + TIMEBASE1_PERIOD_HALF;

    return;
}

