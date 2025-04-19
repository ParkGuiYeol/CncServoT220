/*
 * File: h01_MdeMgmt.c
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

#include "h01_MdeMgmt.h"
#include "rtwtypes.h"
#include "d01_Diaglnteg.h"
#include "e02_MtrCtrl_Pst.h"
#include "f01_CommRx1.h"
#include "D02_DRV_I2C.h"
#include "D01_DRV_CAN.h"
#include "e03_MtrCtrl_MtrCtrl.h"

/* Named constants for Chart: '<S1>/Chart_StateManagement' */
#define Cnst_MtrCtrlMde16Spd           ((uint16_T)16U)
#define Cnst_MtrCtrlMde32Pst           ((uint16_T)32U)
#define Cnst_OprMde16Wait              ((uint16_T)16U)
#define Cnst_OprMde1Standby            ((uint16_T)1U)
#define Cnst_OprMde2Jog                ((uint16_T)2U)
#define Cnst_OprMde32Origin            ((uint16_T)32U)
#define Cnst_OprMde4Mpg                ((uint16_T)4U)
#define Cnst_OprMde8Operation          ((uint16_T)8U)
#define Cnst_i64EncMultiMax            (65535LL)
#define Cnst_s179                      (179.0F)
#define Cnst_s180                      (180.0F)
#define Cnst_s181                      (181.0F)
#define Cnst_s240                      (240.0F)
#define Cnst_s360                      (360.0F)
#define Cnst_sHalf                     (0.5F)
#define Cnst_sInv360                   (0.00277777785F)
#define Cnst_sOneHalf                  (1.5F)
#define Cnst_sZero                     (0.0F)
#define Cnst_u16False                  ((uint16_T)0U)
#define Cnst_u16One                    ((uint16_T)1U)
#define Cnst_u16True                   ((uint16_T)1U)
#define Cnst_u16Zero                   ((uint16_T)0U)
#define IN_MpgJOG                      ((uint8_T)1U)
#define IN_NO_ACTIVE_CHILD             ((uint8_T)0U)
#define IN_Normal                      ((uint8_T)1U)
#define IN_OperNJog                    ((uint8_T)2U)
#define IN_OriginDogin                 ((uint8_T)3U)
#define IN_Standby                     ((uint8_T)4U)
#define IN_Wait                        ((uint8_T)2U)

/* Exported block signals */
uint16_T mSMDE_uFlagInverterOut;  /* '<Root>/bH01SMDE_mSMDE_uFlagInverterOut' */
real32_T mSMDE_sSpdRefInSeqOut;    /* '<Root>/bH01SMDE_mSMDE_sSpdRefInSeqOut' */
real32_T mSMDE_sSpdLimit;              /* '<Root>/bH01SMDE_mSMDE_sSpdLimit' */
real32_T mSMDE_sSpdRef;                /* '<Root>/bH01SMDE_mSMDE_sSpdRef' */
real32_T mSMDE_sIfFreqSeqOut;        /* '<Root>/bH01SMDE_mSMDE_sIfFreqSeqOut' */
uint16_T mSMDE_uMtrCtrlMde;            /* '<Root>/bH01SMDE_mSMDE_uMtrCtrlMde' */
uint16_T mSMDE_uOprState;              /* '<Root>/bH01SMDE_mSMDE_uOprState' */
uint16_T mSMDE_uFlagSaveEncOrigin;
                                /* '<Root>/bH01SMDE_mSMDE_uFlagSaveEncOrigin' */
uint16_T mSMDE_uFlagResetEnc;        /* '<Root>/bH01SMDE_mSMDE_uFlagResetEnc' */
int64_T mSMDE_i64PstOrigin;           /* '<Root>/bH01SMDE_mSMDE_i64PstOrigin' */
int64_T mSMDE_i64PstRef;               /* '<Root>/bH01SMDE_mSMDE_i64PstRef' */
real32_T mSMDE_sRefAngleDisp;        /* '<Root>/bH01SMDE_mSMDE_sRefAngleDisp' */
real32_T mSMDE_sActAngleDisp;        /* '<Root>/bH01SMDE_mSMDE_sActAngleDisp' */
real32_T mSMDE_sAngleErrDisp;        /* '<Root>/bH01SMDE_mSMDE_sAngleErrDisp' */
real32_T mSMDE_sRefAngle;              /* '<Root>/bH01SMDE_mSMDE_sRefAngle' */
real32_T mSMDE_sActAngle;              /* '<Root>/bH01SMDE_mSMDE_sActAngle' */
real32_T mSMDE_sAngleErr;              /* '<Root>/bH01SMDE_mSMDE_sAngleErr' */
uint16_T mSMDE_uOrgNotDef;             /* '<Root>/bH01SMDE_mSMDE_uOrgNotDef' */

/* Exported data definition */

