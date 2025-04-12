/*
 * File: f01_CommRx1.c
 *
 * Code generated for Simulink model 'f01_CommRx1'.
 *
 * Model version                  : 7.308
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Mar 29 20:36:42 2025
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

#include "f01_CommRx1.h"
#include "rtwtypes.h"
#include <string.h>
#include "D01_DRV_CAN.h"
#include "b01_OSnScheduler.h"

/* Named constants for Chart: '<S1>/Chart_CntForRx1' */
#define Cnst_i32InitCntForRx1          (0L)

/* Exported block signals */
uint16_T mCRX_uAllowingOperation;/* '<Root>/bF01CRX1_mCRX_uAllowingOperation' */
uint16_T mCRX_uCtrlMde0Digt1Can;  /* '<Root>/bF01CRX1_mCRX_uCtrlMde0Digt1Can' */
uint16_T mCRX_uMtrCtrlMde;             /* '<Root>/bF01CRX1_mCRX_uMtrCtrlMde' */
real32_T mCRX_sVltCurrTqCmd;          /* '<Root>/bF01CRX1_mCRX_sVltCurrTqCmd' */
real32_T mCRX_sFreqBetaCmd;            /* '<Root>/bF01CRX1_mCRX_sFreqBetaCmd' */
uint16_T mCRX_uSvOn;                   /* '<Root>/bF01CRX1_mCRX_uSvOn' */
uint16_T mCRX_uStart;                  /* '<Root>/bF01CRX1_mCRX_uStart' */
uint16_T mCRX_uEmg;                    /* '<Root>/bF01CRX1_mCRX_uEmg' */
uint16_T mCRX_uAlarmRst;               /* '<Root>/bF01CRX1_mCRX_uAlarmRst' */
uint16_T mCRX_uRefPst;                 /* '<Root>/bF01CRX1_mCRX_uRefPst' */
uint16_T mCRX_uStop;                   /* '<Root>/bF01CRX1_mCRX_uStop' */
uint16_T mCRX_uOrgin;                  /* '<Root>/bF01CRX1_mCRX_uOrgin' */
uint16_T mCRX_uDogin;                  /* '<Root>/bF01CRX1_mCRX_uDogin' */
uint16_T mCRX_uPJog;                   /* '<Root>/bF01CRX1_mCRX_uPJog' */
uint16_T mCRX_uNJog;                   /* '<Root>/bF01CRX1_mCRX_uNJog' */
uint16_T mCRX_uEnMpg;                  /* '<Root>/bF01CRX1_mCRX_uEnMpg' */
real32_T mCRX_sSpdCmd;                 /* '<Root>/bF01CRX1_mCRX_sSpdCmd' */
uint16_T mCRX_uDaCase;                 /* '<Root>/bF01CRX1_mCRX_uDaCase' */

/* Exported data definition */

/* Definition for custom storage class: FileScope */
static S_CRX1 CRX1 =
{
    {
        0U, 1U, 2U, 11U, 20U, 32U, 33U, 34U, 35U, 36U, 42U, 43U, 44U, 45U, 46U,
        47U, 48U, 58U
    },

    {
        1U, 1U, 9U, 9U, 12U, 1U, 1U, 1U, 1U, 6U, 1U, 1U, 1U, 1U, 1U, 1U, 10U, 6U
    },

    {
        1.0F, 1.0F, 1.0F, 0.1F, 0.1F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
        1.0F, 1.0F, 1.0F, 1.0F, 10.0F, 1.0F
    },

    {
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, -5110.0F, 0.0F
    },

    {
        1U, 2U, 2044U, 1046528U, 4293918720U, 1U, 2U, 4U, 8U, 1008U, 1024U,
        2048U, 4096U, 8192U, 16384U, 32768U, 67043328U, 4227858432U
    },
    32U,
    18,
    0U
} ;                                    /* Referenced by:
                                        * '<S1>/CB_CRX1_a18sClearBitRx1'
                                        * '<S1>/CB_CRX1_a18sFactor'
                                        * '<S1>/CB_CRX1_a18sOffset'
                                        * '<S1>/CB_CRX1_a18u32StartBit'
                                        * '<S1>/CB_CRX1_u32HalfBit'
                                        * '<S1>/CB_LTX2_i32CntMaxForTx2'
                                        */

