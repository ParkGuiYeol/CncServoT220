/*
 * File: e03_MtrCtrl_MtrCtrl.h
 *
 * Code generated for Simulink model 'e03_MtrCtrl_MtrCtrl'.
 *
 * Model version                  : 7.974
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Apr 19 16:30:25 2025
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

#ifndef e03_MtrCtrl_MtrCtrl_h_
#define e03_MtrCtrl_MtrCtrl_h_
#ifndef e03_MtrCtrl_MtrCtrl_COMMON_INCLUDES_
#define e03_MtrCtrl_MtrCtrl_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                /* e03_MtrCtrl_MtrCtrl_COMMON_INCLUDES_ */

#include <string.h>

/* Includes for objects with custom storage classes */
#include "b01_OSnScheduler.h"
#include "f01_CommRx1.h"
#include "d01_Diaglnteg.h"
#include "e01_MtrCtrl_VarGain.h"
#include "e02_MtrCtrl_Pst.h"
#include "c01_MainAdc.h"
#include "h01_MdeMgmt.h"
#ifndef DEFINED_TYPEDEF_FOR_S_E03MTRSWF_
#define DEFINED_TYPEDEF_FOR_S_E03MTRSWF_

typedef struct
{
    real32_T sVdqeLa;
    real32_T sVdqeLb;
    uint16_T uDummy;
}
S_E03MTRSWF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_S_E03MCMV_
#define DEFINED_TYPEDEF_FOR_S_E03MCMV_

typedef struct
{
    real32_T uSoftMdeCurr;
    real32_T sVltSlopRising;
    real32_T sVltSlopFalling;
    real32_T sAlign16Vout;
    real32_T sAlign16Angle;
    real32_T sAlignCurr;
    real32_T sAlignDeg;
    real32_T sIfTsec;
    real32_T sIfSetFreq;
    real32_T sIfInitTheta;
    real32_T sIfCurr;
    real32_T sThetaMixedCntStp;
    real32_T sInvKt;
    real32_T sBetaRiseStep;
    real32_T sMaxFreq;
    real32_T Spare1;
    uint16_T uDummy;
}
S_E03MCMV;

#endif

#ifndef DEFINED_TYPEDEF_FOR_S_E03INIT_
#define DEFINED_TYPEDEF_FOR_S_E03INIT_

typedef struct
{
    real32_T sVfVltSlopVqeRefZ;
    real32_T sVVltSlopVqeRefZ;
    real32_T sTqRefInit;
    real32_T sIsRefInZ;
    real32_T sIdeCtrlIntegZ;
    real32_T sIqeCtrlIntegZ;
    real32_T Spare0;
    real32_T Spare1;
    uint16_T uDummy;
}
S_E03INIT;

#endif

#ifndef DEFINED_TYPEDEF_FOR_S_E03LIM_
#define DEFINED_TYPEDEF_FOR_S_E03LIM_

typedef struct
{
    real32_T sCurrLim;
    real32_T sNegCurrLim;
    real32_T sVrefLim;
    real32_T sNegVrefLim;
    real32_T sMaxTqSet;
    real32_T sNegMaxTqSet;
    real32_T sMaxSpdSet;
    real32_T sNegMaxSpdSet;
    uint16_T uDummy;
}
S_E03LIM;

#endif

#ifndef DEFINED_TYPEDEF_FOR_S_E03CCTRL_
#define DEFINED_TYPEDEF_FOR_S_E03CCTRL_

typedef struct
{
    real32_T sLd;
    real32_T sLq;
    real32_T sKe;
    real32_T sPolePairs;
    real32_T sKad;
    real32_T sKaq;
    uint16_T uDummy;
}
S_E03CCTRL;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_bj1ExGRNw9aiVazfqIN6sG_
#define DEFINED_TYPEDEF_FOR_struct_bj1ExGRNw9aiVazfqIN6sG_

typedef struct
{
    real32_T mCTRL_sIdeRef;
    real32_T mCTRL_sIqeRef;
    real32_T mCTRL_sIde;
    real32_T mCTRL_sIqe;
    real32_T sTheta;
}
struct_bj1ExGRNw9aiVazfqIN6sG;

