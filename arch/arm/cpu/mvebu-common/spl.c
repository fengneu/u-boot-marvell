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

#include <common.h>
#include <spl.h>
#include <fdtdec.h>
#include <asm/arch-mvebu/fdt.h>

DECLARE_GLOBAL_DATA_PTR;

extern void static_dram_init(void);

#ifndef CONFIG_PALLADIUM
static int setup_fdt(void)
{
#ifdef CONFIG_OF_CONTROL
#ifdef CONFIG_OF_EMBED
	/* Get a pointer to the FDT */
	gd->fdt_blob = __dtb_dt_begin;
#else
	#error "Support only embedded FDT mode in SPL"
#endif
#endif
	return 0;
}
#endif

void board_init_f(ulong bootflag)
{
	gd = &gdata;
	gd->baudrate = CONFIG_BAUDRATE;

#ifndef CONFIG_PALLADIUM
	setup_fdt();
	static_dram_init();
#endif
	preloader_console_init();
}