/* Definition for custom storage class: FileScope */
static S_H01MDE H01MDE =
{
    20000.0F,
    100.0F,
    1.0F,
    2000.0F,
    50.0F,
    200.0F,
    0.0F,
    0.0F,
    0.0F,
    0.0F,
    0.0F,
    0.0F,
    50.0F,
    0U
} ;                                    /* Referenced by:
                                        * '<S1>/CB_i32CntSetInPst'
                                        * '<S1>/CB_i32CntSetRdyRestart'
                                        * '<S1>/CB_sJogMdeSpdRef'
                                        * '<S1>/CB_sMpgJogMdeSpdRef'
                                        * '<S1>/CB_sOprMdeSpdLim'
                                        * '<S1>/CB_sSetInPstAngleErr'
                                        */

static S_H01TRT H01TRT =
{
    0U,
    21U,
    17.1428566F,
    0.0583333336F,
    342.857147F,
    (65535LL),
    (32768LL),
    (10000LL),
    131072,
    56.0F,
    0.0178571437F,
    7340032,
    1.36239194e-7F,
    4.90461061e-5F,
    0U
} ;                                    /* Referenced by:
                                        * '<S1>/CB_i32BitPerRev'
                                        * '<S1>/CB_i64EncMultiCtrlMax'
                                        * '<S1>/CB_i64EncMultiTurnOffset'
                                        * '<S1>/CB_sAnglePerTool'
                                        * '<S1>/CB_sAngleTrGain'
                                        * '<S1>/CB_sInvAnglePerTool'
                                        * '<S1>/CB_u16NumOfTool'
                                        * '<S1>/CB_uTurretDirection'
                                        */

/* Block signals and states (default storage) */
StrH01DW GvH01DW;

/* External outputs (root outports fed by signals with default storage) */
StrH01ExtY GvH01Y;

/* Forward declaration for local functions */
static void Ftn_Wait(void);
static void Ftn_CalActAngle(void);
static void Ftn_Standby(void);
static void Ftn_CalExOutPst(void);
static void Ftn_MpgJogMde(void);
static void Ftn_CalRefPst(void);
static void Ftn_CalRefAngle(void);
static void Ftn_MoveToRefPst(void);
static void Ftn_CalAngleError(void);
static void Ftn_OriginDogin(void);

/* Function for Chart: '<S1>/Chart_StateManagement' */
static void Ftn_Wait(void)
{
    mSMDE_uFlagInverterOut = Cnst_u16False;
    if (((real32_T)GvH01DW.i32CntSenless) >= H01MDE.i32CntSetRdyRestart)
    {
        GvH01DW.i32CntSenless = (int32_T)H01MDE.i32CntSetRdyRestart;
        GvH01DW.mSMDE_uFlagRestart = Cnst_u16True;
    }
    else
    {
        GvH01DW.i32CntSenless++;
    }
}

/* Function for Chart: '<S1>/Chart_StateManagement' */
static void Ftn_CalActAngle(void)
{
    real32_T sTemp;

    /*  Calculation Acture Angle */
    sTemp = ((real32_T)((int64_T)(mMTPST_i64TurretPst - mSMDE_i64PstOrigin))) *
        H01TRT.sAngleTrGain;
    if (sTemp > Cnst_sZero)
    {
        sTemp -= ((real32_T)((int16_T)((real32_T)(sTemp * Cnst_sInv360)))) *
            Cnst_s360;
    }
    else
    {
        sTemp = (sTemp - (((real32_T)((int16_T)((real32_T)(sTemp * Cnst_sInv360))))
                          * Cnst_s360)) + Cnst_s360;
    }

    if (sTemp < Cnst_sZero)
    {
        sTemp += Cnst_s360;
    }
    else if (sTemp > Cnst_s360)
    {
        sTemp -= Cnst_s360;
    }
    else
    {
        /* no actions */
    }

    if (((uint32_T)H01TRT.uTurretDirection) == Cnst_u16True)
    {
        mSMDE_sActAngle = Cnst_s360 - sTemp;
    }
    else
    {
        mSMDE_sActAngle = sTemp;
    }

    if (GvH01DW.sRxRefAngle > Cnst_s360)
    {
        mSMDE_sRefAngleDisp = GvH01DW.sRxRefAngle - Cnst_s360;
    }
    else if (GvH01DW.sRxRefAngle < Cnst_sZero)
    {
        mSMDE_sRefAngleDisp = GvH01DW.sRxRefAngle + Cnst_s360;
    }
    else
    {
        mSMDE_sRefAngleDisp = GvH01DW.sRxRefAngle;
    }

    if (mSMDE_sActAngle > Cnst_s360)
    {
        mSMDE_sActAngleDisp = mSMDE_sActAngle - Cnst_s360;
    }
    else if (mSMDE_sActAngle < Cnst_sZero)
    {
        mSMDE_sActAngleDisp = mSMDE_sActAngle + Cnst_s360;
    }
    else
    {
        mSMDE_sActAngleDisp = mSMDE_sActAngle;
    }

    mSMDE_sAngleErrDisp = mSMDE_sRefAngleDisp - mSMDE_sActAngleDisp;
    if (mSMDE_sAngleErrDisp > Cnst_s240)
    {
        mSMDE_sAngleErrDisp -= Cnst_s360;
    }
    else if (mSMDE_sAngleErrDisp < -240.0F)
    {
        mSMDE_sAngleErrDisp += Cnst_s360;
    }
    else
    {
        /*  No Action */
    }
}

