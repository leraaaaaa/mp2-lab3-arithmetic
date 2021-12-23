// òåñòû äëÿ ñòåêà

#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_a_stack)
{
	ASSERT_NO_THROW(TStack <char> a);
}

TEST(TStack, cant_create_negative_size_stack)
{
	ASSERT_ANY_THROW(TStack <double> a(-1));
}

TEST(TStack, can_push)
{
	TStack <double> a;	
	double x = -5.5;
	ASSERT_NO_THROW(a.push(x));
}

TEST(TStack, can_pop)
{
	TStack <double> a;
	double x = -5.5;
	a.push(x);
	ASSERT_NO_THROW(a.pop());
}

TEST(TStack, pop_is_right)
{
	TStack <double> a;
	double x = -5.5, y = 1.0;
	a.push(x);
	a.push(y);
	EXPECT_EQ(a.pop(), 1.0);
	EXPECT_EQ(a.pop(), -5.5);
}

TEST(TStack, can_create_copy_stack)
{
	TStack <int> a(3);
	for (int i = 0; i < 3; i++)
		a.push(i);
	ASSERT_NO_THROW(TStack <int> b(a));
}

TEST(TStack, copy_stack_is_equal_to_first)
{
	TStack <int> a(3);
	for (int i = 0; i < 3; i++)
		a.push(i);
	TStack <int> b(a);
	EXPECT_EQ(a.pop(), b.pop());
}

TEST(TStack, throws_when_using_pop_with_an_empty_stack)
{
	TStack <char> a;
	ASSERT_ANY_THROW(a.pop());
}

TEST(TStack, stack_is_empty_by_default)
{
	TStack <char> a;
	EXPECT_EQ(a.IsEmpty(), true);
}

TEST(TStack, is_empty_is_right)
{
	TStack <int> a(3);
	for (int i = 0; i < 3; i++)
		a.push(i);
	EXPECT_EQ(a.IsEmpty(), false);
}

TEST(TStack, can_get_head)
{
	TStack <int> a(3);
	for (int i = 0; i < 3; i++)
		a.push(i);
	EXPECT_EQ(a.GetHead(), 3);
}

TEST(TStack, can_change_stack_size)
{
	TStack <int> a(3);
	for (int i = 0; i < 6; i++)
		a.push(i);
	EXPECT_EQ(a.pop(), 5);
}

TEST(TStack, can_clear_stack)
{
	TStack <double> a;
	double x = 2.3;
	a.push(x);
	a.clear();
	EXPECT_EQ(a.IsEmpty(), true);
}

TEST(TStack, cant_peek_with_an_empty_stack)
{
	TStack <double> a;
	ASSERT_ANY_THROW(a.peek());
}

TEST(TStack, cant_pop_with_an_empty_stack)
{
	TStack <double> a;
	ASSERT_ANY_THROW(a.pop());
}
