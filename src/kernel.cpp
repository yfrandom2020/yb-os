#include "types.h"
#include "gdt/gdt.h"
// This is the main kernel file
// this file is the main code that gets exectuted upon booting the os
// // the main function is kernelMain which will in turn call the other functions
void printf(char* str)
{
    // char* str is a pointer to the address of the "Hello world!", so it contains something like 0x00a679
    // now we want to have a pointer to the video memory address
    // pointer to 0xb8000
    static uint16_t* VideoMemory = (uint16_t*) 0xb8000; // right side is like saying int* x where x is 0xb8000
    static uint8_t x = 0, y = 0;
    for (int i = 0; str[i] != '\0'; ++i)
    {
        switch(str[i])
        {
            case '\n': // new line
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
            y++; // next line
            x = 0;
        }
        if (y >= 25)
        {
            // no more place on screen
            for (y = 0; y < 25; y++)
                for (x = 0; x < 80; x++)
                    VideoMemory[80*y + i] = (VideoMemory[80*y + i]&0xFF00) | ' '; // clear screen
            x = 0;
            y = 0;
        }
    }
}

// conventions

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
    // this is the kernelMain function - the main function of the kernel and the os
    // this function is the first to run and is the one called from the loader.s file

    printf("Hello World! \n"); // this is a string literal, stored somewhere in a non modifiable segment

    // test pull
    printf("Hello World!");
    GlobalDescriptorTable gdt; // initialize a gdt, will only be used in the case of complete virtual memory


    while(1);
}

