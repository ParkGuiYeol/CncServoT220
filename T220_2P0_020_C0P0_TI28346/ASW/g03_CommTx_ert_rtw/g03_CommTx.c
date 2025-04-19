/*
 * File: g03_CommTx.c
 *
 * Code generated for Simulink model 'g03_CommTx'.
 *
 * Model version                  : 7.370
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Apr 19 17:42:21 2025
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

#include "g03_CommTx.h"
#include "rtwtypes.h"
#include "c01_MainAdc.h"
#include "c02_SubAdc.h"
#include "e03_MtrCtrl_MtrCtrl.h"
#include "e02_MtrCtrl_Pst.h"
#include "h01_MdeMgmt.h"
#include "M2_Interrupt.h"
#include "d01_Diaglnteg.h"

/* Named constants for Chart: '<S1>/Chart_CntForTx2' */
#define ConstG01_i32InitCntForTx2      (0L)

/* Named constants for Chart: '<S1>/Nftn_CommDataParsingTx2' */
#define Cnst_u32_0                     (0UL)
#define Cnst_u32_32                    (32UL)

/* Exported block signals */
uint32_T mCTX_u32DataLowTx1;           /* '<Root>/bG03CTX_mCTX_u32DataLowTx1' */
uint32_T mCTX_u32DataHighTx1;         /* '<Root>/bG03CTX_mCTX_u32DataHighTx1' */
uint32_T mCTX_u32DataLowTx2;           /* '<Root>/bG03CTX_mCTX_u32DataLowTx2' */
uint32_T mCTX_u32DataHighTx2;         /* '<Root>/bG03CTX_mCTX_u32DataHighTx2' */

/* Exported data definition */

/* Definition for custom storage class: FileScope */
static S_CTX3 CTX3 =
{
    {
        2.0F, 2.0F, 2.0F, 10.0F, 10.0F, 1.0F
    },

    {
        0U, 12U, 22U, 32U, 42U, 52U
    },

    {
        0.0F, -40.0F, -40.0F, -51.1F, -51.1F, 0.0F
    },

    {
        0.0F, -40.0F, -40.0F, -51.1F, -51.1F, 0.0F
    },

    {
        2047.5F, 471.5F, 471.5F, 51.2F, 51.2F, 4095.0F
    },

    {
        4294963200U, 4290777087U, 4194303U, 4294966272U, 4293919743U, 1048575U
    },
    5,
    1U,
    0U
} ;                                    /* Referenced by:
                                        * '<S1>/CB_CTX3_a6sClearBitTx1'
                                        * '<S1>/CB_CTX3_a6sInvFactorTx1'
                                        * '<S1>/CB_CTX3_a6sMaxTx1'
                                        * '<S1>/CB_CTX3_a6sMinTx1'
                                        * '<S1>/CB_CTX3_a6sOffsetTx1'
                                        * '<S1>/CB_CTX3_a6u32StartBitTx1'
                                        * '<S1>/CB_CTX3_i32CntMaxForTx3'
                                        * '<S2>/CB_CTX2_uSW_REV'
                                        */

/* Block signals and states (default storage) */
StrG03DW GvG03DW;
static void Ftn_CommDataParsingTx1_Init(void);
static void Ftn_CommDataParsingTx1(void);
static void Ftn_CommDataParsingTx2(void);

/* System initialize for atomic system: '<Root>/Ftn_CommDataParsingTx1' */
static void Ftn_CommDataParsingTx1_Init(void)
{
    GvG03DW.i32inxTx3 = 0L;
    GvG03DW.u32DataLowTx2 = 0UL;
    GvG03DW.u32DataHighTx2 = 0UL;
}

