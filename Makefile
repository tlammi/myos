CCFLAGS = --std=c++17 -g -O0 -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -I include -I arch/x86/include
ASFLAGS = --32 
LDFLAGS = -melf_i386

include src/Makefile
include arch/x86/Makefile

all: myos.iso

%.o: %.cpp
	g++ $(CCFLAGS) -o $@ -c $<

%.o: %.s
	as $(ASFLAGS) -o $@ $<

myos.bin: arch/x86/linker.ld $(objs)
	ld $(LDPARAMS) -T $< -o $@ $(objs)

myos.iso: myos.bin
	mkdir -p iso/boot/grub
	cp $< iso/boot
	rm -f iso/boot/grub/grub.cfg
	echo 'set timeout=0' >> iso/boot/grub/grub.cfg
	echo 'set default=0' >> iso/boot/grub/grub.cfg
	echo '' >> iso/boot/grub/grub.cfg
	echo 'menuentry "MyOS" {' >> iso/boot/grub/grub.cfg
	echo '  multiboot /boot/myos.bin' >> iso/boot/grub/grub.cfg
	echo '  boot' >> iso/boot/grub/grub.cfg
	echo '}' >> iso/boot/grub/grub.cfg
	echo '' >> iso/boot/grub/grub.cfg
	#genisoimage -o $@ iso
	grub-mkrescue --output=$@ iso


clean:
	rm -f myos.bin
	rm -f $(objs)
	rm -rf iso
	rm -f myos.iso
