/*
 * File: e03_MtrCtrl_MtrCtrl.h
 *
 * Code generated for Simulink model 'e03_MtrCtrl_MtrCtrl'.
 *
 * Model version                  : 7.922
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu Apr 10 11:44:39 2025
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
    real32_T sSpdLimOfNor;
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
    int64_T Delay_DSTATE;              /* '<S40>/Delay' */
    real32_T aMerOutCCurrTheta[4];     /* '<S7>/Merge' */
    real32_T aMerVC[3];                /* '<S1>/Merge' */
    real32_T sIde;                     /* '<S22>/SignalConversion1' */
    real32_T sIqe;                     /* '<S22>/SignalConversion2' */
    real32_T sAppTheta;                /* '<S22>/SignalConversion3' */
    real32_T sIds;                     /* '<S31>/Gain1' */
    real32_T mCTRL_sIfTheta_daj2;      /* '<S31>/mCTRL_sIfTheta' */
    real32_T sIqs;                     /* '<S31>/Gain2' */
    real32_T sIde_esgf;                /* '<S31>/Sum2' */
    real32_T sIqe_nbmc;                /* '<S31>/Sum3' */
    real32_T sIfCurr;                  /* '<S31>/sIfCurr' */
    real32_T sIds_gxrm;                /* '<S18>/Gain1' */
    real32_T sIdqCosTheta;             /* '<S18>/TrigonometricFunction1' */
    real32_T sIqs_pe32;                /* '<S18>/Gain2' */
    real32_T sIdqSinTheta;             /* '<S18>/TrigonometricFunction' */
    real32_T sSpdRef;                  /* '<S37>/Merge1' */
    real32_T sSpdRefPstMde;            /* '<S40>/Saturation1' */
    real32_T sSpdRefLimited;           /* '<S48>/Switch1' */
    real32_T sSpdCtrlMdeTqRefLimited;  /* '<S46>/Saturation1' */
    real32_T sIqeIntegLimited;         /* '<S35>/Saturation1' */
    real32_T sIqKpErr;                 /* '<S35>/Product2' */
    real32_T sIqFFRlt;                 /* '<S35>/Add4' */
    real32_T sVqeRef;                  /* '<S35>/Saturation' */
    real32_T sIdeIntegLimited;         /* '<S34>/Saturation1' */
    real32_T sIdKpErr;                 /* '<S34>/Product1' */
    real32_T sIdFFRlt;                 /* '<S34>/Product6' */
    real32_T sVdeRef;                  /* '<S34>/Saturation' */
    real32_T sTheta;                   /* '<S24>/SignalConversion4' */
    real32_T sIFreqBetaCmd;            /* '<S26>/Chart_CalIsBeta2IdqRef' */
    real32_T sVVqeRef;                 /* '<S12>/Switch2' */
    real32_T sVfThetaRef;              /* '<S15>/Chart_MtrCtrlMdeVFCtrl' */
    real32_T sVfVqeRef;                /* '<S14>/Switch2' */
    real32_T TqRefLimited;             /* '<S37>/Merge' */
    real32_T sIfThetaZ;                /* '<S32>/UnitDelay' */
    real32_T sIsRefIn2;                /* '<S50>/UnitDelay_sIsRefIn' */
    real32_T Delay1_DSTATE;            /* '<S40>/Delay1' */
    real32_T sTqRef_IntegZ;            /* '<S40>/UnitDelay1' */
    real32_T Delay_DSTATE_fsbd;        /* '<S49>/Delay' */
    real32_T sSpdAntiValZ;             /* '<S46>/UnitDelay' */
    real32_T sTqRef_IntegZ_czro;       /* '<S46>/UnitDelay1' */
    real32_T sIqeIntegZ;               /* '<S35>/UnitDelay' */
    real32_T sIdeIntegZ;               /* '<S34>/UnitDelay' */
    real32_T sIsRefIn2_cw5o;           /* '<S29>/UnitDelay_sIsRefIn' */
    real32_T sVqeRefZ_V;               /* '<S12>/UnitDelay1' */
    real32_T sVqeRefZ_VF;              /* '<S14>/UnitDelay1' */
    real32_T sLpfLowZ;                 /* '<S11>/sLpfLowZ' */
    real32_T sLpfNowZ;                 /* '<S11>/sLpfNowZ' */
    real32_T sLpfLowZ_nuzg;            /* '<S10>/sLpfLowZ' */
    real32_T sLpfNowZ_m0tm;            /* '<S10>/sLpfNowZ' */
    uint16_T uAppCtrlMde;              /* '<S8>/Chart' */
}
StrE03DW;

