/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:25:32 by jamar             #+#    #+#             */
/*   Updated: 2024/08/07 15:35:25 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

typedef struct s_set_pair {
	t_deque	*set_a;
	t_deque	*set_b;
}	t_set_pair;

static inline void	destroy_set_pair(t_set_pair pair)
{
	deque_destroy(pair.set_a);
	deque_destroy(pair.set_b);
}

void	apply_operation(t_set_pair set_pair, t_operation operation);
void	sort_and_output_solution(t_set_pair set_pair);

#endif // PUSH_SWAP_H
