/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:59:08 by jamar             #+#    #+#             */
/*   Updated: 2024/08/13 18:04:26 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "problem.h"
#include "deque_order.h"

void	sort_and_output_solution_for_small_array(t_state state);

int	radix_sort_number_is_candidate(t_deque_data number, unsigned int bit_index)
{
	return (((number >> bit_index) & 1) == 0);
}

void	bucketize_into_stack_b(t_state state, unsigned int bit_index)
{
	size_t	i;
	t_deque	*stack_a;
	size_t	numbers_to_check;

	i = 0;
	stack_a = state.stack_a;
	numbers_to_check = deque_len(stack_a);
	while (i < numbers_to_check)
	{
		if (radix_sort_number_is_candidate(*deque_first(stack_a), bit_index))
			apply_operation(state, OP_PUSH_B);
		else
			apply_operation(state, OP_ROTATE_A);
		i++;
	}
}

void	exhaust_stack_b_into_stack_a(t_state state)
{
	while ((int)deque_len(state.stack_b) > 0)
		apply_operation(state, OP_PUSH_A);
}

void	radix_sort_and_output_solution(t_state state)
{
	size_t	i;

	i = 0;
	while (!deque_is_sorted(state.stack_a, ascending_order))
	{
		bucketize_into_stack_b(state, i);
		exhaust_stack_b_into_stack_a(state);
		i++;
	}
}

void	sort_and_output_solution(t_state state)
{
	if (deque_is_sorted(state.stack_a, ascending_order))
		return ;
	if (deque_len(state.stack_a) <= 5)
		return (sort_and_output_solution_for_small_array(state));
	radix_sort_and_output_solution(state);
}
