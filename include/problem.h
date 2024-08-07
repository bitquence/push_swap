/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   problem.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:25:32 by jamar             #+#    #+#             */
/*   Updated: 2024/08/07 18:13:37 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROBLEM_H
# define PROBLEM_H

# include "deque.h"

typedef enum e_operation {
	OP_SWAP_A,
	OP_SWAP_B,
	OP_SWAP_BOTH,
	OP_PUSH_A,
	OP_PUSH_B,
	OP_ROTATE_A,
	OP_ROTATE_B,
	OP_ROTATE_BOTH,
	OP_REVERSE_ROTATE_A,
	OP_REVERSE_ROTATE_B,
	OP_REVERSE_ROTATE_BOTH,
}	t_operation;

const char *operation_code_of(t_operation operation);

typedef struct s_state {
	t_deque	*stack_a;
	t_deque	*stack_b;
}	t_state;

static inline void	destroy_state(t_state state)
{
	deque_destroy(state.stack_a);
	deque_destroy(state.stack_b);
}

void	apply_operation(t_state state, t_operation operation);
void	sort_and_output_solution(t_state state);

#endif // PROBLEM_H
