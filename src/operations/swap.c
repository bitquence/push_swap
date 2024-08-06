/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:48:12 by jamar             #+#    #+#             */
/*   Updated: 2024/08/06 16:05:59 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include "operations.h"
#include "assert.h"

void	op_swap(t_deque *deque)
{
	t_deque_data	first;
	t_deque_data	second;

	if (deque_len(deque) <= 1)
		return;
	first = deque_pop_front(deque);
	second = deque_pop_front(deque);
	deque_push_front(deque, first);
	deque_push_front(deque, second);
}

void	op_push(t_deque *lhs, t_deque *rhs)
{
	t_deque_data	lhs_first;

	if (deque_len(lhs) == 0)
		return;
	assert (!deque_is_full(rhs)); // forbidden function!
	lhs_first = deque_pop_front(lhs);
	deque_push_front(rhs, lhs_first);
}

void	op_rotate(t_deque *deque)
{
	deque_rotate_once_left(deque);
}

void	op_reverse_rotate(t_deque *deque)
{
	deque_rotate_once_right(deque);
}
