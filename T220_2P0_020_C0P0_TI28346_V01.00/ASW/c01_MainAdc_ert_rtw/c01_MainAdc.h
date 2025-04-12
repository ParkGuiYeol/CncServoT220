/*
 * File: c01_MainAdc.h
 *
 * Code generated for Simulink model 'c01_MainAdc'.
 *
 * Model version                  : 7.199
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Mar 29 20:27:45 2025
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

#ifndef c01_MainAdc_h_
#define c01_MainAdc_h_
#ifndef c01_MainAdc_COMMON_INCLUDES_
#define c01_MainAdc_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* c01_MainAdc_COMMON_INCLUDES_ */

#include <string.h>

/* Includes for objects with custom storage classes */
#include "L02_ADC_READ.h"
#include "j01_McuInit.h"
#ifndef DEFINED_TYPEDEF_FOR_S_C01HVSWF_
#define DEFINED_TYPEDEF_FOR_S_C01HVSWF_

typedef struct
{
    real32_T sVdcInit;
    real32_T sCofHvdc;
    real32_T sHVdcLa;
    real32_T sHVdcLb;
    uint16_T uDummy;
}
S_C01HVSWF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_S_C01VTEST_
#define DEFINED_TYPEDEF_FOR_S_C01VTEST_

typedef struct
{
    real32_T uFlag;
    real32_T sValue;
    uint16_T uDummy;
}
S_C01VTEST;

#endif

#ifndef DEFINED_TYPEDEF_FOR_S_C01VSENS_
#define DEFINED_TYPEDEF_FOR_S_C01VSENS_

typedef struct
{
    real32_T sResolut;
    real32_T sOpampOffset;
    real32_T sHwGain;
    real32_T sHwOffest;
    real32_T sVdcMin;
    real32_T sVdcLowerLim;
    uint16_T uDummy;
}
S_C01VSENS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_S_C01ISENS_
#define DEFINED_TYPEDEF_FOR_S_C01ISENS_

typedef struct
{
    real32_T sResolut;
    real32_T sHwOffset;
    real32_T sOpampOffset;
    real32_T sAdChipOffset;
    real32_T sGa;
    real32_T sCalCurrGain;
    uint16_T uDummy;
}
S_C01ISENS;

#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct
{
    real32_T sHVdcLow;                 /* '<S5>/Sum1' */
    real32_T sLpfNowZ;                 /* '<S5>/sLpfNowZ' */
    real32_T sLpfLowZ;                 /* '<S5>/sLpfLowZ' */
}
StrC01DW;

/* External inputs (root inport signals with default storage) */
typedef struct
{
    int32_T bADCREAD_ADR_i32IcSens;    /* '<Root>/bADCREAD_ADR_i32IcSens' */
    int32_T bADCREAD_ADR_i32IvtTempSens;
                                      /* '<Root>/bADCREAD_ADR_i32IvtTempSens' */
    int32_T bADCREAD_ADR_i32MtrTempSens;
                                      /* '<Root>/bADCREAD_ADR_i32MtrTempSens' */
    uint16_T bJ01MINITZ_mMinit_uFlgChangeISR;
                                  /* '<Root>/bJ01MINITZ_mMinit_uFlgChangeISR' */
    uint16_T bJ01MINITZ_mMinit_uHwFltCurrOff;
                               /* '<Root>/bJ01MINITZ_mMinit_uHwFltCurrOffset' */
}
StrC01ExtU;

/* Block signals and states (default storage) */
extern StrC01DW GvC01DW;

/* External inputs (root inport signals with default storage) */
extern StrC01ExtU GvC01U;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T mMsens_sIa;            /* '<Root>/bC01MADC_mMsens_sIa' */
extern real32_T mMsens_sIb;            /* '<Root>/bC01MADC_mMsens_sIb' */
extern real32_T mMsens_sIc;            /* '<Root>/bC01MADC_mMsens_sIc' */
extern real32_T mMsens_sAbsIa;         /* '<Root>/bC01MADC_mMsens_sAbsIa' */
extern real32_T mMsens_sAbsIb;         /* '<Root>/bC01MADC_mMsens_sAbsIb' */
extern real32_T mMsens_sAbsIc;         /* '<Root>/bC01MADC_mMsens_sAbsIc' */
extern real32_T mMsens_sHVdcLow;       /* '<Root>/bC01MADC_mMsens_sHVdcLow' */
extern real32_T mMsens_sInvHVdcLow;   /* '<Root>/bC01MADC_mMsens_sInvHVdcLow' */

/* Model entry point functions */
extern void c01_MainAdc_initialize(void);
extern void c01_MainAdc_step(void);

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
 * '<Root>' : 'c01_MainAdc'
 * '<S1>'   : 'c01_MainAdc/Ftn_MainAdcHVdc'
 * '<S2>'   : 'c01_MainAdc/Ftn_MainAdcMtrCurr'
 * '<S3>'   : 'c01_MainAdc/Ftn_MainAdcHVdc/Nftn_CalHVdcLow'
 * '<S4>'   : 'c01_MainAdc/Ftn_MainAdcHVdc/Nftn_CalHVdcNow'
 * '<S5>'   : 'c01_MainAdc/Ftn_MainAdcHVdc/Nftn_LpfHVdc'
 */

/*-
 * Requirements for '<Root>': c01_MainAdc

 */
#endif                                 /* c01_MainAdc_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
