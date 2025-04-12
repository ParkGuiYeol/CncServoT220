/*
 * Define_DAC.h
 *
 * C/C++ source code generated on : Thu Jan 11 10:09:04 2024
 * Created by: System Research Team
 * Code generated on : Sat Mar 15 00:16:24 2025
 *
 */

#ifndef DEFINE_DAC_H_
#define DEFINE_DAC_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "rtwtypes.h"

#define DAC_MID                        (8192.0F)                 //
#define DAC_RNG                        (8192.0F)                 //
#define DAC_EFF                        (0x3FFFU)                 //

//======================== Pre-Defines : Type Selection ========================//
#define DAC_Val(_ch)                   ((DACS.CH##_ch.Type == 0) ? (float)(*(float *)DACS.CH##_ch.Out) : \
 ((DACS.CH##_ch.Type == 1) ? (float)(*(uint8_T *)DACS.CH##_ch.Out) : \
 ((DACS.CH##_ch.Type == 2) ? (float)(*(uint16_T *)DACS.CH##_ch.Out) : \
 ((DACS.CH##_ch.Type == 3) ? (float)(*(uint32_T *)DACS.CH##_ch.Out) : \
 ((DACS.CH##_ch.Type == 4) ? (float)(*(uint64_T *)DACS.CH##_ch.Out) : \
 ((DACS.CH##_ch.Type == 5) ? (float)(*(int8_T *)DACS.CH##_ch.Out) : \
 ((DACS.CH##_ch.Type == 6) ? (float)(*(int16_T *)DACS.CH##_ch.Out) : \
 ((DACS.CH##_ch.Type == 7) ? (float)(*(int32_T *)DACS.CH##_ch.Out) : \
 (float)(*(int64_T *)DACS.CH##_ch.Out)))))))))

//============================  Structures : S_DACS ============================//
typedef struct
{
    //-------------------------------  Variables -------------------------------//
    uint16_T Sel;
    float Rng;

    //--------------------------  Structures : S_ADAC --------------------------//
    struct S_ADAC
    {
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  Variables ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
        void *Out;
        float Rng, Mid;
        uint8_T Type;
        float INVRng;
    }
    CH1, CH2, CH3, CH4;
}
S_DACS;

extern S_DACS DACS;
extern void DAC_Out(void);

#ifdef __cplusplus
extern "C" {
#endif

#endif /* DEFINE_DAC_H_ */
