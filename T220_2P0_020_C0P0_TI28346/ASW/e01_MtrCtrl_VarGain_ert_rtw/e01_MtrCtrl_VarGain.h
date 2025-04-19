/*
 * File: e01_MtrCtrl_VarGain.h
 *
 * Code generated for Simulink model 'e01_MtrCtrl_VarGain'.
 *
 * Model version                  : 7.579
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Apr 19 16:29:20 2025
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

#ifndef e01_MtrCtrl_VarGain_h_
#define e01_MtrCtrl_VarGain_h_
#ifndef e01_MtrCtrl_VarGain_COMMON_INCLUDES_
#define e01_MtrCtrl_VarGain_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                /* e01_MtrCtrl_VarGain_COMMON_INCLUDES_ */

#include <string.h>

/* Includes for objects with custom storage classes */
#include "e03_MtrCtrl_MtrCtrl.h"
#include "e02_MtrCtrl_Pst.h"
#include "h01_MdeMgmt.h"
#include "b01_OSnScheduler.h"
#ifndef DEFINED_TYPEDEF_FOR_S_E01PCG_
#define DEFINED_TYPEDEF_FOR_S_E01PCG_

typedef struct
{
    real32_T sPCG_KpMax;
    real32_T sPCG_KpMin;
    real32_T sPCG_KpGa;
    real32_T sPCG_KpGb;
    real32_T sPCG_Ki;
    real32_T sPCG_Kd;
    real32_T sPCG_Ka;
    real32_T sPCG_Apst;
    uint16_T uDummy;
}
S_E01PCG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_S_E01SCG_
#define DEFINED_TYPEDEF_FOR_S_E01SCG_

typedef struct
{
    real32_T sSCG_KpMax;
    real32_T sSCG_KpMin;
    real32_T sSCG_KpGa;
    real32_T sSCG_KpGb;
    real32_T sSCG_Ki;
    real32_T sSCG_Ka;
    real32_T sSCG_Alpha;
    uint16_T uDummy;
}
S_E01SCG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_S_E01CCG_
#define DEFINED_TYPEDEF_FOR_S_E01CCG_

typedef struct
{
    real32_T sCCG_Kpd;
    real32_T sCCG_Kid;
    real32_T sCCG_Kad;
    real32_T sCCG_Kpq;
    real32_T sCCG_Kiq;
    real32_T sCCG_Kaq;
    uint16_T uDummy;
}
S_E01CCG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_S_E01SLP_
#define DEFINED_TYPEDEF_FOR_S_E01SLP_

typedef struct
{
    real32_T sSpdRising;
    real32_T sSpdFalling;
    real32_T sTqRisingTqMde;
    real32_T sTqFallingTqMde;
    real32_T sTqRisingSpdPstMde;
    real32_T sTqFallingSpdPstMde;
    real32_T sCurrRising;
    real32_T sCurrFalling;
    uint16_T uDummy;
}
S_E01SLP;

#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct
{
    real32_T sAbsWm;                   /* '<Root>/Abs' */
    real32_T sAbsTqRefIn;              /* '<Root>/Abs1' */
}
StrE01DW;

/* Block signals and states (default storage) */
extern StrE01DW GvE01DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T mMCVG_sPCG_Kp;         /* '<Root>/bE01MCVG_mMCVG_sPCG_Kp' */
extern real32_T mMCVG_sPCG_Ki;         /* '<Root>/bE01MCVG_mMCVG_sPCG_Ki' */
extern real32_T mMCVG_sPCG_Kd;         /* '<Root>/bE01MCVG_mMCVG_sPCG_Kd' */
extern real32_T mMCVG_sPCG_Ka;         /* '<Root>/bE01MCVG_mMCVG_sPCG_Ka' */
extern real32_T mMCVG_sPCG_Apst;       /* '<Root>/bE01MCVG_mMCVG_sPCG_Apst' */
extern real32_T mMCVG_sSCG_Kp;         /* '<Root>/bE01MCVG_mMCVG_sSCG_Kp' */
extern real32_T mMCVG_sSCG_Ki;         /* '<Root>/bE01MCVG_mMCVG_sSCG_Ki' */
extern real32_T mMCVG_sSCG_Ka;         /* '<Root>/bE01MCVG_mMCVG_sSCG_Ka' */
extern real32_T mMCVG_sSCG_Apst;       /* '<Root>/bE01MCVG_mMCVG_sSCG_Apst' */
extern real32_T mMCVG_sCCG_Kpd;        /* '<Root>/bE01MCVG_mMCVG_sCCG_Kpd' */
extern real32_T mMCVG_sCCG_Kid;        /* '<Root>/bE01MCVG_mMCVG_sCCG_Kid' */
extern real32_T mMCVG_sCCG_Kad;        /* '<Root>/bE01MCVG_mMCVG_sCCG_Kad' */
extern real32_T mMCVG_sCCG_Kpq;        /* '<Root>/bE01MCVG_mMCVG_sCCG_Kpq' */
extern real32_T mMCVG_sCCG_Kiq;        /* '<Root>/bE01MCVG_mMCVG_sCCG_Kiq' */
extern real32_T mMCVG_sCCG_Kaq;        /* '<Root>/bE01MCVG_mMCVG_sCCG_Kaq' */
extern real32_T mMCVG_sSpdSlpRising; /* '<Root>/bE01MCVG_mMCVG_sSpdSlpRising' */
extern real32_T mMCVG_sSpdSlpFalling;
                                    /* '<Root>/bE01MCVG_mMCVG_sSpdSlpFalling' */
extern real32_T mMCVG_sTqSlpRising;   /* '<Root>/bE01MCVG_mMCVG_sTqSlpRising' */
extern real32_T mMCVG_sTqSlpFalling; /* '<Root>/bE01MCVG_mMCVG_sTqSlpFalling' */
extern real32_T mMCVG_sCurrSlpRising;
                                    /* '<Root>/bE01MCVG_mMCVG_sCurrSlpRising' */
extern real32_T mMCVG_sCurrSlpFalling;
                                   /* '<Root>/bE01MCVG_mMCVG_sCurrSlpFalling' */

/* Model entry point functions */
extern void e01_MtrCtrl_VarGain_initialize(void);
extern void e01_MtrCtrl_VarGain_step(void);

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
 * '<Root>' : 'e01_MtrCtrl_VarGain'
 * '<S1>'   : 'e01_MtrCtrl_VarGain/Nftn_VarGainGroupA'
 * '<S2>'   : 'e01_MtrCtrl_VarGain/Nftn_VarGainGroupB'
 * '<S3>'   : 'e01_MtrCtrl_VarGain/Nftn_VarGainGroupC'
 * '<S4>'   : 'e01_MtrCtrl_VarGain/Nftn_VarGainGroupC/Chart_VarGainGroupC'
 */

/*-
 * Requirements for '<Root>': e01_MtrCtrl_VarGain

 */
#endif                                 /* e01_MtrCtrl_VarGain_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
