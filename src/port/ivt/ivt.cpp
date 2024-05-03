#include "../port.h"
// this file will be the actual communication with the PIC

Port8Bit PIC = new Port8Bit(0x20); // establishing port connection with PIC
PIC.Write(0x11); // initialize the PIC
