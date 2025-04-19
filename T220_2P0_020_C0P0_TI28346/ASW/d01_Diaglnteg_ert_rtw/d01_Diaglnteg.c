/*
 * File: d01_Diaglnteg.c
 *
 * Code generated for Simulink model 'd01_Diaglnteg'.
 *
 * Model version                  : 7.634
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Apr 19 16:28:44 2025
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

#include "d01_Diaglnteg.h"
#include "rtwtypes.h"
#include <math.h>
#include "c01_MainAdc.h"
#include "b01_OSnScheduler.h"
#include "M2_Interrupt.h"
#include "j01_McuInit.h"
#include "h01_MdeMgmt.h"
#include "e03_MtrCtrl_MtrCtrl.h"
#include "c02_SubAdc.h"
#include "M1_Interrupt.h"
#include "e02_MtrCtrl_Pst.h"

/* Named constants for Chart: '<S5>/Chart_T01Diag_OverCurrErrDtc' */
#define Cnst_F08_CrtOvrFlt             (256UL)

/* Named constants for Chart: '<S6>/Chart_T01GateAndEstpFltDtc' */
#define Cnst_F01_EstopSwitchFlt        (2UL)
#define Cnst_F02_IgptShrtFlt           (4UL)

/* Named constants for Chart: '<S7>/Chart_T01HvdcFltDtc' */
#define Cnst_F03_HvdcOvrVolFlt         (8UL)
#define Cnst_F04_HvdcUdrVolFlt         (16UL)

/* Named constants for Chart: '<S16>/Chart_T30CrtSnsrFltDtc' */
#define Cnst_F05_CrtSnsrFlt            (32UL)
#define Cnst_F06_CrtSnsrOfsFlt         (64UL)
#define Cnst_F07_CrtStallFlt           (128UL)

/* Named constants for Chart: '<S15>/Chart' */
#define Cnst_F11_MtrTempSnsrFlt        (2048UL)
#define Cnst_F12_MtrTempOvrFlt         (4096UL)

/* Named constants for Chart: '<S14>/Chart' */
#define Cnst_F010_IvtTempOvrFlt        (1024UL)
#define Cnst_F09_IvtTempSnsrFlt        (512UL)

/* Named constants for Chart: '<S13>/Chart_T30InitNvRamDtc' */
#define Cnst_F16_T10_InitNvRam         (65536UL)

/* Named constants for Chart: '<S12>/Chart_T01Diag_OverCurrErrDtc' */
#define Cnst_F13_MtrSpdFlt             (8192UL)

