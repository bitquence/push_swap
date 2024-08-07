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

    empty = deque_new(64);
    ASSERT_NE(empty, nullptr);

    contiguous = deque_new(64);
    ASSERT_NE(contiguous, nullptr);

    full = deque_new(42);
    ASSERT_NE(full, nullptr);

    alphabet = deque_new(64);
    ASSERT_NE(alphabet, nullptr);

    non_unique = deque_new(64);
    ASSERT_NE(full, nullptr);

    all_equal = deque_new(64);
    ASSERT_NE(alphabet, nullptr);

    for (int num = 1; num <= 42; num++)
      deque_push_back(contiguous, num);

    for (int num = 1; num <= 42; num++)
      deque_push_back(full, num);

    for (char ch = 'N'; ch <= 'Z'; ch++)
      deque_push_back(alphabet, ch);
    for (char ch = 'M'; ch >= 'A'; ch--)
      deque_push_front(alphabet, ch);

    for (int i = 0; i < 63; i++)
      deque_push_back(non_unique, i);
    deque_push_back(non_unique, 63);

    for (int i = 0; i < 64; i++)
      deque_push_front(all_equal, 42);
  }

  void TearDown() override {
    deque_destroy(no_capacity);
    deque_destroy(empty);
    deque_destroy(contiguous);
    deque_destroy(full);
    deque_destroy(alphabet);
    deque_destroy(non_unique);
    deque_destroy(all_equal);
  }

  t_deque *no_capacity;
  t_deque *empty;
  t_deque *contiguous;
  t_deque *full;
  t_deque *alphabet;
  t_deque *non_unique;
  t_deque *all_equal;
};

TEST_F(DequeTest, LengthMatches) {
  EXPECT_EQ(no_capacity->len, 0);
  EXPECT_EQ(empty->len, 0);
  EXPECT_EQ(contiguous->len, 42);
  EXPECT_EQ(full->len, 42);
  EXPECT_EQ(alphabet->len, 26);
}

TEST_F(DequeTest, DequeIsEmpty) {
  EXPECT_TRUE(deque_is_empty(empty));
}

TEST_F(DequeTest, DequeIsNotEmpty) {
  EXPECT_FALSE(deque_is_empty(contiguous));
  EXPECT_FALSE(deque_is_empty(full));
  EXPECT_FALSE(deque_is_empty(alphabet));
}

TEST_F(DequeTest, DequeIsFull) {
  EXPECT_TRUE(deque_is_full(full));
}

// i still have no idea if i should handle this case, or if this behaviour makes
// sense even lmao
TEST_F(DequeTest, ZeroCapacityDequeIsBothEmptyAndFull) {
  EXPECT_TRUE(deque_is_full(no_capacity));
  EXPECT_TRUE(deque_is_empty(no_capacity));
}

TEST_F(DequeTest, DequeIsNotFull) {
  EXPECT_FALSE(deque_is_full(contiguous));
  EXPECT_FALSE(deque_is_full(alphabet));
}

t_compare_function always_false = [](int a, int b) {
  return int(false);
};

t_compare_function ascending_order = [](int a, int b) {
  return int(a < b);
};

TEST_F(DequeTest, NonContiguousDequeIsSorted) {
  EXPECT_TRUE(deque_is_sorted(alphabet, ascending_order));
}

TEST_F(DequeTest, ContiguousDequeIsSorted) {
  EXPECT_TRUE(deque_is_sorted(contiguous, ascending_order));
}

TEST_F(DequeTest, UnsortedDequeIsNotSorted) {
  std::swap(*deque_get_mut(alphabet, 4),
            *deque_get_mut(alphabet, 2));

  EXPECT_FALSE(deque_is_sorted(alphabet, ascending_order));
}

TEST_F(DequeTest, EmptyDequeIsAlwaysSorted) {
  EXPECT_TRUE(deque_is_sorted(empty, ascending_order));
  EXPECT_TRUE(deque_is_sorted(empty, always_false));

  EXPECT_TRUE(deque_is_sorted(no_capacity, ascending_order));
  EXPECT_TRUE(deque_is_sorted(no_capacity, always_false));
}

TEST_F(DequeTest, DequeIsUnsortedAccordingToFalseFunction) {
  EXPECT_FALSE(deque_is_sorted(alphabet, always_false));
}

