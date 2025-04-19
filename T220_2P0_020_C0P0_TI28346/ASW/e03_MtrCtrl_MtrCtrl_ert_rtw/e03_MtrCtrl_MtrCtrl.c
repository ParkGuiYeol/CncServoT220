/*
 * File: e03_MtrCtrl_MtrCtrl.c
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

#include "e03_MtrCtrl_MtrCtrl.h"
#include "rtwtypes.h"
#include <math.h>
#include "h01_MdeMgmt.h"
#include "d01_Diaglnteg.h"
#include "b01_OSnScheduler.h"
#include "f01_CommRx1.h"
#include "e02_MtrCtrl_Pst.h"
#include "e01_MtrCtrl_VarGain.h"
#include "c01_MainAdc.h"

/* Exported block signals */
real32_T mCTRL_sIsRef;                 /* '<Root>/bE03MCTRL_mCTRL_sIsRef' */
real32_T mCTRL_sIdeRef;                /* '<Root>/bE03MCTRL_mCTRL_sIdeRef' */
real32_T mCTRL_sIqeRef;                /* '<Root>/bE03MCTRL_mCTRL_sIqeRef' */
real32_T mCTRL_sIde;                   /* '<Root>/bE03MCTRL_mCTRL_sIde' */
real32_T mCTRL_sIqe;                   /* '<Root>/bE03MCTRL_mCTRL_sIqe' */
real32_T mCTRL_sIfTheta;               /* '<Root>/bE03MCTRL_mCTRL_sIfTheta' */
real32_T mCTRL_sIfFreq;                /* '<Root>/bE03MCTRL_mCTRL_sIfFreq' */
real32_T mCTRL_sSpdRefIn;              /* '<Root>/bE03MCTRL_mCTRL_sSpdRefIn' */
real32_T mCTRL_sTqRefIn;               /* '<Root>/bE03MCTRL_mCTRL_sTqRefIn' */
real32_T mCTRL_sVdeRefLow;             /* '<Root>/bE03MCTRL_mCTRL_sVdeRefLow' */
real32_T mCTRL_sVqeRefLow;             /* '<Root>/bE03MCTRL_mCTRL_sVqeRefLow' */
real32_T mCTRL_sVdeRef;                /* '<Root>/bE03MCTRL_mCTRL_sVdeRef' */
real32_T mCTRL_sVqeRef;                /* '<Root>/bE03MCTRL_mCTRL_sVqeRef' */
real32_T mCTRL_sThetaCtrl;             /* '<Root>/bE03MCTRL_mCTRL_sThetaCtrl' */

/* Exported data definition */

/* Definition for custom storage class: FileScope */
static S_E03CCTRL E03CCTRL =
{
    0.003F,
    0.003F,
    0.252538741F,
    4.0F,
    0.0F,
    0.0F,
    0U
} ;                                    /* Referenced by:
                                        * '<S35>/CB_E03CCTRL_sLq'
                                        * '<S36>/CB_E03CCTRL_sKe'
                                        * '<S36>/CB_E03CCTRL_sLd'
                                        */

static S_E03INIT E03INIT =
{
    0.0F,
    0.0F,
    0.0F,
    0.0F,
    0.0F,
    0.0F,
    0.0F,
    0.0F,
    0U
} ;                                    /* Referenced by:
                                        * '<S12>/UnitDelay1'
                                        * '<S14>/UnitDelay1'
                                        * '<S35>/UnitDelay'
                                        * '<S36>/UnitDelay'
                                        * '<S29>/UnitDelay_sIsRefIn'
                                        * '<S47>/UnitDelay1'
                                        * '<S52>/UnitDelay_sIsRefIn'
                                        */

static S_E03LIM E03LIM =
{
    17.3948269F,
    -17.3948269F,
    1000.0F,
    -1000.0F,
    5.73F,
    -5.73F,
    2000.0F,
    -2000.0F,
    0U
} ;                                    /* Referenced by:
                                        * '<S35>/Saturation'
                                        * '<S35>/Saturation1'
                                        * '<S36>/Saturation'
                                        * '<S36>/Saturation1'
                                        * '<S27>/CB_E03LIM_sCurrLim'
                                        * '<S41>/Saturation1'
                                        * '<S41>/Saturation2'
                                        * '<S41>/Saturation3'
                                        * '<S41>/Saturation5'
                                        * '<S47>/Saturation1'
                                        * '<S47>/Saturation2'
                                        * '<S53>/Saturation'
                                        */

static S_E03MCMV E03MCMV =
{
    2.0F,
    10.0F,
    10.0F,
    15.0F,
    0.0F,
    10.0F,
    270.0F,
    1.5F,
    53.3333321F,
    0.0F,
    5.0F,
    0.005F,
    2.6398592F,
    0.015F,
    20.0F,
    0.0F,
    0U
} ;                                    /* Referenced by:
                                        * '<S3>/CB_E03MCMV_sAlign16Angle'
                                        * '<S3>/CB_E03MCMV_sAlign16Vout'
                                        * '<S12>/CB_E03MCMV_sVltSlopFalling'
                                        * '<S12>/CB_E03MCMV_sVltSlopRising'
                                        * '<S14>/CB_E03MCMV_sVltSlopFalling'
                                        * '<S14>/CB_E03MCMV_sVltSlopRising'
                                        * '<S18>/CB_E03MCMV_sAlignCurr'
                                        * '<S18>/CB_E03MCMV_sAlignDeg'
                                        * '<S25>/Constant'
                                        * '<S33>/CB_E03MCMV_sIfCurr'
                                        * '<S33>/CB_E03MCMV_sIfSetFreq'
                                        * '<S33>/CB_E03MCMV_sIfTsec'
                                        * '<S33>/UnitDelay'
                                        * '<S26>/CB_sBetaRiseStep'
                                        * '<S26>/CB_sMaxFreq'
                                        * '<S53>/Gain'
                                        */

