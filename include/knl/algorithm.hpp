#pragma once

namespace knl{

template<typename T>
constexpr const T& max(const T& a, const T& b){
	return a > b ? a : b;
}

template<typename T>
constexpr const T& min(const T& a, const T& b){
	return a < b ? a : b;
}


template<typename T, typename Cmp>
constexpr const T& max(const T& a, const T& b, Cmp cmp){
	return cmp(a,b) ? b : a;
}

template<typename T, typename Cmp>
constexpr const T& min(const T& a, const T& b, Cmp cmp){
	return cmp(a,b) ? a : b;
}

}
