/*
 *	D02_DRV_I2C.c
 *
 * C/C++ source code generated on : Thu Jan 11 10:09:04 2024
 * Created by: System Research Team
 * Code generated on : Sat Mar 15 00:16:24 2025
 *
 */

#include "Define_Header.h"
#include "M1_Interrupt.h"
#include "D02_DRV_I2C.h"

/*********************************************************** 		Variables		***********************************************************/
uint16_T mI2c_uFlagSaveEncOrigin = 0U;
uint16_T uFlagSaveEncOriginZ = 0U;

uint16_T mI2c_uFlagResetEnc = 0U;
uint16_T uFlagResetEncZ = 0U;

uint16_T error_code = 0U;
uint16_T main_temp0 = 0U;
uint16_T Flag_EEPROM_Busy = 0U;

int16 EEP_Load0 = 0, EEP_Load1 = 0;
unsigned int eep_cnt = 0;
unsigned int eep_addr = 0;
unsigned int eep_inter_addr = 0;
unsigned int eep_data = 0;
char Flag_Init = 0;

float PD[Param_Menu_Item_Max];              // Parameters Define
float PC[Param_Menu_Item_Max];              // Parameters Invariable Value
float P1[Param_Menu_Item_Max];              // Parameters Control Value
float P2[Param_Menu_Item_Max];              // Parameters Control Value

// Rounded value
//                        0, 1,   2,   3,   4,   5,   6,   7,   8,   9,       10,  11,  12,   13,   14,   15,   16, 17,   18,    19,      20,  21,  22,  23,   24,   25,  26,    27,   28,   29
float PD_RV[30]     = {   1, 1, 100, 100, 100, 100, 100,  10, 100,  10,      100,  10, 100, 1000, 1000, 1000, 1000,  1,    1, 10000,       1,   1,   1,   1,    1, 1000,   1,     1,    1,    1};
float PC_RV[30]     = { 100, 1, 100,   1, 100, 100, 100, 100, 100, 100,        1,   1,  10,   10,  100,    1,   10, 10,   10,    10,       1,   1,  10,  10, 1000, 1000, 1000, 1000, 1000, 1000};
float P1_RV[30]     = {   1, 1,   1, 100, 100, 100, 100,   1,   1, 100,      100, 100, 100,  100,    1,    1,   10, 10,   10,    10,      10,   1,   1,   1,    1,    1,    1,    1,    1,    1};
float P2_RV[30]     = {   1, 1,   1,   1,   1,   1,   1,   1,   1,   1,        1,   1,   1,    1,    1,    1,    1,  1,   100,  100,     100, 100, 100, 100,  100,  100,  100,    1,    1, 1000};

// 1/Rounded value
//                         0, 1,    2,    3,    4,    5,    6,    7,    8,    9,       10,   11,   12,    13,    14,    15,    16,  17,    18,     19,       20,   21,   22,   23,    24,    25,    26,    27,    28,    29
float PD_DP[30]     = {    1, 1, 0.01, 0.01, 0.01, 0.01, 0.01,  0.1, 0.01,  0.1,     0.01,  0.1, 0.01, 0.001, 0.001, 0.001, 0.001,   1,     1, 0.0001,        1,    1,    1,     1,     1, 0.001,     1,     1,     1,     1};
float PC_DP[30]     = { 0.01, 1, 0.01,    1, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01,        1,    1,  0.1,   0.1,  0.01,     1,   0.1, 0.1,   0.1,    0.1,        1,    1,  0.1,   0.1, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001};
float P1_DP[30]     = {    1, 1,    1, 0.01, 0.01, 0.01, 0.01,    1,    1, 0.01,     0.01, 0.01, 0.01,  0.01,     1,     1,   0.1, 0.1,   0.1,    0.1,      0.1,    1,    1,     1,     1,     1,     1,     1,     1,     1};
float P2_DP[30]     = {    1, 1,    1,    1,    1,    1,    1,    1,    1,    1,        1,    1,    1,     1,     1,     1,     1,   1,  0.01,   0.01,     0.01, 0.01, 0.01,  0.01,  0.01,  0.01,  0.01,     1,     1, 0.001};

