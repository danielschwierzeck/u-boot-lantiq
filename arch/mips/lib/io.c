/*
 * (C) Copyright 2003
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <asm/io.h>
#include <linux/compiler.h>

/*
 * mips_io_port_base is the begin of the address space to which x86 style
 * I/O ports are mapped.
 */
const unsigned long mips_io_port_base = -1;

#ifdef CONFIG_PHYS_TO_BUS

__weak unsigned long phys_to_bus(unsigned long phys)
{
	return (unsigned long)virt_to_phys((void *)phys);
}

__weak unsigned long bus_to_phys(unsigned long bus)
{
	return (unsigned long)phys_to_virt(bus);
}

#endif
