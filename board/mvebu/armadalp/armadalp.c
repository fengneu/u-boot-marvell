/*
* ***************************************************************************
* Copyright (C) 2015 Marvell International Ltd.
* ***************************************************************************
* This program is free software: you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the Free
* Software Foundation, either version 2 of the License, or any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
* ***************************************************************************
*/

/* #define DEBUG*/

#include <common.h>
#include <malloc.h>
#include <errno.h>
#include <netdev.h>
#include <asm/io.h>
#include <asm/arch-armadalp/armadalp.h>
#include <linux/compiler.h>
#include "board-info.h"

struct mvebu_board_info *mvebu_board_info_get(enum fdt_compat_id compat_id)
{
	switch (compat_id) {
#ifdef CONFIG_ARMADA_LP_DB0
	case COMPAT_MVEBU_ARMADA_LP_DB0:
		return &db0_armadalp_info;
#endif
#ifdef CONFIG_ARMADA_LP_DB1
	case COMPAT_MVEBU_ARMADA_LP_DB1:
		return &db1_armadalp_info;
#endif
#ifdef CONFIG_ARMADA_LP_CUSTOMER
	case COMPAT_MVEBU_ARMADA_LP_CUSTOMER:
		return &armadalp_customer_info;
#endif
	default:
		error("Missing board information for compatible string = %d\n", compat_id);
#ifdef CONFIG_ARMADA_LP_DB0
		return &db0_armadalp_info;
#else
		return NULL;
#endif
	}
}