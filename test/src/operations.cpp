#include <gtest/gtest.h>
//#include <climits>

extern "C" {
#include "operations.h"
};

class OperationsTest : public testing::Test {
protected:
  void SetUp() override {
    full = deque_new(64);
    ASSERT_NE(full, nullptr);

    half_full = deque_new(64);
    ASSERT_NE(half_full, nullptr);

    empty = deque_new(64);
    ASSERT_NE(empty, nullptr);

    singleton = deque_new(64);
    ASSERT_NE(singleton, nullptr);

    subject_case = deque_new(6);
    ASSERT_NE(subject_case, nullptr);

    for (int num = 32; num > -32; --num)
      deque_push_back(full, num);

    for (int num = 32; num > 0; --num)
      deque_push_back(half_full, num);

    deque_push_back(singleton, 42);

    for (int i : {2, 1, 3, 6, 5, 8})
      deque_push_back(subject_case, i);
  }

  void TearDown() override {
    deque_destroy(full);
    deque_destroy(half_full);
    deque_destroy(empty);
    deque_destroy(singleton);
    deque_destroy(subject_case);
  }

  t_deque *full;
  t_deque *half_full;
  t_deque *empty;
  t_deque *singleton;
  t_deque *subject_case;
};

TEST_F(OperationsTest, CanSwapOnFullDeque) {
  op_swap(full);

  EXPECT_TRUE(deque_is_full(full));
  ASSERT_EQ(*deque_first(full), 31);
  ASSERT_EQ(*deque_get(full, 1), 32);
}

TEST_F(OperationsTest, CanSwapOnHalfFullDeque) {
  op_swap(half_full);

  EXPECT_EQ(deque_len(half_full), 32);
  ASSERT_EQ(*deque_first(half_full), 31);
  ASSERT_EQ(*deque_get(half_full, 1), 32);
}

TEST_F(OperationsTest, SwapEmptyDequeHasNoEffect) {
  op_swap(empty);

  EXPECT_TRUE(deque_is_empty(empty));
}

TEST_F(OperationsTest, SwapSingletonDequeHasNoEffect) {
  op_swap(singleton);

  EXPECT_EQ(deque_len(singleton), 1);
  EXPECT_EQ(*deque_first(singleton), 42);
}

TEST_F(OperationsTest, CanPushIntoEmptyDeque) {
  op_push(full, empty);

  ASSERT_EQ(deque_len(full), 63);
  ASSERT_EQ(deque_len(empty), 1);
  ASSERT_EQ(*deque_first(full), 31);
  ASSERT_EQ(*deque_first(empty), 32);
}

TEST_F(OperationsTest, CanPushIntoHalfFullDeque) {
  op_push(full, half_full);

  ASSERT_EQ(deque_len(full), 63);
  ASSERT_EQ(deque_len(half_full), 33);
  ASSERT_EQ(*deque_first(full), 31);
  ASSERT_EQ(*deque_first(half_full), 32);
}

TEST_F(OperationsTest, CanPushOutOfSingletonDeque) {
  op_push(singleton, half_full);

  ASSERT_TRUE(deque_is_empty(singleton));
  ASSERT_EQ(deque_len(half_full), 33);
  ASSERT_EQ(deque_first(singleton), nullptr);
  ASSERT_EQ(*deque_first(half_full), 42);
}

TEST_F(OperationsTest, PushOutOfEmptyDequeHasNoEffect) {
  op_push(empty, half_full);

  EXPECT_TRUE(deque_is_empty(empty));
  ASSERT_EQ(deque_len(half_full), 32);
  //ASSERT_EQ(deque_first(empty), nullptr);
  ASSERT_EQ(*deque_first(half_full), 32);
}

//TEST_F(OperationsTest, CannotPushIntoFullDeque) {
//  op_push(singleton, full);
//}

TEST_F(OperationsTest, PushOutAndIntoSameDequeHasNoEffect) {
  op_push(half_full, half_full);

  EXPECT_EQ(deque_len(half_full), 32);
  EXPECT_EQ(*deque_first(half_full), 32);
}

TEST_F(OperationsTest, CanRotateFullDeque) {
  op_rotate(full);

  EXPECT_TRUE(deque_is_full(full));
  ASSERT_EQ(*deque_first(full), 31);
  EXPECT_EQ(*deque_get(full, 62), -31);
  ASSERT_EQ(*deque_last(full), 32);
}

TEST_F(OperationsTest, CanRotateHalfFullDeque) {
  op_rotate(half_full);

  EXPECT_EQ(deque_len(half_full), 32);
  ASSERT_EQ(*deque_first(half_full), 31);
  EXPECT_EQ(*deque_get(half_full, 30), 1);
  ASSERT_EQ(*deque_last(half_full), 32);
}

TEST_F(OperationsTest, RotateEmptyDequeHasNoEffect) {
  op_rotate(empty);

  EXPECT_TRUE(deque_is_empty(empty));
  //EXPECT_EQ(deque_first(empty), nullptr);
  //EXPECT_EQ(deque_last(empty), nullptr);
}

TEST_F(OperationsTest, RotateSingletonDequeHasNoEffect) {
  op_rotate(singleton);

  EXPECT_EQ(deque_len(singleton), 1);
  EXPECT_EQ(*deque_first(singleton), 42);
  //EXPECT_EQ(*deque_last(singleton), 42);
}

TEST_F(OperationsTest, CanReverseRotateFullDeque) {
  op_reverse_rotate(full);

  EXPECT_TRUE(deque_is_full(full));
  ASSERT_EQ(*deque_first(full), -31);
  EXPECT_EQ(*deque_get(full, 1), 32);
  ASSERT_EQ(*deque_last(full), -30);
}

TEST_F(OperationsTest, CanReverseRotateHalfFullDeque) {
  op_reverse_rotate(half_full);

  EXPECT_EQ(deque_len(half_full), 32);
  ASSERT_EQ(*deque_first(half_full), 1);
  EXPECT_EQ(*deque_get(half_full, 1), 32);
  ASSERT_EQ(*deque_last(half_full), 2);
}

TEST_F(OperationsTest, ReverseRotateEmptyDequeHasNoEffect) {
  op_reverse_rotate(empty);

  EXPECT_TRUE(deque_is_empty(empty));
  //EXPECT_EQ(deque_first(empty), nullptr);
  //EXPECT_EQ(deque_last(empty), nullptr);
}

TEST_F(OperationsTest, ReverseRotateSingletonDequeHasNoEffect) {
  op_reverse_rotate(singleton);

  EXPECT_EQ(deque_len(singleton), 1);
  EXPECT_EQ(*deque_first(singleton), 42);
  //EXPECT_EQ(*deque_last(singleton), 42);
}
