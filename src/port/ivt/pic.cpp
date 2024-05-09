#include "../port.h"
#include "../../types.h"
#include "pic.h"
// this file will be the actual communication with the PIC - the programmable interrupt chip
// the PIC is what connects the cpu to the hardware devices, for example the keyboard is connected with IRQ 1

extern "C" void pic_init()
{
    // the following function initializes the pic, will be called from the kernelMain funtion

    Port8Bit pic((uint16_t)0x20); // establishing port connection with PIC

    pic.Write((uint8_t)0x11); // initialize the PIC
}

void init_pic() {


     //Port8Bit pic((uint16_t)PIC1); // establishing port connection with PIC, the master port

    //pic.Write((uint8_t)0x11); // initialize the PIC

    uint16_t ICW1_INIT = 0x10; // ICW - initialization command word
    uint16_t ICW4_8086 = 0x01;
    // Initialize PIC1
    outb(PIC1_COMMAND, ICW1_INIT | ICW4_8086);
    outb(PIC1_DATA, 0x20); // PIC1 base IRQ is 0x20
    outb(PIC1_DATA, 0x04); // Tell PIC1 that there is a slave PIC at IRQ2 (0000 0100)
    outb(PIC1_DATA, 0x01); // 8086 mode

    // Initialize PIC2
    outb(PIC2_COMMAND, ICW1_INIT | ICW4_8086);
    outb(PIC2_DATA, 0x28); // PIC2 base IRQ is 0x28
    outb(PIC2_DATA, 0x02); // Tell PIC2 its cascade identity (0000 0010)
    outb(PIC2_DATA, 0x01); // 8086 mode

    // Mask all interrupts
    //outb(PIC1_DATA, 0xFF);
    //outb(PIC2_DATA, 0xFF);
}

void PIC_sendEOI(uint8_t irq)
{
    // when the cpu finishes dealing with the interrupt it sends an EOI to the PIC that sent it
    // if from master -> only to master
    // if from slave -> both master and slave
	if(irq >= 8)
		outb(PIC2_COMMAND,PIC_EOI);

	outb(PIC1_COMMAND,PIC_EOI);
}

