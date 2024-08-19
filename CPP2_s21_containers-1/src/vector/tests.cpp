#include <gtest/gtest.h>

#include <iostream>
#include <vector>
#include "s21_vector.h"

TEST(VectorTest, Full_funcTest) {
  using namespace s21;
  vector<int> emp;
  vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_TRUE(v.empty() == false);
  EXPECT_TRUE(int(v.size()) == 5);
  ASSERT_EQ(v.max_size(), pow(2, 62) - 1);
  v.reserve(100);
  EXPECT_TRUE(v.capacity() == 100);
  v.shrink_to_fit();
  ASSERT_EQ(v.capacity(), v.size());
}

TEST(VectorTest, funcTest) {
  using namespace s21;
  vector<int> v = {1, 2, 3, 4, 5};
  vector<int> v2 = {1, 2, 3};
  v.push_back(6);
  EXPECT_TRUE(v[5] == 6);
  VectorIterator s = &v[3];
  v.insert(s, 10);
  ASSERT_EQ(v[3], 10);
  v.erase(s);
  ASSERT_EQ(v[3], 4);
  v.pop_back();
  ASSERT_EQ(v.back(), 5);
  v.swap(v2);
  ASSERT_EQ(v2.back(), 5);
  ASSERT_EQ(v.back(), 3);
  v.clear();
  ASSERT_EQ(int(v.size()), 0);
}

TEST(VectorTest, elaccessorTest) {
  using namespace s21;
  vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_TRUE(v.front() == 1);
  EXPECT_TRUE(v.back() == 5);
  EXPECT_TRUE(v.at(2) == 3);
  EXPECT_TRUE(v[1] == 2);
  int* f = v.data();
  EXPECT_TRUE(*f == 1);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
