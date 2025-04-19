/*
 * File: e01_MtrCtrl_VarGain.c
 *
 * Code generated for Simulink model 'e01_MtrCtrl_VarGain'.
 *
 * Model version                  : 7.579
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Apr 19 16:29:20 2025
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

#include "e01_MtrCtrl_VarGain.h"
#include <math.h>
#include "rtwtypes.h"
#include "e02_MtrCtrl_Pst.h"
#include "b01_OSnScheduler.h"
#include "h01_MdeMgmt.h"
#include "e03_MtrCtrl_MtrCtrl.h"

/* Exported block signals */
real32_T mMCVG_sPCG_Kp;                /* '<Root>/bE01MCVG_mMCVG_sPCG_Kp' */
real32_T mMCVG_sPCG_Ki;                /* '<Root>/bE01MCVG_mMCVG_sPCG_Ki' */
real32_T mMCVG_sPCG_Kd;                /* '<Root>/bE01MCVG_mMCVG_sPCG_Kd' */
real32_T mMCVG_sPCG_Ka;                /* '<Root>/bE01MCVG_mMCVG_sPCG_Ka' */
real32_T mMCVG_sPCG_Apst;              /* '<Root>/bE01MCVG_mMCVG_sPCG_Apst' */
real32_T mMCVG_sSCG_Kp;                /* '<Root>/bE01MCVG_mMCVG_sSCG_Kp' */
real32_T mMCVG_sSCG_Ki;                /* '<Root>/bE01MCVG_mMCVG_sSCG_Ki' */
real32_T mMCVG_sSCG_Ka;                /* '<Root>/bE01MCVG_mMCVG_sSCG_Ka' */
real32_T mMCVG_sSCG_Apst;              /* '<Root>/bE01MCVG_mMCVG_sSCG_Apst' */
real32_T mMCVG_sCCG_Kpd;               /* '<Root>/bE01MCVG_mMCVG_sCCG_Kpd' */
real32_T mMCVG_sCCG_Kid;               /* '<Root>/bE01MCVG_mMCVG_sCCG_Kid' */
real32_T mMCVG_sCCG_Kad;               /* '<Root>/bE01MCVG_mMCVG_sCCG_Kad' */
real32_T mMCVG_sCCG_Kpq;               /* '<Root>/bE01MCVG_mMCVG_sCCG_Kpq' */
real32_T mMCVG_sCCG_Kiq;               /* '<Root>/bE01MCVG_mMCVG_sCCG_Kiq' */
real32_T mMCVG_sCCG_Kaq;               /* '<Root>/bE01MCVG_mMCVG_sCCG_Kaq' */
real32_T mMCVG_sSpdSlpRising;        /* '<Root>/bE01MCVG_mMCVG_sSpdSlpRising' */
real32_T mMCVG_sSpdSlpFalling;      /* '<Root>/bE01MCVG_mMCVG_sSpdSlpFalling' */
real32_T mMCVG_sTqSlpRising;          /* '<Root>/bE01MCVG_mMCVG_sTqSlpRising' */
real32_T mMCVG_sTqSlpFalling;        /* '<Root>/bE01MCVG_mMCVG_sTqSlpFalling' */
real32_T mMCVG_sCurrSlpRising;      /* '<Root>/bE01MCVG_mMCVG_sCurrSlpRising' */
real32_T mMCVG_sCurrSlpFalling;    /* '<Root>/bE01MCVG_mMCVG_sCurrSlpFalling' */

/* Exported data definition */

/* Definition for custom storage class: FileScope */
static S_E01CCG E01CCG =
{
    10.0F,
    1200.0F,
    0.7F,
    10.0F,
    1200.0F,
    0.7F,
    0U
} ;                                    /* Referenced by:
                                        * '<S2>/CB_sCCG_Kad'
                                        * '<S2>/CB_sCCG_Kaq'
                                        * '<S2>/CB_sCCG_Kid'
                                        * '<S2>/CB_sCCG_Kiq'
                                        * '<S2>/CB_sCCG_Kpd'
                                        * '<S2>/CB_sCCG_Kpq'
                                        */

