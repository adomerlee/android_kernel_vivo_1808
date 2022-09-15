/*
 * Copyright (C) 2018 MediaTek Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See http://www.gnu.org/licenses/gpl-2.0.html for more details.
 */

#ifndef __HELIO_DVFSRC_MT6779_H
#define __HELIO_DVFSRC_MT6779_H

#include <mach/upmu_hw.h>

#define PMIC_VCORE_ADDR		PMIC_RG_BUCK_VCORE_VOSEL
#define VCORE_BASE_UV		400000
#define VCORE_STEP_UV		6250

#define PMIC_VSRAM_OTHERS_ADDR	PMIC_RG_LDO_VSRAM_OTHERS_VOSEL
#define VSRAM_BASE_UV	500000
#define VSRAM_STEP_UV	6250

/* VSRAM_OTHERS */
#define vsram_pmic_to_uv(pmic)	\
	(((pmic) * VSRAM_STEP_UV) + VSRAM_BASE_UV)
#define vsram_uv_to_pmic(uv)	/* pmic >= uv */	\
	((((uv) - VSRAM_BASE_UV) + (VSRAM_STEP_UV - 1)) / VSRAM_STEP_UV)

#define VCOREFS_LEVEL_POSITIVE

/* met profile table index */
enum met_info_index {
	INFO_OPP_IDX = 0,
	INFO_FREQ_IDX,
	INFO_VCORE_IDX,
	INFO_SPM_LEVEL_IDX,
	INFO_MAX,
};

enum met_src_index {
	SRC_MD2SPM_IDX = 0,
	DDR_OPP_IDX,
	DDR_SW_REQ1_SPM_IDX,
	DDR_SW_REQ2_CM_IDX,
	DDR_SW_REQ3_PMQOS_IDX,
	DDR_SW_REQ4_MD_IDX,
	DDR_SW_REQ8_MCUSYS_IDX,
	DDR_QOS_BW_IDX,
	DDR_EMI_TOTAL_IDX,
	DDR_HRT_BW_IDX,
	DDR_HIFI_IDX,
	DDR_HIFI_LATENCY_IDX,
	DDR_MD_LATENCY_IDX,
	VCORE_OPP_IDX,
	VCORE_SW_REQ3_PMQOS_IDX,
	VCORE_SCP_IDX,
	VCORE_HIFI_IDX,
	SRC_SCP_REQ_IDX,
	SRC_PMQOS_TATOL_IDX,
	SRC_PMQOS_BW0_IDX,
	SRC_PMQOS_BW1_IDX,
	SRC_PMQOS_BW2_IDX,
	SRC_PMQOS_BW3_IDX,
	SRC_PMQOS_BW4_IDX,
	SRC_TOTAL_EMI_BW_IDX,
	SRC_HRT_MD_BW_IDX,
	SRC_HRT_DISP_BW_IDX,
	SRC_HRT_ISP_BW_IDX,
	SRC_MD_SCENARIO_IDX,
	SRC_HIFI_SCENARIO_IDX,
	SRC_MD_EMI_LATENCY_IDX,
	SRC_MAX
};

extern int commit_data(int type, int data, int check_spmfw);
extern void pm_qos_trace_dbg_show_request(int pm_qos_class);
extern u32 dvfsrc_get_md_bw(void);
extern u32 dvfsrc_calc_isp_hrt_opp(int bw);

#endif /* __HELIO_DVFSRC_MT6779_H */


