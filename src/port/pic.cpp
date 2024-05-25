#include "port.h"
#include "../types.h"
#include "pic.h"


// This file will be the actual communication with the PIC - the programmable interrupt chip
// The PIC is what connects the cpu to the hardware devices, for example the keyboard is connected with IRQ 1
// https://wiki.osdev.org/8259_PIC

uint8_t port_inb(uint8_t portnumber)
{
     uint8_t result;
     __asm__ volatile("inb %1, %0" : "=a" (result) : "Nd" ((uint16_t)portnumber));
     return result;
}


void port_outb(uint16_t port, uint8_t data)
{
     __asm__ volatile("outb %0, %1" : : "a" (data), "Nd" (port));
}


extern "C" void init_pic()
{
    // Send initializing commands to the two PICs

    printf((uint8_t*)"entered init_pic \n");
    uint16_t ICW1_INIT = 0x10; // ICW - initialization command word
    uint16_t ICW4_8086 = 0x01;


    // Initialize PIC1
    port_outb(PIC1_COMMAND, ICW1_INIT | ICW4_8086);
    port_outb(PIC1_DATA, PIC1_BASE_IRQ); // PIC1 base IRQ is 0x20 - this translates to telling the PIC that it's idt offset starts with the number 0x20 which is 32. This is because the first 32 (0 - 31) entries of the IVT are reserved for the compiler. They contain entries related to compiler errors and other things
    port_outb(PIC1_DATA, 0x04); // Tell PIC1 that there is a slave PIC at IRQ2 (0000 0100)
    port_outb(PIC1_DATA, 0x01); // 8086 mode


    // Initialize PIC2
    port_outb(PIC2_COMMAND, ICW1_INIT | ICW4_8086);
    port_outb(PIC2_DATA, PIC2_BASE_IRQ); // PIC2 base IRQ is 0x28
    port_outb(PIC2_DATA, 0x02); // Tell PIC2 its cascade identity (0000 0010)
    port_outb(PIC2_DATA, 0x01); // 8086 mode


    // Mask all interrupts
    //outb(PIC1_DATA, 0xFF);
    //outb(PIC2_DATA, 0xFF);
    // This is a convention process done at the initialization process
    // In order to prevent spurios IRQ the interrupts sent to the PIC's are disabled until the system is fully booted and only then are enabled

    printf((uint8_t*)"ended init_pic \n");
}

void interrupt_flag()
{
    asm volatile("sti");
}

extern "C" void enable_interrupts()
{
    // Unmask interrupts on PIC1 and PIC2
    port_outb(PIC1_DATA, 0x00); // Unmask all interrupts on PIC1
    port_outb(PIC2_DATA, 0x00); // Unmask all interrupts on PIC2
    interrupt_flag();
    
}


extern "C" void PIC_sendEOI(uint8_t irq)
{
    // When the cpu finishes dealing with the interrupt it sends an EOI (end of interrupt) to the PIC that sent it
    // If from master -> only to master
    // If from slave -> both master and slave
	if(irq >= 8)
		port_outb(PIC2_COMMAND,PIC_EOI);
	port_outb(PIC1_COMMAND,PIC_EOI);
}

