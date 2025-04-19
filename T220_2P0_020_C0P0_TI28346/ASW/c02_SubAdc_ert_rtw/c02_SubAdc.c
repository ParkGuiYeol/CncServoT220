/*
 * File: c02_SubAdc.c
 *
 * Code generated for Simulink model 'c02_SubAdc'.
 *
 * Model version                  : 7.333
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Apr 19 16:28:10 2025
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

#include "c02_SubAdc.h"
#include "rtwtypes.h"
#include "look1_iflf_binlca.h"
#include "L02_ADC_READ.h"
#include "b01_OSnScheduler.h"

/* Exported block signals */
real32_T mSsens_sIvtTempLow;          /* '<Root>/bC02SADC_mSsens_sIvtTempLow' */
real32_T mSsens_sMrtTempLow;          /* '<Root>/bC02SADC_mSsens_sMrtTempLow' */

/* Exported data definition */

/* Definition for custom storage class: FileScope */
static S_C02IGBTS C02IGBTS =
{
    0.00122070312F,
    2.5F,
    33000.0F,
    0.492452532F,
    5.0F,
    120.0F,
    25.0F,
    0.0F,
    25.0F,
    10.0F,
    0.993736506F,
    0.003131754F,
    0U
} ;                                    /* Referenced by:
                                        * '<S1>/CB_C02IGBTS_sIgbtNtcHwGain'
                                        * '<S1>/CB_C02IGBTS_sIgbtNtcHwOffset'
                                        * '<S1>/CB_C02PCBTS_sIgbtNtcR0'
                                        * '<S1>/CB_C02PCBTS_sIgbtNtcResolut'
                                        * '<S1>/CB_C02PCBTS_sIgbtNtcV0'
                                        * '<S7>/Saturation'
                                        * '<S24>/Constant'
                                        * '<S24>/Constant1'
                                        * '<S24>/sLpfLowZ'
                                        * '<S24>/sLpfNowZ'
                                        */

static S_C02ITLK C02ITLKV =
{
    {
        400.0F, 1092.0F, 2822.0F, 6282.0F, 16662.0F, 35000.0F
    },

    {
        143.235977F, 137.777832F, 133.121429F, 129.066315F, 125.478363F,
        122.263557F, 119.353462F, 116.696747F, 114.253944F, 111.994064F,
        109.892342F
    },

    {
        109.892342F, 105.206688F, 101.162392F, 97.6087875F, 94.4423904F,
        91.5891113F, 88.9940948F, 86.6156616F, 84.4213562F, 82.3854752F,
        80.4872894F
    },

    {
        80.4872894F, 77.0391541F, 73.9728088F, 71.214119F, 68.7084808F,
        66.4145355F, 64.300209F, 62.3401566F, 60.5139923F, 58.8050842F, 57.1997F
    },

    {
        57.1997F, 52.8984833F, 49.2063103F, 45.9757385F, 43.1067657F,
        40.5284843F, 38.1888351F, 36.0484886F, 34.0770226F, 32.2504349F,
        30.5494499F
    },

    {
        30.5494499F, 27.8048058F, 25.3373642F, 23.0976238F, 21.0481625F,
        19.1600075F, 17.4102802F, 15.7806101F, 14.2560244F, 12.8241606F,
        11.474699F
    },

    {
        400.0F, 469.2F, 538.4F, 607.6F, 676.8F, 746.0F, 815.2F, 884.4F, 953.6F,
        1022.8F, 1092.0F
    },

    {
        1092.0F, 1265.0F, 1438.0F, 1611.0F, 1784.0F, 1957.0F, 2130.0F, 2303.0F,
        2476.0F, 2649.0F, 2822.0F
    },

    {
        2822.0F, 3168.0F, 3514.0F, 3860.0F, 4206.0F, 4552.0F, 4898.0F, 5244.0F,
        5590.0F, 5936.0F, 6282.0F
    },

    {
        6282.0F, 7320.0F, 8358.0F, 9396.0F, 10434.0F, 11472.0F, 12510.0F,
        13548.0F, 14586.0F, 15624.0F, 16662.0F
    },

    {
        16662.0F, 18495.8F, 20329.6F, 22163.4F, 23997.2F, 25831.0F, 27664.8F,
        29498.6F, 31332.4F, 33166.2F, 35000.0F
    }
} ;                                    /* Referenced by:
                                        * '<S2>/CB_C02ITLKV_sArrDivR'
                                        * '<S10>/IVT_LT0'
                                        * '<S11>/IVT_LT1'
                                        * '<S12>/IVT_LT2'
                                        * '<S13>/IVT_LT3'
                                        * '<S14>/IVT_LT4'
                                        */

