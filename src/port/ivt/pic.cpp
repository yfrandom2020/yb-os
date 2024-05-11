#include "../port.h"
#include "../../types.h"
#include "pic.h"


// This file will be the actual communication with the PIC - the programmable interrupt chip
// The PIC is what connects the cpu to the hardware devices, for example the keyboard is connected with IRQ 1


static inline uint8_t inb(uint8_t portnumber)
{
     uint8_t result;
     __asm__ volatile("inb %1, %0" : "=a" (result) : "Nd" (portnumber));
     return result;
}


static inline void outb(uint16_t port, uint8_t data)
{
     __asm__ volatile("outb %0, %1" : : "a" (data), "Nd" (port));
}


extern "C" void init_pic()
{
    // Send initializing commands to the two PICs


    uint16_t ICW1_INIT = 0x10; // ICW - initialization command word
    uint16_t ICW4_8086 = 0x01;


    // Initialize PIC1
    outb(PIC1_COMMAND, ICW1_INIT | ICW4_8086);
    outb(PIC1_DATA, 0x20); // PIC1 base IRQ is 0x20 - this translates to telling the PIC that it's ivt offset starts with the number 0x20 which is 32. This is because the first 32 (0 - 31) entries of the IVT are reserved for the compiler. They contain entries related to compiler errors and other things
    outb(PIC1_DATA, 0x04); // Tell PIC1 that there is a slave PIC at IRQ2 (0000 0100)
    outb(PIC1_DATA, 0x01); // 8086 mode


    // Initialize PIC2
    outb(PIC2_COMMAND, ICW1_INIT | ICW4_8086);
    outb(PIC2_DATA, 0x28); // PIC2 base IRQ is 0x28
    outb(PIC2_DATA, 0x02); // Tell PIC2 its cascade identity (0000 0010)
    outb(PIC2_DATA, 0x01); // 8086 mode


    // Mask all interrupts
    outb(PIC1_DATA, 0xFF);
    outb(PIC2_DATA, 0xFF);
    // This is a convention process done at the initialization process
    // In order to prevent spurios IRQ the interrupts sent to the PIC's are disabled until the system is fully booted and only then are enabled
}


extern "C" void enable_interrupts()
{
    // Unmask interrupts on PIC1 and PIC2
    outb(PIC1_DATA, 0x00); // Unmask all interrupts on PIC1
    outb(PIC2_DATA, 0x00); // Unmask all interrupts on PIC2
}


extern "C" void PIC_sendEOI(uint8_t irq)
{
    // When the cpu finishes dealing with the interrupt it sends an EOI (end of interrupt) to the PIC that sent it
    // If from master -> only to master
    // If from slave -> both master and slave
	if(irq >= 8)
		outb(PIC2_COMMAND,PIC_EOI);
	outb(PIC1_COMMAND,PIC_EOI);
}

