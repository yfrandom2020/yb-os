# on windows machine
cp os-disk.qcow2 test.qcow2
/usr/bin/qemu-system-i386 -cdrom objects/mykernel.iso -drive file=os-disk.qcow2,cache=none -boot d -m 512 -no-reboot -no-shutdown -d int -M smm=off -s 
#/usr/bin/qemu-system-i386 -cdrom objects/mykernel.iso -drive format=raw,file=disk.img,cache=none -boot d -m 512 -d int -M smm=off -s 
#-drive file=disk.img,cache=none
#-drive file=os-disk.qcow2,cache=none
#-device "isa-debug-exit,iobase=0xf4,iosize=0x04"
#-drive file=os-disk.qcow2,cache=none
