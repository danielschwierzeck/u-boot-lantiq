/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2011-2020 Sphairon GmbH (a ZyXEL company)
 */

#ifndef __SAS_ETL_H__
#define __SAS_ETL_H__

#include <sas/etl_user.h>
#include <sas/flashlayout.h>

/**
 * sas_etl_init - initialize ETL subsystem
 */
void sas_etl_init(void);
int sas_etl_load(void);

int sas_etl_flash_read(unsigned long addr);
int sas_etl_flash_write(unsigned long addr);
int sas_etl_flash_erase(void);
int sas_etl_import(unsigned long addr);
int sas_etl_export(unsigned long addr);

void sas_etl_env_set_ethaddr(int *save_env);
void sas_etl_env_save(int *save_env);

const char *sas_etl_get_string(enum sas_etl_id idx);
int sas_etl_get_integer(enum sas_etl_id idx);
unsigned long sas_etl_get_hex(enum sas_etl_id idx, unsigned int len);
void sas_etl_set_string(enum sas_etl_id idx, const char *val);
void sas_etl_set_integer(enum sas_etl_id idx, int val);
void sas_etl_set_hex(enum sas_etl_id idx, unsigned int len, unsigned long val);

void sas_etl_print(void);
void sas_etl_dump(void);

int sas_etl_version(void);
void sas_etl_version_set_default(void);
enum sas_flash_layout_type sas_etl_flash_layout(void);
size_t sas_etl_data_part_size(void);
enum sas_data_part_loc sas_etl_data_part_loc(void);
unsigned int sas_etl_base_platform(void);

const char *sas_etl_id_str(enum sas_etl_id idx);
enum sas_etl_id sas_etl_id_parse(const char *str);

int sas_etl_set_value(enum sas_etl_id idx, const char *str);

#endif /* __SAS_ETL_H__ */
