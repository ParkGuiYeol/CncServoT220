/*
 * File: c02_SubAdc.h
 *
 * Code generated for Simulink model 'c02_SubAdc'.
 *
 * Model version                  : 7.333
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Mar 29 20:28:08 2025
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

#ifndef c02_SubAdc_h_
#define c02_SubAdc_h_
#ifndef c02_SubAdc_COMMON_INCLUDES_
#define c02_SubAdc_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* c02_SubAdc_COMMON_INCLUDES_ */

#include <string.h>

/* Includes for objects with custom storage classes */
#include "L02_ADC_READ.h"
#include "b01_OSnScheduler.h"
#ifndef DEFINED_TYPEDEF_FOR_S_C02IGBTS_
#define DEFINED_TYPEDEF_FOR_S_C02IGBTS_

typedef struct
{
    real32_T sIgbtNtcResolut;
    real32_T sIgbtNtcHwOffset;
    real32_T sIgbtNtcR0;
    real32_T sIgbtNtcHwGain;
    real32_T sIgbtNtcV0;
    real32_T sIgbtNtcTmax;
    real32_T sIgbtNtcTmin;
    real32_T sIgbtTempOfs;
    real32_T sTempInit;
    real32_T sCofTemp;
    real32_T sTempLa;
    real32_T sTempLb;
    uint16_T uDummy;
}
S_C02IGBTS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_S_C02MTRTS_
#define DEFINED_TYPEDEF_FOR_S_C02MTRTS_

typedef struct
{
    real32_T sMtrNtcResolut;
    real32_T sMtrNtcHwOffset;
    real32_T sMtrNtcR0;
    real32_T sMtrNtcHwGain;
    real32_T sMtrNtcV0;
    real32_T sMtrNtcTmax;
    real32_T sMtrNtcTmin;
    real32_T sMtrTempOfs;
    real32_T sTempInit;
    real32_T sCofTemp;
    real32_T sTempLa;
    real32_T sTempLb;
    uint16_T uDummy;
}
S_C02MTRTS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_S_C02ITLK_
#define DEFINED_TYPEDEF_FOR_S_C02ITLK_

typedef struct
{
    real32_T sArrDivR[6];
    real32_T sArrT0[11];
    real32_T sArrT1[11];
    real32_T sArrT2[11];
    real32_T sArrT3[11];
    real32_T sArrT4[11];
    real32_T sArrR0[11];
    real32_T sArrR1[11];
    real32_T sArrR2[11];
    real32_T sArrR3[11];
    real32_T sArrR4[11];
}
S_C02ITLK;

#endif

#ifndef DEFINED_TYPEDEF_FOR_S_C02MTLK_
#define DEFINED_TYPEDEF_FOR_S_C02MTLK_

typedef struct
{
    real32_T sArrDivR[6];
    real32_T sArrT0[11];
    real32_T sArrT1[11];
    real32_T sArrT2[11];
    real32_T sArrT3[11];
    real32_T sArrT4[11];
    real32_T sArrR0[11];
    real32_T sArrR1[11];
    real32_T sArrR2[11];
    real32_T sArrR3[11];
    real32_T sArrR4[11];
}
S_C02MTLK;

#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct
{
    real32_T sMtrTemp_R;               /* '<S4>/Chart_MtrTempSensR' */
    real32_T sMtrTsen_Now;             /* '<S6>/Merge' */
    real32_T sIvtTemp_R;               /* '<S1>/Chart_IvtTempSensR' */
    real32_T sIvtTsen_Now;             /* '<S3>/Merge' */
    real32_T sLpfLowZ;                 /* '<S24>/sLpfLowZ' */
    real32_T sLpfNowZ;                 /* '<S24>/sLpfNowZ' */
    real32_T sLpfLowZ_mhrj;            /* '<S25>/sLpfLowZ' */
    real32_T sLpfNowZ_eaw3;            /* '<S25>/sLpfNowZ' */
    uint16_T uMtrTemp_RIndex;          /* '<S5>/Chart_IgbtTempSensA' */
    uint16_T uIvtTemp_RIndex;          /* '<S2>/Chart_IgbtTempSensA' */
}
StrC02DW;

