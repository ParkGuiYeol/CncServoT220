/*
 *	WatchDog.c
 *
 * C/C++ source code generated on : Thu Jan 11 10:09:04 2024
 * Created by: System Research Team
 * Code generated on : Sat Mar 15 00:16:24 2025
 *
 */

#include "Define_Header.h"

void ResetDog(void)
{
	EALLOW;

	// Reset WatchDoeg
	SysCtrlRegs.WDKEY = 0x0055;
	SysCtrlRegs.WDKEY = 0x00AA;

	// WatchDog Configuration
	SysCtrlRegs.SCSR = 0x0000;
									// 2	: WDINTS	; WatchDog Interrupt Status bit.
									//					; 0(/WDINT Activate), 1(/WDINT Not Activate)
									// 1	: WDENINT	; WatchDog Interrupt Enable
									//					; 0(Reset Mode), 1(Interrupt Mode)
									// 0	: WDOVERRIDE; WatchDog Override
									//					; 0(Can modify WDDIS), 1(Can't modify WDDIS)
	SysCtrlRegs.WDCR = 0x0028;
									// 7	: WDFLAG	; WatchDog Reset Status Bit.
									//					; 0(Reset is caused).
									// 6	: WDDIS		; WatchDog Disable.
									//					; 0(Enable), 1(Disable).
									// 5-3	: WDCHK		; WatchDog Check.
									//					; 101 must be written to change WDCR Register.
									// 2-0	: WDPS		; WatchDog Pre-scale.
									//					; 000(OSCCLK/1), 001(OSCCLK/1), 010(OSCCLK/2), 011(OSCCLK/4), ..., 111(OSCCLK/64)	; OSCCLK = 20[MHz]
	EDIS;

	return;
}

void DisableDog(void)
{
    EALLOW;
    SysCtrlRegs.WDCR = 0x0068;
                                    // 7    : WDFLAG    ; WatchDog Reset Status Bit.
                                    //                  ; 0(Reset is caused).
                                    // 6    : WDDIS     ; WatchDog Disable.
                                    //                  ; 0(Enable), 1(Disable).
                                    // 5-3  : WDCHK     ; WatchDog Check.
                                    //                  ; 101 must be written to change WDCR Register.
                                    // 2-0  : WDPS      ; WatchDog Pre-scale.
                                    //                  ; 000(/1), 001(/1), 010(/2), 011(/4), ..., 111(/64)
    EDIS;

    return;
}
