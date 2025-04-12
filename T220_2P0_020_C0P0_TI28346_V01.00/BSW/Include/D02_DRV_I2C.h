/*
 * D02_DRV_I2C.h
 *
 *  Created on: 2025. 3. 27.
 *      Author: admin
 */

#ifndef BSW_INCLUDE_D02_DRV_I2C_H_
#define BSW_INCLUDE_D02_DRV_I2C_H_

#include "DSP2834x_Device.h"                // DSP2834x Register & Data Type Define.(Supported by TI)

// ############################################################################################################################# //

// ==========================================================  I2C ADD ======================================================== //
#define     USED_MARK                       0x06                    // EEPROM USED MARK SIGN
#define     EEP_MARK                        0x01                    // EEPROM USED MARK ADDRESS

#define     I2C_SLAVE_ADDR                  0x50                    // SLAVE ADDRESS
#define     I2C_CLR_NACK_BIT                0x0002                  // Clear Status Flags

// EEPROM DATA SAVE ADDRESS
#define     USB_PDCI_ADD_SRT                0x40                    // USB_PD_ADD_SRT ADDRESS
#define     EEP_SYSTEM_SRT                  0x40                    // EEPROM SYSTEM MENU START ADDRESS
#define     EEP_PD_ADD_SRT                  (EEP_SYSTEM_SRT+30*2)   // EEPROM CONTROL MENU START ADDRESS
#define     EEP_PC_ADD_SRT                  (EEP_SYSTEM_SRT+60*2)   // EEPROM CONTROL MENU START ADDRESS
#define     EEP_P1_ADD_SRT                  (EEP_SYSTEM_SRT+90*2)   // EEPROM CONTROL MENU START ADDRESS
#define     EEP_P2_ADD_SRT                  (EEP_SYSTEM_SRT+120*2)  // EEPROM CONTROL MENU START ADDRESS

#define     Param_Menu_Item_Max             30                      // PARA. ITEM MAX. NO. 0~29

// =======================================================  Parameters Define ================================================== //
#define     Rated_Speed                     0               // PD000: Motor rated speed
#define     Max_Speed                       1               // PD001: Motor maximum speed
#define     Rated_Torque                    2               // PD002: Motor rated torque
#define     Max_Torque                      3               // PD003: Motor max torque
#define     Rated_Current                   4               // PD004: Rated current
#define     Max_Current                     5               // PD005: Max current
#define     Rotor_Inertia                   6               // PD006: Rotor inertia(Js)
#define     System_Inertia_Ratio            7               // PD007: System inertia ratio
#define     Torque_Constant                 8               // PD008: Torque Constant
#define     Number_of_pole                  9               // PD009: Number of pole
#define     BEMF_Constant                   10              // PD010: BEMF Constant
#define     Resistance                      11              // PD011: Phase resistance*10^3
#define     Inductance                      12              // PD012: Phase Inductance*10^3
#define     ParameterM_Ke                   13              // PD013: BEMF Constant*2*PI/1000 x 60/(2*PI)
#define     ParameterM_Phi                  14              // PD014: phi_f = Ke* 2/P
#define     ParameterM_Kt                   15              // PD015: Kt = P/2 x 3/2 x phi_f
#define     ParameterM_Inv_Kt               16              // PD016: Inv_Kt = 1/Kt
#define     Curr_Accel_Decel_Time           17              // PD017: Current Acceleration/Deceleration Time
#define     Spd_Accel_Decel_Time            18              // PD018: Speed Acceleration/Deceleration Time
#define     Theta_offset                    19              // PD019: ���� ����
#define     POS_ORIGIN_1                    20              // PD020: �ⱸ ���� ���� �� 1
#define     POS_ORIGIN_2                    21              // PD021: �ⱸ ���� ���� �� 2
#define     POS_ORIGIN_3                    22              // PD022: �ⱸ ���� ���� �� 3
#define     POS_ORIGIN_4                    23              // PD023: �ⱸ ���� ���� �� 4
#define     POS_ORIGIN_5                    24              // PD024: ���ڴ� Ÿ��(0: Tamagawa ABS, 1: Inc 2000)
#define     Gear_Ratio                      25              // PD025: ���Ӻ�
#define     Turret_No_Of_Tool               26              // PD026: �ͷ� ������
#define     S_Curve_Flag                    27              // PD027: S Curve ���
#define     S_Curve_Gain                    28              // PD028: S Curve ����(Turret �ʱ� ������ S Ŀ�� ���� �ӵ�)
#define     Encoder_Type                    29              // PD029: ���ڴ� Ÿ��(0: Tamagawa ABS, 1: Inc 2000)

