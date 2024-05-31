# on windows machine
/usr/bin/qemu-system-i386 -cdrom objects/mykernel.iso -hda os-disk.qcow2 -boot d -m 512 -no-reboot -no-shutdown -d int -M smm=off -s
