/************************************************************************
*
*   Copyright: Lantiq Asia Pacific Pte Ltd
*   Author:    William Widjaja
*
*   Additional U-boot command to allow otp programming when Root of Trust Transfer mode
*
*   Revision:  1.0
*
************************************************************************/

#include <common.h>
#include <command.h>
#include <asm/boot.h>
#include <asm/addrspace.h>

extern u32 otp_prog_signal(void);
extern void otp_prog_wait_cmd(void);
extern int otp_prog_execute(void);

int rot_prog(cmd_tbl_t * cmdtp, int flag, int argc, char *argv[])
{
    u32 ret = 0;

    if (argc != 2) {
        printf("Wrong Number of arguements given!\n");
        cmd_usage(cmdtp);
        return -1;
    }

    #ifdef CONFIG_GRX500_BOOT_4KEC_ONLY
    /* do it directly without need to go through wait cmd */
    ret = otp_prog_execute();
    #else
    ret = otp_prog_signal();
    #endif

    /* otp programming result check
     * 0 = otp program success
     * 1 = invalid param
     * 2 = otp content not word / 4 bytes aligned
     * 3 = otp program failure
    */
    switch(ret){
        case 0 :
            printf("OTP program success!\n");
            break;
        case 1 :
            printf("ERROR: Invalid parameters!\n");
            break;
        case 2 :
            printf("ERROR: otp content not word / 4 bytes aligned!\n");
            break;
        case 3 :
            printf("ERROR: otp program failure!\n");
            break;
        default :
            printf("ERROR: Unknown!\n");
            break;
    }

    return (int)ret;
}

int do_rot(cmd_tbl_t * cmdtp, int flag, int argc, char *argv[])
{
    if (strcmp(argv[1], "prog_key") == 0)
        return rot_prog(cmdtp, flag, argc, argv);

    cmd_usage(cmdtp);

    return 0;
}

U_BOOT_CMD(rot, 5, 1, do_rot,
    "Command to Program OTP Production Keys",
    "rot prog_key\n"
);