/* External inputs (root inport signals with default storage) */
typedef struct
{
    real32_T bC01MADC_mMsens_sAbsIa;   /* '<Root>/bC01MADC_mMsens_sAbsIa' */
    real32_T bC01MADC_mMsens_sAbsIb;   /* '<Root>/bC01MADC_mMsens_sAbsIb' */
    real32_T bC01MADC_mMsens_sAbsIc;   /* '<Root>/bC01MADC_mMsens_sAbsIc' */
    real32_T bC01MADC_mMsens_sInvHVdcLow;
                                      /* '<Root>/bC01MADC_mMsens_sInvHVdcLow' */
    int32_T bB01SCHED_mSched_i32CntForVarGa;
                                /* '<Root>/bB01SCHED_mSched_i32CntForVarGain' */
    real32_T bBSWGVAL_mBSW_sFreq;      /* '<Root>/bBSWGVAL_mBSW_sFreq' */
    uint16_T bBSWGVAL_mBSW_uExinputAll;/* '<Root>/bBSWGVAL_mBSW_uExinputAll' */
    uint16_T bBSWGVAL_mBSW_a11uReadInput[11];
                                      /* '<Root>/bBSWGVAL_mBSW_a11uReadInput' */
    uint16_T bBSWGVAL_mBSW_uEstpSwitchDtc;
                                     /* '<Root>/bBSWGVAL_mBSW_uEstpSwitchDtc' */
    uint16_T bBSWGVAL_mBSW_uGateFltDtc;/* '<Root>/bBSWGVAL_mBSW_uGateFltDtc' */
    uint16_T bBSWGVAL_mBSW_uInitNvRam; /* '<Root>/bBSWGVAL_mBSW_uInitNvRam' */
    uint16_T bBSWGVAL_mI2c_uFlagSaveEncOrigi;
                                 /* '<Root>/bBSWGVAL_mI2c_uFlagSaveEncOrigin' */
    uint16_T bBSWGVAL_mI2c_uFlagResetEnc;
                                      /* '<Root>/bBSWGVAL_mI2c_uFlagResetEnc' */
    uint16_T bBSWGVAL_mEnc_uCF;        /* '<Root>/bBSWGVAL_mEnc_uCF' */
    uint16_T bBSWGVAL_mEnc_uSF;        /* '<Root>/bBSWGVAL_mEnc_uSF' */
    uint16_T bBSWGVAL_mEnc_uEND;       /* '<Root>/bBSWGVAL_mEnc_uEND' */
    uint16_T bBSWGVAL_mEnc_uALMC;      /* '<Root>/bBSWGVAL_mEnc_uALMC' */
    uint16_T bBSWGVAL_mEnc_uCRC;       /* '<Root>/bBSWGVAL_mEnc_uCRC' */
    uint16_T bBSWGVAL_mEnc_uABS0;      /* '<Root>/bBSWGVAL_mEnc_uABS0' */
    uint16_T bBSWGVAL_mEnc_uABS1;      /* '<Root>/bBSWGVAL_mEnc_uABS1' */
    uint16_T bBSWGVAL_mEnc_uABS2;      /* '<Root>/bBSWGVAL_mEnc_uABS2' */
    uint16_T bBSWGVAL_mEnc_uABM0;      /* '<Root>/bBSWGVAL_mEnc_uABM0' */
    uint16_T bBSWGVAL_mEnc_uABM1;      /* '<Root>/bBSWGVAL_mEnc_uABM1' */
    uint16_T bBSWGVAL_mEnc_uABM2;      /* '<Root>/bBSWGVAL_mEnc_uABM2' */
    real32_T bE01MCVG_mMCVG_sSCG_Apst; /* '<Root>/bE01MCVG_mMCVG_sSCG_Apst' */
    real32_T bE01MCVG_mMCVG_sCCG_Kad;  /* '<Root>/bE01MCVG_mMCVG_sCCG_Kad' */
    real32_T bE01MCVG_mMCVG_sCCG_Kaq;  /* '<Root>/bE01MCVG_mMCVG_sCCG_Kaq' */
    uint32_T bD01DIAG_mDIAG_u32FltAll; /* '<Root>/bD01DIAG_mDIAG_u32FltAll' */
    uint16_T bD01DIAG_mDIAG_uChprOpr1On0Off;
                                   /* '<Root>/bD01DIAG_mDIAG_uChprOpr1On0Off' */
    uint16_T bD01DIAG_mDIAG_uFan1On0Off;/* '<Root>/bD01DIAG_mDIAG_uFan1On0Off' */
    uint16_T bD01DIAG_mDIAG_uCntCrtOvr;/* '<Root>/bD01DIAG_mDIAG_uCntCrtOvr' */
    uint32_T bD01DIAG_sF01_T01_EstopSwitchFl;
                                 /* '<Root>/bD01DIAG_sF01_T01_EstopSwitchFlt' */
    uint32_T bD01DIAG_sF02_T01_IgptShrtFlt;
                                    /* '<Root>/bD01DIAG_sF02_T01_IgptShrtFlt' */
    uint32_T bD01DIAG_sF03_T01_HvdcOvrVolFlt;
                                  /* '<Root>/bD01DIAG_sF03_T01_HvdcOvrVolFlt' */
    uint32_T bD01DIAG_sF04_T01_HvdcUdrVolFlt;
                                  /* '<Root>/bD01DIAG_sF04_T01_HvdcUdrVolFlt' */
    uint32_T bD01DIAG_sF05_T30_CrtSnsrFlt;
                                     /* '<Root>/bD01DIAG_sF05_T30_CrtSnsrFlt' */
    uint32_T bD01DIAG_sF06_T30_CrtSnsrOfsFlt;
                                  /* '<Root>/bD01DIAG_sF06_T30_CrtSnsrOfsFlt' */
    uint32_T bD01DIAG_sF07_T30_CrtStallFlt;
                                    /* '<Root>/bD01DIAG_sF07_T30_CrtStallFlt' */
    uint32_T bD01DIAG_sF08_T01_CrtOvrFlt;
                                      /* '<Root>/bD01DIAG_sF08_T01_CrtOvrFlt' */
    uint32_T bD01DIAG_sF09_T30_IvtTempSnsrFl;
                                 /* '<Root>/bD01DIAG_sF09_T30_IvtTempSnsrFlt' */
    uint32_T bD01DIAG_sF10_T30_IvtTempOvrFlt;
                                  /* '<Root>/bD01DIAG_sF10_T30_IvtTempOvrFlt' */
    uint32_T bD01DIAG_sF11_T30_MtrTempSnsrFl;
                                 /* '<Root>/bD01DIAG_sF11_T30_MtrTempSnsrFlt' */
    uint32_T bD01DIAG_sF12_T30_MtrTempOvrFlt;
                                  /* '<Root>/bD01DIAG_sF12_T30_MtrTempOvrFlt' */
    uint32_T bD01DIAG_sF13_T10_MtrSpdFlt;
                                      /* '<Root>/bD01DIAG_sF13_T10_MtrSpdFlt' */
    uint32_T bD01DIAG_sF16_T10_InitNvRam;
                                      /* '<Root>/bD01DIAG_sF16_T10_InitNvRam' */
    uint16_T bF01CRX1_mCRX_uAllowingOperatio;
                                 /* '<Root>/bF01CRX1_mCRX_uAllowingOperation' */
    uint16_T bF01CRX1_mCRX_uCtrlMde0Digt1Can;
                                  /* '<Root>/bF01CRX1_mCRX_uCtrlMde0Digt1Can' */
    uint16_T bF01CRX1_mCRX_uMtrCtrlMde;/* '<Root>/bF01CRX1_mCRX_uMtrCtrlMde' */
    uint16_T bF01CRX1_mCRX_uSvOn;      /* '<Root>/bF01CRX1_mCRX_uSvOn' */
    uint16_T bF01CRX1_mCRX_uStart;     /* '<Root>/bF01CRX1_mCRX_uStart' */
    uint16_T bF01CRX1_mCRX_uEmg;       /* '<Root>/bF01CRX1_mCRX_uEmg' */
    uint16_T bF01CRX1_mCRX_uAlarmRst;  /* '<Root>/bF01CRX1_mCRX_uAlarmRst' */
    uint16_T bF01CRX1_mCRX_uRefPst;    /* '<Root>/bF01CRX1_mCRX_uRefPst' */
    uint16_T bF01CRX1_mCRX_uStop;      /* '<Root>/bF01CRX1_mCRX_uStop' */
    uint16_T bF01CRX1_mCRX_uOrgin;     /* '<Root>/bF01CRX1_mCRX_uOrgin' */
    uint16_T bF01CRX1_mCRX_uDogin;     /* '<Root>/bF01CRX1_mCRX_uDogin' */
    uint16_T bF01CRX1_mCRX_uPJog;      /* '<Root>/bF01CRX1_mCRX_uPJog' */
    uint16_T bF01CRX1_mCRX_uNJog;      /* '<Root>/bF01CRX1_mCRX_uNJog' */
    uint16_T bF01CRX1_mCRX_uEnMpg;     /* '<Root>/bF01CRX1_mCRX_uEnMpg' */
    real32_T bF01CRX1_mCRX_sSpdCmd;    /* '<Root>/bF01CRX1_mCRX_sSpdCmd' */
    uint16_T bF01CRX1_mCRX_uDaCase;    /* '<Root>/bF01CRX1_mCRX_uDaCase' */
    real32_T bE02MCEST_mMTPST_sRpm;    /* '<Root>/bE02MCEST_mMTPST_sRpm' */
    uint32_T bE02MCEST_mMTPST_u32EncMultiTur;
                                 /* '<Root>/bE02MCEST_mMTPST_u32EncMultiTurn' */
    real32_T bE02MCEST_mMTPST_sIds;    /* '<Root>/bE02MCEST_mMTPST_sIds' */
    real32_T bE02MCEST_mMTPST_sIqs;    /* '<Root>/bE02MCEST_mMTPST_sIqs' */
    real32_T bH01SMDE_mSMDE_sSpdLimit; /* '<Root>/bH01SMDE_mSMDE_sSpdLimit' */
    real32_T bH01SMDE_mSMDE_sPstRef;   /* '<Root>/bH01SMDE_mSMDE_sPstRef' */
    uint16_T bH01SMDE_mSMDE_uOprState; /* '<Root>/bH01SMDE_mSMDE_uOprState' */
    uint16_T bH01SMDE_mSMDE_uFlagSaveEncOrig;
                                /* '<Root>/bH01SMDE_mSMDE_uFlagSaveEncOrigin' */
    uint16_T bH01SMDE_mSMDE_uFlagResetEnc;
                                     /* '<Root>/bH01SMDE_mSMDE_uFlagResetEnc' */
    int64_T bH01SMDE_mSMDE_i64PstOrigin;
                                      /* '<Root>/bH01SMDE_mSMDE_i64PstOrigin' */
    real32_T bH01SMDE_mSMDE_sRefAngle; /* '<Root>/bH01SMDE_mSMDE_sRefAngle' */
    real32_T bH01SMDE_mSMDE_sActAngle; /* '<Root>/bH01SMDE_mSMDE_sActAngle' */
    real32_T bH01SMDE_mSMDE_sAngleErr; /* '<Root>/bH01SMDE_mSMDE_sAngleErr' */
    uint16_T bH01SMDE_mSMDE_uExOut_uAlarm;
                                     /* '<Root>/bH01SMDE_mSMDE_uExOut_uAlarm' */
    uint16_T bH01SMDE_mSMDE_uExOut_uStadby;
                                    /* '<Root>/bH01SMDE_mSMDE_uExOut_uStadby' */
    uint16_T bH01SMDE_mSMDE_uExOut_uBrake;
                                     /* '<Root>/bH01SMDE_mSMDE_uExOut_uBrake' */
    uint16_T bH01SMDE_mSMDE_uExOut_uOrgOut;
                                    /* '<Root>/bH01SMDE_mSMDE_uExOut_uOrgOut' */
    uint16_T bH01SMDE_mSMDE_uExOut_uInPst;
                                     /* '<Root>/bH01SMDE_mSMDE_uExOut_uInPst' */
    uint16_T bH01SMDE_mSMDE_uExOut_uFltCode;
                                   /* '<Root>/bH01SMDE_mSMDE_uExOut_uFltCode' */
    uint16_T bH01SMDE_mSMDE_uExOut_uActPst;
                                    /* '<Root>/bH01SMDE_mSMDE_uExOut_uActPst' */
    uint16_T bH01SMDE_mSMDE_uExOut_uOrgNotDe;
                                 /* '<Root>/bH01SMDE_mSMDE_uExOut_uOrgNotDef' */
}
StrE03ExtU;

