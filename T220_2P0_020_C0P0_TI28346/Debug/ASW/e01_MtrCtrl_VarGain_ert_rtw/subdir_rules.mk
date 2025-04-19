################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
ASW/e01_MtrCtrl_VarGain_ert_rtw/%.obj: ../ASW/e01_MtrCtrl_VarGain_ert_rtw/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -O4 --opt_for_speed=2 --include_path="D:/6_CncServo/1_CncServoCode/2_KCNC_T220_2P0_020_TI28346_GitHub/T220_2P0_020_C0P0_TI28346/BSW/Include" --include_path="D:/6_CncServo/1_CncServoCode/2_KCNC_T220_2P0_020_TI28346_GitHub/T220_2P0_020_C0P0_TI28346/BSW/Source" --include_path="C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/Include" --include_path="D:/6_CncServo/1_CncServoCode/2_KCNC_T220_2P0_020_TI28346_GitHub/T220_2P0_020_C0P0_TI28346/ASW/slprj/ert/_sharedutils" --include_path="D:/6_CncServo/1_CncServoCode/2_KCNC_T220_2P0_020_TI28346_GitHub/T220_2P0_020_C0P0_TI28346/ASW/b01_OSnScheduler_ert_rtw" --include_path="D:/6_CncServo/1_CncServoCode/2_KCNC_T220_2P0_020_TI28346_GitHub/T220_2P0_020_C0P0_TI28346/ASW/c01_MainAdc_ert_rtw" --include_path="D:/6_CncServo/1_CncServoCode/2_KCNC_T220_2P0_020_TI28346_GitHub/T220_2P0_020_C0P0_TI28346/ASW/c02_SubAdc_ert_rtw" --include_path="D:/6_CncServo/1_CncServoCode/2_KCNC_T220_2P0_020_TI28346_GitHub/T220_2P0_020_C0P0_TI28346/ASW/d01_Diaglnteg_ert_rtw" --include_path="D:/6_CncServo/1_CncServoCode/2_KCNC_T220_2P0_020_TI28346_GitHub/T220_2P0_020_C0P0_TI28346/ASW/e01_MtrCtrl_VarGain_ert_rtw" --include_path="D:/6_CncServo/1_CncServoCode/2_KCNC_T220_2P0_020_TI28346_GitHub/T220_2P0_020_C0P0_TI28346/ASW/e02_MtrCtrl_Pst_ert_rtw" --include_path="D:/6_CncServo/1_CncServoCode/2_KCNC_T220_2P0_020_TI28346_GitHub/T220_2P0_020_C0P0_TI28346/ASW/e03_MtrCtrl_MtrCtrl_ert_rtw" --include_path="D:/6_CncServo/1_CncServoCode/2_KCNC_T220_2P0_020_TI28346_GitHub/T220_2P0_020_C0P0_TI28346/ASW/e04_MtrCtrl_PwmSet_ert_rtw" --include_path="D:/6_CncServo/1_CncServoCode/2_KCNC_T220_2P0_020_TI28346_GitHub/T220_2P0_020_C0P0_TI28346/ASW/f01_CommRx1_ert_rtw" --include_path="D:/6_CncServo/1_CncServoCode/2_KCNC_T220_2P0_020_TI28346_GitHub/T220_2P0_020_C0P0_TI28346/ASW/g03_CommTx_ert_rtw" --include_path="D:/6_CncServo/1_CncServoCode/2_KCNC_T220_2P0_020_TI28346_GitHub/T220_2P0_020_C0P0_TI28346/ASW/h01_MdeMgmt_ert_rtw" --include_path="D:/6_CncServo/1_CncServoCode/2_KCNC_T220_2P0_020_TI28346_GitHub/T220_2P0_020_C0P0_TI28346/ASW/j01_McuInit_ert_rtw" -g --diag_warning=225 --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="ASW/e01_MtrCtrl_VarGain_ert_rtw/$(basename $(<F)).d_raw" --obj_directory="ASW/e01_MtrCtrl_VarGain_ert_rtw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