/* Exported block signals */
uint16_T mDIAG_uFltStat;               /* '<Root>/bD01DIAG_mDIAG_uFltStat' */
uint32_T mDIAG_u32FltAll;              /* '<Root>/bD01DIAG_mDIAG_u32FltAll' */
uint16_T mDIAG_uChprOpr1On0Off;    /* '<Root>/bD01DIAG_mDIAG_uChprOpr1On0Off' */
uint16_T mDIAG_uFan1On0Off;            /* '<Root>/bD01DIAG_mDIAG_uFan1On0Off' */
uint16_T mDIAG_uCntCrtOvr;             /* '<Root>/bD01DIAG_mDIAG_uCntCrtOvr' */
uint32_T sF01_T01_EstopSwitchFlt;/* '<Root>/bD01DIAG_sF01_T01_EstopSwitchFlt' */
uint32_T sF02_T01_IgptShrtFlt;      /* '<Root>/bD01DIAG_sF02_T01_IgptShrtFlt' */
uint32_T sF03_T01_HvdcOvrVolFlt;  /* '<Root>/bD01DIAG_sF03_T01_HvdcOvrVolFlt' */
uint32_T sF04_T01_HvdcUdrVolFlt;  /* '<Root>/bD01DIAG_sF04_T01_HvdcUdrVolFlt' */
uint32_T sF05_T30_CrtSnsrFlt;        /* '<Root>/bD01DIAG_sF05_T30_CrtSnsrFlt' */
uint32_T sF06_T30_CrtSnsrOfsFlt;  /* '<Root>/bD01DIAG_sF06_T30_CrtSnsrOfsFlt' */
uint32_T sF07_T30_CrtStallFlt;      /* '<Root>/bD01DIAG_sF07_T30_CrtStallFlt' */
uint32_T sF08_T01_CrtOvrFlt;          /* '<Root>/bD01DIAG_sF08_T01_CrtOvrFlt' */
uint32_T sF09_T30_IvtTempSnsrFlt;/* '<Root>/bD01DIAG_sF09_T30_IvtTempSnsrFlt' */
uint32_T sF10_T30_IvtTempOvrFlt;  /* '<Root>/bD01DIAG_sF10_T30_IvtTempOvrFlt' */
uint32_T sF11_T30_MtrTempSnsrFlt;/* '<Root>/bD01DIAG_sF11_T30_MtrTempSnsrFlt' */
uint32_T sF12_T30_MtrTempOvrFlt;  /* '<Root>/bD01DIAG_sF12_T30_MtrTempOvrFlt' */
uint32_T sF13_T10_MtrSpdFlt;          /* '<Root>/bD01DIAG_sF13_T10_MtrSpdFlt' */
uint32_T sF16_T10_InitNvRam;          /* '<Root>/bD01DIAG_sF16_T10_InitNvRam' */

/* Exported data definition */

/* Definition for custom storage class: FileScope */
static S_D01CRT D01CRT =
{
    22.6132755F,
    35.0F,
    4.584F,
    2,
    2,
    167,
    0U
} ;                                    /* Referenced by:
                                        * '<S5>/CB_D01CRT_i32CrtFltDebCnt'
                                        * '<S5>/CB_D01CRT_sOvrCrtFltDtcLvl'
                                        * '<S16>/CB_D01CRT_i32CrtSnsrFltDebCnt'
                                        * '<S16>/CB_D01CRT_i32FixedCrtFltDtcCnt'
                                        * '<S16>/CB_D01CRT_sCrtSnsrFltDtcLvl'
                                        * '<S16>/CB_D01CRT_sFixedCrtFltDtcLvl'
                                        */

static S_D01SPD D01SPD =
{
    2500.0F,
    2,
    0U
} ;                                    /* Referenced by:
                                        * '<S12>/D01SPD_i32OvrSpdFltDebCnt'
                                        * '<S12>/D01SPD_sOvrSpdFltDtcLvl'
                                        */

static S_D01TEMP D01TEMP =
{
    -30.0F,
    75.0F,
    40.0F,
    30.0F,
    -30.0F,
    110.0F,
    180.0F,
    0U
} ;                                    /* Referenced by:
                                        * '<S14>/D01SPD_sFanOffIvtTempSet'
                                        * '<S14>/D01SPD_sFanOnIvtTempSet'
                                        * '<S14>/D01SPD_sIvtOvrTempFltDtcLvl'
                                        * '<S14>/D01SPD_sIvtTempSnsrFltDtcLow'
                                        * '<S15>/D01SPD_sMtrOvrTempFltDtcLvl'
                                        * '<S15>/D01SPD_sMtrTempSnsrDtcHigh'
                                        * '<S15>/D01SPD_sMtrTempSnsrDtcLow'
                                        */

static S_D01VDC D01VDC =
{
    20.0F,
    180.0F,
    240.0F,
    375.0F,
    385.0F,
    405.0F,
    0U
} ;                                    /* Referenced by:
                                        * '<S7>/CB_sDcOvrChpHysOprLvl'
                                        * '<S7>/CB_sDcOvrVltFltDtcLvl'
                                        * '<S7>/CB_sDcOvrWarnFltDtcLvl'
                                        * '<S7>/CB_sDcUdrVltFltDtcLvl'
                                        */

