/*
 *	CAN.c
 *
 * C/C++ source code generated on : Thu Jan 11 10:09:04 2024
 * Created by: System Research Team
 * Code generated on : Sat Mar 15 00:16:24 2025
 *
 */

#include "Define_Header.h"
#include "D01_DRV_CAN.h"
#include "g03_CommTx.h"
#include "rtwtypes.h"

// Predefine
//// Predefine : Maximum Number of Used eCAN Module.
#define CAN_INDEX_MAX               1

#define CAN_MC_HOST                 ECanaRegs
#define CAN_MB_HOST                 ECanaMboxes
//#define CAN_MC_HOST_1             ECanbRegs
//#define CAN_MB_HOST_1             ECanbMboxes
volatile struct ECAN_REGS *CANREGS[CAN_INDEX_MAX] = {&CAN_MC_HOST};
volatile struct ECAN_MBOXES *CANMBOXES[CAN_INDEX_MAX] = {&CAN_MB_HOST};

uint32_T CAN_RX_ID[6] = {0x060F, 0x0610, 0x0611, 0x0612, 0x0613, 0x0614};
uint32_T CAN_TX_ID[7] = {0x0619, 0x061A, 0x061B, 0x061C, 0x061D, 0x061E, 0x061F};

uint16_T mCRX1_uRxChSel = 0U;
uint32_T mCRX1_u32CrrDataLow = 0U;
uint32_T mCRX1_u32CrrDataHigh = 0U;

