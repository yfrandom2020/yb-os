#include "isr.h"
#include "idt.h"
#include "gdt/gdt.h"
#include "../kernel.h"
#include "../types.h"

ISRHandler ISRHandlers[256];

static const char* const Exceptions[] = {
    "Divide by zero error",
    "Debug",
    "Non-maskable Interrupt",
    "Breakpoint",
    "Overflow",
    "Bound Range Exceeded",
    "Invalid Opcode",
    "Device Not Available",
    "Double Fault",
    "Coprocessor Segment Overrun",
    "Invalid TSS",
    "Segment Not Present",
    "Stack-Segment Fault",
    "General Protection Fault",
    "Page Fault",
    "",
    "x87 Floating-Point Exception",
    "Alignment Check",
    "Machine Check",
    "SIMD Floating-Point Exception",
    "Virtualization Exception",
    "Control Protection Exception ",
    "",
    "",
    "",
    "",
    "",
    "",
    "Hypervisor Injection Exception",
    "VMM Communication Exception",
    "Security Exception",
    ""
};

void ISR_InitializeGates();

void ISR_Initialize()
{
    ISR_InitializeGates();
    for (int i = 0; i < 256; i++)
        set_flag(i);

    disable_flag(0x80);
}

void __attribute__((cdecl)) ISR_Handler(Registers* regs)
{
    if (ISRHandlers[regs->interrupt] != NULL)
        ISRHandlers[regs->interrupt](regs);

    // else if (regs->interrupt >= 32)
    //     printf((uint8_t*)"Unhandled interrupt %d!\n", regs->interrupt);

    // Currently disabled until printf is improved
    // Printing the current state of registers in case of error
    // else
    // {
    //     printf("Unhandled exception %d %s\n", regs->interrupt, Exceptions[regs->interrupt]);

    //     printf("  eax=%x  ebx=%x  ecx=%x  edx=%x  esi=%x  edi=%x\n",
    //            regs->eax, regs->ebx, regs->ecx, regs->edx, regs->esi, regs->edi);

    //     printf("  esp=%x  ebp=%x  eip=%x  eflags=%x  cs=%x  ds=%x  ss=%x\n",
    //            regs->esp, regs->ebp, regs->eip, regs->eflags, regs->cs, regs->ds, regs->ss);

    //     printf("  interrupt=%x  errorcode=%x\n", regs->interrupt, regs->error);

    //     printf("KERNEL PANIC!\n");
    //     Panic();
    // }
}

void ISR_RegisterHandler(int interrupt, ISRHandler handler)
{
    ISRHandlers[interrupt] = handler;
    set_flag(interrupt);
}