const float Const_PD[Param_Menu_Item_Max]=      // Constant PD(Parameters Define)     (Turret: ¡ß, ATC: ¡Þ)
{
        3000,       // PD000: Rated_Speed                                                   ¡ß   ¡Þ
        3800,       // PD001: Max_Speed                                                     ¡ß   ¡Þ
        1.5,        // PD002: Rated_Torque                                                  ¡ß   ¡Þ
        4.3,        // PD003: Max_Torque                                                    ¡ß   ¡Þ
        2.33,       // PD004: Rated_Current                                                 ¡ß   ¡Þ
        7.0,        // PD005: Max_Current[I_rms]                                            ¡ß   ¡Þ
        0.33,       // PD006: Rotor_Inertia, ¡¿10-4kg¡¤m2                                     ¡ß   ¡Þ
        300,        // PD007: System_Inertia_Ratio                                          ¡ß   ¡Þ
        0.64,       // PD008: Torque_Constant                                               ¡ß   ¡Þ
        8,          // PD009: Number_of_pole                                                ¡ß   ¡Þ
        24.2,       // PD010: BEMF_Constant, 10^-3 Vp / min^-1                              ¡ß   ¡Þ
        2090,       // PD011: Resistance[m§Ù]                                                ¡ß   ¡Þ
        7.57,       // PD012: Inductance[mH]                                                ¡ß   ¡Þ
        0.327,      // PD013: ParameterM_Ke, Automatic Calculation                          ¡ß   ¡Þ
        0.082,      // PD014: ParameterM_Phi, Automatic Calculation                         ¡ß   ¡Þ
        0.490,      // PD015: ParameterM_Kt, Automatic Calculation                          ¡ß   ¡Þ
        2.04,       // PD016: ParameterM_Inv_Kt, Automatic Calculation                      ¡ß   ¡Þ
        400,        // PD017: Curr_Accel/Decel Time                                         ¡ß   ¡Þ
        50000,      // PD018: Spd_Accel/Decel Time                                          ¡ß   ¡Þ
        3.1803,     // PD019: Theta_offset <<<<<<<<<< Motor Align                           ¡ß   ¡Þ

        0,          // PD020: Tamagawa_Multi_enc1                                          ¡ß   ¡Þ
        0,          // PD021: Tamagawa_Multi_enc2                                          ¡ß   ¡Þ
        0,          // PD022: Tamagawa_Multi_enc3                                          ¡ß   ¡Þ
        0,          // PD023: Tamagawa_Multi_enc4                                          ¡ß   ¡Þ
        0,          // PD024: Tamagawa_Multi_enc5                                          ¡ß   ¡Þ

        50.0,       // PD025: Gear_Ratio                                                    ¡ß   ¡Þ
        28,         // PD026: Turret_No_Of_Tool                                             ¡ß
        0,          // PD027: S_Curve_Flag                                                  ¡ß
        500,        // PD028: S-Cuve Parameters                                             ¡ß
        0,          // PD029: Encoder_Type,(0: Tamagawa ABS, 1: Inc 2000)
};

