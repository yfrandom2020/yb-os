#include "gdt.h"
// https://wiki.osdev.org/Global_Descriptor_Table
// https://wiki.osdev.org/GDT_Tutorial
// Gvahim os book - pages 118 to 130
// Implmenting the constructors for the gdt table

GlobalDescriptorTable::GlobalDescriptorTable() // This is the constructor of an instance in the gdt class, each instance (we only need one) contains several segement selectors inside it
: nullSegmentSelector(0,0,0),
codeSegmentSelector(0,64*1024*1024, 0x9A),
unusedSegmentSelector(0,0,0),
dataSegmentSelector(0,64*1024*1024, 0x92)
{
    uint32_t i[2]; // Array with two elements, each sized 4 bytes total 8 bytes
    // It's loaded to the gdtr as address and size of gdt

    // There is only a single object of the class GlobalDescriptorTable, we want to load this object into the gdtr


    i[0] = (uint32_t)this; // The address of the object the was just created

    i[1] = sizeof(GlobalDescriptorTable) << 16; // The size of the class

    asm volatile("lgdt (%0)": : "p" (((uint8_t *) i)+2)); // Loading into the gdtr using inline assembly, pointer to the gdt object that was created

    printf((uint8_t*)"initialized table \n");
}

GlobalDescriptorTable::~GlobalDescriptorTable()
{
    // Destructor of the gdt object
    // Doesn't actually gets used but defining for convention
}

uint16_t GlobalDescriptorTable::DataSegmentSelector() // Return address of data segment (relative)
{
    return (uint8_t*)&dataSegmentSelector - (uint8_t*)this;
    // For example if object begins in address 300 and data seg begins in 305 then the returned address will be 5, essentially this is the offset of each segment selector from the beggining of the table
}

uint16_t GlobalDescriptorTable::CodeSegmentSelector()
{
    return (uint8_t*)&codeSegmentSelector - (uint8_t*)this;
    // Same as previous
}


GlobalDescriptorTable::SegmentDescriptor::SegmentDescriptor(uint32_t base, uint32_t limit, uint8_t flags)
{
    // Parameters in: base - starting address (still in real mode) , limit - size in bytes, flags - the different permissions
    // This is the constructor of a single entry in the gdt table
    // Each entry (called segement descriptor) describes a single segment
    // Parameters: base - starting address, limit - size, flags - type of segment
    uint8_t* target = (uint8_t*) this;

    if(limit <= 65536)
    {
        target[6] = 0x40;

    }
    else
    {
        if((limit & 0xFFF) != 0xFFF)
            limit = (limit >> 12) - 1;
        else
            limit = limit >> 12;
        target[6] = 0xC0;

    }
    target[0] = limit & 0xFF;
    target[1] = (limit >> 8) & 0xFF;
    target[6] |= (limit >> 16) & 0xF;

    target[2] = base  & 0xFF;
    target[3] = (base >> 8) & 0xFF;
    target[4] = (base >> 16) & 0xFF;
    target[7] = (base >> 24) & 0xFF;

    target[5] = flags;
}
uint32_t GlobalDescriptorTable::SegmentDescriptor::Base()
{
    // Get the base of a segment from a single entry of the table
    // Reverse the splitting action done in the entry constructor (segmentDescriptor)
    uint8_t* target = (uint8_t*)this;
    uint32_t result = target[7];
    result = (result << 8) + target[4];
    result = (result << 8) + target[3];
    result = (result << 8) + target[2];
    return result;
}

uint32_t GlobalDescriptorTable::SegmentDescriptor::Limit()
{
    // Same as previous
    uint8_t* target = (uint8_t*)this;
    uint32_t result = target[6] & 0xF;
    result = (result << 8) + target[1];
    result = (result << 8) + target[0];
    if((target[6] & 0xC0) == 0xc0)
        result = (result << 12) | 0xFFF;
    return result;
}
