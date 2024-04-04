GPPPARAMS = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore
ASPARAMS = --32
LDPARAMS = -melf_i386
objects = loader.o gdt.o port.o kernel.o
directory = "parts"
%.o: %.cpp
	g++ $(GPPPARAMS) -o $@ -c $<
	sudo mv $@ /home/fridkin/os/yb-os/parts
%.o: %.s
	as $(ASPARAMS) -o $@ $<
	sudo mv $@ /home/fridkin/os/yb-os/parts
mykernel.bin: linker.ld $(objects)
	ld $(LDPARAMS) -T $< -o $@ $(objects)
	sudo mv $@ /home/fridkin/os/yb-os/parts
install: mykernel.bin
	sudo cp $< /boot/mykernel.bin
mykernel.iso: mykernel.bin
	mkdir iso
	mkdir iso/boot
	mkdir iso/boot/grub
	cp $< iso/boot/
	echo 'set timeout=0' > iso/boot/grub/grub.cfg
	echo 'set default=0' >> iso/boot/grub/grub.cfg
	echo '' >> iso/boot/grub/grub.cfg
	echo 'menuentry "My Operating System" {' >> iso/boot/grub/grub.cfg
	echo ' multiboot /boot/mykernel.bin' >> iso/boot/grub/grub.cfg
	echo '  boot' >> iso/boot/grub/grub.cfg
	echo '}' >> iso/boot/grub/grub.cfg
	grub-mkrescue --output=$@ iso
	rm -rf iso
.PHONY: clean
clean:
	cd /home/fridkin/os/yb-os/parts
	rm -f $(objects) mykernel.bin mykernel.iso