static S_E03MTRSWF E03MTRSWF =
{
    0.997758865F,
    0.00112058F,
    0U
} ;                                    /* Referenced by:
                                        * '<S10>/Constant'
                                        * '<S10>/Constant1'
                                        * '<S11>/Constant'
                                        * '<S11>/Constant1'
                                        */

/* Block signals and states (default storage) */
StrE03DW GvE03DW;
static void Ftn_LpfVdqeRef(void);
static void Ftn_SelectionCtrlMde_Init(void);
static void Ftn_SelectionCtrlMde(void);
static void Ftn_VfCtrlSlop_Init(void);
static void Ftn_VfCtrlSlop(void);
static void Ftn_MtrCtrlMdeVFCtrl_Init(void);
static void Ftn_MtrCtrlMdeVFCtrl(void);
static void Ftn_VCtrlSlop_Init(void);
static void Ftn_VCtrlSlop(void);
static void Ftn_MtrCtrlMdeVCtrl_Init(void);
static void Ftn_MtrCtrlMdeVCtrl(void);
static void Ftn_MtrCtrlMdeAlignCtrl(void);
static void Ftn_CurrRefSelection_Init(void);
static void Ftn_CurrRefSelection(void);
static void Ftn_IdControl_Init(void);
static void Ftn_IdControl(void);
static void Ftn_IqControl_Init(void);
static void Ftn_IqControl(void);
static void Ftn_MtrMdeCmCurrCtrl(void);
static void Ftn_SpdCtrl_Init(void);
static void Ftn_SpdCtrl(void);
static void Ftn_SoftSpdMde(void);
static void Ftn_MtrMdeCmSpSpdCtrl_Init(void);
static void Ftn_MtrMdeCmSpSpdCtrl(void);
static void Ftn_PstCtrl(void);
static void Ftn_TqSpdPstCtrl_Init(void);
static void Ftn_TqSpdPstCtrl(void);
static void Ftn_MtrMdeCmCurrAlignCtrl(void);
static void Ftn_MtrMdeCmIFCtrlB(void);
static void Ftn_MtrMdeCmIFCtrl_Init(void);
static void Ftn_MtrMdeCmIFCtrl(void);
static void Ftn_MtrMdeComn_Init(void);
static void Ftn_MtrMdeComn(void);
static void Ftn_MtrCtrlMdeDefault(void);

/* Output and update for atomic system: '<S1>/Ftn_LpfVdqeRef' */
static void Ftn_LpfVdqeRef(void)
{
    mCTRL_sVdeRefLow = ((GvE03DW.sLpfNowZ + mCTRL_sVdeRef) * E03MTRSWF.sVdqeLb)
        + (GvE03DW.sLpfLowZ * E03MTRSWF.sVdqeLa);
    mCTRL_sVqeRefLow = ((GvE03DW.sLpfNowZ_m0tm + mCTRL_sVqeRef) *
                        E03MTRSWF.sVdqeLb) + (GvE03DW.sLpfLowZ_nuzg *
        E03MTRSWF.sVdqeLa);
    GvE03DW.sLpfLowZ = mCTRL_sVdeRefLow;
    GvE03DW.sLpfNowZ = mCTRL_sVdeRef;
    GvE03DW.sLpfLowZ_nuzg = mCTRL_sVqeRefLow;
    GvE03DW.sLpfNowZ_m0tm = mCTRL_sVqeRef;
}

/* System initialize for atomic system: '<S1>/Ftn_SelectionCtrlMde' */
static void Ftn_SelectionCtrlMde_Init(void)
{
    GvE03DW.uAppCtrlMde = 0U;
}

/* Output and update for atomic system: '<S1>/Ftn_SelectionCtrlMde' */
static void Ftn_SelectionCtrlMde(void)
{
    if (mSMDE_uFlagInverterOut == 1U)
    {
        if (mDIAG_uFltStat == 0U)
        {
            GvE03DW.uAppCtrlMde = mSMDE_uMtrCtrlMde;
        }
        else
        {
            GvE03DW.uAppCtrlMde = 0U;
        }
    }
    else
    {
        GvE03DW.uAppCtrlMde = 0U;
    }
}

/* System initialize for atomic system: '<S6>/Ftn_VfCtrlSlop' */
static void Ftn_VfCtrlSlop_Init(void)
{
    GvE03DW.sVqeRefZ_VF = E03INIT.sVfVltSlopVqeRefZ;
}

/* Output and update for atomic system: '<S6>/Ftn_VfCtrlSlop' */
static void Ftn_VfCtrlSlop(void)
{
    real32_T rtb_sBaudMinVF;
    real32_T rtb_sBudMax2VF;
    rtb_sBaudMinVF = GvE03DW.sVqeRefZ_VF - (mBSW_sTime * E03MCMV.sVltSlopFalling);
    rtb_sBudMax2VF = (E03MCMV.sVltSlopRising * mBSW_sTime) + GvE03DW.sVqeRefZ_VF;
    if (mCRX_sVltCurrTqCmd < rtb_sBudMax2VF)
    {
        rtb_sBudMax2VF = mCRX_sVltCurrTqCmd;
    }

    if (rtb_sBudMax2VF > rtb_sBaudMinVF)
    {
        GvE03DW.sVfVqeRef = rtb_sBudMax2VF;
    }
    else
    {
        GvE03DW.sVfVqeRef = rtb_sBaudMinVF;
    }

    GvE03DW.sVqeRefZ_VF = GvE03DW.sVfVqeRef;
}

