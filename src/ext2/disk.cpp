#include <ext2/disk.h>
// Implementing disk.h functions
// In the disk, the smallest readable and writable size is a sector - which is 512 bytes lone
// A hard drive is comprised of platters, each platter has two heads, each head has tracks, each track has sectors

void ata_initialize() 
{
    disable_interrupt_flag();
    // Initialize both primary and secondary ATA buses, master and slave
    port_outb(ATA_PRIMARY_CONTROL, 0x02); // Disable IRQs
    port_outb(ATA_PRIMARY_DRIVE, 0xA0); // Select master drive on primary bus
    Enable_interrupts();

}

void ata_wait_bsy() {
    uint32_t timeout = 100000; // Adjust the timeout value as needed
    while ((port_inb(ATA_PRIMARY_STATUS) & ATA_SR_BSY) && --timeout);
    if (timeout == 0) {
        printf((uint8_t*)"Timeout waiting for BSY to clear\n",0);
    } else {
        printf((uint8_t*)"BSY cleared\n",0);
    }
}

void ata_wait_drq() 
{
    while (!(port_inb(ATA_PRIMARY_STATUS) & ATA_SR_DRQ));
}

void ata_flush()
{
    
    ata_wait_bsy();
    port_outb(ATA_PRIMARY_COMMAND, 0xE7);
}

void ata_read_sector(uint32_t lba, uint8_t* buffer) 
{
    
    disable_interrupt_flag();
    printf((uint8_t*)"In ata_read_sector\n",0);

    ata_wait_bsy(); // Wait for the drive to be ready

    // Setup the drive and LBA
    printf((uint8_t*)"Setting up drive and LBA\n",0);
    port_outb(ATA_PRIMARY_DRIVE, 0xE0 | ((lba >> 24) & 0x0F));
    port_outb(ATA_PRIMARY_SECCOUNT, 1); // Read one sector
    port_outb(ATA_PRIMARY_LBA0, (uint8_t)lba);
    port_outb(ATA_PRIMARY_LBA1, (uint8_t)(lba >> 8));
    port_outb(ATA_PRIMARY_LBA2, (uint8_t)(lba >> 16));
    
    port_outb(ATA_PRIMARY_COMMAND, ATA_CMD_READ_PIO);

    ata_wait_bsy(); // Wait for the drive to process the command

    // Check if there are any errors
    uint8_t status = port_inb(ATA_PRIMARY_STATUS);
    if (status & ATA_SR_ERR) {
        printf((uint8_t*)"Error after sending read command: %x\n", 0);
        Enable_interrupts();
        return;
    }

    ata_wait_drq(); // Wait for the drive to be ready for data transfer

    printf((uint8_t*)"Reading data\n",0);
    port_insw(ATA_PRIMARY_DATA, (uint16_t*)buffer, 256); // Read 256 words (512 bytes)

    Enable_interrupts();
    printf((uint8_t*)"Read complete\n",0);
}


void ata_write_sector(uint32_t lba, uint8_t* buffer) 
{
    disable_interrupt_flag();
    ata_wait_bsy();
    port_outb(ATA_PRIMARY_DRIVE, 0xE0 | ((lba >> 24) & 0x0F));
    port_outb(ATA_PRIMARY_SECCOUNT, 1);
    port_outb(ATA_PRIMARY_LBA0, (uint8_t)lba);
    port_outb(ATA_PRIMARY_LBA1, (uint8_t)(lba >> 8));
    port_outb(ATA_PRIMARY_LBA2, (uint8_t)(lba >> 16));
    port_outb(ATA_PRIMARY_COMMAND, ATA_CMD_WRITE_PIO);

    ata_wait_bsy();
    ata_wait_drq();

    port_outsw(ATA_PRIMARY_DATA, buffer, 256); // Write 256 words (512 bytes)
    ata_flush();
    Enable_interrupts();
}

