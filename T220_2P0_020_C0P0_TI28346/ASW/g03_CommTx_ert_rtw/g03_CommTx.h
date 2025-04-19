/*
 * File: g03_CommTx.h
 *
 * Code generated for Simulink model 'g03_CommTx'.
 *
 * Model version                  : 7.370
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Apr 19 17:42:21 2025
 * Created by: System Research Team
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. Execution efficiency
 *    3. RAM efficiency
 *    4. ROM efficiency
 * Validation result: Not run
 */

#ifndef g03_CommTx_h_
#define g03_CommTx_h_
#ifndef g03_CommTx_COMMON_INCLUDES_
#define g03_CommTx_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* g03_CommTx_COMMON_INCLUDES_ */

#include <string.h>

/* Includes for objects with custom storage classes */
#include "M2_Interrupt.h"
#include "e03_MtrCtrl_MtrCtrl.h"
#include "d01_Diaglnteg.h"
#include "e02_MtrCtrl_Pst.h"
#include "c01_MainAdc.h"
#include "h01_MdeMgmt.h"
#include "c02_SubAdc.h"
#ifndef DEFINED_TYPEDEF_FOR_S_CTX3_
#define DEFINED_TYPEDEF_FOR_S_CTX3_

typedef struct
{
    real32_T a6sInvFactorTx1[6];
    uint32_T a6u32StartBitTx1[6];
    real32_T a6sOffsetTx1[6];
    real32_T a6sMinTx1[6];
    real32_T a6sMaxTx1[6];
    uint32_T a6sClearBitTx1[6];
    int32_T i32CntMaxForTx3;
    uint16_T uSW_REV;
    uint16_T uDummy;
}
S_CTX3;

#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct
{
    int32_T i32inxTx3;                 /* '<S1>/Chart_CntForTx2' */
    uint32_T u32DataLowTx2;            /* '<S1>/Nftn_CommDataParsingTx2' */
    uint32_T u32DataHighTx2;           /* '<S1>/Nftn_CommDataParsingTx2' */
}
StrG03DW;

/* Block signals and states (default storage) */
extern StrG03DW GvG03DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern uint32_T mCTX_u32DataLowTx1;    /* '<Root>/bG03CTX_mCTX_u32DataLowTx1' */
extern uint32_T mCTX_u32DataHighTx1;  /* '<Root>/bG03CTX_mCTX_u32DataHighTx1' */
extern uint32_T mCTX_u32DataLowTx2;    /* '<Root>/bG03CTX_mCTX_u32DataLowTx2' */
extern uint32_T mCTX_u32DataHighTx2;  /* '<Root>/bG03CTX_mCTX_u32DataHighTx2' */

/* Model entry point functions */
extern void g03_CommTx_initialize(void);
extern void g03_CommTx_step(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'g03_CommTx'
 * '<S1>'   : 'g03_CommTx/Ftn_CommDataParsingTx1'
 * '<S2>'   : 'g03_CommTx/Ftn_CommDataParsingTx2'
 * '<S3>'   : 'g03_CommTx/Ftn_CommDataParsingTx1/Chart_CntForTx2'
 * '<S4>'   : 'g03_CommTx/Ftn_CommDataParsingTx1/Nftn_CommDataParsingTx2'
 * '<S5>'   : 'g03_CommTx/Ftn_CommDataParsingTx2/BitShift'
 * '<S6>'   : 'g03_CommTx/Ftn_CommDataParsingTx2/BitShift1'
 * '<S7>'   : 'g03_CommTx/Ftn_CommDataParsingTx2/BitShift2'
 * '<S8>'   : 'g03_CommTx/Ftn_CommDataParsingTx2/BitShift/bit_shift'
 * '<S9>'   : 'g03_CommTx/Ftn_CommDataParsingTx2/BitShift1/bit_shift'
 * '<S10>'  : 'g03_CommTx/Ftn_CommDataParsingTx2/BitShift2/bit_shift'
 */

/*-
 * Requirements for '<Root>': g03_CommTx

 */
#endif                                 /* g03_CommTx_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
