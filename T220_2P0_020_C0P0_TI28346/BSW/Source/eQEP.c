/*
 *	eQEP.c
 *
 * C/C++ source code generated on : Thu Jan 11 10:09:04 2024
 * Created by: System Research Team
 * Code generated on : Sat Mar 15 00:16:24 2025
 *
 */

#include "Define_Header.h"
#include "Define_eQEP.h"

//#define ENC_PPR						14400
//#define INV_ENC_PPR					6.9444444444e-5L
//
//
//float Pole_Pairs = 3;
//
//float pst_data = 0;
//float theta_m = 0, theta_e = 0, Init_theta_e = 0;
//
//Uint16 dir_data = 0;
//float m_data = 0, m_data_old = -10;
//float rpm_m = 0, rpm_m_old = 0, rpm_m_low = 0;
//float Wm = 0, We = 0;
//
//float TWc_rpm = 10000;

void Init_QEP(void)
{
	/*

	//-------------------------------------------------------------------------------------------------//
	//-----------------------------------------eQEP3 [Encoder]-----------------------------------------//
	//-------------------------------------------------------------------------------------------------//
	// Emulation Mode
	EQep3Regs.QEPCTL.bit.FREE_SOFT = EMUMODE_FREE;

	// Signal Modify
	EQep3Regs.QDECCTL.bit.QAP = EQEPNX_NORMAL;
	EQep3Regs.QDECCTL.bit.QBP = EQEPNX_NORMAL;
	EQep3Regs.QDECCTL.bit.QIP = EQEPNX_NORMAL;
	EQep3Regs.QDECCTL.bit.SWAP = EQEPAB_NORMAL;

	// Position Counter
	EQep3Regs.QDECCTL.bit.QSRC = PST_QUAD;				// Quadrature Mode
	EQep3Regs.QEPCTL.bit.PCRM = PST_RESET_INDEX;		// Cleared by Index Event
	EQep3Regs.QPOSMAX = (ENC_PPR-1);					// PPR : 14400
	EQep3Regs.QEPCTL.bit.QPEN = PST_ENABLE;				// Position Counter Enable

	// Unit Timer
	EQep3Regs.QEPCTL.bit.UTE = UNIT_DISABLE;			// Unit Timer Enable.

	// Capture Unit
	EQep3Regs.QCAPCTL.bit.CEN = CAPT_DISABLE;			// Capture Unit Disable.

	// QEPn Position Compare
	EQep3Regs.QPOSCTL.bit.PCE = COMP_DISABLE;			// Compare Unit Disable.

	// QEPn Watch dog
	EQep3Regs.QEPCTL.bit.WDE = WATCH_DISABLE;			// QEP3 Watch Dog Disable.

	// Synchronization
	EQep3Regs.QDECCTL.bit.SOEN = SYNCH_DISABLE;			// Synch Out Disable.

	 */
	return;
}

