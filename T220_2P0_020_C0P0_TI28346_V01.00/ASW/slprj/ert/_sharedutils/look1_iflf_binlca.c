/*
 * File: look1_iflf_binlca.c
 *
 * Code generated for Simulink model 'c02_SubAdc'.
 *
 * Model version                  : 7.310
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Mon Jan 20 23:50:14 2025
 * Created by: GuiYeol Park
 */

#include "look1_iflf_binlca.h"
#include "rtwtypes.h"

real32_T look1_iflf_binlca(real32_T u0, const real32_T bp0[], const real32_T
    table[], uint32_T maxIndex)
{
    real32_T frac;
    real32_T y;
    uint32_T iLeft;

    /* Column-major Lookup 1-D
       Search method: 'binary'
       Use previous index: 'off'
       Interpolation method: 'Linear point-slope'
       Extrapolation method: 'Clip'
       Use last breakpoint for index at or above upper limit: 'on'
       Remove protection against out-of-range input in generated code: 'off'
     */
    /* Prelookup - Index and Fraction
       Index Search method: 'binary'
       Extrapolation method: 'Clip'
       Use previous index: 'off'
       Use last breakpoint for index at or above upper limit: 'on'
       Remove protection against out-of-range input in generated code: 'off'
     */
    if (u0 <= bp0[0UL])
    {
        iLeft = 0UL;
        frac = 0.0F;
    }
    else if (u0 < bp0[maxIndex])
    {
        uint32_T bpIdx;
        uint32_T iRght;

        /* Binary Search */
        bpIdx = (maxIndex >> 1UL);
        iLeft = 0UL;
        iRght = maxIndex;
        while ((iRght - iLeft) > 1UL)
        {
            if (u0 < bp0[bpIdx])
            {
                iRght = bpIdx;
            }
            else
            {
                iLeft = bpIdx;
            }

            bpIdx = ((iRght + iLeft) >> 1UL);
        }

        frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1UL] - bp0[iLeft]);
    }
    else
    {
        iLeft = maxIndex;
        frac = 0.0F;
    }

    /* Column-major Interpolation 1-D
       Interpolation method: 'Linear point-slope'
       Use last breakpoint for index at or above upper limit: 'on'
       Overflow mode: 'wrapping'
     */
    if (iLeft == maxIndex)
    {
        y = table[iLeft];
    }
    else
    {
        real32_T yL_0d0;
        yL_0d0 = table[iLeft];
        y = ((table[iLeft + 1UL] - yL_0d0) * frac) + yL_0d0;
    }

    return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
