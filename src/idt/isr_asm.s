# Now we need to populate the IDT and fill it with the different interrupt handlers (exceptions, keyboard, timer..)
# It's problematic to use inline assembly and write in C++ everything so we will have an assembly file that generates 255 stubs that jump to a C++ function
# Cpu pushes to the stack: ss, esp, eflags, cs, eip when having an interrupt in kernel mode which will happen most of the time


.extern ISR_Handler 

#-------------------------------------------------------------------
.macro ISR_NOERRORCODE num
.global ISR\num\()
ISR\num\():
    pushl $0              # push dummy error code
    pushl $\num            # push interrupt number
    jmp isr_common
.endm

.macro ISR_ERRORCODE num
.global ISR\num\()
ISR\num\():
                        # cpu pushes an error code to the stack
    pushl $\num           # push interrupt number
    jmp isr_common
.endm

.include "idt/isrs_gen.inc"
#----------------------------------------------------------------------- These macros are replicated - these are simple stubs for each of the 256 different interrupts - differentiated by the number
# All of these macros jump to the same place since they all push the same values before being executed

isr_common: # This is a common place all the previously generated stubs reach. First push values to save the state of the kernel before executing the ISR and then jump to it
    pusha               # Save all the values in the registers - pushes in order eax, ecx, edx, ebx, esp, ebp, esi, edi

    xor %eax, %eax      # clear eax for segment operations
    mov %ax, %ds        # clear ds
    pushl %eax          # saving only the state of data segment register

    mov $0x10, %ax      # use kernel data segment
    mov %ax, %ds
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs

    pushl %esp          # pass pointer to stack to C, so we can access all the pushed information

    # CURRENT STATE OF STACK BEFORE PUSHING
    # (STACK GROWING DOWNWARDS)
    # eax, ecx, edx, ebx, esp, ebp, esi, edi, ds, esp
    # Therefore esp has the lowest value and eax has the highest value

    call ISR_Handler
    add $4, %esp        # adjust stack pointer after ISR_Handler call

    pop %eax            # restore old segment register values
    mov %ax, %ds
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs

    popa                # pop all general-purpose registers
    add $8, %esp        # remove error code and interrupt number
    iret                # return from interrupt