static S_E01PCG E01PCG =
{
    42.0F,
    41.9F,
    0.00190985936F,
    41.8F,
    0.0F,
    1.0F,
    0.0F,
    0.04F,
    0U
} ;                                    /* Referenced by:
                                        * '<S1>/CB_sPCG_Apst'
                                        * '<S1>/CB_sPCG_Ka'
                                        * '<S1>/CB_sPCG_Kd'
                                        * '<S1>/CB_sPCG_Ki'
                                        * '<S1>/CB_sPCG_KpGa'
                                        * '<S1>/CB_sPCG_KpGb'
                                        * '<S1>/Saturation'
                                        */

static S_E01SCG E01SCG =
{
    0.2F,
    0.1F,
    0.000636619749F,
    0.0666666701F,
    3.0F,
    0.8F,
    1.0F,
    0U
} ;                                    /* Referenced by:
                                        * '<S1>/CB_sSCG_Alpha'
                                        * '<S1>/CB_sSCG_Ka'
                                        * '<S1>/CB_sSCG_Ki'
                                        * '<S1>/CB_sSCG_KpGa'
                                        * '<S1>/CB_sSCG_KpGb'
                                        * '<S1>/Saturation1'
                                        */

static S_E01SLP E01SLP =
{
    5000.0F,
    5000.0F,
    20.0F,
    20.0F,
    1000.0F,
    1000.0F,
    1000.0F,
    1000.0F,
    0U
} ;                                    /* Referenced by:
                                        * '<S3>/CB_sCCG_Kaq'
                                        * '<S3>/CB_sCCG_Kid'
                                        * '<S3>/CB_sCCG_Kiq'
                                        * '<S3>/CB_sCCG_Kpd'
                                        * '<S3>/CB_sTqFalling'
                                        * '<S3>/CB_sTqFallingSpdPstMde'
                                        * '<S3>/CB_sTqRising'
                                        * '<S3>/CB_sTqRisingSpdPstMde'
                                        */

/* Block signals and states (default storage) */
StrE01DW GvE01DW;

/* Model step function */
void e01_MtrCtrl_VarGain_step(void)
{
    real32_T u0;
    GvE01DW.sAbsWm = (real32_T)fabs((real_T)mMTPST_sWm);
    if (mSched_i32CntForVarGain == 1L)
    {
        u0 = (GvE01DW.sAbsWm * E01PCG.sPCG_KpGa) + E01PCG.sPCG_KpGb;
        if (u0 > E01PCG.sPCG_KpMax)
        {
            mMCVG_sPCG_Kp = E01PCG.sPCG_KpMax;
        }
        else if (u0 < E01PCG.sPCG_KpMin)
        {
            mMCVG_sPCG_Kp = E01PCG.sPCG_KpMin;
        }
        else
        {
            mMCVG_sPCG_Kp = u0;
        }

        u0 = (GvE01DW.sAbsWm * E01SCG.sSCG_KpGa) + E01SCG.sSCG_KpGb;
        if (u0 > E01SCG.sSCG_KpMax)
        {
            mMCVG_sSCG_Kp = E01SCG.sSCG_KpMax;
        }
        else if (u0 < E01SCG.sSCG_KpMin)
        {
            mMCVG_sSCG_Kp = E01SCG.sSCG_KpMin;
        }
        else
        {
            mMCVG_sSCG_Kp = u0;
        }

        mMCVG_sPCG_Ki = E01PCG.sPCG_Ki;
        mMCVG_sPCG_Kd = E01PCG.sPCG_Kd;
        mMCVG_sPCG_Ka = E01PCG.sPCG_Ka;
        mMCVG_sPCG_Apst = E01PCG.sPCG_Apst;
        mMCVG_sSCG_Ki = E01SCG.sSCG_Ki;
        mMCVG_sSCG_Ka = E01SCG.sSCG_Ka;
        mMCVG_sSCG_Apst = E01SCG.sSCG_Alpha;
    }
    else if (mSched_i32CntForVarGain == 2L)
    {
        mMCVG_sCCG_Kpd = E01CCG.sCCG_Kpd;
        mMCVG_sCCG_Kid = E01CCG.sCCG_Kid;
        mMCVG_sCCG_Kad = E01CCG.sCCG_Kad;
        mMCVG_sCCG_Kpq = E01CCG.sCCG_Kpq;
        mMCVG_sCCG_Kiq = E01CCG.sCCG_Kiq;
        mMCVG_sCCG_Kaq = E01CCG.sCCG_Kaq;
    }
    else
    {
        mMCVG_sSpdSlpRising = E01SLP.sSpdRising;
        if (mSMDE_uMtrCtrlMde == 8U)
        {
            mMCVG_sTqSlpRising = E01SLP.sTqRisingTqMde;
            mMCVG_sTqSlpFalling = E01SLP.sTqFallingTqMde;
        }
        else
        {
            mMCVG_sTqSlpRising = E01SLP.sTqRisingSpdPstMde;
            mMCVG_sTqSlpFalling = E01SLP.sTqFallingSpdPstMde;
        }

        mMCVG_sSpdSlpFalling = E01SLP.sSpdFalling;
        mMCVG_sCurrSlpRising = E01SLP.sCurrRising;
        mMCVG_sCurrSlpFalling = E01SLP.sCurrFalling;
    }

    GvE01DW.sAbsTqRefIn = (real32_T)fabs((real_T)mCTRL_sTqRefIn);
}

