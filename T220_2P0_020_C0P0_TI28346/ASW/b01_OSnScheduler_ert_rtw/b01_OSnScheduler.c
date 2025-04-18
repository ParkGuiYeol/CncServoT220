/*
 * File: b01_OSnScheduler.c
 *
 * Code generated for Simulink model 'b01_OSnScheduler'.
 *
 * Model version                  : 7.234
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Apr 19 16:27:17 2025
 * Created by: System Research Team
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. Execution efficiency
 *    3. RAM efficiency
 *    4. ROM efficiency
 * Validation result: Not run
 */

#include "b01_OSnScheduler.h"
#include "rtwtypes.h"

/* user code (top of source file) */
real32_T mBSW_sTime;
real32_T mBSW_sTime2;
real32_T mBSW_sOutloopTime;
real32_T mBSW_sTimePstCtrl;
real32_T mBSW_sInvTimePstCtrl;
real32_T mBSW_sFreq;

/* Exported block signals */
uint16_T mSched_uFlagSpdCtrl;       /* '<Root>/bB01SCHED_mSched_uFlagSpdCtrl' */
uint16_T mSched_uFlagSpdSlop;       /* '<Root>/bB01SCHED_mSched_uFlagSpdSlop' */
int32_T mSched_i32CntForSch;        /* '<Root>/bB01SCHED_mSched_i32CntForSch' */
int32_T mSched_i32CntForVarGain;/* '<Root>/bB01SCHED_mSched_i32CntForVarGain' */

/* Exported data definition */

/* Definition for custom storage class: FileScope */
static S_B01SCHED B01SCHED =
{
    30,
    10,
    3,
    1,
    8,
    15000U,
    7500U,
    3750U,
    50U,
    1020U,
    10000.0F,
    0.0001F,
    0.0002F,
    0.001F,
    0.003F,
    333.333344F,
    131071U,
    0U
} ;                                    /* Referenced by:
                                        * '<S1>/CB_i32CntMaxForSch'
                                        * '<S1>/CB_i32CntMaxForSpdCtrl'
                                        * '<S1>/CB_i32CntMaxForVarGain'
                                        * '<S1>/CB_i32Every8'
                                        * '<S1>/CB_i32InitCntForSch'
                                        */

/* Block signals and states (default storage) */
StrB01DW GvB01DW;
static void Ftn_TaskScheduling_Init(void);
static void Ftn_TaskScheduling(void);

/* System initialize for atomic system: '<Root>/Ftn_TaskScheduling' */
static void Ftn_TaskScheduling_Init(void)
{
    mSched_i32CntForSch = 0L;
    mSched_uFlagSpdCtrl = 0U;
    mSched_uFlagSpdSlop = 0U;
    mSched_i32CntForVarGain = 0L;
    GvB01DW.i32CntForSpdCtrl = 1L;
}

/* Output and update for atomic system: '<Root>/Ftn_TaskScheduling' */
static void Ftn_TaskScheduling(void)
{
    if (mSched_i32CntForSch >= B01SCHED.i32CntMaxForSch)
    {
        mSched_i32CntForSch = B01SCHED.i32InitCntForSch;
        GvB01DW.i32CntForSpdCtrl = B01SCHED.i32InitCntForSch;
    }
    else
    {
        mSched_i32CntForSch += B01SCHED.i32InitCntForSch;
    }

    if (GvB01DW.i32CntForSpdCtrl >= B01SCHED.i32CntMaxForSpdCtrl)
    {
        GvB01DW.i32CntForSpdCtrl = B01SCHED.i32InitCntForSch;
        mSched_uFlagSpdCtrl = 1U;
    }
    else
    {
        GvB01DW.i32CntForSpdCtrl += B01SCHED.i32InitCntForSch;
        mSched_uFlagSpdCtrl = 0U;
        mSched_uFlagSpdSlop = (uint16_T)((GvB01DW.i32CntForSpdCtrl ==
            B01SCHED.i32Every8) ? ((int16_T)1) : ((int16_T)0));
    }

    if (mSched_i32CntForVarGain >= B01SCHED.i32CntMaxForVarGain)
    {
        mSched_i32CntForVarGain = B01SCHED.i32InitCntForSch;
    }
    else
    {
        mSched_i32CntForVarGain += B01SCHED.i32InitCntForSch;
    }
}

/* Model step function */
void b01_OSnScheduler_step(void)
{
    Ftn_TaskScheduling();
}

/* Model initialize function */
void b01_OSnScheduler_initialize(void)
{
    /* Registration code */

    /* states (dwork) */
    (void) memset((void *) &GvB01DW, 0,
                  sizeof(StrB01DW));

    /* external outputs */
    mSched_uFlagSpdCtrl = 0U;
    mSched_uFlagSpdSlop = 0U;
    mSched_i32CntForSch = 0L;
    mSched_i32CntForVarGain = 0L;
    Ftn_TaskScheduling_Init();

    /* user code (Initialize function Trailer) */
    mBSW_sFreq = B01SCHED.sFreq;
    mBSW_sTime = B01SCHED.sTime;
    mBSW_sTime2 = B01SCHED.sTime2;
    mBSW_sOutloopTime = B01SCHED.sOutloopTime;
    mBSW_sTimePstCtrl = B01SCHED.sTimePstCtrl;
    mBSW_sInvTimePstCtrl = B01SCHED.sInvTimePstCtrl;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
