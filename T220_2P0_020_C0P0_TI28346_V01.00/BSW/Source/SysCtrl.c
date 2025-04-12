/*
 *	SysCtrl.c
 *
 * C/C++ source code generated on : Thu Jan 11 10:09:04 2024
 * Created by: System Research Team
 * Code generated on : Sat Mar 15 00:16:24 2025
 *
 */

#include "D01_DRV_CAN.h"
#include "Define_Header.h"

void Init_PLL(void)
{
    // To write PLLCR Register, PLLSTS[DIVSEL] must be set to 0.
    if (SysCtrlRegs.PLLSTS.bit.DIVSEL != 0)
    {
        EALLOW;
        SysCtrlRegs.PLLSTS.bit.DIVSEL = 0;
        EDIS;
    }

    // Change PLLCR[DIV].
    if (SysCtrlRegs.PLLCR.bit.DIV != DSP28_PLLCR)
    {
        EALLOW;
        SysCtrlRegs.PLLCR.bit.DIV = DSP28_PLLCR;
        EDIS;
    }

    // Wait for PLL to lock.
    while(SysCtrlRegs.PLLSTS.bit.PLLLOCKS != 1);

    // Change PLLSTS[DIVSEL].
    // For power settle, it is changed step by step and needed delay time in each step.
    switch (DSP28_DIVSEL)
    {
        case 1 :
            EALLOW;
            SysCtrlRegs.PLLSTS.bit.DIVSEL = 1;
            EDIS;
            break;
        case 2 :
            EALLOW;
            SysCtrlRegs.PLLSTS.bit.DIVSEL = 1;
            DELAY_US(50L);
            SysCtrlRegs.PLLSTS.bit.DIVSEL = 2;
            EDIS;
            break;
        case 3 :
            EALLOW;
            SysCtrlRegs.PLLSTS.bit.DIVSEL = 1;
            DELAY_US(50L);
            SysCtrlRegs.PLLSTS.bit.DIVSEL = 2;
            DELAY_US(50L);
            SysCtrlRegs.PLLSTS.bit.DIVSEL = 3;
            EDIS;
            break;
        default :
            break;
    }

    return;
}

