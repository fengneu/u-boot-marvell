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

#ifndef _SOC_INFO_H_
#define _SOC_INFO_H_

/* General MPP definitions */
#define MAX_MPP_OPTS		7
#define MAX_MPP_ID		59

#define MPP_BIT_CNT		4
#define MPP_FIELD_MASK		0x7
#define MPP_FIELD_BITS		3
#define MPP_VAL_MASK		0xF

#define MPPS_PER_REG		(32 / MPP_BIT_CNT)
#define MAX_MPP_REGS		((MAX_MPP_ID + MPPS_PER_REG) / MPPS_PER_REG)

#endif	/* _SOC_INFO_H_ */