/* Block signals and states (default storage) */
StrF01DW GvF01DW;

/* External inputs (root inport signals with default storage) */
StrF01ExtU GvF01U;
static void Ftn_Rx1Deparsing_Init(void);
static void Ftn_Rx1Deparsing(void);

/* System initialize for atomic system: '<Root>/Ftn_Rx1Deparsing' */
static void Ftn_Rx1Deparsing_Init(void)
{
    int16_T i;
    GvF01DW.inx = 0L;
    for (i = 0; i < 18; i++)
    {
        GvF01DW.sParsRlt1[i] = 0.0F;
    }

    mCRX_uAllowingOperation = 0U;
    mCRX_uCtrlMde0Digt1Can = 0U;
    mCRX_uMtrCtrlMde = 0U;
    mCRX_sVltCurrTqCmd = 0.0F;
    mCRX_sFreqBetaCmd = 0.0F;
    mCRX_uSvOn = 0U;
    mCRX_uStart = 0U;
    mCRX_uEmg = 0U;
    mCRX_uAlarmRst = 0U;
    mCRX_uRefPst = 0U;
    mCRX_uStop = 0U;
    mCRX_uOrgin = 0U;
    mCRX_uDogin = 0U;
    mCRX_uPJog = 0U;
    mCRX_uNJog = 0U;
    mCRX_uEnMpg = 0U;
    mCRX_sSpdCmd = 0.0F;
    mCRX_uDaCase = 0U;
}

