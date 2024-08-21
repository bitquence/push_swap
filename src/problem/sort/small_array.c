/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:58:43 by jamar             #+#    #+#             */
/*   Updated: 2024/08/13 19:04:50 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "problem.h"
#include "deque_order.h"

size_t	longest_continuously_increasing_subsequence_len(const t_deque *stack);

void	sort_and_output_solution_for_three_or_less(t_state state)
{
	t_deque *stack_a;

	stack_a = state.stack_a;
	if (longest_continuously_increasing_subsequence_len(stack_a) == 1)
		apply_operation(state, OP_SWAP_A);
	if (deque_is_sorted(stack_a, ascending_order) || deque_len(stack_a) <= 2)
		return ;
	if (*deque_first(stack_a) > *deque_get(stack_a, 1))
		apply_operation(state, OP_ROTATE_A);
	else
		apply_operation(state, OP_REVERSE_ROTATE_A);
}

void	sort_and_output_solution_for_small_array(t_state state)
{
	bool	sorting_more_than_three_integers;

	sorting_more_than_three_integers = (deque_len(state.stack_a) > 3);
	if (sorting_more_than_three_integers)
		return ;
		//push_smallest_numbers_out(state);
	sort_and_output_solution_for_three_or_less(state);
	if (sorting_more_than_three_integers)
		return ;
		//exhaust_stack_b_into_stack_a(state);
}
