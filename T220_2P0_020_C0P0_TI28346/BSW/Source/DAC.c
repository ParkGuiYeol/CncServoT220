/*
 *	DAC.c
 *
 * C/C++ source code generated on : Thu Jan 11 10:09:04 2024
 * Created by: System Research Team
 * Code generated on : Sat Mar 15 00:16:24 2025
 *
 */

#include "Define_Header.h"
#include "Define_DAC.h"
#include "f01_CommRx1.h"
#include "e03_MtrCtrl_MtrCtrl.h"
#include "e04_MtrCtrl_PwmSet.h"

/*****************************************************************     Variables     ******************************************************************/
S_DACS DACS =
{
    .Sel = 4U
};

/************************************************************** 		Code		***********************************************************/
void DAC_Out(void)
{
    switch (DACS.Sel)
    {
        case 1:
            DACS.CH1.Out = &mGPwm_sVanRef;
            DACS.CH2.Out = &mGPwm_sVbnRef;
            DACS.CH3.Out = &mGPwm_sVcnRef;
            DACS.CH4.Out = &mCTRL_sThetaCtrl;
            DACS.CH1.Rng = 100.0F;
            DACS.CH2.Rng = 100.0F;
            DACS.CH3.Rng = 100.0F;
            DACS.CH4.Rng = 7.0F;
            DACS.CH1.Mid = 0.0F;
            DACS.CH2.Mid = 0.0F;
            DACS.CH3.Mid = 0.0F;
            DACS.CH4.Mid = 0.0F;
            DACS.CH1.Type = 0U;
            DACS.CH2.Type = 0U;
            DACS.CH3.Type = 0U;
            DACS.CH4.Type = 0U;
            DACS.Sel = 0U;
            break;

        default:
			break;
	}

    DACS.Sel = mCRX_uDaCase;

	FPGA_Send(ADDF_DA_CH1, ((uint16_T)((((DAC_Val(1) - DACS.CH1.Mid) * DACS.CH1.INVRng) * DAC_RNG) + DAC_MID) & DAC_EFF));
	FPGA_Send(ADDF_DA_CH2, ((uint16_T)((((DAC_Val(2) - DACS.CH1.Mid) * DACS.CH1.INVRng) * DAC_RNG) + DAC_MID) & DAC_EFF));
	FPGA_Send(ADDF_DA_CH3, ((uint16_T)((((DAC_Val(3) - DACS.CH1.Mid) * DACS.CH1.INVRng) * DAC_RNG) + DAC_MID) & DAC_EFF));
	FPGA_Send(ADDF_DA_CH4, ((uint16_T)((((DAC_Val(4) - DACS.CH1.Mid) * DACS.CH1.INVRng) * DAC_RNG) + DAC_MID) & DAC_EFF));

	//	DEC		HEX		Vout
	//	16384	4000	 10 V
	//	8192	2000	  0 V
	//	0		0		-10 V

	// ex: ((DA(1) - da1.mid) * DAC_RNG * da1_rng_inv) + DAC_MID) = ((10A Output - 0) * 8192 * 1/10) + 8192 = 16384
	// ex: ((DA(1) - da1.mid) * DAC_RNG * da1_rng_inv) + DAC_MID) = ((-10A Output - 0) * 8192 * 1/10) + 8192 = 0

	return;
}
