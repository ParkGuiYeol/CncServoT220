/*
 *  Fnd_key.c
 *
 *  Created on: 2016. 1. 20.
 *      Author: Park Gui Yeol
 *
 */

#include "Define_Header.h"
#include "d01_Diaglnteg.h"
#include "D10_Fnd_key.h"
#include "M2_Interrupt.h"

/**************************************************************   Variables   ************************************************************/
uint16_T key_input = 0U, old_key_input = 0U, key_buffer = 0U;
uint16_T sign = 0U;
uint16_T key_continuous = 0, Flag_key_continuous = 0, Flag_First_cotinuous = 0, Continuous_CNT = 0, Set_key_continuous = 0;
uint16_T FndDot[10]    = {0x00bf, 0x0086, 0x00db, 0x00cf, 0x00e6, 0x00ed, 0x00fd, 0x00a7, 0x00ff, 0x00ef};
uint16_T Fnd[10]       = {0x003f, 0x0006, 0x005b, 0x004f, 0x0066, 0x006d, 0x007d, 0x0027, 0x007f, 0x006f};
uint16_T Init_Disp[14] = {0x0000, 0x0000, 0x0000, 0x0000, 0x006d, 0x003f, 0x003f, 0x0006, 0x0040, 0x0006, 0x0066, 0x003f, 0x003f, 0x0000}; // S001-1400

// Decimal point number
//                    0, 1, 2, 3, 4, 5, 6, 7, 8, 9,   10, 11, 12, 13, 14, 15, 16, 17, 18, 19,    20, 21, 22, 23, 24, 25, 26, 27, 28, 29
char PD_Array[30] = { 0, 0, 2, 2, 2, 2, 2, 2, 2, 1,    2,  1,  2,  3,  3,  3,  3,  0,  0,  4,     0,  0,  0,  0,  0,  3,  0,  0,  2,  0};
char PC_Array[30] = { 2, 0, 2, 0, 2, 2, 2, 2, 2, 2,    0,  0,  1,  1,  2,  0,  1,  1,  1,  1,     0,  0,  1,  1,  3,  3,  3,  3,  3,  3};
char P1_Array[30] = { 0, 0, 0, 2, 2, 2, 2, 0, 0, 2,    3,  0,  1,  1,  1,  1,  0,  0,  0,  0,     0,  0,  0,  0,  0,  0,  0,  0,  0,  0};
char P2_Array[30] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0,  0,  0,  0,  0,  0,  0,  0,  2,  2,     2,  2,  2,  2,  2,  2,  2,  0,  0,  0};

// Limit                    0,     1,     2,     3,     4,     5,     6,     7,     8,     9,        10,    11,    12,    12,   14,     15,    16,    17,    18,     19,        20,    21,    22,    23,   24,     25,    26,    27,    28,  29
uint16_T PD_LIMIT[30] = { 50000, 50000,   100,   100,   100,   100,   100,    50,   100,   100,       100, 50000,   100,   100,  100,    100,   100, 50000, 50000, 6.5535,     65535, 65535, 65535, 65535,   10, 65.535, 65535,   100,     0,   1};
uint16_T PC_LIMIT[30] = {   500, 50000,   500,  1000,  1000,  1000,  1000,  1000,  1000,  1000,      5000,  5000,   100,   100,  100,      4,   100,   100,   100,    100,      5000,   100,   100,   100,  100,    100,   100,   100,   100, 100};
uint16_T P1_LIMIT[30] = { 36000, 36000, 36000,   360,   360,   360,   360,     1,     1,     1,       100,     0,   360,   360,  360,    360,     0,     0,     0,      0,         0,     0,     0,     0,    0,      0,     0,     0,     1,   1};
uint16_T P2_LIMIT[30] = { 20000, 20000, 20000, 20000, 20000, 20000, 20000, 20000, 20000, 20000,     20000, 20000, 20000, 20000, 20000, 20000, 20000, 20000,   360,    360,       360,   360,   360,   360,  360,    360,   360, 20000, 50000,   0};

uint16_T FndGpioSet[5] = {0};
uint16_T ForcedEstop = 0U;
uint16_T uFinishInitDisp = 1U;
int16_T i16Fnd_i = 0, i16Fnd_j = 0, i16Fnd_k = 0;

