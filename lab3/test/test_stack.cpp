#include "../lab3/stack.h"

#include "gtest.h"
			



TEST(TStack, can_create_stack_with_positive_size) {
    ASSERT_NO_THROW(TStack<int> stack(5));
}

TEST(TStack, throws_when_creating_stack_with_invalid_size) {
    ASSERT_ANY_THROW(TStack<int> stack(-5)); 
    ASSERT_ANY_THROW(TStack<int> stack(0)); 
}

TEST(TStack, can_push_and_pop_elements) {
    TStack<int> stack(3);
    stack.Push(10);
    stack.Push(20);

    EXPECT_EQ(20, stack.Pop());
    EXPECT_EQ(10, stack.Pop());
}


TEST(TStack, throws_when_popping_from_empty_stack) {
    TStack<int> stack(3);
    ASSERT_ANY_THROW(stack.Pop());
}


TEST(TStack, empty_returns_true_for_new_stack) {
    TStack<int> stack(3);
    EXPECT_TRUE(stack.isEmpty());
}


TEST(TStack, can_peek_top_element) {
    TStack<int> stack(3);
    stack.Push(10);
    stack.Push(20);

    EXPECT_EQ(20, stack.getTop());
    EXPECT_EQ(20, stack.getTop());
}

TEST(TStack, throws_when_peeking_into_empty_stack) {
    TStack<int> stack(3);
    ASSERT_ANY_THROW(stack.getTop());
}


TEST(TStack, can_clear_stack) {
    TStack<int> stack(3);
    stack.Push(10);
    stack.Push(20);

    stack.Clear();

    EXPECT_TRUE(stack.isEmpty());
    ASSERT_ANY_THROW(stack.Pop());
}


TEST(TStack, can_create_copied_stack) {
    TStack<int> stack(3);
    stack.Push(10);
    stack.Push(20);

    ASSERT_NO_THROW(TStack<int> copiedStack(stack));
}

TEST(TStack, copied_stack_is_equal_to_source) {
    TStack<int> stack(3);
    stack.Push(10);
    stack.Push(20);

    TStack<int> copiedStack(stack);

    EXPECT_EQ(copiedStack.Pop(), 20);
    EXPECT_EQ(copiedStack.Pop(), 10);
}


TEST(TStack, can_assign_stack_to_itself) {
    TStack<int> stack(5);
    stack.Push(10);
    stack.Push(20);

    stack = stack;

    EXPECT_FALSE(stack.isEmpty());
    EXPECT_EQ(20, stack.Pop());
    EXPECT_EQ(10, stack.Pop());
}

TEST(TStack, can_assign_stacks_of_equal_size) {
    TStack<int> stack1(5);
    stack1.Push(10);
    stack1.Push(20);

    TStack<int> stack2(5);
    stack2 = stack1;

    EXPECT_FALSE(stack2.isEmpty());
    EXPECT_EQ(stack2.Pop(), 20);
    EXPECT_EQ(stack2.Pop(), 10);
}

TEST(TStack, can_assign_stacks_of_different_size) {
    TStack<int> stack1(5);
    stack1.Push(10);
    stack1.Push(20);

    TStack<int> stack2(3);
    stack2 = stack1;

    EXPECT_EQ(stack2.Pop(), 20);
    EXPECT_EQ(stack2.Pop(), 10);
}


TEST(TStack, compare_equal_stacks_return_true) {
    TStack<int> stack1(3);
    stack1.Push(10);
    stack1.Push(20);

    TStack<int> stack2(3);
    stack2.Push(10);
    stack2.Push(20);

    EXPECT_TRUE(stack1 == stack2);
}

TEST(TStack, stacks_with_different_sizes_are_not_equal) {
    TStack<int> stack1(3);
    stack1.Push(10);
    stack1.Push(20);

    TStack<int> stack2(2);
    stack2.Push(10);

    EXPECT_FALSE(stack1 == stack2);
}



//---------------------------------------------------------------------------------------------

TEST(TCalc, can_set_and_get_infix_expression) {
    TCalc calc;
    calc.SetInfix("3 + 5");

    EXPECT_EQ("3 + 5", calc.GetInfix());
}

TEST(TCalc, can_not_create_wrong_postfix) {
    TCalc calc;
    calc.SetInfix("3 + 5))"); 

    ASSERT_ANY_THROW(calc.ToPostfix());
}

TEST(TCalc, can_convert_simple_expression_to_postfix) {
    TCalc calc;
    calc.SetInfix("3 + 5");
    calc.ToPostfix();

    EXPECT_EQ("3 5 + ", calc.GetPostfix());
}

TEST(TCalc, can_subtract_numbers) {
    TCalc calc;
    calc.SetInfix("10 - 4");
    double result = calc.Calc();

    EXPECT_EQ(6, result);
}

TEST(TCalc, can_multiply_numbers) {
    TCalc calc;
    calc.SetInfix("3 * 5");
    double result = calc.Calc();

    EXPECT_EQ(15, result);
}

TEST(TCalc, can_divide_numbers) {
    TCalc calc;
    calc.SetInfix("15 / 3");
    double result = calc.Calc();

    EXPECT_EQ(5, result);
}

TEST(TCalc, can_convert_expression_with_parentheses_to_postfix) {
    TCalc calc;
    calc.SetInfix("(3 + 5) * 2");
    calc.ToPostfix();

    EXPECT_EQ("3 5 + 2 * ", calc.GetPostfix());
}

TEST(TCalc, can_evaluate_simple_expression) {
    TCalc calc;
    calc.SetInfix("3 + 5");
    double result = calc.Calc();

    EXPECT_EQ(8, result);
}

TEST(TCalc, can_evaluate_expression_with_parentheses) {
    TCalc calc;
    calc.SetInfix("(3 + 5) * 2");
    double result = calc.Calc();

    EXPECT_EQ(16, result);
}

TEST(TCalc, can_handle_unary_minus) {
    TCalc calc;
    calc.SetInfix("-3 + 5");
    double result = calc.Calc();

    EXPECT_EQ(2, result);
}



TEST(TCalc, can_evaluate_expression_with_exponentiation) {
    TCalc calc;
    calc.SetInfix("2 ^ 3");
    double result = calc.Calc();

    EXPECT_EQ(8, result);
}

TEST(TCalc, throws_on_invalid_expression) {
    TCalc calc;
    calc.SetInfix("3 + * 5");

    ASSERT_ANY_THROW(calc.Calc());
}

TEST(TCalc, can_evaluate_nested_parentheses) {
    TCalc calc;
    calc.SetInfix("(9 + 56 * (7 - 7 / 4)* (77 + 1 * 8 - (3 + 4)))");
    double result = calc.Calc();
    double a = 9 + 56 * (7 - 7.0 / 4.0) * (77 + 1 * 8 - (3 + 4));

    EXPECT_EQ(a, result);
}
