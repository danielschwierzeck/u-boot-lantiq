/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2011-2020 Sphairon GmbH (a ZyXEL company)
 */

#ifndef __SAS_UTIL_H__
#define __SAS_UTIL_H__

int sas_setenv(const char *name, const char *value, int *saveenv);

int sas_setenv_num(const char *name, int value, int *saveenv);

int sas_setenv_hex(const char *name, int value, int *saveenv);

void sas_saveenv(void);

int sas_run_command(const char* fmt, ...)
		__attribute__((format(printf, 1, 2)));

size_t sas_run_tftpboot(ulong loadaddr, const char *file);

int sas_confirm(const char *message);

void sas_banner_header_print(const char *fmt, ...)
		__attribute__((format(printf, 1, 2)));

void sas_banner_content_print(const char *fmt, ...)
		__attribute__((format(printf, 1, 2)));

void sas_banner_footer_print(void);

void sas_banner_line_print(void);

#endif /* __SAS_UTIL_H__ */
