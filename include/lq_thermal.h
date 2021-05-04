#ifndef _LQ_THERMAL_H_
#define _LQ_THERMAL_H_

#include <config.h>

struct thermal_data {
	unsigned int *ctrl_reg;
	unsigned int *data_reg;
	int critical;
	int min;
	int max;
};

struct thermal_data driver_data;

#ifdef CONFIG_GRX500_THERMAL
void lq_thermal_init(void);
int read_cpu_temperature(struct thermal_data *priv);
#else
void lq_thermal_init(void) {}
int read_cpu_temperature(struct thermal_data *priv) {return 0;}
#endif /* CONFIG_GRX500_THERMAL */


#endif	/* _LQ_THERMAL_H_ */