/* System initialize for action system: '<S1>/Ftn_MtrCtrlMdeVFCtrl' */
static void Ftn_MtrCtrlMdeVFCtrl_Init(void)
{
    Ftn_VfCtrlSlop_Init();
    GvE03DW.sVfThetaRef = 0.0F;
}

/* Output and update for action system: '<S1>/Ftn_MtrCtrlMdeVFCtrl' */
static void Ftn_MtrCtrlMdeVFCtrl(void)
{
    Ftn_VfCtrlSlop();
    GvE03DW.sVfThetaRef += (6.28318548F * mCRX_sFreqBetaCmd) * mBSW_sTime;
    if (GvE03DW.sVfThetaRef > 6.28318548F)
    {
        GvE03DW.sVfThetaRef -= 6.28318548F;
    }
    else
    {
        /*  No Action  */
    }

    GvE03DW.aMerVC[0] = 0.0F;
    GvE03DW.aMerVC[1] = GvE03DW.sVfVqeRef;
    GvE03DW.aMerVC[2] = GvE03DW.sVfThetaRef;
}

/* System initialize for atomic system: '<S5>/Ftn_VCtrlSlop' */
static void Ftn_VCtrlSlop_Init(void)
{
    GvE03DW.sVqeRefZ_V = E03INIT.sVVltSlopVqeRefZ;
}

/* Output and update for atomic system: '<S5>/Ftn_VCtrlSlop' */
static void Ftn_VCtrlSlop(void)
{
    real32_T rtb_sBaudMinV;
    real32_T rtb_sBudMax2V;
    rtb_sBaudMinV = GvE03DW.sVqeRefZ_V - (mBSW_sTime * E03MCMV.sVltSlopFalling);
    rtb_sBudMax2V = (E03MCMV.sVltSlopRising * mBSW_sTime) + GvE03DW.sVqeRefZ_V;
    if (mCRX_sVltCurrTqCmd < rtb_sBudMax2V)
    {
        rtb_sBudMax2V = mCRX_sVltCurrTqCmd;
    }

    if (rtb_sBudMax2V > rtb_sBaudMinV)
    {
        GvE03DW.sVVqeRef = rtb_sBudMax2V;
    }
    else
    {
        GvE03DW.sVVqeRef = rtb_sBaudMinV;
    }

    GvE03DW.sVqeRefZ_V = GvE03DW.sVVqeRef;
}

/* System initialize for action system: '<S1>/Ftn_MtrCtrlMdeVCtrl' */
static void Ftn_MtrCtrlMdeVCtrl_Init(void)
{
    Ftn_VCtrlSlop_Init();
}

/* Output and update for action system: '<S1>/Ftn_MtrCtrlMdeVCtrl' */
static void Ftn_MtrCtrlMdeVCtrl(void)
{
    Ftn_VCtrlSlop();
    GvE03DW.aMerVC[0] = 0.0F;
    GvE03DW.aMerVC[1] = GvE03DW.sVVqeRef;
    GvE03DW.aMerVC[2] = mMTPST_sTheta;
}

/* Output and update for action system: '<S1>/Ftn_MtrCtrlMdeAlignCtrl' */
static void Ftn_MtrCtrlMdeAlignCtrl(void)
{
    GvE03DW.aMerVC[0] = 0.0F;
    GvE03DW.aMerVC[1] = E03MCMV.sAlign16Vout;
    GvE03DW.aMerVC[2] = E03MCMV.sAlign16Angle * 0.0174532924F;
}

/* System initialize for atomic system: '<S7>/Ftn_CurrRefSelection' */
static void Ftn_CurrRefSelection_Init(void)
{
    GvE03DW.sIsRefIn2 = (real_T)E03INIT.sIsRefInZ;
    GvE03DW.sIFreqBetaCmd = 0.0F;
}

