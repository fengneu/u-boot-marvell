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

#ifndef _REGS_BASE_H_
#define _REGS_BASE_H_

#include <asm/arch/memory-map.h>

#define MPP_REGS_BASE		(MVEBU_REGS_BASE + 0x18000)
#define MVEBU_ADEC_BASE		(MVEBU_REGS_BASE + 0x20000)

#define MVEBU_GLOBAL_TIMER_BASE	(MVEBU_REGS_BASE + 0x20300)
#define MVEBU_PCIE_BASE(x)	((x == 0) ? (MVEBU_REGS_BASE + 0x80000) : \
				(MVEBU_REGS_BASE + 0x40000 + (0x4000 * (x - 1))))

#define MVEBU_MISC_REGS_BASE	(MVEBU_REGS_BASE + 0x18200)
#define MVEBU_DEVICE_ID_REG	(MVEBU_MISC_REGS_BASE + 0x38)
#define MVEBU_DEVICE_REV_REG	(MVEBU_MISC_REGS_BASE + 0x3C)
#define MVEBU_RESET_MASK_REG	(MVEBU_MISC_REGS_BASE + 0x60)
#define MVEBU_SOFT_RESET_REG	(MVEBU_MISC_REGS_BASE + 0x64)

#endif	/* _REGS_BASE_H_ */