uint16_T uMode = MENU_Main;
int16_T iDisplay_DP = 0;
uint16_T ukeyBuffer = 0U;
uint16_T uForcedEstop = 0U;
uint16_T uSelectDefineNo = 0U;
uint16_T uModeNubBuffer[5] = {0U, 0U, 0U, 0U, 0U};
uint16_T uModeBuffer[5]    = {0x73, 0x5e, 0x3f, 0x3f, 0x3f};                // Initial data buffer of FND: Pd000(x: d, I, c)
char cMenu[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};                           // Array are going to reserve for FND buffer
char cMenuLimNo[10] = { 0, 3, 0, 1, 9, 0, 0, 0, 0, 0};                      // limit number in the FND buffer
// cMenuLimNo[10] = { P, D, 0, 0, 0, 0, 0, 0, 0, 0};
// cMenuLimNo[10]은 cProcedure의 값의 한계값
// cProcedure는 5개의 FND 메모리를 의미, [ P(0), D(1), 0(2), 0(3), 0(4)]
real32_T sDisplayValue = 0;

//char uModeBuffer[5]             = {0x73, 0x5e, 0x3f, 0x3f, 0x3f};         // Initial data buffer of FND: Pd000(x: d, I, c)
//char uModeNubBuffer[5]          = {0, 0, 0, 0, 0};
int16_T cProcedure = 1;
int16_T cProcedure_Change = 1;
//uint16_T uSelectDefineNo = 0U;
//uint16_T ukeyContinuous = 0U;
//uint16_T uSetkeyContinuous = 0U;
//uint16_T uFlagkeyContinuous = 0U;
//uint16_T uFlagFirstCotinuous = 0U;
//uint16_T uContinuousCNT = 0U;

/*****************************************************************************************************************************************
0x003f: 0       0x00bf: 1.      0x0077: A       0x0038: L       0x0040: CENTER -
0x0006: 1       0x0086: 2.      0x007c: B       0x0054: N       0x0001: UPPER -
0x005b: 2       0x00db: 3.      0x0039: C       0x005c: O       0x0008: LOWER -
0x004f: 3       0x00cf: 4.      0x005e: D       0x0073: P       0x00ff: ALL ON
0x0066: 4       0x00e6: 5.      0x0079: E       0x0067: Q       0x0000: LANK(ALL OFF)
0x006d: 5       0x00ed: 6.      0x0071: F       0x0050: R       0x001c: u
0x007d: 6       0x00fd: 7.      0x007d: G       0x006d: S       0x0074: k
0x0027: 7       0x00a7: 8.      0x0076: H       0x0078: T       0x0070: ㅏ
0x007f: 8       0x00ff: 9.      0x0006: I       0x0032: U
0x006f: 9       0x00ef: 0.      0x000E: J       0x006e: Y
******************************************************************************************************************************************/
static void putu(unsigned int value, uint16_T decimal_point);
static void putuf(unsigned int value, uint16_T decimal_point);
static void putf(float value, uint16_T decimal_point);
static void FndSet(int index, uint16_T data);
static void Key_Scan(void);
//static void Debounce_Delay(void);

/**************************************************************** Codes ******************************************************************/
//static void Debounce_Delay(void)
//{
//    unsigned long   debounce_loop;
//
//    debounce_loop = 1810;
//
//    while(--debounce_loop)
//    {
//        DELAY_US(1);
//    }
//
//    return;
//}

static void Key_Scan(void)
{
    unsigned long key_temp;

    key_temp = GpioDataRegs.GPBDAT.all;                 // All(32bit) porta read

    key_input = (key_temp >> 20);                       // Make bit27,26,25,24->bit3,2,1,0 (make 0000~1111 for table read)

    key_input = (key_input & 0x000f);                   // Remain bit0~3

    //Debounce_Delay();                                 // Debounce delay

    return;
}

void Key_Read(void)
{
    Key_Scan();                                         // key_input

    if(old_key_input != key_input)                      // Debounce ok check
    {
        key_buffer = key_input;
        key_continuous = 0;
        Flag_key_continuous = 0;
        Flag_First_cotinuous = 0;
    }
    else                                                // uMode가 MENU_Main이 아닌 상태에서  Up/Down 키를 연속으로 입력할 경우 key_input을 연속으로 발생시킨다.
    {
        if((uMode != MENU_Main) && (key_input == UP_KEY  || key_input == DOWN_KEY))
        {
            Flag_key_continuous = 1;
            key_continuous++;

            if(Flag_First_cotinuous == 0)
            {
                Continuous_CNT = 1000;
            }

            if(key_continuous > Continuous_CNT)
            {
                Flag_First_cotinuous = 1;
                Continuous_CNT = 100;
                key_continuous = 0;
                key_buffer = key_input;
            }
        }
        else
            Set_key_continuous = 0;
    }

    old_key_input = key_input;                              // key input data save for debounce check

//    asm(" nop");

    return;
}

