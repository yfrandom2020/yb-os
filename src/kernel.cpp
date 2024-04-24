#include "types.h"
#include "gdt/gdt.h"
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
            case '\n':
                y++;
                x = 0;
                break;
            default:
                VideoMemory[i] = (VideoMemory[i]&0xFF00) | str[i];
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
                    VideoMemory[i] = (VideoMemory[i]&0xFF00) | ' ';


            x = 0;
            y = 0;
        }


    }

}

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
    printf("Hello World! \n"); // this is a string literal, stored somewhere in a non modifiable segment

    // test pull
    printf("Hello World!");
    GlobalDescriptorTable gdt;
    while(1);
}

