/*
 * D10_Fnd_key.h
 *
 *  Created on: 2025. 4. 27.
 *      Author: admin
 */

#ifndef BSW_INCLUDE_D10_FND_KEY_H_
#define BSW_INCLUDE_D10_FND_KEY_H_

extern uint16_T FndGpioSet[5];
extern uint16_T uFinishInitDisp;
extern int16_T mBSW_iCntFndFlicker;

extern void Main_Display(Uint16 display_no);
extern void Init_Display(void);
extern void Key_Read(void);
extern void Btn_Operation(void);

#endif /* BSW_INCLUDE_D10_FND_KEY_H_ */
