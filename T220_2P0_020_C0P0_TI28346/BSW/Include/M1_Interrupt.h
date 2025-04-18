/*
 * File: M1_Interrupt.h
 *
 * C/C++ source code generated on : Sun Mar 16 11:41:14 2025
 * Created by: System Research Team
 *
 */

#ifndef BSW_INCLUDE_M1_INTERRUPT_H_
#define BSW_INCLUDE_M1_INTERRUPT_H_

/* user code (top of header file) */
#include "Define_Pin.h"
#include "L02_ADC_READ.h"
#include "b01_OSnScheduler.h"
#include "c01_MainAdc.h"
#include "c02_SubAdc.h"
#include "d01_Diaglnteg.h"
#include "e01_MtrCtrl_VarGain.h"
#include "e02_MtrCtrl_Pst.h"
#include "e03_MtrCtrl_MtrCtrl.h"
#include "e04_MtrCtrl_PwmSet.h"
#include "j01_McuInit.h"

/* user code (bottom of header file) */
extern uint16_T mBSW_uInitNvRam;
extern uint16_T mEnc_uCF;
extern uint16_T mEnc_uSF;
extern uint16_T mEnc_uEND;
extern uint16_T mEnc_uALMC;
extern uint16_T mEnc_uCRC;
extern uint16_T mEnc_uABS0;
extern uint16_T mEnc_uABS1;
extern uint16_T mEnc_uABS2;
extern uint16_T mEnc_uABM0;
extern uint16_T mEnc_uABM1;
extern uint16_T mEnc_uABM2;

#endif /* BSW_INCLUDE_M1_INTERRUPT_H_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
