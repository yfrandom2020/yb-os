#!/bin/bash
DEPENDENCIES_DIR="./dependencies"
DISK_FILE="os-disk.raw"
DISK_PATH="$DEPENDENCIES_DIR/$DISK_FILE"

# Change directory to dependencies folder

# Check if os-disk.raw exists in the dependencies folder
if [ ! -e "dependancies/os-disk.raw" ]; then
    # If the file doesn't exist, create it
    /usr/bin/qemu-img create -f raw os-disk.raw 512M
    loop_device=$(sudo losetup -fP --show os-disk.raw)
    sudo parted ${loop_device} --script mklabel msdos
    sudo parted ${loop_device} --script mkpart primary fat16 1MiB 100%
    sudo parted ${loop_device} --script set 1 boot on
    sudo mkfs.vfat -F 16 ${loop_device}p1
    sudo dd if=/dev/loop0 bs=512 count=1 | hexdump -C
    sudo losetup -d ${loop_device}
    sudo mv os-disk.raw dependancies/ 
fi

# Run qemu-system-i386 with mykernel.iso and os-disk.qcow2
sudo hexdump -C dependancies/os-disk.raw
/usr/bin/qemu-system-i386 -cdrom ./objects/mykernel.iso -drive file=dependancies/os-disk.raw,format=raw,cache=none -boot d -m 512 -no-reboot -no-shutdown -M smm=off -s

