#include <gtest/gtest.h>

extern "C" {
#include "deque.h"
#include "problem.h"
#include "deque_order.h"
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
  t_state state = {
    .stack_a = subject_case,
    .stack_b = stack_b
  };
  t_operation solution[] = {
    OP_SWAP_A,
    OP_PUSH_B, OP_PUSH_B, OP_PUSH_B,
    OP_ROTATE_A, OP_ROTATE_B,
    OP_REVERSE_ROTATE_A, OP_REVERSE_ROTATE_B,
    OP_SWAP_A,
    OP_PUSH_A, OP_PUSH_A, OP_PUSH_A
  };

  for (t_operation op: solution)
    apply_operation(state, op);
  EXPECT_EQ(deque_len(state.stack_a), 6);
  EXPECT_TRUE(deque_is_empty(state.stack_b));
  EXPECT_TRUE(deque_is_sorted(state.stack_b, ascending_order));
}
