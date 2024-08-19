#include <gtest/gtest.h>

#include <iostream>
#include <stack>

#include "s21_stack.h"

TEST(stack_test, constructor) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;
  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(stack_test, constructor_init) {
  std::initializer_list<int> init_stack = {1, 2, 3};
  s21::stack<int> s21_stack{init_stack};
  std::stack<int> std_stack{init_stack};
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(stack_test, constructor_copy) {
  std::initializer_list<int> init_list_1 = {1, 2, 3};
  s21::stack<int> s21_stack{init_list_1};
  s21::stack<int> s21_stack_copy{s21_stack};
  std::stack<int> std_stack{init_list_1};
  std::stack<int> std_stack_copy{std_stack};
  EXPECT_EQ(s21_stack_copy.size(), std_stack_copy.size());
  EXPECT_EQ(s21_stack_copy.top(), std_stack_copy.top());
}

TEST(stack_test, constructor_move) {
  std::initializer_list<int> init_list_1 = {1, 2, 3};
  s21::stack<int> s21_stack{init_list_1};
  s21::stack<int> s21_stack_move{s21_stack};
  std::stack<int> std_stack{init_list_1};
  std::stack<int> std_stack_move{std_stack};
  EXPECT_EQ(s21_stack_move.size(), std_stack_move.size());
  EXPECT_EQ(s21_stack_move.top(), std_stack_move.top());
}

TEST(stack_test, top) {
  std::initializer_list<int> init_list_1 = {4, 5, 6, 7};
  s21::stack<int> s21_stack{init_list_1};
  std::stack<int> std_stack{init_list_1};
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(stack_test, top_throw) {
  std::initializer_list<int> init_list_1;
  s21::stack<int> s21_stack{init_list_1};
  EXPECT_THROW(s21_stack.top(), std::out_of_range);
}

TEST(stack_test, empty_not_empty) {
  std::initializer_list<int> init_list_1 = {4, 5, 6, 7};
  s21::stack<int> s21_stack{init_list_1};
  std::stack<int> std_stack{init_list_1};
  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(stack_test, empty) {
  std::initializer_list<int> init_list_1;
  s21::stack<int> s21_stack{init_list_1};
  std::stack<int> std_stack{init_list_1};
  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(stack_test, size) {
  std::initializer_list<int> init_list_1 = {4, 5, 6, 7};
  s21::stack<int> s21_stack{init_list_1};
  std::stack<int> std_stack{init_list_1};
  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(stack_test, push) {
  std::initializer_list<int> init_list_1 = {4, 5, 6, 7};
  s21::stack<int> s21_stack{init_list_1};
  std::stack<int> std_stack{init_list_1};
  s21_stack.push(1);
  std_stack.push(1);
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(stack_test, push_to_empty) {
  std::initializer_list<int> init_list_1;
  s21::stack<int> s21_stack{init_list_1};
  std::stack<int> std_stack{init_list_1};
  s21_stack.push(1);
  std_stack.push(1);
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(stack_test, pop) {
  std::initializer_list<int> init_list_1 = {4, 5, 6, 7};
  s21::stack<int> s21_stack{init_list_1};
  std::stack<int> std_stack{init_list_1};
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(stack_test, pop_throw) {
  std::initializer_list<int> init_list_1;
  s21::stack<int> s21_stack{init_list_1};
  EXPECT_THROW(s21_stack.pop(), length_error);
}

TEST(stack_test, swap) {
  std::initializer_list<int> init_list_1 = {4, 5, 6, 7};
  std::initializer_list<int> init_list_2 = {1, 2, 3};
  s21::stack<int> s21_stack{init_list_1};
  s21::stack<int> s21_stack_swap{init_list_2};
  std::stack<int> std_stack{init_list_1};
  std::stack<int> std_stack_swap{init_list_2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
  EXPECT_EQ(s21_stack_swap.top(), std_stack_swap.top());
}

TEST(StackTest, swap_empty) {
  std::initializer_list<int> init_list_1 = {4, 5, 6, 7};
  std::initializer_list<int> init_list_2;
  s21::stack<int> s21_stack{init_list_1};
  s21::stack<int> s21_stack_swap{init_list_2};
  std::stack<int> std_stack{init_list_1};
  std::stack<int> std_stack_swap{init_list_2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
}

TEST(StackTest, swap_full_empty) {
  std::initializer_list<int> init_list_1;
  std::initializer_list<int> init_list_2;
  s21::stack<int> s21_stack{init_list_1};
  s21::stack<int> s21_stack_swap{init_list_2};
  std::stack<int> std_stack{init_list_1};
  std::stack<int> std_stack_swap{init_list_2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}