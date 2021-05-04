/*
 * (C) Copyright 2003
 * Wolfgang Denk, DENX Software Engineering, <wd@denx.de>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include <command.h>
#include <asm/mipsregs.h>
#include <asm/arch/prx300.h>
#include <lantiq.h>

void _machine_restart(void)
{
	u32 reg;

	reg = RST_REQ_GLB_SW_MASK | RST_REQ_GPHY_MASK;
	ltq_w32(RCU_MODULE_BASE, RST_REQ, reg);
}

unsigned int ltq_get_cpu_rev(void)
{
	u32 reg;

	reg = ltq_r32(LTQ_CHIPID, LTQ_MPS_CHIPID);
	return (unsigned int)(reg & REV_MASK) >> REV_SHIFT;
}