/* Output and update for atomic system: '<S7>/Ftn_CurrRefSelection' */
static void Ftn_CurrRefSelection(void)
{
    real_T rtb_sBaudMin;
    real_T rtb_sBudMax2;
    real32_T temp1;
    if (mCTRL_sIsRef > E03LIM.sCurrLim)
    {
        rtb_sBaudMin = (real_T)E03LIM.sCurrLim;
    }
    else if (mCTRL_sIsRef < (-E03LIM.sCurrLim))
    {
        rtb_sBaudMin = (real_T)((real32_T)(-E03LIM.sCurrLim));
    }
    else
    {
        rtb_sBaudMin = (real_T)mCTRL_sIsRef;
    }

    if (((int32_T)E03MCMV.uSoftMdeCurr) == 2L)
    {
        rtb_sBudMax2 = ((real_T)((real32_T)(mBSW_sTime * mMCVG_sCurrSlpRising)))
            + GvE03DW.sIsRefIn2;
        if (rtb_sBaudMin < rtb_sBudMax2)
        {
            rtb_sBudMax2 = rtb_sBaudMin;
        }

        rtb_sBaudMin = GvE03DW.sIsRefIn2 - ((real_T)((real32_T)(mBSW_sTime *
            mMCVG_sCurrSlpFalling)));
        if (rtb_sBudMax2 > rtb_sBaudMin)
        {
            rtb_sBaudMin = rtb_sBudMax2;
        }

        GvE03DW.sIsRefIn2 = rtb_sBaudMin;
    }

    if (GvE03DW.uAppCtrlMde == 256U)
    {
        temp1 = (GvE03DW.sIFreqBetaCmd + 90.0F) * 0.0174532924F;
        GvE03DW.sIFreqBetaCmd += E03MCMV.sBetaRiseStep;
        if (GvE03DW.sIFreqBetaCmd >= E03MCMV.sMaxFreq)
        {
            GvE03DW.sIFreqBetaCmd = E03MCMV.sMaxFreq;
        }
        else
        {
            /* No Action */
        }
    }
    else
    {
        GvE03DW.sIFreqBetaCmd = 0.0F;
        if (GvE03DW.uAppCtrlMde == 64U)
        {
            temp1 = 1.57079637F;
        }
        else
        {
            temp1 = (mCRX_sFreqBetaCmd + 90.0F) * 0.0174532924F;
        }
    }

    mCTRL_sIdeRef = (real32_T)((real_T)(rtb_sBaudMin * ((real_T)cosf(temp1))));
    mCTRL_sIqeRef = (real32_T)((real_T)(rtb_sBaudMin * ((real_T)sinf(temp1))));
    mCTRL_sIde = GvE03DW.sIde;
    mCTRL_sIqe = GvE03DW.sIqe;
    GvE03DW.sTheta = GvE03DW.sAppTheta;
}

/* System initialize for atomic system: '<S21>/Ftn_IdControl' */
static void Ftn_IdControl_Init(void)
{
    GvE03DW.sIdeIntegZ = E03INIT.sIdeCtrlIntegZ;
}

/*
 * Output and update for atomic system: '<S21>/Ftn_IdControl'
 * Block description for: '<S21>/Ftn_IdControl'
 *   /+ d-Axis Current Control +/
 */
static void Ftn_IdControl(void)
{
    real32_T rtb_sIdErr;
    real32_T u0;
    rtb_sIdErr = mCTRL_sIdeRef - mCTRL_sIde;
    u0 = (mBSW_sTime * (mMCVG_sCCG_Kid * rtb_sIdErr)) + GvE03DW.sIdeIntegZ;
    if (u0 > E03LIM.sVrefLim)
    {
        GvE03DW.sIdeIntegLimited = E03LIM.sVrefLim;
    }
    else if (u0 < E03LIM.sNegVrefLim)
    {
        GvE03DW.sIdeIntegLimited = E03LIM.sNegVrefLim;
    }
    else
    {
        GvE03DW.sIdeIntegLimited = u0;
    }

    GvE03DW.sIdKpErr = mMCVG_sCCG_Kpd * rtb_sIdErr;
    GvE03DW.sIdFFRlt = (mCTRL_sIqe * mMTPST_sWe) * E03CCTRL.sLq;
    u0 = (GvE03DW.sIdeIntegLimited + GvE03DW.sIdKpErr) - GvE03DW.sIdFFRlt;
    if (u0 > E03LIM.sVrefLim)
    {
        GvE03DW.sVdeRef = E03LIM.sVrefLim;
    }
    else if (u0 < E03LIM.sNegVrefLim)
    {
        GvE03DW.sVdeRef = E03LIM.sNegVrefLim;
    }
    else
    {
        GvE03DW.sVdeRef = u0;
    }

    GvE03DW.sIdeIntegZ = GvE03DW.sIdeIntegLimited;
}

/* System initialize for atomic system: '<S21>/Ftn_IqControl' */
static void Ftn_IqControl_Init(void)
{
    GvE03DW.sIqeIntegZ = E03INIT.sIqeCtrlIntegZ;
}

/*
 * Output and update for atomic system: '<S21>/Ftn_IqControl'
 * Block description for: '<S21>/Ftn_IqControl'
 *   /+ q-Axis Current Control +/
 */
static void Ftn_IqControl(void)
{
    real32_T rtb_sIqErr;
    real32_T u0;
    rtb_sIqErr = mCTRL_sIqeRef - mCTRL_sIqe;
    u0 = (mBSW_sTime * (mMCVG_sCCG_Kiq * rtb_sIqErr)) + GvE03DW.sIqeIntegZ;
    if (u0 > E03LIM.sVrefLim)
    {
        GvE03DW.sIqeIntegLimited = E03LIM.sVrefLim;
    }
    else if (u0 < E03LIM.sNegVrefLim)
    {
        GvE03DW.sIqeIntegLimited = E03LIM.sNegVrefLim;
    }
    else
    {
        GvE03DW.sIqeIntegLimited = u0;
    }

    GvE03DW.sIqKpErr = mMCVG_sCCG_Kpq * rtb_sIqErr;
    GvE03DW.sIqFFRlt = (mCTRL_sIde * (mMTPST_sWe * E03CCTRL.sLd)) + (mMTPST_sWm *
        E03CCTRL.sKe);
    u0 = (GvE03DW.sIqeIntegLimited + GvE03DW.sIqKpErr) + GvE03DW.sIqFFRlt;
    if (u0 > E03LIM.sVrefLim)
    {
        GvE03DW.sVqeRef = E03LIM.sVrefLim;
    }
    else if (u0 < E03LIM.sNegVrefLim)
    {
        GvE03DW.sVqeRef = E03LIM.sNegVrefLim;
    }
    else
    {
        GvE03DW.sVqeRef = u0;
    }

    GvE03DW.sIqeIntegZ = GvE03DW.sIqeIntegLimited;
}

