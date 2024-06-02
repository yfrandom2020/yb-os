#pragma once
#include <types.h>
#include <ext2/disk.h>
#include <stddef.h>

// The file system will follow a similar design to the ext2
// This will be a simplified version of the ext2, something similar to: gvahim os chapter 10 - file system 
// The os is booted from cdrom but the file system will be on hard drive


#define BLOCK_SIZE 1024 // Block size 1024 bytes which is 1kb
#define INODE_SIZE 128 // Size of node is 128 bytes - which is also 0.125 kb
#define SUPERBLOCK_SIZE 1024 // Size of superblock is same as other blocks
#define BLOCKS_PER_GROUP 8192 
#define INODES_PER_GROUP 1024
#define NUM_INODES 1024
#define SECTOR_SIZE 512 // A sector in the hard disk is 512 bytes long

// Superblock structure
typedef struct  
{
    uint32_t total_blocks;
    uint32_t total_inodes;
    uint32_t free_blocks;
    uint32_t free_inodes;
    char padding[BLOCK_SIZE - 4 * sizeof(uint32_t)];
} __attribute__((packed)) superblock;

// Inode structure
typedef struct 
{
    uint16_t mode;
    uint32_t size;
    uint32_t block[15];
    char padding[INODE_SIZE - sizeof(uint16_t) - sizeof(uint32_t) - 15 * sizeof(uint32_t)];
} __attribute__((packed)) inode; 

// File system structure
typedef struct 
{
    superblock sb;
    inode inodes[NUM_INODES];
    uint8_t data_blocks[NUM_INODES * 10][BLOCK_SIZE]; // Example size for data blocks
} __attribute__((packed)) file_system;

void *memset(void *ptr, int value, size_t num);
void init_superblock(superblock *sb, uint32_t total_blocks, uint32_t total_inodes);
void init_inode(inode *in, uint16_t mode, uint16_t uid, uint32_t size);
void Init_ext();