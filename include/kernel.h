// Kernel header
// The kernel header will include all the other header files
// Therefore, when creating header files of new tasks it is only needed to include the kernel.h file
#pragma once
#include <types.h>
#include "gdt/gdt.h"
#include "port/port.h"
#include "port/pic.h"
#include "idt/idt.h"
#include "idt/util.h"
#include "idt/isr/isr.h"
#include "idt/isr/isrgen.h"
#include "fat16/disk.h"
#include "fat16/fat16.h"

#define KEYBOARD_BUFFER_SIZE 128
#define VIDEO_MEMORY_ADDRESS 0xb8000 // Special address in RAM that when written to prints on screen
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
#define WHITE_ON_BLACK 0x0F
#define MAX_COMMAND_LENGTH 128
#define MAX_COMMANDS 10

extern uint8_t up_time = 0;
typedef void (*command_func_t)(void); // pointer to a void function that takes no arguments

uint16_t* VideoMemory = (uint16_t*) VIDEO_MEMORY_ADDRESS;
extern uint8_t x = 0, y = 0;

char command_buffer[MAX_COMMAND_LENGTH]; // printing related - a buffer to store the characters written 
int command_length = 0;

bool loop_flag = true;


void *memset(void *ptr, int value, size_t num);
int strcmp(const char *str1, const char *str2);
void clear_screen();
void help_command();
void printDecimal();
void unknown_command();
void ben_dover();

void shut_down();
void uptime();

void printf(uint8_t* ptr, int flag);
void Populate_Irq_Entries();

typedef struct 
{
    // This struct describes the configuration for a single command recognized by the kernel
    // Each instruction has a corresponding function that is called by the execute_command 
    const char *name;
    command_func_t func;
} __attribute__((packed)) command_t;

const command_t all_commands[MAX_COMMANDS] = 
{
    {"clear", clear_screen},
    {"hello", help_command},
    {"ben dover", ben_dover},
    {"shut down", shut_down},
    {"up time", printDecimal},
    {"unknown", unknown_command}
};




void execute_command() 
{
    command_buffer[command_length] = '\0'; // add a terminator in the end
    int found = 0;

    for (int i = 0; i < MAX_COMMANDS; i++) 
    {
        if (strcmp(command_buffer, all_commands[i].name) == 0) 
        {
            all_commands[i].func();
            found = 1;
            command_length = 0;
            return;
        }
    }

    if (!found) {
        unknown_command();
    }

    // Clear the command buffer
    command_length = 0;
}

void scroll() 
{
    // Instead of clearing the entire terminal we shift everything one line down
    for (int i = 0; i < SCREEN_HEIGHT - 1; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            VideoMemory[i * SCREEN_WIDTH + j] = VideoMemory[(i + 1) * SCREEN_WIDTH + j];
        }
    }
    for (int j = 0; j < SCREEN_WIDTH; j++) {
        VideoMemory[(SCREEN_HEIGHT - 1) * SCREEN_WIDTH + j] = (WHITE_ON_BLACK << 8) | ' ';
    }
    y = SCREEN_HEIGHT - 1;
    x = 0;
}


void putchar(char c, int flag) 
{
    // Print a single character to screen
    // Using static variables x and y to determine position in the video memory
    // Flag 1 for normal prints - flag zero for prints emitted from handler functions
    switch (c) {
        case '\n':
            x = 0;
            y++;
            if (flag == 1) execute_command();
            if (y >= SCREEN_HEIGHT) 
            {
                scroll();
            }
            break;
        default:
            if (c != '>') 
            {
                if (flag == 1) command_buffer[command_length++] = c;
                //printf("not a >, adding to buffer", 0);
            }
            VideoMemory[y * SCREEN_WIDTH + x] = (WHITE_ON_BLACK << 8) | c;
            x++;
            break;
    }

    if (x >= SCREEN_WIDTH) {
        x = 0;
        y++;
    }
    if (y >= SCREEN_HEIGHT) {
        scroll();
    }
}

// Basic printf function to print a string
void printf(uint8_t* str, int flag) 
{
    // Flag is a general parameter that indicates if call is from user or from kernel
    // If from user (1) we activate the keyboard buffer and invoke the commands list
    // Else pass
    // Future - add support of variables %d, %s
    for (int i = 0; str[i] != '\0'; i++) {
        putchar(str[i], flag);
    }
}


void printfHex(uint8_t key)
{
    uint8_t* foo = (uint8_t*)"00";
    uint8_t* hex = (uint8_t*)"0123456789ABCDEF";
    foo[0] = hex[(key >> 4) & 0xF];
    foo[1] = hex[key & 0xF];
    printf(foo,0);
}


