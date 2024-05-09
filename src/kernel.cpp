/*--------------------------------------------------------------------------------------------------------------------*/
// This is the main kernel file
// This file is the main code that gets exectuted upon booting the os
// The main function is kernelMain which will in turn call the other functions, such as IVT and PIC related function
/*--------------------------------------------------------------------------------------------------------------------*/
#include "types.h"
#include "gdt/gdt.h"

extern void init_pic(); // Telling the compiler that this is a function that will be called from a different file and will appear in the linking phase
extern void enable_interrupts();
extern void PIC_sendEOI(uint8_t irq); // These are PIC related functions
extern void initIVT();

// Extern "C" means that when compiling the source code, the name of the function will not be changed by the compiler
// This is done in order to call function from other files, and making sure that the names are saved


void printf(char* str)
{
    // This is a basic printf function - a subsitute for the original c++ function
    // This function refers to a specific memory address in the RAM that prints its values to screen and writes the desired text there
    // Char* str is a pointer to the address of the "Hello world!", so it contains something like 0x00a679
    static uint16_t* VideoMemory = (uint16_t*) 0xb8000; // In the RAM, there are special addresses that when filled, print what's in them on the screen. These addresses start in 0xb800 and span for additional 80*25 bytes (the size of the screen)
    static uint8_t x = 0, y = 0; // Function variables to determine what's the first vacant address that can be written to. These variables are static so they will keep their values between calls, and text won't override each other
    for (int i = 0; str[i] != '\0'; ++i)
    {
        switch(str[i])
        {
            case '\n': // New line
                y++;
                x = 0;
                break;
            default:
                VideoMemory[80*y + i] = (VideoMemory[80*y + i]&0xFF00) | str[i];
                x++;
                break;
        }
        if (x >= 80)
        {
            y++; // Next line
            x = 0;
        }
        if (y >= 25)
        {
            // No more place on screen
            for (y = 0; y < 25; y++)
                for (x = 0; x < 80; x++)
                    VideoMemory[80*y + i] = (VideoMemory[80*y + i]&0xFF00) | ' '; // Clear screen
            x = 0;
            y = 0;
        }
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

    printf("Hello World! \n"); // This is a string literal, stored somewhere in a non modifiable segment

    // Test pull
    printf("Hello World!");
    //GlobalDescriptorTable gdt; // initialize a gdt, will only be used in the case of complete virtual memory

    init_pic(); // Initialize the PIC, first step in setting up interrupts and drivers
    initIVT(); // Set up the IVT

    while(1);
}

