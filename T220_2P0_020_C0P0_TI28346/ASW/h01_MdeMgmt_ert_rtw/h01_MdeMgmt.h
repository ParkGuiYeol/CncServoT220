/*
 * File: h01_MdeMgmt.h
 *
 * Code generated for Simulink model 'h01_MdeMgmt'.
 *
 * Model version                  : 3.394
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Mar 29 20:43:24 2025
 * Created by: System Research Team
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. Execution efficiency
 *    3. RAM efficiency
 *    4. ROM efficiency
 * Validation result: Not run
 */

#ifndef h01_MdeMgmt_h_
#define h01_MdeMgmt_h_
#ifndef h01_MdeMgmt_COMMON_INCLUDES_
#define h01_MdeMgmt_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* h01_MdeMgmt_COMMON_INCLUDES_ */

#include <string.h>

/* Includes for objects with custom storage classes */
#include "D01_DRV_CAN.h"
#include "f01_CommRx1.h"
#include "e03_MtrCtrl_MtrCtrl.h"
#include "D02_DRV_I2C.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct
{
    uint16_T uFlagResetEncZ;           /* '<S1>/Chart_StateManagement' */
    uint16_T uFlagSaveEncOriginZ;      /* '<S1>/Chart_StateManagement' */
    uint8_T is_active_c3_h01_MdeMgmt;  /* '<S1>/Chart_StateManagement' */
    uint8_T is_c3_h01_MdeMgmt;         /* '<S1>/Chart_StateManagement' */
}
StrH01DW;

