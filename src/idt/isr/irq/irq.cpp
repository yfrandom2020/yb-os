// In this file we will handle the hardware interrupts received from components such as keyboard and timer
#include <idt/isr/irq/irq.h>
#include <port/port.h>

Port8Bit keyboard_port((uint8_t)0x60);
extern uint64_t up_time;

uint8_t scancode_to_ascii(uint8_t scancode) {
    // Simple scan code to ASCII conversion table for alphanumeric keys
    
    static const char scancode_table[128] = {
        0,  27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',  // 0x00 - 0x0F
        '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',   // 0x10 - 0x1C
        0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0,       // 0x1D - 0x29
        '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0, '*', 0,       // 0x2A - 0x35
        ' ', 0                                                                  // 0x36 - 0x37 (Space at 0x39)
    };

    if (scancode < 128) {
        return scancode_table[scancode];
    }
    return 0;
}

void Keyboard(Registers* state)
{
    // Keyboard isr  
    // 1. Read from the relevant port (0x60) the data of the keyboard
    // 2. Translate to ASCII
    // Forward to kernel buffers
    uint8_t data = keyboard_port.Read();
    data = scancode_to_ascii(data);
    char buffer[2] = {data, '\0'};
    printf(buffer, 1); // print character
    PIC_sendEOI(state->interrupt - PIC1); // number of irq
}

void Timer(Registers* state)
{
    // The timer interrupt is an interrupt sent by the timer in set intervals
    // There isn't much to implement since we aren't implemeting context switching
    up_time++;
    PIC_sendEOI(state->interrupt - PIC1); // number of irq
}

void Disk(Registers* state)
{
    // This ISR will handle the disk communication
    // To communicate with the disk we first initialize it using port communication
    

    PIC_sendEOI(state->interrupt - PIC2); // finish ISR routine

}

void Populate_Irq_Entries()
{
    // The ISRHandlers array in the isr.cpp contains an array of void pointers to the ISR themselves
    

    // The current structure:
    // When an interrupt is called:
    // 1. It is searched in the idt
    // The specific ISR stub is called from within the idt (each stub defined in assembly file using macro)
    // After pushing some values, the general purpose ISR_Handler is called with the state of teh registers as input (Registers* state)

    // We populate ISRHandlers with the irqs we defined
    ISR_RegisterHandler(PIC1_BASE_IRQ, Timer);
    ISR_RegisterHandler(PIC1_BASE_IRQ + 1, Keyboard);
    ISR_RegisterHandler(PIC2_BASE_IRQ + 7, Disk); // Disk connected to IRQ 14 (or 15) depends if IDE is primary or secondary
}