static void putu(unsigned int value, uint16_T decimal_point)
{
    int i;

    char digit[5];                                          // 5 digit number -> digit[5];

    unsigned long temp;

    temp = (unsigned long)value ;

    for (i = (4-decimal_point); i >= 0; i--)                // 5 digit number -> Initial i = 4;
    {
        digit[i] = (temp % 10);
        temp = (unsigned int)temp/10 ;
    }

    i = 0 ;

    while ((digit[i] == 0) && (i < (5-decimal_point)))      // 5 digit number -> i < 5;
    {
        if(sign == 1)
        {
            FndSet(0x00, 0x40);
            if(uMode != Define_Change)
            {
                sign = 0;
            }
        }
        else
        {
            if(uMode == Define_Change)
                FndSet(i, 0x3f);                         // 0x003f: 0
            else
                FndSet(i, 0x00);                         // 0x0000: LANK(ALL OFF)
        }
        i++;
    }

    if (i == (5-decimal_point))                             // 5 digit number -> i == 5;
    {
        FndSet(i-1, FndDot[digit[0]]);                  // 값이 비었을 경우 "0."이라고 나타낸다.
    }
    else
    {
        if(uMode == Define_Change)
        {
            if(sign == 1)
            {
                sign = 0;
                i = 1 ;
            }
            else
                i = 0;
        }

        while (i < (5-decimal_point))                       // 5 digit number -> i == 5;
        {
            if(decimal_point == 0)                            // 정수형일 경우, digit array의 숫자를 차례로 나타낸다.
            {
                FndSet(i, Fnd[digit[i]]);
            }
            else
            {
                if(i==4-decimal_point)                      // 실수형일 경우, 마지막 정수에는 Point로 나타낸다.
                {
                    FndSet(i, FndDot[digit[i]]);
                }
                else
                    FndSet(i, Fnd[digit[i]]);
            }
            i++;
        }
    }

    i = 0;

    return;
}

static void putuf(unsigned int value, uint16_T decimal_point)
{
    int i;

    char digit[3];

    unsigned long temp ;

    temp = (unsigned long)value;

    for (i = decimal_point-1 ; i >= 0 ; i--)
    {                                                       //decimal_point 1: i = 0, decimal_point 2: i = 1
        digit[i] = (temp % 10);
        temp = (unsigned int)temp / 10;
    }

    i=0;

    while (i < decimal_point)
    {                                                       // decimal_point: 1->(i = 1), 2 ->(i = 2)
        FndSet(i+(-decimal_point+4), Fnd[digit[i++]]);   // decimal_point: 1->4, 2->3, 3->2
    }

    return;
}

static void putf(float value, uint16_T decimal_point)
{
    unsigned long float_Val, float_Val_1, integer, Integer_Val;

    if(value<0)
        sign = 1;
    else
        sign = 0;

    integer = (long)ABS(value);

    value *= pow(10, decimal_point);                        // decimal_point1: 10, decimal_point2: 100

    float_Val_1 = (long)ABS(value);

    Integer_Val = integer*pow(10, decimal_point);

    float_Val = float_Val_1 - Integer_Val;

    putu(integer, decimal_point);

    putuf(float_Val, decimal_point);

    return;
}

static void FndSet(int index, uint16_T data)
{
    switch (index)
    {
        case 0:
            FndGpioSet[0] = data;
            break;

        case 1:
            FndGpioSet[1] = data;
            break;

        case 2:
            FndGpioSet[2] = data;
            break;

        case 3:
            FndGpioSet[3] = data;
            break;

        case 4:
            FndGpioSet[4] = data;
            break;

        default:
            // No Action
            break;
    }
}

