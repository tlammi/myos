
.set ALIGN, 1 << 0
.set MEMINFO, 1 << 1
.set FLAGS, ALIGN | MEMINFO
.set MAGIC, 0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

.section .bss
.align 16
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

.section .text
.extern kernel_main
#.extern call_ctors
.global _start
.type _start @function

_start:
	mov $stack_top, %esp
	#call call_ctors
	push %eax
	push %ebx
	call kernel_main

_stop:
	cli
	hlt
	jmp _stop

.size _start, . - _start
