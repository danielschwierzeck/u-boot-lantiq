/* Copyright (c) 2019, Intel Corporation.
 *
 * PRX300 SoC anti rollback ID implementation
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
*/

#include <common.h>
#include <lantiq.h>

u32 get_rbid_spl(void)
{
    u32 rb_id   = 0;
    u32 rb_bits = 0;

    /* only consider bits 0:15 as uboot+fsb rollback bits*/
    rb_bits = REG32(0xb6180130) & 0x0000FFFFUL;

    if (rb_bits == 0xFFFFFFFFUL)
        rb_id = 32; // safety against undefine ffz when no 0
    else
        /* the index of first zero coincidentally also count the number of consecutive trailing bit 1 */
        rb_id = ffz(rb_bits);

    return rb_id;
}

u32 get_rbid_uboot(void)
{
    u32 rb_id   = 0;
    u32 rb_bits = 0;

    /* only consider bits 0:15 as uboot+fsb rollback bits*/
    rb_bits = REG32(0xb6180130) & 0x0000FFFFUL;

    if (rb_bits == 0xFFFFFFFFUL)
        rb_id = 32; // safety against undefine ffz when no 0
    else
        /* the index of first zero coincidentally also count the number of consecutive trailing bit 1 */
        rb_id = ffz(rb_bits);

    return rb_id;
}

u32 get_rbid_tos(void)
{
    u32 rb_id   = 0;
    u32 rb_bits = 0;

    /* only consider bits 16:31 as tos rollback bits*/
    rb_bits = (REG32(0xb6180130) & 0xFFFF0000UL) >> 16;

    if (rb_bits == 0xFFFFFFFFUL)
        rb_id = 32; // safety against undefine ffz when no 0
    else
        /* the index of first zero coincidentally also count the number of consecutive trailing bit 1 */
        rb_id = ffz(rb_bits);

    return rb_id;
}
