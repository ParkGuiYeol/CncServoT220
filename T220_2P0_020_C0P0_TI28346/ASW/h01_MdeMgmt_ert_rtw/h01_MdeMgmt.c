/*
 * File: h01_MdeMgmt.c
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

#include "h01_MdeMgmt.h"
#include "rtwtypes.h"
#include "D02_DRV_I2C.h"
#include "f01_CommRx1.h"
#include "D01_DRV_CAN.h"
#include "e03_MtrCtrl_MtrCtrl.h"

/* Named constants for Chart: '<S1>/Chart_StateManagement' */
#define Cnst_OprMdeOrigin              ((uint16_T)32U)
#define Cnst_OprMdeStandby             ((uint16_T)1U)
#define Cnst_sZero                     (0.0F)
#define Cnst_u16False                  ((uint16_T)0U)
#define Cnst_u16True                   ((uint16_T)1U)
#define Cnst_u16Zero                   ((uint16_T)0U)
#define IN_NO_ACTIVE_CHILD             ((uint8_T)0U)
#define IN_Origin                      ((uint8_T)1U)
#define IN_Standby                     ((uint8_T)2U)

/* Exported block signals */
uint16_T mSMDE_uFlagInverterOut;  /* '<Root>/bH01SMDE_mSMDE_uFlagInverterOut' */
real32_T mSMDE_sSpdRefInSeqOut;    /* '<Root>/bH01SMDE_mSMDE_sSpdRefInSeqOut' */
real32_T mSMDE_sSpdRef;                /* '<Root>/bH01SMDE_mSMDE_sSpdRef' */
real32_T mSMDE_sIfFreqSeqOut;        /* '<Root>/bH01SMDE_mSMDE_sIfFreqSeqOut' */
uint16_T mSMDE_uMtrCtrlMde;            /* '<Root>/bH01SMDE_mSMDE_uMtrCtrlMde' */
uint16_T mSMDE_uOprState;              /* '<Root>/bH01SMDE_mSMDE_uOprState' */
uint16_T mSMDE_uFlagSaveEncOrigin;
                                /* '<Root>/bH01SMDE_mSMDE_uFlagSaveEncOrigin' */
uint16_T mSMDE_uFlagResetEnc;        /* '<Root>/bH01SMDE_mSMDE_uFlagResetEnc' */
int64_T mSMDE_i64PstOrigin;           /* '<Root>/bH01SMDE_mSMDE_i64PstOrigin' */
int64_T mSMDE_i64PstRef;               /* '<Root>/bH01SMDE_mSMDE_i64PstRef' */
uint16_T mSMDE_uExternalOutput;    /* '<Root>/bH01SMDE_mSMDE_uExternalOutput' */

/* Block signals and states (default storage) */
StrH01DW GvH01DW;

/* External inputs (root inport signals with default storage) */
StrH01ExtU GvH01U;

/* Forward declaration for local functions */
static void Ftn_Standby(void);
static void Ftn_OriginDogin(void);

/* Function for Chart: '<S1>/Chart_StateManagement' */
static void Ftn_Standby(void)
{
    /*  Operation mode set (0: I/O, 1: Communication) */
    if (((uint32_T)mCRX1_uRxChSel) == Cnst_u16True)
    {
        mSMDE_uFlagInverterOut = mCRX_uAllowingOperation;
        mSMDE_uMtrCtrlMde = mCRX_uMtrCtrlMde;
        mSMDE_sSpdRef = mCRX_sSpdCmd;
    }
    else
    {
        mSMDE_uFlagInverterOut = Cnst_u16False;
        mSMDE_uMtrCtrlMde = Cnst_u16Zero;
        mSMDE_sSpdRef = Cnst_sZero;
    }

    mSMDE_sSpdRefInSeqOut = mCTRL_sSpdRefIn;
    mSMDE_sIfFreqSeqOut = mCTRL_sIfFreq;
    mSMDE_uExternalOutput = Cnst_u16Zero;
    mSMDE_uOprState = Cnst_u16Zero;
}

/* Function for Chart: '<S1>/Chart_StateManagement' */
static void Ftn_OriginDogin(void)
{
    mSMDE_uFlagInverterOut = Cnst_u16False;
    if (((uint32_T)mCRX_uOrgin) == Cnst_u16True)
    {
        /*  Act uOrigin */
        mSMDE_uFlagSaveEncOrigin = Cnst_u16True;
    }
    else
    {
        /*  Act uDogin */
        mSMDE_uFlagResetEnc = Cnst_u16True;
    }

    mSMDE_i64PstOrigin = 0LL;
    mSMDE_i64PstRef = 0LL;
    GvH01DW.uFlagResetEncZ = mI2c_uFlagResetEnc;
    GvH01DW.uFlagSaveEncOriginZ = mI2c_uFlagSaveEncOrigin;
}

/* Model step function */
void h01_MdeMgmt_step(void)
{
    if (((uint32_T)GvH01DW.is_active_c3_h01_MdeMgmt) == 0U)
    {
        GvH01DW.is_active_c3_h01_MdeMgmt = 1U;
        GvH01DW.is_c3_h01_MdeMgmt = IN_Standby;
        mSMDE_uOprState = Cnst_OprMdeStandby;
    }
    else if (((uint32_T)GvH01DW.is_c3_h01_MdeMgmt) == IN_Origin)
    {
        if (((((uint32_T)mI2c_uFlagResetEnc) == Cnst_u16True) || (((uint32_T)
                GvH01DW.uFlagResetEncZ) == Cnst_u16False)) || ((((uint32_T)
                mI2c_uFlagSaveEncOrigin) == Cnst_u16True) || (((uint32_T)
                GvH01DW.uFlagSaveEncOriginZ) == Cnst_u16False)))
        {
            GvH01DW.is_c3_h01_MdeMgmt = IN_Standby;
            mSMDE_uOprState = Cnst_OprMdeStandby;
        }
        else
        {
            Ftn_OriginDogin();
        }

        /* case IN_Standby: */
    }
    else if ((((uint32_T)mCRX_uOrgin) == Cnst_u16True) || (((uint32_T)
               mCRX_uDogin) == Cnst_u16True))
    {
        GvH01DW.is_c3_h01_MdeMgmt = IN_Origin;
        mSMDE_uOprState = Cnst_OprMdeOrigin;
    }
    else
    {
        Ftn_Standby();
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
    GvH01DW.uFlagResetEncZ = 0U;
    GvH01DW.uFlagSaveEncOriginZ = 0U;
    GvH01DW.is_active_c3_h01_MdeMgmt = 0U;
    GvH01DW.is_c3_h01_MdeMgmt = IN_NO_ACTIVE_CHILD;

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
