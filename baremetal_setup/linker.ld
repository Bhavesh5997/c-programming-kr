ENTRY(_start)

MEMORY
{
	IMEM(rx) : ORIGIN = 0xA0000000, LENGTH = 64K
	DMEM(rwx) : ORIGIN = 0xA0020000, LENGTH = 64K
}

DMEM_START = ORIGIN(DMEM);
DMEM_END = ORIGIN(DMEM) + LENGTH(DMEM) - 1;

SECTIONS
{
	.text : {
		start_text = .;
		. = ALIGN(4);
		*(.text)
		. = ALIGN(4);
		end_text = .;
	} > IMEM

	.rodata : {
		. = ALIGN(4);
		start_rodata = .;
		*(.rodata)
		. = ALIGN(4);
		end_rodata = .;
	} > IMEM

	.data : {
		. = ALIGN(4);
		start_data = .;
		*(.data)
		. = ALIGN(4);
		end_data = .;
	} > DMEM

	.bss : {
		. = ALIGN(4);
		start_bss = .;
		*(.sbss)
		*(.bss)
		. = ALIGN(4);
		end_bss = .;
	} > DMEM

	heap_size = 0x00000100;
	.heap : {
		. = ALIGN(4);
		start_heap = .;
		. = . + heap_size;
		. = ALIGN(4);
		end_heap = .;
	} > DMEM

	. = . + 0x00000004;
	stack_size = DMEM_END - .;
	.stack : {
		. = ALIGN(4);
		end_stack = .;
		. = . + stack_size ;
		. = ALIGN(4);
		start_stack = .;
	} > DMEM
}
