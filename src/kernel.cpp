/*--------------------------------------------------------------------------------------------------------------------*/
// This is the main kernel file
// This file is the main code that gets exectuted upon booting the os
// The main function is kernelMain which will in turn call the other functions, such as IDT and PIC related function
// Realistically, this os follows a monolythic kernel design so all processes are level 0
/*--------------------------------------------------------------------------------------------------------------------*/
#include "kernel.h"
#include "initializers.h"

int8_t* commands[1] = {nullptr}; // An array where each element is a pointer to a char

void clear_screen() 
{
    // QEMU prints some text to screen about boot device
    // Before doing any actions, clear screen
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            VideoMemory[y * SCREEN_WIDTH + x] = (WHITE_ON_BLACK << 8) | ' ';
        }
    }
    // Reset cursor position
    x = 0;
    y = 0;
    printf(">", 0);  // Add '>' at the beginning of a new line
}


void help_command() 
{
    printf("hello \n", 0);
    printf(">", 0);  // Add '>' at the beginning of a new line
}

void unknown_command() 
{
    printf("Error \n", 0);
    printf(">", 0);  // Add '>' at the beginning of a new line
}




// Extern "C" means that when compiling the source code, the name of the function will not be changed by the compiler
// This is done in order to call function from other files, and making sure that the names are saved
void fill_keyboard_buffer(uint8_t letter)
{
    static int32_t index = 0;
    // This is part of the keyboard driver
    // This function will be called by the ISR when the input happens
    command_buffer[index] = letter;
    // Enter means that the current data that was typed will be inputted as a command to the kernel. In this case we will first reset the buffer and then execute the command
    keyboard_buffer[index] = letter;
    if (index < 127)
    {
        index++;
    }
    if (letter == '\n')
    {
        index = 0;
    }
}


// Conventions
typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors()
{
    for(constructor* i = &start_ctors; i != &end_ctors; i++)
        (*i)();
}


extern "C" void kernelMain(void* multiboot_structure, uint32_t magicnumber)
{
    // This is the kernelMain function - the main function of the kernel and the os
    // This function is the first to run and is the one called from the loader.s file
    
    clear_screen();
    
    initializers();
    
    printf(">",0);

    // Entering main kernel loop

    while (true)
    {
        continue;
    }
    
}

