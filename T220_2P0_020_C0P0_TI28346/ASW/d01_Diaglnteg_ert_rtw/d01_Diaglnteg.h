/*
 * File: d01_Diaglnteg.h
 *
 * Code generated for Simulink model 'd01_Diaglnteg'.
 *
 * Model version                  : 7.632
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Mar 29 20:28:39 2025
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

#ifndef d01_Diaglnteg_h_
#define d01_Diaglnteg_h_
#ifndef d01_Diaglnteg_COMMON_INCLUDES_
#define d01_Diaglnteg_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* d01_Diaglnteg_COMMON_INCLUDES_ */

#include <string.h>

/* Includes for objects with custom storage classes */
#include "M2_Interrupt.h"
#include "b01_OSnScheduler.h"
#include "M1_Interrupt.h"
#include "e03_MtrCtrl_MtrCtrl.h"
#include "e02_MtrCtrl_Pst.h"
#include "j01_McuInit.h"
#include "c01_MainAdc.h"
#include "h01_MdeMgmt.h"
#include "c02_SubAdc.h"
#ifndef DEFINED_TYPEDEF_FOR_S_D01CRT_
#define DEFINED_TYPEDEF_FOR_S_D01CRT_

typedef struct
{
    real32_T sOvrCrtFltDtcLvl;
    real32_T sCrtSnsrFltDtcLvl;
    real32_T sFixedCrtFltDtcLvl;
    int32_T i32CrtFltDebCnt;
    int32_T i32CrtSnsrFltDebCnt;
    int32_T i32FixedCrtFltDtcCnt;
    uint16_T uDummy;
}
S_D01CRT;

#endif

#ifndef DEFINED_TYPEDEF_FOR_S_D01VDC_
#define DEFINED_TYPEDEF_FOR_S_D01VDC_

typedef struct
{
    real32_T sDcUdrVltLedOffSet;
    real32_T sDcUdrVltFltDtcLvl;
    real32_T sDcVltInitRlyOprLvl;
    real32_T sDcOvrChpHysOprLvl;
    real32_T sDcOvrWarnFltDtcLvl;
    real32_T sDcOvrVltFltDtcLvl;
    uint16_T uDummy;
}
S_D01VDC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_S_D02DFLT_
#define DEFINED_TYPEDEF_FOR_S_D02DFLT_

typedef struct
{
    uint32_T u32DisFltAll;
    uint16_T uDummy;
}
S_D02DFLT;

#endif

#ifndef DEFINED_TYPEDEF_FOR_S_D01SPD_
#define DEFINED_TYPEDEF_FOR_S_D01SPD_

typedef struct
{
    real32_T sOvrSpdFltDtcLvl;
    int32_T i32OvrSpdFltDebCnt;
    uint16_T uDummy;
}
S_D01SPD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_S_D01TEMP_
#define DEFINED_TYPEDEF_FOR_S_D01TEMP_

typedef struct
{
    real32_T sIvtTempSnsrFltDtcLow;
    real32_T sIvtOvrTempFltDtcLvl;
    real32_T sFanOnIvtTempSet;
    real32_T sFanOffIvtTempSet;
    real32_T sMtrTempSnsrDtcLow;
    real32_T sMtrOvrTempFltDtcLvl;
    real32_T sMtrTempSnsrDtcHigh;
    uint16_T uDummy;
}
S_D01TEMP;

#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct
{
    real32_T sImax;                    /* '<S1>/Max' */
    int32_T mDIAG_i32CntCurrOver;     /* '<S12>/Chart_T01Diag_OverCurrErrDtc' */
    int32_T mDIAG_i32CntCrOvr;         /* '<S5>/Chart_T01Diag_OverCurrErrDtc' */
    int32_T i32CntIaFixedCurrUp;       /* '<S16>/Chart_T30CrtSnsrFltDtc' */
    int32_T i32CntIaFixedCurrDown;     /* '<S16>/Chart_T30CrtSnsrFltDtc' */
    int32_T i32CntSnsrFlt;             /* '<S16>/Chart_T30CrtSnsrFltDtc' */
    int32_T i32CntIbFixedCurrDown;     /* '<S16>/Chart_T30CrtSnsrFltDtc' */
    int32_T i32CntIbFixedCurrUp;       /* '<S16>/Chart_T30CrtSnsrFltDtc' */
    uint16_T uFlag_Hysteresis;         /* '<S7>/Chart_T01HvdcFltDtc' */
}
StrD01DW;

/* Block signals and states (default storage) */
extern StrD01DW GvD01DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern uint16_T mDIAG_uFltStat;        /* '<Root>/bD01DIAG_mDIAG_uFltStat' */
extern uint32_T mDIAG_u32FltAll;       /* '<Root>/bD01DIAG_mDIAG_u32FltAll' */
extern uint16_T mDIAG_uChprOpr1On0Off;
                                   /* '<Root>/bD01DIAG_mDIAG_uChprOpr1On0Off' */
extern uint16_T mDIAG_uFan1On0Off;     /* '<Root>/bD01DIAG_mDIAG_uFan1On0Off' */
extern uint16_T mDIAG_uCntCrtOvr;      /* '<Root>/bD01DIAG_mDIAG_uCntCrtOvr' */
extern uint32_T sF01_T01_EstopSwitchFlt;
                                 /* '<Root>/bD01DIAG_sF01_T01_EstopSwitchFlt' */
