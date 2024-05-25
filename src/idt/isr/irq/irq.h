#pragma once
#include "../isr.h"
#include "../../../port/pic.h"
void Keyboard(Registers* state);
void Timer(Registers* state);
void Populate_Irq_Entries();
uint8_t port_inb(uint8_t portnumber);
void port_outb(uint16_t port, uint8_t data);