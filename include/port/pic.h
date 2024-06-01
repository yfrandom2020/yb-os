// This is a header file that contains a few variables relating to the pic.cpp file
// Pic related variables - ports of pics, as well as some commands that are sent to them

#pragma once
#include "../types.h"


#define PIC1		0x20		/* IO base address for master PIC */ // - 32
#define PIC2		0xA0		/* IO base address for slave PIC */ // - 160
#define PIC1_COMMAND	PIC1 // Command port of the master PIC
#define PIC1_DATA	(PIC1+1) // Data port of the master PIC
#define PIC2_COMMAND	PIC2 // Command port of the slave PIC
#define PIC2_DATA	(PIC2+1) // Data port of the slave PIC
#define PIC_EOI 	0x20		/* End-of-interrupt command code */
#define PIC1_BASE_IRQ           32 // the first address of pic 1 in idt. PIC1 is mapped to interrupts 32 - 39 + PIC2 is mapped to interrupt 40 - 47 
#define PIC2_BASE_IRQ           PIC1_BASE_IRQ + 8


void printf(const char* letter);
uint8_t port_inb(uint8_t portnumber);
void port_outb(uint16_t port, uint8_t data);
void port_insw(uint16_t port, void* addr, int count);
void port_outsw(uint16_t port, void* addr, int count);
extern "C" void Init_pic();
void disable_interrupt_flag();
extern "C" void Enable_interrupts();
extern "C" void PIC_sendEOI(uint8_t irq);
void interrupt_flag();