static S_D02DFLT D02DFLT =
{
    81918U,
    0U
} ;                                  /* Referenced by: '<S3>/CB_u32DisFltAll' */

/* Block signals and states (default storage) */
StrD01DW GvD01DW;
static void Ftn_T01CalCurrMax(void);
static void Ftn_T01CrtFltDtc_Init(void);
static void Ftn_T01CrtFltDtc(void);
static void Ftn_T01GateAndEstpFltDtc_Init(void);
static void Ftn_T01GateAndEstpFltDtc(void);
static void Ftn_T01HvdcFltDtc_Init(void);
static void Ftn_T01HvdcFltDtc(void);
static void Ftn_T01DiagGroup_Init(void);
static void Ftn_T01DiagGroup(void);
static void Ftn_FaultIntegration_Init(void);
static void Ftn_FaultIntegration(void);
static void Ftn_T01Diaglntegration_Init(void);
static void Ftn_T01Diaglntegration(void);
static void Ftn_T30StalAndCrtSnsrFltDt_Init(void);
static void Ftn_T30StalAndCrtSnsrFltDtc(void);
static void Ftn_T30MtrTempFltDtc_Init(void);
static void Ftn_T30MtrTempFltDtc(void);
static void Ftn_T30IvtTempFltDtc_Init(void);
static void Ftn_T30IvtTempFltDtc(void);
static void Ftn_T30InitNvRamDtc_Init(void);
static void Ftn_T30InitNvRamDtc(void);
static void Ftn_T10MtrSpdFltDtc_Init(void);
static void Ftn_T10MtrSpdFltDtc(void);
static void Ftn_T30DiagGroup_Init(void);
static void Ftn_T30DiagGroup(void);

/* Output and update for atomic system: '<Root>/Ftn_T01CalCurrMax' */
static void Ftn_T01CalCurrMax(void)
{
    GvD01DW.sImax = fmaxf(fmaxf(mMsens_sAbsIa, mMsens_sAbsIb), mMsens_sAbsIc);
}

/* System initialize for atomic system: '<S2>/Ftn_T01CrtFltDtc' */
static void Ftn_T01CrtFltDtc_Init(void)
{
    GvD01DW.mDIAG_i32CntCrOvr = 0L;
    sF08_T01_CrtOvrFlt = 0UL;
}

/* Output and update for atomic system: '<S2>/Ftn_T01CrtFltDtc' */
static void Ftn_T01CrtFltDtc(void)
{
    if (GvD01DW.sImax >= D01CRT.sOvrCrtFltDtcLvl)
    {
        if (GvD01DW.mDIAG_i32CntCrOvr >= D01CRT.i32CrtFltDebCnt)
        {
            GvD01DW.mDIAG_i32CntCrOvr = D01CRT.i32CrtFltDebCnt;
            sF08_T01_CrtOvrFlt = Cnst_F08_CrtOvrFlt;
        }
        else
        {
            GvD01DW.mDIAG_i32CntCrOvr++;
        }
    }
    else
    {
        GvD01DW.mDIAG_i32CntCrOvr = 0L;
    }

    mDIAG_uCntCrtOvr = (uint16_T)GvD01DW.mDIAG_i32CntCrOvr;
}

/* System initialize for atomic system: '<S2>/Ftn_T01GateAndEstpFltDtc' */
static void Ftn_T01GateAndEstpFltDtc_Init(void)
{
    sF01_T01_EstopSwitchFlt = 0UL;
    sF02_T01_IgptShrtFlt = 0UL;
}

/* Output and update for atomic system: '<S2>/Ftn_T01GateAndEstpFltDtc' */
static void Ftn_T01GateAndEstpFltDtc(void)
{
    if (mBSW_uGateFltDtc == 0U)
    {
        sF02_T01_IgptShrtFlt = Cnst_F02_IgptShrtFlt;
    }
    else
    {
        /*  No Action  */
    }

    if (mBSW_uEstpSwitchDtc == 0U)
    {
        sF01_T01_EstopSwitchFlt = Cnst_F01_EstopSwitchFlt;
    }
    else
    {
        /*  No Action  */
    }
}

