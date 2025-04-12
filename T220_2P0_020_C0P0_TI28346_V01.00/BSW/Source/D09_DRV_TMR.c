/*
 *	CPUTimers.c
 *
 * C/C++ source code generated on : Thu Jan 11 10:09:04 2024
 * Created by: System Research Team
 * Code generated on : Sat Mar 15 00:16:24 2025
 *
 */

#include "Define_Header.h"
#include "D09_DRV_TMR.h"
#include "rtwtypes.h"

#define CANTXTimer                      CpuTimer0Regs

uint16_T mBSW_u1msFlag = 0U;

void Init_CPUTimers(void)
{
    // Initialize CPU Timer for CAN TX
    CANTXTimer.TCR.all = TCR_TSS_CountStop;             // 4        : TSS       ; 0(Running), 1(Stopped).

    //// Initialize CPU Timer for CAN TX : Pre-Scale Configuration
    CANTXTimer.TPR.all = 0;                             // SYSCLKOUT / 1
    CANTXTimer.TPRH.all = 0;

    //// Initialize CPU Timer for Watch Cat : Time Period Configuration
    CANTXTimer.PRD.all = 300000;                        // Watch Cat (SYSCLKOUT(300[MHz]) / 300000 = 1[kHz] = 1[msec])

    //// Initialize CPU Timer for Watch Cat : Timer Configuration
    CANTXTimer.TCR.all |= TCR_TIE_InterruptEnable       // 14       : TIE       ; 0(Interrupt Disable), 1(Interrupt Enable).
                        | TCR_FREESOFT_FreeRun          // 11-10    : FREESOFT  ; 00(Stop After Next Counting), 01(Stop After Counting ZERO), 1x(Free Run).
                        | TCR_TRB_CountReload;          // 5        : TRB       ; 1(PRD Value is Reloaded to TIM).

    return;
}

void Start_Timer(void)
{

    CANTXTimer.TCR.bit.TSS = TSS_CountRun;

	return;
}

interrupt void ISR_CAN_TX(void)
{
    mBSW_u1msFlag = 1U;

    CANTXTimer.TCR.all |= TCR_TIF_InterruptClear;
    PieCtrlRegs.PIEACK.bit.ACK1 = 1;                                // Timer0 PIE Interrupt Clear

    return;
}