// PC
const float Const_PC[Param_Menu_Item_Max]=      // Constant PC(Parameters Control)
{
        20.0,       // PC000: CCG_Kpc                                                       ¡ß   ¡Þ
        12000,      // PC001: CCG_Kic                                                       ¡ß   ¡Þ
        10.0,       // PC002: CCM_KA                                                        ¡ß   ¡Þ

        1,          // PC003: Speed_Gain_Mode

        0.06,       // PC004: SCG_Kp_1                                                      ¡ß   ¡Þ
        7.0,        // PC005: SSCG_Ki_1                                                     ¡ß   ¡Þ
        50.0,       // PC006: SCG_Ka_1                                                      ¡ß   ¡Þ

        0.06,       // PC007: SCG_Kp_2                                                          ¡Þ
        7.0,        // PC008: SCG_Ki_2                                                          ¡Þ
        50.0,       // PC009: SCG_Ka_2                                                          ¡Þ

        500,        // PC010: SPD_Gain_ADJ_Speed1
        1000,       // PC011: SPD_Gain_ADJ_Speed2
        20.0,       // PC012: SPD_Gain_ADJ_TRQ1
        80.0,       // PC013: SPD_Gain_ADJ_TRQ2
        1.0,        // PC014: PI_IP_Ratio                                                   ¡ß   ¡Þ

        1,          // PC015: Position_Gain_Mode
        25.0,       // PC016: PCG_Loop_1                                                    ¡ß   ¡Þ
        30.0,       // PC017: PCG_Loop_2                                                    ¡ß   ¡Þ

        0,          // PC018: PCG_Kdd_1                                                     ¡ß   ¡Þ
        0,          // PC019: PCG_Kdd_2

        500,        // PC020: Pos_Gain_ADJ_Speed1                                           ¡ß   ¡Þ
        100,            // PC021: Pos_Gain_ADJ_Speed2                                           ¡ß   ¡Þ
        20.0,       // PC022: Pos_Gain_ADJ_TRQ1
        80.0,       // PC023: Pos_Gain_ADJ_TRQ2

        0.001,      // PC024: Pos_Gain_Feedforward_30                                       ¡ß   ¡Þ
        0.035,      // PC025: Pos_Gain_Feedforward_60                                       ¡ß
        0.000,      // PC026: Pos_Gain_Feedforward_90                                       ¡ß
        0.000,      // PC027: Pos_Gain_Feedforward_120                                      ¡ß
        0.000,      // PC028: Pos_Gain_Feedforward_150                                      ¡ß
        0.000,      // PC029: Pos_Gain_Feedforward_180                                      ¡ß
};

// P1
const float Const_P1[Param_Menu_Item_Max]=      // Constant P1(PARAMETERS Bank 1)
{
        20,         // P1000: Stop_Position1_Offset                                             ¡Þ
        20,         // P1001: Stop_Position2_Offset                                             ¡Þ
        1762,       // P1002: Pre_Set_Point                                                     ¡Þ

        58.0,       // P1003: Deceleration_Initation_Point_OV1_1                                ¡Þ
        65.5,       // P1004: Stop_Point_OV1_1                                                  ¡Þ
        257.0,      // P1005: Deceleration_Initation_Point__OV1_2                               ¡Þ
        294.5,      // P1006: Stop_Point_OV1_2                                                  ¡Þ

        0,          // P1007: Origin_Set_Use_Key                                            ¡ß   ¡Þ
        1,          // P1008: ATC_Direction                                                     ¡Þ
        1.00,       // P1009: HEAVY_ACCEL_TIME_GAIN                                             ¡Þ

        57.0,       // P1010: Decel_Init_Point_3_Auto                                           ¡Þ
        286.0,      // P1011: Decel_Init_Point_4_Auto                                           ¡Þ
        25.0,       // P1012: Decel_Init_Point_3_Auto_OV                                        ¡Þ
        280.0,      // P1013: Decel_Init_Point_3_Auto_OV                                        ¡Þ

        100,        // P1014: LPF_SPD_FREQUNCY                                              ¡ß   ¡Þ
        0,          // P1015: P1_Spare_15

        0.0,        // P1016: CEND_Offset_30,  Turret CEND                                  ¡ß
        0.0,        // P1017: CEND_Offset_60,  Turret CEND                                  ¡ß
        0.0,        // P1018: CEND_Offset_90,  Turret CEND                                  ¡ß
        0.0,        // P1019: CEND_Offset_120, Turret CEND                                  ¡ß
        0.0,        // P1020: CEND_Offset_150, Turret CEND                                  ¡ß
        0.0,        // P1021: CEND_Offset_180, Turret CEND                                  ¡ß

        0,          // P1022: P1_Spare_22
        20,         // P1023: DETAIL_JOG_SPDREF                                             ¡ß
        200,        // P1024: STEP_JOG_SPDREF                                               ¡ß
        0,          // P1025: Turret Direction(0: CW, 1: CCW)                               ¡ß
        0,          // P1026: Turret Communication(0: I/O, 1: FANUC Serial)                 ¡ß
        30,         // P1027: Operation_Mode(10: Turret, 20: F500, 30: F500 II)             ¡ß   ¡Þ
        0,          // P1028: Auto_Calc_PresetNGear                                             ¡Þ
        0,          // P1029: Auto_Step_Operation                                           ¡ß   ¡Þ
};