/*
 * Output and update for action system: '<S7>/Ftn_MtrMdeCmCurrCtrl'
 * Block description for: '<S7>/Ftn_MtrMdeCmCurrCtrl'
 *   Current Control
 */
static void Ftn_MtrMdeCmCurrCtrl(void)
{
    GvE03DW.aMerOutCCurrTheta[0] = mCRX_sVltCurrTqCmd;
    GvE03DW.aMerOutCCurrTheta[1] = mMTPST_sIde;
    GvE03DW.aMerOutCCurrTheta[2] = mMTPST_sIqe;
    GvE03DW.aMerOutCCurrTheta[3] = mMTPST_sTheta;
}

/* System initialize for action system: '<S39>/Ftn_SpdCtrl' */
static void Ftn_SpdCtrl_Init(void)
{
    GvE03DW.sTqRef_IntegZ = E03INIT.sTqRefInit;
}

/*
 * Output and update for action system: '<S39>/Ftn_SpdCtrl'
 * Block description for: '<S39>/Ftn_SpdCtrl'
 *   /+ d-Axis Current Control +/
 */
static void Ftn_SpdCtrl(void)
{
    real32_T rtb_sTqRef_IntegLimited;
    real32_T rtb_sWm_err;
    rtb_sWm_err = (0.104719758F * mCTRL_sSpdRefIn) - mMTPST_sWm;
    rtb_sTqRef_IntegLimited = (((rtb_sWm_err - GvE03DW.sSpdAntiValZ) *
        mMCVG_sSCG_Ki) * mBSW_sOutloopTime) + GvE03DW.sTqRef_IntegZ;
    if (rtb_sTqRef_IntegLimited > E03LIM.sMaxTqSet)
    {
        rtb_sTqRef_IntegLimited = E03LIM.sMaxTqSet;
    }
    else if (rtb_sTqRef_IntegLimited < E03LIM.sNegMaxTqSet)
    {
        rtb_sTqRef_IntegLimited = E03LIM.sNegMaxTqSet;
    }
    else
    {
        /* no actions */
    }

    rtb_sWm_err = rtb_sTqRef_IntegLimited + (rtb_sWm_err * mMCVG_sSCG_Kp);
    if (rtb_sWm_err > E03LIM.sMaxTqSet)
    {
        GvE03DW.sSpdCtrlMdeTqRefLimited = E03LIM.sMaxTqSet;
    }
    else if (rtb_sWm_err < E03LIM.sNegMaxTqSet)
    {
        GvE03DW.sSpdCtrlMdeTqRefLimited = E03LIM.sNegMaxTqSet;
    }
    else
    {
        GvE03DW.sSpdCtrlMdeTqRefLimited = rtb_sWm_err;
    }

    GvE03DW.sSpdAntiValZ = mMCVG_sSCG_Ka * (rtb_sWm_err -
        GvE03DW.sSpdCtrlMdeTqRefLimited);
    GvE03DW.sTqRef_IntegZ = rtb_sTqRef_IntegLimited;
}

/* Output and update for action system: '<S39>/Ftn_SoftSpdMde' */
static void Ftn_SoftSpdMde(void)
{
    real_T rtb_sSpdRefLimited;
    real32_T rtb_sBaudMax1;
    real32_T rtb_sBaudMin;
    if (GvE03DW.sSpdRef > mSMDE_sSpdLimit)
    {
        rtb_sSpdRefLimited = (real_T)mSMDE_sSpdLimit;
    }
    else if (GvE03DW.sSpdRef < (-mSMDE_sSpdLimit))
    {
        rtb_sSpdRefLimited = (real_T)((real32_T)(-mSMDE_sSpdLimit));
    }
    else
    {
        rtb_sSpdRefLimited = (real_T)GvE03DW.sSpdRef;
    }

    rtb_sBaudMin = GvE03DW.Delay_DSTATE_fsbd;
    rtb_sBaudMax1 = (mBSW_sOutloopTime * mMCVG_sSpdSlpRising) + rtb_sBaudMin;
    if (rtb_sSpdRefLimited >= ((real_T)rtb_sBaudMax1))
    {
        rtb_sSpdRefLimited = (real_T)rtb_sBaudMax1;
    }

    rtb_sBaudMin -= mBSW_sOutloopTime * mMCVG_sSpdSlpFalling;
    if (rtb_sSpdRefLimited > ((real_T)rtb_sBaudMin))
    {
        mCTRL_sSpdRefIn = (real32_T)rtb_sSpdRefLimited;
    }
    else
    {
        mCTRL_sSpdRefIn = rtb_sBaudMin;
    }

    GvE03DW.Delay_DSTATE_fsbd = mCTRL_sSpdRefIn;
}

/* System initialize for action system: '<S38>/Ftn_MtrMdeCmSpSpdCtrl' */
static void Ftn_MtrMdeCmSpSpdCtrl_Init(void)
{
    Ftn_SpdCtrl_Init();
}

/* Output and update for action system: '<S38>/Ftn_MtrMdeCmSpSpdCtrl' */
static void Ftn_MtrMdeCmSpSpdCtrl(void)
{
    if (mSched_uFlagSpdCtrl == 1U)
    {
        Ftn_SpdCtrl();
    }
    else if (mSched_uFlagSpdSlop == 1U)
    {
        Ftn_SoftSpdMde();
    }
    else
    {
        /* no actions */
    }

    GvE03DW.TqRefLimited = GvE03DW.sSpdCtrlMdeTqRefLimited;
}

