#include <gtest/gtest.h>

extern "C" {
#include "deque.h"
#include "problem.h"
};

class ProblemTest : public testing::Test {
protected:
  void SetUp() override {
    subject_case = deque_new(6);
    ASSERT_NE(subject_case, nullptr);

    stack_b = deque_new(1024);
    ASSERT_NE(stack_b, nullptr);

    for (int i : {2, 1, 3, 6, 5, 8})
      deque_push_back(subject_case, i);
  }

  void TearDown() override {
    deque_destroy(subject_case);
    deque_destroy(stack_b);
  }

  t_deque *subject_case;
  t_deque *stack_b;
};

TEST_F(ProblemTest, SubjectTestCase) {
  t_set_pair pair = {
    .set_a = subject_case,
    .set_b = stack_b
  };
  t_operation solution[] = {
    OP_SWAP_A,
    OP_PUSH_B, OP_PUSH_B, OP_PUSH_B,
    OP_ROTATE_A, OP_ROTATE_B,
    OP_REVERSE_ROTATE_A, OP_REVERSE_ROTATE_B,
    OP_SWAP_A,
    OP_PUSH_A, OP_PUSH_A, OP_PUSH_A
  };
  t_compare_function ascending_order = (t_compare_function)[](int a, int b) {
    return int(a < b);
  };

  for (t_operation op: solution)
    apply_operation(pair, op);
  EXPECT_EQ(deque_len(pair.set_a), 6);
  EXPECT_TRUE(deque_is_empty(pair.set_b));
  EXPECT_TRUE(deque_is_sorted(pair.set_b, ascending_order));
}
