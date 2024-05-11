# to set the stack pointer
.set MAGIC, 0x1badb002
.set FLAGS, (1<<0 | 1<<1)
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
    .long MAGIC
    .long FLAGS
    .long CHECKSUM

.section .text
.extern kernelMain # .extern tells the compiler to not worry these function don't exist yet, since they will be added in the linking process (linker.ld)
.extern callConstructors
.global loader

loader:
    mov $kernel_stack, %esp # initializing kernel stack
    call callConstructors # convention
    push %eax # these registers contain some information regarding the multiboot strucure
    push %ebx
    call kernelMain # transitioning to kernel c++ function

_stop: # a never ending loop added as a security measure, in case the call command doesn't work the kernel shouldn't just stop running
    cli
    hlt
    jmp _stop


.section .bss
.space 2*1024*1024 # 2 MB
kernel_stack:


