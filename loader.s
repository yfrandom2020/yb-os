# to set the stack pointer
.set MAGIC, 0x1badb002
.set FLAGS, (1<<0 | 1<<1)
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
    .long MAGIC
    .long FLAGS
    .long CHECKSUM

.section .text
.extern kernelMain
.extern callConstructors
.global loader

loader:
    mov $kernel_stack, %esp # initializing stack
    call callConstructors
    push %eax
    push %ebx
    call kernelMain # transitioning to kernel action

_stop:
    cli
    hlt
    jmp _stop


.section .bss
.space 2*1024*1024 # 2 MB
kernel_stack:


