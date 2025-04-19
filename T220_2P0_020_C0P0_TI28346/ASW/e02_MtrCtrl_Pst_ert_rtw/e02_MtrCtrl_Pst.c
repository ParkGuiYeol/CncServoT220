/*
 * File: e02_MtrCtrl_Pst.c
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

#include "e02_MtrCtrl_Pst.h"
#include "rtwtypes.h"
#include <math.h>
#include "c01_MainAdc.h"
#include "d01_Diaglnteg.h"
#include "b01_OSnScheduler.h"
#include "M1_Interrupt.h"

/* Exported block signals */
real32_T mMTPST_sWm;                   /* '<Root>/bE02MTPST_mMTPST_sWm' */
real32_T mMTPST_sWe;                   /* '<Root>/bE02MTPST_mMTPST_sWe' */
real32_T mMTPST_sRpm;                  /* '<Root>/bE02MTPST_mMTPST_sRpm' */
real32_T mMTPST_sTheta;                /* '<Root>/bE02MTPST_mMTPST_sTheta' */
uint32_T mMTPST_u32EncMultiTurn; /* '<Root>/bE02MTPST_mMTPST_u32EncMultiTurn' */
int64_T mMTPST_i64TurretPst;        /* '<Root>/bE02MTPST_mMTPST_i64TurretPst' */
real32_T mMTPST_sIde;                  /* '<Root>/bE02MTPST_mMTPST_sIde' */
real32_T mMTPST_sIqe;                  /* '<Root>/bE02MTPST_mMTPST_sIqe' */
real32_T mMTPST_sIds;                  /* '<Root>/bE02MTPST_mMTPST_sIds' */
real32_T mMTPST_sIqs;                  /* '<Root>/bE02MTPST_mMTPST_sIqs' */

/* Exported data definition */

/* Definition for custom storage class: FileScope */
static S_E02ITDC E02ITDC =
{
    -0.04363323F,
    -0.04363323F,
    0.0F,
    -0.04363323F,
    0U
} ;                             /* Referenced by: '<S2>/CB_E02ITDC_sVltTdcGb' */

static S_E02PST E02PST =
{
    0.0F,
    0.25F,
    65535U,
    32768U,
    131071,
    MAX_int16_T,
    32767.0F,
    3.05185094e-5F,
    0.000191753454F,
    983,
    0U
} ;                                    /* Referenced by:
                                        * '<S6>/CB_E02PST_i16AllowedCntMin'
                                        * '<S6>/CB_E02PST_i16EncElectMaxCnt'
                                        * '<S11>/CB_E02ESTP_sInvPolePairs'
                                        * '<S11>/CB_E02PST_sPI2InvPPR'
                                        * '<S12>/CB_E02PST_i32EncElectMaxCnt'
                                        * '<S12>/CB_E02PST_i32EncElectMaxCnt1'
                                        * '<S12>/CB_E02PST_sInvEncElectMaxCnt'
                                        * '<S13>/CB_E02PST_sPI2InvPPR'
                                        * '<S13>/CB_E02PST_sThetaOffset'
                                        * '<S16>/CB_u32EncMultiTurnOffset'
                                        */

static S_E02SWF E02SWF =
{
    0.969069898F,
    0.0154650388F,
    0.987512112F,
    0.00624395348F,
    0.987512112F,
    0.00624395348F,
    0U
} ;                                    /* Referenced by:
                                        * '<S7>/Constant'
                                        * '<S7>/Constant1'
                                        * '<S8>/Constant'
                                        * '<S8>/Constant1'
                                        * '<S9>/Constant'
                                        * '<S9>/Constant1'
                                        */

/* Block signals and states (default storage) */
StrE02DW GvE02DW;
static void Ftn_RevAbc2dqe_Init(void);
static void Ftn_RevAbc2dqe(void);
static void Ftn_RevCurrDlyCmpsn(void);
static void Ftn_CalMdata_Init(void);
static void Ftn_CalMdata(void);
static void Ftn_SpdMtMethod_Init(void);
static void Ftn_SpdMtMethod(void);

/* System initialize for atomic system: '<Root>/Ftn_RevAbc2dqe' */
static void Ftn_RevAbc2dqe_Init(void)
{
    mMTPST_sIde = 0.0F;
    mMTPST_sIqe = 0.0F;
}

/*
 * Output and update for atomic system: '<Root>/Ftn_RevAbc2dqe'
 * Block description for: '<Root>/Ftn_RevAbc2dqe'
 *   DQ Transformation
 */