/* Block signals and states (default storage) */
extern StrE03DW GvE03DW;

/* External inputs (root inport signals with default storage) */
extern StrE03ExtU GvE03U;

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
 * '<S31>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Ftn_MtrMdeCmIFCtrl/Ftn_MtrMdeCmIFCtrlB'
 * '<S32>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Ftn_MtrMdeCmIFCtrl/Nftn_MtrMdeCmIFCtrlA'
 * '<S33>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Ftn_MtrMdeCmIFCtrl/Nftn_MtrMdeCmIFCtrlA/Chart'
 * '<S34>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_CurrCtrl/Ftn_IdControl'
 * '<S35>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_CurrCtrl/Ftn_IqControl'
 * '<S36>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_CurrCtrl/Nftn_GenMuxVdqeRef'
 * '<S37>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_MtrMdeCmSpdCm/Ftn_TqSpdPstCtrl'
 * '<S38>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_MtrMdeCmSpdCm/Ftn_TqSpdPstCtrl/Ftn_MtrMdeCmSpSpdCtrl'
 * '<S39>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_MtrMdeCmSpdCm/Ftn_TqSpdPstCtrl/Ftn_MtrMdeCmTqOut'
 * '<S40>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_MtrMdeCmSpdCm/Ftn_TqSpdPstCtrl/Ftn_PstCtrl'
 * '<S41>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_MtrMdeCmSpdCm/Ftn_TqSpdPstCtrl/Nftn_MtrMdeCmSpdCmTqCtrl'
 * '<S42>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_MtrMdeCmSpdCm/Ftn_TqSpdPstCtrl/Subsystem'
 * '<S43>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_MtrMdeCmSpdCm/Ftn_TqSpdPstCtrl/Subsystem3'
 * '<S44>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_MtrMdeCmSpdCm/Ftn_TqSpdPstCtrl/Subsystem4'
 * '<S45>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_MtrMdeCmSpdCm/Ftn_TqSpdPstCtrl/Ftn_MtrMdeCmSpSpdCtrl/Ftn_SoftSpdMde'
 * '<S46>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_MtrMdeCmSpdCm/Ftn_TqSpdPstCtrl/Ftn_MtrMdeCmSpSpdCtrl/Ftn_SpdCtrl'
 * '<S47>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_MtrMdeCmSpdCm/Ftn_TqSpdPstCtrl/Ftn_MtrMdeCmSpSpdCtrl/Subsystem'
 * '<S48>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_MtrMdeCmSpdCm/Ftn_TqSpdPstCtrl/Ftn_MtrMdeCmSpSpdCtrl/Ftn_SoftSpdMde/Nftn_GensAppIeSpdRefLim'
 * '<S49>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_MtrMdeCmSpdCm/Ftn_TqSpdPstCtrl/Ftn_MtrMdeCmSpSpdCtrl/Ftn_SoftSpdMde/Nftn_SftMdeSpdStart'
 * '<S50>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_MtrMdeCmSpdCm/Ftn_TqSpdPstCtrl/Nftn_MtrMdeCmSpdCmTqCtrl/Nftn_SftMdeTqRef'
 * '<S51>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_MtrMdeComn/Nftn_MtrMdeCmSpdCm/Ftn_TqSpdPstCtrl/Nftn_MtrMdeCmSpdCmTqCtrl/Nftn_TqLimit'
 * '<S52>'  : 'e03_MtrCtrl_MtrCtrl/Nftn_MotorControl/Ftn_SelectionCtrlMde/Chart'
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