//================================================ Code ================================================//
void Init_eCAN(void)
{
    struct ECAN_REGS eCAN_Shadow;                                                       // CAN Shadow Register for only 32bit Access
    int temp_index = 0;

    // Main Can Register Setting
    for (temp_index = 0; temp_index < CAN_INDEX_MAX; temp_index++)
    {
        EALLOW;

        CANPRegsWrite(CANREGS[temp_index], TIOC, CANTIOC_TXFUNC_TxEnable);              // 3        : TXFUNC    ; 1(CANTX pin is Used)
        CANPRegsWrite(CANREGS[temp_index], RIOC, CANRIOC_RXFUNC_RxEnable);              // 3        : RXFUNC    ; 1(CANRX pin is Used)

        CANPRegsOR(CANREGS[temp_index], MC, CANMC_CCR_ConfigureModeRequest);            // 12       : CCR       ;  0(Normal Mode Req.), 1(Configure Mode Req.).

        // Wait for the Approving of CPU Access
        do
            eCAN_Shadow.CANES.all = CANREGS[temp_index]->CANES.all;                     // Load CANES Register
        while(eCAN_Shadow.CANES.bit.CCE == 0);                                          // Check Configuration Mode Approbation.

        // Configure Bit Timing Parameter
        CANPRegsWrite(CANREGS[temp_index], BTC, CANBTC_BRP_Value(9)                     // 23-16    : BRPreg    ; TQ = (BRPreg + 1) * 4 / Fsys.
                                                                                        //                      ; 133.3[ns] = 10 * 4 / 300[MHz] => 7.5 [MHz]
                                                | CANBTC_SJW_Value(1)                   // 9-8      : SJWreg    ; SJW_max = min(4TQ, TSEG2reg + 1).
                                                | CANBTC_SAM_3Samples                   // 7        : SAM       ; 0(1 Sampling), 1(3 Sampling).
                                                | CANBTC_TSEG1_Value(8)                 // 6-3      : TSEG1reg  ; TSEG1 = TSEG1reg + 1.
                                                | CANBTC_TSEG2_Value(4));               // 2-0      : TSEG2reg  ; TSEG2 = TSEG2reg + 1.
                                                                                        //                      ; Baud Rate = 1 / TQ / (TSEG1 + TSEG2 + 1).
                                                                                        //                      ; 500[kbps] = 1 / 133.3[ns] / (9 + 5 + 1) with 66% Sample.

        CANPRegsWrite(CANREGS[temp_index], MC, CANMC_SUSP_FreeRun                       // 16       : SUSPEND   ; 0(Soft Mode), 1(Free Mode).
                                            | CANMC_MBCC_TSCountNormal                  // 15       : MBCC      ; 0(Normal Count), 1(Count Reset).
                                            | CANMC_SCB_eCANMode                        // 13       : SCB       ; 0(SCC Mode), 1(eCAN Mode).
                                            | CANMC_CCR_NormalModeRequest               // 12       : CCR       ; 0(Normal Mode Req.), 1(Configure Mode Req.).
                                            | CANMC_PDR_NormalModeRequest               // 11       : PDR       ; 0(Normal Mode Req.), 1(Power Down Mode Req.).
                                            | CANMC_DBO_LSBFirst                        // 10       : DBO       ; 0(MSB First_Most), 1(LSB First_Least).
                                            | CANMC_WUBA_PowerDownAutoRecovery          // 9        : WUBA      ; 0(Manual Power Recovery), 1(Auto Power Recovery).
                                            | CANMC_CDR_MBNormaModeRequest              // 8        : CDR       ; 0(Normal Mode Req.), 1(MB Data Access Req.).
                                            | CANMC_ABO_AutoBusOn                       // 7        : ABO       ; 0(Manual Bus Off Recovery), 1(Auto Bus Off Recovery).
                                            | CANMC_STM_NormalMode);                    // 6        : STM       ; 0(Normal Mode), 1(Self Test Mode).

        // Initialize MSGCTRL of each Mailbox for proper Operation
        CANMBOXES[temp_index]->MBOX0.MSGCTRL.all = 0x00000000;
        CANMBOXES[temp_index]->MBOX1.MSGCTRL.all = 0x00000000;
        CANMBOXES[temp_index]->MBOX2.MSGCTRL.all = 0x00000000;
        CANMBOXES[temp_index]->MBOX3.MSGCTRL.all = 0x00000000;
        CANMBOXES[temp_index]->MBOX4.MSGCTRL.all = 0x00000000;
        CANMBOXES[temp_index]->MBOX5.MSGCTRL.all = 0x00000000;
        CANMBOXES[temp_index]->MBOX6.MSGCTRL.all = 0x00000000;
        CANMBOXES[temp_index]->MBOX7.MSGCTRL.all = 0x00000000;
        CANMBOXES[temp_index]->MBOX8.MSGCTRL.all = 0x00000000;
        CANMBOXES[temp_index]->MBOX9.MSGCTRL.all = 0x00000000;
        CANMBOXES[temp_index]->MBOX10.MSGCTRL.all = 0x00000000;
        CANMBOXES[temp_index]->MBOX11.MSGCTRL.all = 0x00000000;
        CANMBOXES[temp_index]->MBOX12.MSGCTRL.all = 0x00000000;
        CANMBOXES[temp_index]->MBOX13.MSGCTRL.all = 0x00000000;
        CANMBOXES[temp_index]->MBOX14.MSGCTRL.all = 0x00000000;
        CANMBOXES[temp_index]->MBOX15.MSGCTRL.all = 0x00000000;
        CANMBOXES[temp_index]->MBOX16.MSGCTRL.all = 0x00000000;
        CANMBOXES[temp_index]->MBOX17.MSGCTRL.all = 0x00000000;
        CANMBOXES[temp_index]->MBOX18.MSGCTRL.all = 0x00000000;
        CANMBOXES[temp_index]->MBOX19.MSGCTRL.all = 0x00000000;
        CANMBOXES[temp_index]->MBOX20.MSGCTRL.all = 0x00000000;
        CANMBOXES[temp_index]->MBOX21.MSGCTRL.all = 0x00000000;
        CANMBOXES[temp_index]->MBOX22.MSGCTRL.all = 0x00000000;
        CANMBOXES[temp_index]->MBOX23.MSGCTRL.all = 0x00000000;
        CANMBOXES[temp_index]->MBOX24.MSGCTRL.all = 0x00000000;
        CANMBOXES[temp_index]->MBOX25.MSGCTRL.all = 0x00000000;
        CANMBOXES[temp_index]->MBOX26.MSGCTRL.all = 0x00000000;
        CANMBOXES[temp_index]->MBOX27.MSGCTRL.all = 0x00000000;
        CANMBOXES[temp_index]->MBOX28.MSGCTRL.all = 0x00000000;
        CANMBOXES[temp_index]->MBOX29.MSGCTRL.all = 0x00000000;
        CANMBOXES[temp_index]->MBOX30.MSGCTRL.all = 0x00000000;
        CANMBOXES[temp_index]->MBOX31.MSGCTRL.all = 0x00000000;

        EDIS;

        // Wait for returning CAN Module to Normal Mode
        do
            eCAN_Shadow.CANES.all = CANREGS[temp_index]->CANES.all;                     // Load CANES Register.
        while(eCAN_Shadow.CANES.bit.CCE == 1);                                          // Check Normal Mode Approbation.

        // Initialize MailBoxes of Host Controller
        //// Initialize MailBoxes of Host Controller : MailBoxes Transmission Cancel.
        CANPRegsWrite(CANREGS[temp_index], TRR, 0xFFFFFFFF);                            // n(31 ~ 0): TRRn      ; 1(Cancels MailBox n Transmission Request)

        //// Initialize MailBoxes of Host Controller : Check Transmission Cancellation Completion.
        do
            eCAN_Shadow.CANTRS.all = CANREGS[temp_index]->CANTRS.all;
        while(eCAN_Shadow.CANTRS.all > 0);

        //// Initialize MailBoxes of Host Controller : All MailBoxes Disable for Setting.
        CANPRegsWrite(CANREGS[temp_index], ME, 0x00000000);                             // n(31 ~ 0): MEn       ; 0(MBn is Disable), 1(MBn is Enable).
    }

    // MailBoxes for Host Controller
    /******************** Receive Mailbox ********************/
    //#warning 상위 제어기 수신용
    //// MailBoxes for Host Controller : MailBox 0(Rx)
    CAN_MB_HOST.MBOX0.MSGID.all = MSGID_QUICK_NormalStandardID
                                | MSGID_StandardID_Value(CAN_RX_ID[0]);
    CAN_MB_HOST.MBOX0.MSGCTRL.all = MSGCTRL_DLC_8Byte;                                  // 3:0      : DLC       ; 8(8Byte Data Length), 7(7Byte Data Length), 6(6Byte Data Length), ..., 0(0Byte Data Length).

    //// MailBoxes for Host Controller : MailBox 1(Rx)
    CAN_MB_HOST.MBOX1.MSGID.all = MSGID_QUICK_NormalStandardID
                                | MSGID_StandardID_Value(CAN_RX_ID[1]);
    CAN_MB_HOST.MBOX1.MSGCTRL.all = MSGCTRL_DLC_8Byte;                                  // 3:0      : DLC       ; 8(8Byte Data Length), 7(7Byte Data Length), 6(6Byte Data Length), ..., 0(0Byte Data Length).

    //// MailBoxes for Host Controller : MailBox 2(Rx)
    CAN_MB_HOST.MBOX2.MSGID.all = MSGID_QUICK_NormalStandardID
                                | MSGID_StandardID_Value(CAN_RX_ID[2]);
    CAN_MB_HOST.MBOX2.MSGCTRL.all = MSGCTRL_DLC_8Byte;                                  // 3:0      : DLC       ; 8(8Byte Data Length), 7(7Byte Data Length), 6(6Byte Data Length), ..., 0(0Byte Data Length).

    //// MailBoxes for Host Controller : MailBox 3(Rx)
    CAN_MB_HOST.MBOX3.MSGID.all = MSGID_QUICK_NormalStandardID
                                | MSGID_StandardID_Value(CAN_RX_ID[3]);
    CAN_MB_HOST.MBOX3.MSGCTRL.all = MSGCTRL_DLC_8Byte;                                  // 3:0      : DLC       ; 8(8Byte Data Length), 7(7Byte Data Length), 6(6Byte Data Length), ..., 0(0Byte Data Length).

    //// MailBoxes for Host Controller : MailBox 4(Rx)
    CAN_MB_HOST.MBOX4.MSGID.all = MSGID_QUICK_NormalStandardID
                                | MSGID_StandardID_Value(CAN_RX_ID[4]);
    CAN_MB_HOST.MBOX4.MSGCTRL.all = MSGCTRL_DLC_8Byte;                                  // 3:0      : DLC       ; 8(8Byte Data Length), 7(7Byte Data Length), 6(6Byte Data Length), ..., 0(0Byte Data Length).

    //// MailBoxes for Host Controller : MailBox 5(Rx)
    CAN_MB_HOST.MBOX5.MSGID.all = MSGID_QUICK_NormalStandardID
                                | MSGID_StandardID_Value(CAN_RX_ID[5]);
    CAN_MB_HOST.MBOX5.MSGCTRL.all = MSGCTRL_DLC_8Byte;                                  // 3:0      : DLC       ; 8(8Byte Data Length), 7(7Byte Data Length), 6(6Byte Data Length), ..., 0(0Byte Data Length).

    /******************** Transmit Mailbox ********************/
    //#warning 상위 제어기 송신용
    // MailBoxes for Host Controller : MailBox 24(Tx)
    CAN_MB_HOST.MBOX24.MSGID.all = MSGID_QUICK_NormalStandardID
                                | MSGID_StandardID_Value(CAN_TX_ID[0]);
    CAN_MB_HOST.MBOX24.MSGCTRL.all = MSGCTRL_TPL_TX2ndPri                               // 12:8     : TPL       ; 31(Highest Priority), 30(2nd Priority), 29(3rd Priority), ..., 0(Lowest Priority).
                                | MSGCTRL_DLC_8Byte;                                    // 3:0      : DLC       ; 8(8Byte Data Length), 7(7Byte Data Length), 6(6Byte Data Length), ..., 0(0Byte Data Length).

    //// MailBoxes for Host Controller : MailBox 25(Tx)
    CAN_MB_HOST.MBOX25.MSGID.all = MSGID_QUICK_NormalStandardID
                                | MSGID_StandardID_Value(CAN_TX_ID[1]);
    CAN_MB_HOST.MBOX25.MSGCTRL.all = MSGCTRL_TPL_TX2ndPri                               // 12:8     : TPL       ; 31(Highest Priority), 30(2nd Priority), 29(3rd Priority), ..., 0(Lowest Priority).
                                | MSGCTRL_DLC_8Byte;                                    // 3:0      : DLC       ; 8(8Byte Data Length), 7(7Byte Data Length), 6(6Byte Data Length), ..., 0(0Byte Data Length).

    //// MailBoxes for Host Controller : MailBox 26(Tx)
    CAN_MB_HOST.MBOX26.MSGID.all = MSGID_QUICK_NormalStandardID
                                | MSGID_StandardID_Value(CAN_TX_ID[2]);
    CAN_MB_HOST.MBOX26.MSGCTRL.all = MSGCTRL_TPL_TX2ndPri                               // 12:8     : TPL       ; 31(Highest Priority), 30(2nd Priority), 29(3rd Priority), ..., 0(Lowest Priority).
                                | MSGCTRL_DLC_8Byte;                                    // 3:0      : DLC       ; 8(8Byte Data Length), 7(7Byte Data Length), 6(6Byte Data Length), ..., 0(0Byte Data Length).

    //// MailBoxes for Host Controller : MailBox 27(Tx)
    CAN_MB_HOST.MBOX27.MSGID.all = MSGID_QUICK_NormalStandardID
                                | MSGID_StandardID_Value(CAN_TX_ID[3]);
    CAN_MB_HOST.MBOX27.MSGCTRL.all = MSGCTRL_TPL_TX2ndPri                               // 12:8     : TPL       ; 31(Highest Priority), 30(2nd Priority), 29(3rd Priority), ..., 0(Lowest Priority).
                                | MSGCTRL_DLC_8Byte;                                    // 3:0      : DLC       ; 8(8Byte Data Length), 7(7Byte Data Length), 6(6Byte Data Length), ..., 0(0Byte Data Length).

    //// MailBoxes for Host Controller : MailBox 28(Tx)
    CAN_MB_HOST.MBOX28.MSGID.all = MSGID_QUICK_NormalStandardID
                                | MSGID_StandardID_Value(CAN_TX_ID[4]);
    CAN_MB_HOST.MBOX28.MSGCTRL.all = MSGCTRL_TPL_TX2ndPri                               // 12:8     : TPL       ; 31(Highest Priority), 30(2nd Priority), 29(3rd Priority), ..., 0(Lowest Priority).
                                | MSGCTRL_DLC_8Byte;                                    // 3:0      : DLC       ; 8(8Byte Data Length), 7(7Byte Data Length), 6(6Byte Data Length), ..., 0(0Byte Data Length).

    //// MailBoxes for Host Controller : MailBox 29(Tx)
    CAN_MB_HOST.MBOX29.MSGID.all = MSGID_QUICK_NormalStandardID
                                | MSGID_StandardID_Value(CAN_TX_ID[5]);
    CAN_MB_HOST.MBOX29.MSGCTRL.all = MSGCTRL_TPL_TX2ndPri                               // 12:8     : TPL       ; 31(Highest Priority), 30(2nd Priority), 29(3rd Priority), ..., 0(Lowest Priority).
                                | MSGCTRL_DLC_8Byte;                                    // 3:0      : DLC       ; 8(8Byte Data Length), 7(7Byte Data Length), 6(6Byte Data Length), ..., 0(0Byte Data Length).

    //// MailBoxes for Host Controller : MailBox 30(Tx)
    CAN_MB_HOST.MBOX30.MSGID.all = MSGID_QUICK_NormalStandardID
                                | MSGID_StandardID_Value(CAN_TX_ID[6]);
    CAN_MB_HOST.MBOX30.MSGCTRL.all = MSGCTRL_TPL_TX2ndPri                               // 12:8     : TPL       ; 31(Highest Priority), 30(2nd Priority), 29(3rd Priority), ..., 0(Lowest Priority).
                                | MSGCTRL_DLC_8Byte;                                    // 3:0      : DLC       ; 8(8Byte Data Length), 7(7Byte Data Length), 6(6Byte Data Length), ..., 0(0Byte Data Length).

    //// MailBoxes for Host Controller : Direction
    CANRegsWrite(CAN_MC_HOST, MD, CANMD_MB00_Rx                                         // 0        : MD0       ; 0(Tx MB0), 1(Rx MB0).
                                | CANMD_MB01_Rx                                         // 1        : MD1       ; 0(Tx MB1), 1(Rx MB1).
                                | CANMD_MB02_Rx                                         // 2        : MD2       ; 0(Tx MB2), 1(Rx MB2).
                                | CANMD_MB03_Rx                                         // 3        : MD3       ; 0(Tx MB3), 1(Rx MB3).
                                | CANMD_MB04_Rx                                         // 4        : MD4       ; 0(Tx MB4), 1(Rx MB4).
                                | CANMD_MB05_Rx);                                       // 5        : MD5       ; 0(Tx MB5), 1(Rx MB5).

    // Interrupt for Host Controller
    //// Interrupt for Host Controller : Interrupt Enable and Line
    EALLOW;
    CANRegsWrite(CAN_MC_HOST, MIM, CANMIM_MB00_InterruptEnable                          // 0        : MIM0      ; 0(MB0 Interrupt Disable), 1(MB0 Interrupt Enable).
                                | CANMIM_MB01_InterruptEnable                           // 1        : MIM1      ; 0(MB1 Interrupt Disable), 1(MB1 Interrupt Enable).
                                | CANMIM_MB02_InterruptEnable                           // 2        : MIM2      ; 0(MB2 Interrupt Disable), 1(MB2 Interrupt Enable).
                                | CANMIM_MB03_InterruptEnable                           // 3        : MIM2      ; 0(MB3 Interrupt Disable), 1(MB3 Interrupt Enable).
                                | CANMIM_MB04_InterruptEnable                           // 4        : MIM4      ; 0(MB4 Interrupt Disable), 1(MB4 Interrupt Enable).
                                | CANMIM_MB05_InterruptEnable);                         // 5        : MIM5      ; 0(MB5 Interrupt Disable), 1(MB5 Interrupt Enable).

    CANRegsWrite(CAN_MC_HOST, MIL, CANMIL_MB00_IntLine0                                 // 0        : MIL0      ; 0(MB0 Interrupt Uses Line 0), 1(MB0 Interrupt Uses Line 1).
                                | CANMIL_MB01_IntLine1                                  // 1        : MIL1      ; 0(MB1 Interrupt Uses Line 0), 1(MB1 Interrupt Uses Line 1).
                                | CANMIL_MB02_IntLine1                                  // 2        : MIL2      ; 0(MB2 Interrupt Uses Line 0), 1(MB2 Interrupt Uses Line 1).
                                | CANMIL_MB03_IntLine1                                  // 3        : MIL3      ; 0(MB3 Interrupt Uses Line 0), 1(MB3 Interrupt Uses Line 1).
                                | CANMIL_MB04_IntLine1                                  // 4        : MIL4      ; 0(MB4 Interrupt Uses Line 0), 1(MB4 Interrupt Uses Line 1).
                                | CANMIL_MB05_IntLine1);                                // 5        : MIL5      ; 0(MB5 Interrupt Uses Line 0), 1(MB5 Interrupt Uses Line 1).

    CANRegsWrite(CAN_MC_HOST, GIM, CANGIM_I1EN_IntLine1Enable                           // 1        : I1EN      ; 0(Interrupt Line 1 Disable), 1(Interrupt Line 1 Enable).
                                | CANGIM_I0EN_IntLine0Enable);                          // 0        : I0EN      ; 0(Interrupt Line 0 Disable), 1(Interrupt Line 0 Enable).
    EDIS;

    // MailBox Enable for Host Controller
    CANRegsWrite(CAN_MC_HOST, ME, CANMD_MB00_Enable                                     // 0        : ME0       ; 0(MB0 is Disable), 1(MB0 is Enable).
                                | CANMD_MB01_Enable                                     // 1        : ME1       ; 0(MB1 is Disable), 1(MB1 is Enable).
                                | CANMD_MB02_Enable                                     // 2        : ME2       ; 0(MB2 is Disable), 1(MB2 is Enable).
                                | CANMD_MB03_Enable                                     // 3        : ME3       ; 0(MB3 is Disable), 1(MB3 is Enable).
                                | CANMD_MB04_Enable                                     // 4        : ME4       ; 0(MB4 is Disable), 1(MB4 is Enable).
                                | CANMD_MB05_Enable                                     // 5        : ME5       ; 0(MB5 is Disable), 1(MB5 is Enable).

                                | CANMD_MB24_Enable                                     // 25       : ME25      ; 0(MB25 is Disable), 1(MB25 is Enable).
                                | CANMD_MB25_Enable                                     // 25       : ME25      ; 0(MB25 is Disable), 1(MB25 is Enable).
                                | CANMD_MB26_Enable                                     // 26       : ME26      ; 0(MB26 is Disable), 1(MB26 is Enable).
                                | CANMD_MB27_Enable                                     // 27       : ME27      ; 0(MB27 is Disable), 1(MB27 is Enable).
                                | CANMD_MB28_Enable                                     // 28       : ME28      ; 0(MB28 is Disable), 1(MB28 is Enable).
                                | CANMD_MB29_Enable                                     // 29       : ME29      ; 0(MB29 is Disable), 1(MB29 is Enable).
                                | CANMD_MB30_Enable);                                   // 30       : ME30      ; 0(MB30 is Disable), 1(MB30 is Enable).
    return;
}

