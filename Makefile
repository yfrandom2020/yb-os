# This is the general makefile for the project
# This makefile will include a couple of things
# 1) compilation instructions for c++ src files and asm src files 
# 2) 2) linking instructions using the script linker.ld to create mykernel.bin, which is the actual file being run in the QEMU machine
# 3) Calling scripts that 1) create the virtual hard drive (run.sh) and commit changes to github (commit.sh)
GPPPARAMS = -I./include -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wall -Werror -g -nostdinc++
ASPARAMS = --32 -I./include -g
LDPARAMS = -melf_i386
objects = loader.o kernel.o util.o initializers.o gdt.o gdt_asm.o port.o pic.o idt.o isrs_gen.o isr.o isr_asm.o irq.o disk.o fat16.o
all_objects = $(objects) mykernel.bin mykernel.iso
path = /home/fridkin/os/yb-os/objects
src_path = /home/fridkin/os/yb-os/src
include_path = /home/fridkin/os/yb-os/include
shared_path = /mnt/hgfs/vm-shared-2
common_path = /home/fridkin/os/yb-os

.PHONY: all
all:

	clear

	make second_clean

	make clean

	make src/loader.o

	make src/kernel.o

	make src/initializers.o

	make src/util/util.o

	make src/gdt/gdt.o

	make src/gdt/gdt_asm.o

	make src/port/port.o

	make src/port/pic.o

	make src/idt/idt.o

	make src/idt/isr/isr.o

	make src/idt/isr/isr_asm.o
	
	make src/idt/isr/isrs_gen.o
	
	make src/idt/isr/irq/irq.o

	make src/fat16/disk.o

	make src/fat16/fat16.o

	make mykernel.bin

	make mykernel.iso

	sudo mv $(all_objects) $(path)

	bash scripts/run.sh

# General instruction to compile c++ files using g++ (gnu c++ compiler) and the compilation flags defined earlier
%.o: %.cpp
	g++ $(GPPPARAMS) -o $@ -c $<
	-@sudo mv $@ $(common_path)

# General instruction to compile asm files using GAS (gnu assembler) and the compilation flags defined earlier
%.o: %.s
	as $(ASPARAMS) -o $@ $<
	-@sudo mv $@ $(common_path)


gdt.o:
	@cd gdt && \
	make gdt.o && \
	mv gdt.o $(common_path)


port.o:
	@cd port && \
	make port.o && \
	mv port.o $(common_path)


kernel.o:


loader.o:

# General linking instruction that receives all the compiled src code (in form of object files) and links it into a binary file using linker.ld
mykernel.bin: src/linker.ld $(objects)
	ld $(LDPARAMS) -T $< -o $@ $(objects)



install: mykernel.bin
	sudo cp $< /boot/mykernel.bin


# General instruction to create an ISO file using the GRUB menu  
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

# General clean instruction to clean directories from object files. Has two uses 1) When re - compiling the code after changes we need to delete the files first 
# 2) If my code crashes in the middle and only some object files are made they will be stuck in the src directory - we implement an instruction to clean instead of manually
.PHONY: clean
clean:
	@cd $(path) && \
	rm -f $(objects) mykernel.bin mykernel.iso
	rm -f $(shared_path)/mykernel.iso

.PHONY: second_clean
second_clean:
	
	@cd $(include_path) && \
	rm -f $(objects) 
	
	@cd $(src_path) && \
	rm -f $(objects) 

.PHONY: check_disk_image
check_disk_image:
	@if [ ! -f dependancies/os-disk.qcow2 ]; then \
		echo "Disk image not found. Creating disk image..."; \
		bash disk.sh; \
	fi

# Use commit.sh to push to github
commit:
	bash scripts/commit.sh