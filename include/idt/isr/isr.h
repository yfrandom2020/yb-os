// After preparing the IDT (an array containing ISR) we need to load the ISR's into it
// In order to implement ISR (interrupt service routine) we need to do a few things

// Each ISR is a simple and short function that does a small task
// There is a problem: we can't use inline assembly since it's risky and might corrupt the stack
// Therefore we will have a small assembly stub that pushes specific values and then calls a general ISR handling function (aka ISR_Handler)
#pragma once

#include "types.h"
#include "idt/idt.h"
#include "gdt/gdt.h"
#include "idt/isr/isrgen.h"
#include <stddef.h>

void printf(uint8_t* ptr, int flag);

typedef struct
{
    // A useful struct that is used to represnt the values of the registers when pushed into the stack
    // The general ISR_Handler receives a struct of this type and using the values inside it, it deciphers which ISR was called

    uint32_t ds;                                            // data segment pushed by us
    uint32_t edi, esi, ebp, useless, ebx, edx, ecx, eax;    // pusha
    uint32_t interrupt, error;                              // we push interrupt, error is pushed automatically (or dummy)
    uint32_t eip, cs, eflags, esp, ss;                      // pushed automatically by CPU
} __attribute__((packed)) Registers;

typedef void (*ISRHandler)(Registers* regs); // We define a new type - ISRHANDLER is a pointer to a void function that receives the Registers struct as input
extern "C" void ISR_Initialize();
void ISR_RegisterHandler(int interrupt, ISRHandler handler);
extern "C" void __attribute__((cdecl)) ISR_Handler(Registers* regs); // cdecl is a calling convention in function. The way it works is that variables are pushed to the stack from right to left and the function is responsible for cleaning in the end of the run