/* System initialize for atomic system: '<S2>/Ftn_T01HvdcFltDtc' */
static void Ftn_T01HvdcFltDtc_Init(void)
{
    mDIAG_uChprOpr1On0Off = 0U;
    GvD01DW.uFlag_Hysteresis = 0U;
    sF03_T01_HvdcOvrVolFlt = 0UL;
    sF04_T01_HvdcUdrVolFlt = 0UL;
}

/* Output and update for atomic system: '<S2>/Ftn_T01HvdcFltDtc' */
static void Ftn_T01HvdcFltDtc(void)
{
    if (mMsens_sHVdcLow < D01VDC.sDcUdrVltFltDtcLvl)
    {
        /*  < 180 [Vdc]  */
        sF04_T01_HvdcUdrVolFlt = Cnst_F04_HvdcUdrVolFlt;
    }
    else if (mMsens_sHVdcLow > D01VDC.sDcOvrVltFltDtcLvl)
    {
        /*  > 405 [Vdc]  */
        mDIAG_uChprOpr1On0Off = 1U;
        GvD01DW.uFlag_Hysteresis = 1U;
        sF03_T01_HvdcOvrVolFlt = Cnst_F03_HvdcOvrVolFlt;
    }
    else if (mMsens_sHVdcLow > D01VDC.sDcOvrWarnFltDtcLvl)
    {
        /*  > 385 [Vdc]  */
        mDIAG_uChprOpr1On0Off = 1U;
        GvD01DW.uFlag_Hysteresis = 1U;
    }
    else if (mMsens_sHVdcLow > D01VDC.sDcOvrChpHysOprLvl)
    {
        /*  > 375 [Vdc]  */
        mDIAG_uChprOpr1On0Off = (uint16_T)((GvD01DW.uFlag_Hysteresis == 1U) ?
            ((int16_T)1) : ((int16_T)0));
    }
    else
    {
        mDIAG_uChprOpr1On0Off = 0U;
    }
}

/* System initialize for atomic system: '<Root>/Ftn_T01DiagGroup' */
static void Ftn_T01DiagGroup_Init(void)
{
    Ftn_T01CrtFltDtc_Init();
    Ftn_T01GateAndEstpFltDtc_Init();
    Ftn_T01HvdcFltDtc_Init();
}

/* Output and update for atomic system: '<Root>/Ftn_T01DiagGroup' */
static void Ftn_T01DiagGroup(void)
{
    Ftn_T01CrtFltDtc();
    Ftn_T01GateAndEstpFltDtc();
    Ftn_T01HvdcFltDtc();
}

/* System initialize for atomic system: '<S3>/Ftn_FaultIntegration' */
static void Ftn_FaultIntegration_Init(void)
{
    mDIAG_uFltStat = 0U;
    mDIAG_u32FltAll = 0UL;
}

/* Output and update for atomic system: '<S3>/Ftn_FaultIntegration' */
static void Ftn_FaultIntegration(void)
{
    uint32_T u32FltSum;
    int16_T F00;
    u32FltSum = (((((((((((((sF01_T01_EstopSwitchFlt | sF02_T01_IgptShrtFlt) |
                            sF03_T01_HvdcOvrVolFlt) | sF04_T01_HvdcUdrVolFlt) |
                          sF05_T30_CrtSnsrFlt) | sF06_T30_CrtSnsrOfsFlt) |
                        sF07_T30_CrtStallFlt) | sF08_T01_CrtOvrFlt) |
                      sF09_T30_IvtTempSnsrFlt) | sF10_T30_IvtTempOvrFlt) |
                    sF11_T30_MtrTempSnsrFlt) | sF12_T30_MtrTempOvrFlt) |
                  sF13_T10_MtrSpdFlt) | sF16_T10_InitNvRam) &
        D02DFLT.u32DisFltAll;
    if (u32FltSum != 0UL)
    {
        mDIAG_uFltStat = 1U;
        F00 = 1;
    }
    else
    {
        mDIAG_uFltStat = 0U;
        F00 = 0;
    }

    mDIAG_u32FltAll = ((uint32_T)F00) | u32FltSum;
}

