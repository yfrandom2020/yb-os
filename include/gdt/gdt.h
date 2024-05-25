// #ifndef __GDT_H
// #define __GDT_H
// #include "../types.h"
// void printf(uint8_t* letter);

// // this is the global descriptor table
// // the global descriptor table is the first step (out of two with the second being implmenting paging) in implementing virtualization
// // the gdt (global descriptor table) replaces the idea of segment registers that describe a single segment and instead contains multiple entries called segment selectors with each one describing a different segment, as well as different levels of protections




// // declare the header file and include the types header
// // defining the gdt class, as well as a segment class inside

//     class GlobalDescriptorTable // a class that represents the gdt table
//     {
//         public:
//             // class that describes a single entry in the table
//             class SegmentDescriptor
//             {
//             private: // attributes of each single entry, according to the strcuture of the gdt table
//                 uint16_t limit_lo;
//                 uint16_t base_lo;
//                 uint8_t base_hi;
//                 uint8_t type;
//                 uint8_t flags_limit_hi;
//                 uint8_t base_vhi;

//             public:
//                 SegmentDescriptor(uint32_t base, uint32_t limit, uint8_t type); // constructor of entry
//                 uint32_t Base(); // getters
//                 uint32_t Limit();
//             } __attribute__((packed)); // don't change anything when compiling - don't allow the compilation process to make small changes and move around bytes

//         // initializing segments
//         SegmentDescriptor nullSegmentSelector;
//         SegmentDescriptor codeSegmentSelector;
//         // initially one code segment and one data segment for the kernel space
        
//         SegmentDescriptor dataSegmentSelector;

//     //public:
//         // constructor and destructor of the gdt class
//         GlobalDescriptorTable();
//         ~GlobalDescriptorTable();
//         // descriptors of segments
//         uint16_t CodeSegmentSelector(); // will return the address - descriptor
//         uint16_t DataSegmentSelector();

//     };
// #define GDT_CODE_SEGMENT 0x8
// #endif


#ifndef __gdt_h
#define __gdt_h

#define GDT_CODE_SEGMENT 0x08
#define GDT_DATA_SEGMENT 0x10

void GDT_Initialize();

#endif