static S_C02MTLK C02MTLKV =
{
    {
        490.0F, 510.6F, 562.1F, 665.1F, 974.1F, 1520.0F
    },

    {
        0.065427F, 0.604336F, 1.14180839F, 1.67785394F, 2.21248245F, 2.74570322F,
        3.27752614F, 3.80796F, 4.33701468F, 4.86469936F, 5.39102268F
    },

    {
        5.39102268F, 6.70093393F, 8.00253201F, 9.29595089F, 10.5813208F,
        11.8587685F, 13.1284199F, 14.3903952F, 15.6448126F, 16.8917866F,
        18.1314297F
    },

    {
        18.1314297F, 20.5891628F, 23.0188541F, 25.4213142F, 27.7973137F,
        30.1475849F, 32.4728355F, 34.773735F, 37.05093F, 39.3050385F,
        41.5366516F
    },

    {
        41.5366516F, 48.1020737F, 54.4841728F, 60.6955452F, 66.7474518F, 72.65F,
        78.4123077F, 84.0426178F, 89.5484467F, 94.9366074F, 100.213364F
    },

    {
        100.213364F, 109.28067F, 118.04612F, 126.534248F, 134.766541F,
        142.761887F, 150.537064F, 158.10701F, 165.485092F, 172.683289F,
        179.712494F
    },

    {
        490.0F, 492.06F, 494.12F, 496.18F, 498.24F, 500.3F, 502.36F, 504.42F,
        506.48F, 508.54F, 510.6F
    },

    {
        510.6F, 515.75F, 520.9F, 526.05F, 531.2F, 536.35F, 541.5F, 546.65F,
        551.8F, 556.95F, 562.1F
    },

    {
        562.1F, 572.4F, 582.7F, 593.0F, 603.3F, 613.6F, 623.9F, 634.2F, 644.5F,
        654.8F, 665.1F
    },

    {
        665.1F, 696.0F, 726.9F, 757.8F, 788.7F, 819.6F, 850.5F, 881.4F, 912.3F,
        943.2F, 974.1F
    },

    {
        974.1F, 1028.69F, 1083.28F, 1137.87F, 1192.46F, 1247.05F, 1301.64F,
        1356.23F, 1410.82F, 1465.41F, 1520.0F
    }
} ;                                    /* Referenced by:
                                        * '<S5>/CB_C02ITLKV_sArrDivR'
                                        * '<S18>/IVT_LT0'
                                        * '<S19>/IVT_LT1'
                                        * '<S20>/IVT_LT2'
                                        * '<S21>/IVT_LT3'
                                        * '<S22>/IVT_LT4'
                                        */

static S_C02MTRTS C02MTRTS =
{
    0.00122070312F,
    2.5F,
    5000.0F,
    0.2903F,
    5.0F,
    160.0F,
    25.0F,
    0.0F,
    25.0F,
    10.0F,
    0.993736506F,
    0.003131754F,
    0U
} ;                                    /* Referenced by:
                                        * '<S4>/CB_C02IGBTS_sMtrNtcHwGain'
                                        * '<S4>/CB_C02IGBTS_sMtrNtcHwOffset'
                                        * '<S4>/CB_C02PCBTS_sMtrNtcR0'
                                        * '<S4>/CB_C02PCBTS_sMtrNtcResolut'
                                        * '<S4>/CB_C02PCBTS_sMtrNtcV0'
                                        * '<S7>/Saturation1'
                                        * '<S25>/Constant'
                                        * '<S25>/Constant1'
                                        * '<S25>/sLpfLowZ'
                                        * '<S25>/sLpfNowZ'
                                        */

