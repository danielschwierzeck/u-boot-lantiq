// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2011-2020 Sphairon GmbH (a ZyXEL company)
 */

#include <common.h>

#include <sas/util.h>

#if defined(CONFIG_ENV_IS_NOWHERE)
#define sas_has_saveenv		0
#else
#define sas_has_saveenv		1
#endif

int sas_setenv(const char *name, const char *value, int *saveenv)
{
	const char *s;
	int modified = 0, value_len = 0;

	if (value)
		value_len = strlen(value);

	s = getenv(name);
	if (s) {
		if (!value_len) {
			/* value should be removed */
			value = NULL;
			modified = 1;
		} else {
			/* value should be updated */
			modified = strcmp(s, value);
		}
	} else {
		if (!value_len) {
			/* value unchanged */
			return 0;
		} else {
			/* value should be added */
			modified = 1;
		}
	}

	if (modified && saveenv)
		*saveenv = 1;

	return setenv(name, value);
}

int sas_setenv_num(const char *name, int value, int *saveenv)
{
	char buf[32];

	sprintf(buf, "%d", value);

	return sas_setenv(name, buf, saveenv);
}

int sas_setenv_hex(const char *name, int value, int *saveenv)
{
	char buf[32];

	sprintf(buf, "0x%x", value);

	return sas_setenv(name, buf, saveenv);
}

void sas_saveenv(void)
{
	if (sas_has_saveenv)
		saveenv();
}

int sas_run_command(const char* fmt, ...)
{
	va_list args;
	char cmd[128];
	int ret;

	va_start(args, fmt);
	vsprintf(cmd, fmt, args);
	va_end(args);

	debug("sas_run_command: %s\n", cmd);

	ret = run_command(cmd, 0);

	/* error is -1, success is 0 or 1 if cmd is repeatable */
	if (ret < 0)
		return 1;

	return 0;
}

size_t sas_run_tftpboot(ulong loadaddr, const char *file)
{
	size_t filesize;
	int ret;
	const char *rootpath = getenv("rootpath");

	setenv("filesize", "0");
	ret = sas_run_command("tftpboot %08lx %s%s", loadaddr,
			      rootpath ? rootpath : "", file);
	if (ret)
		return 0;

	filesize = getenv_ulong("filesize", 16, 0);

	return filesize;
}

int sas_confirm(const char *message)
{
	char c;
	int ret;

	puts(message);
	for (;;) {
		puts("\nDo you want to continue (y|n)? :");
		c = getc();

		if (c == 'y') {
			ret = 1;
			goto done;
		}

		if (c == 'n') {
			ret = 0;
			goto done;
		}
	}

done:
	puts("\n");
	return ret;
}

static void sas_banner_repeat(char *line, unsigned int n,
					char c, char **pos)
{
	char *p = line;

	while (likely(n--))
		*p++ = c;

	*pos = p;
}

static void sas_banner_content(const char *fmt, va_list args)
{
	int n;
	char line[80];
	char *p = line;

	*p++ = '*';
	*p++ = ' ';
	n = vsprintf(p, fmt, args);
	sas_banner_repeat(p + n, 61 - n, ' ', &p);

	*p++ = '*';
	*p++ = '\n';
	*p = 0;
	puts(line);
}

void sas_banner_header_print(const char *fmt, ...)
{
	va_list args;
	char line[80];
	char *p = line;

	*p++ = '\n';
	sas_banner_repeat(p, 64, '*', &p);
	*p++ = '\n';
	*p = 0;
	puts(line);

	va_start(args, fmt);
	sas_banner_content(fmt, args);
	va_end(args);

	p = line;
	*p++ = '*';
	*p++ = ' ';
	sas_banner_repeat(p, 60, '-', &p);

	*p++ = ' ';
	*p++ = '*';
	*p++ = '\n';
	*p = 0;
	puts(line);
}

void sas_banner_content_print(const char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	sas_banner_content(fmt, args);
	va_end(args);
}

void sas_banner_footer_print(void)
{
	char line[80];
	char *p = line;

	sas_banner_repeat(p, 64, '*', &p);
	*p++ = '\n';
	*p = 0;
	puts(line);
}

void sas_banner_line_print(void)
{
	char line[80];
	char *p = line;

	*p++ = '*';
	*p++ = ' ';
	sas_banner_repeat(p, 60, '-', &p);

	*p++ = ' ';
	*p++ = '*';
	*p++ = '\n';
	*p = 0;
	puts(line);
}