/* External inputs (root inport signals with default storage) */
typedef struct
{
    uint32_T bCOMRX_mCRX1_u32CrrDataLow;/* '<Root>/bCOMRX_mCRX1_u32CrrDataLow' */
    uint32_T bCOMRX_mCRX1_u32CrrDataHigh;
                                      /* '<Root>/bCOMRX_mCRX1_u32CrrDataHigh' */
    uint16_T bF01CRX1_mCRX_uCtrlMde0Digt1Can;
                                  /* '<Root>/bF01CRX1_mCRX_uCtrlMde0Digt1Can' */
    real32_T bF01CRX1_mCRX_sVltCurrTqCmd;
                                      /* '<Root>/bF01CRX1_mCRX_sVltCurrTqCmd' */
    real32_T bF01CRX1_mCRX_sFreqBetaCmd;/* '<Root>/bF01CRX1_mCRX_sFreqBetaCmd' */
    uint16_T bF01CRX1_mCRX_uSvOn;      /* '<Root>/bF01CRX1_mCRX_uSvOn' */
    uint16_T bF01CRX1_mCRX_uStart;     /* '<Root>/bF01CRX1_mCRX_uStart' */
    uint16_T bF01CRX1_mCRX_uEmg;       /* '<Root>/bF01CRX1_mCRX_uEmg' */
    uint16_T bF01CRX1_mCRX_uAlarmRst;  /* '<Root>/bF01CRX1_mCRX_uAlarmRst' */
    uint16_T bF01CRX1_mCRX_uRefPst;    /* '<Root>/bF01CRX1_mCRX_uRefPst' */
    uint16_T bF01CRX1_mCRX_uStop;      /* '<Root>/bF01CRX1_mCRX_uStop' */
    uint16_T bF01CRX1_mCRX_uPJog;      /* '<Root>/bF01CRX1_mCRX_uPJog' */
    uint16_T bF01CRX1_mCRX_uNJog;      /* '<Root>/bF01CRX1_mCRX_uNJog' */
    uint16_T bF01CRX1_mCRX_uEnMpg;     /* '<Root>/bF01CRX1_mCRX_uEnMpg' */
    uint16_T bF01CRX1_mCRX_uDaCase;    /* '<Root>/bF01CRX1_mCRX_uDaCase' */
    real32_T bE03MCTRLZ_mCTRL_sIsRef;  /* '<Root>/bE03MCTRLZ_mCTRL_sIsRef' */
    real32_T bE03MCTRLZ_mCTRL_sIdeRef; /* '<Root>/bE03MCTRLZ_mCTRL_sIdeRef' */
    real32_T bE03MCTRLZ_mCTRL_sIqeRef; /* '<Root>/bE03MCTRLZ_mCTRL_sIqeRef' */
    real32_T bE03MCTRLZ_mCTRL_sIde;    /* '<Root>/bE03MCTRLZ_mCTRL_sIde' */
    real32_T bE03MCTRLZ_mCTRL_sIqe;    /* '<Root>/bE03MCTRLZ_mCTRL_sIqe' */
    real32_T bE03MCTRLZ_mCTRL_sIfTheta;/* '<Root>/bE03MCTRLZ_mCTRL_sIfTheta' */
    real32_T bE03MCTRLZ_mCTRL_sTqRefIn;/* '<Root>/bE03MCTRLZ_mCTRL_sTqRefIn' */
    real32_T bE03MCTRLZ_mCTRL_sVdeRefLow;
                                      /* '<Root>/bE03MCTRLZ_mCTRL_sVdeRefLow' */
    real32_T bE03MCTRLZ_mCTRL_sVqeRefLow;
                                      /* '<Root>/bE03MCTRLZ_mCTRL_sVqeRefLow' */
    real32_T bE03MCTRLZ_mCTRL_sVdeRef; /* '<Root>/bE03MCTRLZ_mCTRL_sVdeRef' */
    real32_T bE03MCTRLZ_mCTRL_sVqeRef; /* '<Root>/bE03MCTRLZ_mCTRL_sVqeRef' */
    real32_T bE03MCTRLZ_mCTRL_sThetaCtrl;
                                      /* '<Root>/bE03MCTRLZ_mCTRL_sThetaCtrl' */
    real32_T bBSWGVAL_mBSW_sTime;      /* '<Root>/bBSWGVAL_mBSW_sTime' */
    real32_T bBSWGVAL_mBSW_sTime2;     /* '<Root>/bBSWGVAL_mBSW_sTime2' */
    real32_T bBSWGVAL_mBSW_sOutloopTime;/* '<Root>/bBSWGVAL_mBSW_sOutloopTime' */
    real32_T bBSWGVAL_mBSW_sFreq;      /* '<Root>/bBSWGVAL_mBSW_sFreq' */
    uint16_T bBSWGVAL_mBSW_uExinputAll;/* '<Root>/bBSWGVAL_mBSW_uExinputAll' */
    uint16_T bBSWGVAL_mBSW_a11uReadInput[11];
                                      /* '<Root>/bBSWGVAL_mBSW_a11uReadInput' */
    uint16_T bBSWGVAL_mBSW_uEstpSwitchDtc;
                                     /* '<Root>/bBSWGVAL_mBSW_uEstpSwitchDtc' */
    uint16_T bBSWGVAL_mBSW_uGateFltDtc;/* '<Root>/bBSWGVAL_mBSW_uGateFltDtc' */
    uint16_T bBSWGVAL_mBSW_uInitNvRam; /* '<Root>/bBSWGVAL_mBSW_uInitNvRam' */
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
StrH01ExtU;

/* Block signals and states (default storage) */
extern StrH01DW GvH01DW;

/* External inputs (root inport signals with default storage) */
extern StrH01ExtU GvH01U;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern uint16_T mSMDE_uFlagInverterOut;
                                  /* '<Root>/bH01SMDE_mSMDE_uFlagInverterOut' */
extern real32_T mSMDE_sSpdRefInSeqOut;
                                   /* '<Root>/bH01SMDE_mSMDE_sSpdRefInSeqOut' */
extern real32_T mSMDE_sSpdRef;         /* '<Root>/bH01SMDE_mSMDE_sSpdRef' */
extern real32_T mSMDE_sIfFreqSeqOut; /* '<Root>/bH01SMDE_mSMDE_sIfFreqSeqOut' */
extern uint16_T mSMDE_uMtrCtrlMde;     /* '<Root>/bH01SMDE_mSMDE_uMtrCtrlMde' */
extern uint16_T mSMDE_uOprState;       /* '<Root>/bH01SMDE_mSMDE_uOprState' */
extern uint16_T mSMDE_uFlagSaveEncOrigin;
                                /* '<Root>/bH01SMDE_mSMDE_uFlagSaveEncOrigin' */
extern uint16_T mSMDE_uFlagResetEnc; /* '<Root>/bH01SMDE_mSMDE_uFlagResetEnc' */
extern int64_T mSMDE_i64PstOrigin;    /* '<Root>/bH01SMDE_mSMDE_i64PstOrigin' */
extern int64_T mSMDE_i64PstRef;        /* '<Root>/bH01SMDE_mSMDE_i64PstRef' */
extern uint16_T mSMDE_uExternalOutput;
                                   /* '<Root>/bH01SMDE_mSMDE_uExternalOutput' */

/* Model entry point functions */
extern void h01_MdeMgmt_initialize(void);
extern void h01_MdeMgmt_step(void);

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
 * '<Root>' : 'h01_MdeMgmt'
 * '<S1>'   : 'h01_MdeMgmt/Nftn_StateManagement'
 * '<S2>'   : 'h01_MdeMgmt/Nftn_StateManagement/Chart_StateManagement'
 */

/*-
 * Requirements for '<Root>': h01_MdeMgmt

 */
#endif                                 /* h01_MdeMgmt_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
