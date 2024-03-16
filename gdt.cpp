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
    i[0] = (int32_t)this;
    i[1] = sizeof(GlobalDescriptorTable) << 16;

    asm volatile("lgdt (%0)": : "p" (((uint8_t *) i)+2));
}

GlobalDescriptorTable::~GlobalDescriptorTable()
{
    // destructor
    // doesn't actually gets used but defining for convention
}

uint16_t GlobalDescriptorTable::DataSegmentSelector() // return address of segment
{
    return (uint8_t*)&dataSegmentSelector - (uint8_t*)this;
}

uint16_t GlobalDescriptorTable::CodeSegmentSelector()
{
    return (uint8_t*)&codeSegmentSelector - (uint8_t*)this;
}


GlobalDescriptorTable::SegmentSelector::SegmentSelector(uint32_t base, uint32_t limit, uint8_t flags)
{
    uint8_t* target = (uint8_t*) this;

    if(limit <= 65536)
    {
        target[6] = 0x40;

    }
    else
    {

    }

}