/* Function for Chart: '<S1>/Chart_StateManagement' */
static void Ftn_Standby(void)
{
    /*  Operation mode set (0: I/O, 1: Communication) */
    if (((uint32_T)mCRX1_uRxChSel) == Cnst_u16True)
    {
        /*  Communication */
        if (((uint32_T)mCRX_uSvOn) == Cnst_u16True)
        {
            mSMDE_uFlagInverterOut = Cnst_u16True;
            mSMDE_uMtrCtrlMde = Cnst_MtrCtrlMde32Pst;
        }
        else
        {
            /*  CAN Operation */
            mSMDE_uFlagInverterOut = mCRX_uAllowingOperation;
            mSMDE_uMtrCtrlMde = mCRX_uMtrCtrlMde;
            mSMDE_sSpdRef = mCRX_sSpdCmd;
        }

        /*  I/O Operation */
    }
    else if (((uint32_T)mCRX_uSvOn) == Cnst_u16True)
    {
        mSMDE_uFlagInverterOut = Cnst_u16True;
        mSMDE_uMtrCtrlMde = Cnst_MtrCtrlMde32Pst;
    }
    else
    {
        mSMDE_uFlagInverterOut = Cnst_u16False;
        mSMDE_uMtrCtrlMde = Cnst_u16Zero;
        mSMDE_sSpdRef = Cnst_sZero;
        mSMDE_i64PstRef = mMTPST_i64TurretPst;
    }

    mSMDE_sSpdRefInSeqOut = mCTRL_sSpdRefIn;
    mSMDE_sIfFreqSeqOut = mCTRL_sIfFreq;
    GvH01DW.uOrginZ = mCRX_uOrgin;
    GvH01DW.uDoginZ = mCRX_uDogin;
    GvH01DW.uFlagResetEncZ = mI2c_uFlagResetEnc;
    GvH01DW.uFlagSaveEncOriginZ = mI2c_uFlagSaveEncOrigin;
}

/* Function for Chart: '<S1>/Chart_StateManagement' */
static void Ftn_CalExOutPst(void)
{
    /*  Calculating the Current Position and Setting the Digital Output */
    GvH01DW.sNumTool = (real32_T)((real_T)(((real_T)((int16_T)((real_T)
        (((((real_T)((real32_T)(mSMDE_sActAngle * H01TRT.sInvAnglePerTool))) +
           1.0) + 0.05) * 10.0)))) * 0.1));

    /*  소숫점이하 버림 */
    if (mSMDE_sActAngle > (Cnst_s360 - H01MDE.sSetInPstAngleErr))
    {
        GvH01Y.bH01SMDE_mSMDE_uExOut.uActPst = Cnst_u16One;
    }
    else if ((((real_T)((int16_T)GvH01DW.sNumTool)) * 10.0) == (((real_T)
               GvH01DW.sNumTool) * 10.0))
    {
        GvH01Y.bH01SMDE_mSMDE_uExOut.uActPst = (uint16_T)GvH01DW.sNumTool;
    }
    else
    {
        GvH01Y.bH01SMDE_mSMDE_uExOut.uActPst = Cnst_u16Zero;
    }
}

/* Function for Chart: '<S1>/Chart_StateManagement' */
static void Ftn_MpgJogMde(void)
{
    if ((((uint32_T)mCRX_uPJog) == Cnst_u16True) && (((uint32_T)mCRX_uNJog) ==
            Cnst_u16True))
    {
        mSMDE_uMtrCtrlMde = Cnst_MtrCtrlMde32Pst;
        mSMDE_sSpdRef = Cnst_sZero;
    }
    else if (((uint32_T)mCRX_uPJog) == Cnst_u16True)
    {
        mSMDE_uMtrCtrlMde = Cnst_MtrCtrlMde16Spd;
        mSMDE_sSpdRef = H01MDE.sMpgJogMdeSpdLim;
    }
    else if (((uint32_T)mCRX_uNJog) == Cnst_u16True)
    {
        mSMDE_uMtrCtrlMde = Cnst_MtrCtrlMde16Spd;
        mSMDE_sSpdRef = -H01MDE.sMpgJogMdeSpdLim;
    }
    else
    {
        mSMDE_uMtrCtrlMde = Cnst_MtrCtrlMde32Pst;
        mSMDE_sSpdRef = Cnst_sZero;
    }

    mSMDE_i64PstRef = mMTPST_i64TurretPst;
}

