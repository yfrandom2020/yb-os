#ifndef __KERNEL_H
#define __KERNEL_H
// The kernel header will include all the other header files of the system
// Therefore, when creating header files of new tasks it is only needed to include the kernel.h file
#include "types.h"
#include "types.h"
#include "gdt/gdt.h"
#include "port/port.h"
#include "port/pic.h"
#include "idt/idt.h"
#include "idt/util.h"
#include "idt/isr/isr.h"
#include "idt/isr/irq/irq.h"
#include "idt/isr/isrgen.h"
#define KEYBOARD_BUFFER_SIZE 128
extern "C" void fill_keyboard_buffer(uint8_t letter);
void printf(uint8_t* ptr);
#endif
