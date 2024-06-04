#pragma once
#include <types.h>
#include <fat16/disk.h>
#include <stddef.h>
#include <util/util.h>
extern ata ata0m;
typedef struct 
{
    // The mbr contains three different parts
    // Boot code - first 446 bytes
    // Partition tables - 4 entries with each sized 16 bytes that describe different partitions on the disk 
    // The struct describes a single entry
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
    // Implement mbr strcure, we will load this into sector 0
    uint8_t  bootstrap[446];
    MBR_PartitionEntry partitionTable[4];
    uint16_t signature; // 0x55AA
} __attribute__((packed)) MBR;


typedef struct 
{
    // The first sector of each partition is called the boot sector and contains some metadata about the partition and file system
    uint8_t  BS_jmpBoot[3];
    uint8_t  BS_OEMName[8];
    uint16_t BPB_BytsPerSec; // 512
    uint8_t  BPB_SecPerClus; // 8 
    uint16_t BPB_RsvdSecCnt;
    uint8_t  BPB_NumFATs; // usually 2
    uint16_t BPB_RootEntCnt; // garbage value, must be set
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



void Read_MBR(MBR* mbr_sector);
void readBootSector(); // Use ata_read_sector  
FAT16_BootSector parseBootSector(uint8_t* bootSectorBuffer); // Receive the data from previous function and parse

extern uint32_t lba_start;
extern uint32_t lba_limit;
extern uint8_t partition_type;