#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct
{
    real_T sIsRefIn2;                  /* '<S29>/UnitDelay_sIsRefIn' */
    real32_T aMerOutCCurrTheta[4];     /* '<S7>/Merge' */
    real32_T aMerVC[3];                /* '<S1>/Merge' */
    real32_T sIde;                     /* '<S22>/SignalConversion1' */
    real32_T sIqe;                     /* '<S22>/SignalConversion2' */
    real32_T sAppTheta;                /* '<S22>/SignalConversion3' */
    real32_T sIds;                     /* '<S32>/Gain1' */
    real32_T mCTRL_sIfTheta_daj2;      /* '<S32>/mCTRL_sIfTheta' */
    real32_T sIqs;                     /* '<S32>/Gain2' */
    real32_T sIde_esgf;                /* '<S32>/Sum2' */
    real32_T sIqe_nbmc;                /* '<S32>/Sum3' */
    real32_T sIfCurr;                  /* '<S32>/sIfCurr' */
    real32_T sIds_gxrm;                /* '<S18>/Gain1' */
    real32_T sIdqCosTheta;             /* '<S18>/TrigonometricFunction1' */
    real32_T sIqs_pe32;                /* '<S18>/Gain2' */
    real32_T sIdqSinTheta;             /* '<S18>/TrigonometricFunction' */
    real32_T sSpdRef;                  /* '<S38>/Merge1' */
    real32_T sPstKpCtrlRlt;            /* '<S41>/Saturation5' */
    real32_T sPstKdCtrlRlt;            /* '<S41>/Saturation3' */
    real32_T sSpdRefPstMde;            /* '<S41>/Saturation1' */
    real32_T sSpdCtrlMdeTqRefLimited;  /* '<S47>/Saturation1' */
    real32_T sIqeIntegLimited;         /* '<S36>/Saturation1' */
    real32_T sIqKpErr;                 /* '<S36>/Product2' */
    real32_T sIqFFRlt;                 /* '<S36>/Add4' */
    real32_T sVqeRef;                  /* '<S36>/Saturation' */
    real32_T sIdeIntegLimited;         /* '<S35>/Saturation1' */
    real32_T sIdKpErr;                 /* '<S35>/Product1' */
    real32_T sIdFFRlt;                 /* '<S35>/Product6' */
    real32_T sVdeRef;                  /* '<S35>/Saturation' */
    real32_T sTheta;                   /* '<S24>/SignalConversion4' */
    real32_T sIFreqBetaCmd;            /* '<S26>/Chart_CalIsBeta2IdqRef' */
    real32_T sVVqeRef;                 /* '<S12>/Switch2' */
    real32_T sVfThetaRef;              /* '<S15>/Chart_MtrCtrlMdeVFCtrl' */
    real32_T sVfVqeRef;                /* '<S14>/Switch2' */
    real32_T TqRefLimited;             /* '<S38>/Merge' */
    real32_T sIfThetaZ;                /* '<S33>/UnitDelay' */
    real32_T sIsRefIn2_hdgx;           /* '<S52>/UnitDelay_sIsRefIn' */
    real32_T Delay1_DSTATE;            /* '<S41>/Delay1' */
    real32_T Delay2_DSTATE;            /* '<S41>/Delay2' */
    real32_T Delay_DSTATE;             /* '<S41>/Delay' */
    real32_T Delay_DSTATE_fsbd;        /* '<S50>/Delay' */
    real32_T sSpdAntiValZ;             /* '<S47>/UnitDelay' */
    real32_T sTqRef_IntegZ;            /* '<S47>/UnitDelay1' */
    real32_T sIqeIntegZ;               /* '<S36>/UnitDelay' */
    real32_T sIdeIntegZ;               /* '<S35>/UnitDelay' */
    real32_T sVqeRefZ_V;               /* '<S12>/UnitDelay1' */
    real32_T sVqeRefZ_VF;              /* '<S14>/UnitDelay1' */
    real32_T sLpfLowZ;                 /* '<S11>/sLpfLowZ' */
    real32_T sLpfNowZ;                 /* '<S11>/sLpfNowZ' */
    real32_T sLpfLowZ_nuzg;            /* '<S10>/sLpfLowZ' */
    real32_T sLpfNowZ_m0tm;            /* '<S10>/sLpfNowZ' */
    uint16_T uAppCtrlMde;              /* '<S8>/Chart' */
}
StrE03DW;