// P2
const float Const_P2[Param_Menu_Item_Max]=      // Constant P2(PARAMETERS Bank 2)
{
        400,        // P2000: CEND_Offset                                                       ¡Þ
        0,          // P2001: Pre_Set_Point_Calc                                                ¡Þ

        3200,       // P2002: Set_Speed_1, T_Set_Speed_1                                    ¡ß   ¡Þ
        3200,       // P2003: Set_Speed_2, T_Set_Speed_2                                    ¡ß   ¡Þ
        3000,       // P2004: Set_Speed_3, T_Set_Speed_3                                    ¡ß   ¡Þ
        3000,       // P2005: Set_Speed_4, T_Set_Speed_4                                    ¡ß   ¡Þ
        3200,       // P2006: Set_Speed_5, T_Set_Speed_5                                    ¡ß   ¡Þ

        3000,       // P2007: Set_Override_Speed1, T_Set_Speed_6                            ¡ß   ¡Þ
        1500,       // P2008: Set_Override_Speed2                                               ¡Þ
        1500,       // P2009: Set_Override_Speed3                                               ¡Þ
        1500,       // P2010: Set_Override_Speed4                                               ¡Þ
        3000,       // P2011: Set_Override_Speed5                                               ¡Þ

        50000,      // P2012: Acceleration_Time_1                                               ¡Þ
        40000,      // P2013: Deceleration_Time_1                                               ¡Þ
        50000,      // P2014: Acceleration_Time_2                                               ¡Þ
        50000,      // P2015: Deceleration_Time_2                                               ¡Þ
        50000,      // P2016: Acceleration_Time_3                                               ¡Þ
        50000,      // P2017: Deceleration_Time_3                                               ¡Þ

        58.0,       // P2018: Deceleration_Initiation_Point_1_Auto                              ¡Þ
        65.5,       // P2019: Stop_Point_1_Auto                                                 ¡Þ
        287.0,      // P2020: Deceleration_Initiation_Point_2_Auto                              ¡Þ
        294.5,      // P2021: Stop_Point_2_Auto                                                 ¡Þ

        58.0,       // P2022: Area1_Initiation_Point_Manu                                       ¡Þ
        65.5,       // P2023: Area1_End_Point_Manu                                              ¡Þ
        287.0,      // P2024: Area2_Initiation_Point_Manu                                       ¡Þ
        294.0,      // P2025: Area2_End_Point_Manu                                              ¡Þ

        360.00,     // P2026: Target_Point                                                      ¡Þ
        500,        // P2027: Manu_Oper_Speed                                                   ¡Þ
        20000,      // P2028: Manu_Opera_Accel_Decel_Time                                       ¡Þ
        0.5,        // P2029: Manu_Pos_Gain_Feedforward
};

static void USED_MARK_Load(void);
static void USED_MARK_Save(void);
static void PD_Read(void);
static void PC_Read(void);
static void P1_Read(void);
static void P2_Read(void);
static void Param_Init(void);
// =========================================================== Codes ================================================================//
void Eeprom_Delay(unsigned long eeprom_loop)
{
	eeprom_loop = eeprom_loop * 80;

	while( --eeprom_loop )
	{
		asm(" NOP");
	}

	return;
}

void Init_I2C(void)											// Initialize I2C-A:
{
	I2caRegs.I2CPSC.all = 29;        						// Prescaler - need 7-12 Mhz on module clk (150/15 = 10MHz)

	I2caRegs.I2CCLKL = 10;									// NOTE: must be non zero
	I2caRegs.I2CCLKH = 10;									// NOTE: must be non zero

	I2caRegs.I2CMDR.all = 0x0020;							// Take I2C out of reset
   															// Stop I2C when suspended

	I2caRegs.I2CFFTX.all = 0x6000;							// Enable FIFO mode and TXFIFO
	I2caRegs.I2CFFRX.all = 0x2040;							// Enable RXFIFO, clear RXFFINT,

	return;
}

