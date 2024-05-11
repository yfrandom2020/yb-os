/*--------------------------------------------------------------------------------------------------------------------*/
// This is the main kernel file
// This file is the main code that gets exectuted upon booting the os
// The main function is kernelMain which will in turn call the other functions, such as IVT and PIC related function
/*--------------------------------------------------------------------------------------------------------------------*/
#include "types.h"
#include "gdt/gdt.h"
#include "port/ivt/pic.h"
#include "port/ivt/ivt.h"

extern void init_pic(); // Telling the compiler that this is a function that will be called from a different file and will appear in the linking phase

extern void enable_interrupts();
extern void PIC_sendEOI(uint8_t irq); // These are PIC related functions
extern void initIVT();

char keyboard_buffer[KEYBOARD_BUFFER_SIZE]; // initializing a keyboard buffer that will contain what is typed
int keyboard_buffer_index = 0;

void initialize_buffer()
{
    for (int i = 0; i < 128; i++)
    {
        keyboard_buffer[i] = '\0';
    }
}


// Extern "C" means that when compiling the source code, the name of the function will not be changed by the compiler
// This is done in order to call function from other files, and making sure that the names are saved

extern "C" void fill_keyboard_buffer(uint8_t letter)
{
    // This is part of the keyboard driver
    // This function will be called by the ISR when the input happens
    static int index = 0;
    if (letter == "Enter") // Enter means that the current data that was typed will be inputted as a command to the kernel. In this case we will first reset the buffer and then execute the command
    {
        index = 0;
        for (int i = 0; i < 128; i++)
        {
            keyboard_buffer[i] = "";
        }
        index = 0;
    }
    else if (index <= 127)
    {
        keyboard_buffer[index] = letter;
        printf(letter);
        index++;
    }
}

uint8_t check_buffer_status()
{
    // This function will be used by the kernel main loop to check for new input
    // This function keeps track of the keyboard buffer index and checks with it for updates
    static previous_index = 0;

    if (previous_index == keyboard_buffer_index) return '\0'; // This can only happen if there has been no output yet

}




void printf(char* str)
{
    // This is a basic printf function - a subsitute for the original c++ function
    // This function refers to a specific memory address in the RAM that prints its values to screen and writes the desired text there
    // Char* str is a pointer to the address of the "Hello world!", so it contains something like 0x00a679
    static uint16_t* VideoMemory = (uint16_t*) 0xb8000; // In the RAM, there are special addresses that when filled, print what's in them on the screen. These addresses start in 0xb800 and span for additional 80*25 bytes (the size of the screen)
    static uint8_t x = 0, y = 0;
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

    printf("Hello World! \n");

    //GlobalDescriptorTable gdt; // initialize a gdt, will only be used in the case of complete virtual memory


    // Completing a few steps before entering the main kernel loop
    // 1) Initialize the PIC
    // 2) Initialize the IVT
    // 3) Connect the drivers
    // 4) Re - enable interrupts

    initialize_buffer();
    init_pic();
    initIVT();
    printf(">");
    enable_interrupts();

    // Entering main kernel loop
    uint8_t user_data = '\0';
    while(true)
    {
        user_data = check_buffer_status();
        if (user_data != '\0')
        {


        }

    }
}

