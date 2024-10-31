#include "../lab3/stack.h"

#include "gtest.h"

TEST(TStack, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> m(5));
}

TEST(TStack, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TStack<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TStack, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TStack<int> m(-5));
}

TEST(TStack, can_create_copied_matrix)
{
  TStack<int> m(5);

  ASSERT_NO_THROW(TStack<int> m1(m));
}

TEST(TStack, copied_matrix_is_equal_to_source_one)
{
	TStack<int> m1(5);
	for (int i = 0; i < 5; i++)
	{
		m1[i][i] = i + 1;
	}

	TStack<int> m2(m1);
	EXPECT_EQ(m1, m2);
}

TEST(TStack, copied_matrix_has_its_own_memory)
{
	TStack<int> m1(5), m2(5);

	EXPECT_NE(&m1[0][0], &m2[0][0]);
}

TEST(TStack, can_get_size)
{
	TStack<int> m(5);
	EXPECT_EQ(5, m.GetSize());
}

TEST(TStack, can_set_and_get_element)
{
	TStack<int> m(5);
	int b = 10;
	m[2][3] = b;

	EXPECT_EQ(b, m[2][3]);
}

TEST(TStack, throws_when_set_element_with_negative_index)
{
	TStack<int> m(5);

	ASSERT_ANY_THROW(m[-1][-1] = 1);
}

TEST(TStack, throws_when_set_element_with_too_large_index)
{
	TStack<int> m(5);

	ASSERT_ANY_THROW(m[5][5] = 1);
}

TEST(TStack, can_assign_matrix_to_itself)
{
	TStack<int> m1(5);
	TStack<int> m2(m1);
	m1 = m1;

	EXPECT_EQ(m1, m2);
}

TEST(TStack, can_assign_matrices_of_equal_size)
{
	TStack<int> m1(5);
	TStack<int> m2(5);
	m2 = m1;

	EXPECT_EQ(m1, m2);
}

TEST(TStack, assign_operator_change_matrix_size)
{
	TStack<int> m1(5);
	TStack<int> m2(4);
	m2 = m1;

	EXPECT_EQ(5, m2.GetSize());
}

TEST(TStack, can_assign_matrices_of_different_size)
{
	TStack<int> m1(5);
	TStack<int> m2(4);
	m2 = m1;

	EXPECT_EQ(m1, m2);
}

TEST(TStack, compare_equal_matrices_return_true)
{
	TStack<int> m1(5), m2(5);

	EXPECT_EQ(true, m1 == m2);
}

TEST(TStack, compare_matrix_with_itself_return_true)
{
	TStack<int> m1(5);

	EXPECT_EQ(true, m1 == m1);
}

TEST(TStack, matrices_with_different_size_are_not_equal)
{
	TStack<int> m1(5), m2(4);

	EXPECT_EQ(false, m1 == m2);
}

TEST(TStack, can_add_matrices_with_equal_size)
{
	TStack<int> m1(1), m2(5), m3(5);
	m1[0][0] = 5;
	m2[0][0] = 5;
	m3[0][0] = m2[0][0]+ m1[0][0];

	EXPECT_EQ(m3[0][0], 10);
}

TEST(TStack, cant_add_matrices_with_not_equal_size)
{
	TStack<int> m1(5), m2(4);
	m1[0][0] = 5;
	m2[0][0] = 5;

	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TStack, can_subtract_matrices_with_equal_size)
{
	TStack<int> m1(5), m2(5), m3(5);
	m1[0][0] = 5;
	m2[0][0] = 15;
	m3[0][0] = m2[0][0] - m1[0][0];

	EXPECT_EQ(m3[0][0], 10);
}

TEST(TStack, cant_subtract_matrixes_with_not_equal_size)
{
	TStack<int> m1(5), m2(4);
	m1[0][0] = 5;
	m2[0][0] = 5;

	ASSERT_ANY_THROW(m1 - m2);
}