void Eep_Load(void)
{
	if(!(eep_addr & BIT8))
	{
		I2caRegs.I2CSAR = I2C_SLAVE_ADDR;       			// Setup slave address, b0=0
		eep_inter_addr = eep_addr - 0;
	}
	else
	{
		I2caRegs.I2CSAR = I2C_SLAVE_ADDR+1;      			// Setup slave address, b0=1
		eep_inter_addr = eep_addr - 256;
	}

	I2caRegs.I2CCNT = 1;
	I2caRegs.I2CDXR = eep_inter_addr;

	I2caRegs.I2CMDR.all = 0x2620;	        				// Send data to setup EEPROM address

	Eeprom_Delay(50);

	if(I2caRegs.I2CSTR.bit.NACK == 1)
	{
		I2caRegs.I2CMDR.bit.STP = 1;
		I2caRegs.I2CSTR.all = I2C_CLR_NACK_BIT;
		error_code = 20;									// MEMORY ERROR=20
	}

	if(!(eep_addr & BIT8))
	{
		I2caRegs.I2CSAR = I2C_SLAVE_ADDR;       			// Setup slave address, b0=0
	}
	else
	{
		I2caRegs.I2CSAR = I2C_SLAVE_ADDR+1;       			// Setup slave address, b0=1
	}

	I2caRegs.I2CCNT = 1;									// numbytes
	I2caRegs.I2CMDR.all = 0x2C20;		    				// Send restart as master receiver

	Eeprom_Delay(50);

	eep_data = I2caRegs.I2CDRR;

	if(I2caRegs.I2CSTR.bit.NACK ==1)
	{
		I2caRegs.I2CMDR.bit.STP = 1;
		I2caRegs.I2CSTR.all = I2C_CLR_NACK_BIT;
		error_code = 20;									// MEMORY ERROR=20
	}

	I2caRegs.I2CFFTX.bit.TXFFRST=0;
	I2caRegs.I2CFFRX.bit.RXFFRST=0;
	I2caRegs.I2CFFTX.bit.TXFFRST=1;
	I2caRegs.I2CFFRX.bit.RXFFRST=1;

	Eeprom_Delay(8);										// 4*10usec=40USEC

	return;
}

void Eep_Save(void)
{
	I2caRegs.I2CFFTX.bit.TXFFRST = 0;						//FIFI RESET
	I2caRegs.I2CFFTX.bit.TXFFRST = 1;						//FIFO ENABLE

	if(!(eep_addr & BIT8))
	{
		I2caRegs.I2CSAR = I2C_SLAVE_ADDR;       			// Setup slave address, b0=0
		eep_inter_addr = eep_addr - 0;
	}
	else
	{
		I2caRegs.I2CSAR = I2C_SLAVE_ADDR + 1;       		// Setup slave address, b0=1
		eep_inter_addr = eep_addr - 256;
	}

	I2caRegs.I2CCNT = 2;           							// Setup number of bytes (Buffer + Address)
	I2caRegs.I2CDXR = eep_inter_addr;             			// Memory Address
	I2caRegs.I2CDXR = eep_data;

	I2caRegs.I2CMDR.all = 0x6E20;           				// Send start as master transmitter

	Eeprom_Delay(1000);										//500*10usec=5msec

	if(I2caRegs.I2CSTR.bit.NACK ==1)						//nak check
	{
		I2caRegs.I2CMDR.bit.STP = 1;						//stop bit clear
		I2caRegs.I2CSTR.all = I2C_CLR_NACK_BIT;				//nak bit clear

		error_code = 20;									//MEMORY ERROR=20
	}

	return;
}