/* Output and update for atomic system: '<Root>/Ftn_CommDataParsingTx1' */
static void Ftn_CommDataParsingTx1(void)
{
    real32_T rtb_TmpSignalConversionAtSFunct[6];
    real32_T sTxData;
    uint32_T a32u32TxData;
    if (GvG03DW.i32inxTx3 >= CTX3.i32CntMaxForTx3)
    {
        GvG03DW.i32inxTx3 = ConstG01_i32InitCntForTx2;
    }
    else
    {
        GvG03DW.i32inxTx3++;
    }

    rtb_TmpSignalConversionAtSFunct[0] = mMsens_sHVdcLow;
    rtb_TmpSignalConversionAtSFunct[1] = mSsens_sIvtTempLow;
    rtb_TmpSignalConversionAtSFunct[2] = mSsens_sMrtTempLow;
    rtb_TmpSignalConversionAtSFunct[3] = mCTRL_sTqRefIn;
    rtb_TmpSignalConversionAtSFunct[4] = mCTRL_sIsRef;
    rtb_TmpSignalConversionAtSFunct[5] = mMTPST_sRpm;
    if (rtb_TmpSignalConversionAtSFunct[GvG03DW.i32inxTx3] >= CTX3.a6sMaxTx1
            [(GvG03DW.i32inxTx3)])
    {
        sTxData = CTX3.a6sMaxTx1[(GvG03DW.i32inxTx3)];
    }
    else if (rtb_TmpSignalConversionAtSFunct[GvG03DW.i32inxTx3] <=
             CTX3.a6sMinTx1[(GvG03DW.i32inxTx3)])
    {
        sTxData = CTX3.a6sMinTx1[(GvG03DW.i32inxTx3)];
    }
    else
    {
        sTxData = rtb_TmpSignalConversionAtSFunct[GvG03DW.i32inxTx3];
    }

    a32u32TxData = (uint32_T)((real32_T)((sTxData - CTX3.a6sOffsetTx1
        [(GvG03DW.i32inxTx3)]) * CTX3.a6sInvFactorTx1[(GvG03DW.i32inxTx3)]));
    if (CTX3.a6u32StartBitTx1[(GvG03DW.i32inxTx3)] >= Cnst_u32_32)
    {
        /*  Spare bit is always set to 1. (The initial value of u32DataHighTx2 is set to 0x80000000.) */
        GvG03DW.u32DataHighTx2 &= CTX3.a6sClearBitTx1[(GvG03DW.i32inxTx3)];
        if (CTX3.a6u32StartBitTx1[(GvG03DW.i32inxTx3)] != Cnst_u32_32)
        {
            a32u32TxData <<= (uint64_T)((uint32_T)(CTX3.a6u32StartBitTx1
                [(GvG03DW.i32inxTx3)] - 32UL));
        }

        GvG03DW.u32DataHighTx2 |= a32u32TxData;
    }
    else
    {
        GvG03DW.u32DataLowTx2 &= CTX3.a6sClearBitTx1[(GvG03DW.i32inxTx3)];
        if (CTX3.a6u32StartBitTx1[(GvG03DW.i32inxTx3)] != Cnst_u32_0)
        {
            a32u32TxData <<= (uint64_T)CTX3.a6u32StartBitTx1[(GvG03DW.i32inxTx3)];
        }

        GvG03DW.u32DataLowTx2 |= a32u32TxData;
    }

    mCTX_u32DataLowTx1 = GvG03DW.u32DataLowTx2;
    mCTX_u32DataHighTx1 = GvG03DW.u32DataHighTx2;
}

/* Output and update for atomic system: '<Root>/Ftn_CommDataParsingTx2' */
static void Ftn_CommDataParsingTx2(void)
{
    /* :  switch mode */
    /* :  case 1 */
    /* :  y = bitsll(cast_to_fi(u), N); */
    mCTX_u32DataLowTx2 = ((uint32_T)mSMDE_uOrgNotDef) | (((uint32_T)
        mBSW_uExinputAll) << 16U);

    /* :  switch mode */
    /* :  case 1 */
    /* :  y = bitsll(cast_to_fi(u), N); */
    /* :  switch mode */
    /* :  case 1 */
    /* :  y = bitsll(cast_to_fi(u), N); */
    mCTX_u32DataHighTx2 = (mDIAG_u32FltAll | ((((uint32_T)mSMDE_uOprState) <<
        19U) & 16252928UL)) | ((((uint32_T)CTX3.uSW_REV) << 24U) & 4278190080UL);
}

/* Model step function */
void g03_CommTx_step(void)
{
    Ftn_CommDataParsingTx1();
    Ftn_CommDataParsingTx2();
}

/* Model initialize function */
void g03_CommTx_initialize(void)
{
    /* Registration code */

    /* states (dwork) */
    (void) memset((void *) &GvG03DW, 0,
                  sizeof(StrG03DW));

    /* external outputs */
    mCTX_u32DataLowTx1 = 0UL;
    mCTX_u32DataHighTx1 = 0UL;
    mCTX_u32DataLowTx2 = 0UL;
    mCTX_u32DataHighTx2 = 0UL;
    Ftn_CommDataParsingTx1_Init();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
