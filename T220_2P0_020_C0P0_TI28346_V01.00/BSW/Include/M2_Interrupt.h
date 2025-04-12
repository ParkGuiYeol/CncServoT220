/*
 * File: M2_Interrupt.h
 *
 * C/C++ source code generated on : Sun Mar 16 11:41:14 2025
 * Created by: System Research Team
 *
 */

#ifndef BSW_INCLUDE_M2_INTERRUPT_H_
#define BSW_INCLUDE_M2_INTERRUPT_H_

/* user code (top of header file) */
/*********************************************************** EXTERNAL INPUT *****************************************************************/
//Input Check structure
typedef union{
    uint16_T  all;
    struct{
        uint16_T uSvOn:1;             // 00
        uint16_T uStart:1;            // 01
        uint16_T uEmg:1;              // 02
        uint16_T uAlarmRst:1;         // 03
        uint16_T uRefPst:6;           // 09
        uint16_T uStop:1;             // 10
        uint16_T uOrgin:1;            // 11
        uint16_T uDogin:1;            // 12
        uint16_T uPJog:1;             // 13
        uint16_T uNJog:1;             // 14
        uint16_T uEnMpg:1;            // 15
    } bit;
} S_EXINPUT;

/***********************************************************   EXTERNAL OUTPUT *****************************************************************/
//Input Check structure
typedef union{
    uint16_T  all;
    struct{
        uint16_T  uAlarm:1;         // 00
        uint16_T  uStadby:1;        // 01
        uint16_T  uBrake:1;         // 02
        uint16_T  uOrgOut:1;        // 03
        uint16_T  uInPst:1;         // 04
        uint16_T  uFltCode:4;       // 05-08
        uint16_T  uActPst:6;        // 09-14
        uint16_T  uOrgNotDef:1;     // 15
    } bit;
} S_EXOUTPUT;

/* user code (bottom of header file) */
extern uint16_T mBSW_uEstpSwitchDtc;
extern uint16_T mBSW_a11uReadInput[11];
extern uint16_T mBSW_uExinputAll;

#endif /* BSW_INCLUDE_M2_INTERRUPT_H_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
