ENTRY(_start)
OUTPUT_FORMAT(elf32-i386)
OUTPUT_ARCH(i386:i386)
/*OUTPUT_FORMAT(elf64-x86-64)*/

SECTIONS{
	. = 0x1000;
	.text : {
		*(.entry)
		. = ALIGN(8);
		KEEP(*(.multiboot));
		*(.text*)
		*(.rodata)
	}

	.data : {
		/*Global scope/static constructors*/
		start_ctors = .;
		KEEP(*( .init_array ));
		KEEP(*(SORT_BY_INIT_PRIORITY( .init_array.* )));
		end_ctors = .;

		*(.data)
	}

	.bss : {
		*(.bss)
	}
	
	/DISCARD/ : {
		*(.fini_array*)
		*(.comment)
	}
}

