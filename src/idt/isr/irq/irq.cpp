// In this file we will handle the hardware interrupts received from components such as keyboard and timer
#include "irq.h"

ISRHandler irq[16];

void __attribute__((cdecl)) keyboard(Registers* state)
{
    // Keyboard isr  
    // 1. Read from the relevant port (0x60) the data of the keyboard
    // 2. Translate to ASCII
    // Forward to kernel buffers
    printf((uint8_t*)".");
    if (state->interrupt < 0xA0) PIC_sendEOI(state->interrupt - PIC1); // The input is the irq number
    else PIC_sendEOI(state->interrupt - PIC2);
}

void __attribute__((cdecl)) timer(Registers* state)
{
    // The timer interrupt is an interrupt sent by the timer in set intervals
    // There isn't much to implement since we aren't implemeting context switching


    printf((uint8_t*)".");

}

void __attribute__((cdecl)) populate_irq_entries()
{
    // The ISRHandlers array in the isr.cpp contains an array of void pointers to the ISR themselves
    

    // The current structure:
    // When an interrupt is called:
    // 1. It is searched in the idt
    // The specific ISR stub is called from within the idt (each stub defined in assembly file using macro)
    // After pushing some values, the general purpose ISR_Handler is called with the state of teh registers as input (Registers* state)

    // We populate ISRHandlers with the irqs we defined

    ISRHandlers[PIC1 + 0] = timer;
    ISRHandlers[PIC1 + 1] = keyboard;
}