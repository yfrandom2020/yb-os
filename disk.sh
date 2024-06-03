/usr/bin/qemu-img create -f qcow2 os-disk.qcow2 512M
# This starts a GParted virtual machine that is used to define the ext2 partition to the hard drive used by the os 
/usr/bin/qemu-system-i386 -cdrom gparted-live-1.6.0-3-i686.iso -hda os-disk.qcow2 -boot d -m 512


# dd if=/dev/zero of=disk.img bs=1M count=1
# sudo losetup -f -P disk.img
# sudo parted /dev/loop0 mklabel gpt
# sudo parted -a optimal /dev/loop0 mkpart primary 0% 100%
# sudo mkfs.vfat /dev/loop0p1
# cp disk.img test.img




# dd if=/dev/zero of=disk.img bs=1M count=10

# # Set up the loop device
# LOOP_DEVICE=$(sudo losetup -f --show disk.img)

# # Create a GPT partition table
# sudo parted $LOOP_DEVICE mklabel gpt

# # Create a primary partition
# sudo parted -a optimal $LOOP_DEVICE mkpart primary 0% 100%

# # Format the partition with FAT32 (vfat)
# sudo mkfs.vfat ${LOOP_DEVICE}p1

# # Detach the loop device
# sudo losetup -d $LOOP_DEVICE

# # Copy the disk image to test.img
# cp disk.img test.img