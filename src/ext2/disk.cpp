#include <ext2/disk.h>
// Implementing disk.h functions
// In the disk, the smallest readable and writable size is a sector - which is 512 bytes lone
// A hard drive is comprised of platters, each platter has two heads, each head has tracks, each track has sectors

void ata_initialize() 
{
    // Initialize both primary and secondary ATA buses, master and slave
    port_outb(0x1F6, 0xA0); // Select master drive on primary bus
    // You can add additional initialization for slave or secondary if needed
}

void ata_wait_bsy() 
{
    while (port_inb(ATA_PRIMARY_STATUS) & ATA_SR_BSY);
}

void ata_wait_drq() 
{
    while (!(port_inb(ATA_PRIMARY_STATUS) & ATA_SR_DRQ));
}

void ata_read_sector(uint32_t lba, uint8_t* buffer) 
{
    // Read from a specified location
    ata_wait_bsy();
    port_outb(ATA_PRIMARY_DRIVE, 0xE0 | ((lba >> 24) & 0x0F));
    port_outb(ATA_PRIMARY_SECCOUNT, 1);
    port_outb(ATA_PRIMARY_LBA0, (uint8_t)lba);
    port_outb(ATA_PRIMARY_LBA1, (uint8_t)(lba >> 8));
    port_outb(ATA_PRIMARY_LBA2, (uint8_t)(lba >> 16));
    port_outb(ATA_PRIMARY_COMMAND, ATA_CMD_READ_PIO);

    ata_wait_bsy();
    ata_wait_drq();

    port_insw(ATA_PRIMARY_DATA, buffer, 256); // Read 256 words (512 bytes)
}


void ata_write_sector(uint32_t lba, uint8_t* buffer) 
{
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
}
