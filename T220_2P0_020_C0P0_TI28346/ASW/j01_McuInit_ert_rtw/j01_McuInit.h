/*
 * File: j01_McuInit.h
 *
 * Code generated for Simulink model 'j01_McuInit'.
 *
 * Model version                  : 7.618
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Apr 19 16:33:19 2025
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

#ifndef j01_McuInit_h_
#define j01_McuInit_h_
#ifndef j01_McuInit_COMMON_INCLUDES_
#define j01_McuInit_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* j01_McuInit_COMMON_INCLUDES_ */

#include <string.h>

/* Includes for objects with custom storage classes */
#include "c01_MainAdc.h"
#ifndef DEFINED_TYPEDEF_FOR_S_J01MINIT_
#define DEFINED_TYPEDEF_FOR_S_J01MINIT_

typedef struct
{
    int32_T i32CntMaxMcuInit;
    real32_T sInvMaxCnt;
    real32_T sOcfISensOfs;
    uint16_T uDummy;
}
S_J01MINIT;

#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct
{
    real32_T sIaSum;                   /* '<S1>/Chart_CntForTx2' */
    real32_T sIbSum;                   /* '<S1>/Chart_CntForTx2' */
    int32_T i32CntMcuInit;             /* '<S1>/Chart_CntForTx2' */
}
StrJ01DW;

/* Block signals and states (default storage) */
extern StrJ01DW GvJ01DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T mMinit_sCurrOfsIa;    /* '<Root>/bJ01MINIT_mMinit_sCurrOfsIa' */
extern real32_T mMinit_sCurrOfsIb;    /* '<Root>/bJ01MINIT_mMinit_sCurrOfsIb' */
extern uint16_T mMinit_uFlgChangeISR;
                                   /* '<Root>/bJ01MINIT_mMinit_uFlgChangeISR' */
extern uint16_T mMinit_uHwFltCurrOffset;
                                /* '<Root>/bJ01MINIT_mMinit_uHwFltCurrOffset' */

/* Model entry point functions */
extern void j01_McuInit_initialize(void);
extern void j01_McuInit_step(void);

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
 * '<Root>' : 'j01_McuInit'
 * '<S1>'   : 'j01_McuInit/Nftn_CalCrtOfs'
 * '<S2>'   : 'j01_McuInit/Nftn_CalCrtOfs/Chart_CntForTx2'
 */

/*-
 * Requirements for '<Root>': j01_McuInit

 */
#endif                                 /* j01_McuInit_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