// RX
// MailBox 0: 0x060F
// MailBox 1: 0x0610
// MailBox 2: 0x0611
// MailBox 3: 0x0612
// MailBox 4: 0x0613
// MailBox 5: 0x0614

// TX
// MailBox 24: 0x0619
// MailBox 25: 0x061A
// MailBox 26: 0x061B
// MailBox 27: 0x061C
// MailBox 28: 0x061D
// MailBox 29: 0x061E
// MailBox 29: 0x061F

// HCU CAN Communication
interrupt void ISR_CAN_HostRx(void)
{
    mCRX1_u32CrrDataLow = CAN_MB_HOST.MBOX0.MDL.all;
    mCRX1_u32CrrDataHigh = CAN_MB_HOST.MBOX0.MDH.all;

    CAN_MC_HOST.CANRMP.all |= MB00;
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

    return;
}

// WIA Monitoring CAN Communication
interrupt void ISR_CAN_HostRx_Monitor(void)
{
    mCRX1_uRxChSel = 1U;

    if (CAN_MC_HOST.CANRMP.all & MB01)
    {
//        mCRX1_u32CrrDataLow = CAN_MB_HOST.MBOX1.MDL.all;
//        mCRX1_u32CrrDataHigh = CAN_MB_HOST.MBOX1.MDH.all;

        CAN_MC_HOST.CANRMP.all |= MB01;
    }

    if (CAN_MC_HOST.CANRMP.all & MB02)
    {
//        CAN_RX_EX.GAIN.RT_Data.Data.Low = CAN_MB_HOST.MBOX2.MDL.all;
//        CAN_RX_EX.GAIN.RT_Data.Data.High = CAN_MB_HOST.MBOX2.MDH.all;

        CAN_MC_HOST.CANRMP.all |= MB02;
    }

    if (CAN_MC_HOST.CANRMP.all & MB03)                                      // Auto
    {
//        CAN_RX_EX.AUTO.RT_Data.Data.Low = CAN_MB_HOST.MBOX3.MDL.all;
//        CAN_RX_EX.AUTO.RT_Data.Data.High = CAN_MB_HOST.MBOX3.MDH.all;

        CAN_MC_HOST.CANRMP.all |= MB03;
    }

    if (CAN_MC_HOST.CANRMP.all & MB04)                                      // Fault_Level
    {
//        CAN_RX_EX.FAULT_LEVEL.RT_Data.Data.Low = CAN_MB_HOST.MBOX4.MDL.all;
//        CAN_RX_EX.FAULT_LEVEL.RT_Data.Data.High = CAN_MB_HOST.MBOX4.MDH.all;

        CAN_MC_HOST.CANRMP.all |= MB04;
    }

    if (CAN_MC_HOST.CANRMP.all & MB05)                                      // DAC
    {
//        CAN_RX_EX.DAC.RT_Data.Data.Low = CAN_MB_HOST.MBOX5.MDL.all;
//        CAN_RX_EX.DAC.RT_Data.Data.High = CAN_MB_HOST.MBOX5.MDH.all;

        CAN_MC_HOST.CANRMP.all |= MB05;
    }

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

    return;
}

