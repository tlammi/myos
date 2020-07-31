#pragma once

namespace knl{

struct false_type{
	static constexpr bool value = false;
};

struct true_type{
	static constexpr bool value = true;
};

template<typename T, typename U>
struct is_same: public false_type{};

template<typename T>
struct is_same<T, T>: public true_type{};

template<typename T, typename U>
constexpr bool is_same_v = is_same<T, U>::value;


template<size_t S, typename First, typename... Types>
struct nth_type: public nth_type<S-1, Types...>{};

template<typename First, typename... Types>
struct nth_type<0, First, Types...>{
	using type = First;
};

template<size_t S, typename... Types>
using nth_type_t = typename nth_type<S, Types...>::type;


template<size_t S, typename First, typename... Types>
constexpr nth_type_t<S, First, Types...> nth_value(First first, Types... args){
	return nth_value<S-1, Types...>(std::forward<Types>(args)...);
}

template<typename First, typename... Types>
constexpr First nth_value(First first, Types... args){
	return first;
}

}
