// this is a header file that contains a few variables relating to the pic.cpp file

#define PIC1		0x20		/* IO base address for master PIC */
#define PIC2		0xA0		/* IO base address for slave PIC */
#define PIC1_COMMAND	PIC1 // command port of the master PIC
#define PIC1_DATA	(PIC1+1) // data port of the master PIC
#define PIC2_COMMAND	PIC2 // command port of the slave PIC
#define PIC2_DATA	(PIC2+1) // data port of the slave PIC
#define PIC_EOI 	0x20		/* End-of-interrupt command code */
