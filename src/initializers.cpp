#include "initializers.h"

void initializers()
{
    // Completing a few steps before entering the main kernel loop
    // 1) Initialize the PIC
    // 2) Initialize the IDT
    // 3) Connect the drivers
    // 4) Re - enable interrupts
    // 5) Initialize the disk

    
    GDT_Initialize(); 

    IDT_Initialize(); // Loading the idt into idtr - the array exists

    ISR_Initialize();

    Populate_Irq_Entries(); // Filling in the ISRHandlers array

    Init_pic(); // Init_pic also masks all interrups

    Enable_interrupts();


    //ata_initialize(); // Initialize disk

    //Init_ext();
}