/* Output and update for atomic system: '<Root>/Ftn_Rx1Deparsing' */
static void Ftn_Rx1Deparsing(void)
{
    uint32_T CRX1_u32Pars_Temp;
    if (GvF01DW.inx >= (CRX1.i32CntMaxForRx1 - 1L))
    {
        GvF01DW.inx = Cnst_i32InitCntForRx1;
    }
    else
    {
        GvF01DW.inx++;
    }

    if (mCRX1_uRxChSel != 0U)
    {
        if (CRX1.a18u32StartBit[(GvF01DW.inx)] >= CRX1.u32HalfBit)
        {
            CRX1_u32Pars_Temp = ((mCRX1_u32CrrDataHigh & CRX1.a18sClearBitRx1
                                  [(GvF01DW.inx)]) >> (CRX1.a18u32StartBit
                                  [(GvF01DW.inx)] - CRX1.u32HalfBit));
        }
        else
        {
            CRX1_u32Pars_Temp = ((mCRX1_u32CrrDataLow & CRX1.a18sClearBitRx1
                                  [(GvF01DW.inx)]) >> CRX1.a18u32StartBit
                                 [(GvF01DW.inx)]);
        }

        GvF01DW.sParsRlt1[GvF01DW.inx] = (((real32_T)CRX1_u32Pars_Temp) *
            CRX1.a18sFactor[(GvF01DW.inx)]) + CRX1.a18sOffset[(GvF01DW.inx)];
        mCRX_uDaCase = (uint16_T)GvF01DW.sParsRlt1[17];
        mCRX_uCtrlMde0Digt1Can = (uint16_T)GvF01DW.sParsRlt1[1];
        if (mCRX_uCtrlMde0Digt1Can == 0U)
        {
            mCRX_uAllowingOperation = 0U;
            mCRX_uMtrCtrlMde = 0U;
            mCRX_sVltCurrTqCmd = 0.0F;
            mCRX_sFreqBetaCmd = 0.0F;
            mCRX_uSvOn = mBSW_a11uReadInput[0];
            mCRX_uStart = mBSW_a11uReadInput[1];
            mCRX_uEmg = mBSW_a11uReadInput[2];
            mCRX_uAlarmRst = mBSW_a11uReadInput[3];
            mCRX_uRefPst = mBSW_a11uReadInput[4];
            mCRX_uStop = mBSW_a11uReadInput[5];
            mCRX_uOrgin = mBSW_a11uReadInput[6];
            mCRX_uDogin = mBSW_a11uReadInput[7];
            mCRX_uPJog = mBSW_a11uReadInput[8];
            mCRX_uNJog = mBSW_a11uReadInput[9];
            mCRX_uEnMpg = mBSW_a11uReadInput[10];
            mCRX_sSpdCmd = 0.0F;
        }
        else
        {
            mCRX_uAllowingOperation = (uint16_T)GvF01DW.sParsRlt1[0];
            mCRX_uMtrCtrlMde = (uint16_T)GvF01DW.sParsRlt1[2];
            mCRX_sVltCurrTqCmd = GvF01DW.sParsRlt1[3];
            mCRX_sFreqBetaCmd = GvF01DW.sParsRlt1[4];
            mCRX_uSvOn = (uint16_T)GvF01DW.sParsRlt1[5];
            mCRX_uStart = (uint16_T)GvF01DW.sParsRlt1[6];
            mCRX_uEmg = (uint16_T)GvF01DW.sParsRlt1[7];
            mCRX_uAlarmRst = (uint16_T)GvF01DW.sParsRlt1[8];
            mCRX_uRefPst = (uint16_T)GvF01DW.sParsRlt1[9];
            mCRX_uStop = (uint16_T)GvF01DW.sParsRlt1[10];
            mCRX_uOrgin = (uint16_T)GvF01DW.sParsRlt1[11];
            mCRX_uDogin = (uint16_T)GvF01DW.sParsRlt1[12];
            mCRX_uPJog = (uint16_T)GvF01DW.sParsRlt1[13];
            mCRX_uNJog = (uint16_T)GvF01DW.sParsRlt1[14];
            mCRX_uEnMpg = (uint16_T)GvF01DW.sParsRlt1[15];
            mCRX_sSpdCmd = GvF01DW.sParsRlt1[16];
        }
    }
    else
    {
        mCRX_uAllowingOperation = 0U;
        mCRX_uCtrlMde0Digt1Can = 0U;
        mCRX_uMtrCtrlMde = 0U;
        mCRX_sVltCurrTqCmd = 0.0F;
        mCRX_sFreqBetaCmd = 0.0F;
        mCRX_uSvOn = mBSW_a11uReadInput[0];
        mCRX_uStart = mBSW_a11uReadInput[1];
        mCRX_uEmg = mBSW_a11uReadInput[2];
        mCRX_uAlarmRst = mBSW_a11uReadInput[3];
        mCRX_uRefPst = mBSW_a11uReadInput[4];
        mCRX_uStop = mBSW_a11uReadInput[5];
        mCRX_uOrgin = mBSW_a11uReadInput[6];
        mCRX_uDogin = mBSW_a11uReadInput[7];
        mCRX_uPJog = mBSW_a11uReadInput[8];
        mCRX_uNJog = mBSW_a11uReadInput[9];
        mCRX_uEnMpg = mBSW_a11uReadInput[10];
        mCRX_sSpdCmd = 0.0F;
        mCRX_uDaCase = 0U;
    }
}

/* Model step function */
void f01_CommRx1_step(void)
{
    Ftn_Rx1Deparsing();
}

/* Model initialize function */
void f01_CommRx1_initialize(void)
{
    /* Registration code */

    /* states (dwork) */
    (void) memset((void *)&GvF01DW, 0,
                  sizeof(StrF01DW));

    /* external inputs */
    (void)memset(&GvF01U, 0, sizeof(StrF01ExtU));

    /* external outputs */
    mCRX_uAllowingOperation = 0U;
    mCRX_uCtrlMde0Digt1Can = 0U;
    mCRX_uMtrCtrlMde = 0U;
    mCRX_sVltCurrTqCmd = 0.0F;
    mCRX_sFreqBetaCmd = 0.0F;
    mCRX_uSvOn = 0U;
    mCRX_uStart = 0U;
    mCRX_uEmg = 0U;
    mCRX_uAlarmRst = 0U;
    mCRX_uRefPst = 0U;
    mCRX_uStop = 0U;
    mCRX_uOrgin = 0U;
    mCRX_uDogin = 0U;
    mCRX_uPJog = 0U;
    mCRX_uNJog = 0U;
    mCRX_uEnMpg = 0U;
    mCRX_sSpdCmd = 0.0F;
    mCRX_uDaCase = 0U;
    Ftn_Rx1Deparsing_Init();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
