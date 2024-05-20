# In the IDT file we defined and implemented the IDT
# Now we need to populate this table and fill it with the different interrupt handlers (exceptions, keybaord, timer..)
# It's problematic to use inline assembly and write in C++ everything so we will have an assembly file that generates 255 stubs that jump to a C++ function
# Cpu pushes to the stack: ss, esp, eflags, cs, eip
%include "isrs_gen.inc"


.extern ISR_Handler
%macro ISR_NOERRORCODE 1

.global ISR%1:
ISR%1:
    push 0              # push dummy error code
    push %1             # push interrupt number
    jmp isr_common

%endmacro

%macro ISR_ERRORCODE 1
global ISR%1:
ISR%1:
                        # cpu pushes an error code to the stack
    push %1             # push interrupt number
    jmp isr_common

%endmacro

isr_common:
    pusha               # pushes in order eax, ecx, edx, ebx, esp, ebp, esi, edi

    xor %eax, %eax        # push ds
    mov %ax, %ds
    push %eax

    mov %ax, 0x10        # use kernel data segment
    mov %ds, %ax
    mov %es, %ax
    mov %fs, %ax
    mov %gs, %ax

    push %esp            # pass pointer to stack to C, so we can access all the pushed information
    call ISR_Handler
    add %esp, 4

    pop %eax             # restore old segment
    mov %ds, %ax
    mov %es, %ax
    mov %fs, %ax
    mov %gs, %ax

    popa                # pop what we pushed with pusha
    add %esp, 8          # remove error code and interrupt number
    iret                # will pop cs, eip, eflags, ss, esp