/*
 * File: M1_Interrupt.c
 *
 * C/C++ source code generated on : Sun Mar 16 11:41:14 2025
 * Created by: System Research Team
 *
 */

#include "Define_Header.h"
#include "M1_Interrupt.h"

/* Definition for custom storage class: FileScope */
uint16_T mBSW_uInitNvRam = 0U;
uint16_T mEnc_uCF = 0U;
uint16_T mEnc_uSF = 0U;
uint16_T mEnc_uEND = 0U;
uint16_T mEnc_uALMC = 0U;
uint16_T mEnc_uCRC = 0U;
uint16_T mEnc_uABS0 = 0U;
uint16_T mEnc_uABS1 = 0U;
uint16_T mEnc_uABS2 = 0U;
uint16_T mEnc_uABM0 = 0U;
uint16_T mEnc_uABM1 = 0U;
uint16_T mEnc_uABM2 = 0U;
uint16_T mCRX_uAlarmRstZ = 0U;

/* Block signals and states (default storage) */
static void ReadEncData(void);

/* M1_Interrupt step function */
interrupt void M1_Interrupt(void)
{
    // FPAG ADC CONVST(DSP �� FPGA, Conversion Start ~ End of Conversion -> 4usec)
    M1_INT_ON;

    // Parallel ADC CONVST(ADC Conversion Start ~ End of Conversion -> 4usec: (16~20 Clk) * 3(CH2*3) = 60 clk = 60* 1/15Mhz = 4 usec)
    ADC_CONVST();
    DELAY_US(4);

    // Position_Read
    ReadEncData();

    // Current Sensing
    b01_OSnScheduler_step();
    L02_ADC_READ();
    c01_MainAdc_step();
    c02_SubAdc_step();
    d01_Diaglnteg_step();
    e01_MtrCtrl_VarGain_step();
    e02_MtrCtrl_Pst_step();
    e03_MtrCtrl_MtrCtrl_step();
    e04_MtrCtrl_PwmSet_step();



    // PWM Output & Enable
    if ((mDIAG_uFltStat == 0U)&&(mSMDE_uFlagInverterOut != 0U))
    {
        PWM1_ON;
    }
    else
    {
        PWM1_OFF;

        // System Reset
        if ((mCRX_uAlarmRst == 1U) && (mCRX_uAlarmRstZ == 0U))
        {
            d01_Diaglnteg_initialize();
            h01_MdeMgmt_initialize();
        }

        mCRX_uAlarmRstZ = mCRX_uAlarmRst;
    }

    // PWM Set
    PWM_SetDuty(mGPwm_sVanRef, mGPwm_sVbnRef, mGPwm_sVcnRef, mMsens_sInvHVdcLow);

    // Digital to Analog Converting
    DAC_Out();

    // Interrupt End Signal (DSP �� FPGA)
    M1_INT_OFF;

    // ePWM1 PIE Interrupt Clear
    EPwm1Regs.ETCLR.bit.INT = 1;
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

    return;
}

interrupt void M1_Offset(void)
{
    // FPAG ADC CONVST(DSP �� FPGA, Conversion Start ~ End of Conversion -> 4usec)
    M1_INT_ON;

    // Parallel ADC CONVST(ADC Conversion Start ~ End of Conversion -> 4usec: (16~20 Clk) * 3(CH2*3) = 60 clk = 60* 1/15Mhz = 4 usec)
    ADC_CONVST();
    DELAY_US(4);

    // Current Sensing
    b01_OSnScheduler_step();
    L02_ADC_READ();
    c01_MainAdc_step();
    c02_SubAdc_step();
    j01_McuInit_step();

    // System '<Root>/TmpModelReferenceSubsystem'
    if (mMinit_uFlgChangeISR == 1U)
    {
        // Interrupt Function Change
        EALLOW;
        PieVectTable.EPWM1_INT = &M1_Interrupt;
        EDIS;
    }

    // Interrupt End Signal (DSP �� FPGA)
    M1_INT_OFF;

    // ePWM1 PIE Interrupt Clear
    EPwm1Regs.ETCLR.bit.INT = 1;
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

    return;
}


void ReadEncData(void)
{
    mEnc_uCF    = FPGA_Receive(0x12);
    mEnc_uSF    = FPGA_Receive(0x13);
    mEnc_uEND   = FPGA_Receive(0x17);
    mEnc_uALMC  = FPGA_Receive(0x1B);
    mEnc_uCRC   = FPGA_Receive(0x1C);
    mEnc_uABS0  = FPGA_Receive(0x14);
    mEnc_uABS1  = FPGA_Receive(0x15);
    mEnc_uABS2  = FPGA_Receive(0x16);
    mEnc_uABM0  = FPGA_Receive(0x18);
    mEnc_uABM1  = FPGA_Receive(0x19);
    mEnc_uABM2  = FPGA_Receive(0x1A);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
