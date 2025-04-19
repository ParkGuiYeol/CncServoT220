/*
 * File: e04_MtrCtrl_PwmSet.c
 *
 * Code generated for Simulink model 'e04_MtrCtrl_PwmSet'.
 *
 * Model version                  : 7.213
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Apr 19 16:31:18 2025
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

#include "e04_MtrCtrl_PwmSet.h"
#include <math.h>
#include "rtwtypes.h"
#include "e03_MtrCtrl_MtrCtrl.h"
#include "c01_MainAdc.h"
#include "e02_MtrCtrl_Pst.h"

/* Exported block signals */
real32_T mGPwm_sVanRef;                /* '<Root>/bE04GPWM_mGPwm_sVanRef' */
real32_T mGPwm_sVbnRef;                /* '<Root>/bE04GPWM_mGPwm_sVbnRef' */
real32_T mGPwm_sVcnRef;                /* '<Root>/bE04GPWM_mGPwm_sVcnRef' */
real32_T mGPwm_sMiLow;                 /* '<Root>/bE04GPWM_mGPwm_sMiLow' */
real32_T mGPwm_sThetaCtrl;             /* '<Root>/bE04GPWM_mGPwm_sThetaCtrl' */

/* Exported data definition */

/* Definition for custom storage class: FileScope */
static S_E04SWF E04SWF =
{
    0.987512112F,
    0.00624395348F,
    0U
} ;                                    /* Referenced by:
                                        * '<S6>/Constant'
                                        * '<S6>/Constant1'
                                        */

static S_E04VTDC E04VTDC =
{
    0.104719758F,
    0.0F,
    0.00033333333F,
    0.0F,
    0U
} ;                                    /* Referenced by:
                                        * '<S5>/Constant14'
                                        * '<S5>/Constant15'
                                        * '<S5>/Saturation'
                                        */

/* Block signals and states (default storage) */
StrE04DW GvE04DW;
static void Ftn_CalModulationIndex(void);
static void Ftn_FindMinMax(void);
static void Ftn_SVPWM(void);
static void Ftn_Vdqe2Vabc(void);
static void Ftn_VltDelayCompensation(void);

/* Output and update for atomic system: '<Root>/Ftn_CalModulationIndex' */
static void Ftn_CalModulationIndex(void)
{
    real32_T rtb_sMI;
    rtb_sMI = (sqrtf((mCTRL_sVdeRef * mCTRL_sVdeRef) + (mCTRL_sVqeRef *
                 mCTRL_sVqeRef)) * 2.0F) * mMsens_sInvHVdcLow;
    mGPwm_sMiLow = ((GvE04DW.sLpfNowZ + rtb_sMI) * E04SWF.sVltRatioLb) +
        (GvE04DW.sLpfLowZ * E04SWF.sVltRatioLa);
    GvE04DW.sLpfNowZ = rtb_sMI;
    GvE04DW.sLpfLowZ = mGPwm_sMiLow;
}

/* Output and update for atomic system: '<Root>/Ftn_FindMinMax' */
static void Ftn_FindMinMax(void)
{
    if (mGPwm_sVanRef > mGPwm_sVbnRef)
    {
        GvE04DW.sTempVmax2 = mGPwm_sVanRef;
    }
    else
    {
        GvE04DW.sTempVmax2 = mGPwm_sVbnRef;
    }

    if (GvE04DW.sTempVmax2 > mGPwm_sVcnRef)
    {
        GvE04DW.sVrMax = GvE04DW.sTempVmax2;
    }
    else
    {
        GvE04DW.sVrMax = mGPwm_sVcnRef;
    }

    if (mGPwm_sVanRef < mGPwm_sVbnRef)
    {
        GvE04DW.sTempVmin2 = mGPwm_sVanRef;
    }
    else
    {
        GvE04DW.sTempVmin2 = mGPwm_sVbnRef;
    }

    if (GvE04DW.sTempVmin2 < mGPwm_sVcnRef)
    {
        GvE04DW.sVrMin = GvE04DW.sTempVmin2;
    }
    else
    {
        GvE04DW.sVrMin = mGPwm_sVcnRef;
    }
}

