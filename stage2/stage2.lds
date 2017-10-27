OUTPUT_FORMAT("elf32-tradbigmips")
OUTPUT_ARCH(mips)
ENTRY(_start)

SECTIONS
{
  .text : {
        *(.text)
	*(.rodata)
	*(.rodata1)
	*(.rodata.str1.4)
        }
  .reginfo : { *(.reginfo) }

  .date : {
	*(.data)
	}
  
  _gp = ALIGN(16);
  .got : { *(.got) }
  . = ALIGN(16);
  .bss  : {
	*(.dynbss)
	*(.bss)
  }
  
   stage2_end = .;

}
