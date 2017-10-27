/************************************************************************
*
*	Copyright: Lantiq Asia Pacific Pte Ltd
*	Author:	   Mohammad Firdaus B Alias Thani
*	
*	Additional U-boot command to allow booting of the TOS from
*	the U-boot commandline.
*
*	Revision:  1.0
*
************************************************************************/

#include <common.h>
#include <command.h>
#include <asm/boot.h>
#include <asm/addrspace.h>

int run_tos(cmd_tbl_t * cmdtp, int flag, int argc, char *argv[])
{
	unsigned long ddr_addr, size, load_addr;
	unsigned long phy_ddr_addr;

	if (argc != 5) {
		printf("Wrong Number of arguements given!\n");
		cmd_usage(cmdtp);
		return -1;
	}
	
	load_addr = (ulong) simple_strtoul(argv[2], NULL, 16);
	ddr_addr = (ulong) simple_strtoul(argv[3], NULL, 16);
	size = (ulong) simple_strtoul(argv[4], NULL, 16);

	phy_ddr_addr = CPHYSADDR((u32)ddr_addr) | 0x20000000;
	
	asm("sync");	
    invalidate_scache_range((u32)phy_ddr_addr, (u32)(phy_ddr_addr + size));
    invalidate_dcache_range((u32)phy_ddr_addr, (u32)(phy_ddr_addr + size));

	/* Write the location we want 4Kec to load to */
	REG32(MPS_LOAD_ADDR) = load_addr;
	/* Write DDR location to mailbox */
	REG32(MPS_DDR_LOC) = ddr_addr;
	/* Write image size to mailbox */
	REG32(MPS_SIZE_LOC) = size;
	/* Trigger 4Kec to run */
	REG32(SRAMFLAG) = IPCMAGIC;

	return 0;
}

int wait_tos(cmd_tbl_t * cmdtp, int flag, int argc, char *argv[])
{
	if (argc != 2) {
		printf("Wrong Number of arguements given!\n");
		cmd_usage(cmdtp);
		return -1;
	}

	/* wait till 4kec kernel notify us with bootcore up icc msg  */
	while(REG32(0xbf2013f8)!=0x00000100);

	return 0;
}

int boot_tos(cmd_tbl_t * cmdtp, int flag, int argc, char *argv[])
{
	if (strcmp(argv[1], "load_os") == 0)
		return run_tos(cmdtp, flag, argc, argv);
	else if (strcmp(argv[1], "wait_os") == 0)
		return wait_tos(cmdtp, flag, argc, argv);

	cmd_usage(cmdtp);

	return 0;
}

U_BOOT_CMD(secboot, 5, 1, boot_tos, 
	"Command to Boot TOS",
	"secboot load_os [4Kec high mem addr] [ddr load address] [image size]\n"
	"secboot wait_os\n"
);

