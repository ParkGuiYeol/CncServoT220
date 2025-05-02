/*
// TI File $Revision: /main/9 $
// Checkin $Date: July 9, 2009   09:23:26 $
//###########################################################################
//
// FILE:    28346_RAM_lnk.cmd
//
// TITLE:   Linker Command File For 28346 examples that run out of RAM
//
//###########################################################################
// $TI Release:   $
// $Release Date:   $
//###########################################################################
*/

/* ======================================================
// For Code Composer Studio V2.2 and later
// ---------------------------------------
// Add the header linker command file directly to the project.
========================================================= */

/* ======================================================
// For Code Composer Studio prior to V2.2
// --------------------------------------
// Include DSP2834x_Headers_nonBIOS.cmd in the project
/*========================================================= */

MEMORY
{
PAGE 0 :
   BEGIN        : origin = 0x000000, length = 0x000002
   RAMM0        : origin = 0x000052, length = 0x0003AE
   RAML0        : origin = 0x008000, length = 0x002000
   RAML1        : origin = 0x00A000, length = 0x002000
   RAML2        : origin = 0x00C000, length = 0x002000
   RAML3        : origin = 0x00E000, length = 0x002000
   RAML4        : origin = 0x010000, length = 0x002000
   RAML5        : origin = 0x012000, length = 0x002000
   ZONE7A       : origin = 0x200000, length = 0x00FC00
   RAMH0        : origin = 0x300000, length = 0x008000
   RAMH1        : origin = 0x308000, length = 0x008000
   RAMH2        : origin = 0x310000, length = 0x008000
   CSM_RSVD     : origin = 0x33FF80, length = 0x000076
   CSM_PWL_PROG : origin = 0x33FFF8, length = 0x000008
   IQTABLES     : origin = 0x3FE000, length = 0x000B50
   IQTABLES2    : origin = 0x3FEB50, length = 0x00008C
   FPUTABLES    : origin = 0x3FEBDC, length = 0x0006A0
   BOOTROM      : origin = 0x3FF27C, length = 0x000D44
   RESET        : origin = 0x3FFFC0, length = 0x000002

PAGE 1 :
   BOOT_RSVD    : origin = 0x000002, length = 0x000050
   RAMM1        : origin = 0x000400, length = 0x000400
   RAML6        : origin = 0x014000, length = 0x002000
   RAML7        : origin = 0x016000, length = 0x002000
   ZONE7B       : origin = 0x20FC00, length = 0x000400
   RAMH3        : origin = 0x318000, length = 0x008000
   RAMH4        : origin = 0x320000, length = 0x008000
   RAMH5        : origin = 0x328000, length = 0x008000
}

SECTIONS
{
   codestart        : > BEGIN,     PAGE = 0
   ramfuncs         : > RAML0,     PAGE = 0

   /* 코드(.text)는 RAML2~RAML5에 분산 (PAGE = 0) */
   .text             >> RAML2 | RAML3 | RAML4 | RAML5, PAGE = 0

   .cinit           : > RAML0,     PAGE = 0
   .pinit           : > RAML0,     PAGE = 0
   .switch          : > RAML0,     PAGE = 0

   /* 스택(.stack)은 RAML0에 배치 (64K 이하 메모리) */
   .stack           : > RAML0,     PAGE = 0

   /* 글로벌/정적 변수(.ebss)는 RAML1로 */
   .ebss            : > RAML1,     PAGE = 0

   /* 상수 데이터(.econst)도 RAML1로 */
   .econst          : > RAML1,     PAGE = 0

   /* 힙(.esysmem)은 RAML7에 배치 */
   .esysmem         : > RAML7,     PAGE = 1

   IQmath           : > RAML1,     PAGE = 0
   IQmathTables     : > IQTABLES,  PAGE = 0, TYPE = NOLOAD

   /*
   IQmathTables2    : > IQTABLES2, PAGE = 0, TYPE = NOLOAD
   {
       IQmath.lib<IQNexpTable.obj> (IQmathTablesRam)
   }
   */

   FPUmathTables    : > FPUTABLES, PAGE = 0, TYPE = NOLOAD

   DMARAML2         : > RAML2,     PAGE = 0
   DMARAML3         : > RAML3,     PAGE = 0
   DMARAML4         : > RAML4,     PAGE = 0
   DMARAML5         : > RAML5,     PAGE = 0
   DMARAML6         : > RAML6,     PAGE = 1
   DMARAML7         : > RAML7,     PAGE = 1

   ZONE7DATA        : > ZONE7B,    PAGE = 1

   .reset           : > RESET,     PAGE = 0, TYPE = DSECT
   csm_rsvd         : > CSM_RSVD,  PAGE = 0, TYPE = DSECT
   csmpasswds       : > CSM_PWL_PROG, PAGE = 0, TYPE = DSECT
}

/*
//===========================================================================
// End of file.
//===========================================================================
*/