extern uint32_T sF02_T01_IgptShrtFlt;
                                    /* '<Root>/bD01DIAG_sF02_T01_IgptShrtFlt' */
extern uint32_T sF03_T01_HvdcOvrVolFlt;
                                  /* '<Root>/bD01DIAG_sF03_T01_HvdcOvrVolFlt' */
extern uint32_T sF04_T01_HvdcUdrVolFlt;
                                  /* '<Root>/bD01DIAG_sF04_T01_HvdcUdrVolFlt' */
extern uint32_T sF05_T30_CrtSnsrFlt; /* '<Root>/bD01DIAG_sF05_T30_CrtSnsrFlt' */
extern uint32_T sF06_T30_CrtSnsrOfsFlt;
                                  /* '<Root>/bD01DIAG_sF06_T30_CrtSnsrOfsFlt' */
extern uint32_T sF07_T30_CrtStallFlt;
                                    /* '<Root>/bD01DIAG_sF07_T30_CrtStallFlt' */
extern uint32_T sF08_T01_CrtOvrFlt;   /* '<Root>/bD01DIAG_sF08_T01_CrtOvrFlt' */
extern uint32_T sF09_T30_IvtTempSnsrFlt;
                                 /* '<Root>/bD01DIAG_sF09_T30_IvtTempSnsrFlt' */
extern uint32_T sF10_T30_IvtTempOvrFlt;
                                  /* '<Root>/bD01DIAG_sF10_T30_IvtTempOvrFlt' */
extern uint32_T sF11_T30_MtrTempSnsrFlt;
                                 /* '<Root>/bD01DIAG_sF11_T30_MtrTempSnsrFlt' */
extern uint32_T sF12_T30_MtrTempOvrFlt;
                                  /* '<Root>/bD01DIAG_sF12_T30_MtrTempOvrFlt' */
extern uint32_T sF13_T10_MtrSpdFlt;   /* '<Root>/bD01DIAG_sF13_T10_MtrSpdFlt' */
extern uint32_T sF16_T10_InitNvRam;   /* '<Root>/bD01DIAG_sF16_T10_InitNvRam' */

/* Model entry point functions */
extern void d01_Diaglnteg_initialize(void);
extern void d01_Diaglnteg_step(void);

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
 * '<Root>' : 'd01_Diaglnteg'
 * '<S1>'   : 'd01_Diaglnteg/Ftn_T01CalCurrMax'
 * '<S2>'   : 'd01_Diaglnteg/Ftn_T01DiagGroup'
 * '<S3>'   : 'd01_Diaglnteg/Ftn_T01Diaglntegration'
 * '<S4>'   : 'd01_Diaglnteg/Ftn_T30DiagGroup'
 * '<S5>'   : 'd01_Diaglnteg/Ftn_T01DiagGroup/Ftn_T01CrtFltDtc'
 * '<S6>'   : 'd01_Diaglnteg/Ftn_T01DiagGroup/Ftn_T01GateAndEstpFltDtc'
 * '<S7>'   : 'd01_Diaglnteg/Ftn_T01DiagGroup/Ftn_T01HvdcFltDtc'
 * '<S8>'   : 'd01_Diaglnteg/Ftn_T01DiagGroup/Ftn_T01CrtFltDtc/Chart_T01Diag_OverCurrErrDtc'
 * '<S9>'   : 'd01_Diaglnteg/Ftn_T01DiagGroup/Ftn_T01GateAndEstpFltDtc/Chart_T01GateAndEstpFltDtc'
 * '<S10>'  : 'd01_Diaglnteg/Ftn_T01DiagGroup/Ftn_T01HvdcFltDtc/Chart_T01HvdcFltDtc'
 * '<S11>'  : 'd01_Diaglnteg/Ftn_T01Diaglntegration/Ftn_FaultIntegration'
 * '<S12>'  : 'd01_Diaglnteg/Ftn_T30DiagGroup/Ftn_T10MtrSpdFltDtc'
 * '<S13>'  : 'd01_Diaglnteg/Ftn_T30DiagGroup/Ftn_T30InitNvRamDtc'
 * '<S14>'  : 'd01_Diaglnteg/Ftn_T30DiagGroup/Ftn_T30IvtTempFltDtc'
 * '<S15>'  : 'd01_Diaglnteg/Ftn_T30DiagGroup/Ftn_T30MtrTempFltDtc'
 * '<S16>'  : 'd01_Diaglnteg/Ftn_T30DiagGroup/Ftn_T30StalAndCrtSnsrFltDtc'
 * '<S17>'  : 'd01_Diaglnteg/Ftn_T30DiagGroup/Ftn_T10MtrSpdFltDtc/Chart_T01Diag_OverCurrErrDtc'
 * '<S18>'  : 'd01_Diaglnteg/Ftn_T30DiagGroup/Ftn_T30InitNvRamDtc/Chart_T30InitNvRamDtc'
 * '<S19>'  : 'd01_Diaglnteg/Ftn_T30DiagGroup/Ftn_T30IvtTempFltDtc/Chart'
 * '<S20>'  : 'd01_Diaglnteg/Ftn_T30DiagGroup/Ftn_T30MtrTempFltDtc/Chart'
 * '<S21>'  : 'd01_Diaglnteg/Ftn_T30DiagGroup/Ftn_T30StalAndCrtSnsrFltDtc/Chart_T30CrtSnsrFltDtc'
 */

/*-
 * Requirements for '<Root>': d01_Diaglnteg

 */
#endif                                 /* d01_Diaglnteg_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