/* System initialize for atomic system: '<Root>/Ftn_T01Diaglntegration' */
static void Ftn_T01Diaglntegration_Init(void)
{
    Ftn_FaultIntegration_Init();
}

/* Output and update for atomic system: '<Root>/Ftn_T01Diaglntegration' */
static void Ftn_T01Diaglntegration(void)
{
    Ftn_FaultIntegration();
}

/* System initialize for action system: '<S4>/Ftn_T30StalAndCrtSnsrFltDtc' */
static void Ftn_T30StalAndCrtSnsrFltDt_Init(void)
{
    sF05_T30_CrtSnsrFlt = 0UL;
    sF06_T30_CrtSnsrOfsFlt = 0UL;
    GvD01DW.i32CntIaFixedCurrUp = 0L;
    GvD01DW.i32CntIaFixedCurrDown = 0L;
    GvD01DW.i32CntSnsrFlt = 0L;
    GvD01DW.i32CntIbFixedCurrDown = 0L;
    GvD01DW.i32CntIbFixedCurrUp = 0L;
    sF07_T30_CrtStallFlt = 0UL;
}

/* Output and update for action system: '<S4>/Ftn_T30StalAndCrtSnsrFltDtc' */
static void Ftn_T30StalAndCrtSnsrFltDtc(void)
{
    if (mMinit_uHwFltCurrOffset != 0U)
    {
        sF06_T30_CrtSnsrOfsFlt = Cnst_F06_CrtSnsrOfsFlt;
    }
    else if (GvD01DW.sImax >= D01CRT.sCrtSnsrFltDtcLvl)
    {
        if (GvD01DW.i32CntSnsrFlt >= D01CRT.i32CrtSnsrFltDebCnt)
        {
            GvD01DW.i32CntSnsrFlt = D01CRT.i32CrtSnsrFltDebCnt;
            sF05_T30_CrtSnsrFlt = Cnst_F05_CrtSnsrFlt;
        }
        else
        {
            GvD01DW.i32CntSnsrFlt++;
        }
    }
    else
    {
        GvD01DW.i32CntSnsrFlt = 0L;
    }

    if (sF07_T30_CrtStallFlt == 0UL)
    {
        if (((mSMDE_uMtrCtrlMde == 16U) || (mSMDE_uMtrCtrlMde == 32U)) &&
                (mCTRL_sTqRefIn >= D01CRT.sFixedCrtFltDtcLvl))
        {
            if (mMsens_sIa > 0.0F)
            {
                GvD01DW.i32CntIaFixedCurrUp++;
                GvD01DW.i32CntIaFixedCurrDown = 0L;
            }
            else
            {
                GvD01DW.i32CntIaFixedCurrDown++;
                GvD01DW.i32CntIaFixedCurrUp = 0L;
            }

            if ((GvD01DW.i32CntIaFixedCurrUp + GvD01DW.i32CntIaFixedCurrDown) >
                    D01CRT.i32FixedCrtFltDtcCnt)
            {
                sF07_T30_CrtStallFlt = Cnst_F07_CrtStallFlt;
            }
            else
            {
                /*  No action  */
            }

            if (mMsens_sIb > 0.0F)
            {
                GvD01DW.i32CntIbFixedCurrUp++;
                GvD01DW.i32CntIbFixedCurrDown = 0L;
            }
            else
            {
                GvD01DW.i32CntIbFixedCurrDown++;
                GvD01DW.i32CntIbFixedCurrUp = 0L;
            }

            if ((GvD01DW.i32CntIbFixedCurrUp + GvD01DW.i32CntIbFixedCurrDown) >
                    D01CRT.i32FixedCrtFltDtcCnt)
            {
                sF07_T30_CrtStallFlt = Cnst_F07_CrtStallFlt;
            }
            else
            {
                /*  No action  */
            }
        }
        else
        {
            GvD01DW.i32CntIaFixedCurrUp = 0L;
            GvD01DW.i32CntIaFixedCurrDown = 0L;
            GvD01DW.i32CntIbFixedCurrUp = 0L;
            GvD01DW.i32CntIbFixedCurrDown = 0L;
        }
    }
    else
    {
        GvD01DW.i32CntIaFixedCurrUp = 0L;
        GvD01DW.i32CntIaFixedCurrDown = 0L;
        GvD01DW.i32CntIbFixedCurrUp = 0L;
        GvD01DW.i32CntIbFixedCurrDown = 0L;
    }
}

