#include <gtest/gtest.h>
#include "knl/tuple.hpp"
#include "knl/utility.hpp"
#include "knl/type_traits.hpp"


TEST(TupleTest, One){
	knl::Tuple<int> tupl;
	ASSERT_EQ(tupl.size(), 1);
	tupl.get<int>() = 100;
	ASSERT_EQ(tupl.get<int>(), 100);
	ASSERT_EQ(tupl.get<0>(), 100);
	tupl.get<int>() = 99;
	ASSERT_EQ(tupl.get<0>(), 99);
	ASSERT_EQ(tupl.get<int>(), 99);
}

TEST(TupleTest, Empty){
	knl::Tuple<> tupl;
	ASSERT_EQ(tupl.size(), 0);
}

TEST(TupleTest, Multiple){
	knl::Tuple<int,char,double> tupl;
	tupl.get<int>() = 100;
	tupl.get<char>() = 'a';
	tupl.get<double>() = 1.0;

	ASSERT_EQ(tupl.get<0>(), 100);
	ASSERT_EQ(tupl.get<1>(), 'a');
	ASSERT_EQ(tupl.get<2>(), 1.0);
}

TEST(TupleTest, MultipleSame){
	knl::Tuple<int,int,int,int> tupl;
	tupl.get<0>() = 1;
	tupl.get<1>() = 2;
	tupl.get<2>() = 3;
	tupl.get<3>() = 4;

	ASSERT_EQ(tupl.get<0>(), 1);
	ASSERT_EQ(tupl.get<1>(), 2);
	ASSERT_EQ(tupl.get<2>(), 3);
	ASSERT_EQ(tupl.get<3>(), 4);
}

TEST(TupleTest, PairAndTuple){
	knl::Pair<int,double> pair;
	knl::Tuple<int,double> tupl;
	bool val = knl::is_same_v<knl::Pair<int,double>,knl::Tuple<int,double>>;
	ASSERT_TRUE(val);
}

TEST(TupleTest, Ctor){
	knl::Tuple<int,double> tpl{1, 10.0};
	ASSERT_EQ(tpl.get<0>(), 1);
	ASSERT_EQ(tpl.get<double>(), 10.0);
}
