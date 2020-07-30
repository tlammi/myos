#pragma once

#include <types.hpp>
#include <knl/type_traits.hpp>

namespace knl{

template<size_t Index, typename Type>
class _TupleImpl{
public:
	Type val_;
};

template<size_t Index, typename First=void, typename... Types>
class _TupleRecur:
	public _TupleImpl<Index, First>,
	public _TupleRecur<Index+1, Types...> {
public:
	template<typename T>
	T& get(){
		if constexpr(is_same<T, First>::value){
			return static_cast<_TupleImpl<Index, First>*>(this)->val_;
		}
		else{
			return static_cast<_TupleRecur<Index+1, Types...>*>(this)-> template get<T>();
		}
	}

	template<size_t S, typename T = typename nth_type<S-Index, First, Types...>::type>
	T& get(){
		if constexpr (S == Index){
			return static_cast<_TupleImpl<Index, First>*>(this)->val_;
		} else{
			return static_cast<_TupleRecur<Index+1, Types...>*>(this)-> template get<S>();
		}
	}
};

template<size_t Index>
class _TupleRecur<Index, void>{};

template<typename First=void, typename... Types>
class Tuple: public _TupleRecur<0, First, Types...>{
public:
	template<typename T>
	inline T& get(){
		return static_cast<_TupleRecur<0, First, Types...>*>(this)-> template get<T>();
	}

	template<size_t S, typename T = typename nth_type<S, First, Types...>::type>
	inline T& get(){
		return static_cast<_TupleRecur<0, First, Types...>*>(this)-> template get<S>();
	}

	constexpr size_t size() const {
		if constexpr(is_same<First, void>::value){
			return 0;
		}
		return sizeof...(Types)+1;
	}
};

}
