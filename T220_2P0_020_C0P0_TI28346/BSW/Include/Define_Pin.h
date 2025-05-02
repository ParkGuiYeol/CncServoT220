/*
 *	Define_ADC.c
 *
 * C/C++ source code generated on : Thu Jan 11 10:09:04 2024
 * Created by: System Research Team
 * Code generated on : Sat Mar 15 00:16:24 2025
 *
 */

#ifndef DEFINE_ADC_H_
#define DEFINE_ADC_H_

#ifdef __cplusplus
extern "C" {
#endif

//#define ADC_RESOLUTION			4.8828125e-4F

//zone0
#define ADC_RD_ADDR					((volatile int *)(0x004000))
#define ADC_WR_ADDR					((volatile int *)(0x004000))

//zone6
#define FPGA_RD_ADDR				((volatile int *)(0x100000))
#define FPGA_WR_ADDR				((volatile int *)(0x100000))

/********************************** Pin Define ***********************************/
///// FAN /////
#define FAN_ON                      GpioDataRegs.GPBSET.bit.GPIO51 = 1
#define FAN_OFF                     GpioDataRegs.GPBCLEAR.bit.GPIO51 = 1

///// DC_RELAY_SIG /////
#define DC_RELAY_ON                 GpioDataRegs.GPASET.bit.GPIO24 = 1
#define DC_RELAY_OFF                GpioDataRegs.GPACLEAR.bit.GPIO24 = 1

///// Test Point /////
#define DO_ON                       GpioDataRegs.GPASET.bit.GPIO29 = 1
#define DO_OFF                      GpioDataRegs.GPACLEAR.bit.GPIO29 = 1

///// FPGA /////
#define FPGA_RESET_OFF				GpioDataRegs.GPASET.bit.GPIO15 = 1
#define FPGA_RESET_ON				GpioDataRegs.GPACLEAR.bit.GPIO15 = 1

///// CHOPPER /////
#define CHOPPER_OFF					GpioDataRegs.GPASET.bit.GPIO26 = 1
#define CHOPPER_ON					GpioDataRegs.GPACLEAR.bit.GPIO26 = 1

///// TP /////
#define IO_EN_OFF					GpioDataRegs.GPASET.bit.GPIO22 = 1
#define IO_EN_ON					GpioDataRegs.GPACLEAR.bit.GPIO22 = 1

///// PWM Set #1 /////
#define PWM1_ON						GpioDataRegs.GPACLEAR.bit.GPIO27 = 1
#define PWM1_OFF					GpioDataRegs.GPASET.bit.GPIO27 = 1

///// DSP -> FPGA Output Signal /////
#define M1_INT_ON					GpioDataRegs.GPBSET.bit.GPIO48 = 1
#define M1_INT_OFF					GpioDataRegs.GPBCLEAR.bit.GPIO48 = 1

#define M2_INT_ON					GpioDataRegs.GPBSET.bit.GPIO49 = 1
#define M2_INT_OFF					GpioDataRegs.GPBCLEAR.bit.GPIO49 = 1

///// Parallel ADC Conversion Start
#define ADC_CONVT_START_ON			GpioDataRegs.GPACLEAR.bit.GPIO12 = 1
#define ADC_CONVT_START_OFF			GpioDataRegs.GPASET.bit.GPIO12 = 1

///// Gate Drive Fault /////
#define mBSW_uGateFltDtc			GpioDataRegs.GPADAT.bit.GPIO13

//#define LED_ALRAM_OUT_OFF         GpioDataRegs.GPBSET.bit.GPIO34 = 1
//#define LED_ALRAM_OUT_ON          GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1

//#define LED_SERVO_ON_OFF          GpioDataRegs.GPBSET.bit.GPIO35 = 1
//#define LED_SERVO_ON_ON           GpioDataRegs.GPBCLEAR.bit.GPIO35 = 1

//#define LED_E_STOP_OFF            GpioDataRegs.GPBSET.bit.GPIO37 = 1
//#define LED_E_STOP_ON             GpioDataRegs.GPBCLEAR.bit.GPIO37 = 1

///// DC RELAY /////
//#define DC_RELAY_ON               GpioDataRegs.GPASET.bit.GPIO30 = 1
//#define DC_RELAY_OFF              GpioDataRegs.GPACLEAR.bit.GPIO30 = 1

///// E-STOP SWITHC /////
//#define E_STOP_SWITCH             GpioDataRegs.GPADAT.bit.GPIO25

//******************************************************************************** FND SCAN
#define FNDS0_OF                    GpioDataRegs.GPASET.bit.GPIO7 = 1
#define FNDS0_ON                    GpioDataRegs.GPACLEAR.bit.GPIO7 = 1

#define FNDS1_OF                    GpioDataRegs.GPASET.bit.GPIO8 = 1
#define FNDS1_ON                    GpioDataRegs.GPACLEAR.bit.GPIO8 = 1

#define FNDS2_OF                    GpioDataRegs.GPBSET.bit.GPIO34 = 1
#define FNDS2_ON                    GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1

#define FNDS3_OF                    GpioDataRegs.GPBSET.bit.GPIO35 = 1
#define FNDS3_ON                    GpioDataRegs.GPBCLEAR.bit.GPIO35 = 1

#define FNDS4_OF                    GpioDataRegs.GPBSET.bit.GPIO37 = 1
#define FNDS4_ON                    GpioDataRegs.GPBCLEAR.bit.GPIO37 = 1

//******************************************************************************** FND DATA
#define FNDD0_ON                    GpioDataRegs.GPBSET.bit.GPIO56 = 1
#define FNDD0_OF                    GpioDataRegs.GPBCLEAR.bit.GPIO56 = 1

#define FNDD1_ON                    GpioDataRegs.GPBSET.bit.GPIO57 = 1
#define FNDD1_OF                    GpioDataRegs.GPBCLEAR.bit.GPIO57 = 1

#define FNDD2_ON                    GpioDataRegs.GPBSET.bit.GPIO58 = 1
#define FNDD2_OF                    GpioDataRegs.GPBCLEAR.bit.GPIO58 = 1

#define FNDD3_ON                    GpioDataRegs.GPBSET.bit.GPIO59 = 1
#define FNDD3_OF                    GpioDataRegs.GPBCLEAR.bit.GPIO59 = 1

#define FNDD4_ON                    GpioDataRegs.GPBSET.bit.GPIO60 = 1
#define FNDD4_OF                    GpioDataRegs.GPBCLEAR.bit.GPIO60 = 1

#define FNDD5_ON                    GpioDataRegs.GPBSET.bit.GPIO61 = 1
#define FNDD5_OF                    GpioDataRegs.GPBCLEAR.bit.GPIO61 = 1

#define FNDD6_ON                    GpioDataRegs.GPBSET.bit.GPIO62 = 1
#define FNDD6_OF                    GpioDataRegs.GPBCLEAR.bit.GPIO62 = 1

#define FNDD7_ON                    GpioDataRegs.GPBSET.bit.GPIO63 = 1
#define FNDD7_OF                    GpioDataRegs.GPBCLEAR.bit.GPIO63 = 1

#ifdef __cplusplus
}
#endif


#endif /* DEFINE_ADC_H_ */
