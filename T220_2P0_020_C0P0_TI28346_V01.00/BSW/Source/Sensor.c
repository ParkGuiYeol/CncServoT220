/*
 *	Sensor.c
 *
 * C/C++ source code generated on : Thu Jan 11 10:09:04 2024
 * Created by: System Research Team
 * Code generated on : Sat Mar 15 00:16:24 2025
 *
 */

#include "Define_Header.h"

/***********************************************************      Variables     ************************************************************/

/*************************************************************      Code        ************************************************************/
void ADC_CONVST(void)
{
	// If the output data are read after the entire sequence has been converted, the output data are presented in LIFO manner (last in, first out).
	// Sequencer Register Map
	//	11	10	9	8	7	6	5	4	3	2	1	0
	//	S1	S0	SL1	Sl0	CH1	CM1	CH2	CM2	CH3	CM3	SP1	SP0
	//	1	1	1	1	1	0	0	1	0	0	0	0	= 0xF90
	//	1	1	1	1	0	0	0	1	1	0	0	0	= 0xF18 (Entire sequence Mode: last in, first out, CHA1+, CHB1+, CHA1-, CHB1-, CHA0+, CHB0+)

	ADC_Send(0x104);								// Configuration Register Send
	asm (" RPT #50 || NOP"); 						// 70nsec
	ADC_Send(0xF18);								// Sequencer Register Send
	asm (" RPT #50 || NOP"); 						// 70nsec

	ADC_CONVT_START_OFF;
	asm (" RPT #50 || NOP"); 						// 70nsec
	ADC_CONVT_START_ON;
	asm (" RPT #50 || NOP"); 						// 70nsec
	ADC_CONVT_START_OFF;

	return;
}
