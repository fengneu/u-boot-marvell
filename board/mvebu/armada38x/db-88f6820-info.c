/*
 * ***************************************************************************
 * Copyright (C) Marvell International Ltd. and its affiliates
 * ***************************************************************************
 * Marvell GPL License Option
 * If you received this File from Marvell, you may opt to use, redistribute
 * and/or modify this File in accordance with the terms and conditions of the
 * General Public License Version 2, June 1991 (the "GPL License"), a copy of
 * which is available along with the File in the license.txt file or by writing
 * to the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 or on the worldwide web at http://www.gnu.org/licenses/gpl.txt.
 *
 * THE FILE IS DISTRIBUTED AS-IS, WITHOUT WARRANTY OF ANY KIND, AND THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE ARE
 * EXPRESSLY DISCLAIMED. The GPL License provides additional details about this
 * warranty disclaimer.
 * ***************************************************************************
 */

#include <common.h>
#include <linux/compiler.h>
#include <asm/arch-mvebu/unit-info.h>
#include <asm/arch-mvebu/mpp.h>
#include "board-info.h"

struct mvebu_board_config db_a38x_config = {
	.sar_cnt = 2,
	.active_sar = {BOOT_SRC_SAR, CPUS_NUM_SAR},
	.cfg_cnt = 2,
	.active_cfg = {BOARD_ID_CFG, SERDES_0_CFG}
};

int board_get_id(void)
{
	return ARMADA_38X_DB_ID;
}

int db_a38x_configure_mpp(void)
{
#ifdef CONFIG_MVEBU_NAND_BOOT
	mpp_enable_bus(a38x_db_info.mpp_regs, NAND_0_MPP_BUS, 0);
#endif
#ifdef CONFIG_MVEBU_SPI_BOOT
	mpp_enable_bus(a38x_db_info.mpp_regs, SPI_0_MPP_BUS, 0);
#endif
	return 0;
}

struct mvebu_board_info a38x_db_info = {
	.name = "DB-88F6820-BP",
	.id = ARMADA_38X_DB_ID,
	.mpp_regs = {0x11111111, 0x11111111, 0x11266011, 0x22222011,
		     0x22200002, 0x40042022, 0x55550555, 0x00005550},
	.configure_mpp = &db_a38x_configure_mpp,
	.configurable = 1,
	.config_data = &db_a38x_config,
};
