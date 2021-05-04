/*
 * Copyright (c) 2018, Intel Corporation.
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

void sso_init(void);
int sso_output(int gpio, u32 value, u8 duty_cycle);
int sso_output_all(u32 value, u8 duty_cycle);
