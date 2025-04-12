/*
 *	Sensor.c
 *
 * C/C++ source code generated on : Thu Jan 11 10:09:04 2024
 * Created by: System Research Team
 * Code generated on : Sat Mar 15 00:16:24 2025
 *
 */

#include "Define_Header.h"
#include "L02_ADC_READ.h"
#include "rtwtypes.h"

/************************************ ADS7865IPBS ****************************************/
// Sequencer Register Map
//  11  10  9   8   7   6   5   4   3   2   1   0
//  S1  S0  SL1 Sl0 CH1 CM1 CH2 CM2 CH3 CM3 SP1 SP0
//  1   1   1   1   1   0   0   1   0   0   0   0   = 0xF90
//  1   1   1   1   0   0   0   1   1   0   0   0   = 0xF18 (Entire sequence Mode: last in, first out, CHA1+, CHB1+, CHA1-, CHB1-, CHA0+, CHB0+)

int ADR_i32IaSens       = 0;
int ADR_i32IbSens       = 0;
int ADR_i32IcSens       = 0;
int ADR_i32HVdcSens     = 0;
int ADR_i32IvtTempSens  = 0;
int ADR_i32MtrTempSens  = 0;

/*************************************************************      Code        ************************************************************/
void L02_ADC_READ(void)
{
    ADR_i32IaSens       = ((int)*ADC_ADDR) << ADC_SHIFT >> ADC_SHIFT;
    ADR_i32IbSens       = ((int)*ADC_ADDR) << ADC_SHIFT >> ADC_SHIFT;
    ADR_i32HVdcSens     = ((int)*ADC_ADDR) << ADC_SHIFT >> ADC_SHIFT;
    ADR_i32IvtTempSens  = ((int)*ADC_ADDR) << ADC_SHIFT >> ADC_SHIFT;
    ADR_i32MtrTempSens  = ((int)*ADC_ADDR) << ADC_SHIFT >> ADC_SHIFT;

    return;
}
