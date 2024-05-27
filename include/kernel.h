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
typedef void (*command_func_t)(void); // pointer to a void function that takes no arguments

uint16_t* VideoMemory = (uint16_t*) VIDEO_MEMORY_ADDRESS;
uint8_t x = 0, y = 0;
char command_buffer[MAX_COMMAND_LENGTH];
int command_length = 0;
int8_t keyboard_buffer[KEYBOARD_BUFFER_SIZE]; // Initializing a keyboard buffer that will contain what is typed
int32_t keyboard_buffer_index = 0;
void clear_screen();
void help_command();
void unknown_command();


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
    // Add more commands here
    {"unknown", unknown_command}
};


int strcmp(const char *str1, const char *str2) 
{
    // Compare between two strings and return wether they are equal or not    
    while (*str1 && (*str1 == *str2)) 
    {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}


void initialize_buffers()
{
    // Set the keyboard and command buffer to zero
    for (int32_t i = 0; i < 128; i++)
    {
        keyboard_buffer[i] = '\0';
        command_buffer[i] = '\0';
    }
}


void execute_command() {
    command_buffer[command_length] = '\0'; // Null-terminate the command
    int found = 0;

    for (int i = 0; i < MAX_COMMANDS; i++) 
    {
        if (strcmp(command_buffer, all_commands[i].name) == 0) 
        {
            all_commands[i].func();
            found = 1;
            command_length = 0;
            return;
            break;
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


void putchar(char c) 
{
    // Print a single character to screen
    // Using static variables x and y to determine position in the video memory
    switch (c) {
        case '\n':
            x = 0;
            y++;
            execute_command();
            if (y >= SCREEN_HEIGHT) {
                scroll();
            }
            break;
        default:
            command_buffer[command_length++] = c;
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
void printf(const char* str) 
{
    // Use putcher to iterate over string a print it
    // Future - add support of variables %d, %s
    for (int i = 0; str[i] != '\0'; i++) {
        putchar(str[i]);
    }
}


void printf(uint8_t* ptr);
void Populate_Irq_Entries();
void scroll();
void putchar(char c);
void printf();