void Init_Display(void)
{
    if(i16Fnd_j < 14)
    {
//      if(i16Fnd_k < 20)
        if(i16Fnd_k < 15)                                   // Init_Disp 속도 조절
        {
            i16Fnd_k++;
        }
        else
        {
            i16Fnd_k = 0;
            i16Fnd_j++;

            while (i16Fnd_i < 5)
            {
                FndSet(i16Fnd_i, Init_Disp[i16Fnd_i]);
                i16Fnd_i++;
            }

            i16Fnd_i = 0;

            while(i16Fnd_i < 13)
            {
                Init_Disp[i16Fnd_i] = Init_Disp[i16Fnd_i+1];
                i16Fnd_i++;
                Init_Disp[13] = 0x0000;
            }

            i16Fnd_i = 0;
        }
    }
    else
    {
        putu(mM2Int_SwRev, 0U);

        // S/W Version Display
        if(mBSW_iCntFndFlicker == 1)
        {
            FndSet(0x00, 0x6d);                                 // Send "S" to the First FND.
        }
        else if(mBSW_iCntFndFlicker == 2)
        {
            FPGA_Send(0x00, 0x00);                              // Disable Display in the main function.(Flicker Function)
        }

        if(i16Fnd_k < 100)                                      // S/W Ver Display Time
        {
            i16Fnd_k++;
        }
        else
        {
            uFinishInitDisp = 0U;
        }
    }
}

void Main_Display(uint16_T display_no)
{
    switch(uMode)
    {
        //================================================================================================================//
        case  MENU_Main:                                                        // 0, Default Function

            if(mI2c_uFlagResetEnc == 1U)                                        // Origin Display
            {
                FndGpioSet[0] = 0x005c;
                FndGpioSet[1] = 0x0050;
                FndGpioSet[2] = 0x0006;
                FndGpioSet[3] = 0x007d;
                FndGpioSet[4] = 0x0054;
            }
            else
            {
                if(mDIAG_uFltStat != 0U)
                {
                    putu(FltFndDisp, 0U);                                       // Fault Code Display

                    if(mBSW_iCntFndFlicker == 1)
                    {
                        FndSet(0x00, 0x71);                                     // Send "F" to the First FND.
                    }
                    else if(mBSW_iCntFndFlicker == 2)
                    {
                        FPGA_Send(0x00, 0x00);                                  // Disable Display in the main function.(Flicker Function)
                    }
                }
                else
                {
                    switch(display_no)
                    {
                        case 0:
                            putf(mSsens_sIvtTempLow, 2U);
                            break;

                        case 1:
                            putf(mSsens_sMrtTempLow, 2U);
                            break;

                        case 2:
                            putf(mMsens_sHVdcLow, 2U);
                            break;

                        case 3:
                            putf(mCTRL_sIsRef, 2U);
                            break;

                        case 4:
                            putf(mCTRL_sTqRefIn, 2U);
                            break;

                        case 5:
                            putf(mMTPST_sRpm, 0U);
                            break;

                        default:

                            break;
                    }
                }
            }

            break;

        //================================================================================================================//
        case  Mode_Select:                                                      // 1, Mode select function
            FndGpioSet[0] = uModeBuffer[0];
            FndGpioSet[1] = uModeBuffer[1];
            FndGpioSet[2] = uModeBuffer[2];
            FndGpioSet[3] = uModeBuffer[3];
            FndGpioSet[4] = uModeBuffer[4];

            if(mBSW_iCntFndFlicker == 1)
            {
                FndGpioSet[cProcedure] = uModeBuffer[cProcedure];
            }
            else if(mBSW_iCntFndFlicker == 2)
            {
                FndGpioSet[cProcedure] = 0x00;
            }

            break;

        //================================================================================================================//
        case  Define_Change:                                                    // Define_Change function
            putf(sDisplayValue, (uint16_T)iDisplay_DP);                         // Fault Code Display

            if(mBSW_iCntFndFlicker == 1)
            {
                // No Action
            }
            else if(mBSW_iCntFndFlicker == 2)
            {
                FndGpioSet[4-cProcedure_Change] = 0x00;
            }

            break;

        //================================================================================================================//
        case Auto_Align:
            break;

        //================================================================================================================//
        default:
            uMode = MENU_Main;
            break;
    }
}