/* Function for Chart: '<S1>/Chart_StateManagement' */
static void Ftn_CalRefPst(void)
{
    real32_T sAbsAngleErr;

    /*  Calculation Angle Error */
    mSMDE_uMtrCtrlMde = Cnst_MtrCtrlMde32Pst;
    mSMDE_sAngleErr = GvH01DW.sRxRefAngle - mSMDE_sActAngle;
    if (mSMDE_sAngleErr < Cnst_sZero)
    {
        sAbsAngleErr = -mSMDE_sAngleErr;
    }
    else
    {
        sAbsAngleErr = mSMDE_sAngleErr;
    }

    /*  각도 지령이 179~180도일 경우 또는 엔코더 포화시 근거리 운전 모드 -> 초기 멀티턴 방향으로 이동 */
    if (((sAbsAngleErr > Cnst_s179) && (sAbsAngleErr < Cnst_s181)) ||
            ((mSMDE_i64PstOrigin > H01TRT.i64EncMultiCtrlMax) &&
             (mSMDE_i64PstOrigin < (Cnst_i64EncMultiMax -
            H01TRT.i64EncMultiCtrlMax))))
    {
        if (((uint32_T)H01TRT.uTurretDirection) == Cnst_u16True)
        {
            /*  uTurretDirection == Cnst_u16True */
            if (mSMDE_i64PstOrigin < H01TRT.i64EncMultiTurnOffset)
            {
                /*  멀티턴이 0~32768 사이에 있을 경우 중앙(센터)에 가깝게 이동하기 위해 CCW 방향으로 이동해야 함 */
                if (mSMDE_sAngleErr > Cnst_sZero)
                {
                    /*  CW 방향의 각도 지령일 경우  CCW 방향으로 이동(180-360=-180) */
                    mSMDE_sRefAngle = mSMDE_sAngleErr;
                }
                else
                {
                    /*  CCW 방향의 각도 지령일 경우  CCW 방향으로 이동(-180=-180) */
                    mSMDE_sRefAngle = mSMDE_sAngleErr + Cnst_s360;
                }

                /*  멀티턴이 35535~65535 사이에 있을 경우 중앙(센터)에 가깝게 이동하기 위해 CW 방향으로 이동해야 함 */
            }
            else if (mSMDE_sAngleErr > Cnst_sZero)
            {
                /*  CW 방향의 각도 지령일 경우  CW 방향으로 이동(180=180) */
                mSMDE_sRefAngle = mSMDE_sAngleErr - Cnst_s360;
            }
            else
            {
                /*  CCW 방향의 각도 지령일 경우  CCW 방향으로 이동(-180+360=180) */
                mSMDE_sRefAngle = mSMDE_sAngleErr;
            }

            /*  uTurretDirection == Cnst_u16False */
        }
        else if (mSMDE_i64PstOrigin < H01TRT.i64EncMultiTurnOffset)
        {
            /*  멀티턴이 0~32768 사이에 있을 경우 중앙(센터)에 가깝게 이동하기 위해 CCW 방향으로 이동해야 함 */
            if (mSMDE_sAngleErr > Cnst_sZero)
            {
                /*  CW 방향의 각도 지령일 경우  CCW 방향으로 이동(180-360=-180) */
                mSMDE_sRefAngle = mSMDE_sAngleErr - Cnst_s360;
            }
            else
            {
                /*  CCW 방향의 각도 지령일 경우  CCW 방향으로 이동(-180=-180) */
                mSMDE_sRefAngle = mSMDE_sAngleErr;
            }

            /*  멀티턴이 35535~65535 사이에 있을 경우 중앙(센터)에 가깝게 이동하기 위해 CW 방향으로 이동해야 함 */
        }
        else if (mSMDE_sAngleErr > Cnst_sZero)
        {
            /*  CW 방향의 각도 지령일 경우  CW 방향으로 이동(180=180) */
            mSMDE_sRefAngle = mSMDE_sAngleErr;
        }
        else
        {
            /*  CCW 방향의 각도 지령일 경우  CCW 방향으로 이동(-180+360=180) */
            mSMDE_sRefAngle = mSMDE_sAngleErr + Cnst_s360;
        }
    }
    else if (mSMDE_sAngleErr > Cnst_s180)
    {
        mSMDE_sRefAngle = mSMDE_sAngleErr - Cnst_s360;
    }
    else if (mSMDE_sAngleErr < -180.0F)
    {
        mSMDE_sRefAngle = mSMDE_sAngleErr + Cnst_s360;
    }
    else
    {
        mSMDE_sRefAngle = mSMDE_sAngleErr;
    }

    if (((uint32_T)H01TRT.uTurretDirection) == Cnst_u16True)
    {
        mSMDE_i64PstRef = mMTPST_i64TurretPst - ((int64_T)((real32_T)(((real32_T)
            H01TRT.i32BitPerRev) * (mSMDE_sRefAngle * Cnst_sInv360))));
    }
    else
    {
        mSMDE_i64PstRef = mMTPST_i64TurretPst + ((int64_T)((real32_T)(((real32_T)
            H01TRT.i32BitPerRev) * (mSMDE_sRefAngle * Cnst_sInv360))));
    }
}

