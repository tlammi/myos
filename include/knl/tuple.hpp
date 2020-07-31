#pragma once

#include <types.hpp>
#include <knl/type_traits.hpp>

namespace knl{


template<size_t Index, typename Type>
class _TupleImpl{
public:
	inline _TupleImpl(){}
	inline _TupleImpl(const Type& val): val_{val}{}
	inline _TupleImpl(Type&& val): val_{val}{}
protected:
	inline Type& get(){return val_;}
	inline const Type& get() const {return val_;}
private:
	Type val_{};
};

template<size_t Index, size_t TypeCount, typename... Types>
class _TupleRecur:
	public _TupleImpl<Index, nth_type_t<Index, Types...>>,
	public _TupleRecur<Index+1, TypeCount, Types...>{
public:
	template<typename T>
	T& get(){
		if constexpr(is_same_v<T, nth_type_t<Index, Types...>>)
			return _TupleImpl<Index, nth_type_t<Index, Types...>>::get();

		else
			return _TupleRecur<Index+1, TypeCount, Types...>:: template get<T>();
	}

	template<typename T>
	const T& get() const {
		if constexpr(is_same_v<T, nth_type_t<Index, Types...>>)
			return _TupleImpl<Index, nth_type_t<Index, Types...>>::get();
		else
			return _TupleRecur<Index+1, TypeCount, Types...>:: template get<T>();
	}

	template<size_t S>
	nth_type_t<S, Types...>& get() {
		if constexpr(S == Index)
			return _TupleImpl<Index, nth_type_t<Index, Types...>>::get();
		else
			return _TupleRecur<Index+1, TypeCount, Types...>:: template get<S>();
	}

	template<size_t S>
	const nth_type_t<S, Types...>& get() const {
		if constexpr(S == Index)
			return _TupleImpl<Index, nth_type_t<Index, Types...>>::get();
		else
			return _TupleRecur<Index+1, TypeCount, Types...>:: template get<S>();
	}
};

template<size_t Index, typename... Types>
class _TupleRecur<Index, Index, Types...>{};

template<typename... Types>
class Tuple: public _TupleRecur<0, sizeof...(Types), Types...>{
public:
	constexpr size_t size(){return sizeof...(Types);}
};
}