/* Model initialize function */
void e01_MtrCtrl_VarGain_initialize(void)
{
    /* Registration code */

    /* states (dwork) */
    (void) memset((void *) &GvE01DW, 0,
                  sizeof(StrE01DW));

    /* external outputs */
    mMCVG_sPCG_Kp = 0.0F;
    mMCVG_sPCG_Ki = 0.0F;
    mMCVG_sPCG_Kd = 0.0F;
    mMCVG_sPCG_Ka = 0.0F;
    mMCVG_sPCG_Apst = 0.0F;
    mMCVG_sSCG_Kp = 0.0F;
    mMCVG_sSCG_Ki = 0.0F;
    mMCVG_sSCG_Ka = 0.0F;
    mMCVG_sSCG_Apst = 0.0F;
    mMCVG_sCCG_Kpd = 0.0F;
    mMCVG_sCCG_Kid = 0.0F;
    mMCVG_sCCG_Kad = 0.0F;
    mMCVG_sCCG_Kpq = 0.0F;
    mMCVG_sCCG_Kiq = 0.0F;
    mMCVG_sCCG_Kaq = 0.0F;
    mMCVG_sSpdSlpRising = 0.0F;
    mMCVG_sSpdSlpFalling = 0.0F;
    mMCVG_sTqSlpRising = 0.0F;
    mMCVG_sTqSlpFalling = 0.0F;
    mMCVG_sCurrSlpRising = 0.0F;
    mMCVG_sCurrSlpFalling = 0.0F;
    mMCVG_sPCG_Ki = E01PCG.sPCG_Ki;
    mMCVG_sPCG_Kd = E01PCG.sPCG_Kd;
    mMCVG_sPCG_Ka = E01PCG.sPCG_Ka;
    mMCVG_sPCG_Apst = E01PCG.sPCG_Apst;
    mMCVG_sSCG_Ki = E01SCG.sSCG_Ki;
    mMCVG_sSCG_Ka = E01SCG.sSCG_Ka;
    mMCVG_sSCG_Apst = E01SCG.sSCG_Alpha;
    mMCVG_sCCG_Kpd = E01CCG.sCCG_Kpd;
    mMCVG_sCCG_Kid = E01CCG.sCCG_Kid;
    mMCVG_sCCG_Kad = E01CCG.sCCG_Kad;
    mMCVG_sCCG_Kpq = E01CCG.sCCG_Kpq;
    mMCVG_sCCG_Kiq = E01CCG.sCCG_Kiq;
    mMCVG_sCCG_Kaq = E01CCG.sCCG_Kaq;
    mMCVG_sSpdSlpRising = E01SLP.sSpdRising;
    mMCVG_sTqSlpRising = 0.0F;
    mMCVG_sTqSlpFalling = 0.0F;
    mMCVG_sSpdSlpFalling = E01SLP.sSpdFalling;
    mMCVG_sCurrSlpRising = E01SLP.sCurrRising;
    mMCVG_sCurrSlpFalling = E01SLP.sCurrFalling;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