void USED_MARK_Load(void)
{
    eep_addr = EEP_MARK;                                            // SET 1st USED MARK ADDRESS
    Eep_Load();                                                     // EEPROM DATA READ, RESULT=EEP_DATA
    EEP_Load0 = eep_data;

    eep_addr = (EEP_MARK+1);                                        // SET 2nd USED MARK ADDRESS
    Eep_Load();                                                     // EEPROM DATA READ, RESULT=EEP_DATA
    EEP_Load1 = eep_data;

    return;
}

void USED_MARK_Save(void)
{
    eep_addr = EEP_MARK;                                    //EEPROM 1st USED MARK ADDRESS SET
    eep_data = USED_MARK;                                   // used mark write
    Eep_Save();

    eep_addr = (EEP_MARK+1);                                // EEPROM 2nd USED MARK ADDRESS SET
    eep_data = USED_MARK;                                   // used mark write
    Eep_Save();

    return;
}

void PD_Read(void)
{
    /****************************** PD Value Read, Decimal Point = 2 ****************************/
    eep_cnt = 0;
    eep_addr = EEP_PD_ADD_SRT;

    do
    {
        Eep_Load();
        main_temp0 = eep_data & 0x00ff;
        eep_addr++;
        Eep_Load();
        eep_data = eep_data << 8;
        eep_data = eep_data & 0xff00;
        main_temp0 = (main_temp0 | eep_data);
        PD[eep_cnt] = (float)main_temp0 * PD_DP[eep_cnt];

        eep_addr++;
        eep_cnt++;

    } while(eep_cnt < Param_Menu_Item_Max);

    return;
}

void PC_Read(void)
{
    /****************************** PC Value Read, Decimal Point = 1 *************************/
    eep_cnt = 0;
    eep_addr = EEP_PC_ADD_SRT;

    do
    {
        Eep_Load();
        main_temp0 = eep_data & 0x00ff;
        eep_addr++;
        Eep_Load();
        eep_data = eep_data << 8;
        eep_data = eep_data & 0xff00;
        main_temp0 = (main_temp0 | eep_data);
        PC[eep_cnt] = ((float)main_temp0) * 0.1;

        PC[eep_cnt] = ((float)main_temp0)*PC_DP[eep_cnt];                       // dPCM1_KP: 0.0007, Decimal Point 4

        eep_addr++;
        eep_cnt++;

    } while(eep_cnt < Param_Menu_Item_Max);

    return;
}

void P1_Read(void)
{
    /************************** P1 Value Read, Decimal Point = ? ***************************/
    eep_cnt = 0;
    eep_addr = EEP_P1_ADD_SRT;

    do
    {
        Eep_Load();
        main_temp0 = eep_data & 0x00ff;

        eep_addr++;
        Eep_Load();

        eep_data = eep_data << 8;
        eep_data = eep_data & 0xff00;
        main_temp0 = (main_temp0 | eep_data);

        P1[eep_cnt] = (float)main_temp0 * P1_DP[eep_cnt];

        eep_addr++;

        eep_cnt++;
    } while(eep_cnt < Param_Menu_Item_Max);

    return;
}

void P2_Read(void)
{
    /************************** P2 Value Read, Decimal Point = ? ***************************/
    eep_cnt = 0;
    eep_addr = EEP_P2_ADD_SRT;

    do
    {
        Eep_Load();
        main_temp0 = eep_data & 0x00ff;

        eep_addr++;
        Eep_Load();

        eep_data = eep_data << 8;
        eep_data = eep_data & 0xff00;
        main_temp0 = (main_temp0 | eep_data);

        P2[eep_cnt] = (float)main_temp0 * P2_DP[eep_cnt];

        eep_addr++;

        eep_cnt++;
    } while(eep_cnt < Param_Menu_Item_Max);

    return;
}