void Init_PeripheralClocks(void)
{
	EALLOW;

	// High Speed Clock
	SysCtrlRegs.HISPCP.all = 0x001F;			// 4.6875[MHz](SYSCLKOUT/64)
												// 4-0	: HSPCLK	; High Speed Clock Pre-scale
												//					; 00000(x0), 00001(/4), 00010(/6), 00011(/8), ..., 11111(/64)

	// Low Speed Clock
	SysCtrlRegs.LOSPCP.all = 0x0002;			// 75[MHz](SYSCLKOUT/4)
												// 2-0	: LSPCLK	; Low Speed Clock Pre-scale
												//					; 000(/1), 001(/2), 010(/4), 011(/6), ..., 111(/14)

	// Peripheral Clocks Enable					// 0(Disable), 1(Enable)
	// CAN
	SysCtrlRegs.PCLKCR0.bit.ECANAENCLK = 1;		// For CAN Communication				; 0(Disable)
	SysCtrlRegs.PCLKCR0.bit.ECANBENCLK = 0;

	// I2C
	SysCtrlRegs.PCLKCR0.bit.I2CAENCLK = 1;

	// MCBSP
	SysCtrlRegs.PCLKCR0.bit.MCBSPAENCLK = 0;
	SysCtrlRegs.PCLKCR0.bit.MCBSPBENCLK = 1;	// For Resolver							; 0(Disable)

	// SCI
	SysCtrlRegs.PCLKCR0.bit.SCIAENCLK = 1;		// For RS-232 Communication				; 1(Enable)
	SysCtrlRegs.PCLKCR0.bit.SCIBENCLK = 0;
	SysCtrlRegs.PCLKCR0.bit.SCICENCLK = 0;

	// SPI
	SysCtrlRegs.PCLKCR0.bit.SPIAENCLK = 1;		// For communicating with Flash-ROM.	; 1(Enable)
	SysCtrlRegs.PCLKCR0.bit.SPIDENCLK = 1;		// For communicating with EXT-DAC.		; 1(Enable)

	// PWM
	SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;		// Disable TBCLK for PWM Synchronization; 0(Disable)
	SysCtrlRegs.PCLKCR1.bit.EPWM1ENCLK = 1;		// A phase PWM for first 3-phase		; 1(Enable)
	SysCtrlRegs.PCLKCR1.bit.EPWM2ENCLK = 1;		// B phase PWM for first 3-phase		; 1(Enable)
	SysCtrlRegs.PCLKCR1.bit.EPWM3ENCLK = 1;		// C phase PWM for first 3-phase		; 1(Enable)
	SysCtrlRegs.PCLKCR1.bit.EPWM4ENCLK = 1;		// A phase PWM for Second 3-phase		; 1(Enable)
	SysCtrlRegs.PCLKCR1.bit.EPWM5ENCLK = 1;		// B phase PWM for Second 3-phase		; 1(Enable)
	SysCtrlRegs.PCLKCR1.bit.EPWM6ENCLK = 1;		// C phase PWM for Second 3-phase		; 1(Enable)
	SysCtrlRegs.PCLKCR1.bit.EPWM7ENCLK = 0;
	SysCtrlRegs.PCLKCR1.bit.EPWM8ENCLK = 1;
	SysCtrlRegs.PCLKCR2.bit.EPWM9ENCLK = 1;

	// CAP
	SysCtrlRegs.PCLKCR1.bit.ECAP1ENCLK = 0;
	SysCtrlRegs.PCLKCR1.bit.ECAP2ENCLK = 0;		// For Hall-Sensor(When GPIO is set CAP); 0(Disable)
	SysCtrlRegs.PCLKCR1.bit.ECAP3ENCLK = 0;		// For Hall-Sensor(When GPIO is set CAP); 0(Disable)
	SysCtrlRegs.PCLKCR1.bit.ECAP4ENCLK = 0;		// For Hall-Sensor(When GPIO is set CAP); 0(Disable)
	SysCtrlRegs.PCLKCR1.bit.ECAP5ENCLK = 0;
	SysCtrlRegs.PCLKCR1.bit.ECAP6ENCLK = 0;

	// QEP
	SysCtrlRegs.PCLKCR1.bit.EQEP1ENCLK = 0;		// For Resolver							; 0(Disable)
	SysCtrlRegs.PCLKCR1.bit.EQEP2ENCLK = 0;		// For Hall-Sensor(When GPIO is set QEP); 0(Disable)
	SysCtrlRegs.PCLKCR2.bit.EQEP3ENCLK = 1;		// For Encoder							; 1(Enable)

	// CPU Timer
	SysCtrlRegs.PCLKCR3.bit.CPUTIMER0ENCLK = 1;	// Main Controller.						; 1(Enable)
	SysCtrlRegs.PCLKCR3.bit.CPUTIMER1ENCLK = 0;
	SysCtrlRegs.PCLKCR3.bit.CPUTIMER2ENCLK = 0;

	// DMA
	SysCtrlRegs.PCLKCR3.bit.DMAENCLK = 0;

	// GPIO Input
	SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK = 0;	// For GPIO Input						; 0(Disable)

	// XINF
	SysCtrlRegs.PCLKCR3.bit.XINTFENCLK = 1;		// For ADC Parallel Communication		; 1(Enable)

	EDIS;

	return;
}

void Init_PieCtrl(void)
{
	// CPU Master Interrupt Disable.
	DINT;

	// Peripheral Mater Interrupt Disable.
	PieCtrlRegs.PIECTRL.bit.ENPIE = 0;

	// Clear all PIEIER register.
	PieCtrlRegs.PIEIER1.all = 0x0000;
	PieCtrlRegs.PIEIER2.all = 0x0000;
	PieCtrlRegs.PIEIER3.all = 0x0000;
	PieCtrlRegs.PIEIER4.all = 0x0000;
	PieCtrlRegs.PIEIER5.all = 0x0000;
	PieCtrlRegs.PIEIER6.all = 0x0000;
	PieCtrlRegs.PIEIER7.all = 0x0000;
	PieCtrlRegs.PIEIER8.all = 0x0000;
	PieCtrlRegs.PIEIER9.all = 0x0000;
	PieCtrlRegs.PIEIER10.all = 0x0000;
	PieCtrlRegs.PIEIER11.all = 0x0000;
	PieCtrlRegs.PIEIER12.all = 0x0000;

	// Clear all PIEIFR Register.
	PieCtrlRegs.PIEIFR1.all = 0x0000;
	PieCtrlRegs.PIEIFR2.all = 0x0000;
	PieCtrlRegs.PIEIFR3.all = 0x0000;
	PieCtrlRegs.PIEIFR4.all = 0x0000;
	PieCtrlRegs.PIEIFR5.all = 0x0000;
	PieCtrlRegs.PIEIFR6.all = 0x0000;
	PieCtrlRegs.PIEIFR7.all = 0x0000;
	PieCtrlRegs.PIEIFR8.all = 0x0000;
	PieCtrlRegs.PIEIFR9.all = 0x0000;
	PieCtrlRegs.PIEIFR10.all = 0x0000;
	PieCtrlRegs.PIEIFR11.all = 0x0000;
	PieCtrlRegs.PIEIFR12.all = 0x0000;

	// Clear all IER Register.
	IER = 0x0000;

	// Clear all IFR Register.
	IFR = 0x0000;

	return;
}

