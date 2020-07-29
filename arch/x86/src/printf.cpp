
#include <log/printf.hpp>
#include <types.hpp>

namespace log{

void printf(const char* fmt){
	unsigned short* vmem = (unsigned short*)0xb0000;
	for(size_t i=0; fmt[i] != '\0'; ++i)
		vmem[i] = (vmem[i] & 0xff00) | fmt[i];
}

}