void Param_Init(void)
{
    // Parameters Define Value Initialize
    eep_cnt = 0;
    do
        {
            PD[eep_cnt] = Const_PD[eep_cnt];                                //parameter read from table, 16bit(lsb+masb)
            eep_cnt++;
        } while(eep_cnt < Param_Menu_Item_Max);

    // Control Constant Value Initialize
    eep_cnt = 0;
    do
        {
            PC[eep_cnt] = Const_PC[eep_cnt];                                //parameter read from table, 16bit(lsb+masb)
            eep_cnt++;
        } while(eep_cnt < Param_Menu_Item_Max);

    // Parameters Bank 1 Value Initialize
    eep_cnt = 0;
    do
        {
            P1[eep_cnt] = Const_P1[eep_cnt];                                //parameter read from table, 16bit(lsb+masb)
            eep_cnt++;
        } while(eep_cnt < Param_Menu_Item_Max);

    // Parameters Bank 1 Value Initialize
    eep_cnt = 0;
    do
        {
            P2[eep_cnt] = Const_P2[eep_cnt];                                //parameter read from table, 16bit(lsb+masb)
            eep_cnt++;
        } while(eep_cnt < Param_Menu_Item_Max);

    return;
}

void PD_Save(void)                                                          // Parameters Define Save
{
    Flag_EEPROM_Busy = 1;
    mBSW_uInitNvRam = 1U;                                               // The initial data save mode of the EEPROM. The user has to reboot the drive.
    PWM1_OFF;

    eep_cnt = 0;                                                            // Loop counter initialize.
    eep_addr = EEP_PD_ADD_SRT;                                              // EEPROM PD START ADDRESS

    do
    {
        main_temp0 = PD[eep_cnt]*PD_RV[eep_cnt] + 0.5;                      // Parameter read from table, 16bit
        eep_data = main_temp0 & 0x00ff;
        Eep_Save();

        eep_addr++;
        eep_data = main_temp0 >> 8;
        eep_data = eep_data & 0x00ff;
        Eep_Save();                                                         // Data save

        eep_addr++;                                                         // EEPROM ADDRESS +1 FOR NEXT LOOP
        eep_cnt++;

    } while(eep_cnt < Param_Menu_Item_Max);

    Flag_EEPROM_Busy = 0;

    return;
}

void PC_Save(void)
{
    Flag_EEPROM_Busy = 1;
    mBSW_uInitNvRam = 1U;                                               // The initial data save mode of the EEPROM. The user has to reboot the drive.
    PWM1_OFF;

    eep_cnt = 0;                                                            // Loop counter initialize.
    eep_addr = EEP_PC_ADD_SRT;                                              // EEPROM PD START ADDRESS

        do
        {
            main_temp0 = PC[eep_cnt]*PC_RV[eep_cnt] + 0.5;                  // Parameter read from table, 16bit

            eep_data = main_temp0 & 0x00ff;

            Eep_Save();

            eep_addr++;
            eep_data = main_temp0 >> 8;
            eep_data = eep_data & 0x00ff;

            Eep_Save();                                                     // Data save

            eep_addr++;                                                     // EEPROM ADDRESS +1 FOR NEXT LOOP
            eep_cnt++;

        } while(eep_cnt < Param_Menu_Item_Max);

    Flag_EEPROM_Busy = 0;
    return;
}

void P1_Save(void)
{
    Flag_EEPROM_Busy = 1;
    mBSW_uInitNvRam = 1U;                                               // The initial data save mode of the EEPROM. The user has to reboot the drive.
    PWM1_OFF;

    eep_cnt = 0;                                                            // Loop counter initialize.
    eep_addr = EEP_P1_ADD_SRT;                                              // EEPROM PD START ADDRESS

    do
    {
        main_temp0 = P1[eep_cnt]*P1_RV[eep_cnt] + 0.5;                      // Parameter read from table, 16bit

        eep_data = main_temp0 & 0x00ff;

        Eep_Save();

        eep_addr++;
        eep_data = main_temp0 >> 8;
        eep_data = eep_data & 0x00ff;

        Eep_Save();                                                         // Data save

        eep_addr++;                                                         // EEPROM ADDRESS +1 FOR NEXT LOOP
        eep_cnt++;

    } while(eep_cnt < Param_Menu_Item_Max);

    Flag_EEPROM_Busy = 0;

    return;
}

