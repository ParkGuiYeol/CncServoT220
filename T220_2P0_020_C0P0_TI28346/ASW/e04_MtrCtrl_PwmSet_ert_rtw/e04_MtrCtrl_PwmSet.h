/*
 * File: e04_MtrCtrl_PwmSet.h
 *
 * Code generated for Simulink model 'e04_MtrCtrl_PwmSet'.
 *
 * Model version                  : 7.213
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Apr 19 16:31:18 2025
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

#ifndef e04_MtrCtrl_PwmSet_h_
#define e04_MtrCtrl_PwmSet_h_
#ifndef e04_MtrCtrl_PwmSet_COMMON_INCLUDES_
#define e04_MtrCtrl_PwmSet_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* e04_MtrCtrl_PwmSet_COMMON_INCLUDES_ */

#include <string.h>

/* Includes for objects with custom storage classes */
#include "e03_MtrCtrl_MtrCtrl.h"
#include "e02_MtrCtrl_Pst.h"
#include "c01_MainAdc.h"
#ifndef DEFINED_TYPEDEF_FOR_S_E04SWF_
#define DEFINED_TYPEDEF_FOR_S_E04SWF_

typedef struct
{
    real32_T sVltRatioLa;
    real32_T sVltRatioLb;
    uint16_T uDummy;
}
S_E04SWF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_S_E04VTDC_
#define DEFINED_TYPEDEF_FOR_S_E04VTDC_

typedef struct
{
    real32_T sVltTdcRadMax;
    real32_T sVltTdcRadMin;
    real32_T sVltTdcGa;
    real32_T sVltTdcGb;
    uint16_T uDummy;
}
S_E04VTDC;

#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct
{
    real32_T sTempVmax2;               /* '<S2>/Switch1' */
    real32_T sVrMax;                   /* '<S2>/Switch2' */
    real32_T sTempVmin2;               /* '<S2>/Switch3' */
    real32_T sVrMin;                   /* '<S2>/Switch4' */
    real32_T sLpfNowZ;                 /* '<S6>/sLpfNowZ' */
    real32_T sLpfLowZ;                 /* '<S6>/sLpfLowZ' */
}
StrE04DW;

/* Block signals and states (default storage) */
extern StrE04DW GvE04DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T mGPwm_sVanRef;         /* '<Root>/bE04GPWM_mGPwm_sVanRef' */
extern real32_T mGPwm_sVbnRef;         /* '<Root>/bE04GPWM_mGPwm_sVbnRef' */
extern real32_T mGPwm_sVcnRef;         /* '<Root>/bE04GPWM_mGPwm_sVcnRef' */
extern real32_T mGPwm_sMiLow;          /* '<Root>/bE04GPWM_mGPwm_sMiLow' */
extern real32_T mGPwm_sThetaCtrl;      /* '<Root>/bE04GPWM_mGPwm_sThetaCtrl' */

/* Model entry point functions */
extern void e04_MtrCtrl_PwmSet_initialize(void);
extern void e04_MtrCtrl_PwmSet_step(void);

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
 * '<Root>' : 'e04_MtrCtrl_PwmSet'
 * '<S1>'   : 'e04_MtrCtrl_PwmSet/Ftn_CalModulationIndex'
 * '<S2>'   : 'e04_MtrCtrl_PwmSet/Ftn_FindMinMax'
 * '<S3>'   : 'e04_MtrCtrl_PwmSet/Ftn_SVPWM'
 * '<S4>'   : 'e04_MtrCtrl_PwmSet/Ftn_Vdqe2Vabc'
 * '<S5>'   : 'e04_MtrCtrl_PwmSet/Ftn_VltDelayCompensation'
 * '<S6>'   : 'e04_MtrCtrl_PwmSet/Ftn_CalModulationIndex/Nft_LpfMI'
 */

/*-
 * Requirements for '<Root>': e04_MtrCtrl_PwmSet

 */
#endif                                 /* e04_MtrCtrl_PwmSet_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
