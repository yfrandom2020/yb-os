#!/bin/bash
DEPENDENCIES_DIR="./dependancies"
DISK_FILE="os-disk.qcow2"
DISK_PATH="$DEPENDENCIES_DIR/$DISK_FILE"
# Check if os-disk.qcow2 exists in the dependancies folder


TEST_DIR="./test"
TEST_DISK_FILE="test.qcow2"
TEST_DISK_PATH="$TEST_DIR/$TEST_DISK_FILE"

if [ ! -e "$DISK_PATH" ]; then
    # If the file doesn't exist, create it
    /usr/bin/qemu-img create -f qcow2 "$DISK_FILE" 512M
    # Start GParted virtual machine to define ext2 partition
    /usr/bin/qemu-system-i386 -cdrom "$DEPENDENCIES_DIR/gparted-live-1.6.0-3-i686.iso" -hda "$DISK_FILE" -boot d -m 512

    # Move the created disk to the dependencies folder
    sudo mv "$DISK_FILE" "$DEPENDENCIES_DIR"

    # Copy os-disk.qcow2 to test.qcow2 and move it to /test folder
    sudo cp "$DISK_PATH" "$TEST_DISK_FILE"
    sudo mv "$TEST_DISK_FILE" "$TEST_DIR"
fi

# Run qemu-system-i386 with mykernel.iso and os-disk.qcow2
/usr/bin/qemu-system-i386 -cdrom ./objects/mykernel.iso -drive file="$DISK_PATH",cache=none -boot d -m 512 -no-reboot -no-shutdown -d int -M smm=off -s
