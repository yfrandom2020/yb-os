#pragma once
#include "../types.h"
#include "../port/port.h"
#include "util.h"
// This is the IDT header file. The idt (interrupt descriptor table) is a table that holds the different ISR (interrupt service routines)
// The IDT is similar in structure to the GDT with the structure being very much alike
// https://wiki.osdev.org/Interrupt_Descriptor_Table
// There are a few parameters in the IDT: offset (of the function inside a segment), segment (address of segment), reserved (typically 0), flags (to indicate type of interrupt and what protection level is allowed to run it)

typedef struct {
 uint16_t offset_low;
 uint16_t segment_selector;
 uint8_t Reserved;
 uint8_t Flags;
 uint16_t offset_high;
} __attribute__((packed)) idt_entry; // This is a single entry in the IDT
// __attribute__ ((packed)) tells the compiler to not move the stuff defined too much and minimize padding

typedef struct {
  uint16_t limit;
  idt_entry* pointer;
} __attribute__((packed)) idt_descriptor;

typedef enum {
    idt_flag_gate_task          = 0x5,
    idt_flag_gate_16bit_int     = 0x6,
    idt_flag_gate_16bit_trap    = 0x7,
    idt_flag_gate_32bit_int     =0xe,
    idt_flag_32bit_trap         =0xf,
    idt_flag_ring0              = (0 << 5),
    idt_flag_ring1              = (1 << 5),
    idt_flag_ring2              = (2 << 5),
    idt_flag_ring3              = (3 << 5), // These flags represent the different levels of authority for the interrupt call - 0 means kernel and 3 means userland. 1 is usually driver
    idt_flag_present            = 0x80
} idt_flags;

extern "C" void idt_set_gate(int interrupt, void* base, uint16_t segment_descriptor, uint8_t flags);
extern "C" void IDT_Initialize();
extern "C" void set_flag(int interrupt);
extern "C" void disable_flag(int interrupt);
void idt_load_assembly(idt_descriptor* ptr);

