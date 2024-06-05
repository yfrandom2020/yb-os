// #include "gdt.h"
// // https://wiki.osdev.org/Global_Descriptor_Table
// // https://wiki.osdev.org/GDT_Tutorial
// // Gvahim os book - pages 118 to 130
// // Implmenting the constructors for the gdt table

// GlobalDescriptorTable::GlobalDescriptorTable() // This is the constructor of an instance in the gdt class, each instance (we only need one) contains several segement selectors inside it
// : nullSegmentSelector(0,0,0),
// codeSegmentSelector(0,64*1024*1024, 0x9A),
// dataSegmentSelector(0,64*1024*1024, 0x92)
// {
//     uint32_t i[2]; // Array with two elements, each sized 4 bytes total 8 bytes
//     // It's loaded to the gdtr as address and size of gdt

//     // There is only a single object of the class GlobalDescriptorTable, we want to load this object into the gdtr


//     i[0] = (uint32_t)this; // The address of the object the was just created

//     i[1] = sizeof(GlobalDescriptorTable) << 16; // The size of the class

//     asm volatile("lgdt (%0)": : "p" (((uint8_t *) i)+2)); // Loading into the gdtr using inline assembly, pointer to the gdt object that was created

//     printf((uint8_t*)"initialized table \n");
// }

// GlobalDescriptorTable::~GlobalDescriptorTable()
// {
//     // Destructor of the gdt object
//     // Doesn't actually gets used but defining for convention
// }

// uint16_t GlobalDescriptorTable::DataSegmentSelector() // Return address of data segment (relative)
// {
//     return (uint8_t*)&dataSegmentSelector - (uint8_t*)this;
//     // For example if object begins in address 300 and data seg begins in 305 then the returned address will be 5, essentially this is the offset of each segment selector from the beggining of the table
// }

// uint16_t GlobalDescriptorTable::CodeSegmentSelector()
// {
//     return (uint8_t*)&codeSegmentSelector - (uint8_t*)this;
//     // Same as previous
// }


// GlobalDescriptorTable::SegmentDescriptor::SegmentDescriptor(uint32_t base, uint32_t limit, uint8_t flags)
// {
//     // Parameters in: base - starting address (still in real mode) , limit - size in bytes, flags - the different permissions
//     // This is the constructor of a single entry in the gdt table
//     // Each entry (called segement descriptor) describes a single segment
//     // Parameters: base - starting address, limit - size, flags - type of segment
//     uint8_t* target = (uint8_t*) this;

//     if(limit <= 65536)
//     {
//         target[6] = 0x40;

//     }
//     else
//     {
//         if((limit & 0xFFF) != 0xFFF)
//             limit = (limit >> 12) - 1;
//         else
//             limit = limit >> 12;
//         target[6] = 0xC0;

//     }
//     target[0] = limit & 0xFF;
//     target[1] = (limit >> 8) & 0xFF;
//     target[6] |= (limit >> 16) & 0xF;

//     target[2] = base  & 0xFF;
//     target[3] = (base >> 8) & 0xFF;
//     target[4] = (base >> 16) & 0xFF;
//     target[7] = (base >> 24) & 0xFF;

//     target[5] = flags;
// }
// uint32_t GlobalDescriptorTable::SegmentDescriptor::Base()
// {
//     // Get the base of a segment from a single entry of the table
//     // Reverse the splitting action done in the entry constructor (segmentDescriptor)
//     uint8_t* target = (uint8_t*)this;
//     uint32_t result = target[7];
//     result = (result << 8) + target[4];
//     result = (result << 8) + target[3];
//     result = (result << 8) + target[2];
//     return result;
// }

// uint32_t GlobalDescriptorTable::SegmentDescriptor::Limit()
// {
//     // Same as previous
//     uint8_t* target = (uint8_t*)this;
//     uint32_t result = target[6] & 0xF;
//     result = (result << 8) + target[1];
//     result = (result << 8) + target[0];
//     if((target[6] & 0xC0) == 0xc0)
//         result = (result << 12) | 0xFFF;
//     return result;
// }

#include "gdt/gdt.h"
#include "types.h"

