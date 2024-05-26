#pragma once
// The kernel header will include all the other header files of the system
// Therefore, when creating header files of new tasks it is only needed to include the kernel.h file
#include "types.h"
#include "gdt/gdt.h"
#include "port/port.h"
#include "port/pic.h"
#include "idt/idt.h"
#include "idt/util.h"
#include "idt/isr/isr.h"
#include "idt/isr/isrgen.h"
#define KEYBOARD_BUFFER_SIZE 128
#define VIDEO_MEMORY_ADDRESS 0xb8000
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
#define WHITE_ON_BLACK 0x0F
#define MAX_COMMAND_LENGTH 128
#define MAX_COMMANDS 10
typedef void (*command_func_t)(void);

typedef struct {
    const char *name;
    command_func_t func;
} __attribute__((packed)) command_t;

void clear_command();
void help_command();
void unknown_command();

extern "C" void fill_keyboard_buffer(uint8_t letter);
void printf(uint8_t* ptr);
void Populate_Irq_Entries();
void scroll();
void putchar(char c);
void printf();