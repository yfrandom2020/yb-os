/*--------------------------------------------------------------------------------------------------------------------*/
// This is the main kernel file
// This file is the main code that gets exectuted upon booting the os
// The main function is kernelMain which will in turn call the other functions, such as IDT and PIC related function
// Realistically, this os follows a monolythic kernel design so all processes are level 0
/*--------------------------------------------------------------------------------------------------------------------*/
#include <kernel.h>
#include <initializers.h>

void clear_screen() 
{
    // QEMU prints some text to screen about boot device
    // Before doing any actions, clear screen
    for (int y = 0; y < SCREEN_HEIGHT; y++) 
    {
        for (int x = 0; x < SCREEN_WIDTH; x++) 
        {
            VideoMemory[y * SCREEN_WIDTH + x] = (WHITE_ON_BLACK << 8) | ' ';
        }
    }
    // Reset cursor position
    x = 0;
    y = 0;
    printf((uint8_t*)">", 0);  
}

void ben_dover()
{
    printf((uint8_t*)"sapoj cutie \n",0);
    printf((uint8_t*)">", 0);  
}

void shut_down() // test shut down - when qemu sits on specific port
{
    Port32Bit qemu(0xf4);
    qemu.Write(0x10);
    printf((uint8_t*)"\nShutting down FridkinOS... \n",0);
    //loop_flag = false;
}

void help_command() 
{
    printf((uint8_t*)"hello \n", 0);
    printf((uint8_t*)">", 0); 
}

void unknown_command() 
{
    printf((uint8_t*)"error \n", 0);
    printf((uint8_t*)">", 0);  
}

void *memset(void *ptr, int value, size_t num) 
{
    unsigned char *p = (unsigned char *)ptr;
    unsigned char v = (unsigned char)value;

    for (size_t i = 0; i < num; i++) {
        *p++ = v;
    }

    return ptr;
}


// Extern "C" means that when compiling the source code, the name of the function will not be changed by the compiler
// This is done in order to call function from other files, and making sure that the names are saved

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
    
    ata0m.Identify();
    //ata0m.Write28(100, (uint8_t*)"ata test", 8);
    //ata0m.Flush();
    //ata0m.Read28(0, 512);


    while (true)
    {
        if (loop_flag) continue;
        else break;
    } 
}

