/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:15:19 by jamar             #+#    #+#             */
/*   Updated: 2024/08/06 17:18:44 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

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

void	apply_operation(t_set_pair set_pair, t_operation operation);

/**
 * Swap the first 2 elements at the top of stack `deque`.
 *
 * Does nothing if there is only one or no elements.
 */
void	op_swap(t_deque *deque);

/**
 * Take the first element at the top of `lhs` and put it at the top of `rhs`.
 *
 * Does nothing if `lhs` is empty.
 */
void	op_push(t_deque *lhs, t_deque *rhs);

/**
 * Shift up all elements of stack `deque` by 1, meaning the first element
 * becomes the last one.
 *
 * [Does nothing if there are only one or no elements.]
 */
void	op_rotate(t_deque *deque);

/**
 * Shift down all elements of stack `deque` by 1, meaning the last element
 * becomes the first one.
 *
 * [Does nothing if there are only one or no elements.]
 */
void	op_reverse_rotate(t_deque *deque);

#endif // OPERATIONS_H
