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

void printf(uint8_t* letter);
static inline uint8_t inb(uint8_t portnumber);
static inline void outb(uint16_t port, uint8_t data);
extern "C" void init_pic();
extern "C" void enable_interrupts();
extern "C" void PIC_sendEOI(uint8_t irq);