void Init_PieVectTable(void)
{
	EALLOW;

	// Reserved Space
	PieVectTable.PIE1_RESERVED = &ISR_Default;
	PieVectTable.PIE2_RESERVED = &ISR_Default;
	PieVectTable.PIE3_RESERVED = &ISR_Default;
	PieVectTable.PIE4_RESERVED = &ISR_Default;
	PieVectTable.PIE5_RESERVED = &ISR_Default;
	PieVectTable.PIE6_RESERVED = &ISR_Default;
	PieVectTable.PIE7_RESERVED = &ISR_Default;
	PieVectTable.PIE8_RESERVED = &ISR_Default;
	PieVectTable.PIE9_RESERVED = &ISR_Default;
	PieVectTable.PIE10_RESERVED = &ISR_Default;
	PieVectTable.PIE11_RESERVED = &ISR_Default;
	PieVectTable.PIE12_RESERVED = &ISR_Default;
	PieVectTable.PIE13_RESERVED = &ISR_Default;

	// Not-Peripheral Interrupt
	PieVectTable.XINT13 = &ISR_Default;			// XINT13 or CPU Timer1 Interrupt
	PieVectTable.TINT2 = &ISR_Default;			// CPU Timer2 Interrupt
	PieVectTable.DATALOG = &ISR_Default;		// Data-logging Interrupt
	PieVectTable.RTOSINT = &ISR_Default;		// RTOS Interrupt
	PieVectTable.EMUINT = &ISR_Default;			// Emulation Interrupt
	PieVectTable.XNMI = &ISR_Default;			// Non-Maskable Interrupt
	PieVectTable.ILLEGAL = &ISR_Default;		// Illegal Interrupt
	PieVectTable.USER1 = &ISR_Default;			// User Defined Trap 1
	PieVectTable.USER2 = &ISR_Default;			// User Defined Trap 2
	PieVectTable.USER3 = &ISR_Default;			// User Defined Trap 3
	PieVectTable.USER4 = &ISR_Default;			// User Defined Trap 4
	PieVectTable.USER5 = &ISR_Default;			// User Defined Trap 5
	PieVectTable.USER6 = &ISR_Default;			// User Defined Trap 6
	PieVectTable.USER7 = &ISR_Default;			// User Defined Trap 7
	PieVectTable.USER8 = &ISR_Default;			// User Defined Trap 8
	PieVectTable.USER9 = &ISR_Default;			// User Defined Trap 9
	PieVectTable.USER10 = &ISR_Default;			// User Defined Trap 10
	PieVectTable.USER11 = &ISR_Default;			// User Defined Trap 11
	PieVectTable.USER12 = &ISR_Default;			// User Defined Trap 12

	// Group 1 PIE Peripheral
	PieVectTable.rsvd1_1 = &ISR_Default;
	PieVectTable.rsvd1_2 = &ISR_Default;
	PieVectTable.rsvd1_3 = &ISR_Default;
	PieVectTable.XINT1 = &ISR_Default;
	PieVectTable.XINT2 = &ISR_Default;
	PieVectTable.rsvd1_6 = &ISR_Default;
	PieVectTable.TINT0 = &ISR_CAN_TX;			// CPU Timer 0 Interrupt
	PieVectTable.WAKEINT = &ISR_Default;		// LPM/WD Interrupt					; WatchDog

	// Group 2 PIE Peripheral
	PieVectTable.EPWM1_TZINT = &ISR_Default;	// PWM1 Trip Zone Interrupt
	PieVectTable.EPWM2_TZINT = &ISR_Default;	// PWM2 Trip Zone Interrupt
	PieVectTable.EPWM3_TZINT = &ISR_Default;	// PWM3 Trip Zone Interrupt
	PieVectTable.EPWM4_TZINT = &ISR_Default;	// PWM4 Trip Zone Interrupt
	PieVectTable.EPWM5_TZINT = &ISR_Default;	// PWM5 Trip Zone Interrupt
	PieVectTable.EPWM6_TZINT = &ISR_Default;	// PWM6 Trip Zone Interrupt
	PieVectTable.EPWM7_TZINT = &ISR_Default;	// PWM7 Trip Zone Interrupt
	PieVectTable.EPWM8_TZINT = &ISR_Default;	// PWM8 Trip Zone Interrupt

	// Group 3 PIE Peripheral
	PieVectTable.EPWM1_INT = &M1_Offset;		// PWM1 Interrupt					; Main Controller
	PieVectTable.EPWM2_INT = &M2_Offset;		// PWM2 Interrupt
	PieVectTable.EPWM3_INT = &ISR_Default;		// PWM3 Interrupt
	PieVectTable.EPWM4_INT = &ISR_Default;		// PWM4 Interrupt
	PieVectTable.EPWM5_INT = &ISR_Default;		// PWM5 Interrupt
	PieVectTable.EPWM6_INT = &ISR_Default;		// PWM6 Interrupt
	PieVectTable.EPWM7_INT = &ISR_Default;		// PWM7 Interrupt
	PieVectTable.EPWM8_INT = &ISR_Default;		// PWM8 Interrupt

	// Group 4 PIE Peripheral
	PieVectTable.ECAP1_INT = &ISR_Default;		// CAP1 Interrupt
	PieVectTable.ECAP2_INT = &ISR_Default;		// CAP2 Interrupt
	PieVectTable.ECAP3_INT = &ISR_Default;		// CAP3 Interrupt
	PieVectTable.ECAP4_INT = &ISR_Default;		// CAP4 Interrupt
	PieVectTable.ECAP5_INT = &ISR_Default;		// CAP5 Interrupt
	PieVectTable.ECAP6_INT = &ISR_Default;		// CAP6 Interrupt
	PieVectTable.rsvd4_7 = &ISR_Default;
	PieVectTable.rsvd4_8 = &ISR_Default;

	// Group 5 PIE Peripheral
	PieVectTable.EQEP1_INT = &ISR_Default;		// QEP1 Interrupt
	PieVectTable.EQEP2_INT = &ISR_Default;		// QEP2 Interrupt
	PieVectTable.EQEP3_INT = &ISR_Default;		// QEP3 Interrupt
	PieVectTable.rsvd5_4 = &ISR_Default;
	PieVectTable.rsvd5_5 = &ISR_Default;
	PieVectTable.rsvd5_6 = &ISR_Default;
	PieVectTable.rsvd5_7 = &ISR_Default;
	PieVectTable.rsvd5_8 = &ISR_Default;

	// Group 6 PIE Peripheral
	PieVectTable.SPIRXINTA = &ISR_Default;		// SPI-A Receive Interrupt
	PieVectTable.SPITXINTA = &ISR_Default;		// SPI-A Transmit Interrupt
	PieVectTable.MRINTB = &ISR_Default;			// McBSP-B
	PieVectTable.MXINTB = &ISR_Default;			// McBSP-B or SPI-B
	PieVectTable.MRINTA = &ISR_Default;			// McBSP-A
	PieVectTable.MXINTA = &ISR_Default;			// McBSP-A
	PieVectTable.SPIRXINTD = &ISR_Default;		// SPI-D Receive Interrupt
	PieVectTable.SPITXINTD = &ISR_Default;		// SPI-D Transmit Interrupt

	// Group 7 PIE Peripheral
	PieVectTable.DINTCH1 = &ISR_Default;		// DMA Channel 1
	PieVectTable.DINTCH2 = &ISR_Default;		// DMA Channel 2
	PieVectTable.DINTCH3 = &ISR_Default;		// DMA Channel 3
	PieVectTable.DINTCH4 = &ISR_Default;		// DMA Channel 4
	PieVectTable.DINTCH5 = &ISR_Default;		// DMA Channel 5
	PieVectTable.DINTCH6 = &ISR_Default;		// DMA Channel 6
	PieVectTable.rsvd7_7 = &ISR_Default;
	PieVectTable.rsvd7_8 = &ISR_Default;

	// Group 8 PIE Peripheral
	PieVectTable.I2CINT1A = &ISR_Default;		// I2C-A
	PieVectTable.I2CINT2A = &ISR_Default;		// I2C-A
	PieVectTable.rsvd8_3 = &ISR_Default;
	PieVectTable.rsvd8_4 = &ISR_Default;
	PieVectTable.SCIRXINTC = &ISR_Default;		// SCI-C
	PieVectTable.SCITXINTC = &ISR_Default;		// SCI-C
	PieVectTable.rsvd8_7 = &ISR_Default;
	PieVectTable.rsvd8_8 = &ISR_Default;

	// Group 9 PIE Peripheral
	PieVectTable.SCIRXINTA = &ISR_Default;		// SCI-A Receive Interrupt
	PieVectTable.SCITXINTA = &ISR_Default;		// SCI-A Transmit Interrupt
	PieVectTable.SCIRXINTB = &ISR_Default;		// SCI-B Receive Interrupt
	PieVectTable.SCITXINTB = &ISR_Default;		// SCI-B Transmit Interrupt
	PieVectTable.ECAN0INTA = &ISR_CAN_HostRx;           // CAN-A Interrupt 0                ; Host Receive
	PieVectTable.ECAN1INTA = &ISR_CAN_HostRx_Monitor;   // CAN-A Interrupt 1                ; Monitoring Receive
	PieVectTable.ECAN0INTB = &ISR_Default;		// CAN-B
	PieVectTable.ECAN1INTB = &ISR_Default;		// CAN-B

	// Group 10 PIE Peripheral
	PieVectTable.EPWM9_TZINT = &ISR_Default;	// PWM9 Trip Zone Interrupt
	PieVectTable.rsvd10_2 = &ISR_Default;
	PieVectTable.rsvd10_3 = &ISR_Default;
	PieVectTable.rsvd10_4 = &ISR_Default;
	PieVectTable.rsvd10_5 = &ISR_Default;
	PieVectTable.rsvd10_6 = &ISR_Default;
	PieVectTable.rsvd10_7 = &ISR_Default;
	PieVectTable.rsvd10_8 = &ISR_Default;

	// Group 11 PIE Peripheral
	PieVectTable.EPWM9_INT = &ISR_Default;		// PWM9 Interrupt
	PieVectTable.rsvd11_2 = &ISR_Default;
	PieVectTable.rsvd11_3 = &ISR_Default;
	PieVectTable.rsvd11_4 = &ISR_Default;
	PieVectTable.rsvd11_5 = &ISR_Default;
	PieVectTable.rsvd11_6 = &ISR_Default;
	PieVectTable.rsvd11_7 = &ISR_Default;
	PieVectTable.rsvd11_8 = &ISR_Default;

	// Group 12 PIE Peripheral
	PieVectTable.XINT3 = &ISR_Default;
	PieVectTable.XINT4 = &ISR_Default;
	PieVectTable.XINT5 = &ISR_Default;
	PieVectTable.XINT6 = &ISR_Default;
	PieVectTable.XINT7 = &ISR_Default;
	PieVectTable.rsvd12_6 = &ISR_Default;
	PieVectTable.LVF = &ISR_Default;			// Floating Point Unit Overflow
	PieVectTable.LUF = &ISR_Default;			// Floating Point Unit Underflow

	EDIS;

	// Enable the PIE Vector Table
	PieCtrlRegs.PIECTRL.bit.ENPIE = 1;			// 0(Disable), 1(Enable)

	return;
}

void Start_PieCtrl(void)
{
	PieCtrlRegs.PIEIER1.bit.INTx7 = 1;			// Timer Interrupt
	IER |=M_INT1;

	PieCtrlRegs.PIEIER3.bit.INTx1 = 1;			// ePWM1 Interrupt
	PieCtrlRegs.PIEIER3.bit.INTx2 = 1;			// ePWM1 Interrupt
	IER |= M_INT3;

	PieCtrlRegs.PIEIER9.bit.INTx1 = 1;			// SCI-A Rx Interrupt
    PieCtrlRegs.PIEIER9.bit.INTx5 = 1;          // CANA Interrupt RX    ; CAN RX for Host Controller.
    PieCtrlRegs.PIEIER9.bit.INTx6 = 1;          // CANA Interrupt RX    ; CAN RX for Host Controller.
	IER |= M_INT9;

	EINT;
	ERTM;

	return;
}

interrupt void ISR_Default(void)
{
	ESTOP0;										// Stop Emulation
	for(;;);
}
