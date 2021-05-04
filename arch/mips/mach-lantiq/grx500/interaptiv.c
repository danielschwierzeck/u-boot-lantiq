#include <common.h>

u32 permission_wr(u32 addr, u32 val){
	REG32(addr) = val;
	return 0;
}

void set_permission(void)
{
	int i = 0;

	i += permission_wr(0xb3f81458, 0x1f); 	//ssb6:ln60
	i += permission_wr(0xb3f81450, 0x1f); 
	i += permission_wr(0xb3f80858, 0x7f); 	//ssb6:ddr,memmax ,vector 0, 0x7f
	i += permission_wr(0xb3f80850, 0x7f);    
	i += permission_wr(0xb3f80878, 0x7f); 	//ssb6:ddr,memmax ,vector 1 
	i += permission_wr(0xb3f80870, 0x7f);    
	i += permission_wr(0xb3f80898, 0x7f); 	//ssb6:ddr,memmax ,vector 2
	i += permission_wr(0xb3f80890, 0x7f);    
	i += permission_wr(0xb3f808b8, 0x7f); 	//ssb6:ddr,memmax ,vector 3
	i += permission_wr(0xb3f808b0, 0x7f);    
	i += permission_wr(0xb3f808d8, 0x7f); 	//ssb6:ddr,memmax ,vector 4
	i += permission_wr(0xb3f808d0, 0x7f);    
	i += permission_wr(0xb3f808f8, 0x7f); 	//ssb6:ddr,memmax ,vector 5
	i += permission_wr(0xb3f808f0, 0x7f);    
	i += permission_wr(0xb3f80918, 0x7f); 	//ssb6:ddr,memmax ,vector 6
	i += permission_wr(0xb3f80910, 0x7f);    
	i += permission_wr(0xb3f80938, 0x7f); 	//ssb6:ddr,memmax ,vector 7
	i += permission_wr(0xb3f80930, 0x7f);    
	i += permission_wr(0xb3f80c58, 0x1f); 	//ssb6:ddr,upctl 
	i += permission_wr(0xb3f80c50, 0x1f);
	i += permission_wr(0xb3f81058, 0x1f); 	//ssb6:ddr,phy
	i += permission_wr(0xb3f81050, 0x1f);
	i += permission_wr(0xb3f80458, 0x3); 	//ssb6:iocu (2-bit)
	i += permission_wr(0xb3f80450, 0x3);
  

	/* SSX0 FOR OTHER MASTER TO ACCESS BOOTROM, OTP, SSBRAM */	
	i = 0;
	i += permission_wr(0xbff82858, 0x1f); 	//ss0:ln01
	i += permission_wr(0xbff82850, 0x1f); 
	i += permission_wr(0xbff82C58, 0x1f); 	//ss0:ln02
	i += permission_wr(0xbff82C50, 0x1f); 
	i += permission_wr(0xbff83058, 0x1f); 	//ss0:ln03
	i += permission_wr(0xbff83050, 0x1f); 
	i += permission_wr(0xbff83458, 0x1f); 	//ss0:ex04
	i += permission_wr(0xbff83450, 0x1f); 
	i += permission_wr(0xbff83858, 0x1f); 	//ss0:ex05
	i += permission_wr(0xbff83850, 0x1f); 
	i += permission_wr(0xbff80858, 0x1f); 	//ss0:rom
	i += permission_wr(0xbff80850, 0x1f); 
	i += permission_wr(0xbff80c58, 0x1f); 	//ss0:otp
	i += permission_wr(0xbff80c50, 0x1f); 
	i += permission_wr(0xbff80458, 0x1f); 	//ss0:ssb, region 0
	i += permission_wr(0xbff80450, 0x1f); 
	i += permission_wr(0xbff80478, 0x01);   //ss0:ssb, region 1 (1, from S1.3)
	i += permission_wr(0xbff80470, 0x01);
	i += permission_wr(0xbff80498, 0x01);   //ss0:ssb, region 2 (1, from S1.3)
	i += permission_wr(0xbff80490, 0x01);
	i += permission_wr(0xbff804b8, 0x01);   //ss0:ssb, region 3 (1, from S1.3)
	i += permission_wr(0xbff804b0, 0x01);
	i += permission_wr(0xbff81058, 0x1f);   //ssx0, cbm1
	i += permission_wr(0xbff81050, 0x1f);
	i += permission_wr(0xbff81458, 0x1f);   //ssx0, cbm2
	i += permission_wr(0xbff81450, 0x1f);
	i += permission_wr(0xbff82058, 0x1f);   //ssx0, dma3
	i += permission_wr(0xbff82050, 0x1f);
	i += permission_wr(0xbff82458, 0x1f);   //ssx0, dma4
	i += permission_wr(0xbff82450, 0x1f);
	i += permission_wr(0xbff81858, 0x1f);   //ssx0, eip97 (only 4kec should access)
	i += permission_wr(0xbff81850, 0x1f);
	i += permission_wr(0xbff81C58, 0x1f);   //ssx0, eip123 (only 4kec should access)
	i += permission_wr(0xbff81C50, 0x1f);


	
	/* SSX4 - FOR OTHER MASTER TO ACCESS PERIPHERALS */
	i = 0;
	i += permission_wr(0xb7f82058, 0x1f); 	//ssb4:asc0
	i += permission_wr(0xb7f82050, 0x1f); 
	i += permission_wr(0xb7f82458, 0x1f); 	//ssb4:asc1
	i += permission_wr(0xb7f82450, 0x1f); 
	i += permission_wr(0xb7f81858, 0x1f); 	//ssb4:ledc
	i += permission_wr(0xb7f81850, 0x1f);
	i += permission_wr(0xb7f81458, 0x1f); 	//ssb4:gpio (0x1 for only 4KEc)
	i += permission_wr(0xb7f81450, 0x1f);
	i += permission_wr(0xb7f81C58, 0x1f); 	//ssb4:i2c
	i += permission_wr(0xb7f81C50, 0x1f);
	i += permission_wr(0xb7f83858, 0x1f); 	//ssb4:ebu
	i += permission_wr(0xb7f83850, 0x1f);
	i += permission_wr(0xb7f82858, 0x1f); 	//ssb4:gptc0
	i += permission_wr(0xb7f82850, 0x1f);
	i += permission_wr(0xb7f83C58, 0x1f); 	//ssb4:gptc1
	i += permission_wr(0xb7f83C50, 0x1f);
	i += permission_wr(0xb7f84058, 0x1f); 	//ssb4:gptc2
	i += permission_wr(0xb7f84050, 0x1f);
	i += permission_wr(0xb7f80458, 0x1f);	//ssx4, cgu
	i += permission_wr(0xb7f80450, 0x1f);
	i += permission_wr(0xb7f80858, 0x1f);	//ssx4, rcu
	i += permission_wr(0xb7f80850, 0x1f);
	i += permission_wr(0xb7f80C58, 0x1f);	//ssx4, pmu
	i += permission_wr(0xb7f80C50, 0x1f);
	i += permission_wr(0xb7f81058, 0x1f);	//ssx4, pcm
	i += permission_wr(0xb7f81050, 0x1f);
	i += permission_wr(0xb7f82C58, 0x1f);	//ssx4, spi0
	i += permission_wr(0xb7f82C50, 0x1f);
	i += permission_wr(0xb7f83058, 0x1f);	//ssx4, spi1
	i += permission_wr(0xb7f83050, 0x1f);
	i += permission_wr(0xb7f83458, 0x1f);	//ssx4, dma0
	i += permission_wr(0xb7f83450, 0x1f);
	

	/* SSX1 */
	i = 0;
	i += permission_wr(0xbdf80058, 0x1f);       //ssx1, reg1-r0 (only 4kec should access reg1-r0)
	i += permission_wr(0xbdf80050, 0x1f);
	i += permission_wr(0xbdf80078, 0x1f);   //ssx1, reg1-r1 (only 4kec should access reg1-r1)
	i += permission_wr(0xbdf80070, 0x1f);
	i += permission_wr(0xbdf80c58, 0x1f);       //ssx1:gswipl_pm
	i += permission_wr(0xbdf80c50, 0x1f);
	i += permission_wr(0xbdf80458, 0x1f);       //ssx1:dm2r, Vector 0
	i += permission_wr(0xbdf80450, 0x1f);
	i += permission_wr(0xbdf80858, 0x1f);       //ssx1:dm2t, Vector 0
	i += permission_wr(0xbdf80850, 0x1f);
	i += permission_wr(0xbdf81058, 0x1);        //ssx1:ln10, 1 bit for all
	i += permission_wr(0xbdf81050, 0x1);

	/*ssx2*/
        i += permission_wr(0xbbf80058, 0x1f);   //ssx2, reg2-r0 (only 4kec should access reg2-r0)
        i += permission_wr(0xbbf80050, 0x1f);
        i += permission_wr(0xbbf80078, 0x1f);   //ssx2, reg2-r1 (only 4kec should access reg2-r1)
        i += permission_wr(0xbbf80070, 0x1f);
        i += permission_wr(0xbbf81C58, 0x1f);   //ssx2, gswip-r
        i += permission_wr(0xbbf81C50, 0x1f);
        i += permission_wr(0xbbf81858, 0x1f);   //ssx2, dma1tx
        i += permission_wr(0xbbf81850, 0x1f);
        i += permission_wr(0xbbf81458, 0x1f);   //ssx2, dma1rx
        i += permission_wr(0xbbf81450, 0x1f);
        i += permission_wr(0xbbf80458, 0x1f);   //ssx2, usb0
        i += permission_wr(0xbbf80450, 0x1f);
        i += permission_wr(0xbbf80858, 0x1f);   //ssx2, usb0c
        i += permission_wr(0xbbf80850, 0x1f);
        i += permission_wr(0xbbf80C58, 0x1f);   //ssx2, usb1
        i += permission_wr(0xbbf80C50, 0x1f);
        i += permission_wr(0xbbf81058, 0x1f);   //ssx2, usb1c
        i += permission_wr(0xbbf81050, 0x1f);
        i += permission_wr(0xbbf82058, 0x1);    //ssx2, ln20, 1 bit for all
        i += permission_wr(0xbbf82050, 0x1);

	/*ssx3*/
        i += permission_wr(0xb9f80058, 0x1f);   //ssx3, reg3-r0 (only 4kec should access reg3-r0)
        i += permission_wr(0xb9f80050, 0x1f);
        i += permission_wr(0xb9f80078, 0x1f);   //ssx3, reg3-r1 (only 4kec should access reg3-r1)
        i += permission_wr(0xb9f80070, 0x1f);
        i += permission_wr(0xb9f81458, 0x1f);   //ssx3, pcie1
        i += permission_wr(0xb9f81450, 0x1f);
        i += permission_wr(0xb9f81858, 0x1f);   //ssx3, pcie1a
        i += permission_wr(0xb9f81850, 0x1f);
        i += permission_wr(0xb9f81C58, 0x1f);   //ssx3, pcie1c
        i += permission_wr(0xb9f81C50, 0x1f);
        i += permission_wr(0xb9f82058, 0x1f);   //ssx3, msi1
        i += permission_wr(0xb9f82050, 0x1f);
        i += permission_wr(0xb9f82458, 0x1f);   //ssx3, pcie2
        i += permission_wr(0xb9f82450, 0x1f);
        i += permission_wr(0xb9f82858, 0x1f);   //ssx3, pcie2a
        i += permission_wr(0xb9f82850, 0x1f);
        i += permission_wr(0xb9f82C58, 0x1f);   //ssx3, pcie2c
        i += permission_wr(0xb9f82C50, 0x1f);
        i += permission_wr(0xb9f83058, 0x1f);   //ssx3, msi2
        i += permission_wr(0xb9f83050, 0x1f);
        i += permission_wr(0xb9f80458, 0x1f);   //ssx3, pcie3
        i += permission_wr(0xb9f80450, 0x1f);
        i += permission_wr(0xb9f80858, 0x1f);   //ssx3, pcie3a
        i += permission_wr(0xb9f80850, 0x1f);
        i += permission_wr(0xb9f80C58, 0x1f);   //ssx3, pcie3c
        i += permission_wr(0xb9f80C50, 0x1f);
        i += permission_wr(0xb9f81058, 0x1f);   //ssx3, msi3
        i += permission_wr(0xb9f81050, 0x1f);
        i += permission_wr(0xb9f83458, 0x1);    //ssx3, ln30, 1 bit for all
        i += permission_wr(0xb9f83450, 0x1);

}


void start_interaptiv(u32 addr)
{
	u32 i = 0;

	set_permission();
	/* wait until reset finished */
	i += REG32(0xb6000014) & REG32(0xb6000024);      // Dummy command for Read Only Reset Register
	if ((REG32(0xb6000014) & 4) == 0){                      // Read status if InterAptiv Cluster in reset?
		REG32(0xb6000010) = 0x00000004;                 // If not in reset, reset it
		while ((REG32(0xb6000014) & 8) == 0);   // Wait until InterAptiv Cluster back in reset
	}

	REG32(0xb608004c) |= 0x01;                                                       
	REG32(0xb608005c) |= 0xdfffff;

	REG32(0xbf2001e0) = addr; // pointer to interaptiv normal entry program
	REG32(0xbf2001f4) = 0x56701dcb; // RVEC_INSTALLED

	REG32(0xbf2001e4) = addr; // pointer to interaptiv nmi handling program
	REG32(0xbf2001f8) = 0x45601CBA; // NVEC_INSTALLED

	REG32(0xb6000010) = 0x00000008;  // Bring InterAptiv Cluster out of reset
}
