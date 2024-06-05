#pragma once
#include <types.h>
#include <fat16/disk.h>
#include <stddef.h>
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
    // The first sector of each partition is called the boot sector and contains some metadata about the partition and the file system
    uint8_t  BS_jmpBoot[3];
    uint8_t  BS_OEMName[8];
    uint16_t BPB_BytsPerSec; // 512
    uint8_t  BPB_SecPerClus; // 16 0x10
    uint16_t BPB_RsvdSecCnt;
    uint8_t  BPB_NumFATs; // usually 2
    uint16_t BPB_RootEntCnt; // garbage values, must be set
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



void Read_MBR();
void readBootSector(); // Use ata_read_sector  
FAT16_BootSector parseBootSector(uint8_t* bootSectorBuffer); // Receive the data from previous function and parse

// MBR information about our FAT16 partition
extern uint32_t lba_start;
extern uint32_t lba_limit;
extern uint8_t partition_type;

// Boot sector information about FAT16
extern uint16_t bytes_per_sector;
extern uint8_t sectors_per_cluster;
extern uint16_t reserved_sectors;
extern uint8_t number_of_FATs;
extern uint16_t root_entries;
extern uint16_t total_sectors;

extern uint16_t sectors_per_FAT;
extern uint32_t root_directory_sectors;
extern uint32_t first_data_sector;
extern uint32_t total_clusters;
// Calculate the starting sector of the FAT and root directory
extern uint32_t fat_start_sector;
extern uint32_t root_dir_start_sector;