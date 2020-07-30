CCFLAGS = --std=c++17 -g -O0 -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -I include -I arch/x86/include
ASFLAGS = --32 
LDFLAGS = -melf_i386

include src/Makefile
include arch/x86/Makefile


%.o: %.cpp
	g++ $(CCFLAGS) -o $@ -c $<

%.o: %.s
	as $(ASFLAGS) -o $@ $<

myos.bin: arch/x86/linker.ld $(objs)
	ld $(LDPARAMS) -T $< -o $@ $(objs)

clean:
	rm -f myos.bin
	rm -f $(objs)
