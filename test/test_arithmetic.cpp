// тесты для вычисления арифметических выражений

#include <gtest.h>
#include "arithmetic.h"

TEST(Arithmetic, can_create_an_exemplar_of_class1)
{
	ASSERT_NO_THROW(Arithmetic a);
}

TEST(Arithmetic, can_create_an_exemplar_of_class2)
{
	ASSERT_NO_THROW(Arithmetic a('-'));
}

TEST(Arithmetic, can_create_an_exemplar_of_class3)
{
	ASSERT_NO_THROW(Arithmetic a(5.0));
}

TEST(Arithmetic, getx_getop_getf_are_correct)
{
	Arithmetic* a = new Arithmetic[2];
	a[0] = 1.0;
	a[1] = '(';
	EXPECT_EQ(1.0, a[0].GetX());
	EXPECT_EQ('(', a[1].GetOp());
	EXPECT_EQ(1, a[0].GetF());
	EXPECT_EQ(0, a[1].GetF());
}

TEST(Arithmetic, getpriority_is_correct)
{
	Arithmetic* a = new Arithmetic[2];
	a[0] = '$';
	a[1] = '(';
	EXPECT_EQ(1, a[1].GetPriority());
	ASSERT_ANY_THROW(a[0].GetPriority());	
}

TEST(Arithmetic, count1)
{
	Arithmetic a;
	string s = "3+5+2";
	EXPECT_EQ(10, a.result(s));
}

TEST(Arithmetic, count2)
{
	Arithmetic a;
	string s = "-3+3";
	EXPECT_EQ(0, a.result(s));
}

TEST(Arithmetic, count3)
{
	Arithmetic a;
	string s = "-7*(-5)";
	EXPECT_EQ(35, a.result(s));
}

TEST(Arithmetic, count4)
{
	Arithmetic a;
	string s = "-5/20";
	EXPECT_EQ(-0.25, a.result(s));
}

TEST(Arithmetic, count5)
{
	Arithmetic a;
	string s = "-10+30-15+45+(-50+25)";
	EXPECT_EQ(25, a.result(s));
}

TEST(Arithmetic, count6)
{
	Arithmetic a;
	string s = "48/24*3";
	EXPECT_EQ(6, a.result(s));
}

TEST(Arithmetic, count7)
{
	Arithmetic a;
	string s = "2/5*(-7+47)-10";
	EXPECT_EQ(6, a.result(s));
}

TEST(Arithmetic, count8)
{
	Arithmetic a;
	string s = "2--2";
	EXPECT_EQ(4, a.result(s));
}
