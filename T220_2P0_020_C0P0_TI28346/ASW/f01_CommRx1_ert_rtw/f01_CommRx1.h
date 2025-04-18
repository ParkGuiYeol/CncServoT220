/*
 * File: f01_CommRx1.h
 *
 * Code generated for Simulink model 'f01_CommRx1'.
 *
 * Model version                  : 7.308
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Mar 29 20:36:42 2025
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

#ifndef f01_CommRx1_h_
#define f01_CommRx1_h_
#ifndef f01_CommRx1_COMMON_INCLUDES_
#define f01_CommRx1_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* f01_CommRx1_COMMON_INCLUDES_ */

#include <string.h>

/* Includes for objects with custom storage classes */
#include "b01_OSnScheduler.h"
#include "D01_DRV_CAN.h"

/* user code (top of header file) */
#include "Define_Header.h"
#ifndef DEFINED_TYPEDEF_FOR_S_CRX1_
#define DEFINED_TYPEDEF_FOR_S_CRX1_

typedef struct
{
    uint32_T a18u32StartBit[18];
    uint32_T a18u32Length[18];
    real32_T a18sFactor[18];
    real32_T a18sOffset[18];
    uint32_T a18sClearBitRx1[18];
    uint32_T u32HalfBit;
    int32_T i32CntMaxForRx1;
    uint16_T uDummy;
}
S_CRX1;

#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct
{
    real32_T sParsRlt1[18];            /* '<S1>/Nftn_CommDataParsing' */
    int32_T inx;                       /* '<S1>/Chart_CntForRx1' */
}
StrF01DW;

/* External inputs (root inport signals with default storage) */
typedef struct
{
    real32_T bBSWGVAL_mBSW_sTime;      /* '<Root>/bBSWGVAL_mBSW_sTime' */
    real32_T bBSWGVAL_mBSW_sTime2;     /* '<Root>/bBSWGVAL_mBSW_sTime2' */
    real32_T bBSWGVAL_mBSW_sOutloopTime;/* '<Root>/bBSWGVAL_mBSW_sOutloopTime' */
    real32_T bBSWGVAL_mBSW_sFreq;      /* '<Root>/bBSWGVAL_mBSW_sFreq' */
    uint16_T bBSWGVAL_mBSW_uExinputAll;/* '<Root>/bBSWGVAL_mBSW_uExinputAll' */
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
StrF01ExtU;

/* Block signals and states (default storage) */
extern StrF01DW GvF01DW;

/* External inputs (root inport signals with default storage) */
extern StrF01ExtU GvF01U;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern uint16_T mCRX_uAllowingOperation;
                                 /* '<Root>/bF01CRX1_mCRX_uAllowingOperation' */
extern uint16_T mCRX_uCtrlMde0Digt1Can;
                                  /* '<Root>/bF01CRX1_mCRX_uCtrlMde0Digt1Can' */
extern uint16_T mCRX_uMtrCtrlMde;      /* '<Root>/bF01CRX1_mCRX_uMtrCtrlMde' */
extern real32_T mCRX_sVltCurrTqCmd;   /* '<Root>/bF01CRX1_mCRX_sVltCurrTqCmd' */
extern real32_T mCRX_sFreqBetaCmd;     /* '<Root>/bF01CRX1_mCRX_sFreqBetaCmd' */
extern uint16_T mCRX_uSvOn;            /* '<Root>/bF01CRX1_mCRX_uSvOn' */
extern uint16_T mCRX_uStart;           /* '<Root>/bF01CRX1_mCRX_uStart' */
extern uint16_T mCRX_uEmg;             /* '<Root>/bF01CRX1_mCRX_uEmg' */
extern uint16_T mCRX_uAlarmRst;        /* '<Root>/bF01CRX1_mCRX_uAlarmRst' */
extern uint16_T mCRX_uRefPst;          /* '<Root>/bF01CRX1_mCRX_uRefPst' */
extern uint16_T mCRX_uStop;            /* '<Root>/bF01CRX1_mCRX_uStop' */
extern uint16_T mCRX_uOrgin;           /* '<Root>/bF01CRX1_mCRX_uOrgin' */
extern uint16_T mCRX_uDogin;           /* '<Root>/bF01CRX1_mCRX_uDogin' */
extern uint16_T mCRX_uPJog;            /* '<Root>/bF01CRX1_mCRX_uPJog' */
extern uint16_T mCRX_uNJog;            /* '<Root>/bF01CRX1_mCRX_uNJog' */
extern uint16_T mCRX_uEnMpg;           /* '<Root>/bF01CRX1_mCRX_uEnMpg' */
extern real32_T mCRX_sSpdCmd;          /* '<Root>/bF01CRX1_mCRX_sSpdCmd' */
extern uint16_T mCRX_uDaCase;          /* '<Root>/bF01CRX1_mCRX_uDaCase' */

/* Model entry point functions */
extern void f01_CommRx1_initialize(void);
extern void f01_CommRx1_step(void);

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
 * '<Root>' : 'f01_CommRx1'
 * '<S1>'   : 'f01_CommRx1/Ftn_Rx1Deparsing'
 * '<S2>'   : 'f01_CommRx1/Ftn_Rx1Deparsing/Chart_CntForRx1'
 * '<S3>'   : 'f01_CommRx1/Ftn_Rx1Deparsing/Nftn_CommDataParsing'
 */

/*-
 * Requirements for '<Root>': f01_CommRx1

 */
#endif                                 /* f01_CommRx1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
