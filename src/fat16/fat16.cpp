#include <fat16/fat16.h>
// This is the beggining of the file system - which is FAT16


MBR mbr;

void Read_MBR()
{
    // Write to the first sector of the disk - which is the MBR
    // In: struct sized 512 that includes a partition table
    // Out: None

    ata0m.Read28(0, 512, (uint8_t*)&mbr); // Load MBR into mbr struct, this will actually load correctly the data

    if (mbr.signature != 0xaa55) printf((uint8_t*)"error", 0);

    MBR_PartitionEntry* firstPartition = &(mbr.partitionTable[0]); // pointer to the first partition table entry

    uint32_t lba_start = firstPartition->relativeSector; // Actual beggining of our partition

    uint32_t lba_limit = firstPartition->totalSectors; // Size of partition

    uint8_t partition_type = firstPartition->partitionType;

    // Purpose of function: to set up values in the lba global variables  
}


void readBootSector() 
{
    // Implement reading of the boot sector using your disk I/O functions
    // For example:
    // readSector(0, bootSectorBuffer);
    
}

