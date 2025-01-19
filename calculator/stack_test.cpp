#include "pch.h"
#include "..//stack.h"

TEST(stack_test, DefaultConstructor) {
    Stack<int> stack;
    EXPECT_EQ(0, stack.getSize());
}

TEST(stack_test, getSize) {
    Stack<int> stack;
    EXPECT_EQ(0, stack.getSize());
    stack.push(1);
    EXPECT_EQ(1, stack.getSize());
    stack.push(2);
    EXPECT_EQ(2, stack.getSize());
}

TEST(stack_test, push) {
    Stack<int> stack;
    stack.push(1);
    EXPECT_EQ(1, stack.getSize());
    stack.push(2);
    EXPECT_EQ(2, stack.getSize());
    for (int i = 0; i < 13; ++i) {
        stack.push(i);
    }
    EXPECT_EQ(15, stack.getSize());
    stack.push(16);
    EXPECT_EQ(16, stack.getSize());
}

TEST(stack_test, pop) {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    EXPECT_EQ(2, stack.pop());
    EXPECT_EQ(1, stack.getSize());
    EXPECT_EQ(1, stack.pop());
    EXPECT_EQ(0, stack.getSize());
}

TEST(StackTest, isEmpty) {
    Stack<int> stack;
    EXPECT_TRUE(stack.isEmpty());
    stack.push(1);
    EXPECT_FALSE(stack.isEmpty());
}

TEST(StackTest, pushOperator) {
    Stack<int> stack;
    stack << 10;
    EXPECT_EQ(1, stack.getSize());
    stack << 2;
    EXPECT_EQ(2, stack.getSize());
    for (int i = 0; i < 13; ++i) {
        stack << i;
    }
    EXPECT_EQ(15, stack.getSize());
    stack << 16;
    EXPECT_EQ(16, stack.getSize());
}

TEST(StackTest, PopOperator) {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    EXPECT_EQ(2, stack.pop());
    EXPECT_EQ(1, stack.getSize());
    EXPECT_EQ(1, stack.pop());
    EXPECT_EQ(0, stack.getSize());
}

TEST(StackTest, CopyOperator) {
    Stack<int> original;
    original.push(1);
    original.push(2);
    Stack<int> copy;
    copy = original;
    EXPECT_EQ(2, copy.getSize());
    EXPECT_EQ(2, copy.pop());
    EXPECT_EQ(1, copy.pop());
}

TEST(StackTest, LessOperator) {
    Stack<int> stack1;
    stack1.push(1);
    stack1.push(2);
    Stack<int> stack2;
    stack2.push(1);
    EXPECT_TRUE(stack1 > stack2);
    EXPECT_FALSE(stack1 < stack2);
}

TEST(StackTest, MoreOperator) {
    Stack<int> stack1;
    stack1.push(1);
    Stack<int> stack2;
    stack2.push(1);
    stack2.push(2);
    EXPECT_TRUE(stack2 > stack1);
    EXPECT_FALSE(stack2 < stack1);
}

TEST(StackTest, EqualityOperator) {
    Stack<int> stack1;
    stack1.push(1);
    stack1.push(2);
    Stack<int> stack2;
    stack2.push(1);
    stack2.push(2);
    EXPECT_TRUE(stack1 == stack2);
    Stack<int> stack3;
    stack3.push(1);
    EXPECT_FALSE(stack1 == stack3);
}

TEST(StackTest, SquareBrackets) {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    EXPECT_EQ(1, stack[0]);
    EXPECT_EQ(2, stack[1]);
}

TEST(StackTest, lastElement) {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    EXPECT_EQ(2, stack.lastElement());
}