# on windows machine
qemu-system-i386.exe -cdrom C:\\vm-shared-2\\mykernel.iso -hda mydisk.qcow2 -boot d -m 512 -no-reboot -no-shutdown -d int -M smm=off -s
