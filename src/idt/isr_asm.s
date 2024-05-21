# In the IDT file we defined and implemented the IDT
# Now we need to populate this table and fill it with the different interrupt handlers (exceptions, keybaord, timer..)
# It's problematic to use inline assembly and write in C++ everything so we will have an assembly file that generates 255 stubs that jump to a C++ function
# Cpu pushes to the stack: ss, esp, eflags, cs, eip
# %include "isrs_gen.inc"


# .extern ISR_Handler # Telling the compiler it's an outer function that will be added in link time

# #-------------------------------------------------------------------
# %macro ISR_NOERRORCODE 1 # The following macro works for interrupts without error code (that the cpu pushes in addition to the esp and eflags), it generates a global address named isr%1 in which you push to the stack the interrupt number and then jump to the isr_handler
# .global ISR%1:
# ISR%1:
#     push 0              # push dummy error code
#     push %1             # push interrupt number
#     jmp isr_common

# %endmacro

# %macro ISR_ERRORCODE 1
# global ISR%1:
# ISR%1:
#                         # cpu pushes an error code to the stack
#     push %1             # push interrupt number
#     jmp isr_common

# %endmacro
# #----------------------------------------------------------------------- These macros are replicated - these are simple stubs for each of the 256 different interrups - differentiated by the number
# # All of these macros jump to the same place since they all push the same values before being executed


# isr_common: # This is a common place all the previously generates stubs reach. First push values to save the state of the kernel before executign the ISR and then jump to it
    
#     pusha               # Save all the values in the registers - pushes in order eax, ecx, edx, ebx, esp, ebp, esi, edi

#     xor %eax, %eax        # push ds
#     mov %ax, %ds
#     push %eax              # saving only the state of data segment register

#     mov %ax, 0x10        # use kernel data segment
#     mov %ds, %ax
#     mov %es, %ax
#     mov %fs, %ax
#     mov %gs, %ax

#     push %esp            # pass pointer to stack to C, so we can access all the pushed information


#     # CURRENT STATE OF STACK BEFORE PUSHING
#     # (STACK GROWING DOWNWARDS)

#     # eax, ecx, edx, ebx, esp, ebp, esi, edi, ds, esp
#     # Therefore esp has the lowest value and eax has the highest value

#     call ISR_Handler
#     add %esp, 4 # points to values previously pushed before ISR_HANDLER

#     pop %eax             # restore old segment
#     mov %ds, %ax
#     mov %es, %ax
#     mov %fs, %ax
#     mov %gs, %ax

#     popa                # pop what we pushed with pusha
#     add %esp, 8          # remove error code and interrupt number
#     iret                # The difference between ret and iret is that iret also pops the eflags that the cpu pushes








#------------------------------------------------------------------------------------------------------------------
# In the IDT file we defined and implemented the IDT
# Now we need to populate this table and fill it with the different interrupt handlers (exceptions, keyboard, timer..)
# It's problematic to use inline assembly and write in C++ everything so we will have an assembly file that generates 255 stubs that jump to a C++ function
# Cpu pushes to the stack: ss, esp, eflags, cs, eip


.extern ISR_Handler # Telling the compiler it's an outer function that will be added in link time

#-------------------------------------------------------------------
.macro ISR_NOERRORCODE num
    .global ISR\num
ISR\num:
    pushl $0              # push dummy error code
    pushl $num            # push interrupt number
    jmp isr_common
.endm

.macro ISR_ERRORCODE num
    .global ISR\num
ISR\num:
                        # cpu pushes an error code to the stack
    pushl $num           # push interrupt number
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
