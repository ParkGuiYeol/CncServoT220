/*
 * File: h01_MdeMgmt.h
 *
 * Code generated for Simulink model 'h01_MdeMgmt'.
 *
 * Model version                  : 3.570
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Apr 19 17:45:23 2025
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
#include "d01_Diaglnteg.h"
#include "D02_DRV_I2C.h"
#include "e02_MtrCtrl_Pst.h"
#ifndef DEFINED_TYPEDEF_FOR_X_H01EXO_
#define DEFINED_TYPEDEF_FOR_X_H01EXO_

typedef struct
{
    uint16_T uAlarm;
    uint16_T uStadby;
    uint16_T uBrake;
    uint16_T uOrgOut;
    uint16_T uInPst;
    uint16_T uActPst;
    uint16_T uOrgNotDef;
}
X_H01EXO;

#endif

#ifndef DEFINED_TYPEDEF_FOR_S_H01TRT_
#define DEFINED_TYPEDEF_FOR_S_H01TRT_

typedef struct
{
    uint16_T uTurretDirection;
    uint16_T u16NumOfTool;
    real32_T sAnglePerTool;
    real32_T sInvAnglePerTool;
    real32_T sAngleRefMax;
    int64_T i64EncMultiTurnMax;
    int64_T i64EncMultiTurnOffset;
    int64_T i64EncMultiCtrlMax;
    int32_T i32EncMecMaxCnt;
    real32_T sGearRatio;
    real32_T sInvGearRatio;
    int32_T i32BitPerRev;
    real32_T sInvBitPerRev;
    real32_T sAngleTrGain;
    uint16_T uDummy;
}
S_H01TRT;

#endif

#ifndef DEFINED_TYPEDEF_FOR_S_H01MDE_
#define DEFINED_TYPEDEF_FOR_S_H01MDE_

typedef struct
{
    real32_T i32CntSetRdyRestart;
    real32_T i32CntSetInPst;
    real32_T sSetInPstAngleErr;
    real32_T sOprMdeSpdLim;
    real32_T sMpgJogMdeSpdLim;
    real32_T sJogMdeSpdLim;
    real32_T sSpare1;
    real32_T sSpare2;
    real32_T sSpare3;
    real32_T sSpare4;
    real32_T sSpare5;
    real32_T sSpare6;
    real32_T sSpare7;
    uint16_T uDummy;
}
S_H01MDE;

#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct
{
    real32_T sNumTool;                 /* '<S1>/Chart_StateManagement' */
    real32_T sRxRefAngle;              /* '<S1>/Chart_StateManagement' */
    int32_T i32CntSenless;             /* '<S1>/Chart_StateManagement' */
    uint16_T mSMDE_uFlagRestart;       /* '<S1>/Chart_StateManagement' */
    uint16_T uFlagResetEncZ;           /* '<S1>/Chart_StateManagement' */
    uint16_T uFlagSaveEncOriginZ;      /* '<S1>/Chart_StateManagement' */
    uint16_T uNexRefPst;               /* '<S1>/Chart_StateManagement' */
    uint16_T uDoginZ;                  /* '<S1>/Chart_StateManagement' */
    uint16_T uOrginZ;                  /* '<S1>/Chart_StateManagement' */
    uint16_T uFlagCmpltOpMde;          /* '<S1>/Chart_StateManagement' */
    uint16_T uFalg_NJog_Step;          /* '<S1>/Chart_StateManagement' */
    uint16_T uFalg_PJog_Step;          /* '<S1>/Chart_StateManagement' */
    uint16_T uFlagStepJogMde;          /* '<S1>/Chart_StateManagement' */
    uint16_T uStartZ;                  /* '<S1>/Chart_StateManagement' */
    uint8_T is_active_c4_h01_MdeMgmt;  /* '<S1>/Chart_StateManagement' */
    uint8_T is_c4_h01_MdeMgmt;         /* '<S1>/Chart_StateManagement' */
    uint8_T is_Normal;                 /* '<S1>/Chart_StateManagement' */
}
StrH01DW;

/* External outputs (root outports fed by signals with default storage) */
typedef struct
{
    real32_T bH01SMDE_mSMDE_sPstRef;   /* '<Root>/bH01SMDE_mSMDE_sPstRef' */
    X_H01EXO bH01SMDE_mSMDE_uExOut;    /* '<Root>/bH01SMDE_mSMDE_uExOut' */
}
StrH01ExtY;

/* Block signals and states (default storage) */
extern StrH01DW GvH01DW;

/* External outputs (root outports fed by signals with default storage) */
extern StrH01ExtY GvH01Y;

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
extern real32_T mSMDE_sSpdLimit;       /* '<Root>/bH01SMDE_mSMDE_sSpdLimit' */
extern real32_T mSMDE_sSpdRef;         /* '<Root>/bH01SMDE_mSMDE_sSpdRef' */
extern real32_T mSMDE_sIfFreqSeqOut; /* '<Root>/bH01SMDE_mSMDE_sIfFreqSeqOut' */
extern uint16_T mSMDE_uMtrCtrlMde;     /* '<Root>/bH01SMDE_mSMDE_uMtrCtrlMde' */
extern uint16_T mSMDE_uOprState;       /* '<Root>/bH01SMDE_mSMDE_uOprState' */
extern uint16_T mSMDE_uFlagSaveEncOrigin;
                                /* '<Root>/bH01SMDE_mSMDE_uFlagSaveEncOrigin' */
extern uint16_T mSMDE_uFlagResetEnc; /* '<Root>/bH01SMDE_mSMDE_uFlagResetEnc' */
extern int64_T mSMDE_i64PstOrigin;    /* '<Root>/bH01SMDE_mSMDE_i64PstOrigin' */
extern int64_T mSMDE_i64PstRef;        /* '<Root>/bH01SMDE_mSMDE_i64PstRef' */
extern real32_T mSMDE_sRefAngleDisp; /* '<Root>/bH01SMDE_mSMDE_sRefAngleDisp' */
extern real32_T mSMDE_sActAngleDisp; /* '<Root>/bH01SMDE_mSMDE_sActAngleDisp' */
extern real32_T mSMDE_sAngleErrDisp; /* '<Root>/bH01SMDE_mSMDE_sAngleErrDisp' */
extern real32_T mSMDE_sRefAngle;       /* '<Root>/bH01SMDE_mSMDE_sRefAngle' */
extern real32_T mSMDE_sActAngle;       /* '<Root>/bH01SMDE_mSMDE_sActAngle' */
extern real32_T mSMDE_sAngleErr;       /* '<Root>/bH01SMDE_mSMDE_sAngleErr' */
extern uint16_T mSMDE_uOrgNotDef;      /* '<Root>/bH01SMDE_mSMDE_uOrgNotDef' */

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
