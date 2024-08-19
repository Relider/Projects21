#include <gtest/gtest.h>

#include <iostream>
#include <list>
#include <queue>

#include "s21_queue.h"

template <typename value_type>
bool compare_queues(s21::queue<value_type> s21_queue,
                    std::queue<value_type> std_queue) {
  bool result = true;
  if (s21_queue.size() == std_queue.size()) {
    while (!s21_queue.empty() && !std_queue.empty()) {
      if (s21_queue.front() != std_queue.front()) {
        result = false;
        break;
      }
      s21_queue.pop();
      std_queue.pop();
    }
  } else {
    result = false;
  }
  return result;
}

TEST(queue_test, constructor) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  EXPECT_TRUE(s21_queue.empty());
  bool result = true;
  while (!s21_queue.empty()) {
    if (s21_queue.front() != std_queue.front()) {
      result = false;
      break;
    }
    s21_queue.pop();
    std_queue.pop();
  }
  EXPECT_TRUE(result);
}

TEST(queue_test, constructor_init) {
  std::initializer_list<int> init_list = {1, 2, 3, 4, 5};
  s21::queue<int> s21_queue{init_list};
  std::queue<int> std_queue{init_list};
  bool result = true;
  while (!s21_queue.empty()) {
    if (s21_queue.front() != std_queue.front()) {
      result = false;
      break;
    }
    s21_queue.pop();
    std_queue.pop();
  }
  EXPECT_TRUE(result);
}

TEST(queue_test, copy) {
  std::initializer_list<int> init_list = {1, 2, 3, 7, 9};
  s21::queue<int> s21_queue{init_list};
  s21::queue<int> s21_queue_copy(s21_queue);
  std::queue<int> std_queue{init_list};
  std::queue<int> std_queue_copy(std_queue);
  bool result = true;
  while (!s21_queue_copy.empty()) {
    if (s21_queue_copy.front() != std_queue_copy.front()) {
      result = false;
      break;
    }
    s21_queue_copy.pop();
    std_queue_copy.pop();
  }
  EXPECT_TRUE(result);
}

TEST(queue_test, copy_empty) {
  s21::queue<int> s21_queue;
  s21::queue<int> s21_queue_copy(s21_queue);
  std::queue<int> std_queue;
  std::queue<int> std_queue_copy(std_queue);
  bool result = true;
  while (!s21_queue_copy.empty()) {
    if (s21_queue_copy.front() != std_queue_copy.front()) {
      result = false;
      break;
    }
    s21_queue_copy.pop();
    std_queue_copy.pop();
  }
  EXPECT_TRUE(result);
}

TEST(queue_test, move) {
  std::initializer_list<int> init_list = {1, 2, 3, 7, 20};
  s21::queue<int> s21_queue{init_list};
  s21::queue<int> s21_queue_move(std::move(s21_queue));
  std::queue<int> std_queue{init_list};
  std::queue<int> std_queue_move(std::move(std_queue));
  bool result = true;
  while (!s21_queue_move.empty()) {
    if (s21_queue_move.front() != std_queue_move.front()) {
      result = false;
      break;
    }
    s21_queue_move.pop();
    std_queue_move.pop();
  }
  EXPECT_TRUE(result);
}

TEST(queue_test, move_empty) {
  s21::queue<int> s21_queue;
  s21::queue<int> s21_queue_move(std::move(s21_queue));
  std::queue<int> std_queue;
  std::queue<int> std_queue_move(std::move(std_queue));
  bool result = true;
  while (!s21_queue_move.empty()) {
    if (s21_queue_move.front() != std_queue_move.front()) {
      result = false;
      break;
    }
    s21_queue_move.pop();
    std_queue_move.pop();
  }
  EXPECT_TRUE(result);
}

TEST(queue_test, move_assign_operator) {
  std::initializer_list<int> init_list = {1, 2, 3, 7, 20};
  s21::queue<int> s21_queue{init_list};
  s21::queue<int> s21_queue_move = std::move(s21_queue);
  std::queue<int> std_queue{init_list};
  std::queue<int> std_queue_move = std::move(std_queue);
  bool result = true;
  while (!s21_queue_move.empty()) {
    if (s21_queue_move.front() != std_queue_move.front()) {
      result = false;
      break;
    }
    s21_queue_move.pop();
    std_queue_move.pop();
  }
  EXPECT_TRUE(result);
}

