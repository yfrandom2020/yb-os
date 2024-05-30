#include <ext2/ext2.h>
// This is the beggining of the file system

// Function to initialize superblock
void init_superblock(superblock *sb, uint32_t total_blocks, uint32_t total_inodes) 
{
    sb->total_inodes = total_inodes;
    sb->total_blocks = total_blocks;
    sb->free_blocks = total_blocks - 1; // 1 block reserved for superblock
    sb->free_inodes = total_inodes - 1; // 1 inode reserved for root directory
    sb->block_size = BLOCK_SIZE;
    sb->inode_size = INODE_SIZE;
    sb->blocks_per_group = BLOCKS_PER_GROUP;
    sb->inodes_per_group = INODES_PER_GROUP;
}


// Function to initialize inode
void init_inode(inode *in, uint16_t mode, uint16_t uid, uint32_t size) 
{
    in->mode = mode;
    in->uid = uid;
    in->size = size;
    in->atime = 0;
    in->ctime = 0;
    in->mtime = 0;
    in->dtime = 0;
    in->gid = 0;
    in->links_count = 1;
    in->blocks = (size + BLOCK_SIZE - 1) / BLOCK_SIZE; // Number of 1024-byte blocks needed
    in->flags = 0;
    memset(in->block, 0, sizeof(in->block));
}

void Init_ext()
{
    superblock sb;
    init_superblock(&sb, 1024 * 1024 / BLOCK_SIZE, 1024 * 1024 / INODE_SIZE); // Example sizes

    inode root_inode;
    init_inode(&root_inode, 0x4000, 0, 0); // Directory inode
}