void CAN_HostTx(uint32_T MBNum)
{
    if (CAN_MC_HOST.CANTRS.all & MBNum)                         // 송신 요청이 이미 있으면
    {
        CAN_MC_HOST.CANTRR.all |= MBNum;                        // 송신 취소
    }
    else
    {
                                                                // 송신 완료시 클리어
    }

    CAN_MC_HOST.CANTA.all |= MBNum;                             // 통신 완료됬다는 플래그, 1을 써주면 다시 클리어됨
    CAN_MC_HOST.CANAA.all |= MBNum;                             // 통신 Tx를 최소가 완료됨.

    switch (MBNum)
    {
        case MB23:

            CAN_MB_HOST.MBOX23.MDL.all = mCTX_u32DataLowTx1;
            CAN_MB_HOST.MBOX23.MDH.all = mCTX_u32DataHighTx1;

            break;

        case MB24:

            CAN_MB_HOST.MBOX24.MDL.all = mCTX_u32DataLowTx2;
            CAN_MB_HOST.MBOX24.MDH.all = mCTX_u32DataHighTx2;

            break;

        case MB25:

//            CAN_MB_HOST.MBOX25.MDL.all = CAN_TX1.Tx_Data.Data.Low;
//            CAN_MB_HOST.MBOX25.MDH.all = CAN_TX1.Tx_Data.Data.High;

            break;

        case MB26:

//            CAN_MB_HOST.MBOX26.MDL.all = CAN_TX2.Tx_Data.Data.Low;
//            CAN_MB_HOST.MBOX26.MDH.all = CAN_TX2.Tx_Data.Data.High;

            break;

        case MB27:

//            CAN_MB_HOST.MBOX27.MDL.all = CAN_TX_EX.GAIN.RT_Data.Data.Low;
//            CAN_MB_HOST.MBOX27.MDH.all = CAN_TX_EX.GAIN.RT_Data.Data.High;

            break;

        case MB28:

//            CAN_MB_HOST.MBOX28.MDL.all = CAN_TX_EX.AUTO.RT_Data.Data.Low;
//            CAN_MB_HOST.MBOX28.MDH.all = CAN_TX_EX.AUTO.RT_Data.Data.High;

            break;

        case MB29:

//            CAN_MB_HOST.MBOX29.MDL.all = CAN_TX_EX.FAULT_LEVEL.RT_Data.Data.Low;
//            CAN_MB_HOST.MBOX29.MDH.all = CAN_TX_EX.FAULT_LEVEL.RT_Data.Data.High;

            break;

        case MB30:

//            CAN_MB_HOST.MBOX30.MDL.all = CAN_TX_EX.DAC.RT_Data.Data.Low;
//            CAN_MB_HOST.MBOX30.MDH.all = CAN_TX_EX.DAC.RT_Data.Data.High;

            break;
        default:

            break;
    }

    CAN_MC_HOST.CANTRS.all |= MBNum;                            // 송신을 다시 하라고 요청

    return;
}

//void CAN_Communicaiton(void)
//{
//    static int COM_loop_cnt = 1;
//
//    switch (COM_loop_cnt++)         // 10 msec
//    {
//        //================================================= MB24 ================================================//
//        case CAN_TX_STEP_0:
//
//            CAN_HostTx(MB24);
//            break;
//        //================================================= MB25 ================================================//
//        case CAN_TX_STEP_1:
//
//            CAN_HostTx(MB25);
//            break;
//
//        //================================================= MB26 ================================================//
//        case CAN_TX_STEP_2:
//
//            CAN_HostTx(MB26);
//            break;
//
//        //================================================= MB27 ================================================//
//        case CAN_TX_STEP_3:
//
//            CAN_HostTx(MB27);
//            break;
//
//        //================================================= MB28 ================================================//
//        case CAN_TX_STEP_4:
//
//            CAN_HostTx(MB28);
//            break;
//
//        //================================================= MB29 ================================================//
//        case CAN_TX_STEP_5:
//
//            CAN_HostTx(MB29);
//            break;
//
//        //================================================= MB30 ================================================//
//        case CAN_TX_STEP_6:
//
//            CAN_HostTx(MB30);
//            COM_loop_cnt = 1;
//            break;
//    }
//}
