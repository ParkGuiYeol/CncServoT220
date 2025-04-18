/*
 *	GPIO.c
 *
 * C/C++ source code generated on : Thu Jan 11 10:09:04 2024
 * Created by: System Research Team
 * Code generated on : Sat Mar 15 00:16:24 2025
 *
 */

#include "Define_Header.h"

void Init_GPIO(void)
{
	EALLOW;

	//-------------------------------------------------------------------------------------------------//
	//-------------------------------------------- GPIOA-1 --------------------------------------------//
	//-------------------------------------------------------------------------------------------------//
	// GPIOA-1 MUX
	GpioCtrlRegs.GPAMUX1.all = 0x00881555;  // GPIOA-1 MUX1
	GpioCtrlRegs.GPAMUX2.all = 0x52004555;	// GPIOA-2 MUX2
	GpioCtrlRegs.GPADIR.all = 0xBF4097FF;	// GPIOA Input/Output of GPIO			; 0(Input), 1(Output)
	GpioCtrlRegs.GPACTRL.all = 0x00000000;	// GPIOA Sampling Frequency of GPIO		; SAMPCLK = SYSCLKOUT/(2 x QUALPRDn): 0(/1), 1(/2), 2(/4), ..., 255(/510)
	GpioCtrlRegs.GPAQSEL2.all = 0xFC000000;
	GpioCtrlRegs.GPAQSEL1.all = 0x3C000000;	// GPIOA Qualification Mode				; ACQCLK = SAMPCLK/GPAQSELn			: 0(/1), 1(/2), 2(/5), 3(ASYNCH)
	GpioCtrlRegs.GPAPUD.all = 0xFF4FFFFF;	// GPIOA Internal Pull-up				; 0(Enable), 1(Disable)
	GpioDataRegs.GPACLEAR.all = 0xE3400FC0;	// GPIOA Initial Value of GPIOx Output	; 1(Clear)
	GpioDataRegs.GPASET.all = 0x1C009000;	// GPIOA Initial Value of GPIOx Output	; 1(Set)

	/******************************************************************** GPIOA MUX2 ********************************************************************/
	// GPIO31					01					0(GPIO31), 			1(CANTXA[O]),		2(XA17[O]),			3(XA17[O])			¡æ CANTXA
	// GPIO30					01					0(GPIO30), 			1(CANRXA[I]),		2(XA18[O]),			3(XA18[O])			¡æ CANRXA

	// GPIO29					00					0(GPIO29), 			1(SCITXDA[O]),		2(XA19[O]), 		3(XA19[O])			¡æ DO
	// GPIO28					10					0(GPIO28), 			1(SCIRXDA[I]),		2(XZCS6[O]), 		3(XZCS6[O])			¡æ XCS6

	// GPIO27					00					0(GPIO27), 			1(ECAP4[I/O]),		2(EQEP2S[I/O]),		3(MFSXB[I/O])		¡æ /EPWM_EN
	// GPIO26					00					0(GPIO26), 			1(ECAP3[I/O]),		2(EQEP2I[I/O]), 	3(MCLKXB[I/O])		¡æ BRAKE_CHOPPER_ON

	// GPIO25					00					0(GPIO25), 			1(ECAP2[I/O]),		2(EQEP2B[I]),		3(MDRB[I])			¡æ ALARM_LED
	// GPIO24					00					0(GPIO24), 			1(ECAP1[I/O]),		2(EQEP2A[I]), 		3(MDXB[O])			¡æ DC_RELAY_SIG

	// GPIO23					01					0(GPIO23), 			1(EQEP1I[I/O]),		2(MFSXA[I/O]),		3(SCIRXDB[I])		¡æ ENC-C_DSP
	// GPIO22					00					0(GPIO22), 			1(EQEP1S[I/O]),		2(MCLKXA[I/O]),		3(SCITXDB[O])		¡æ DO

	// GPIO21					01					0(GPIO21), 			1(EQEP1B[I]),		2(MDRA[I]),			3(CANRXB[I])		¡æ ENC-B_DSP
	// GPIO20					01					0(GPIO20), 			1(EQEP1A[I]),		2(MDXA[O]), 		3(CANTXB[O])		¡æ ENC-A_DSP

	// GPIO19					01					0(GPIO19), 			1(SPISTEA[I/O]),	2(SCIRXDB[I]),		3(CANTXA[O])		¡æ SPISTEA(Flash ROM)
	// GPIO18					01					0(GPIO18), 			1(SPICLKA[I/O]),	2(SCITXDB[O]), 		3(CANRXA[I])		¡æ SPICLKA(Flash ROM)

	// GPIO17					01					0(GPIO17), 			1(SPISOMIA[I/O]),	2(CANRXB[I]),		3(TZ6[I])			¡æ SPISOMIA(Flash ROM)
	// GPIO16					01					0(GPIO16), 			1(SPISMOA[I/O]),	2(CANTXB[O]),		3(TZ5[I])			¡æ SPISMOA(Flash ROM)

	/******************************************************************** GPIOA MUX1 *********************************************************************/
	// GPIO15					00					0(GPIO15),			1(TZ4/XHOLDA[I]),	2(SCIRXDB[I]),		3(MFSXB[I/O])		¡æ FPGA_RESET
	// GPIO14					00					0(GPIO14),			1(TZ3/XHOLD[I]),	2(SCIRXDB[O]),		3(MCLKXB[I/O])		¡æ BRAKE_CHOPPER_CHECK

	// GPIO13					00					0(GPIO13),			1(TZ2[I]), 			2(CANRXB[I]), 		3(MDRB[O])			¡æ /TZ_IGBT_FAULT
	// GPIO12					00					0(GPIO12),			1(TZ1[I]), 			2(CANTXB[O]), 		3(MDXB[O])			¡æ /ADC_CV

	// GPIO11					10					0(GPIO11),			1(EPWM6B[O]), 		2(SCIRXDB[I]),		3(ECAP4[I/O])		¡æ RS485_RXD_DSP
	// GPIO10					00					0(GPIO10),			1(EPWM6A[O]), 		2(CANRXB[I]), 		3(ADCSOCBO[O])		¡æ RS485_DIR_DSP

	// GPIO9					10					0(GPIO9),			1(EPWM5B[O]), 		2(SCITXDB[O]),		3(ECAP3[I/O])		¡æ RS485_TXD_DSP
	// GPIO8					00					0(GPIO8),			1(EPWM5A[O]), 		2(CANTXB[O]), 		3(ADCSOCAO[O])		¡æ FND_DIG1

	// GPIO7					00					0(GPIO7),			1(EPWM4B[O]), 		2(MCLKRA[I/O]),		3(ECAP2[I/O])		¡æ FND_DIG0
	// GPIO6					01					0(GPIO6),			1(EPWM4A[O]), 		2(EPWMSYNCI[I]),	3(EPWMSYNCO[O])		¡æ ADS7865I_CLK

	// GPIO5					01					0(GPIO5),			1(EPWM3B[O]), 		2(MFSRA[I/O]),		3(ECAP1[I/O])		¡æ EPWM3B
	// GPIO4					01					0(GPIO4),			1(EPWM3A[O]), 		2(Reserved), 		3(Reserved)			¡æ EPWM3A

	// GPIO3					01					0(GPIO3),			1(EPWM2B[O]), 		2(ECAP5[I/O]),		3(MCLKRB[I/O])		¡æ EPWM2B
	// GPIO2					01					0(GPIO2),			1(EPWM2A[O]), 		2(Reserved), 		3(Reserved)			¡æ EPWM2A

	// GPIO1					01					0(GPIO1),			1(EPWM1B[O]),		2(ECAP6[I/O]),		3(MFSRB[I/O])		¡æ EPWM1B
	// GPIO0					01					0(GPIO0),			1(EPWM1A[O]),		2(Reserved),		3(Reserved)			¡æ EPWM1A

	/******************************************************************* GPIOA ETC. **********************************************************************/
	// 	Pin	Name				DIR[0(In), 1(out)]	ACTRL[0 ~ 255]		QSEL[0, 1, 2, 3]	PUD[0(En), 1(DIS)]	CLEAR[1(Clear)]		SET[1(Set)]
	//	31	CANTXA  			1					0					11					1					1					0
	//	30	CANRXA		        0					0					11					1					1					0
	//	29	DO		            1					0					11					1					1					0
	//	28	XCS6				1					0					00					1					0					1

	//	27	/EPWM_EN			1					0					00					1					0					1
	//	26	/BRAKE_CHOPPER_ON	1					0					00					1					0					1
	//	25	ALARM_LED   		1					0					00					1					1					0
	//	24	DC_RELAY_SIG		1					0					00					1					1					0

	//	23	ENC-C_DSP			0					0					00					0					0					0
	//	22	DO					1					0					00					1					1					0
	//	21	ENC-B_DSP			0					0					00					0					0					0
	//	20	ENC-A_DSP			0					0					00					0					0					0

	//	19	SPISTEA(Flash ROM)	0					0					00					1					0					0
	//	18	SPICLKA(Flash ROM)	0					0					00					1					0					0
	//	17	SPISOMIA(Flash ROM)	0					0					00					1					0					0
	//	16	SPISMOA(Flash ROM)	0					0					00					1					0					0

	//	15	FPGA_RESET			1					0					00					1					0					1
	//	14	BRAKE_CHOPPER_CHECK	0					0					11					1					0					0
	//	13	/TZ_IGBT_FAULT		0					0					11					1					0					0
	//	12	/ADC_CV				1					0					00					1					0					1

	//	11	RS485_RXD_DSP		0					0					00					1					1					0
	//	10	RS485_DIR_DSP		1					0					00					1					1					0
	//	09	RS485_TXD_DSP		1					0					00					1					1					0
	//	08	FND_DIG1			1					0					00					1					1					0

	//	07	FND_DIG0			1					0					00					1					1					0
	//	06	ADS7865I_CLK		1					0					00					1					1					0
	//	05	EPWM3B				1					0					00					1					0					0
	//	04	EPWM3A				1					0					00					1					0					0

	//	03	EPWM2B				1					0					00					1					0					0
	//	02	EPWM2A				1					0					00					1					0					0
	//	01	EPWM1B				1					0					00					1					0					0
	//	00	EPWM1A				1					0					00					1					0					0
	/****************************************************************************************************************************************************/

	//-------------------------------------------------------------------------------------------------//
	//-------------------------------------------- GPIOB-1 --------------------------------------------//
	//-------------------------------------------------------------------------------------------------//
	GpioCtrlRegs.GPBMUX1.all = 0xFFFFF305;
	GpioCtrlRegs.GPBMUX2.all = 0x00000000;
	GpioCtrlRegs.GPBDIR.all = 0xFF0B003C;		// GPIOB Input/Output of GPIO			; 0(Input), 1(Output)
	GpioCtrlRegs.GPBCTRL.all = 0x00000000;		// GPIOB Sampling Frequency of GPIO		; SAMPCLK = SYSCLKOUT/(2 x QUALPRDn): 0(/1), 1(/2), 2(/4), ..., 255(/510)
	GpioCtrlRegs.GPBQSEL1.all = 0x0000FF30;
	GpioCtrlRegs.GPBQSEL2.all = 0x00000000;		// GPIOB Qualification Mode				; ACQCLK = SAMPCLK/GPAQSELn			: 0(/1), 1(/2), 2(/5), 3(ASYNCH)
	GpioCtrlRegs.GPBPUD.all = 0xFFFFFFFF;		// GPIOB Internal Pull-up				; 0(Enable), 1(Disable)
	GpioDataRegs.GPBCLEAR.all = 0x000B002C;		// GPIOB Initial Value of GPIOx Output	; 1(Clear)
	GpioDataRegs.GPBSET.all = 0xFF000010;		// GPIOB Initial Value of GPIOx Output	; 1(Set)

	/******************************************************************** GPIOB MUX2 ******************************************************************/
	// GPIO63					00					0(GPIO63), 			1(SCITXDC[O]),		2(XD16[I/O]),		3(EPWM9A[O])		FND_D7
	// GPIO62					00					0(GPIO62), 			1(SCIRXDC[I]),		2(XD17[I/O]),		3(EPWM9A[O])		FND_D6

	// GPIO61					00					0(GPIO61), 			1(MFSRB[I/O]),		2(XD18[I/O]), 		3(EPWM8B[O])		FND_D5
	// GPIO60					00					0(GPIO60), 			1(MCLKRB[I/O]),		2(XD19[I/O]), 		3(EPWM8A[O])		FND_D4

	// GPIO59					00					0(GPIO59), 			1(MFSRA[I/O]),		2(XD20[I/O]),		3(EPWM7B[O])		FND_D3
	// GPIO58					00					0(GPIO58), 			1(MCLKRA[I/O]),		2(XD21[I/O]), 		3(EPWM7A[O])		FND_D2

	// GPIO57					00					0(GPIO57), 			1(SPISTEA[I/O]),	2(XD22[I/O]),		3(EQEP3I[I/O])		FND_D1
	// GPIO56					00					0(GPIO56), 			1(SPICLKA[I/O]),	2(XD23[I/O]),		3(EQEP3S[I/O])		FND_D0

	// GPIO55					00					0(GPIO55), 			1(SPISOMIA[I/O]),	2(XD24[I/O]),		3(EQEP3B[I])		DSP_SET_KEY
	// GPIO54					00					0(GPIO54), 			1(SPISIMOA[I/O]),	2(XD25[I/O]),		3(EQEP3A[I])		DSP_DOWN_KEY

	// GPIO53					00					0(GPIO53), 			1(EPQE1I[I/O]),		2(XD26[I/O]),		3(Reserved)			DSP_UP_KEY
	// GPIO52					00					0(GPIO52), 			1(EQEP1S[I/O]),		2(XD27[I/O]), 		3(Reserved)			DSP_MODE_KEY

	// GPIO51					00					0(GPIO51), 			1(EQEP1B[I]),		2(XD28[I/O]),		3(SPISTED[I/O])		FANOUT_SIG
	// GPIO50					00					0(GPIO50), 			1(EQEP1A[I]),		2(XD29[I/O]), 		3(SPICLKD[I/O])		L1_LINE_CHECK

	// GPIO49					00					0(GPIO49), 			1(ECAP6[I/O]),		2(XD30[I/O]),		3(SPISOMID[I/O])	D/F_SIGNAL_2
	// GPIO48					00					0(GPIO48), 			1(ECAP5[I/O]),		2(XD31[I/O]),		3(SPISIMOD[I/O])	D/F_SIGNAL_1
	/******************************************************************** GPIOB MUX1 *****************************************************************/
	// GPIO47					11					0(GPIO47), 			1(Reserved),		2(XA7[O]),			3(XA7[O])			ADDR7
	// GPIO46					11					0(GPIO46), 			1(Reserved),		2(XA6[O]),			3(XA6[O])			ADDR6

	// GPIO45					11					0(GPIO45), 			1(Reserved),		2(XA5[O]),			3(XA5[O])			ADDR5
	// GPIO44					11					0(GPIO44), 			1(Reserved),		2(XA4[O]),			3(XA4[O])			ADDR4

	// GPIO43					11					0(GPIO43), 			1(Reserved),		2(XA3[O]),			3(XA3[O])			ADDR3
	// GPIO42					11					0(GPIO42), 			1(Reserved),		2(XA2[O]),			3(XA2[O])			ADDR2

	// GPIO41 					11					0(GPIO41), 			1(Reserved),		2(XA1[O]),			3(XA1[O])			ADDR1
	// GPIO40					11					0(GPIO40), 			1(Reserved),		2(XA0/XWE1[O]),		3(XA0/XWE1[O])		ADDR0

	// GPIO39					11					0(GPIO39), 			1(Reserved),		2(XA16[O]),			3(XA16[O])			ADDR16
	// GPIO38					11					0(GPIO38), 			1(Reserved),		2(/XWE0[O]),		3(/XWE0[O])			XWR(/XWE0)

	// GPIO37					00					0(GPIO37), 			1(ECAP2[I/O]),		2(/XZCS7[O]),		3(/XZCS7[O])		FND_DIG5
	// GPIO36					11					0(GPIO36), 			1(SCIRXDA[I]),		2(/XZCS0[O]),		3(/XZCS0[O])		XCS0

	// GPIO35					00					0(GPIO35), 			1(SCITXDA[O]),		2(XR/W[O]),			3(XR/W[O])			FND_DIG4
	// GPIO34					00					0(GPIO34), 			1(ECAP1[I/O]),		2(XREADY[I]),		3(XREADY[I])		FND_DIG3

	// GPIO33					01					0(GPIO33), 			1(SCLA[I/OC]),		2(EPWMSYNCO[O]),	3(/ADCSOCB0[O])		SCLA(I2C_CLA)
	// GPIO32					01					0(GPIO32), 			1(SDAA[I/OC]),		2(EPWMSYNCI[I]),	3(/ADCSOCA0[O])		SDAA(I2C_SDA)

	/******************************************************************* GPIOB ETC. *****************************************************************/
	// 	Pin	Name				DIR[0(In), 1(out)]	ACTRL[0 ~ 255]		QSEL[0, 1, 2, 3]	PUD[0(En), 1(DIS)]	CLEAR[1(Clear)]		SET[1(Set)]
	//	63	FND_D7				1					0					00					1					0					1
	//	62	FND_D6				1					0					00					1					0					1
	//	61	FND_D5				1					0					00					1					0					1
	//	60	FND_D4				1					0					00					1					0					1

	//	59	FND_D3				1					0					00					1					0					1
	//	58	FND_D2				1					0					00					1					0					1
	//	57	FND_D1				1					0					00					1					0					1
	//	56	FND_D0				1					0					00					1					0					1

	//	55	DSP_SET_KEY			0					0					11					1					0					0
	//	54	DSP_DOWN_KEY		0					0					11					1					0					0
	//	53	DSP_UP_KEY			0					0					11					1					0					0
	//	52	DSP_MODE_KEY		0					0					11					1					0					0

	//	51	FANOUT_SIG  		1                   0                   00                  1                   1                   0
	//	50	L1_LINE_CHECK		0					0					11					1					0					0
	//	49	D/F_SIGNAL_2		1					0					00					1					1					0
	//	48	D/F_SIGNAL_1		1					0					00					1					1					0

	//	47	ADDR7				0					0					00					1					0					0
	//	46	ADDR6				0					0					00					1					0					0
	//	45	ADDR5				0					0					00					1					0					0
	//	44	ADDR4				0					0					00					1					0					0

	//	43	ADDR3				0					0					00					1					0					0
	//	42	ADDR2				0					0					00					1					0					0
	//	41	ADDR1				0					0					00					1					0					0
	//	40	ADDR0				0					0					00					1					0					0

	//	39	ADDR16				0					0					00					1					0					0
	//	38	XWR(/XWE0)			0					0					00					1					0					0
	//	37	FND_DIG5    		1					0					00					1					1					0
	//	36	XCS0				1					0					00					1					0					1

	//	35	FND_DIG4			1					0					00					1					1					0
	//	34	FND_DIG3			1					0					00					1					1					0
	//	33	SCLA(I2C_CLA)		0					0					00					1					0					0
	//	32	SDAA(I2C_SDA)		0					0					00					1					0					0

	//------------------------------------------------------------------------------------------------------------------------------------------------//
	//----------------------------------------------------------------  GPIOB  -----------------------------------------------------------------------//
	//------------------------------------------------------------------------------------------------------------------------------------------------//
	GpioCtrlRegs.GPCMUX1.all = 0xFFFFFFFF;
	GpioCtrlRegs.GPCMUX2.all = 0x000000FF;
	GpioCtrlRegs.GPCDIR.all =  0x00000000;		// GPIOC Input/Output of GPIO			; 0(Input), 1(Output)
	GpioCtrlRegs.GPCPUD.all = 0x00FFFFFF;		// GPIOC Internal Pull-up				; 0(Enable), 1(Disable)
	GpioDataRegs.GPCCLEAR.all = 0x00000000;	// GPIOC Initial Value of GPIOx Output	; 1(Clear)
	GpioDataRegs.GPCSET.all = 0x00000000;		// GPIOC Initial Value of GPIOx Output	; 1(Set)
	/******************************************************************** GPIOC MUX2 *****************************************************************/
	// GPIO87					00					0(GPIO87),			1(GPIO87),			2(XA15[I/O]),		3(XA15[I/O])		GPIO87(BOOT_SEL4)
	// GPIO86					00					0(GPIO86),			1(GPIO86),			2(XA14[I/O]),		3(XA14[I/O])		GPIO86(BOOT_SEL3)

	// GPIO85					00					0(GPIO85),			1(GPIO85),			2(XA13[I/O]),		3(XA13[I/O])		GPIO85(BOOT_SEL2)
	// GPIO84					00					0(GPIO84),			1(GPIO84),			2(XA12[I/O]),		3(XA12[I/O])		GPIO84(BOOT_SEL1)

	// GPIO83					11					0(GPIO83),			1(GPIO83),			2(XA11[I/O]),		3(XA11[I/O])		ADDR11
	// GPIO82					11					0(GPIO82),			1(GPIO82),			2(XA10[I/O]),		3(XA10[I/O])		ADDR10

	// GPIO81					11					0(GPIO81),			1(GPIO81),			2(XA9[I/O]),		3(XA9[I/O])			ADDR9
	// GPIO80					11					0(GPIO80),			1(GPIO80),			2(XA8[I/O]),		3(XA8[I/O])			ADDR8

	/******************************************************************** GPIOC MUX1 *****************************************************************/
	// GPIO79					11					0(GPIO79),			1(GPIO79),			2(XD0[I/O]),		3(XD0[I/O])			XD0
	// GPIO78					11					0(GPIO78),			1(GPIO78),			2(XD1[I/O]),		3(XD1[I/O])			XD1

	// GPIO77					11					0(GPIO77),			1(GPIO77),			2(XD2[I/O]),		3(XD2[I/O])			XD2
	// GPIO76					11					0(GPIO76),			1(GPIO76),			2(XD3[I/O]),		3(XD3[I/O])			XD3

	// GPIO75					11					0(GPIO75),			1(GPIO75),			2(XD4[I/O]),		3(XD4[I/O])			XD4
	// GPIO74					11					0(GPIO74),			1(GPIO74),			2(XD5[I/O]),		3(XD5[I/O])			XD5

	// GPIO73					11					0(GPIO73),			1(GPIO73),			2(XD6[I/O]),		3(XD6[I/O])			XD6
	// GPIO72					11					0(GPIO72),			1(GPIO72),			2(XD7[I/O]),		3(XD7[I/O])			XD7

	// GPIO71					11					0(GPIO71),			1(GPIO71),			2(XD8[I/O]),		3(XD8[I/O])			XD8
	// GPIO70					11					0(GPIO70),			1(GPIO70),			2(XD9[I/O]),		3(XD9[I/O])			XD9

	// GPIO69					11					0(GPIO69),			1(GPIO69),			2(XD10[I/O]),		3(XD10[I/O])		XD10
	// GPIO68					11					0(GPIO68),			1(GPIO68),			2(XD11[I/O]),		3(XD11[I/O])		XD11

	// GPIO67					11					0(GPIO67),			1(GPIO67),			2(XD12[I/O]),		3(XD12[I/O])		XD12
	// GPIO66					11					0(GPIO66),			1(GPIO66),			2(XD13[I/O]),		3(XD13[I/O])		XD13

	// GPIO65					11					0(GPIO65),			1(GPIO65),			2(XD14[I/O]),		3(XD14[I/O])		XD14
	// GPIO64					11					0(GPIO64),			1(GPIO64),			2(XD15[I/O]),		3(XD15[I/O])		XD15

	/******************************************************************* GPIOC ETC. *****************************************************************/
	// 	Pin	Name				DIR[0(In), 1(out)]											PUD[0(En), 1(DIS)]	CLEAR[1(Clear)]		SET[1(Set)]
	//	87	ADDR15				0															1					0					0
	//	86	ADDR14				0															1					0					0
	//	85	ADDR13				0															1					0					0
	//	84	ADDR12				0															1					0					0

	//	83	ADDR11				0															1					0					0
	//	82	ADDR10				0															1					0					0
	//	81	ADDR9				0															1					0					0
	//	80	ADDR8				0															1					0					0

	//	79	DATA_0				0															1					0					0
	//	78	DATA_1				0															1					0					0
	//	77	DATA_2				0															1					0					0
	//	76	DATA_3				0															1					0					0

	//	75	DATA_4				0															1					0					0
	//	74	DATA_5				0															1					0					0
	//	73	DATA_6				0															1					0					0
	//	72	DATA_7				0															1					0					0

	//	71	DATA_8				0															1					0					0
	//	70	DATA_9				0															1					0					0
	//	69	DATA_10				0															1					0					0
	//	68	DATA_11				0															1					0					0

	//	67	DATA_12				0															1					0					0
	//	66	DATA_13				0															1					0					0
	//	65	DATA_14				0															1					0					0
	//	64	DATA_15				0															1					0					0

	EDIS;
}
