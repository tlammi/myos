
#include <log/printf.hpp>
#include <types.hpp>

namespace log{

namespace {
constexpr int DIM_W{80};
constexpr int DIM_H{25};
unsigned short* const VMEM_BASE{(unsigned short*)0xb8000};

void clear_screen(){
	unsigned short* vmem = VMEM_BASE;
	for(size_t i=0; i < DIM_W*DIM_H; ++i){
		vmem[i] = (vmem[i] & 0xff00) | ' ';
	}
}

}

void printf(const char* fmt){
	clear_screen();
	unsigned short* vmem = VMEM_BASE;
	for(size_t i=0; fmt[i] != '\0'; ++i){
		vmem[i] = (vmem[i] & 0xff00) | fmt[i];
	}
}

}
