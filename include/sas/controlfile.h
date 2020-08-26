/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2011-2020 Sphairon GmbH (a ZyXEL company)
 */

#ifndef __SAS_CONTROLFILE_H__
#define __SAS_CONTROLFILE_H__

enum sas_cf_state {
	CF_STARTED,
	CF_FINISHED,
	CF_FAILED,
};

int sas_cf_check_board(void);
void sas_cf_status_board(enum sas_cf_state state);
void sas_cf_run(void);
int sas_cf_is_active(void);
void sas_cf_led_action(enum sas_cf_state state);

#endif /* __SAS_CONTROLFILE_H__ */
