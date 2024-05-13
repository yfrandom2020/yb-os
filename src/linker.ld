ENTRY(loader)
OUTPUT_FORMAT(elf32-i386)
OUTPUT_ARCH(i386:i386)
SECTIONS
{

    /*. = 0x0000;*/
    /*.ivt : /* Define a section for the IVT */
    /*{*/
        /* Place the IVT here */
        /**(.ivt)*/
    /*}*/

    /* IVT goes until 0x3FF */
    . = 0x400; /* load the rest of the code right after the IVT ends */
    .text :
    {
        *(.multiboot)
        *(.text*)
        *(.rdata)
    }

    .data :
    {
        start_ctors = .;
        KEEP(*( .init_array));
        KEEP(*(SORT_BY_INIT_PRIORITY( .init_array.*)));
        end_ctors = .;
        *(.data)
    }

    .bss :
    {
        *(.bss)
    }

    /DISCARD/ :
    {
        *(.fini_array*)
        *(.comment)

    }
}
