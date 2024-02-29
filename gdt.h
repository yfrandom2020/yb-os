#ifndef __GDT.H
#define __GDT.H
#include "types.h"
// defining the gdt class, as well as a segment class inside

    class GlobalDescriptorTable
    {
        public:
            class SegmentDescriptor
            {
            private:
                uint16_t limit_lo;
                uint16_t base_lo;
                uint8_t base_hi;
                uint8_t type;
                uint8_t flags_limit_hi;
                uint8_t base vhi;

            public:
                SegmentDescriptor(uint32_t base, uint32_t limit, uint8_t type);
                uint32_t Base();
                uint32_t Limit();
            } __attribute__((packed));

        // initializing some segments - convention
        SegmentDescriptor nullSegmentSelector;
        SegmentDescriptor unusedSegmentSelector;
        // initially one code segment and one data segment for the kernel space
        SegmentDescriptor codeSegmentSelector;
        SegmentDescriptor dataSegmentSelector;

    public:
        // constructor and destructor
        GlobalDescriptorTable();
        ~GlobalDescriptorTable();
        // descriptors of segments
        uint16_t CodeSegmentSelector();
        uint16_t DataSegmentSelector();



    };

#endif
