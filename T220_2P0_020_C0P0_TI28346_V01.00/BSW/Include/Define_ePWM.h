/*
 * Define_ePWM.h
 *
 * C/C++ source code generated on : Thu Jan 11 10:09:04 2024
 * Created by: System Research Team
 * Code generated on : Sat Mar 15 00:16:24 2025
 *
 */

#ifndef DEFINE_EPWM_H_
#define DEFINE_EPWM_H_

#ifdef __cplusplus
extern "C" {
#endif

// Emulation Mode
#define EMUMODE_FREE						0x2			// Free Run
#define EMUMODE_SOFT						0x1			// Stop when Counter Complete a Whole Cycle
#define EMUMODE_HARD						0x0			// Stop after the next time-base counter direction changed.

// Time-Base Clock Pre-scare							// TBCLK = SYSCLKOUT/(HSPCLKDIV x CLKDIV)
#define TB_DIV1								0x0
#define TB_DIV2								0x1
#define TB_DIV4								0x2
#define TB_DIV8								0x3
#define TB_DIV16							0x4
#define TB_DIV32							0x5
#define TB_DIV64							0x6
#define TB_DIV128							0x7

// High Speed Time-Base Clock Pre-scare
#define TB_HSPDIV1							0x0
#define TB_HSPDIV2							0x1
#define TB_HSPDIV4							0x2
#define TB_HSPDIV6							0x3
#define TB_HSPDIV8							0x4
#define TB_HSPDIV10							0x5
#define TB_HSPDIV12							0x6
#define TB_HSPDIV14							0x7

// Counter Mode
#define TB_COUNT_UP							0x0
#define TB_COUNT_DOWN						0x1
#define TB_COUNT_UPDOWN						0x2
#define TB_COUNT_DISABLE					0x3

// Period Register Shadow Register Enable
#define TB_SHADOW							0x0
#define TB_IMMEDIATE						0x1

// Phase Register Enable
#define TB_DISABLE							0x0
#define TB_ENABLE							0x1

// Synchronization Output Select.
#define TB_SYNC_IN							0x0
#define TB_CTR_ZERO							0x1
#define TB_CTR_CMPB							0x2
#define TB_SYNC_DISABLE						0x3

// Phase Direction Bit
#define TB_DOWN								0x0			// Count Down after the Synchronization event.
#define TB_UP								0x1			// Count Up after the Synchronization event.

// Compare A/B Register Shadow Register Enable
#define CC_SHADOW							0x0
#define CC_IMMEDIATE						0x1

// Comapre A/B Register Load Mode
#define CC_CTR_ZERO							0x0
#define CC_CTR_PRD							0x1
#define CC_CTR_ZERO_PRD						0x2
#define CC_CTR_DISABLE						0x3

// Action Qualifier
#define AQ_NO_ACTION						0x0
#define AQ_CLEAR							0x1
#define AQ_SET								0x2
#define AQ_TOGGLE							0x3

// Dead Band In Mode
#define DBA_ALL								0x0
#define DBB_RED_DBA_FED						0x1
#define DBA_RED_DBB_FED						0x2
#define DBB_ALL								0x3

// Dead Band Polarity Selection
#define DB_ACTV_HI							0x0			// Active High and Identically
#define DB_ACTV_LOC							0x1			// Active Low and Complementary
#define DB_ACTV_HIC							0x2			// Active High and Complementary
#define DB_ACTB_LO							0x3			// Active Low and Identically

// Dead Band Output Mode
#define	DB_DISABLE							0x0
#define	DBA_ENABLE							0x1
#define	DBB_ENABLE							0x2
#define DB_FULL_ENABLE						0x3

// Event Trigger Select
#define	ET_CTR_ZERO							0x1
#define	ET_CTR_PRD							0x2
#define	ET_CTRU_CMPA						0x4
#define	ET_CTRD_CMPA						0x5
#define	ET_CTRU_CMPB						0x6
#define	ET_CTRD_CMPB						0x7

// Event Trigger Pre-scaler
#define	ET_DISABLE							0x0
#define	ET_1ST								0x1
#define	ET_2ND								0x2
#define	ET_3RD								0x3

// Event Trigger Interrupt Enable
#define ET_DISABLE							0x0
#define ET_ENABLE							0x1

//
#define TB_BPHS_0DELAY						0x0000;
#define TB_BPHS_1DELAY						0x0002;
#define TB_BPHS_2DELAY						0x0004;
#define TB_BPHS_3DELAY						0x0006;

#ifdef __cplusplus
}
#endif /* extern "C" */


#endif /* DEFINE_EPWM_H_ */