/* Block signals and states (default storage) */
StrC02DW GvC02DW;
static void Ftn_CalIvtTemp_Tnow_Init(void);
static void Ftn_CalIvtTemp_Tnow(void);
static void Ftn_CalIvtTemp_RIndex_Init(void);
static void Ftn_CalIvtTemp_RIndex(void);
static void Ftn_CalIvtTemp_R_Init(void);
static void Ftn_CalIvtTemp_R(void);
static void Ftn_CalMtrTemp_Tnow_Init(void);
static void Ftn_CalMtrTemp_Tnow(void);
static void Ftn_CalMtrTemp_RIndex1_Init(void);
static void Ftn_CalMtrTemp_RIndex1(void);
static void Ftn_CalMtrTemp_R_Init(void);
static void Ftn_CalMtrTemp_R(void);

/* System initialize for action system: '<Root>/Ftn_CalIvtTemp_Tnow' */
static void Ftn_CalIvtTemp_Tnow_Init(void)
{
    GvC02DW.sIvtTsen_Now = 0.0F;
}

/* Output and update for action system: '<Root>/Ftn_CalIvtTemp_Tnow' */
static void Ftn_CalIvtTemp_Tnow(void)
{
    switch ((int32_T)GvC02DW.uIvtTemp_RIndex)
    {
      case 1L:
        GvC02DW.sIvtTsen_Now = look1_iflf_binlca(GvC02DW.sIvtTemp_R,
            &C02ITLKV.sArrR0[0], &C02ITLKV.sArrT0[0], 10UL);
        break;

      case 2L:
        GvC02DW.sIvtTsen_Now = look1_iflf_binlca(GvC02DW.sIvtTemp_R,
            &C02ITLKV.sArrR1[0], &C02ITLKV.sArrT1[0], 10UL);
        break;

      case 3L:
        GvC02DW.sIvtTsen_Now = look1_iflf_binlca(GvC02DW.sIvtTemp_R,
            &C02ITLKV.sArrR2[0], &C02ITLKV.sArrT2[0], 10UL);
        break;

      case 4L:
        GvC02DW.sIvtTsen_Now = look1_iflf_binlca(GvC02DW.sIvtTemp_R,
            &C02ITLKV.sArrR3[0], &C02ITLKV.sArrT3[0], 10UL);
        break;

      case 5L:
        GvC02DW.sIvtTsen_Now = look1_iflf_binlca(GvC02DW.sIvtTemp_R,
            &C02ITLKV.sArrR4[0], &C02ITLKV.sArrT4[0], 10UL);
        break;

      default:
        GvC02DW.sIvtTsen_Now = 0.0F;
        break;
    }
}

/* System initialize for action system: '<Root>/Ftn_CalIvtTemp_RIndex' */
static void Ftn_CalIvtTemp_RIndex_Init(void)
{
    GvC02DW.uIvtTemp_RIndex = 5U;
}

/* Output and update for action system: '<Root>/Ftn_CalIvtTemp_RIndex' */
static void Ftn_CalIvtTemp_RIndex(void)
{
    if (GvC02DW.sIvtTemp_R < C02ITLKV.sArrDivR[1])
    {
        GvC02DW.uIvtTemp_RIndex = 1U;
    }
    else if (GvC02DW.sIvtTemp_R < C02ITLKV.sArrDivR[2])
    {
        GvC02DW.uIvtTemp_RIndex = 2U;
    }
    else if (GvC02DW.sIvtTemp_R < C02ITLKV.sArrDivR[3])
    {
        GvC02DW.uIvtTemp_RIndex = 3U;
    }
    else if (GvC02DW.sIvtTemp_R < C02ITLKV.sArrDivR[4])
    {
        GvC02DW.uIvtTemp_RIndex = 4U;
    }
    else
    {
        GvC02DW.uIvtTemp_RIndex = 5U;
    }
}

/* System initialize for action system: '<Root>/Ftn_CalIvtTemp_R' */
static void Ftn_CalIvtTemp_R_Init(void)
{
    GvC02DW.sIvtTemp_R = 25000.0F;
}