void P2_Save(void)
{
    Flag_EEPROM_Busy = 1;
    mBSW_uInitNvRam = 1U;                                                   // The initial data save mode of the EEPROM. The user has to reboot the drive.
    PWM1_OFF;

    eep_cnt = 0;                                                            // Loop counter initialize.
    eep_addr = EEP_P2_ADD_SRT;                                              // EEPROM PD START ADDRESS

    do
    {
        main_temp0 = P2[eep_cnt]*P2_RV[eep_cnt] + 0.5;                      // Parameter read from table, 16bit

        eep_data = main_temp0 & 0x00ff;

        Eep_Save();

        eep_addr++;
        eep_data = main_temp0 >> 8;
        eep_data = eep_data & 0x00ff;

        Eep_Save();                                                         // Data save

        eep_addr++;                                                         // EEPROM ADDRESS +1 FOR NEXT LOOP
        eep_cnt++;

    } while(eep_cnt < Param_Menu_Item_Max);

    Flag_EEPROM_Busy = 0;
    return;
}

void Eep_Init(void)
{
    Eeprom_Delay(5000);                                                     // 5000*10usec=50msec power on delay

    eep_cnt = 0;

    do
    {
        USED_MARK_Load();

        if((EEP_Load0 == USED_MARK) && (EEP_Load1 == USED_MARK))            // 1st and 2nd used mark check
        {
            Flag_Init = 1;
            eep_cnt = 2;                                                    // Go out to the next step.
        }

        eep_cnt++;

    } while(eep_cnt<3);

    if(Flag_Init == 1)
    {
        PD_Read();
        PC_Read();
        P1_Read();
        P2_Read();
    }
    else
    {
        mBSW_uInitNvRam = 1U;                                               // The initial data save mode of the EEPROM. The user has to reboot the drive.

        USED_MARK_Save();

        Param_Init();

        PD_Save();
        PC_Save();
        P1_Save();
        P2_Save();
    }

//    Parameters_Apply(&M1);

    return;
}

void Bftn_SaveOriginData(void)
{
    // Active uFlagSaveEncOrigin
    if((mSMDE_uFlagSaveEncOrigin == 1U)||(uFlagSaveEncOriginZ == 0U))
    {
        mI2c_uFlagSaveEncOrigin = 1U;
    }

    uFlagSaveEncOriginZ = mSMDE_uFlagSaveEncOrigin;

    // SaveOriginData
    if(mI2c_uFlagSaveEncOrigin == 1U)
    {
        PD[POS_ORIGIN_1] = mSMDE_i64PstOrigin & 0x000000FF;                 // PD020
        PD[POS_ORIGIN_2] = (mSMDE_i64PstOrigin>>8) & 0x000000FF;            // PD021
        PD[POS_ORIGIN_3] = (mSMDE_i64PstOrigin>>16) & 0x000000FF;           // PD022
        PD[POS_ORIGIN_4] = (mSMDE_i64PstOrigin>>24) & 0x000000FF;           // PD023
        PD[POS_ORIGIN_5] = (mSMDE_i64PstOrigin>>32) & 0x000000FF;           // PD024

        PD_Save();
        mI2c_uFlagSaveEncOrigin = 0U;
        mBSW_uInitNvRam = 1U;                                               // The initial data save mode of the EEPROM. The user has to reboot the drive.
    }
}

void Bftn_ResetEncMultiTurn(void)
{
    // Active uFlagSaveEncOrigin
    if((mSMDE_uFlagResetEnc == 1U)||(uFlagResetEncZ == 0U))
    {
        mI2c_uFlagResetEnc = 1U;
    }

    uFlagResetEncZ = mSMDE_uFlagResetEnc;

    if(mI2c_uFlagResetEnc == 1U)
    {
        if(mMTPST_u32EncMultiTurn != 0)
        {
            FPGA_Send(0x11, 0);
        }
        else
        {
            mI2c_uFlagResetEnc = 0U;
            mBSW_uInitNvRam = 1U;                                           // The initial data save mode of the EEPROM. The user has to reboot the drive.
//            Mx->TI_Cont->Po_ref = Position;
        }
    }
}
