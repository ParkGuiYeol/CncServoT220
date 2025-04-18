/*
 * File: g03_CommTx.h
 *
 * Code generated for Simulink model 'g03_CommTx'.
 *
 * Model version                  : 7.357
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Mar 29 20:36:57 2025
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

#ifndef g03_CommTx_h_
#define g03_CommTx_h_
#ifndef g03_CommTx_COMMON_INCLUDES_
#define g03_CommTx_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* g03_CommTx_COMMON_INCLUDES_ */

#include <string.h>

/* Includes for objects with custom storage classes */
#include "M2_Interrupt.h"
#include "e03_MtrCtrl_MtrCtrl.h"
#include "d01_Diaglnteg.h"
#include "e02_MtrCtrl_Pst.h"
#include "c01_MainAdc.h"
#include "h01_MdeMgmt.h"
#include "c02_SubAdc.h"
#ifndef DEFINED_TYPEDEF_FOR_S_CTX3_
#define DEFINED_TYPEDEF_FOR_S_CTX3_

typedef struct
{
    real32_T a6sInvFactorTx1[6];
    uint32_T a6u32StartBitTx1[6];
    real32_T a6sOffsetTx1[6];
    real32_T a6sMinTx1[6];
    real32_T a6sMaxTx1[6];
    uint32_T a6sClearBitTx1[6];
    int32_T i32CntMaxForTx3;
    uint16_T uSW_REV;
    uint16_T uDummy;
}
S_CTX3;

#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct
{
    int32_T i32inxTx3;                 /* '<S1>/Chart_CntForTx2' */
    uint32_T u32DataLowTx2;            /* '<S1>/Nftn_CommDataParsingTx2' */
    uint32_T u32DataHighTx2;           /* '<S1>/Nftn_CommDataParsingTx2' */
}
StrG03DW;

/* External inputs (root inport signals with default storage) */
typedef struct
{
    uint16_T bH01SMDE_mSMDE_uFlagInverterOut;
                                  /* '<Root>/bH01SMDE_mSMDE_uFlagInverterOut' */
    real32_T bH01SMDE_mSMDE_sSpdRefInSeqOut;
                                   /* '<Root>/bH01SMDE_mSMDE_sSpdRefInSeqOut' */
    real32_T bH01SMDE_mSMDE_sSpdRef;   /* '<Root>/bH01SMDE_mSMDE_sSpdRef' */
    real32_T bH01SMDE_mSMDE_sIfFreqSeqOut;
                                     /* '<Root>/bH01SMDE_mSMDE_sIfFreqSeqOut' */
    uint16_T bH01SMDE_mSMDE_uMtrCtrlMde;/* '<Root>/bH01SMDE_mSMDE_uMtrCtrlMde' */
    uint16_T bH01SMDE_mSMDE_uFlagSaveEncOrig;
                                /* '<Root>/bH01SMDE_mSMDE_uFlagSaveEncOrigin' */
    uint16_T bH01SMDE_mSMDE_uFlagResetEnc;
                                     /* '<Root>/bH01SMDE_mSMDE_uFlagResetEnc' */
    int64_T bH01SMDE_mSMDE_i64PstOrigin;
                                      /* '<Root>/bH01SMDE_mSMDE_i64PstOrigin' */
    int64_T bH01SMDE_mSMDE_i64PstRef;  /* '<Root>/bH01SMDE_mSMDE_i64PstRef' */
    uint16_T bD01DIAG_mDIAG_uFltStat;  /* '<Root>/bD01DIAG_mDIAG_uFltStat' */
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
    real32_T bC01MADC_mMsens_sIa;      /* '<Root>/bC01MADC_mMsens_sIa' */
    real32_T bC01MADC_mMsens_sIb;      /* '<Root>/bC01MADC_mMsens_sIb' */
    real32_T bC01MADC_mMsens_sIc;      /* '<Root>/bC01MADC_mMsens_sIc' */
    real32_T bC01MADC_mMsens_sAbsIa;   /* '<Root>/bC01MADC_mMsens_sAbsIa' */
    real32_T bC01MADC_mMsens_sAbsIb;   /* '<Root>/bC01MADC_mMsens_sAbsIb' */
    real32_T bC01MADC_mMsens_sAbsIc;   /* '<Root>/bC01MADC_mMsens_sAbsIc' */
    real32_T bC01MADC_mMsens_sInvHVdcLow;
                                      /* '<Root>/bC01MADC_mMsens_sInvHVdcLow' */
    real32_T bE03MCTRL_mCTRL_sIdeRef;  /* '<Root>/bE03MCTRL_mCTRL_sIdeRef' */
    real32_T bE03MCTRL_mCTRL_sIqeRef;  /* '<Root>/bE03MCTRL_mCTRL_sIqeRef' */
    real32_T bE03MCTRL_mCTRL_sIde;     /* '<Root>/bE03MCTRL_mCTRL_sIde' */
    real32_T bE03MCTRL_mCTRL_sIqe;     /* '<Root>/bE03MCTRL_mCTRL_sIqe' */
    real32_T bE03MCTRL_mCTRL_sIfTheta; /* '<Root>/bE03MCTRL_mCTRL_sIfTheta' */
    real32_T bE03MCTRL_mCTRL_sIfFreq;  /* '<Root>/bE03MCTRL_mCTRL_sIfFreq' */
    real32_T bE03MCTRL_mCTRL_sSpdRefIn;/* '<Root>/bE03MCTRL_mCTRL_sSpdRefIn' */
    real32_T bE03MCTRL_mCTRL_sVdeRefLow;/* '<Root>/bE03MCTRL_mCTRL_sVdeRefLow' */
    real32_T bE03MCTRL_mCTRL_sVqeRefLow;/* '<Root>/bE03MCTRL_mCTRL_sVqeRefLow' */
    real32_T bE03MCTRL_mCTRL_sVdeRef;  /* '<Root>/bE03MCTRL_mCTRL_sVdeRef' */
    real32_T bE03MCTRL_mCTRL_sVqeRef;  /* '<Root>/bE03MCTRL_mCTRL_sVqeRef' */
    real32_T bE03MCTRL_mCTRL_sThetaCtrl;/* '<Root>/bE03MCTRL_mCTRL_sThetaCtrl' */
    real32_T bE02MTPST_mMTPST_sWm;     /* '<Root>/bE02MTPST_mMTPST_sWm' */
    real32_T bE02MTPST_mMTPST_sWe;     /* '<Root>/bE02MTPST_mMTPST_sWe' */
    real32_T bE02MTPST_mMTPST_sTheta;  /* '<Root>/bE02MTPST_mMTPST_sTheta' */
    uint32_T bE02MTPST_mMTPST_u32EncMultiTur;
                                 /* '<Root>/bE02MTPST_mMTPST_u32EncMultiTurn' */
    int64_T bE02MTPST_mMTPST_i64TurretPst;
                                    /* '<Root>/bE02MTPST_mMTPST_i64TurretPst' */
    real32_T bE02MTPST_mMTPST_sIde;    /* '<Root>/bE02MTPST_mMTPST_sIde' */
    real32_T bE02MTPST_mMTPST_sIqe;    /* '<Root>/bE02MTPST_mMTPST_sIqe' */
    real32_T bE02MTPST_mMTPST_sIds;    /* '<Root>/bE02MTPST_mMTPST_sIds' */
    real32_T bE02MTPST_mMTPST_sIqs;    /* '<Root>/bE02MTPST_mMTPST_sIqs' */
    real32_T bBSWGVAL_mBSW_sTime;      /* '<Root>/bBSWGVAL_mBSW_sTime' */
    real32_T bBSWGVAL_mBSW_sTime2;     /* '<Root>/bBSWGVAL_mBSW_sTime2' */
    real32_T bBSWGVAL_mBSW_sOutloopTime;/* '<Root>/bBSWGVAL_mBSW_sOutloopTime' */
    real32_T bBSWGVAL_mBSW_sFreq;      /* '<Root>/bBSWGVAL_mBSW_sFreq' */
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
}
StrG03ExtU;

