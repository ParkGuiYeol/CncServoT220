/*
 * File: c01_MainAdc.c
 *
 * Code generated for Simulink model 'c01_MainAdc'.
 *
 * Model version                  : 7.199
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Mar 29 20:27:45 2025
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

#include "c01_MainAdc.h"
#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#include "L02_ADC_READ.h"
#include "j01_McuInit.h"

/* Exported block signals */
real32_T mMsens_sIa;                   /* '<Root>/bC01MADC_mMsens_sIa' */
real32_T mMsens_sIb;                   /* '<Root>/bC01MADC_mMsens_sIb' */
real32_T mMsens_sIc;                   /* '<Root>/bC01MADC_mMsens_sIc' */
real32_T mMsens_sAbsIa;                /* '<Root>/bC01MADC_mMsens_sAbsIa' */
real32_T mMsens_sAbsIb;                /* '<Root>/bC01MADC_mMsens_sAbsIb' */
real32_T mMsens_sAbsIc;                /* '<Root>/bC01MADC_mMsens_sAbsIc' */
real32_T mMsens_sHVdcLow;              /* '<Root>/bC01MADC_mMsens_sHVdcLow' */
real32_T mMsens_sInvHVdcLow;          /* '<Root>/bC01MADC_mMsens_sInvHVdcLow' */

/* Exported data definition */

/* Definition for custom storage class: FileScope */
static S_C01HVSWF C01HVSWF =
{
    0.0F,
    10.0F,
    0.993736506F,
    0.003131754F,
    0U
} ;                                    /* Referenced by:
                                        * '<S5>/Constant'
                                        * '<S5>/Constant1'
                                        * '<S5>/sLpfLowZ'
                                        * '<S5>/sLpfNowZ'
                                        */

static S_C01ISENS C01ISENS =
{
    0.00122070312F,
    2.00400805F,
    4.5F,
    2.5F,
    7.5F,
    -1.0F,
    0U
} ;                                    /* Referenced by:
                                        * '<S2>/Constant'
                                        * '<S2>/Constant1'
                                        * '<S2>/Constant10'
                                        * '<S2>/Constant11'
                                        * '<S2>/Constant12'
                                        * '<S2>/Constant2'
                                        * '<S2>/Constant3'
                                        * '<S2>/Constant4'
                                        * '<S2>/Constant5'
                                        * '<S2>/Constant6'
                                        * '<S2>/Constant7'
                                        */

static S_C01VSENS C01VSENS =
{
    0.00122070312F,
    2.5F,
    97.3881226F,
    0.0F,
    60.0F,
    0.001F,
    0U
} ;                                    /* Referenced by:
                                        * '<S3>/CB_C01VSENS_sVdcLowerLim'
                                        * '<S3>/CB_C01VSENS_sVdcMin'
                                        * '<S4>/Constant1'
                                        * '<S4>/Constant12'
                                        * '<S4>/Constant2'
                                        * '<S4>/Constant3'
                                        */

static S_C01VTEST C01VTEST =
{
    0.0F,
    0.0F,
    0U
} ;                                    /* Referenced by:
                                        * '<S3>/CB_C01VCONT_sValue'
                                        * '<S3>/CB_C01VCONT_uFlag'
                                        */

/* Block signals and states (default storage) */
StrC01DW GvC01DW;

/* External inputs (root inport signals with default storage) */
StrC01ExtU GvC01U;
static void Ftn_MainAdcHVdc_Init(void);
static void Ftn_MainAdcHVdc(void);
static void Ftn_MainAdcMtrCurr(void);

/* System initialize for atomic system: '<Root>/Ftn_MainAdcHVdc' */
static void Ftn_MainAdcHVdc_Init(void)
{
    GvC01DW.sLpfNowZ = C01HVSWF.sVdcInit;
    GvC01DW.sLpfLowZ = C01HVSWF.sVdcInit;
}

/* Output and update for atomic system: '<Root>/Ftn_MainAdcHVdc' */
static void Ftn_MainAdcHVdc(void)
{
    real32_T rtb_sHVdcNow;
    real32_T rtb_sHVdcTemp4;
    rtb_sHVdcNow = (((((real32_T)ADR_i32HVdcSens) * C01VSENS.sResolut) +
                     C01VSENS.sOpampOffset) * C01VSENS.sHwGain) +
        C01VSENS.sHwOffest;
    GvC01DW.sHVdcLow = ((GvC01DW.sLpfNowZ + rtb_sHVdcNow) * C01HVSWF.sHVdcLb) +
        (GvC01DW.sLpfLowZ * C01HVSWF.sHVdcLa);
    if (C01VTEST.uFlag == 1.0F)
    {
        rtb_sHVdcTemp4 = C01VTEST.sValue;
    }
    else
    {
        rtb_sHVdcTemp4 = GvC01DW.sHVdcLow;
    }

    if (rtb_sHVdcTemp4 < C01VSENS.sVdcMin)
    {
        mMsens_sHVdcLow = C01VSENS.sVdcLowerLim;
    }
    else
    {
        mMsens_sHVdcLow = rtb_sHVdcTemp4;
    }

    mMsens_sInvHVdcLow = 1.0F / mMsens_sHVdcLow;
    GvC01DW.sLpfNowZ = rtb_sHVdcNow;
    GvC01DW.sLpfLowZ = GvC01DW.sHVdcLow;
}

/* Output and update for atomic system: '<Root>/Ftn_MainAdcMtrCurr' */
static void Ftn_MainAdcMtrCurr(void)
{
    mMsens_sIa = ((C01ISENS.sOpampOffset - (((((real32_T)ADR_i32IaSens) *
                      C01ISENS.sResolut) + C01ISENS.sAdChipOffset) *
                    C01ISENS.sHwOffset)) * C01ISENS.sGa) - mMinit_sCurrOfsIa;
    mMsens_sIb = ((C01ISENS.sOpampOffset - (((((real32_T)ADR_i32IbSens) *
                      C01ISENS.sResolut) + C01ISENS.sAdChipOffset) *
                    C01ISENS.sHwOffset)) * C01ISENS.sGa) - mMinit_sCurrOfsIb;
    mMsens_sIc = (mMsens_sIa + mMsens_sIb) * C01ISENS.sCalCurrGain;
    mMsens_sAbsIc = fabsf(mMsens_sIc);
    mMsens_sAbsIb = fabsf(mMsens_sIb);
    mMsens_sAbsIa = fabsf(mMsens_sIa);
}

/* Model step function */
void c01_MainAdc_step(void)
{
    Ftn_MainAdcHVdc();
    Ftn_MainAdcMtrCurr();
}

/* Model initialize function */
void c01_MainAdc_initialize(void)
{
    /* Registration code */

    /* states (dwork) */
    (void) memset((void *)&GvC01DW, 0,
                  sizeof(StrC01DW));

    /* external inputs */
    (void)memset(&GvC01U, 0, sizeof(StrC01ExtU));

    /* external outputs */
    mMsens_sIa = 0.0F;
    mMsens_sIb = 0.0F;
    mMsens_sIc = 0.0F;
    mMsens_sAbsIa = 0.0F;
    mMsens_sAbsIb = 0.0F;
    mMsens_sAbsIc = 0.0F;
    mMsens_sHVdcLow = 0.0F;
    mMsens_sInvHVdcLow = 0.0F;
    Ftn_MainAdcHVdc_Init();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
