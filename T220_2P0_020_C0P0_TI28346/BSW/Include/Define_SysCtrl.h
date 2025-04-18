/*
 * Define_PLL.h
 *
 * C/C++ source code generated on : Thu Jan 11 10:09:04 2024
 * Created by: System Research Team
 * Code generated on : Sat Mar 15 00:16:24 2025
 *
 */

#ifndef DEFINE_PLL_H_
#define DEFINE_PLL_H_


#ifdef __cplusplus
extern "C" {
#endif

// SYSCLKOUT = CLKIN * (PLLCR+1)/DIVSEL
// 300[MHz] = 20[MHz] x30 /2
#define DSP28_DIVSEL			2				// 0(/8), 1(/4), 2(/2), 3(/1)
#define DSP28_PLLCR				29				// 0(x1), 1(x2), 2(x3), 3(x4), ..., 29(x30)

// CPU Clock Period
// 3.333333333[ns] (=300[MHz])
#define CPU_RATE				3.333333333L

// Target Device determines CPU frequency
#if (DSP28_28346||DSP28_28344||DSP28_28342)		// DSP28_28346||DSP28_28344||DSP28_28342
	#define CPU_FRQ_200MHZ		0				// 300 Mhz CPU Freq (20 MHz input freq)
	#define CPU_FRQ_250MHZ		0
	#define CPU_FRQ_300MHZ		1
#elif (DSP28_28345||DSP28_28343||DSP28_28341)	// DSP28_28345||DSP28_28343||DSP28_28341
	#define CPU_FRQ_200MHZ		1
	#define CPU_FRQ_250MHZ		0				// 200 MHz CPU Freq (20 MHz input freq)
	#define CPU_FRQ_300MHZ		0
#else											// DSP28_2834F device only
	#define CPU_FRQ_200MHZ		0
	#define CPU_FRQ_250MHZ		1
	#define CPU_FRQ_300MHZ		0				// 250 MHz CPU Freq (20 MHz input freq)
#endif

// Time Delay Function
#define DELAY_US(A)  DSP28x_usDelay(((((long double) A * 1000.0L) / (long double)CPU_RATE) - 9.0L) / 5.0L)

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* DEFINE_PLL_H_ */
