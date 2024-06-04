#pragma once
#include <idt/isr/isr.h>
#include <port/pic.h>

void Keyboard(Registers* state);
void Timer(Registers* state);
void Disk(Registers* state);
void Populate_Irq_Entries();