static void Ftn_RevAbc2dqe(void)
{
    real32_T rtb_sCosTheta;
    real32_T rtb_sSinTheta;
    mMTPST_sIds = 0.333333343F * (((2.0F * mMsens_sIa) - mMsens_sIb) -
        mMsens_sIc);
    rtb_sCosTheta = cosf(GvE02DW.sEncThetaCurrTdc);
    mMTPST_sIqs = 0.577350259F * (mMsens_sIb - mMsens_sIc);
    rtb_sSinTheta = sinf(GvE02DW.sEncThetaCurrTdc);
    if (mDIAG_uCntCrtOvr == 0U)
    {
        mMTPST_sIde = (mMTPST_sIds * rtb_sCosTheta) + (mMTPST_sIqs *
            rtb_sSinTheta);
        mMTPST_sIqe = (mMTPST_sIqs * rtb_sCosTheta) - (mMTPST_sIds *
            rtb_sSinTheta);
    }
    else
    {
        /*  no action  */
    }
}

/* Output and update for atomic system: '<Root>/Ftn_RevCurrDlyCmpsn' */
static void Ftn_RevCurrDlyCmpsn(void)
{
    real32_T rtb_sCalThetaTemp1;
    rtb_sCalThetaTemp1 = mMTPST_sTheta + E02ITDC.sVltTdcGb;
    if (rtb_sCalThetaTemp1 < 0.0F)
    {
        rtb_sCalThetaTemp1 += 6.28318548F;
    }

    if (rtb_sCalThetaTemp1 > 6.28318548F)
    {
        GvE02DW.sEncThetaCurrTdc = rtb_sCalThetaTemp1 - 6.28318548F;
    }
    else
    {
        GvE02DW.sEncThetaCurrTdc = rtb_sCalThetaTemp1;
    }
}

/* System initialize for atomic system: '<S3>/Ftn_CalMdata' */
static void Ftn_CalMdata_Init(void)
{
    GvE02DW.i16Mdata = 0;
}

/* Output and update for atomic system: '<S3>/Ftn_CalMdata' */
static void Ftn_CalMdata(void)
{
    int16_T tmp;
    if (GvE02DW.i16DiffPostion > E02PST.i16AllowedCntMin)
    {
        if ((GvE02DW.i16DiffPostion >= 0) && (E02PST.i16EncElectMaxCnt <
                (GvE02DW.i16DiffPostion - MAX_int16_T)))
        {
            GvE02DW.i16Mdata = MAX_int16_T;
        }
        else if ((GvE02DW.i16DiffPostion < 0) && (E02PST.i16EncElectMaxCnt >
                  (GvE02DW.i16DiffPostion - MIN_int16_T)))
        {
            GvE02DW.i16Mdata = MIN_int16_T;
        }
        else
        {
            GvE02DW.i16Mdata = GvE02DW.i16DiffPostion - E02PST.i16EncElectMaxCnt;
        }
    }
    else
    {
        if (E02PST.i16AllowedCntMin <= MIN_int16_T)
        {
            tmp = MAX_int16_T;
        }
        else
        {
            tmp = -E02PST.i16AllowedCntMin;
        }

        if (GvE02DW.i16DiffPostion < tmp)
        {
            if ((GvE02DW.i16DiffPostion < 0) && (E02PST.i16EncElectMaxCnt <
                    (MIN_int16_T - GvE02DW.i16DiffPostion)))
            {
                GvE02DW.i16Mdata = MIN_int16_T;
            }
            else if ((GvE02DW.i16DiffPostion > 0) && (E02PST.i16EncElectMaxCnt >
                      (MAX_int16_T - GvE02DW.i16DiffPostion)))
            {
                GvE02DW.i16Mdata = MAX_int16_T;
            }
            else
            {
                GvE02DW.i16Mdata = GvE02DW.i16DiffPostion +
                    E02PST.i16EncElectMaxCnt;
            }
        }
        else
        {
            GvE02DW.i16Mdata = GvE02DW.i16DiffPostion;
        }
    }
}

/* System initialize for atomic system: '<Root>/Ftn_SpdMtMethod' */
static void Ftn_SpdMtMethod_Init(void)
{
    Ftn_CalMdata_Init();
}

