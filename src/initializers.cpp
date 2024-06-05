#include "initializers.h"

void initializers()
{
    // Completing a few steps before entering the main kernel loop
    // 1) Initialize the PIC
    // 2) Initialize the IDT
    // 3) Connect the drivers
    // 4) Re - enable interrupts
    // 5) Initialize the disk

    clear_screen();
    
    GDT_Initialize(); 

    IDT_Initialize(); // Loading the idt into idtr - the array exists

    ISR_Initialize();

    Populate_Irq_Entries(); // Filling in the ISRHandlers array, only physical connections: keyboard and timer

    Init_pic(); 

    ata0m.Identify();

    Read_MBR();

    readBootSector();

    Enable_interrupts();
    //ata_initialize(); // Initialize disk

    //Init_ext();
}