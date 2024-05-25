# void __attribute__((cdecl)) GDT_Load(GDTDescriptor* descriptor, uint16_t codeSegment, uint16_t dataSegment);
.global GDT_Load
GDT_Load:

    # make new call frame
    push %ebp              # save old call frame
    mov %esp, %ebp         # initialize new call frame
    
    # load gdt
    mov 8(%ebp), %eax 
    lgdt (%eax)

    # reload code segment
    mov 12(%ebp), %eax
    push %eax
    push $reload_cs
    retf

reload_cs:

    # reload data segments
    mov 16(%ebp), %ax
    mov %ax, %ds
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs
    mov %ax, %ss

    # restore old call frame
    mov %ebp, %esp
    pop %ebp
    ret
