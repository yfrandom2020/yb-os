#ifndef __ISR_H
#define __ISR_H
#include "../types.h"
#include "idt.h"
#include "../gdt/gdt.h"
#include "../kernel.h"


typedef struct
{
    // A useful struct that is used to represnt the values of the registers when pushed into the stack
    
    uint32_t ds;                                            // data segment pushed by us
    uint32_t edi, esi, ebp, useless, ebx, edx, ecx, eax;    // pusha
    uint32_t interrupt, error;                              // we push interrupt, error is pushed automatically (or dummy)
    uint32_t eip, cs, eflags, esp, ss;                      // pushed automatically by CPU
} __attribute__((packed)) Registers;

typedef void (*ISRHandler)(Registers* regs); // We define a new type - ISRHANDLER is a pointer to a void function that receives the Registers struct as input

void ISR_Initialize();
void ISR_RegisterHandler(int interrupt, ISRHandler handler);
void __attribute__((cdecl)) ISR_Handler(Registers* regs); // cdecl is a calling convention in function. The way it works is that variables are pushed to the stack from right to left and the function is responsible for cleaning in the end of the run

#endif