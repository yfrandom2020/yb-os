#include <fat16/fat16.h>
// This is the beggining of the file system - which is FAT16


MBR mbr;
FAT16_BootSector boot_sector;
uint32_t lba_start;
uint32_t lba_limit;

void Read_MBR()
{
    // Write to the first sector of the disk - which is the MBR
    // In: struct sized 512 that includes a partition table
    // Out: None

    ata0m.Read28(0, 512, (uint8_t*)&mbr); // Load MBR into mbr struct, this will actually load correctly the data

    if (mbr.signature != 0xaa55) 
    {
        printf((uint8_t*)"error",0);

    }
    else 
    {
        printf((uint8_t*)"no error",0);
    }
    
    MBR_PartitionEntry* firstPartition = &(mbr.partitionTable[0]); // pointer to the first partition table entry

    uint32_t lba_start = firstPartition->relativeSector; // Actual beggining of our partition

    uint32_t lba_limit = firstPartition->totalSectors; // Size of partition

    uint8_t partition_type = firstPartition->partitionType;

    printfHex(partition_type);
    printf((uint8_t*)"\n",0);

    // Purpose of function: to set up values in the lba global variables  
}


void readBootSector() 
{
    // Implement reading of the boot sector using your disk I/O functions

    // First we read the entire sector into the bootsector structure
    // Then parse it anf gain the useful data
    
    ata0m.Read28(lba_start, sizeof(boot_sector), (uint8_t*)&boot_sector);

    uint16_t bytes_per_sector = boot_sector.BPB_BytsPerSec;
    uint8_t sectors_per_cluster = boot_sector.BPB_SecPerClus;
    uint16_t reserved_sectors = boot_sector.BPB_RsvdSecCnt;
    uint8_t number_of_FATs = boot_sector.BPB_NumFATs;
    uint16_t root_entries = boot_sector.BPB_RootEntCnt;
    uint16_t total_sectors = boot_sector.BPB_TotSec16;
    if (total_sectors == 0) 
    {
        total_sectors = boot_sector.BPB_TotSec32;
    }
    uint16_t sectors_per_FAT = boot_sector.BPB_FATSz16;
    uint32_t root_directory_sectors = ((root_entries * 32) + (bytes_per_sector - 1)) / bytes_per_sector;
    uint32_t first_data_sector = reserved_sectors + (number_of_FATs * sectors_per_FAT) + root_directory_sectors;
    uint32_t total_clusters = (total_sectors - first_data_sector) / sectors_per_cluster;

    // Calculate the starting sector of the FAT and root directory - this is the important thing
    uint32_t fat_start_sector = lba_start + reserved_sectors;
    uint32_t root_dir_start_sector = fat_start_sector + (number_of_FATs * sectors_per_FAT);


    printfHex(sectors_per_cluster);
    printf((uint8_t*)"\n",0);


    printfHex(number_of_FATs);
    printf((uint8_t*)"\n",0);

    printfHex(boot_sector.BPB_SecPerClus);

    
}

