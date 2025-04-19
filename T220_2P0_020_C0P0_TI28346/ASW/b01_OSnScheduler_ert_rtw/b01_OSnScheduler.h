/*
 * File: b01_OSnScheduler.h
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

#ifndef b01_OSnScheduler_h_
#define b01_OSnScheduler_h_
#ifndef b01_OSnScheduler_COMMON_INCLUDES_
#define b01_OSnScheduler_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* b01_OSnScheduler_COMMON_INCLUDES_ */

#include <string.h>

/* user code (top of header file) */
#include "Define_Header.h"
#include "M1_Interrupt.h"
#include "M2_Interrupt.h"
#include "Define_DAC.h"
#ifndef DEFINED_TYPEDEF_FOR_S_B01SCHED_
#define DEFINED_TYPEDEF_FOR_S_B01SCHED_

typedef struct
{
    int32_T i32CntMaxForSch;
    int32_T i32CntMaxForSpdCtrl;
    int32_T i32CntMaxForVarGain;
    int32_T i32InitCntForSch;
    int32_T i32Every8;
    uint16_T uPrd;
    uint16_T uPrdHalf;
    uint16_T uPrdQuter;
    uint16_T uPrdSOC;
    uint16_T uPrdDeadTime;
    real32_T sFreq;
    real32_T sTime;
    real32_T sTime2;
    real32_T sOutloopTime;
    real32_T sTimePstCtrl;
    real32_T sInvTimePstCtrl;
    uint32_T u32MaxEncCnt;
    uint16_T uDummy;
}
S_B01SCHED;

#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct
{
    int32_T i32CntForSpdCtrl;          /* '<S1>/Chart_OuterLoop' */
}
StrB01DW;

/* Block signals and states (default storage) */
extern StrB01DW GvB01DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern uint16_T mSched_uFlagSpdCtrl;/* '<Root>/bB01SCHED_mSched_uFlagSpdCtrl' */
extern uint16_T mSched_uFlagSpdSlop;/* '<Root>/bB01SCHED_mSched_uFlagSpdSlop' */
extern int32_T mSched_i32CntForSch; /* '<Root>/bB01SCHED_mSched_i32CntForSch' */
extern int32_T mSched_i32CntForVarGain;
                                /* '<Root>/bB01SCHED_mSched_i32CntForVarGain' */

/* Model entry point functions */
extern void b01_OSnScheduler_initialize(void);
extern void b01_OSnScheduler_step(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'b01_OSnScheduler'
 * '<S1>'   : 'b01_OSnScheduler/Ftn_TaskScheduling'
 * '<S2>'   : 'b01_OSnScheduler/Ftn_TaskScheduling/Chart_OuterLoop'
 */

/*-
 * Requirements for '<Root>': b01_OSnScheduler

 */

/* user code (bottom of header file) */
extern real32_T mBSW_sTime;
extern real32_T mBSW_sTime2;
extern real32_T mBSW_sOutloopTime;
extern real32_T mBSW_sTimePstCtrl;
extern real32_T mBSW_sInvTimePstCtrl;
extern real32_T mBSW_sFreq;

#endif                                 /* b01_OSnScheduler_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