/* System initialize for action system: '<S4>/Ftn_T30MtrTempFltDtc' */
static void Ftn_T30MtrTempFltDtc_Init(void)
{
    sF11_T30_MtrTempSnsrFlt = 0UL;
    sF12_T30_MtrTempOvrFlt = 0UL;
}

/* Output and update for action system: '<S4>/Ftn_T30MtrTempFltDtc' */
static void Ftn_T30MtrTempFltDtc(void)
{
    if ((mSsens_sMrtTempLow < D01TEMP.sMtrTempSnsrDtcLow) || (mSsens_sMrtTempLow
         > D01TEMP.sMtrTempSnsrDtcHigh))
    {
        sF11_T30_MtrTempSnsrFlt = Cnst_F11_MtrTempSnsrFlt;
    }
    else if (mSsens_sMrtTempLow > D01TEMP.sMtrOvrTempFltDtcLvl)
    {
        sF12_T30_MtrTempOvrFlt = Cnst_F12_MtrTempOvrFlt;
    }
    else
    {
        /*  No Action  */
    }
}

/* System initialize for action system: '<S4>/Ftn_T30IvtTempFltDtc' */
static void Ftn_T30IvtTempFltDtc_Init(void)
{
    sF09_T30_IvtTempSnsrFlt = 0UL;
    sF10_T30_IvtTempOvrFlt = 0UL;
    mDIAG_uFan1On0Off = 0U;
}

/* Output and update for action system: '<S4>/Ftn_T30IvtTempFltDtc' */
static void Ftn_T30IvtTempFltDtc(void)
{
    if (mSsens_sIvtTempLow > D01TEMP.sIvtOvrTempFltDtcLvl)
    {
        sF10_T30_IvtTempOvrFlt = Cnst_F010_IvtTempOvrFlt;
    }
    else if (mSsens_sIvtTempLow > D01TEMP.sFanOnIvtTempSet)
    {
        mDIAG_uFan1On0Off = 1U;
    }
    else if (mSsens_sIvtTempLow < D01TEMP.sFanOffIvtTempSet)
    {
        mDIAG_uFan1On0Off = 0U;
    }
    else if (mSsens_sIvtTempLow < D01TEMP.sIvtTempSnsrFltDtcLow)
    {
        sF09_T30_IvtTempSnsrFlt = Cnst_F09_IvtTempSnsrFlt;
    }
    else
    {
        /*  No Action  */
    }
}

/* System initialize for action system: '<S4>/Ftn_T30InitNvRamDtc' */
static void Ftn_T30InitNvRamDtc_Init(void)
{
    sF16_T10_InitNvRam = 0UL;
}

/* Output and update for action system: '<S4>/Ftn_T30InitNvRamDtc' */
static void Ftn_T30InitNvRamDtc(void)
{
    if (mBSW_uInitNvRam == 1U)
    {
        sF16_T10_InitNvRam = Cnst_F16_T10_InitNvRam;
    }
    else
    {
        /*  No Action  */
    }
}