/* Function for Chart: '<S1>/Chart_StateManagement' */
static void Ftn_CalRefAngle(void)
{
    uint16_T tmp;

    /*  Calculation Reference Angle */
    if ((mSMDE_i64PstOrigin != 0LL) && (((uint32_T)mCRX_uRefPst) >= Cnst_u16One))
    {
        if ((((uint32_T)mCRX_uStart) == Cnst_u16True) && (((uint32_T)
                GvH01DW.uStartZ) == Cnst_u16False))
        {
            if (mCRX_uRefPst > H01TRT.u16NumOfTool)
            {
                tmp = H01TRT.u16NumOfTool;
            }
            else
            {
                tmp = mCRX_uRefPst;
            }

            GvH01DW.sRxRefAngle = ((real32_T)((int32_T)(((int32_T)tmp) -
                ((int32_T)Cnst_u16One)))) * H01TRT.sAnglePerTool;
            Ftn_CalRefPst();
        }
        else
        {
            /*  No Action */
        }
    }
    else
    {
        /*  Index 0 is not a valid value, but if index 0 is received, it is configured to move to the origin. */
        mSMDE_sRefAngle = Cnst_sZero;
    }

    GvH01DW.uStartZ = mCRX_uStart;
}

/* Function for Chart: '<S1>/Chart_StateManagement' */
static void Ftn_MoveToRefPst(void)
{
    if (((((uint32_T)mCRX_uPJog) == Cnst_u16True) && (((uint32_T)mCRX_uNJog) ==
            Cnst_u16True)) || ((((uint32_T)mCRX_uPJog) == Cnst_u16False) &&
                               (((uint32_T)mCRX_uNJog) == Cnst_u16False)))
    {
        mSMDE_uOprState = Cnst_OprMde8Operation;
        mSMDE_uMtrCtrlMde = Cnst_MtrCtrlMde32Pst;
        if (((uint32_T)GvH01DW.uFlagStepJogMde) == Cnst_u16True)
        {
            mSMDE_sSpdLimit = H01MDE.sJogMdeSpdLim;
        }
        else
        {
            mSMDE_sSpdLimit = H01MDE.sOprMdeSpdLim;
        }

        Ftn_CalRefAngle();
    }
    else
    {
        /*  Activation Jog Mode */
        mSMDE_uOprState = Cnst_OprMde2Jog;
        mSMDE_uMtrCtrlMde = Cnst_MtrCtrlMde16Spd;
        GvH01DW.uFlagStepJogMde = Cnst_u16True;
        if (((uint32_T)mCRX_uPJog) == Cnst_u16True)
        {
            if (((uint32_T)GvH01DW.uFalg_NJog_Step) == Cnst_u16False)
            {
                /*  uFalg_PJog_Step = Cnst_u16True; */
                if (((uint32_T)H01TRT.uTurretDirection) == Cnst_u16True)
                {
                    mSMDE_sSpdRef = -H01MDE.sJogMdeSpdLim;
                    GvH01DW.uNexRefPst = (uint16_T)((real32_T)(GvH01DW.sNumTool
                        - Cnst_sOneHalf));
                }
                else
                {
                    mSMDE_sSpdRef = H01MDE.sJogMdeSpdLim;
                    GvH01DW.uNexRefPst = (uint16_T)((real32_T)(GvH01DW.sNumTool
                        + Cnst_sHalf));
                }
            }
            else
            {
                /*  No Action */
            }
        }
        else if (((uint32_T)GvH01DW.uFalg_PJog_Step) == Cnst_u16False)
        {
            /*  uFalg_NJog_Step = Cnst_u16True;; */
            if (((uint32_T)H01TRT.uTurretDirection) == Cnst_u16True)
            {
                mSMDE_sSpdRef = H01MDE.sJogMdeSpdLim;
                GvH01DW.uNexRefPst = (uint16_T)((real32_T)(GvH01DW.sNumTool +
                    Cnst_sHalf));
            }
            else
            {
                mSMDE_sSpdRef = -H01MDE.sJogMdeSpdLim;
                GvH01DW.uNexRefPst = (uint16_T)((real32_T)(GvH01DW.sNumTool -
                    Cnst_sOneHalf));
            }
        }
        else
        {
            /*  No Action */
        }

        mSMDE_sRefAngle = ((real32_T)GvH01DW.uNexRefPst) * H01TRT.sAnglePerTool;
        mSMDE_sAngleErr = mSMDE_sRefAngle - mSMDE_sActAngleDisp;
        mSMDE_i64PstRef = mMTPST_i64TurretPst + ((int64_T)((real32_T)(((real32_T)
            H01TRT.i32BitPerRev) * (mSMDE_sAngleErr * Cnst_sInv360))));
    }
}

