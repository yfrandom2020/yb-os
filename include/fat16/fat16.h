#pragma once
#include <types.h>
#include <fat16/disk.h>
#include <stddef.h>

typedef struct 
{
    uint8_t  bootIndicator;
    uint8_t  startHead;
    uint8_t  startSector;
    uint8_t  startCylinder;
    uint8_t  partitionType;
    uint8_t  endHead;
    uint8_t  endSector;
    uint8_t  endCylinder;
    uint32_t relativeSector;
    uint32_t totalSectors;
} __attribute__((packed)) MBR_PartitionEntry;


typedef struct 
{
    uint8_t  bootstrap[446];
    MBR_PartitionEntry partitionTable[4];
    uint16_t signature;
} __attribute__((packed)) MBR;


typedef struct 
{
    uint8_t  BS_jmpBoot[3];
    uint8_t  BS_OEMName[8];
    uint16_t BPB_BytsPerSec;
    uint8_t  BPB_SecPerClus;
    uint16_t BPB_RsvdSecCnt;
    uint8_t  BPB_NumFATs;
    uint16_t BPB_RootEntCnt;
    uint16_t BPB_TotSec16;
    uint8_t  BPB_Media;
    uint16_t BPB_FATSz16;
    uint16_t BPB_SecPerTrk;
    uint16_t BPB_NumHeads;
    uint32_t BPB_HiddSec;
    uint32_t BPB_TotSec32;
    uint8_t  BS_DrvNum;
    uint8_t  BS_Reserved1;
    uint8_t  BS_BootSig;
    uint32_t BS_VolID;
    uint8_t  BS_VolLab[11];
    uint8_t  BS_FilSysType[8];
} __attribute__((packed)) FAT16_BootSector;

void readBootSector(uint8_t* bootSectorBuffer);
FAT16_BootSector parseBootSector(uint8_t* bootSectorBuffer);
