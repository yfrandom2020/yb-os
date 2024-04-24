GPPPARAMS = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore
ASPARAMS = --32
LDPARAMS = -melf_i386
objects = loader.o gdt.o port.o kernel.o
all_objects = $(objects) mykernel.iso mykernel.bin
path = /home/fridkin/os/yb-os/parts
first_path = /home/fridkin/os/yb-os/src

.PHONY: all
all:
	@make clean
	@make mykernel.bin
	@make mykernel.iso

	sudo mv $(all_objects) $(path)




%.o: %.cpp
	g++ $(GPPPARAMS) -o $@ -c $<
	@sudo mv $@ $(first_path)
%.o: %.s
	as $(ASPARAMS) -o $@ $<
	@sudo mv $@ $(first_path)

gdt.o: @cd /gdt/
port.o: @cd /port/
kernel.o:
loader.o:


mykernel.bin: linker.ld $(objects)
	cd $(path) && \
	ld $(LDPARAMS) -T $(first_path)/$< -o $@ $(objects)
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
	rm -rf iso && \
.PHONY: clean
clean:
	@cd $(path) && \
	@rm -f $(objects) mykernl.bin mykernel.iso
