#ifndef __KERNEL_H
#define __KERNEL_H
#include "types.h"
#include "types.h"
#include "gdt/gdt.h"
#include "port/port.h"
#include "port/pic.h"
#include "idt/idt.h"
#include "idt/isr/isr.h"
#define KEYBOARD_BUFFER_SIZE 128
extern "C" void fill_keyboard_buffer(uint8_t letter);
void printf(uint8_t* ptr);
#endif
