
#include <log/print.hpp>
#include <types.hpp>

using constructor = void(*)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void call_ctors(){
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpointer-arith"
	for(auto i = start_ctors; i != end_ctors; ++i){
		i();
	}
#pragma GCC diagnostic pop
}

extern "C" void kernel_main(void* multiboot, unsigned int magic){
	log::print(log::DEBUG) << "                          \n";
	log::print(log::DEBUG) << "hello, world\n";
}