TEST(queue_test, front) {
  std::initializer_list<int> init_list = {99, 1, 3, 7, 20};
  s21::queue<int> s21_queue{init_list};
  std::queue<int> std_queue{init_list};
  EXPECT_EQ(s21_queue.front(), std_queue.front());
}

TEST(queue_test, back) {
  std::initializer_list<int> init_list = {99, 1, 3, 5, 4, 7, 99};
  s21::queue<int> s21_queue{init_list};
  std::queue<int> std_queue{init_list};
  EXPECT_EQ(s21_queue.back(), std_queue.back());
}

TEST(queue_test, empty) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
  s21_queue.push(2);
  std_queue.push(2);
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(queue_test, scalb) {
  std::initializer_list<int> init_list = {1, 2, 3, 4, 5, 6, 7, 8};
  s21::queue<int> s21_queue{init_list};
  std::queue<int> std_queue{init_list};
  EXPECT_EQ(s21_queue.size(), std_queue.size());
}

TEST(queue_test, push) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  s21_queue.push(3);
  s21_queue.push(4);
  std_queue.push(3);
  std_queue.push(4);
  bool result = true;
  while (!s21_queue.empty()) {
    if (s21_queue.front() != std_queue.front()) {
      result = false;
      break;
    }
    s21_queue.pop();
    std_queue.pop();
  }
  EXPECT_TRUE(result);
}

TEST(queue_test, pop) {
  std::initializer_list<int> init_list = {1, 2, 3, 4, 5, 6, 7, 8};
  s21::queue<int> s21_queue{init_list};
  std::queue<int> std_queue{init_list};
  s21_queue.pop();
  s21_queue.pop();
  std_queue.pop();
  std_queue.pop();
  EXPECT_EQ(s21_queue.front(), 3);
  bool result = true;
  while (!s21_queue.empty()) {
    if (s21_queue.front() != std_queue.front()) {
      result = false;
      break;
    }
    s21_queue.pop();
    std_queue.pop();
  }
  EXPECT_TRUE(result);
}

TEST(queue_test, swap) {
  s21::queue<int> s21_queue1{1, 2, 3, 4, 5};
  s21::queue<int> s21_queue2{6, 7, 8, 9, 10, 11};
  s21_queue1.swap(s21_queue2);

  std::initializer_list<int> il1 = {1, 2, 3, 4, 5};
  std::initializer_list<int> il2 = {6, 7, 8, 9, 10, 11};
  std::queue<int> std_queue1{il1};
  std::queue<int> std_queue2{il2};
  std_queue1.swap(std_queue2);
  bool result = true;
  while (!s21_queue1.empty()) {
    if (s21_queue1.front() != std_queue1.front()) {
      result = false;
      break;
    }
    s21_queue1.pop();
    std_queue1.pop();
  }
  EXPECT_TRUE(result);
  result = true;
  while (!s21_queue2.empty()) {
    if (s21_queue2.front() != std_queue2.front()) {
      result = false;
      break;
    }
    s21_queue2.pop();
    std_queue2.pop();
  }
  EXPECT_TRUE(result);
}

TEST(queue_test, swap_empty) {
  s21::queue<int> s21_queue1{1, 2, 99, 4, 242};
  s21::queue<int> s21_queue2;
  s21_queue1.swap(s21_queue2);

  std::initializer_list<int> il = {1, 2, 99, 4, 242};
  std::queue<int> std_queue1{il};
  std::queue<int> std_queue2;
  std_queue1.swap(std_queue2);
  bool result = true;
  while (!s21_queue1.empty()) {
    if (s21_queue1.front() != std_queue1.front()) {
      result = false;
      break;
    }
    s21_queue1.pop();
    std_queue1.pop();
  }
  EXPECT_TRUE(result);
  result = true;
  while (!s21_queue2.empty()) {
    if (s21_queue2.front() != std_queue2.front()) {
      result = false;
      break;
    }
    s21_queue2.pop();
    std_queue2.pop();
  }
  EXPECT_TRUE(result);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}