typedef struct
{
    uint16_t LimitLow;                  // limit (bits 0-15)
    uint16_t BaseLow;                   // base (bits 0-15)
    uint8_t BaseMiddle;                 // base (bits 16-23)
    uint8_t Access;                     // access
    uint8_t FlagsLimitHi;               // limit (bits 16-19) | flags
    uint8_t BaseHigh;                   // base (bits 24-31)
} __attribute__((packed)) GDTEntry;

typedef struct
{
    uint16_t Limit;                     // sizeof(gdt) - 1
    GDTEntry* Ptr;                      // address of GDT
} __attribute__((packed)) GDTDescriptor;

typedef enum
{
    GDT_ACCESS_CODE_READABLE                = 0x02,
    GDT_ACCESS_DATA_WRITEABLE               = 0x02,

    GDT_ACCESS_CODE_CONFORMING              = 0x04,
    GDT_ACCESS_DATA_DIRECTION_NORMAL        = 0x00,
    GDT_ACCESS_DATA_DIRECTION_DOWN          = 0x04,

    GDT_ACCESS_DATA_SEGMENT                 = 0x10,
    GDT_ACCESS_CODE_SEGMENT                 = 0x18,

    GDT_ACCESS_DESCRIPTOR_TSS               = 0x00,

    GDT_ACCESS_RING0                        = 0x00,
    GDT_ACCESS_RING1                        = 0x20,
    GDT_ACCESS_RING2                        = 0x40,
    GDT_ACCESS_RING3                        = 0x60,

    GDT_ACCESS_PRESENT                      = 0x80,

} GDT_ACCESS;

typedef enum 
{
    GDT_FLAG_64BIT                          = 0x20,
    GDT_FLAG_32BIT                          = 0x40,
    GDT_FLAG_16BIT                          = 0x00,

    GDT_FLAG_GRANULARITY_1B                 = 0x00,
    GDT_FLAG_GRANULARITY_4K                 = 0x80,
} GDT_FLAGS;

// Helper macros
#define GDT_LIMIT_LOW(limit)                (limit & 0xFFFF)
#define GDT_BASE_LOW(base)                  (base & 0xFFFF)
#define GDT_BASE_MIDDLE(base)               ((base >> 16) & 0xFF)
#define GDT_FLAGS_LIMIT_HI(limit, flags)    ((((limit >> 16) & 0xF) | ((flags) & 0xF0)))
#define GDT_BASE_HIGH(base)                 ((base >> 24) & 0xFF)

#define GDT_ENTRY(base, limit, access, flags) {                     \
    GDT_LIMIT_LOW(limit),                                           \
    GDT_BASE_LOW(base),                                             \
    GDT_BASE_MIDDLE(base),                                          \
    access,                                                         \
    GDT_FLAGS_LIMIT_HI(limit, flags),                               \
    GDT_BASE_HIGH(base)                                             \
}

GDTEntry g_GDT[] = {
    // NULL descriptor
    GDT_ENTRY(0, 0, 0, 0),

    // Kernel 32-bit code segment
    GDT_ENTRY(0,
              0xFFFFF,
              GDT_ACCESS_PRESENT | GDT_ACCESS_RING0 | GDT_ACCESS_CODE_SEGMENT | GDT_ACCESS_CODE_READABLE,
              GDT_FLAG_32BIT | GDT_FLAG_GRANULARITY_4K),

    // Kernel 32-bit data segment
    GDT_ENTRY(0,
              0xFFFFF,
              GDT_ACCESS_PRESENT | GDT_ACCESS_RING0 | GDT_ACCESS_DATA_SEGMENT | GDT_ACCESS_DATA_WRITEABLE,
              GDT_FLAG_32BIT | GDT_FLAG_GRANULARITY_4K),

};

GDTDescriptor g_GDTDescriptor = { sizeof(g_GDT) - 1, g_GDT};

extern "C" void __attribute__((cdecl)) GDT_Load(GDTDescriptor* descriptor, uint16_t codeSegment, uint16_t dataSegment);

void GDT_Initialize()
{
    GDT_Load(&g_GDTDescriptor, GDT_CODE_SEGMENT, GDT_DATA_SEGMENT);
}