TEST_F(DequeTest, CanGetElements) {
  for (char ch = 'A'; ch <= 'Z'; ch++)
    ASSERT_EQ((char)*deque_get(alphabet, ch - 'A'), ch);

  for (int i = 0; i < 42; i++)
    ASSERT_EQ(*deque_get(contiguous, i), i + 1);
}

TEST_F(DequeTest, OutOfBoundsGetReturnsNullptr) {
  ASSERT_EQ(deque_get(alphabet, 26), nullptr);
  ASSERT_EQ(deque_get(contiguous, 42), nullptr);

  ASSERT_EQ(deque_get(alphabet, 69), nullptr);
  ASSERT_EQ(deque_get(contiguous, 420), nullptr);

  ASSERT_EQ(deque_get(no_capacity, 0), nullptr);
  ASSERT_EQ(deque_get(empty, 0), nullptr);

  ASSERT_EQ(deque_get(no_capacity, 10), nullptr);
  ASSERT_EQ(deque_get(empty, 10), nullptr);
}

TEST_F(DequeTest, CanGetFirst) {
  ASSERT_EQ(*deque_first(alphabet), 'A');
  ASSERT_EQ(*deque_first(contiguous), 1);
}

TEST_F(DequeTest, CanGetLast) {
  ASSERT_EQ((char)*deque_last(alphabet), 'Z');
  ASSERT_EQ(*deque_last(contiguous), 42);
}

TEST_F(DequeTest, FirstAndLastReturnNullptrForEmptyDeque) {
  EXPECT_EQ(deque_first(no_capacity), nullptr);
  EXPECT_EQ(deque_last(no_capacity), nullptr);

  EXPECT_EQ(deque_first(empty), nullptr);
  EXPECT_EQ(deque_last(empty), nullptr);
}

TEST_F(DequeTest, CanPopBackFromContiguous) {
  ASSERT_EQ(deque_pop_back(contiguous), 42);
  ASSERT_EQ(deque_pop_back(contiguous), 41);
  ASSERT_EQ(deque_pop_back(contiguous), 40);

  ASSERT_EQ(contiguous->len, 39);
}

TEST_F(DequeTest, CanPopBackFromNonContiguous) {
  ASSERT_EQ((char)deque_pop_back(alphabet), 'Z');
  ASSERT_EQ((char)deque_pop_back(alphabet), 'Y');
  ASSERT_EQ((char)deque_pop_back(alphabet), 'X');

  ASSERT_EQ(alphabet->len, 23);
}

TEST_F(DequeTest, CanPopFrontFromContiguous) {
  ASSERT_EQ(deque_pop_front(contiguous), 1);
  ASSERT_EQ(deque_pop_front(contiguous), 2);
  ASSERT_EQ(deque_pop_front(contiguous), 3);

  ASSERT_EQ(contiguous->len, 39);
}

TEST_F(DequeTest, CanPopFrontFromNonContiguous) {
  ASSERT_EQ((char)deque_pop_front(alphabet), 'A');
  ASSERT_EQ((char)deque_pop_front(alphabet), 'B');
  ASSERT_EQ((char)deque_pop_front(alphabet), 'C');

  ASSERT_EQ(alphabet->len, 23);
}

TEST_F(DequeTest, CanPushBackToContiguous) {
  deque_push_back(contiguous, 43);

  ASSERT_EQ(*deque_last(contiguous), 43);
  ASSERT_EQ(contiguous->len, 43);
}

TEST_F(DequeTest, CanPushBackToNonContiguous) {
  deque_push_back(alphabet, 'z');

  ASSERT_EQ((char)*deque_last(alphabet), 'z');
  ASSERT_EQ(alphabet->len, 27);
}

TEST_F(DequeTest, CanPushFrontToContiguous) {
  deque_push_front(contiguous, 0);

  ASSERT_EQ(*deque_first(contiguous), 0);
  ASSERT_EQ(contiguous->len, 43);
}

TEST_F(DequeTest, CanPushFrontToNonContiguous) {
  deque_push_front(alphabet, 'a');

  ASSERT_EQ((char)*deque_first(alphabet), 'a');
  ASSERT_EQ(alphabet->len, 27);
}

