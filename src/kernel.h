#ifndef __KERNEL_H
#define __KERNEL_H
#include "types.h"
#define KEYBOARD_BUFFER_SIZE 128
extern "C" void fill_keyboard_buffer(uint8_t letter);
void printf(char* ptr);
#endif