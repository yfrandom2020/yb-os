GPPPARAMS = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -fpermissive
ASPARAMS = --32
LDPARAMS = -melf_i386
objects = loader.o kernel.o gdt.o port.o pic.o ivt.o
all_objects = $(objects) mykernel.bin mykernel.iso
path = /home/fridkin/os/yb-os/parts
first_path = /home/fridkin/os/yb-os/src

.PHONY: all
all:
	make clean

	make loader.o

	make kernel.o

	make gdt/gdt.o

	make port/port.o

	make port/ivt/pic.o

	make port/ivt/ivt.o

	make mykernel.bin

	make mykernel.iso

	sudo mv $(all_objects) $(path)


%.o: %.cpp
	g++ $(GPPPARAMS) -o $@ -c $<
	-@sudo mv $@ $(first_path)


%.o: %.s
	as $(ASPARAMS) -o $@ $<
	-@sudo mv $@ $(first_path)


gdt.o:
	@cd gdt && \
	make gdt.o && \
	mv gdt.o $(first_path)


port.o:
	@cd port && \
	make port.o && \
	mv port.o $(first_path)


kernel.o:


loader.o:



mykernel.bin: linker.ld $(objects)
	ld $(LDPARAMS) -T $< -o $@ $(objects)



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
	@cd $(path) && \
	rm -f $(objects) mykernel.bin mykernel.iso
