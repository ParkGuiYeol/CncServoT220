/*
 * File: M2_Interrupt.c
 *
 * C/C++ source code generated on : Sun Mar 16 11:41:14 2025
 * Created by: System Research Team
 *
 */
#include "Define_Header.h"
#include "M2_Interrupt.h"
#include "j01_McuInit.h"
#include "h01_MdeMgmt.h"

/* Definition for custom storage class: FileScope */
uint16_T uFlagDigInDebZ = 0U, uFlagDigInDeb = 0U;
int32_T i32CntDigtInDeb = 0;
int32_T i32DigtInDebCntSet = 0;
uint16_T mBSW_uEstpSwitchDtc = 0U;
uint16_T mBSW_a11uReadInput[11] = {0U};
uint16_T mBSW_uExinputAll = 0U;
S_EXINPUT uEXINPUT = {0U}, uEXINPUT_Z = {0U};
S_EXOUTPUT uEXOUTPUT = {0U};


/* Block signals and states (default storage) */
static void ExDigInput(void);
static void ExDigOutput(void);
static void DigitalOutSet(void);

/* M12_Interrupt step function */
interrupt void M2_Interrupt(void)
{
    // DSP to FPGA
    M2_INT_ON;

    // Encoder data request
    FPGA_Send(0x10, 0);

    // External Digital Input
    ExDigInput();

    // Digital Output Allocation
    DigitalOutSet();

    // External Digital Output
    ExDigOutput();

    /* External Digital Output */
    FPGA_Send(0x05, uEXOUTPUT.all);    // I/O Output.

    M2_INT_OFF;                        // Interrupt Start Signal(DSP to FPGA)
    EPwm2Regs.ETCLR.bit.INT = 1;       // ePWM1 Interrupt Clear
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;// ePWM1 PIE Interrupt Clear
    return;
}

interrupt void M2_Offset(void)
{
    // Interrupt Start Signal(DSP �� FPGA)
    M2_INT_ON;

    // Encoder data request
    FPGA_Send(0x10, 0);

    // External Digital Input
    ExDigInput();

    // System '<Root>/TmpModelReferenceSubsystem
    if (mMinit_uFlgChangeISR == 1U)
    {
        // Interrupt Function Change
        EALLOW;
        PieVectTable.EPWM2_INT = &M2_Interrupt;
        EDIS;
    }

    // Interrupt End Signal (DSP �� FPGA)
    M2_INT_OFF;

    // ePWM2 Interrupt Clear
    EPwm2Regs.ETCLR.bit.INT = 1;
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

    return;
}

void ExDigInput(void)
{
    // Receive I/O Input //
    uEXINPUT.all = ~((int32)(((((int32)(FPGA_Receive(0x0D))|0x04)&0x07)<<16)|
                      ((int32)(FPGA_Receive(0x0C) & 0xff)<<8)|(int32)
                      (FPGA_Receive(0x0B) & 0xff))|0xFFF80000);

    if (uEXINPUT.all == uEXINPUT_Z.all)
    {
        if (i32CntDigtInDeb >= i32DigtInDebCntSet)
        {
            i32CntDigtInDeb = i32DigtInDebCntSet;

            uFlagDigInDeb = 1U;
        }
        else
        {
            i32CntDigtInDeb++;
        }
    }
    else
    {
        i32CntDigtInDeb = 0L;
        uFlagDigInDeb = 0U;
    }

    if((uFlagDigInDebZ == 0U)&&(uFlagDigInDeb == 1U))
    {
        mBSW_uExinputAll = uEXINPUT.all;
        mBSW_a11uReadInput[0] = uEXINPUT.bit.uSvOn;
        mBSW_a11uReadInput[1] = uEXINPUT.bit.uStart;
        mBSW_a11uReadInput[2] = uEXINPUT.bit.uEmg;
        mBSW_a11uReadInput[3] = uEXINPUT.bit.uAlarmRst;
        mBSW_a11uReadInput[4] = uEXINPUT.bit.uRefPst;
        mBSW_a11uReadInput[5] = uEXINPUT.bit.uStop;
        mBSW_a11uReadInput[6] = uEXINPUT.bit.uOrgin;
        mBSW_a11uReadInput[7] = uEXINPUT.bit.uDogin;
        mBSW_a11uReadInput[8] = uEXINPUT.bit.uPJog;
        mBSW_a11uReadInput[9] = uEXINPUT.bit.uNJog;
        mBSW_a11uReadInput[10] = uEXINPUT.bit.uEnMpg;

        mBSW_uEstpSwitchDtc = uEXINPUT.bit.uEmg;
    }

    uFlagDigInDebZ = uFlagDigInDeb;
    uEXINPUT_Z.all = uEXINPUT.all;
}

void ExDigOutput(void)
{
    uEXOUTPUT.bit.uStadby = GvH01Y.bH01SMDE_mSMDE_uExOut.uStadby;
    uEXOUTPUT.bit.uActPst = GvH01Y.bH01SMDE_mSMDE_uExOut.uActPst;
    uEXOUTPUT.bit.uAlarm = GvH01Y.bH01SMDE_mSMDE_uExOut.uAlarm;
    uEXOUTPUT.bit.uInPst = GvH01Y.bH01SMDE_mSMDE_uExOut.uInPst;
    uEXOUTPUT.bit.uOrgNotDef = GvH01Y.bH01SMDE_mSMDE_uExOut.uOrgNotDef;
}

void DigitalOutSet(void)
{
    if(mDIAG_uChprOpr1On0Off == 1U)
    {
        DC_RELAY_ON;
    }
    else
    {
        DC_RELAY_OFF;
    }

    if(mDIAG_uFan1On0Off == 1U)
    {
        FAN_ON;
    }
    else
    {
        FAN_OFF;
    }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
