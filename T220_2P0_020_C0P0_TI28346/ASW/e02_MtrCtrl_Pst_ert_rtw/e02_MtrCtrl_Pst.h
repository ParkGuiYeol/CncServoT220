/*
 * File: e02_MtrCtrl_Pst.h
 *
 * Code generated for Simulink model 'e02_MtrCtrl_Pst'.
 *
 * Model version                  : 7.581
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Apr 19 16:29:46 2025
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

#ifndef e02_MtrCtrl_Pst_h_
#define e02_MtrCtrl_Pst_h_
#ifndef e02_MtrCtrl_Pst_COMMON_INCLUDES_
#define e02_MtrCtrl_Pst_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* e02_MtrCtrl_Pst_COMMON_INCLUDES_ */

#include <string.h>

/* Includes for objects with custom storage classes */
#include "b01_OSnScheduler.h"
#include "d01_Diaglnteg.h"
#include "M1_Interrupt.h"
#include "c01_MainAdc.h"
#ifndef DEFINED_TYPEDEF_FOR_S_E02SWF_
#define DEFINED_TYPEDEF_FOR_S_E02SWF_

typedef struct
{
    real32_T sEstWmLa;
    real32_T sEstWmLb;
    real32_T sEstWeLa;
    real32_T sEstWeLb;
    real32_T sEstSpdLa;
    real32_T sEstSpdLb;
    uint16_T uDummy;
}
S_E02SWF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_S_E02ITDC_
#define DEFINED_TYPEDEF_FOR_S_E02ITDC_

typedef struct
{
    real32_T sVltTdcRadMax;
    real32_T sVltTdcRadMin;
    real32_T sVltTdcGa;
    real32_T sVltTdcGb;
    uint16_T uDummy;
}
S_E02ITDC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_S_E02PST_
#define DEFINED_TYPEDEF_FOR_S_E02PST_

typedef struct
{
    real32_T sThetaOffset;
    real32_T sInvPolePairs;
    uint32_T u32EncMultiTurnMax;
    uint32_T u32EncMultiTurnOffset;
    int32_T i32EncMecMaxCnt;
    int16_T i16EncElectMaxCnt;
    real32_T sEncElectMaxCnt;
    real32_T sInvEncElectMaxCnt;
    real32_T sPI2InvPPR;
    int16_T i16AllowedCntMin;
    uint16_T uDummy;
}
S_E02PST;

#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct
{
    real32_T sEncThetaCurrTdc;         /* '<S2>/Switch3' */
    real32_T sLpfNowZ;                 /* '<S8>/sLpfNowZ' */
    real32_T sLpfLowZ;                 /* '<S8>/sLpfLowZ' */
    real32_T sLpfNowZ_mxvj;            /* '<S9>/sLpfNowZ' */
    real32_T sLpfLowZ_g0jt;            /* '<S9>/sLpfLowZ' */
    real32_T sLpfNowZ_oyf4;            /* '<S7>/sLpfNowZ' */
    real32_T sLpfLowZ_nv33;            /* '<S7>/sLpfLowZ' */
    int32_T i32CntIntegerValue;        /* '<S12>/Product1' */
    uint32_T u32EncSingleTurn;         /* '<S16>/Chart_CalSingleTurn' */
    int16_T i16PstNow;                 /* '<S12>/Data_Type_Conversion2' */
    int16_T i16DiffPostion;            /* '<S10>/Add' */
    int16_T i16Mdata;                  /* '<S6>/Chart_CalMdata' */
    int16_T i32PstZ;                   /* '<S10>/Delay' */
}
StrE02DW;

/* Block signals and states (default storage) */
extern StrE02DW GvE02DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T mMTPST_sWm;            /* '<Root>/bE02MTPST_mMTPST_sWm' */
extern real32_T mMTPST_sWe;            /* '<Root>/bE02MTPST_mMTPST_sWe' */
extern real32_T mMTPST_sRpm;           /* '<Root>/bE02MTPST_mMTPST_sRpm' */
extern real32_T mMTPST_sTheta;         /* '<Root>/bE02MTPST_mMTPST_sTheta' */
extern uint32_T mMTPST_u32EncMultiTurn;
                                 /* '<Root>/bE02MTPST_mMTPST_u32EncMultiTurn' */
extern int64_T mMTPST_i64TurretPst; /* '<Root>/bE02MTPST_mMTPST_i64TurretPst' */
extern real32_T mMTPST_sIde;           /* '<Root>/bE02MTPST_mMTPST_sIde' */
extern real32_T mMTPST_sIqe;           /* '<Root>/bE02MTPST_mMTPST_sIqe' */
extern real32_T mMTPST_sIds;           /* '<Root>/bE02MTPST_mMTPST_sIds' */
extern real32_T mMTPST_sIqs;           /* '<Root>/bE02MTPST_mMTPST_sIqs' */

/* Model entry point functions */
extern void e02_MtrCtrl_Pst_initialize(void);
extern void e02_MtrCtrl_Pst_step(void);

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
 * '<Root>' : 'e02_MtrCtrl_Pst'
 * '<S1>'   : 'e02_MtrCtrl_Pst/Ftn_RevAbc2dqe'
 * '<S2>'   : 'e02_MtrCtrl_Pst/Ftn_RevCurrDlyCmpsn'
 * '<S3>'   : 'e02_MtrCtrl_Pst/Ftn_SpdMtMethod'
 * '<S4>'   : 'e02_MtrCtrl_Pst/Nftn_CalEncData'
 * '<S5>'   : 'e02_MtrCtrl_Pst/Ftn_RevAbc2dqe/Ftn_OverCurrDebounceFilter'
 * '<S6>'   : 'e02_MtrCtrl_Pst/Ftn_SpdMtMethod/Ftn_CalMdata'
 * '<S7>'   : 'e02_MtrCtrl_Pst/Ftn_SpdMtMethod/Lib_LPF_Rpm'
 * '<S8>'   : 'e02_MtrCtrl_Pst/Ftn_SpdMtMethod/Lib_LPF_We'
 * '<S9>'   : 'e02_MtrCtrl_Pst/Ftn_SpdMtMethod/Lib_LPF_Wm'
 * '<S10>'  : 'e02_MtrCtrl_Pst/Ftn_SpdMtMethod/Nftn_CalDiffPst'
 * '<S11>'  : 'e02_MtrCtrl_Pst/Ftn_SpdMtMethod/Nftn_CalSpd'
 * '<S12>'  : 'e02_MtrCtrl_Pst/Ftn_SpdMtMethod/Nftn_CntTmToTe'
 * '<S13>'  : 'e02_MtrCtrl_Pst/Ftn_SpdMtMethod/Nftn_ThetaOffset'
 * '<S14>'  : 'e02_MtrCtrl_Pst/Ftn_SpdMtMethod/Nftn_mod'
 * '<S15>'  : 'e02_MtrCtrl_Pst/Ftn_SpdMtMethod/Ftn_CalMdata/Chart_CalMdata'
 * '<S16>'  : 'e02_MtrCtrl_Pst/Nftn_CalEncData/Nftn_IfAction'
 * '<S17>'  : 'e02_MtrCtrl_Pst/Nftn_CalEncData/Nftn_IfAction/Chart_CalMultiTurn'
 * '<S18>'  : 'e02_MtrCtrl_Pst/Nftn_CalEncData/Nftn_IfAction/Chart_CalSingleTurn'
 */

/*-
 * Requirements for '<Root>': e02_MtrCtrl_Pst

 */
#endif                                 /* e02_MtrCtrl_Pst_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