/* Output and update for action system: '<Root>/Ftn_CalIvtTemp_R' */
static void Ftn_CalIvtTemp_R(void)
{
    real32_T sTempVlt;
    sTempVlt = ((((real32_T)ADR_i32IvtTempSens) * C02IGBTS.sIgbtNtcResolut) +
                C02IGBTS.sIgbtNtcHwOffset) * C02IGBTS.sIgbtNtcHwGain;
    GvC02DW.sIvtTemp_R = ((-sTempVlt) * C02IGBTS.sIgbtNtcR0) / (sTempVlt -
        C02IGBTS.sIgbtNtcV0);
}

/* System initialize for action system: '<Root>/Ftn_CalMtrTemp_Tnow' */
static void Ftn_CalMtrTemp_Tnow_Init(void)
{
    GvC02DW.sMtrTsen_Now = 0.0F;
}

/* Output and update for action system: '<Root>/Ftn_CalMtrTemp_Tnow' */
static void Ftn_CalMtrTemp_Tnow(void)
{
    switch ((int32_T)GvC02DW.uMtrTemp_RIndex)
    {
      case 1L:
        GvC02DW.sMtrTsen_Now = look1_iflf_binlca(GvC02DW.sMtrTemp_R,
            &C02MTLKV.sArrR0[0], &C02MTLKV.sArrT0[0], 10UL);
        break;

      case 2L:
        GvC02DW.sMtrTsen_Now = look1_iflf_binlca(GvC02DW.sMtrTemp_R,
            &C02MTLKV.sArrR1[0], &C02MTLKV.sArrT1[0], 10UL);
        break;

      case 3L:
        GvC02DW.sMtrTsen_Now = look1_iflf_binlca(GvC02DW.sMtrTemp_R,
            &C02MTLKV.sArrR2[0], &C02MTLKV.sArrT2[0], 10UL);
        break;

      case 4L:
        GvC02DW.sMtrTsen_Now = look1_iflf_binlca(GvC02DW.sMtrTemp_R,
            &C02MTLKV.sArrR3[0], &C02MTLKV.sArrT3[0], 10UL);
        break;

      case 5L:
        GvC02DW.sMtrTsen_Now = look1_iflf_binlca(GvC02DW.sMtrTemp_R,
            &C02MTLKV.sArrR4[0], &C02MTLKV.sArrT4[0], 10UL);
        break;

      default:
        GvC02DW.sMtrTsen_Now = 0.0F;
        break;
    }
}

/* System initialize for action system: '<Root>/Ftn_CalMtrTemp_RIndex1' */
static void Ftn_CalMtrTemp_RIndex1_Init(void)
{
    GvC02DW.uMtrTemp_RIndex = 1U;
}

/* Output and update for action system: '<Root>/Ftn_CalMtrTemp_RIndex1' */
static void Ftn_CalMtrTemp_RIndex1(void)
{
    if (GvC02DW.sMtrTemp_R < C02MTLKV.sArrDivR[1])
    {
        GvC02DW.uMtrTemp_RIndex = 1U;
    }
    else if (GvC02DW.sMtrTemp_R < C02MTLKV.sArrDivR[2])
    {
        GvC02DW.uMtrTemp_RIndex = 2U;
    }
    else if (GvC02DW.sMtrTemp_R < C02MTLKV.sArrDivR[3])
    {
        GvC02DW.uMtrTemp_RIndex = 3U;
    }
    else if (GvC02DW.sMtrTemp_R < C02MTLKV.sArrDivR[4])
    {
        GvC02DW.uMtrTemp_RIndex = 4U;
    }
    else
    {
        GvC02DW.uMtrTemp_RIndex = 5U;
    }
}

/* System initialize for action system: '<Root>/Ftn_CalMtrTemp_R' */
static void Ftn_CalMtrTemp_R_Init(void)
{
    GvC02DW.sMtrTemp_R = 570.0F;
}

