/*
 * (C) Copyright 2003
 * Wolfgang Denk Engineering, <wd@denx.de>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

/*
OUTPUT_FORMAT("elf32-bigmips", "elf32-bigmips", "elf32-bigmips")
*/
OUTPUT_FORMAT("elf32-tradbigmips", "elf32-tradbigmips", "elf32-tradbigmips")
OUTPUT_ARCH(mips)
ENTRY(_start)
SECTIONS
{
   /*. = 0xa0600050;*/
   . = 0xbe220050; 
   . = ALIGN(4);
   .text       :
   {
     *(.text)
   }

   . = ALIGN(4);
   .rodata  : { *(.rodata) }

   . = ALIGN(16);
   _gp = ABSOLUTE(.);
   .got : { *(.got) }
   
   _etext = ABSOLUTE(.);

   .data 0x9fc00000 : 
   AT( _etext )
   {
      _fdata = ABSOLUTE(.);
      *(.data)
      *(.sdata)
 
      . = ALIGN(4);
      _edata = ABSOLUTE(.);
   }   

   . = ALIGN(4);
   _fbss = .;

   .sbss  : { *(.sbss) }
   .bss  : { *(.bss) }

   /* This is the MIPS specific mdebug section.  */
   .mdebug : { *(.mdebug) }
   /* These are needed for ELF backends which have not yet been
      converted to the new style linker.  */
   .stab 0 : { *(.stab) }
   .stabstr 0 : { *(.stabstr) }
   /* DWARF debug sections.
      Symbols in the .debug DWARF section are relative to the beginning of the
      section so we begin .debug at 0.  It's not clear yet what needs to happen
      for the others.   */
   .debug          0 : { *(.debug) }
   .debug_srcinfo  0 : { *(.debug_srcinfo) }
   .debug_aranges  0 : { *(.debug_aranges) }
   .debug_pubnames 0 : { *(.debug_pubnames) }
   .debug_sfnames  0 : { *(.debug_sfnames) }
   .line           0 : { *(.line) }
   /* These must appear regardless of  .  */
   .gptab.sdata : { *(.gptab.data) *(.gptab.sdata) }
   .gptab.sbss : { *(.gptab.bss) *(.gptab.sbss) }
}
