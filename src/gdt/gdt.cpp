#include "gdt.h"

// writing the constructors for the gdt table
// we need a constructor for a single entry in the table
// also descriptors for a segment: size and offset in memory

GlobalDescriptorTable::GlobalDescriptorTable()
: nullSegmentSelector(0,0,0),
unusedSegmentSelector(0,0,0),
codeSegmentSelector(0,64*1024*1024, 0x9A),
dataSegmentSelector(0,64*1024*1024, 0x92)
{
    uint32_t i[2]; // array with two elements, each sized 4 bytes total 8 bytes
    // it's loaded to the gdtr as address and size of gdt

    //there is only a single object of the class GlobalDescriptorTable, we want to load this object into the gdtr - we need to load it's address and it's size


    i[0] = (int32_t)this; // the address of the object the was just created
    i[1] = sizeof(GlobalDescriptorTable) << 16; // the size of the class

    asm volatile("lgdt (%0)": : "p" (((uint8_t *) i)+2)); // loading into the gdtr using inline assembly
}

GlobalDescriptorTable::~GlobalDescriptorTable()
{
    // destructor
    // doesn't actually gets used but defining for convention
}

uint16_t GlobalDescriptorTable::DataSegmentSelector() // return address of segment (relative)
{
    return (uint8_t*)&dataSegmentSelector - (uint8_t*)this;
    // for example if object begins in address 300 and data seg begins in 305 then the returned address will be 5, essentially this is the offset of each segment
}

uint16_t GlobalDescriptorTable::CodeSegmentSelector()
{
    return (uint8_t*)&codeSegmentSelector - (uint8_t*)this;
    // same as previous
}


GlobalDescriptorTable::SegmentDescriptor::SegmentDescriptor(uint32_t base, uint32_t limit, uint8_t flags)
{
    // this is the constructor of a single entry in the gdt table
    // each entry describes a single segment
    // parameters: base - starting address, limit - size, flags - type of segment
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
    // get the base of a segment from a single entry of the table
    // reverse the splitting action done in the entry constructor (segmentDescriptor)
    uint8_t* target = (uint8_t*)this;
    uint32_t result = target[7];
    result = (result << 8) + target[4];
    result = (result << 8) + target[3];
    result = (result << 8) + target[2];
    return result;
}

uint32_t GlobalDescriptorTable::SegmentDescriptor::Limit()
{
    // same as previous
    uint8_t* target = (uint8_t*)this;
    uint32_t result = target[6] & 0xF;
    result = (result << 8) + target[1];
    result = (result << 8) + target[0];
    if((target[6] & 0xC0) == 0xc0)
        result = (result << 12) | 0xFFF;
    return result;
}