/* Block signals and states (default storage) */
extern StrE03DW GvE03DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T mCTRL_sIsRef;          /* '<Root>/bE03MCTRL_mCTRL_sIsRef' */
extern real32_T mCTRL_sIdeRef;         /* '<Root>/bE03MCTRL_mCTRL_sIdeRef' */
extern real32_T mCTRL_sIqeRef;         /* '<Root>/bE03MCTRL_mCTRL_sIqeRef' */
extern real32_T mCTRL_sIde;            /* '<Root>/bE03MCTRL_mCTRL_sIde' */
extern real32_T mCTRL_sIqe;            /* '<Root>/bE03MCTRL_mCTRL_sIqe' */
extern real32_T mCTRL_sIfTheta;        /* '<Root>/bE03MCTRL_mCTRL_sIfTheta' */
extern real32_T mCTRL_sIfFreq;         /* '<Root>/bE03MCTRL_mCTRL_sIfFreq' */
extern real32_T mCTRL_sSpdRefIn;       /* '<Root>/bE03MCTRL_mCTRL_sSpdRefIn' */
extern real32_T mCTRL_sTqRefIn;        /* '<Root>/bE03MCTRL_mCTRL_sTqRefIn' */
extern real32_T mCTRL_sVdeRefLow;      /* '<Root>/bE03MCTRL_mCTRL_sVdeRefLow' */
extern real32_T mCTRL_sVqeRefLow;      /* '<Root>/bE03MCTRL_mCTRL_sVqeRefLow' */
extern real32_T mCTRL_sVdeRef;         /* '<Root>/bE03MCTRL_mCTRL_sVdeRef' */
extern real32_T mCTRL_sVqeRef;         /* '<Root>/bE03MCTRL_mCTRL_sVqeRef' */
extern real32_T mCTRL_sThetaCtrl;      /* '<Root>/bE03MCTRL_mCTRL_sThetaCtrl' */

