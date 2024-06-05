#!/bin/bash
DEPENDENCIES_DIR="./dependencies"
DISK_FILE="os-disk.qcow2"
DISK_PATH="$DEPENDENCIES_DIR/$DISK_FILE"

# Change directory to dependencies folder

# Check if os-disk.raw exists in the dependencies folder
if [ ! -e "dependancies/os-disk.qcow2" ]; then
    # If the file doesn't exist, create it
    /usr/bin/qemu-img create -f qcow2 os-disk.qcow2 512M 
    /usr/bin/qemu-system-i386 -cdrom dependancies/gparted-live-1.6.0-3-i686.iso -hda os-disk.qcow2 -boot d -m 512
    sudo mv os-disk.qcow2 dependancies/ 
fi

# Run qemu-system-i386 with mykernel.iso and os-disk.qcow2
/usr/bin/qemu-system-i386 -cdrom ./objects/mykernel.iso -drive file=dependancies/os-disk.qcow2,format=qcow2,cache=none -boot d -m 512 -no-reboot -no-shutdown -M smm=off -s