// =======================================================  Parameters Control ================================================ //
#define     CCG_Kpc                         0               // PC002: Current control gain: Kp = Wcc * L * 10^-3
#define     CCG_Kic                         1               // PC003: Current control gain: Ki = Wcc * R * 10^-3
#define     CCM_Kac                         2               // PC004: Ka = 1/CCM1.Kp
#define     Speed_Gain_Mode                 3               // PC005: �ӵ����� ���� ����
#define     SCG_Kp_1                        4               // PC006: �ӵ� ���� Kps ���� 1
#define     SCG_Ki_1                        5               // PC007: �ӵ� ���� ������ 1
#define     SCG_Ka_1                        6               // PC007: �ӵ� ���� ������ 1
#define     SCG_Kp_2                        7               // PC006: �ӵ� ���� Kps ���� 1
#define     SCG_Ki_2                        8               // PC007: �ӵ� ���� ������ 1
#define     SCG_Ka_2                        9               // PC007: �ӵ� ���� ������ 1
#define     SPD_Gain_ADJ_Speed1             10              // PC010: �ӵ� ���� ���� ���� �ӵ� 1
#define     SPD_Gain_ADJ_Speed2             11              // PC011: �ӵ� ���� ���� ���� �ӵ� 2
#define     SPD_Gain_ADJ_TRQ1               12              // PC012: �ӵ� ���� ���� ���� ��ũ 1
#define     SPD_Gain_ADJ_TRQ2               13              // PC013: �ӵ� ���� ���� ���� ��ũ 2
#define     PI_IP_Ratio                     14              // PC014: PI-IP ���� ��� ����
#define     Position_Gain_Mode              15              // PC015: ��ġ ���� �̵� ����
#define     PCG_Loop_1                      16              // PC016: ��ġ���� Kpp ���� 1
#define     PCG_Loop_2                      17              // PC017: ��ġ���� Kpp ���� 2
#define     PCG_Kdd_1                       18              // PC018: ��ġ ���� Kdp ����
#define     PCG_Kdd_2                       19              // PC018: ��ġ ���� Kdp ����
#define     Pos_Gain_ADJ_Speed1             20              // PC019: ��ġ ���� ���� ���� �ӵ� 1
#define     Pos_Gain_ADJ_Speed2             21              // PC020: ��ġ ���� ���� ���� �ӵ� 2
#define     Pos_Gain_ADJ_TRQ1               22              // PC021: ��ġ ���� ���� ���� ��ũ 1
#define     Pos_Gain_ADJ_TRQ2               23              // PC022: ��ġ ���� ���� ���� ��ũ 2
#define     Pos_Gain_Feedforward_1          24              // PC023: �ǵ� ������ ���� 1
#define     Pos_Gain_Feedforward_2          25              // PC025: �ǵ� ������ ���� 2
#define     Pos_Gain_Feedforward_3          26              // PC026: �ǵ� ������ ���� 3
#define     Pos_Gain_Feedforward_4          27              // PC027: �ǵ� ������ ���� 4
#define     Pos_Gain_Feedforward_5          28              // PC028: �ǵ� ������ ���� 5
#define     Pos_Gain_Feedforward_6          29              // PC029: �ǵ� ������ ���� 6

// =================================================== Parameters Bank 1 =================================================== //
#define     Stop_Position1_Offset           0               // PA1_17: ���� ��ġ 1 ������
#define     Stop_Position2_Offset           1               // PA1_18: ���� ��ġ 2 ������
#define     Pre_Set_Point                   2               // PA2_19: ������ ��ġ (750 => 7.5 ��)
#define     Deceleration_Init_Point_OV1_1   3               // PA2_91: ���Ӱ��� ��ġ 1(OV1), �������̵�
#define     Stop_Point_OV1_1                4               // PA2_92: ���� ��ġ 1(OV1), �������̵�
#define     Deceleration_Init_Point__OV1_2  5               // PA2_96: ���Ӱ��� ��ġ 2(OV2), �������̵�
#define     Stop_Point_OV1_2                6               // PA2_98: ���� ��ġ 2(OV2), �ⱸ ����, �������̵�
#define     Origin_Set_Use_Key              7               // PA2_07: ���� ���� ����
#define     ATC_Direction                   8               // PA2_08: ATC ȸ�� ���� ����(0: CW, 1: CCW)
#define     HEAVY_ACCEL_TIME_GAIN           9               // PA2_09: HEAVY_ACCEL_TIME_GAIN
#define     Decel_Init_Point_3_Auto         10              // PA2_10: Decel_Init_Point_3_Auto
#define     Decel_Init_Point_4_Auto         11              // PA2_11: Decel_Init_Point_4_Auto
#define     Decel_Init_Point_3_Auto_OV      12              // PA2_12: Decel_Init_Point_3_Auto_OV
#define     Decel_Init_Point_4_Auto_OV      13              // PA2_13: Decel_Init_Point_3_Auto_OV
#define     LPF_SPD_FREQUNCY                14              // PA2_14: LPF_SPD_FREQUNCY
#define     P1_Spare_15                     15              // PA2_15: P1_Spare_15
#define     CEND_Offset_1                   16              // PA2_16: �ͷ� CEND, IN_Position ���� ����
#define     CEND_Offset_2                   17              // PA2_17: �ͷ� CEND, IN_Position ���� ����
#define     CEND_Offset_3                   18              // PA2_18: �ͷ� CEND, IN_Position ���� ����
#define     CEND_Offset_4                   19              // PA2_19: �ͷ� CEND, IN_Position ���� ����
#define     CEND_Offset_5                   20              // PA2_20: �ͷ� CEND, IN_Position ���� ����
#define     CEND_Offset_6                   21              // PA2_21: �ͷ� CEND, IN_Position ���� ����
#define     P1_Spare_22                     22              // PA2_22:
#define     DETAIL_JOG_SPDREF               23              // PA2_23: DETAIL_JOG_SPDREF
#define     STEP_JOG_SPDREF                 24              // PA2_24: STEP_JOG_SPDREF
#define     Turret_Direction                25              // PA2_25: Turret Direction(0: CW, 1: CCW)
#define     IO_SEL                          26              // PA2_26: Turret Communication(0: I/O, 1: FANUC Serial)
#define     Operation_Mode                  27              // PA2_27: 10: Turret, 20: F500, 30: F500 II
#define     Auto_Calc_PresetNGear           28              // PA2_28: ���� Ʃ�� ����(Pre_set_Point, Gear Ratio)
#define     Auto_Step_Operation             29              // PA2_29: Auto_Step_Operation

