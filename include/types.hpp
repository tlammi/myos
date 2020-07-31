#pragma once

#include "arch/types.hpp"

#define __ASSERT_SIZE(prefix, suffix) static_assert(sizeof(prefix ## suffix) == suffix / 8)
#define ASSERT_SIZES(prefix) \
	__ASSERT_SIZE(prefix, 8); \
	__ASSERT_SIZE(prefix, 16); \
	__ASSERT_SIZE(prefix, 32); \
	__ASSERT_SIZE(prefix, 64)
ASSERT_SIZES(u);
ASSERT_SIZES(s);

#undef ASSERT_SIZES
#undef __ASSERT_SIZE

using size_t = u64;