/* Function for Chart: '<S1>/Chart_StateManagement' */
static void Ftn_CalAngleError(void)
{
    real32_T sAbsAngleErr;

    /*  Calculation Angle Error */
    /* mSMDE_uMtrCtrlMde = Cnst_MtrCtrlMde32Pst; */
    mSMDE_sAngleErr = mSMDE_sRefAngle - mSMDE_sActAngle;
    if (mSMDE_sAngleErr > Cnst_s360)
    {
        mSMDE_sAngleErr -= Cnst_s360;

        /*  No Action */
    }
    else if (mSMDE_sAngleErr < -0.0F)
    {
        mSMDE_sAngleErr += Cnst_s360;
    }
    else
    {
        /* no actions */
    }

    if (mSMDE_sAngleErrDisp < Cnst_sZero)
    {
        sAbsAngleErr = -mSMDE_sAngleErrDisp;
    }
    else
    {
        sAbsAngleErr = mSMDE_sAngleErrDisp;
    }

    if ((sAbsAngleErr < H01MDE.sSetInPstAngleErr) || (sAbsAngleErr > (Cnst_s360
            - H01MDE.sSetInPstAngleErr)))
    {
        if (((real32_T)GvH01DW.i32CntSenless) >= H01MDE.i32CntSetInPst)
        {
            GvH01DW.i32CntSenless = (int32_T)H01MDE.i32CntSetInPst;
            GvH01Y.bH01SMDE_mSMDE_uExOut.uInPst = Cnst_u16True;
            GvH01DW.uFlagStepJogMde = Cnst_u16False;
            GvH01DW.uFalg_PJog_Step = Cnst_u16False;
            GvH01DW.uFalg_NJog_Step = Cnst_u16False;
            GvH01DW.uFlagCmpltOpMde = Cnst_u16True;
        }
        else
        {
            GvH01DW.i32CntSenless++;
        }
    }
    else
    {
        GvH01Y.bH01SMDE_mSMDE_uExOut.uInPst = Cnst_u16False;
        GvH01DW.i32CntSenless = 0;
    }
}

/* Function for Chart: '<S1>/Chart_StateManagement' */
static void Ftn_OriginDogin(void)
{
    mSMDE_uFlagInverterOut = Cnst_u16False;
    if ((((uint32_T)mCRX_uOrgin) != Cnst_u16True) || (((uint32_T)mCRX_uDogin) !=
         Cnst_u16True))
    {
        if (((uint32_T)mCRX_uOrgin) == Cnst_u16True)
        {
            /*  Act uOrigin */
            mSMDE_uFlagSaveEncOrigin = Cnst_u16True;
            mSMDE_sRefAngle = Cnst_sZero;
            mSMDE_i64PstOrigin = mMTPST_i64TurretPst;
            GvH01Y.bH01SMDE_mSMDE_uExOut.uOrgNotDef = Cnst_u16False;
            GvH01Y.bH01SMDE_mSMDE_uExOut.uInPst = Cnst_u16True;
        }
        else if (((uint32_T)mCRX_uDogin) == Cnst_u16True)
        {
            /*  Act uDogin */
            mSMDE_uFlagResetEnc = Cnst_u16True;
            mSMDE_i64PstOrigin = 0LL;
            GvH01Y.bH01SMDE_mSMDE_uExOut.uOrgNotDef = Cnst_u16True;
        }
        else
        {
            /*  No Action */
        }
    }
    else
    {
        /*  No Action */
    }

    GvH01DW.uOrginZ = mCRX_uOrgin;
    GvH01DW.uDoginZ = mCRX_uDogin;
    GvH01DW.uFlagResetEncZ = mI2c_uFlagResetEnc;
    GvH01DW.uFlagSaveEncOriginZ = mI2c_uFlagSaveEncOrigin;
    mSMDE_i64PstRef = mMTPST_i64TurretPst;
    mSMDE_uOrgNotDef = GvH01Y.bH01SMDE_mSMDE_uExOut.uOrgNotDef;
}