// =================================================== Parameters Bank 2 =================================================== //
#define     CEND_Offset                     0               // PA3_73: OCEND ������
#define     P2_Spare_1                      1               // PA3_74: Spare
#define     Set_Speed_1                     2               // PA3_75: �ӵ� ���� 1
#define     Set_Speed_2                     3               // PA3_76: �ӵ� ���� 2
#define     Set_Speed_3                     4               // PA3_77: �ӵ� ���� 3
#define     Set_Speed_4                     5               // PA3_78: �ӵ� ���� 4
#define     Set_Speed_5                     6               // PA3_79: �ӵ� ���� 5
#define     Set_Override_Speed1             7               // PA3_80: �������̵� �ӵ� ���� 1
#define     Set_Override_Speed2             8               // PA3_81: �������̵� �ӵ� ���� 2
#define     Set_Override_Speed3             9               // PA3_82: �������̵� �ӵ� ���� 3
#define     Set_Override_Speed4             10              // PA3_83: �������̵� �ӵ� ���� 4
#define     Set_Override_Speed5             11              // PA3_84: �������̵� �ӵ� ���� 5
#define     Acceleration_Time_1             12              // PA3_85: ���� �ð� 1
#define     Deceleration_Time_1             13              // PA3_86: ���� �ð� 1
#define     Acceleration_Time_2             14              // PA3_87: ���� �ð� 2
#define     Deceleration_Time_2             15              // PA3_88: ���� �ð� 2
#define     Acceleration_Time_3             16              // PA3_89: ���� �ð� 3
#define     Deceleration_Time_3             17              // PA3_90: ���� �ð� 3
#define     Decel_Init_Point_1_Auto         18              // PA3_91: ���� ���� ��ġ 1(�ڵ�)
#define     Stop_Point_1_Auto               19              // PA3_92: ���� ��ġ 1(�ڵ�)
#define     Decel_Init_Point_2_Auto         20              // PA3_93: ���� ���� ��ġ 2(�ڵ�)
#define     Stop_Point_2_Auto               21              // PA3_94: ���� ��ġ 2(�ڵ�)
#define     Area1_Init_Point_Manu           22              // PA3_95: Area1 ���� ��ġ(����)
#define     Area1_End_Point_Manu            23              // PA3_96: Area1 ���� ��ġ(����)
#define     Area2_Init_Point_Manu           24              // PA3_97: Area2 ���� ��ġ(����)
#define     Area2_End_Point_Manu            25              // PA3_98: Area2 ���� ��ġ(����)
#define     Target_Point                    26              // PA3_99: ��ǥ ��ġ
#define     Manu_Oper_Speed                 27              // PA3_27: ���� ���� �ӵ�
#define     Manu_Opera_Accel_Decel_Time     28              // PA3_28: ���� ���� ������ �ð�
#define     Manu_Pos_Gain_Feedforward       29              // PA3_29:

#define     T_Set_Speed_1                   2               // PA3_75: �ӵ� ���� 1
#define     T_Set_Speed_2                   3               // PA3_76: �ӵ� ���� 2
#define     T_Set_Speed_3                   4               // PA3_77: �ӵ� ���� 3
#define     T_Set_Speed_4                   5               // PA3_78: �ӵ� ���� 4
#define     T_Set_Speed_5                   6               // PA3_79: �ӵ� ���� 5
#define     T_Set_Speed_6                   7               // PA3_79: �ӵ� ���� 5
// ############################################################################################################################# //
extern uint16_T mI2c_uFlagSaveEncOrigin;
extern uint16_T mI2c_uFlagResetEnc;

extern float PD[Param_Menu_Item_Max];              // Parameters Define
extern float PC[Param_Menu_Item_Max];              // Parameters Invariable Value
extern float P1[Param_Menu_Item_Max];              // Parameters Control Value
extern float P2[Param_Menu_Item_Max];              // Parameters Control Value

extern void Bftn_SaveOriginData(void);
extern void Bftn_ResetEncMultiTurn(void);

#endif /* BSW_INCLUDE_D02_DRV_I2C_H_ */
