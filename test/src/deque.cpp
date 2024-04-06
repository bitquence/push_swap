#include <gtest/gtest.h>
#include <climits>

extern "C" {
#include "deque.h"
};

class DequeTest : public testing::Test {
protected:
  void SetUp() override {
	no_capacity = deque_new(0);
	ASSERT_NE(no_capacity, nullptr);

	contiguous = deque_new(42);
	ASSERT_NE(contiguous, nullptr);

	ascending = deque_new(25);
	ASSERT_NE(ascending, nullptr);

	for (int num = 1; num <= 42; num++)
		deque_push_back(contiguous, num);

	for (char ch = 'A'; ch <= 'Z'; ch++)
		deque_push_back(contiguous, ch);
  }

  void TearDown() override {
	deque_destroy(no_capacity);
	deque_destroy(contiguous);
	deque_destroy(ascending);
  }

  t_deque *no_capacity;
  t_deque *contiguous;
  t_deque *ascending;
};

TEST_F(DequeTest, IsInitiallyEmpty) { ASSERT_EQ(no_capacity->len, 0); }
