#pragma once

#include <knl/bits/remove_reference.hpp>

namespace knl{

template<typename T>
constexpr T&& forward(remove_reference_t<T>& t){
	return static_cast<remove_reference<T>&&>(t);
}
template<typename T>
constexpr T&& forward(remove_reference_t<T>&& t){
	return t;
}
}