/* Model step function */
void h01_MdeMgmt_step(void)
{
    boolean_T tmp;
    if (((uint32_T)GvH01DW.is_active_c4_h01_MdeMgmt) == 0U)
    {
        GvH01DW.is_active_c4_h01_MdeMgmt = 1U;
        GvH01DW.is_c4_h01_MdeMgmt = IN_Normal;
        GvH01DW.mSMDE_uFlagRestart = Cnst_u16False;
        GvH01DW.is_Normal = IN_Standby;
        mSMDE_uOprState = Cnst_OprMde1Standby;
        GvH01DW.uFlagCmpltOpMde = Cnst_u16False;
        GvH01Y.bH01SMDE_mSMDE_uExOut.uAlarm = Cnst_u16False;
        GvH01Y.bH01SMDE_mSMDE_uExOut.uStadby = Cnst_u16True;

        /*  mSMDE_i64PstRef = mMTPST_i64TurretPst; */
        mSMDE_sSpdLimit = H01MDE.sOprMdeSpdLim;
    }
    else if (((uint32_T)GvH01DW.is_c4_h01_MdeMgmt) == IN_Normal)
    {
        if (((uint32_T)mDIAG_uFltStat) == Cnst_u16True)
        {
            if (((uint32_T)GvH01DW.is_Normal) == IN_OriginDogin)
            {
                mSMDE_uFlagSaveEncOrigin = Cnst_u16False;
                GvH01DW.is_Normal = IN_NO_ACTIVE_CHILD;
            }
            else
            {
                GvH01DW.is_Normal = IN_NO_ACTIVE_CHILD;
            }

            GvH01DW.is_c4_h01_MdeMgmt = IN_Wait;
            mSMDE_uOprState = Cnst_OprMde16Wait;
            GvH01DW.mSMDE_uFlagRestart = Cnst_u16False;
            GvH01DW.i32CntSenless = 0;
            GvH01Y.bH01SMDE_mSMDE_uExOut.uAlarm = Cnst_u16True;
            GvH01Y.bH01SMDE_mSMDE_uExOut.uStadby = Cnst_u16False;
        }
        else
        {
            Ftn_CalActAngle();
            switch (GvH01DW.is_Normal)
            {
              case IN_MpgJOG:
                if ((((uint32_T)mCRX_uSvOn) == Cnst_u16False) || (((uint32_T)
                        mCRX_uEnMpg) == Cnst_u16False))
                {
                    GvH01DW.is_Normal = IN_Standby;
                    mSMDE_uOprState = Cnst_OprMde1Standby;
                    GvH01DW.uFlagCmpltOpMde = Cnst_u16False;
                    GvH01Y.bH01SMDE_mSMDE_uExOut.uAlarm = Cnst_u16False;
                    GvH01Y.bH01SMDE_mSMDE_uExOut.uStadby = Cnst_u16True;

                    /*  mSMDE_i64PstRef = mMTPST_i64TurretPst; */
                    mSMDE_sSpdLimit = H01MDE.sOprMdeSpdLim;
                }
                else
                {
                    mSMDE_uFlagInverterOut = mCRX_uSvOn;
                    Ftn_CalExOutPst();
                    Ftn_MpgJogMde();
                }
                break;

              case IN_OperNJog:
                if ((((uint32_T)mCRX_uSvOn) == Cnst_u16False) || (((uint32_T)
                        GvH01DW.uFlagCmpltOpMde) == Cnst_u16True))
                {
                    GvH01DW.is_Normal = IN_Standby;
                    mSMDE_uOprState = Cnst_OprMde1Standby;
                    GvH01DW.uFlagCmpltOpMde = Cnst_u16False;
                    GvH01Y.bH01SMDE_mSMDE_uExOut.uAlarm = Cnst_u16False;
                    GvH01Y.bH01SMDE_mSMDE_uExOut.uStadby = Cnst_u16True;

                    /*  mSMDE_i64PstRef = mMTPST_i64TurretPst; */
                    mSMDE_sSpdLimit = H01MDE.sOprMdeSpdLim;
                }
                else if ((((uint32_T)mCRX_uSvOn) == Cnst_u16True) && (((uint32_T)
                           mCRX_uEnMpg) == Cnst_u16True))
                {
                    GvH01DW.is_Normal = IN_MpgJOG;
                    mSMDE_uOprState = Cnst_OprMde4Mpg;
                }
                else
                {
                    mSMDE_uFlagInverterOut = mCRX_uSvOn;
                    Ftn_MoveToRefPst();
                    Ftn_CalAngleError();
                    Ftn_CalExOutPst();
                }
                break;

              case IN_OriginDogin:
                if (((((uint32_T)mI2c_uFlagResetEnc) == Cnst_u16False) &&
                        (((uint32_T)GvH01DW.uFlagResetEncZ) == Cnst_u16True)) ||
                    ((((uint32_T)mI2c_uFlagSaveEncOrigin) == Cnst_u16False) &&
                        (((uint32_T)GvH01DW.uFlagSaveEncOriginZ) == Cnst_u16True)))
                {
                    mSMDE_uFlagSaveEncOrigin = Cnst_u16False;
                    GvH01DW.is_Normal = IN_Standby;
                    mSMDE_uOprState = Cnst_OprMde1Standby;
                    GvH01DW.uFlagCmpltOpMde = Cnst_u16False;
                    GvH01Y.bH01SMDE_mSMDE_uExOut.uAlarm = Cnst_u16False;
                    GvH01Y.bH01SMDE_mSMDE_uExOut.uStadby = Cnst_u16True;

                    /*  mSMDE_i64PstRef = mMTPST_i64TurretPst; */
                    mSMDE_sSpdLimit = H01MDE.sOprMdeSpdLim;
                }
                else
                {
                    Ftn_OriginDogin();
                }
                break;

              default:
                /* case IN_Standby: */
                if (((((uint32_T)mCRX_uOrgin) == Cnst_u16True) && (((uint32_T)
                        GvH01DW.uOrginZ) == Cnst_u16False)) || ((((uint32_T)
                        mCRX_uDogin) == Cnst_u16True) && (((uint32_T)
                        GvH01DW.uDoginZ) == Cnst_u16False)))
                {
                    GvH01DW.is_Normal = IN_OriginDogin;
                    mSMDE_uOprState = Cnst_OprMde32Origin;
                }
                else if ((((uint32_T)mCRX_uSvOn) == Cnst_u16True) && (((uint32_T)
                           mCRX_uEnMpg) == Cnst_u16True))
                {
                    GvH01DW.is_Normal = IN_MpgJOG;
                    mSMDE_uOprState = Cnst_OprMde4Mpg;
                }
                else
                {
                    tmp = ((((uint32_T)mCRX_uSvOn) == Cnst_u16True) &&
                           (mSMDE_i64PstOrigin != 0LL));
                    if ((tmp && ((((uint32_T)mCRX_uPJog) == Cnst_u16True) ||
                                 (((uint32_T)mCRX_uNJog) == Cnst_u16True))) ||
                            ((tmp && (((uint32_T)mCRX_uStart) == Cnst_u16True)) &&
                             (((uint32_T)GvH01DW.uStartZ) == Cnst_u16False)))
                    {
                        GvH01DW.is_Normal = IN_OperNJog;
                        GvH01DW.i32CntSenless = 0;
                    }
                    else
                    {
                        Ftn_Standby();
                        Ftn_CalExOutPst();
                    }
                }
                break;
            }
        }

        /* case IN_Wait: */
    }
    else if ((((uint32_T)mDIAG_uFltStat) == Cnst_u16False) && (((uint32_T)
               GvH01DW.mSMDE_uFlagRestart) == Cnst_u16True))
    {
        GvH01DW.is_c4_h01_MdeMgmt = IN_Normal;
        GvH01DW.mSMDE_uFlagRestart = Cnst_u16False;
        GvH01DW.is_Normal = IN_Standby;
        mSMDE_uOprState = Cnst_OprMde1Standby;
        GvH01DW.uFlagCmpltOpMde = Cnst_u16False;
        GvH01Y.bH01SMDE_mSMDE_uExOut.uAlarm = Cnst_u16False;
        GvH01Y.bH01SMDE_mSMDE_uExOut.uStadby = Cnst_u16True;

        /*  mSMDE_i64PstRef = mMTPST_i64TurretPst; */
        mSMDE_sSpdLimit = H01MDE.sOprMdeSpdLim;
    }
    else
    {
        Ftn_Wait();
        mSMDE_i64PstRef = mMTPST_i64TurretPst;
    }
}

