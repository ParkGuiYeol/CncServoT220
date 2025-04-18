/*
 *  main.c
 *
 * C/C++ source code generated on : Thu Jan 11 10:09:04 2024
 * Created by: System Research Team
 * Code generated on : Sat Mar 15 00:16:24 2025
 *
 */

#include "Define_Header.h"
#include "D01_DRV_CAN.h"
#include "D09_DRV_TMR.h"
#include "D02_DRV_I2C.h"
#include "Define_DAC.h"
#include "b01_OSnScheduler.h"
#include "c01_MainAdc.h"
#include "c02_SubAdc.h"
#include "d01_Diaglnteg.h"
#include "e01_MtrCtrl_VarGain.h"
#include "e02_MtrCtrl_Pst.h"
#include "e03_MtrCtrl_MtrCtrl.h"
#include "e04_MtrCtrl_PwmSet.h"
#include "f01_CommRx1.h"
#include "g03_CommTx.h"
#include "h01_MdeMgmt.h"
#include "j01_McuInit.h"

static void Asw_1ms_Task(void);

int32_T mBSW_i32Cnt_CanTxTimer;

void main(void)
{
 	DisableDog();				// Disable WatchDog.

	// Clock Initializing
	Init_PLL();					// PLL Initializing(300[MHz]).
	Init_PeripheralClocks();	// Peripheral Clock Enable/Disable.

	// Interrupt Initializing
	Init_PieCtrl();				// Interrupt Initializing.
	Init_PieVectTable();		// Interrupt Vector Table Initializing.

	// Pin Function Initializing;
	Init_GPIO();				// Pin Function Selection.

	// Each Part Initializing
	Init_I2C();					// I2C SERIAL EEPROM Initializing.
	Eep_Init();					// EEPROM Data Load.
	Init_Xintf();				// External Interface Initializing.
	Init_FPGA();				// FPGA Initializing.
	Init_PWM();					// PWM Initializing.
	Init_eCAN();                // CAN Initializing.
	Init_CPUTimers();			// CPU Timer0 Reset for WatchCAT.

    // Start Event
	Start_PieCtrl();			// Interrupt Enable Start.
    Start_PWM();                // PWM Time Base Start.
    Start_Timer();              // WatchCat Start.

    // MBD Software Component Initialization
    b01_OSnScheduler_initialize();
    c01_MainAdc_initialize();
    c02_SubAdc_initialize();
    d01_Diaglnteg_initialize();
    e01_MtrCtrl_VarGain_initialize();
    e02_MtrCtrl_Pst_initialize();
    e03_MtrCtrl_MtrCtrl_initialize();
    e04_MtrCtrl_PwmSet_initialize();
    f01_CommRx1_initialize();
    g03_CommTx_initialize();
    h01_MdeMgmt_initialize();
    j01_McuInit_initialize();

    // I/O Output Setting
	FAN_OFF;
	CHOPPER_OFF;
	DC_RELAY_OFF;
	IO_EN_ON;

	while(1)
	{
        if(mBSW_u1msFlag == 1U)
        {
            Asw_1ms_Task();
            mBSW_u1msFlag = 0U;
        }

        Bftn_ResetEncMultiTurn();
        Bftn_SaveOriginData();
	}
}

static void Asw_1ms_Task(void)
{
    mBSW_i32Cnt_CanTxTimer++;

    f01_CommRx1_step();
    g03_CommTx_step();

    switch (mBSW_i32Cnt_CanTxTimer)
    {
        case 0:
            CAN_HostTx(MB24);
            break;

        case 1:
            CAN_HostTx(MB25);
            break;

        case 2:

            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            if(DACS.CH1.Rng != 0)
            {
                DACS.CH1.INVRng = 1.0F / DACS.CH1.Rng;
            }
            break;

        case 6:
            if(DACS.CH2.Rng != 0)
            {
                DACS.CH2.INVRng = 1.0F / DACS.CH2.Rng;
            }
            break;

        case 7:
            if(DACS.CH3.Rng != 0)
            {
                DACS.CH3.INVRng = 1.0F / DACS.CH3.Rng;
            }
            break;

        case 8:
            if(DACS.CH4.Rng != 0)
            {
                DACS.CH4.INVRng = 1.0F / DACS.CH4.Rng;
            }
            break;

        case 9:
            mBSW_i32Cnt_CanTxTimer = -1;
          break;

        default:
            // No actions

          break;
    }
}

