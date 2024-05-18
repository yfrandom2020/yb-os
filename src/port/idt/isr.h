
#pragma once
#include "../../types.h"

typedef struct
{
    // in the reverse order they are pushed:
    uint32_t ds;                                            // data segment pushed by us
    uint32_t edi, esi, ebp, useless, ebx, edx, ecx, eax;    // pusha
    uint32_t interrupt, error;                              // we push interrupt, error is pushed automatically (or our dummy)
    uint32_t eip, cs, eflags, esp, ss;                      // pushed automatically by CPU
} __attribute__((packed)) Registers;

typedef void (*ISRHandler)(Registers* regs);

void ISR_Initialize();
void ISR_RegisterHandler(int interrupt, ISRHandler handler);
void __attribute__((cdecl)) ISR_Handler(Registers* regs); // cdecl is a calling convention in function. The way it works is that variables are pushed to the stack from right to left and the function is responsible for cleaning in the end of the run