/* Block signals and states (default storage) */
extern StrG03DW GvG03DW;

/* External inputs (root inport signals with default storage) */
extern StrG03ExtU GvG03U;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern uint32_T mCTX_u32DataLowTx1;    /* '<Root>/bG03CTX_mCTX_u32DataLowTx1' */
extern uint32_T mCTX_u32DataHighTx1;  /* '<Root>/bG03CTX_mCTX_u32DataHighTx1' */
extern uint32_T mCTX_u32DataLowTx2;    /* '<Root>/bG03CTX_mCTX_u32DataLowTx2' */
extern uint32_T mCTX_u32DataHighTx2;  /* '<Root>/bG03CTX_mCTX_u32DataHighTx2' */

/* Model entry point functions */
extern void g03_CommTx_initialize(void);
extern void g03_CommTx_step(void);

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
 * '<Root>' : 'g03_CommTx'
 * '<S1>'   : 'g03_CommTx/Ftn_CommDataParsingTx1'
 * '<S2>'   : 'g03_CommTx/Ftn_CommDataParsingTx2'
 * '<S3>'   : 'g03_CommTx/Ftn_CommDataParsingTx1/Chart_CntForTx2'
 * '<S4>'   : 'g03_CommTx/Ftn_CommDataParsingTx1/Nftn_CommDataParsingTx2'
 * '<S5>'   : 'g03_CommTx/Ftn_CommDataParsingTx2/BitShift'
 * '<S6>'   : 'g03_CommTx/Ftn_CommDataParsingTx2/BitShift1'
 * '<S7>'   : 'g03_CommTx/Ftn_CommDataParsingTx2/BitShift2'
 * '<S8>'   : 'g03_CommTx/Ftn_CommDataParsingTx2/BitShift/bit_shift'
 * '<S9>'   : 'g03_CommTx/Ftn_CommDataParsingTx2/BitShift1/bit_shift'
 * '<S10>'  : 'g03_CommTx/Ftn_CommDataParsingTx2/BitShift2/bit_shift'
 */

/*-
 * Requirements for '<Root>': g03_CommTx

 */
#endif                                 /* g03_CommTx_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
