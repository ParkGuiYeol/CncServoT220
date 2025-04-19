/*
 * File: j01_McuInit.c
 *
 * Code generated for Simulink model 'j01_McuInit'.
 *
 * Model version                  : 7.618
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Apr 19 16:33:19 2025
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

#include "j01_McuInit.h"
#include "rtwtypes.h"
#include "c01_MainAdc.h"

/* Exported block signals */
real32_T mMinit_sCurrOfsIa;           /* '<Root>/bJ01MINIT_mMinit_sCurrOfsIa' */
real32_T mMinit_sCurrOfsIb;           /* '<Root>/bJ01MINIT_mMinit_sCurrOfsIb' */
uint16_T mMinit_uFlgChangeISR;     /* '<Root>/bJ01MINIT_mMinit_uFlgChangeISR' */
uint16_T mMinit_uHwFltCurrOffset;
                                /* '<Root>/bJ01MINIT_mMinit_uHwFltCurrOffset' */

/* Exported data definition */

/* Definition for custom storage class: FileScope */
static S_J01MINIT J01MINIT =
{
    10000,
    0.0001F,
    1.5F,
    0U
} ;                                    /* Referenced by:
                                        * '<S1>/CB_J01MINIT_i32CntMaxMcuInit'
                                        * '<S1>/CB_J01MINIT_sInvMaxCnt'
                                        * '<S1>/CB_J01MINIT_sOcfISensOfs'
                                        */

/* Block signals and states (default storage) */
StrJ01DW GvJ01DW;

/* Model step function */
void j01_McuInit_step(void)
{
    real32_T tmp;
    real32_T tmp_0;
    if (GvJ01DW.i32CntMcuInit >= J01MINIT.i32CntMaxMcuInit)
    {
        GvJ01DW.i32CntMcuInit = J01MINIT.i32CntMaxMcuInit;
        mMinit_sCurrOfsIa = GvJ01DW.sIaSum * J01MINIT.sInvMaxCnt;
        mMinit_sCurrOfsIb = GvJ01DW.sIbSum * J01MINIT.sInvMaxCnt;
        if (mMinit_sCurrOfsIa < 0.0F)
        {
            tmp = -mMinit_sCurrOfsIa;
        }
        else
        {
            tmp = mMinit_sCurrOfsIa;
        }

        if (mMinit_sCurrOfsIb < 0.0F)
        {
            tmp_0 = -mMinit_sCurrOfsIb;
        }
        else
        {
            tmp_0 = mMinit_sCurrOfsIb;
        }

        if ((tmp > J01MINIT.sOcfISensOfs) || (tmp_0 > J01MINIT.sOcfISensOfs))
        {
            mMinit_uHwFltCurrOffset = 1U;
        }
        else
        {
            /*  No Action  */
        }

        mMinit_uFlgChangeISR = 1U;
    }
    else
    {
        GvJ01DW.i32CntMcuInit++;
        GvJ01DW.sIaSum += mMsens_sIa;
        GvJ01DW.sIbSum += mMsens_sIb;
    }
}

/* Model initialize function */
void j01_McuInit_initialize(void)
{
    /* Registration code */

    /* states (dwork) */
    (void) memset((void *) &GvJ01DW, 0,
                  sizeof(StrJ01DW));

    /* external outputs */
    mMinit_sCurrOfsIa = 0.0F;
    mMinit_sCurrOfsIb = 0.0F;
    mMinit_uFlgChangeISR = 0U;
    mMinit_uHwFltCurrOffset = 0U;
    mMinit_sCurrOfsIa = 0.0F;
    mMinit_sCurrOfsIb = 0.0F;
    mMinit_uFlgChangeISR = 0U;
    mMinit_uHwFltCurrOffset = 0U;
    GvJ01DW.i32CntMcuInit = 1L;
    GvJ01DW.sIaSum = 0.0F;
    GvJ01DW.sIbSum = 0.0F;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