TEST_F(DequeTest, CanRotateContiguousDequeOnceToTheLeft) {
  deque_rotate_once_left(contiguous);

  EXPECT_EQ(*deque_get(contiguous, 0), 2);
  EXPECT_EQ(*deque_get(contiguous, 1), 3);
  EXPECT_EQ(*deque_get(contiguous, 2), 4);

  EXPECT_EQ(*deque_get(contiguous, 39), 41);
  EXPECT_EQ(*deque_get(contiguous, 40), 42);
  EXPECT_EQ(*deque_get(contiguous, 41), 1);

  ASSERT_EQ(contiguous->len, 42);
}

TEST_F(DequeTest, CanRotateNonContiguousDequeOnceToTheLeft) {
  deque_rotate_once_left(alphabet);

  EXPECT_EQ((char)*deque_get(alphabet, 0), 'B');
  EXPECT_EQ((char)*deque_get(alphabet, 1), 'C');
  EXPECT_EQ((char)*deque_get(alphabet, 2), 'D');

  EXPECT_EQ((char)*deque_get(alphabet, 23), 'Y');
  EXPECT_EQ((char)*deque_get(alphabet, 24), 'Z');
  EXPECT_EQ((char)*deque_get(alphabet, 25), 'A');

  ASSERT_EQ(alphabet->len, 26);
}

TEST_F(DequeTest, CanRotateContiguousDequeOnceToTheRight) {
  deque_rotate_once_right(contiguous);

  EXPECT_EQ(*deque_get(contiguous, 0), 42);
  EXPECT_EQ(*deque_get(contiguous, 1), 1);
  EXPECT_EQ(*deque_get(contiguous, 2), 2);

  EXPECT_EQ(*deque_get(contiguous, 39), 39);
  EXPECT_EQ(*deque_get(contiguous, 40), 40);
  EXPECT_EQ(*deque_get(contiguous, 41), 41);

  ASSERT_EQ(contiguous->len, 42);
}

TEST_F(DequeTest, CanRotateNonContiguousDequeOnceToTheRight) {
  deque_rotate_once_right(alphabet);

  EXPECT_EQ((char)*deque_get(alphabet, 0), 'Z');
  EXPECT_EQ((char)*deque_get(alphabet, 1), 'A');
  EXPECT_EQ((char)*deque_get(alphabet, 2), 'B');

  EXPECT_EQ((char)*deque_get(alphabet, 23), 'W');
  EXPECT_EQ((char)*deque_get(alphabet, 24), 'X');
  EXPECT_EQ((char)*deque_get(alphabet, 25), 'Y');

  ASSERT_EQ(alphabet->len, 26);
}

TEST_F(DequeTest, RotateLeftThenRightHasNoEffect) {
  deque_rotate_once_left(alphabet);
  deque_rotate_once_right(alphabet);

  EXPECT_EQ((char)*deque_get(alphabet, 0), 'A');
  EXPECT_EQ((char)*deque_get(alphabet, 1), 'B');
  EXPECT_EQ((char)*deque_get(alphabet, 2), 'C');

  EXPECT_EQ((char)*deque_get(alphabet, 23), 'X');
  EXPECT_EQ((char)*deque_get(alphabet, 24), 'Y');
  EXPECT_EQ((char)*deque_get(alphabet, 25), 'Z');

  ASSERT_EQ(alphabet->len, 26);
}

TEST_F(DequeTest, CanPopBackAndPushIntoAgain) {
  t_deque_data element = deque_pop_back(alphabet);

  deque_push_back(alphabet, element);
  EXPECT_EQ((char)*deque_get(alphabet, alphabet->len - 1), 'Z');
  EXPECT_EQ(alphabet->len, 26);
}

TEST_F(DequeTest, CanPopFrontAndPushIntoAgain) {
  t_deque_data element = deque_pop_front(alphabet);

  deque_push_front(alphabet, element);
  EXPECT_EQ((char)*deque_get(alphabet, 0), 'A');
  EXPECT_EQ(alphabet->len, 26);
}

TEST_F(DequeTest, AllElementsAreUnique) {
  ASSERT_TRUE(deque_all_elements_are_unique(no_capacity));
  ASSERT_TRUE(deque_all_elements_are_unique(empty));
  ASSERT_TRUE(deque_all_elements_are_unique(alphabet));
  ASSERT_TRUE(deque_all_elements_are_unique(contiguous));
  ASSERT_TRUE(deque_all_elements_are_unique(full));
}

TEST_F(DequeTest, NotAllElementsAreUnique) {
  ASSERT_FALSE(deque_all_elements_are_unique(all_equal));
}