/* External inputs (root inport signals with default storage) */
typedef struct
{
    int32_T bADCREAD_ADR_i32IaSens;    /* '<Root>/bADCREAD_ADR_i32IaSens' */
    int32_T bADCREAD_ADR_i32IbSens;    /* '<Root>/bADCREAD_ADR_i32IbSens' */
    int32_T bADCREAD_ADR_i32IcSens;    /* '<Root>/bADCREAD_ADR_i32IcSens' */
    int32_T bADCREAD_ADR_i32HVdcSens;  /* '<Root>/bADCREAD_ADR_i32HVdcSens' */
    uint16_T bB01SCHED_mSched_uFlagSpdCtrl;
                                    /* '<Root>/bB01SCHED_mSched_uFlagSpdCtrl' */
    uint16_T bB01SCHED_mSched_uFlagSpdSlop;
                                    /* '<Root>/bB01SCHED_mSched_uFlagSpdSlop' */
    int32_T bB01SCHED_mSched_i32CntForVarGa;
                                /* '<Root>/bB01SCHED_mSched_i32CntForVarGain' */
}
StrC02ExtU;

/* Block signals and states (default storage) */
extern StrC02DW GvC02DW;

/* External inputs (root inport signals with default storage) */
extern StrC02ExtU GvC02U;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T mSsens_sIvtTempLow;   /* '<Root>/bC02SADC_mSsens_sIvtTempLow' */
extern real32_T mSsens_sMrtTempLow;   /* '<Root>/bC02SADC_mSsens_sMrtTempLow' */

/* Model entry point functions */
extern void c02_SubAdc_initialize(void);
extern void c02_SubAdc_step(void);

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
 * '<Root>' : 'c02_SubAdc'
 * '<S1>'   : 'c02_SubAdc/Ftn_CalIvtTemp_R'
 * '<S2>'   : 'c02_SubAdc/Ftn_CalIvtTemp_RIndex'
 * '<S3>'   : 'c02_SubAdc/Ftn_CalIvtTemp_Tnow'
 * '<S4>'   : 'c02_SubAdc/Ftn_CalMtrTemp_R'
 * '<S5>'   : 'c02_SubAdc/Ftn_CalMtrTemp_RIndex1'
 * '<S6>'   : 'c02_SubAdc/Ftn_CalMtrTemp_Tnow'
 * '<S7>'   : 'c02_SubAdc/Ftn_LpfTempSensors'
 * '<S8>'   : 'c02_SubAdc/Ftn_CalIvtTemp_R/Chart_IvtTempSensR'
 * '<S9>'   : 'c02_SubAdc/Ftn_CalIvtTemp_RIndex/Chart_IgbtTempSensA'
 * '<S10>'  : 'c02_SubAdc/Ftn_CalIvtTemp_Tnow/Nftn_IvtTempSensBStp0'
 * '<S11>'  : 'c02_SubAdc/Ftn_CalIvtTemp_Tnow/Nftn_IvtTempSensBStp1'
 * '<S12>'  : 'c02_SubAdc/Ftn_CalIvtTemp_Tnow/Nftn_IvtTempSensBStp2'
 * '<S13>'  : 'c02_SubAdc/Ftn_CalIvtTemp_Tnow/Nftn_IvtTempSensBStp3'
 * '<S14>'  : 'c02_SubAdc/Ftn_CalIvtTemp_Tnow/Nftn_IvtTempSensBStp4'
 * '<S15>'  : 'c02_SubAdc/Ftn_CalIvtTemp_Tnow/Nftn_IvtTempSensBStp5'
 * '<S16>'  : 'c02_SubAdc/Ftn_CalMtrTemp_R/Chart_MtrTempSensR'
 * '<S17>'  : 'c02_SubAdc/Ftn_CalMtrTemp_RIndex1/Chart_IgbtTempSensA'
 * '<S18>'  : 'c02_SubAdc/Ftn_CalMtrTemp_Tnow/Nftn_MtrTempSensBStp0'
 * '<S19>'  : 'c02_SubAdc/Ftn_CalMtrTemp_Tnow/Nftn_MtrTempSensBStp1'
 * '<S20>'  : 'c02_SubAdc/Ftn_CalMtrTemp_Tnow/Nftn_MtrTempSensBStp2'
 * '<S21>'  : 'c02_SubAdc/Ftn_CalMtrTemp_Tnow/Nftn_MtrTempSensBStp3'
 * '<S22>'  : 'c02_SubAdc/Ftn_CalMtrTemp_Tnow/Nftn_MtrTempSensBStp4'
 * '<S23>'  : 'c02_SubAdc/Ftn_CalMtrTemp_Tnow/Nftn_MtrTempSensBStp5'
 * '<S24>'  : 'c02_SubAdc/Ftn_LpfTempSensors/Nftn_LpfIvtTemp'
 * '<S25>'  : 'c02_SubAdc/Ftn_LpfTempSensors/Nftn_LpfMtrTemp'
 */

/*-
 * Requirements for '<Root>': c02_SubAdc

 */
#endif                                 /* c02_SubAdc_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