/* Output and update for action system: '<Root>/Ftn_CalMtrTemp_R' */
static void Ftn_CalMtrTemp_R(void)
{
    real32_T sTempVlt;
    sTempVlt = ((((real32_T)ADR_i32MtrTempSens) * C02MTRTS.sMtrNtcResolut) +
                C02MTRTS.sMtrNtcHwOffset) * C02MTRTS.sMtrNtcHwGain;
    GvC02DW.sMtrTemp_R = ((-sTempVlt) * C02MTRTS.sMtrNtcR0) / (sTempVlt -
        C02MTRTS.sMtrNtcV0);
}

/* Model step function */
void c02_SubAdc_step(void)
{
    real32_T rtb_sIvtTsenLimited;
    real32_T rtb_sMtrTsenLimited;
    switch (mSched_i32CntForSch)
    {
      case 22L:
        if (GvC02DW.sIvtTsen_Now > C02IGBTS.sIgbtNtcTmax)
        {
            rtb_sIvtTsenLimited = C02IGBTS.sIgbtNtcTmax;
        }
        else if (GvC02DW.sIvtTsen_Now < C02IGBTS.sIgbtNtcTmin)
        {
            rtb_sIvtTsenLimited = C02IGBTS.sIgbtNtcTmin;
        }
        else
        {
            rtb_sIvtTsenLimited = GvC02DW.sIvtTsen_Now;
        }

        mSsens_sIvtTempLow = ((GvC02DW.sLpfNowZ + rtb_sIvtTsenLimited) *
                              C02IGBTS.sTempLb) + (GvC02DW.sLpfLowZ *
            C02IGBTS.sTempLa);
        if (GvC02DW.sMtrTsen_Now > C02MTRTS.sMtrNtcTmax)
        {
            rtb_sMtrTsenLimited = C02MTRTS.sMtrNtcTmax;
        }
        else if (GvC02DW.sMtrTsen_Now < C02MTRTS.sMtrNtcTmin)
        {
            rtb_sMtrTsenLimited = C02MTRTS.sMtrNtcTmin;
        }
        else
        {
            rtb_sMtrTsenLimited = GvC02DW.sMtrTsen_Now;
        }

        mSsens_sMrtTempLow = ((GvC02DW.sLpfNowZ_eaw3 + rtb_sMtrTsenLimited) *
                              C02MTRTS.sTempLb) + (GvC02DW.sLpfLowZ_mhrj *
            C02MTRTS.sTempLa);
        GvC02DW.sLpfLowZ = mSsens_sIvtTempLow;
        GvC02DW.sLpfNowZ = rtb_sIvtTsenLimited;
        GvC02DW.sLpfLowZ_mhrj = mSsens_sMrtTempLow;
        GvC02DW.sLpfNowZ_eaw3 = rtb_sMtrTsenLimited;
        break;

      case 6L:
        Ftn_CalIvtTemp_Tnow();
        break;

      case 4L:
        Ftn_CalIvtTemp_RIndex();
        break;

      case 2L:
        Ftn_CalIvtTemp_R();
        break;

      case 16L:
        Ftn_CalMtrTemp_Tnow();
        break;

      case 14L:
        Ftn_CalMtrTemp_RIndex1();
        break;

      case 12L:
        Ftn_CalMtrTemp_R();
        break;

      default:
        /* no actions */
        break;
    }
}

/* Model initialize function */
void c02_SubAdc_initialize(void)
{
    /* Registration code */

    /* states (dwork) */
    (void) memset((void *)&GvC02DW, 0,
                  sizeof(StrC02DW));

    /* external outputs */
    mSsens_sIvtTempLow = 0.0F;
    mSsens_sMrtTempLow = 0.0F;
    Ftn_CalIvtTemp_R_Init();
    Ftn_CalIvtTemp_RIndex_Init();
    Ftn_CalIvtTemp_Tnow_Init();
    Ftn_CalMtrTemp_R_Init();
    Ftn_CalMtrTemp_RIndex1_Init();
    Ftn_CalMtrTemp_Tnow_Init();
    GvC02DW.sLpfLowZ = C02IGBTS.sTempInit;
    GvC02DW.sLpfNowZ = C02IGBTS.sTempInit;
    GvC02DW.sLpfLowZ_mhrj = C02MTRTS.sTempInit;
    GvC02DW.sLpfNowZ_eaw3 = C02MTRTS.sTempInit;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
