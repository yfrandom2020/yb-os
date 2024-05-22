#ifndef __IRQ_H
#define __IRQ_H
#include "../isr.h"
#include "../../../kernel.h"
void __attribute__((cdecl)) keyboard(Registers* state);
void __attribute__((cdecl)) keyboard(Registers* state);
void __attribute__((cdecl)) populate_irq_entries();
#endif