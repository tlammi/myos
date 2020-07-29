
.section .entry
.global _start
_start:
	jmp _loader

.section .text
.extern kernel_main
.extern call_ctors
.global _loader

_loader:
	mov $kernel_stack, %esp
	call call_ctors
	push %eax
	push %ebx
	call kernel_main

_stop:
	cli
	hlt
	jmp _stop

.section .bss
.space 2*1024*1024 # 2 MiB
kernel_stack:

