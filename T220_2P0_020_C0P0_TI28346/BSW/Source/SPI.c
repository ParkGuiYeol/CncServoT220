/*
 *	SPI.c
 *
 * C/C++ source code generated on : Thu Jan 11 10:09:04 2024
 * Created by: System Research Team
 * Code generated on : Sat Mar 15 00:16:24 2025
 *
 */

#include "Define_Header.h"

void Init_SPI(void)
{
	SpidRegs.SPICCR.bit.SPISWRESET = 0;			// Reset SPI.

	SpidRegs.SPIPRI.bit.FREE = 1;				// Free Emulation Mode.

	SpidRegs.SPICCR.bit.SPICHAR = 15;			// 16bit.
	SpidRegs.SPICCR.bit.CLKPOLARITY = 1;		// Falling Edge.

	SpidRegs.SPICTL.bit.CLK_PHASE = 0;			// without Delay.
	SpidRegs.SPICTL.bit.MASTER_SLAVE = 1;		// Master Operation.
	SpidRegs.SPICTL.bit.TALK = 1;				// /SPISTE Activation.

	SpidRegs.SPIBRR = 7;						// Baud Rate = LSPCLK/(SPIBRR+1)	; 9.375[Mbps]

	SpidRegs.SPICCR.bit.SPISWRESET = 1;			// Ready for Communication.

	return;
}
