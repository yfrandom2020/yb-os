// this file will define the IVT (interrupt vector table)
// the IVT is saved at the beggining of the RAM, in address 0x00
// the table is 1024 bytes long, stretching to 0x003FF
// the table contains 256 entries with each entry being a far pointer sized 4 bytes
// each pointer points to a different interrupt handler - a code somewhere else in the RAM that handles this specific interrupt

// Define the Interrupt Vector Table (IVT) at a specific address
void (*IVT[256])() __attribute__((section(".ivt"))); // tell the compiler that this will be saved in a special section named .ivt that will come at the beggining of the linked kernel file

// Define Interrupt Service Routines (ISRs)
extern "C" void ISR0() {
    // Handle interrupt 0
}

extern "C" void ISR1() {
    // Handle interrupt 1
}

// Initialize the IVT with ISR addresses
extern "C" void initIVT() {
    IVT[0] = ISR0;
    IVT[1] = ISR1;
    // Initialize other interrupt vectors as needed
}