/* Output and update for action system: '<S38>/Ftn_PstCtrl' */
static void Ftn_PstCtrl(void)
{
    real32_T rtb_sPstCtrlSpdRefUlimited3;
    real32_T rtb_sPstKiCtrlRlt;
    real32_T rtb_sPsterr;
    real32_T u2;
    real32_T u2_tmp;
    int16_T tmp;
    rtb_sPsterr = ((real32_T)((int64_T)(mSMDE_i64PstRef - mMTPST_i64TurretPst)))
        * 0.0001F;
    rtb_sPstKiCtrlRlt = (mBSW_sTimePstCtrl * ((rtb_sPsterr -
                           GvE03DW.Delay1_DSTATE) * mMCVG_sPCG_Ki)) +
        GvE03DW.Delay2_DSTATE;
    rtb_sPstCtrlSpdRefUlimited3 = E03LIM.sNegMaxSpdSet * 0.05F;
    u2 = E03LIM.sMaxSpdSet * 0.05F;
    if (rtb_sPstKiCtrlRlt > u2)
    {
        rtb_sPstKiCtrlRlt = u2;
    }
    else if (rtb_sPstKiCtrlRlt < rtb_sPstCtrlSpdRefUlimited3)
    {
        rtb_sPstKiCtrlRlt = rtb_sPstCtrlSpdRefUlimited3;
    }
    else
    {
        /* no actions */
    }

    rtb_sPstCtrlSpdRefUlimited3 = rtb_sPsterr * mMCVG_sPCG_Kp;
    u2 = E03LIM.sNegMaxSpdSet * 1.5F;
    u2_tmp = E03LIM.sMaxSpdSet * 1.5F;
    if (rtb_sPstCtrlSpdRefUlimited3 > u2_tmp)
    {
        GvE03DW.sPstKpCtrlRlt = u2_tmp;
    }
    else if (rtb_sPstCtrlSpdRefUlimited3 < u2)
    {
        GvE03DW.sPstKpCtrlRlt = u2;
    }
    else
    {
        GvE03DW.sPstKpCtrlRlt = rtb_sPstCtrlSpdRefUlimited3;
    }

    rtb_sPstCtrlSpdRefUlimited3 = ((rtb_sPsterr - GvE03DW.Delay_DSTATE) *
        mMCVG_sPCG_Kd) * mBSW_sInvTimePstCtrl;
    if (rtb_sPstCtrlSpdRefUlimited3 > u2_tmp)
    {
        GvE03DW.sPstKdCtrlRlt = u2_tmp;
    }
    else if (rtb_sPstCtrlSpdRefUlimited3 < u2)
    {
        GvE03DW.sPstKdCtrlRlt = u2;
    }
    else
    {
        GvE03DW.sPstKdCtrlRlt = rtb_sPstCtrlSpdRefUlimited3;
    }

    if (mMTPST_sWm < 0.0F)
    {
        tmp = -1;
    }
    else
    {
        tmp = (mMTPST_sWm > 0.0F) ? ((int16_T)1) : ((int16_T)0);
    }

    rtb_sPstCtrlSpdRefUlimited3 = ((rtb_sPstKiCtrlRlt + GvE03DW.sPstKpCtrlRlt) +
        GvE03DW.sPstKdCtrlRlt) - (((mMTPST_sWm * mMTPST_sWm) * ((real32_T)tmp)) *
        mMCVG_sPCG_Apst);
    if (rtb_sPstCtrlSpdRefUlimited3 > E03LIM.sMaxSpdSet)
    {
        GvE03DW.sSpdRefPstMde = E03LIM.sMaxSpdSet;
    }
    else if (rtb_sPstCtrlSpdRefUlimited3 < E03LIM.sNegMaxSpdSet)
    {
        GvE03DW.sSpdRefPstMde = E03LIM.sNegMaxSpdSet;
    }
    else
    {
        GvE03DW.sSpdRefPstMde = rtb_sPstCtrlSpdRefUlimited3;
    }

    GvE03DW.sSpdRef = GvE03DW.sSpdRefPstMde;
    GvE03DW.Delay1_DSTATE = mMCVG_sPCG_Ka * (rtb_sPstCtrlSpdRefUlimited3 -
        GvE03DW.sSpdRefPstMde);
    GvE03DW.Delay2_DSTATE = rtb_sPstKiCtrlRlt;
    GvE03DW.Delay_DSTATE = rtb_sPsterr;
}

/* System initialize for atomic system: '<S23>/Ftn_TqSpdPstCtrl' */
static void Ftn_TqSpdPstCtrl_Init(void)
{
    GvE03DW.sIsRefIn2_hdgx = E03INIT.sIsRefInZ;
    GvE03DW.sSpdRef = 0.0F;
    Ftn_MtrMdeCmSpSpdCtrl_Init();
}