/* Model initialize function */
void h01_MdeMgmt_initialize(void)
{
    /* Registration code */

    /* states (dwork) */
    (void) memset((void *)&GvH01DW, 0,
                  sizeof(StrH01DW));

    /* user code (Initialize function Body) */

    /* MISRA-C Dummy Code */
    // H01STMDE.uDummy = 0U;
    mSMDE_i64PstOrigin = 4294180863LL;
    GvH01DW.mSMDE_uFlagRestart = 0U;
    GvH01DW.i32CntSenless = 0;
    GvH01DW.uDoginZ = 0U;
    GvH01DW.uOrginZ = 0U;
    GvH01DW.uFlagResetEncZ = 0U;
    GvH01DW.uFlagSaveEncOriginZ = 0U;
    GvH01DW.uFlagCmpltOpMde = 0U;
    GvH01DW.uFalg_NJog_Step = 0U;
    GvH01DW.uFalg_PJog_Step = 0U;
    GvH01DW.uFlagStepJogMde = 0U;
    GvH01DW.uStartZ = 0U;
    GvH01DW.sRxRefAngle = 0.0F;
    GvH01DW.sNumTool = 0.0F;
    GvH01DW.uNexRefPst = 0U;
    GvH01DW.is_active_c4_h01_MdeMgmt = 0U;
    GvH01DW.is_c4_h01_MdeMgmt = IN_NO_ACTIVE_CHILD;
    GvH01DW.is_Normal = IN_NO_ACTIVE_CHILD;

    /* user code (Initialize function Trailer) */
    mSMDE_i64PstOrigin = (((int64)PD[POS_ORIGIN_5] & 0xFF) << 32)
        | (((int64)PD[POS_ORIGIN_4] & 0xFF) << 24)
        | (((int64)PD[POS_ORIGIN_3] & 0xFF) << 16)
        | (((int64)PD[POS_ORIGIN_2] & 0xFF) << 8)
        | ((int64)PD[POS_ORIGIN_1] & 0xFF);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
