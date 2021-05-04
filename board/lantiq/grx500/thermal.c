#include <asm/io.h>
#include <config.h>
#include <lq_thermal.h>

#define  TS_CTRL_REG 0x16080100
#define  TS_DATA_REG 0x16080104

/* Temp sensor control register */
#define SOC		0x00000001
#define	SOC_MASK	1 << 0
#define	AVG_SEL		0x00000006
#define	TSOVH_INT_EN	0x00000008
#define	CH_SEL		0x00000700
#define	CH_SEL_OFFSET	0x8
#define	TS_EN		0x00000800
#define	TS_EN_MASK	1 << 11
#define	INT_LVL		0xFFFF0000

/* Temp sensor data (read out) register */
#define	TS_CODE		0x00000FFF
#define	TS_DV		0x80000000

#define CRITICAL_TEMPERATURE_HYSTERESIS 10000  /* mC*/

static void  lq_tsens_init(struct thermal_data *priv)
{
	u32 reg;

	reg = readl(priv->ctrl_reg);
	reg &= ~(SOC | TSOVH_INT_EN);	/* stop conversion, disable IRQ */
	reg |= TS_EN;			/* power down TS */
	writel(reg, priv->ctrl_reg);
	udelay(20);			/* wait 1 TS_clk cycles to ensure TS
					   is down */
	reg &= ~TS_EN;			/* power on TS */
	writel(reg, priv->ctrl_reg);
	udelay(160);			/* required by TS spec */

	reg |= SOC;
	writel(reg, priv->ctrl_reg);
	udelay(100);			/* 5 TS_clk cycles before we put
					   TS down */
	reg &= ~SOC;			/*stop conversion*/
	reg |= TS_EN;			/*power down TS*/
	writel(reg, priv->ctrl_reg);
}

int read_cpu_temperature(struct thermal_data *priv)
{
	u32 reg;
	bool ready = false;
	int T, v;
	int a0 = -40;
	int v1 = 3800;
	int v2 = 3421;

	/* Select a channel */
	reg = readl(priv->ctrl_reg);
	reg &= ~CH_SEL;
	reg |= 1<<CH_SEL_OFFSET; /* FIXME: Hardcoded channel 1 */
		writel(reg, priv->ctrl_reg);

	/* Enable the temp sensor */
	reg = readl(priv->ctrl_reg);
	reg |= SOC_MASK;
	reg &= ~TS_EN; /* enables TS */
	writel(reg, priv->ctrl_reg);

	/* Wait for and read out the measurement */
	while(!ready) {
		reg = readl(priv->data_reg);
		if ((reg & TS_DV) > 0) ready = true;
	}

	v = reg & TS_CODE;

	/* Disable the temp sensor */
	reg = readl(priv->ctrl_reg);
	reg &= ~SOC;
	reg |= TS_EN_MASK;
	writel(reg, priv->ctrl_reg);

	/* Temperature interpolation */
	T = (int)(a0 * 1000000 + (-435356 * (v - v1)) +
		  (-360 * (v - v1) * (v - v2)) + 1);

	return T/1000;  /* returns °mC */
}

void lq_thermal_init()
{
	driver_data.ctrl_reg = (unsigned int *)TS_CTRL_REG;
	driver_data.data_reg = (unsigned int *)TS_DATA_REG;
	driver_data.max = CONFIG_GRX500_THERMAL_MAX_THRESHOLD;
	driver_data.critical = driver_data.max - CRITICAL_TEMPERATURE_HYSTERESIS;

	lq_tsens_init(&driver_data);
}