/* Output and update for atomic system: '<S23>/Ftn_TqSpdPstCtrl' */
static void Ftn_TqSpdPstCtrl(void)
{
    real32_T rtb_Saturation;
    real32_T rtb_sBaudMin;
    if ((GvE03DW.uAppCtrlMde == 32U) && (((uint16_T)mSched_i32CntForSch) == 1U))
    {
        Ftn_PstCtrl();
    }
    else if (GvE03DW.uAppCtrlMde == 16U)
    {
        GvE03DW.sSpdRef = mSMDE_sSpdRef;
    }
    else
    {
        /* no actions */
    }

    if ((GvE03DW.uAppCtrlMde == 16U) || (GvE03DW.uAppCtrlMde == 32U))
    {
        Ftn_MtrMdeCmSpSpdCtrl();
    }
    else
    {
        GvE03DW.TqRefLimited = mCRX_sVltCurrTqCmd;
    }

    rtb_Saturation = (mBSW_sTime * mMCVG_sTqSlpRising) + GvE03DW.sIsRefIn2_hdgx;
    if (GvE03DW.TqRefLimited < rtb_Saturation)
    {
        rtb_Saturation = GvE03DW.TqRefLimited;
    }

    rtb_sBaudMin = GvE03DW.sIsRefIn2_hdgx - (mBSW_sTime * mMCVG_sTqSlpFalling);
    if (rtb_Saturation > rtb_sBaudMin)
    {
        mCTRL_sTqRefIn = rtb_Saturation;
    }
    else
    {
        mCTRL_sTqRefIn = rtb_sBaudMin;
    }

    rtb_Saturation = E03MCMV.sInvKt * mCTRL_sTqRefIn;
    if (rtb_Saturation > E03LIM.sCurrLim)
    {
        GvE03DW.aMerOutCCurrTheta[0] = E03LIM.sCurrLim;
    }
    else if (rtb_Saturation < E03LIM.sNegCurrLim)
    {
        GvE03DW.aMerOutCCurrTheta[0] = E03LIM.sNegCurrLim;
    }
    else
    {
        GvE03DW.aMerOutCCurrTheta[0] = rtb_Saturation;
    }

    GvE03DW.aMerOutCCurrTheta[1] = mMTPST_sIde;
    GvE03DW.aMerOutCCurrTheta[2] = mMTPST_sIqe;
    GvE03DW.aMerOutCCurrTheta[3] = mMTPST_sTheta;
    GvE03DW.sIsRefIn2_hdgx = mCTRL_sTqRefIn;
}

/* Output and update for action system: '<S7>/Ftn_MtrMdeCmCurrAlignCtrl' */
static void Ftn_MtrMdeCmCurrAlignCtrl(void)
{
    real32_T rtb_sThetaAlignCtrl;
    GvE03DW.sIds_gxrm = 0.333333343F * (((2.0F * mMsens_sIa) - mMsens_sIb) -
        mMsens_sIc);
    rtb_sThetaAlignCtrl = E03MCMV.sAlignDeg * 0.0174532924F;
    GvE03DW.sIdqCosTheta = cosf(rtb_sThetaAlignCtrl);
    GvE03DW.sIqs_pe32 = 0.577350259F * (mMsens_sIb - mMsens_sIc);
    GvE03DW.sIdqSinTheta = sinf(rtb_sThetaAlignCtrl);
    GvE03DW.aMerOutCCurrTheta[0] = E03MCMV.sAlignCurr;
    GvE03DW.aMerOutCCurrTheta[1] = (GvE03DW.sIds_gxrm * GvE03DW.sIdqCosTheta) +
        (GvE03DW.sIqs_pe32 * GvE03DW.sIdqSinTheta);
    GvE03DW.aMerOutCCurrTheta[2] = (GvE03DW.sIqs_pe32 * GvE03DW.sIdqCosTheta) -
        (GvE03DW.sIds_gxrm * GvE03DW.sIdqSinTheta);
    GvE03DW.aMerOutCCurrTheta[3] = rtb_sThetaAlignCtrl;
}

/* Output and update for atomic system: '<S20>/Ftn_MtrMdeCmIFCtrlB' */
static void Ftn_MtrMdeCmIFCtrlB(void)
{
    real32_T rtb_sIdqCosTheta;
    real32_T rtb_sIdqSinTheta;
    GvE03DW.sIds = 0.333333343F * (((2.0F * mMsens_sIa) - mMsens_sIb) -
        mMsens_sIc);
    GvE03DW.mCTRL_sIfTheta_daj2 = mCTRL_sIfTheta;
    rtb_sIdqCosTheta = cosf(GvE03DW.mCTRL_sIfTheta_daj2);
    GvE03DW.sIqs = 0.577350259F * (mMsens_sIb - mMsens_sIc);
    rtb_sIdqSinTheta = sinf(GvE03DW.mCTRL_sIfTheta_daj2);
    GvE03DW.sIde_esgf = (GvE03DW.sIds * rtb_sIdqCosTheta) + (GvE03DW.sIqs *
        rtb_sIdqSinTheta);
    GvE03DW.sIqe_nbmc = (GvE03DW.sIqs * rtb_sIdqCosTheta) - (GvE03DW.sIds *
        rtb_sIdqSinTheta);
    GvE03DW.sIfCurr = E03MCMV.sIfCurr;
}

/* System initialize for action system: '<S7>/Ftn_MtrMdeCmIFCtrl' */
static void Ftn_MtrMdeCmIFCtrl_Init(void)
{
    GvE03DW.sIfThetaZ = E03MCMV.sIfInitTheta;
    mCTRL_sIfFreq = 0.0F;
    mCTRL_sIfTheta = 0.0F;
}

/*
 * Output and update for action system: '<S7>/Ftn_MtrMdeCmIFCtrl'
 * Block description for: '<S7>/Ftn_MtrMdeCmIFCtrl'
 *   IF_Current
 */
