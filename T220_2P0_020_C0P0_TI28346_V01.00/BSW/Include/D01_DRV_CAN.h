/*
 * D01_DRV_CAN.h
 *
 * C/C++ source code generated on : Thu Jan 11 10:09:04 2024
 * Created by: System Research Team
 * Code generated on : Sat Mar 15 00:16:24 2025
 *
 */

#ifndef INCLUDE_DEFINE_CAN_H_
#define INCLUDE_DEFINE_CAN_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "rtwtypes.h"

// Prototype define
extern void Init_eCAN(void);
extern interrupt void ISR_CAN_HostRx(void);
extern interrupt void ISR_CAN_HostRx_Monitor(void);
extern void CAN_HostTx(uint32_T);
//extern void CAN_Communicaiton(void);

//// CAN TX Step
#define CAN_TX_STEP_0                       2
#define CAN_TX_STEP_1                       4
#define CAN_TX_STEP_2                       5
#define CAN_TX_STEP_3                       6
#define CAN_TX_STEP_4                       7
#define CAN_TX_STEP_5                       8
#define CAN_TX_STEP_6                       10

// Predefine
//// Predefine : In-line Function
#define CANRegsWrite(regs, reg, val)			eCAN_Shadow.CAN##reg.all = regs.CAN##reg.all; 	\
												eCAN_Shadow.CAN##reg.all = val;					\
												regs.CAN##reg.all = eCAN_Shadow.CAN##reg.all
#define CANPRegsWrite(regs, reg, val)			eCAN_Shadow.CAN##reg.all = regs->CAN##reg.all; 	\
												eCAN_Shadow.CAN##reg.all = val;					\
												regs->CAN##reg.all = eCAN_Shadow.CAN##reg.all
#define CANPRegsOR(regs, reg, val)				eCAN_Shadow.CAN##reg.all = regs->CAN##reg.all; 	\
												eCAN_Shadow.CAN##reg.all |= val;				\
												regs->CAN##reg.all = eCAN_Shadow.CAN##reg.all

#define CAN_ROUND								0.5F

extern uint16_T mCRX1_uRxChSel;
extern uint32_T mCRX1_u32CrrDataLow;
extern uint32_T mCRX1_u32CrrDataHigh;

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_DEFINE_CAN_H_ */
