#include <common.h>
#include <asm/io.h>
#include <mach/grx500.h>

#define SSX0_BASE 0xbff00000
#define SSX1_BASE 0xbdf00000
#define SSX2_BASE 0xbbf00000
#define SSX3_BASE 0xb9f00000
#define SSX4_BASE 0xb7f00000
#define SSX6_BASE 0xb3f00000
#define SSX7_BASE 0xa3000000

#define SSX_PM_BASE(mod) (0x80000 + mod * 0x400)
#define SSX_PM_READ_PERM(pm) (0x50 + pm * 0x20)
#define SSX_PM_WRITE_PERM(pm) (0x58 + pm * 0x20)
#define SSX_PM_ALL 0x1f
#define SSX_PM_LN 0x1

static inline void set_perm(unsigned long ssx_base, unsigned int mod,
			    unsigned int pm_val)
{
	void __iomem *base = (void __iomem *)ssx_base;

	writel(pm_val, base + SSX_PM_BASE(mod) + SSX_PM_READ_PERM(0));
	writel(pm_val, base + SSX_PM_BASE(mod) + SSX_PM_WRITE_PERM(0));
}

/*
 * Reset all SSX permissions to allow access from all CPUs. We want an open
 * system instead of this shitty pseudo security voodoo by Intel.
 */
static void reset_permissions(void)
{
	unsigned int mod;

	/*
	 * SSX0:
	 * REG0, SSB, ROM, OTP, CBM1, CBM2, E97, E123, DM3, DM4,
	 * LN01, LN02, LN03, EX04, EX05, LN06,
	 */
	for (mod = 0; mod < 15; mod++)
		set_perm(SSX0_BASE, mod, 0x1f);
	set_perm(SSX0_BASE, 15, 0x1);

	/*
	 * SSX1:
	 * REG1, DM2R, DM2T, GWPL, LN10
	 */
	for (mod = 0; mod < 4; mod++)
		set_perm(SSX1_BASE, mod, 0x1f);
	set_perm(SSX1_BASE, 4, 0x1);

	/*
	 * SSX2:
	 * REG2, US0, US0C, US1, US1C, DM1R, DM1T, GWPR, LN20
	 */
	for (mod = 0; mod < 8; mod++)
		set_perm(SSX2_BASE, mod, 0x1f);
	set_perm(SSX2_BASE, 8, 0x1);

	/*
	 * SSX3:
	 * REG3, PC3, PC3A, PC3C, MSI3, PC1, PC1A, PC1C, MSI1,
	 * PC2, PC2A, PC2C, MSI2, LN30
	 */
	for (mod = 0; mod < 13; mod++)
		set_perm(SSX3_BASE, mod, 0x1f);
	set_perm(SSX3_BASE, 13, 0x1);

	/*
	 * SSX4:
	 * REG4, CGU, RCU, PMU, PCM, GPIO, LEDC, I2C, ASC0, ASC1,
	 * GPT0, SSC0, SSC1, DM0, EBU, GPT1, GPT2
	 */
	for (mod = 0; mod < 18; mod++)
		set_perm(SSX4_BASE, mod, 0x1f);

	/*
	 * SSX6:
	 * REG6, IC, DDR, PCTL, PUB, LN60
	 */
	set_perm(SSX6_BASE, 0, 0x1f);
	set_perm(SSX6_BASE, 1, 0x3);
	set_perm(SSX6_BASE, 2, 0x3f);
	set_perm(SSX6_BASE, 3, 0x1f);
	set_perm(SSX6_BASE, 4, 0x1f);
	set_perm(SSX6_BASE, 5, 0x1f);
}

void start_interaptiv(u32 addr)
{
	u32 i = 0;

	reset_permissions();

	/* wait until reset finished */
	i += REG32(0xb6000014) &
	     REG32(0xb6000024); // Dummy command for Read Only Reset Register
	if ((REG32(0xb6000014) & 4) ==
	    0) { // Read status if InterAptiv Cluster in reset?
		REG32(0xb6000010) = 0x00000004; // If not in reset, reset it
		while ((REG32(0xb6000014) & 8) == 0)
			; // Wait until InterAptiv Cluster back in reset
	}

	REG32(0xb608004c) |= 0x01;
	REG32(0xb608005c) |= 0xdfffff;

	REG32(0xbf2001e0) = addr; // pointer to interaptiv normal entry program
	REG32(0xbf2001f4) = 0x56701dcb; // RVEC_INSTALLED

	REG32(0xbf2001e4) = addr; // pointer to interaptiv nmi handling program
	REG32(0xbf2001f8) = 0x45601CBA; // NVEC_INSTALLED

	REG32(0xb6000010) = 0x00000008; // Bring InterAptiv Cluster out of reset
}
