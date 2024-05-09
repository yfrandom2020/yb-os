// This file will define the IVT (interrupt vector table)
// The IVT is saved at the beggining of the RAM, in address 0x00
// The table is 1024 bytes long, stretching to 0x003FF
// The table contains 256 entries with each entry being a far pointer sized 4 bytes
// Each pointer points to a different interrupt handler - a code somewhere else in the RAM that handles this specific interrupt


// Define the Interrupt Vector Table (IVT) at a specific address
void (*IVT[256])() __attribute__((section(".ivt"))); // Tell the compiler that this will be saved in a special section named .ivt that will come at the beggining of the linked kernel file - in address 0x0
// Creating an array with 256 objects, where each object is a pointer to a void function that takes and returns no arguments (the ISR)


// Define Interrupt Service Routines (ISRs)
extern "C" void isr0()
{
    // Handle interrupt 0
}

extern "C" void isr1()
{
    // Handle interrupt 1
}

extern "C" void isr2()
{
    // Handle interrupt 2
}

extern "C" void isr3()
{
    // Handle interrupt 3
}

extern "C" void isr4()
{
    // Handle interrupt 4
}

extern "C" void isr5()
{
    // Handle interrupt 5
}

extern "C" void isr6()
{
    // Handle interrupt 6
}

extern "C" void isr7()
{
    // Handle interrupt 7
}

extern "C" void isr8()
{
    // Handle interrupt 8
}
extern "C" void isr9()
{
    // Handle interrupt 9
}


extern "C" void isr10()
{
    // Handle interrupt 10
}
extern "C" void isr11()
{
    // Handle interrupt 11
}
extern "C" void isr12()
{
    // Handle interrupt 12
}
extern "C" void isr13()
{
    // Handle interrupt 13
}
extern "C" void isr14()
{
    // Handle interrupt 14
}
extern "C" void isr15()
{
    // Handle interrupt 15
}
extern "C" void isr16()
{
    // Handle interrupt 16
}
extern "C" void isr17()
{
    // Handle interrupt 17
}
extern "C" void isr18()
{
    // Handle interrupt 18
}
extern "C" void isr19()
{
    // Handle interrupt 19
}
extern "C" void isr20()
{
    // Handle interrupt 20
}
extern "C" void isr21()
{
    // Handle interrupt 21
}
extern "C" void isr22()
{
    // Handle interrupt 22
}
extern "C" void isr23()
{
    // Handle interrupt 23
}
extern "C" void isr24()
{
    // Handle interrupt 24
}
extern "C" void isr25()
{
    // Handle interrupt 25
}
extern "C" void isr26()
{
    // Handle interrupt 26
}
extern "C" void isr27()
{
    // Handle interrupt 27
}
extern "C" void isr28()
{
    // Handle interrupt 28
}
extern "C" void isr29()
{
    // Handle interrupt 29
}
extern "C" void isr30()
{
    // Handle interrupt 30
}
extern "C" void isr31()
{
    // Handle interrupt 31
}


// Initialize the IVT with ISR addresses
extern "C" void initIVT()
{
    IVT[0] = isr0;
    IVT[1] = isr1;
    IVT[2] = isr2;
    IVT[3] = isr3;
    IVT[4] = isr4;
    IVT[5] = isr5;
    IVT[6] = isr6;
    IVT[7] = isr7;
    IVT[8] = isr8;
    IVT[9] = isr9;
    IVT[10] = isr10;
    IVT[11] = isr11;
    IVT[12] = isr12;
    IVT[13] = isr13;
    IVT[14] = isr14;
    IVT[15] = isr15;
    IVT[16] = isr16;
    IVT[17] = isr17;
    IVT[18] = isr18;
    IVT[19] = isr19;
    IVT[20] = isr20;
    IVT[21] = isr21;
    IVT[22] = isr22;
    IVT[23] = isr23;
    IVT[24] = isr24;
    IVT[25] = isr25;
    IVT[26] = isr26;
    IVT[27] = isr27;
    IVT[28] = isr28;
    IVT[29] = isr29;
    IVT[30] = isr30;
    IVT[31] = isr31;

}