void Btn_Operation(void)
{
    switch(uMode)
    {
        //================================================================================================================//
        case  MENU_Main:                                                        // 0, Default Function
            if(mSMDE_uFlagInverterOut == 0U)
            {
                if(key_buffer != MODE_KEY)
                {
                    uMode = MENU_Main;
                                                                                    //   M  U  D  S     M  U  D  S
                    if((key_buffer == DOWN_SET_KEY)||(key_buffer == UP_SET_KEY))    // [ □  □  ■  ■ ] [ □  ■  □  ■ ] / e-Stop
                    {
                        ForcedEstop = 1;
                    }

                    if(key_buffer == MODE_SET_KEY)                                  // [ ■  □  □  ■ ]   M U D S   /   Align.
                    {
                        uMode = Auto_Align;
                    }
                }
                else
                {
                    key_buffer = 0;
                    uMode = Mode_Select;
                }
            }

            break;

        //================================================================================================================//
        case  Mode_Select:                                                      // 1, Mode select function
            if(key_buffer == SET_KEY)
            {
                key_buffer = 0;

                uSelectDefineNo = (uModeNubBuffer[2]*100)+(uModeNubBuffer[3]*10)+uModeNubBuffer[4];

                if(uModeBuffer[1] == 0x5e)                                      // PD
                {
                    sDisplayValue = PD[uSelectDefineNo];
                    iDisplay_DP = PD_Array[uSelectDefineNo];
                }
                else if(uModeBuffer[1] == 0x39)                                 // PC
                {
                    sDisplayValue = PC[uSelectDefineNo];
                    iDisplay_DP = PC_Array[uSelectDefineNo];
                }
                else if(uModeBuffer[1] == 0x06)                                 // P1
                {
                    sDisplayValue = P1[uSelectDefineNo];
                    iDisplay_DP = P1_Array[uSelectDefineNo];
                }
                else if(uModeBuffer[1] == 0x5b)                                 // P2
                {
                    sDisplayValue = P2[uSelectDefineNo];
                    iDisplay_DP = P2_Array[uSelectDefineNo];
                }

                cProcedure_Change = 0;                                          // Cursor position initialize.
                uMode = Define_Change;
            }
            else if(key_buffer == MODE_KEY)
            {
                key_buffer = 0;
                cProcedure++;                                                   // Change the position of the FND Buffer.
                if(cProcedure > 4)                                              // Change FND buffer(1~4: except 0 buffer)
                {
                    cProcedure = 1;
                }
            }
            else if(key_buffer == UP_KEY)
            {
                key_buffer = 0;
                cMenu[cProcedure]++;                                            // Change the Number in the buffer
                if(cMenu[cProcedure] > cMenuLimNo[cProcedure])
                {
                    cMenu[cProcedure] = 0;                                      // If it wasn't for Hidden_Key, Value of cMenu[cProcedure] is Zero.
                }
            }
            else if(key_buffer == DOWN_KEY)
            {
                key_buffer = 0;
                cMenu[cProcedure]--;
                if(cMenu[cProcedure] < 0)                                       // if it wasn't for Hidden_Key -> cMenu[cProcedure] < 0.
                {
                    cMenu[cProcedure] = cMenuLimNo[cProcedure];
                }
            }

            if(cProcedure == 1)
            {
                if(cMenu[cProcedure] == 0)                                      // PD: PARAMETERS Define (d: 0x5e)
                {
                    uModeBuffer[1] = 0x5e;
                }
                else if(cMenu[cProcedure] == 1)                                 // PC: Parameters Control (c: 0x39)
                {
                    uModeBuffer[1] = 0x39;
                }
                else if(cMenu[cProcedure] == 2)                                 // P1: Parameters Bank 1 (1: 0x06)
                {
                    uModeBuffer[1] = 0x06;
                }
                else if(cMenu[cProcedure] == 3)                                 // P2: Parameters Bank 2 (2: 0x5b)
                {
                    uModeBuffer[1] = 0x5b;
                }
            }
            else
            {
                uModeBuffer[cProcedure] = Fnd[cMenu[cProcedure]];               // ex: uModeBuffer[2] = fnd[cMenu[2]] -> uModeBuffer[2] = 2
                uModeNubBuffer[cProcedure] = cMenu[cProcedure];
            }

            break;

        //================================================================================================================//
        case  Define_Change:                                                    // Define_Change function
            if(key_buffer == SET_KEY)
            {
                key_buffer = 0;

                if(!((uSelectDefineNo == 0) && (uModeBuffer[1] == 0x5e)))      // The user have to reboot the drive(Except the PD000.)
                {
//                  M1_PWM_OFF;                                                 // M1 PWM OFF

                    if(uModeBuffer[1] == 0x5e)                                  // PD: PARAMETERS Define (d: 0x5e)
                    {
                        PD[uSelectDefineNo] = sDisplayValue;
                        PD_Save();
                    }
                    else if(uModeBuffer[1] == 0x39)                             // PC: Parameters Control (c: 0x39)
                    {
                        PC[uSelectDefineNo] = sDisplayValue;
                        PC_Save();
                    }
                    else if(uModeBuffer[1] == 0x06)                             // P1: Parameters Bank 1 (1: 0x06)
                    {
                        P1[uSelectDefineNo] = sDisplayValue;
                        P1_Save();
                    }
                    else if(uModeBuffer[1] == 0x5b)                             // P2: Parameters Bank 2 (2: 0x5b)
                    {
                        P2[uSelectDefineNo] = sDisplayValue;
                        P2_Save();
                    }
                }
                else
                {
                    PD[uSelectDefineNo] = sDisplayValue;

                    if(mSMDE_uFlagInverterOut == 0U)
                    {
                        PD_Save();
                    }
                }

                uMode = MENU_Main;
            }

            if(key_buffer == MODE_KEY)
            {
                key_buffer = 0;                                                 // change the position of the FND Buffer

                cProcedure_Change--;                                            // change FND buffer(1~4: except 0 buffer)
                if(cProcedure_Change < -1 * iDisplay_DP)
                    cProcedure_Change = -1 * iDisplay_DP + 4;
            }

            if(key_buffer == UP_KEY)
            {
                key_buffer = 0;
                sDisplayValue = sDisplayValue + pow(10, cProcedure_Change);
            }

            if(key_buffer == DOWN_KEY)
            {
                key_buffer = 0;
                sDisplayValue = sDisplayValue - pow(10, cProcedure_Change);
            }

            // ============================================== Variable Limit ===================================================== //
            if(uModeBuffer[1] == 0x5e)                                          // PD: PARAMETERS Define (d: 0x5e)
            {
                sDisplayValue = BOUND(sDisplayValue, PD_LIMIT[uSelectDefineNo], 0);
            }
            else if(uModeBuffer[1] == 0x39)                                     // PC: Parameters Control (c: 0x39)
            {
                sDisplayValue = BOUND(sDisplayValue, PC_LIMIT[uSelectDefineNo], 0);
            }
            else if(uModeBuffer[1] == 0x06)                                     // P1: Parameters Bank 1 (1: 0x06)
            {
                sDisplayValue = BOUND(sDisplayValue, P1_LIMIT[uSelectDefineNo], 0);
            }
            else if(uModeBuffer[1] == 0x5b)                                     // P2: Parameters Bank 2 (2: 0x5b)
            {
                sDisplayValue = BOUND(sDisplayValue, P2_LIMIT[uSelectDefineNo], 0);
            }
            // ==================================================================================================================== //
            break;

        //================================================================================================================//
        case Auto_Align:

//            IO_INPUT.bit.EMG = 1;
//            Fault_M1.bit.Align = 0;
//            TIM1_Cont.Flag.all = 0;

                                                                            //   M  U  D  S
            if(key_buffer == UP_SET_KEY)                                    // [ □  ■  □  ■ ] / Flag_Inverter
            {
//                Flag_Inverter_M1 = 1;
            }
                                                                            //   M  U  D  S
            if((key_buffer == DOWN_SET_KEY)||(key_buffer == UP_SET_KEY))    // [ □  □  ■  ■ ] [ □  ■  □  ■ ] / e-Stop
            {
//                ForcedEstop = 1;
//                Flag_Inverter_M1 = 0;
            }

//            if(Flag_Inverter_M1 == 1)
//            {
//                PD[19] = Theta_M1.offset;
//            }
                                                                            //   M  U  D  S
            if(key_buffer == SET_KEY)                                       // [ □  □  □  ■ ] / Set key는 무시
            {
                key_buffer = 0;
            }
                                                                            //   M  U  D  S
            if(key_buffer == UP_DOUN_KEY)                                   // [ □  ■  ■  □ ]  / 설정 완료
            {
                key_buffer = 0;

                PD_Save();                                                  // Align 모드에서는 현재 theta 값을 저장

//                TIM1_Cont.Flag.all = 16;
//                VFM1_Cont.Flag.all = 0;
//                VFM1_Cont.Vout = 0;
//                Flag_Inverter_M1 = 0;

                uMode = MENU_Main;
            }
            break;

        default:
            uMode = MENU_Main;

            break;
    }

    return;
}
