#include <gtest/gtest.h>

#include <iostream>

#include "s21_map.h"

TEST(MapTest, Full_funcTest) {
  s21::map<int, std::string> m;
  EXPECT_EQ(int(m.size()), 0);
  EXPECT_TRUE(m.empty());
}

TEST(mapConstructorTest, CopyConstructor) {
  s21::map<int, std::string> s21_map{{1, "one"}, {2, "two"}, {3, "tree"}};
  s21::map<int, std::string> s21_copy{{1, "one"}, {2, "two"}, {3, "tree"}};
  std::map<int, std::string> std_map{{1, "one"}, {2, "two"}, {3, "tree"}};
  std::map<int, std::string> std_copy{{1, "one"}, {2, "two"}, {3, "tree"}};
  EXPECT_EQ(s21_copy.size(), std_copy.size());
  EXPECT_FALSE(s21_copy.empty());
}

TEST(mapTest, MaxSize) {
  s21::map<int, std::string> map;
  std::map<int, std::string> map1;
  EXPECT_GT(map.max_size(), map1.max_size());
}

TEST(mapTest, Erase) {
  s21::map<int, std::string> map;
  map.insert({1, "one"});
  map.insert({2, "two"});
  map.insert({3, "three"});
  map.insert({5, "five"});
  auto it1 = map.begin()++;
  map.erase(it1);
  EXPECT_EQ(int(map.size()), 3);
  EXPECT_TRUE(map.contains(1));
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
