ENTRY(_start)
OUTPUT_FORMAT(elf32-i386)
OUTPUT_ARCH(i386:i386)

SECTIONS{
	. = 1M;
	.text BLOCK(4K): ALIGN(4K) {
		KEEP(*(.multiboot));
		*(.text*)
	}

	.rodata BLOCK(4K): ALIGN(4K){
		*(.rodata)
	}
	.data BLOCK(4K) : ALIGN(4K) {
		/*Global scope/static constructors*/
		start_ctors = .;
		KEEP(*( .init_array ));
		KEEP(*(SORT_BY_INIT_PRIORITY( .init_array.* )));
		end_ctors = .;

		*(.data)
	}

	.bss BLOCK(4K): ALIGN(4K){
		*(COMMON)
		*(.bss)
	}
	
	/DISCARD/ : {
		*(.fini_array*)
		*(.comment)
	}
}

