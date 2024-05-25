# Now we need to populate the IDT and fill it with the different interrupt handlers (exceptions, keyboard, timer..)
# Cpu pushes to the stack: ss, esp, eflags, cs, eip when having an interrupt in kernel mode which will happen most of the time

.extern ISR_Handler # The general ISR handler

#-------------------------------------------------------------------
.macro ISR_NOERRORCODE num
.global ISR\num\() # generate the global address
ISR\num\():
    pushl $0              # push dummy error code
    pushl $\num            # push interrupt number
    jmp isr_common          # a common address jumped to by all stubs before calling ISR_Handler - responsible for pushing the right values to the stack before ISR itself
.endm

.macro ISR_ERRORCODE num
.global ISR\num\()
ISR\num\():
                        # cpu pushes an error code to the stack
    pushl $\num           # push interrupt number
    jmp isr_common
.endm

.include "idt/isr/isrs_gen.inc" # Initiate macro invoking
#----------------------------------------------------------------------- These macros are replicated - these are simple stubs for each of the 256 different interrupts - differentiated by the number

isr_common:
    pusha               # Save all the values in the registers - pushes in order eax, ecx, edx, ebx, esp, ebp, esi, edi

    xor %eax, %eax      # Clear eax for segment operations
    mov %ax, %ds        # Clear ds
    pushl %eax          # Saving only the state of data segment register

    mov $0x10, %ax      # Use kernel data segment
    mov %ax, %ds
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs

    pushl %esp          # Pass pointer to stack to C, so we can access all the pushed information

    # CURRENT STATE OF STACK BEFORE PUSHING
    # (STACK GROWING DOWNWARDS)
    # eax, ecx, edx, ebx, esp, ebp, esi, edi, ds, esp
    # Therefore esp has the lowest value and eax has the highest value

    call ISR_Handler
    add $4, %esp        # adjust stack pointer after ISR_Handler call - stack works in word size

    pop %eax            # restore old segment register values
    mov %ax, %ds
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs

    popa                # pop all general-purpose registers
    add $8, %esp        # remove error code and interrupt number
    iret                # return from interrupt
