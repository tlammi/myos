#pragma once

#include <log/printf.hpp>

namespace log{

constexpr char DEBUG{'0'};
constexpr char INFO{'1'};
constexpr char NOTE{'2'};
constexpr char WARN{'3'};
constexpr char ERR{'4'};

constexpr int PRINT_BASE{0xb8000};

class print{
public:
	inline print(char level, const char* f = __builtin_FILE(), int l = __builtin_LINE()){
		(void)level;
		(void)f;
		(void)l;
	}
	
	inline print& operator<<(const char* str){
		printf(str);
	}
private:

};
}