/* System initialize for action system: '<S4>/Ftn_T10MtrSpdFltDtc' */
static void Ftn_T10MtrSpdFltDtc_Init(void)
{
    sF13_T10_MtrSpdFlt = 0UL;
    GvD01DW.mDIAG_i32CntCurrOver = 0L;
}

/* Output and update for action system: '<S4>/Ftn_T10MtrSpdFltDtc' */
static void Ftn_T10MtrSpdFltDtc(void)
{
    if (mMTPST_sRpm >= D01SPD.sOvrSpdFltDtcLvl)
    {
        if (GvD01DW.mDIAG_i32CntCurrOver >= D01SPD.i32OvrSpdFltDebCnt)
        {
            GvD01DW.mDIAG_i32CntCurrOver = D01SPD.i32OvrSpdFltDebCnt;
            sF13_T10_MtrSpdFlt = Cnst_F13_MtrSpdFlt;
        }
        else
        {
            GvD01DW.mDIAG_i32CntCurrOver++;
        }
    }
    else
    {
        GvD01DW.mDIAG_i32CntCurrOver = 0L;
    }
}

/* System initialize for atomic system: '<Root>/Ftn_T30DiagGroup' */
static void Ftn_T30DiagGroup_Init(void)
{
    Ftn_T30StalAndCrtSnsrFltDt_Init();
    Ftn_T30MtrTempFltDtc_Init();
    Ftn_T30IvtTempFltDtc_Init();
    Ftn_T30InitNvRamDtc_Init();
    Ftn_T10MtrSpdFltDtc_Init();
}

/* Output and update for atomic system: '<Root>/Ftn_T30DiagGroup' */
static void Ftn_T30DiagGroup(void)
{
    switch (mSched_i32CntForSch)
    {
      case 28L:
        Ftn_T30StalAndCrtSnsrFltDtc();
        break;

      case 24L:
        Ftn_T30MtrTempFltDtc();
        break;

      case 18L:
        Ftn_T30IvtTempFltDtc();
        break;

      case 2L:
        Ftn_T30InitNvRamDtc();
        break;

      case 6L:
      case 26L:
        Ftn_T10MtrSpdFltDtc();
        break;

      default:
        /* no actions */
        break;
    }
}

/* Model step function */
void d01_Diaglnteg_step(void)
{
    Ftn_T01CalCurrMax();
    Ftn_T30DiagGroup();
    Ftn_T01DiagGroup();
    Ftn_T01Diaglntegration();
}

/* Model initialize function */
void d01_Diaglnteg_initialize(void)
{
    /* Registration code */

    /* states (dwork) */
    (void) memset((void *)&GvD01DW, 0,
                  sizeof(StrD01DW));

    /* external outputs */
    mDIAG_uFltStat = 0U;
    mDIAG_u32FltAll = 0UL;
    mDIAG_uChprOpr1On0Off = 0U;
    mDIAG_uFan1On0Off = 0U;
    mDIAG_uCntCrtOvr = 0U;
    sF01_T01_EstopSwitchFlt = 0UL;
    sF02_T01_IgptShrtFlt = 0UL;
    sF03_T01_HvdcOvrVolFlt = 0UL;
    sF04_T01_HvdcUdrVolFlt = 0UL;
    sF05_T30_CrtSnsrFlt = 0UL;
    sF06_T30_CrtSnsrOfsFlt = 0UL;
    sF07_T30_CrtStallFlt = 0UL;
    sF08_T01_CrtOvrFlt = 0UL;
    sF09_T30_IvtTempSnsrFlt = 0UL;
    sF10_T30_IvtTempOvrFlt = 0UL;
    sF11_T30_MtrTempSnsrFlt = 0UL;
    sF12_T30_MtrTempOvrFlt = 0UL;
    sF13_T10_MtrSpdFlt = 0UL;
    sF16_T10_InitNvRam = 0UL;
    Ftn_T30DiagGroup_Init();
    Ftn_T01DiagGroup_Init();
    Ftn_T01Diaglntegration_Init();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
