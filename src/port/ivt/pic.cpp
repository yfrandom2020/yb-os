#include "../port.h"
#include "../../types.h"
// this file will be the actual communication with the PIC - the programmable interrupt chip
// the PIC is what connects the cpu to the hardware devices, for example the keyboard is connected with IRQ 1
extern "C" void pic_init()
{
    // the following function initializes the pic, will be called from the kernelMain funtion

    Port8Bit pic((uint16_t)0x20); // establishing port connection with PIC
    // object is saved in stack
    pic.Write((uint8_t)0x11); // initialize the PIC

}