static void Ftn_MtrMdeCmIFCtrl(void)
{
    if (mSMDE_sIfFreqSeqOut < E03MCMV.sIfSetFreq)
    {
        mCTRL_sIfFreq = mSMDE_sIfFreqSeqOut + ((E03MCMV.sIfSetFreq * mBSW_sTime)
            / E03MCMV.sIfTsec);
    }
    else
    {
        /*  no action  */
    }

    mCTRL_sIfTheta = GvE03DW.sIfThetaZ + ((6.28318548F * mCTRL_sIfFreq) *
        mBSW_sTime);
    if (mCTRL_sIfTheta > 6.28318548F)
    {
        mCTRL_sIfTheta -= 6.28318548F;
    }
    else
    {
        /*  no action  */
    }

    Ftn_MtrMdeCmIFCtrlB();
    GvE03DW.aMerOutCCurrTheta[0] = GvE03DW.sIfCurr;
    GvE03DW.aMerOutCCurrTheta[1] = GvE03DW.sIde_esgf;
    GvE03DW.aMerOutCCurrTheta[2] = GvE03DW.sIqe_nbmc;
    GvE03DW.aMerOutCCurrTheta[3] = GvE03DW.mCTRL_sIfTheta_daj2;
    GvE03DW.sIfThetaZ = mCTRL_sIfTheta;
}

/* System initialize for action system: '<S1>/Ftn_MtrMdeComn' */
static void Ftn_MtrMdeComn_Init(void)
{
    Ftn_TqSpdPstCtrl_Init();
    Ftn_MtrMdeCmIFCtrl_Init();
    GvE03DW.aMerOutCCurrTheta[0] = 0.0F;
    GvE03DW.aMerOutCCurrTheta[1] = 0.0F;
    GvE03DW.aMerOutCCurrTheta[2] = 0.0F;
    GvE03DW.aMerOutCCurrTheta[3] = 0.0F;
    mCTRL_sIsRef = 0.0F;
    Ftn_CurrRefSelection_Init();
    Ftn_IdControl_Init();
    Ftn_IqControl_Init();
}

/* Output and update for action system: '<S1>/Ftn_MtrMdeComn' */
static void Ftn_MtrMdeComn(void)
{
    switch ((int32_T)GvE03DW.uAppCtrlMde)
    {
      case 4L:
        Ftn_MtrMdeCmCurrCtrl();
        break;

      case 8L:
      case 16L:
      case 32L:
        Ftn_TqSpdPstCtrl();
        break;

      case 128L:
        Ftn_MtrMdeCmCurrAlignCtrl();
        break;

      default:
        Ftn_MtrMdeCmIFCtrl();
        break;
    }

    mCTRL_sIsRef = GvE03DW.aMerOutCCurrTheta[0];
    GvE03DW.sIde = GvE03DW.aMerOutCCurrTheta[1];
    GvE03DW.sIqe = GvE03DW.aMerOutCCurrTheta[2];
    GvE03DW.sAppTheta = GvE03DW.aMerOutCCurrTheta[3];
    Ftn_CurrRefSelection();
    Ftn_IdControl();
    Ftn_IqControl();
    GvE03DW.aMerVC[0] = GvE03DW.sVdeRef;
    GvE03DW.aMerVC[1] = GvE03DW.sVqeRef;
    GvE03DW.aMerVC[2] = GvE03DW.sTheta;
}

/* Output and update for action system: '<S1>/Ftn_MtrCtrlMdeDefault' */
static void Ftn_MtrCtrlMdeDefault(void)
{
    GvE03DW.aMerVC[0] = 0.0F;
    GvE03DW.aMerVC[1] = 0.0F;
    GvE03DW.aMerVC[2] = 0.0F;
}

/* Model step function */
void e03_MtrCtrl_MtrCtrl_step(void)
{
    Ftn_SelectionCtrlMde();
    switch ((int32_T)GvE03DW.uAppCtrlMde)
    {
      case 1L:
        Ftn_MtrCtrlMdeVFCtrl();
        break;

      case 2L:
        Ftn_MtrCtrlMdeVCtrl();
        break;

      case 64L:
        Ftn_MtrCtrlMdeAlignCtrl();
        break;

      case 4L:
      case 8L:
      case 16L:
      case 32L:
      case 128L:
      case 256L:
        Ftn_MtrMdeComn();
        break;

      default:
        Ftn_MtrCtrlMdeDefault();
        break;
    }

    mCTRL_sVdeRef = GvE03DW.aMerVC[0];
    mCTRL_sVqeRef = GvE03DW.aMerVC[1];
    Ftn_LpfVdqeRef();
    mCTRL_sThetaCtrl = GvE03DW.aMerVC[2];
}

/* Model initialize function */
void e03_MtrCtrl_MtrCtrl_initialize(void)
{
    /* Registration code */

    /* states (dwork) */
    (void) memset((void *)&GvE03DW, 0,
                  sizeof(StrE03DW));

    /* external outputs */
    mCTRL_sIsRef = 0.0F;
    mCTRL_sIdeRef = 0.0F;
    mCTRL_sIqeRef = 0.0F;
    mCTRL_sIde = 0.0F;
    mCTRL_sIqe = 0.0F;
    mCTRL_sIfTheta = 0.0F;
    mCTRL_sIfFreq = 0.0F;
    mCTRL_sSpdRefIn = 0.0F;
    mCTRL_sTqRefIn = 0.0F;
    mCTRL_sVdeRefLow = 0.0F;
    mCTRL_sVqeRefLow = 0.0F;
    mCTRL_sVdeRef = 0.0F;
    mCTRL_sVqeRef = 0.0F;
    mCTRL_sThetaCtrl = 0.0F;
    Ftn_SelectionCtrlMde_Init();
    Ftn_MtrMdeComn_Init();
    Ftn_MtrCtrlMdeVFCtrl_Init();
    Ftn_MtrCtrlMdeVCtrl_Init();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
