#pragma once
#include <types.h>
#include <port/pic.h>

#define ATA_PRIMARY_IO 0x1F0
#define ATA_PRIMARY_DATA 0x1F0
#define ATA_PRIMARY_ERROR 0x1F1
#define ATA_PRIMARY_SECCOUNT 0x1F2
#define ATA_PRIMARY_LBA0 0x1F3
#define ATA_PRIMARY_LBA1 0x1F4
#define ATA_PRIMARY_LBA2 0x1F5
#define ATA_PRIMARY_DRIVE 0x1F6
#define ATA_PRIMARY_COMMAND 0x1F7
#define ATA_PRIMARY_STATUS 0x1F7
#define ATA_PRIMARY_ALTSTATUS 0x3F6

#define ATA_CMD_READ_PIO 0x20
#define ATA_CMD_WRITE_PIO 0x30
#define ATA_CMD_IDENTIFY 0xEC

#define ATA_SR_BSY 0x80
#define ATA_SR_DRQ 0x08

uint8_t port_inb(uint8_t portnumber);
void port_outb(uint16_t port, uint8_t data);
void port_insw(uint16_t port, void* addr, int count);
void port_outsw(uint16_t port, void* addr, int count);

void ata_initialize();
void ata_wait_bsy();
void ata_wait_drq();
void ata_read_sector(uint32_t lba, uint8_t* buffer);
void ata_write_sector(uint32_t lba, const uint8_t* buffer);

