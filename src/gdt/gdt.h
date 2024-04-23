#ifndef __GDT_H
#define __GDT_H
#include "../types.h"
// defining the gdt class, as well as a segment class inside

    class GlobalDescriptorTable // class that represents the gdt table
    {
        public:
            // class that describes a single entry in the table
            class SegmentDescriptor
            {
            private: // attributes of each single entry
                uint16_t limit_lo;
                uint16_t base_lo;
                uint8_t base_hi;
                uint8_t type;
                uint8_t flags_limit_hi;
                uint8_t base_vhi;

            public:
                SegmentDescriptor(uint32_t base, uint32_t limit, uint8_t type); // constructor of entry
                uint32_t Base(); // getters
                uint32_t Limit();
            } __attribute__((packed)); // don't change anything when compiling - as in moving bytes

        // initializing segments
        SegmentDescriptor nullSegmentSelector;
        SegmentDescriptor unusedSegmentSelector;
        // initially one code segment and one data segment for the kernel space
        SegmentDescriptor codeSegmentSelector;
        SegmentDescriptor dataSegmentSelector;

    //public:
        // constructor and destructor of the gdt class
        GlobalDescriptorTable();
        ~GlobalDescriptorTable();
        // descriptors of segments
        uint16_t CodeSegmentSelector(); // will return the address - descriptor
        uint16_t DataSegmentSelector();

    };

#endif
