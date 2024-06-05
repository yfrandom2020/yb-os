/*--------------------------------------------------------------------------------------------------------------------*/
// This is the main kernel file
// This file is the main code that gets exectuted upon booting the os
// The main function is kernelMain which will in turn call the other functions, such as IDT and PIC related function ()
// Realistically, this os follows a monolythic kernel design so all processes are level 0
/*--------------------------------------------------------------------------------------------------------------------*/
#include <kernel.h>
#include <initializers.h>

uint8_t x = 0;
uint8_t y = 0;
uint8_t up_time = 0;
int command_length = 0;
ata ata0m(true, 0x1F0);

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

void printDecimal()
{
    // Define a buffer to store the decimal representation
    uint8_t buffer[6]; // Max 5 digits for a 16-bit value + null terminator
    
    // Initialize variables
    int i = 0;
    uint16_t temp = up_time;
    
    // Handle special case when up_time is 0
    if (temp == 0) {
        buffer[i++] = '0';
    } else {
        // Iterate to extract each digit
        while (temp != 0) {
            // Extract the least significant digit
            uint16_t digit = temp % 10;
            
            // Convert the digit to ASCII and store it in the buffer
            buffer[i++] = digit + '0';
            
            // Move to the next digit
            temp /= 10;
        }
    }
    
    // Add null terminator to the end of the buffer
    buffer[i] = '\0';
    
    // Reverse the buffer
    int len = i;
    for (i = 0; i < len / 2; i++) {
        char temp = buffer[i];
        buffer[i] = buffer[len - i - 1];
        buffer[len - i - 1] = temp;
    }
    
    // Print the decimal representation
    printf(buffer,0);
}

void uptime()
{
    printf((uint8_t*)"the OS is up for: ",0);
    printfHex(up_time / 10);
    printf((uint8_t*)" seconds \n",0);
    printf((uint8_t*)">",0);
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
    // This simply calls initalizers and then enters a never ending loop
    
    initializers();
    //uint8_t ptr[512];
    //ata0m.Read28(2,512,ptr);
    //printf(ptr,0);
    
    for (int i = 0; i < 10; i++)
    {
        i--;
    }
}

