#include "idt/idt.h"
// Apparently the weird structure of the table (also in GDT) is caused because of the need of backwards compatability that messes things up

idt_entry IDT[256]; // The actual IDT table - an array sized 256 with each element being an idt_entry struct

idt_descriptor idtr = {sizeof(IDT) - 1, IDT}; // A struct that contains the information about the IDT - it's size and it's initial offset

extern "C" void idt_set_gate(int interrupt, void* base, uint16_t segment_descriptor, uint8_t flags)
{
    // Base - a pointer to the function (isr) - it contains the address of the function
    // Initialize a single gate (gate is the name for a single entry in the this table)
    IDT[interrupt].offset_low = ((uint32_t)base) & 0xFFFF; // Taking the lower 16 bits of the offset
    IDT[interrupt].segment_selector = segment_descriptor; // Since in the IDT the segment section is continuous we can simply load it directly
    IDT[interrupt].Reserved = 0;
    IDT[interrupt].Flags = flags;
    IDT[interrupt].offset_high = ((uint32_t)base >> 16) & 0xFFFF;
}

extern "C" void IDT_Initialize()
{

    // Loading the address and size of IDT to the idtr register using inline assembly
    // Will be called from the kernel main
    asm volatile("lidt (%0)" : : "p" (&idtr));
}

// The following two function enable and disable the "present" flag in a single idt entry
extern "C" void set_flag(int interrupt)
{
    FLAG_SET(IDT[interrupt].Flags, idt_flag_present);
}

extern "C" void disable_flag(int interrupt)
{
    FLAG_UNSET(IDT[interrupt].Flags, idt_flag_present);
}

