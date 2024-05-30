#pragma once 

void initializers();
void initialize_buffers();
void GDT_Initialize();
extern "C" void IDT_Initialize();
extern "C" void ISR_Initialize();
void Populate_Irq_Entries();
extern "C" void Init_pic();
extern "C" void Enable_interrupts();
void ata_initialize();
void Init_ext();
