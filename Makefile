GPPPARAMS = -I./include -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -fpermissive -g
ASPARAMS = --32 -I./include -g
LDPARAMS = -melf_i386
objects = loader.o kernel.o initializers.o gdt.o gdt_asm.o port.o pic.o idt.o isrs_gen.o isr.o isr_asm.o irq.o disk.o ext2.o
all_objects = $(objects) mykernel.bin mykernel.iso
path = /home/fridkin/os/yb-os/objects
first_path = /home/fridkin/os/yb-os/src
include_path = /home/fridkin/os/yb-os/include
shared_path = /mnt/hgfs/vm-shared-2
bin_path = /home/fridkin/os/yb-os

.PHONY: all
all:
	clear

	make second_clean

	make clean

	make src/loader.o

	make src/kernel.o

	make src/initializers.o

	make src/gdt/gdt.o

	make src/gdt/gdt_asm.o

	make src/port/port.o

	make src/port/pic.o

	make src/idt/idt.o

	make src/idt/isr/isr.o

	make src/idt/isr/isr_asm.o
	
	make src/idt/isr/isrs_gen.o
	
	make src/idt/isr/irq/irq.o

	make src/ext2/disk.o

	make src/ext2/ext2.o

	make mykernel.bin

	make mykernel.iso

	sudo mv $(all_objects) $(path)


%.o: %.cpp
	g++ $(GPPPARAMS) -o $@ -c $<
	-@sudo mv $@ $(bin_path)


%.o: %.s
	as $(ASPARAMS) -o $@ $<
	-@sudo mv $@ $(bin_path)


gdt.o:
	@cd gdt && \
	make gdt.o && \
	mv gdt.o $(bin_path)


port.o:
	@cd port && \
	make port.o && \
	mv port.o $(bin_path)


kernel.o:


loader.o:



mykernel.bin: src/linker.ld $(objects)
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

	sudo cp $@ $(shared_path)


.PHONY: clean
clean:
	@cd $(path) && \
	rm -f $(objects) mykernel.bin mykernel.iso
	rm -f $(shared_path)/mykernel.iso

.PHONY: second_clean
second_clean:
	
	@cd $(include_path) && \
	rm -f $(objects) 
	
	@cd $(first_path) && \
	rm -f $(objects) 