/* Model entry point functions */
extern void e03_MtrCtrl_MtrCtrl_initialize(void);
extern void e03_MtrCtrl_MtrCtrl_step(void);

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
 * '<Root>' : 'e03_MtrCtrl_MtrCtrl'
 * '<S1>'   : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl'
 * '<S2>'   : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_LpfVdqeRef'
 * '<S3>'   : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrCtrlMdeAlignCtrl'
 * '<S4>'   : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrCtrlMdeDefault'
 * '<S5>'   : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrCtrlMdeVCtrl'
 * '<S6>'   : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrCtrlMdeVFCtrl'
 * '<S7>'   : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn'
 * '<S8>'   : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_SelectionCtrlMde'
 * '<S9>'   : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Nftn_MerVC'
 * '<S10>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_LpfVdqeRef/LowPassFilter'
 * '<S11>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_LpfVdqeRef/LowPassFilter1'
 * '<S12>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrCtrlMdeVCtrl/Ftn_VCtrlSlop'
 * '<S13>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrCtrlMdeVCtrl/Nftn_MuxVCtrl'
 * '<S14>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrCtrlMdeVFCtrl/Ftn_VfCtrlSlop'
 * '<S15>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrCtrlMdeVFCtrl/Nftn_MuxVFCtrl'
 * '<S16>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrCtrlMdeVFCtrl/Nftn_MuxVFCtrl/Chart_MtrCtrlMdeVFCtrl'
 * '<S17>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Ftn_CurrRefSelection'
 * '<S18>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Ftn_MtrMdeCmCurrAlignCtrl'
 * '<S19>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Ftn_MtrMdeCmCurrCtrl'
 * '<S20>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Ftn_MtrMdeCmIFCtrl'
 * '<S21>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_CurrCtrl'
 * '<S22>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_GenBusFromMerOut'
 * '<S23>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_MtrMdeCmSpdCm'
 * '<S24>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Ftn_CurrRefSelection/Nftn_GenArryOut'
 * '<S25>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Ftn_CurrRefSelection/Nftn_SftCurrMde'
 * '<S26>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Ftn_CurrRefSelection/Nftn_SftCurrMde/Nftn_CalIsBeta2IdqRef'
 * '<S27>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Ftn_CurrRefSelection/Nftn_SftCurrMde/Nftn_GensAppIeRefLim'
 * '<S28>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Ftn_CurrRefSelection/Nftn_SftCurrMde/Nftn_SftMdeCurrBypass'
 * '<S29>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Ftn_CurrRefSelection/Nftn_SftCurrMde/Nftn_SftMdeCurrStart'
 * '<S30>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Ftn_CurrRefSelection/Nftn_SftCurrMde/Nftn_CalIsBeta2IdqRef/Chart_CalIsBeta2IdqRef'
 * '<S31>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Ftn_CurrRefSelection/Nftn_SftCurrMde/Nftn_GensAppIeRefLim/Chart_GensAppIeRefLim'
 * '<S32>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Ftn_MtrMdeCmIFCtrl/Ftn_MtrMdeCmIFCtrlB'
 * '<S33>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Ftn_MtrMdeCmIFCtrl/Nftn_MtrMdeCmIFCtrlA'
 * '<S34>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Ftn_MtrMdeCmIFCtrl/Nftn_MtrMdeCmIFCtrlA/Chart'
 * '<S35>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_CurrCtrl/Ftn_IdControl'
 * '<S36>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_CurrCtrl/Ftn_IqControl'
 * '<S37>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_CurrCtrl/Nftn_GenMuxVdqeRef'
 * '<S38>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_MtrMdeCmSpdCm/Ftn_TqSpdPstCtrl'
 * '<S39>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_MtrMdeCmSpdCm/Ftn_TqSpdPstCtrl/Ftn_MtrMdeCmSpSpdCtrl'
 * '<S40>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_MtrMdeCmSpdCm/Ftn_TqSpdPstCtrl/Ftn_MtrMdeCmTqOut'
 * '<S41>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_MtrMdeCmSpdCm/Ftn_TqSpdPstCtrl/Ftn_PstCtrl'
 * '<S42>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_MtrMdeCmSpdCm/Ftn_TqSpdPstCtrl/Nftn_MtrMdeCmSpdCmTqCtrl'
 * '<S43>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_MtrMdeCmSpdCm/Ftn_TqSpdPstCtrl/Subsystem'
 * '<S44>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_MtrMdeCmSpdCm/Ftn_TqSpdPstCtrl/Subsystem3'
 * '<S45>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_MtrMdeCmSpdCm/Ftn_TqSpdPstCtrl/Subsystem4'
 * '<S46>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_MtrMdeCmSpdCm/Ftn_TqSpdPstCtrl/Ftn_MtrMdeCmSpSpdCtrl/Ftn_SoftSpdMde'
 * '<S47>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_MtrMdeCmSpdCm/Ftn_TqSpdPstCtrl/Ftn_MtrMdeCmSpSpdCtrl/Ftn_SpdCtrl'
 * '<S48>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_MtrMdeCmSpdCm/Ftn_TqSpdPstCtrl/Ftn_MtrMdeCmSpSpdCtrl/Subsystem'
 * '<S49>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_MtrMdeCmSpdCm/Ftn_TqSpdPstCtrl/Ftn_MtrMdeCmSpSpdCtrl/Ftn_SoftSpdMde/Nftn_GensAppIeSpdRefLim'
 * '<S50>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_MtrMdeCmSpdCm/Ftn_TqSpdPstCtrl/Ftn_MtrMdeCmSpSpdCtrl/Ftn_SoftSpdMde/Nftn_SftMdeSpdStart'
 * '<S51>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_MtrMdeCmSpdCm/Ftn_TqSpdPstCtrl/Ftn_MtrMdeCmSpSpdCtrl/Ftn_SoftSpdMde/Nftn_GensAppIeSpdRefLim/Chart_GensAppIeSpdRefLim'
 * '<S52>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_MtrMdeCmSpdCm/Ftn_TqSpdPstCtrl/Nftn_MtrMdeCmSpdCmTqCtrl/Nftn_SftMdeTqRef'
 * '<S53>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_MtrMdeCmSpdCm/Ftn_TqSpdPstCtrl/Nftn_MtrMdeCmSpdCmTqCtrl/Nftn_TqLimit'
 * '<S54>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_SelectionCtrlMde/Chart'
 */

/*-
 * Requirements for '<Root>': e03_MtrCtrl_MtrCtrl

 */
#endif                                 /* e03_MtrCtrl_MtrCtrl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
