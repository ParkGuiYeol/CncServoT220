/*
 * Define_CPUTimers.h
 *
 * C/C++ source code generated on : Thu Jan 11 10:09:04 2024
 * Created by: System Research Team
 * Code generated on : Sat Mar 15 00:16:24 2025
 *
 */

#ifndef DEFINE_CPUTIMERS_H_
#define DEFINE_CPUTIMERS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "rtwtypes.h"

//// Predefine : TIMERxTCR Register
////// Predefine : TIMERxTCR Register - Byte Value
#define TCR_TIF_InterruptClear              0x8000

#define TCR_TSS_CountStop                   0x0010

#define TCR_TIE_InterruptEnable             0x4000
#define TCR_TIE_InterruptDisable            0x0000

#define TCR_FREESOFT_FreeRun                0x0800
#define TCR_FREESOFT_SoftStop               0x0400
#define TCR_FREESOFT_Immediately            0x0000

#define TCR_TRB_CountReload                 0x0020

#define TSS_CountStop                       0x1
#define TSS_CountRun                        0x0

extern uint16_T mBSW_u1msFlag;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* DEFINE_CPUTIMERS_H_ */
