/*
 * Define_Prototypes.h
 *
 * C/C++ source code generated on : Thu Jan 11 10:09:04 2024
 * Created by: System Research Team
 * Code generated on : Sat Mar 15 00:16:24 2025
 *
 */

#ifndef DEFINE_PROTOTYPES_H_
#define DEFINE_PROTOTYPES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "rtwtypes.h"

/*********************************************************** Define ***********************************************************/
interrupt void ISR_Default(void);
interrupt void ISR_CAN_TX(void);
interrupt void M1_Interrupt(void);
interrupt void M1_Offset(void);
interrupt void M2_Interrupt(void);
interrupt void M2_Offset(void);

extern void DisableDog(void);
extern void DSP28x_usDelay(Uint32 Count);
extern void Eep_Init(void);
extern void Init_CPUTimers(void);
extern void Init_FPGA(void);
extern void Init_GPIO(void);
extern void Init_I2C(void);
extern void PD_Save(void);
extern void PC_Save(void);
extern void P1_Save(void);
extern void P2_Save(void);
extern void Init_PeripheralClocks(void);
extern void Init_PieCtrl(void);
extern void Init_PieVectTable(void);
extern void Init_PLL(void);
extern void Init_PWM(void);
extern void Init_Xintf(void);
extern void ResetDog(void);
extern void Start_PieCtrl(void);
extern void Start_PWM(void);
extern void Start_Timer(void);
extern void ADC_CONVST(void);
extern void PWM_SetDuty(real32_T _aref, real32_T _bref, real32_T _cref, real32_T _invdc);

extern void Current_Sensor(void);

/********************************************************************************************************************************/

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* DEFINE_PROTOTYPES_H_ */
