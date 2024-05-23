#ifndef __IRQ_H
#define __IRQ_H
#include "../isr.h"
#include "../../../port/pic.h"
#include "../../../kernel.h"

typedef struct
{
    // A useful struct that is used to represnt the values of the registers when pushed into the stack
    // The general ISR_Handler receives a struct of this type and using the values inside it, it deciphers which ISR was called

    uint32_t ds;                                            // data segment pushed by us
    uint32_t edi, esi, ebp, useless, ebx, edx, ecx, eax;    // pusha
    uint32_t interrupt, error;                              // we push interrupt, error is pushed automatically (or dummy)
    uint32_t eip, cs, eflags, esp, ss;                      // pushed automatically by CPU
} __attribute__((packed)) Registers;

void keyboard(Registers* state);
void timer(Registers* state);
void populate_irq_entries();
#endif