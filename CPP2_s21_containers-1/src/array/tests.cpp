#include <gtest/gtest.h>

#include <iostream>
#include <array>
#include "s21_array.h"

TEST(array_test, constructor_default) {
  const size_t size = 0;
  s21::array<int, size> s21_array;
  std::array<int, size> std_array;
  EXPECT_EQ(s21_array.empty(), std_array.empty());
}

TEST(array_test, constructor_with_no_data) {
  const size_t size = 5;
  s21::array<int, size> s21_array;
  std::array<int, size> std_array;
  EXPECT_EQ(s21_array.empty(), std_array.empty());
}

TEST(array_test, constructor_with_data) {
  const size_t size = 5;
  s21::array<int, size> s21_array = {1, 2, 3, 4, 5};
  std::array<int, size> std_array = {1, 2, 3, 4, 5};
  EXPECT_EQ(s21_array.empty(), std_array.empty());
  EXPECT_EQ(s21_array.size(), std_array.size());
  EXPECT_EQ(s21_array.max_size(), s21_array.max_size());
}

TEST(array_test, copy_constructor) {
  const size_t size = 5;
  s21::array<int, size> s21_array{1, 2, 3, 4, 5};
  std::array<int, size> std_array{1, 2, 3, 4, 5};
  EXPECT_EQ(s21_array.size(), std_array.size());
  auto s21_iterator = s21_array.begin();
  auto std_iterator = std_array.begin();
  bool result = true;
  for (size_t i = 0; i < s21_array.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(array_test, funcTest) {
  s21::array<int, 5> a1 = {1, 2, 3, 4, 5};
  s21::array<int, 5> a2 = {1, 2, 3, 2, 1};
  a1.swap(a2);
  ASSERT_EQ(a2.back(), 5);
  ASSERT_EQ(a1.back(), 1);
  a1.fill(2);
  ASSERT_EQ(a1.back(), 2);
  ASSERT_EQ(a1.front(), 2);
}

TEST(array_test, elaccessorTest) {
  s21::array<int, 5> a = {1, 2, 3, 4, 5};
  EXPECT_TRUE(a.front() == 1);
  EXPECT_TRUE(a.back() == 5);
  EXPECT_TRUE(a.at(2) == 3);
  EXPECT_TRUE(a[1] == 2);
  s21::ArrayIterator f = a.data();
  EXPECT_TRUE(*f == 1);
}

int main(int argc, char* arga[]) {
  ::testing::InitGoogleTest(&argc, arga);
  return RUN_ALL_TESTS();
}