/* Output and update for atomic system: '<Root>/Ftn_SpdMtMethod' */
static void Ftn_SpdMtMethod(void)
{
    real32_T rtb_sSpdNow;
    real32_T rtb_sThetaIntegIn;
    real32_T rtb_sWe;
    real32_T rtb_sWm;
    GvE02DW.i32CntIntegerValue = ((int32_T)((int16_T)floorf(((real32_T)
        GvE02DW.u32EncSingleTurn) * E02PST.sInvEncElectMaxCnt))) * ((int32_T)
        E02PST.i16EncElectMaxCnt);
    if (((int64_T)GvE02DW.u32EncSingleTurn) > ((int64_T)E02PST.i16EncElectMaxCnt))
    {
        GvE02DW.i16PstNow = (int16_T)(((int32_T)GvE02DW.u32EncSingleTurn) -
            GvE02DW.i32CntIntegerValue);
    }
    else
    {
        GvE02DW.i16PstNow = (int16_T)GvE02DW.u32EncSingleTurn;
    }

    GvE02DW.i16DiffPostion = GvE02DW.i16PstNow - GvE02DW.i32PstZ;
    Ftn_CalMdata();
    rtb_sWe = (((real32_T)GvE02DW.i16Mdata) * E02PST.sPI2InvPPR) * mBSW_sFreq;
    mMTPST_sWe = ((GvE02DW.sLpfNowZ + rtb_sWe) * E02SWF.sEstWeLb) +
        (GvE02DW.sLpfLowZ * E02SWF.sEstWeLa);
    rtb_sWm = rtb_sWe * E02PST.sInvPolePairs;
    mMTPST_sWm = ((GvE02DW.sLpfNowZ_mxvj + rtb_sWm) * E02SWF.sEstWmLb) +
        (GvE02DW.sLpfLowZ_g0jt * E02SWF.sEstWmLa);
    rtb_sSpdNow = rtb_sWm * 9.54929638F;
    mMTPST_sRpm = ((GvE02DW.sLpfNowZ_oyf4 + rtb_sSpdNow) * E02SWF.sEstSpdLb) +
        (GvE02DW.sLpfLowZ_nv33 * E02SWF.sEstSpdLa);
    rtb_sThetaIntegIn = (((real32_T)GvE02DW.i16PstNow) * E02PST.sPI2InvPPR) -
        E02PST.sThetaOffset;
    if (rtb_sThetaIntegIn < 0.0F)
    {
        rtb_sThetaIntegIn += 6.28318548F;
    }

    if (rtb_sThetaIntegIn > 6.28318548F)
    {
        mMTPST_sTheta = rtb_sThetaIntegIn - 6.28318548F;
    }
    else
    {
        mMTPST_sTheta = rtb_sThetaIntegIn;
    }

    GvE02DW.i32PstZ = GvE02DW.i16PstNow;
    GvE02DW.sLpfNowZ = rtb_sWe;
    GvE02DW.sLpfLowZ = mMTPST_sWe;
    GvE02DW.sLpfNowZ_mxvj = rtb_sWm;
    GvE02DW.sLpfLowZ_g0jt = mMTPST_sWm;
    GvE02DW.sLpfNowZ_oyf4 = rtb_sSpdNow;
    GvE02DW.sLpfLowZ_nv33 = mMTPST_sRpm;
}

/* Model step function */
void e02_MtrCtrl_Pst_step(void)
{
    uint32_T qY;
    if (mEnc_uEND == 35U)
    {
        GvE02DW.u32EncSingleTurn = ((uint32_T)((uint16_T)((mEnc_uABS0 & 255U) |
            ((mEnc_uABS1 & 255U) << 8U)))) | (((uint32_T)((uint16_T)(mEnc_uABS2
            & 255U))) << 16U);
        mMTPST_u32EncMultiTurn = ((uint32_T)((uint16_T)((mEnc_uABM0 & 255U) |
            ((mEnc_uABM1 & 255U) << 8U)))) | (((uint32_T)((uint16_T)(mEnc_uABM2
            & 255U))) << 16U);
        if (mMTPST_u32EncMultiTurn > E02PST.u32EncMultiTurnOffset)
        {
            qY = mMTPST_u32EncMultiTurn - E02PST.u32EncMultiTurnOffset;
            if (qY > mMTPST_u32EncMultiTurn)
            {
                qY = 0UL;
            }
        }
        else
        {
            qY = mMTPST_u32EncMultiTurn + E02PST.u32EncMultiTurnOffset;
            if (qY < mMTPST_u32EncMultiTurn)
            {
                qY = MAX_uint32_T;
            }
        }

        mMTPST_i64TurretPst = ((int64_T)((uint32_T)(GvE02DW.u32EncSingleTurn &
            ((uint32_T)0x0001FFFF)))) | (((int64_T)((uint16_T)qY)) * 131072LL);
    }

    Ftn_SpdMtMethod();
    Ftn_RevCurrDlyCmpsn();
    Ftn_RevAbc2dqe();
}

/* Model initialize function */
void e02_MtrCtrl_Pst_initialize(void)
{
    /* Registration code */

    /* states (dwork) */
    (void) memset((void *)&GvE02DW, 0,
                  sizeof(StrE02DW));

    /* external outputs */
    mMTPST_sWm = 0.0F;
    mMTPST_sWe = 0.0F;
    mMTPST_sRpm = 0.0F;
    mMTPST_sTheta = 0.0F;
    mMTPST_u32EncMultiTurn = 0UL;
    mMTPST_i64TurretPst = 0LL;
    mMTPST_sIde = 0.0F;
    mMTPST_sIqe = 0.0F;
    mMTPST_sIds = 0.0F;
    mMTPST_sIqs = 0.0F;
    GvE02DW.u32EncSingleTurn = 0UL;
    mMTPST_i64TurretPst = 0LL;
    mMTPST_u32EncMultiTurn = 0UL;
    Ftn_SpdMtMethod_Init();
    Ftn_RevAbc2dqe_Init();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
