#pragma once
#include <types.h>
#include <fat16/disk.h>
#include <stddef.h>

typedef struct  
{
    uint16_t bytesPerSector;
    uint8_t sectorsPerCluster;
    uint16_t reservedSectors;
    uint8_t numberOfFATs;
    uint16_t rootDirectoryEntries;
    uint32_t totalSectors;
    uint8_t mediaDescriptor;
    uint16_t sectorsPerFAT;
    uint16_t sectorsPerTrack;
    uint16_t numberOfHeads;
    uint32_t hiddenSectors;
    uint32_t totalSectors32;
} __attribute__((packed)) BootSector;

void readBootSector(uint8_t* bootSectorBuffer);
BootSector parseBootSector(uint8_t* bootSectorBuffer);
