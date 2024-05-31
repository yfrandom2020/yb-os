# First create and format disk to have one partition that is ext2 defined
# In windows machine

/usr/bin/qemu-img create -f qcow2 os-disk.qcow2 512M

# This starts a GParted virtual machine that is used to define the ext2 partition to the hard drive used by the os 
/usr/bin/qemu-system-i386 -cdrom gparted-live-1.6.0-3-i686.iso -hda os-disk.qcow2 -boot d -m 512

bash run.sh