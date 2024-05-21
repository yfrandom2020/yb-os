# This is an assembly loader file. This file contains the data required by the GRUB in order to validate the kernel as bootable code (in the partition table)
.set MAGIC, 0x1badb002
.set FLAGS, (1<<0 | 1<<1)
.set CHECKSUM, -(MAGIC + FLAGS)
# https://www.youtube.com/watch?v=1T26DpuKnVs - a simple youtube video that explaines well the relations between MBR, boot loader (first 446 bytes of MBR), partition table (64 bytes of MBR that specify the places of boot records in other places in the hard disk), boot record (the first piece of os that usually loads the rest of the os) and kernel
# https://wiki.osdev.org/Boot_Sequence - until early enviroment section
.section .multiboot
    .long MAGIC
    .long FLAGS
    .long CHECKSUM

.section .text
.extern kernelMain # .extern tells the compiler to not worry these function don't exist yet, since they will be added in the linking process
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
.space 2*1024*1024 # Initializing the kernel stack after spacing 2 MB for additional room for code
kernel_stack:


