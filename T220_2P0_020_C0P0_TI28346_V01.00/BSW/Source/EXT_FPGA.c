/*
 *	EXT_FPGA.c
 *
 * C/C++ source code generated on : Thu Jan 11 10:09:04 2024
 * Created by: System Research Team
 * Code generated on : Sat Mar 15 00:16:24 2025
 *
 */

#include "Define_Header.h"
#include "Define_Pin.h"

/*********************************************************** 		Codes			***********************************************************/
void Init_FPGA(void)
{
	FPGA_RESET_ON;

	DELAY_US(2.75);

	FPGA_RESET_OFF;

	DELAY_US(2.75);

	return;
}
/**********************************************************************************************************************************************/
