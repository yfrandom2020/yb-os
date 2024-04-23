GPPPARAMS = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore
ASPARAMS = --32
LDPARAMS = -melf_i386
objects = loader.o gdt.o port.o kernel.o
path = /home/fridkin/os/yb-os/parts
first_path = /home/fridkin/os/yb-os/src

%.o: %.cpp
	g++ $(GPPPARAMS) -o $@ -c $<
	sudo mv $@ $(path)
%.o: %.s
	as $(ASPARAMS) -o $@ $<
	@sudo mv $@ $(path)

gdt.o:
port.o:
kernel.o:
loader.o:


mykernel.bin: linker.ld $(path)/$(objects)
	cd $(path) && \
	ld $(LDPARAMS) -T $(first_path)/$< -o $@ $(objects)
install: mykernel.bin
	sudo cp $< /boot/mykernel.bin
mykernel.iso: $(path)/mykernel.bin
	cd $(path) && \
	mkdir iso && \
	mkdir iso/boot && \
	mkdir iso/boot/grub && \
	cp $< iso/boot/ && \
	echo 'set timeout=0' > iso/boot/grub/grub.cfg && \
	echo 'set default=0' >> iso/boot/grub/grub.cfg && \
	echo '' >> iso/boot/grub/grub.cfg && \
	echo 'menuentry "My Operating System" {' >> iso/boot/grub/grub.cfg && \
	echo ' multiboot /boot/mykernel.bin' >> iso/boot/grub/grub.cfg && \
	echo '  boot' >> iso/boot/grub/grub.cfg && \
	echo '}' >> iso/boot/grub/grub.cfg && \
	grub-mkrescue --output=$@ iso && \
	rm -rf iso && \
.PHONY: clean
clean:
	@cd $(path) && \
	rm -f $(objects) mykernel.bin mykernel.iso