/* Output and update for atomic system: '<Root>/Ftn_SVPWM' */
static void Ftn_SVPWM(void)
{
    real32_T rtb_sOverModultationGain;
    real32_T rtb_sVsn;
    rtb_sOverModultationGain = GvE04DW.sVrMax - GvE04DW.sVrMin;
    if (rtb_sOverModultationGain < 1.0E-5F)
    {
        rtb_sOverModultationGain = 1.0E-5F;
    }

    if (rtb_sOverModultationGain > mMsens_sHVdcLow)
    {
        rtb_sOverModultationGain = mMsens_sHVdcLow / rtb_sOverModultationGain;
    }
    else
    {
        rtb_sOverModultationGain = 1.0F;
    }

    rtb_sVsn = (-0.5F * (GvE04DW.sVrMax + GvE04DW.sVrMin)) *
        rtb_sOverModultationGain;
    mGPwm_sVanRef = (mGPwm_sVanRef * rtb_sOverModultationGain) + rtb_sVsn;
    mGPwm_sVbnRef = (mGPwm_sVbnRef * rtb_sOverModultationGain) + rtb_sVsn;
    mGPwm_sVcnRef = (mGPwm_sVcnRef * rtb_sOverModultationGain) + rtb_sVsn;
}

/* Output and update for atomic system: '<Root>/Ftn_Vdqe2Vabc' */
static void Ftn_Vdqe2Vabc(void)
{
    real32_T rtb_sCosTheta;
    real32_T rtb_sSinTheta;
    rtb_sCosTheta = cosf(mGPwm_sThetaCtrl);
    rtb_sSinTheta = sinf(mGPwm_sThetaCtrl);
    mGPwm_sVanRef = (mCTRL_sVdeRef * rtb_sCosTheta) - (mCTRL_sVqeRef *
        rtb_sSinTheta);
    rtb_sCosTheta = 1.73205078F * ((mCTRL_sVdeRef * rtb_sSinTheta) +
        (mCTRL_sVqeRef * rtb_sCosTheta));
    mGPwm_sVbnRef = -0.5F * (mGPwm_sVanRef - rtb_sCosTheta);
    mGPwm_sVcnRef = -0.5F * (rtb_sCosTheta + mGPwm_sVanRef);
}

/* Output and update for atomic system: '<Root>/Ftn_VltDelayCompensation' */
static void Ftn_VltDelayCompensation(void)
{
    real32_T rtb_sVltTdcTemp4;
    rtb_sVltTdcTemp4 = (E04VTDC.sVltTdcGa * mMTPST_sWm) + E04VTDC.sVltTdcGb;
    if (rtb_sVltTdcTemp4 > E04VTDC.sVltTdcRadMax)
    {
        rtb_sVltTdcTemp4 = E04VTDC.sVltTdcRadMax;
    }
    else if (rtb_sVltTdcTemp4 < E04VTDC.sVltTdcRadMin)
    {
        rtb_sVltTdcTemp4 = E04VTDC.sVltTdcRadMin;
    }
    else
    {
        /* no actions */
    }

    rtb_sVltTdcTemp4 += mCTRL_sThetaCtrl;
    if (rtb_sVltTdcTemp4 > 6.28318548F)
    {
        mGPwm_sThetaCtrl = rtb_sVltTdcTemp4 - 6.28318548F;
    }
    else
    {
        mGPwm_sThetaCtrl = rtb_sVltTdcTemp4;
    }
}

/* Model step function */
void e04_MtrCtrl_PwmSet_step(void)
{
    Ftn_VltDelayCompensation();
    Ftn_Vdqe2Vabc();
    Ftn_FindMinMax();
    Ftn_SVPWM();
    Ftn_CalModulationIndex();
}

/* Model initialize function */
void e04_MtrCtrl_PwmSet_initialize(void)
{
    /* Registration code */

    /* states (dwork) */
    (void) memset((void *)&GvE04DW, 0,
                  sizeof(StrE04DW));

    /* external outputs */
    mGPwm_sVanRef = 0.0F;
    mGPwm_sVbnRef = 0.0F;
    mGPwm_sVcnRef = 0.0F;
    mGPwm_sMiLow = 0.0F;
    mGPwm_sThetaCtrl = 0.0F;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
