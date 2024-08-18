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

void	sort_and_output_solution(t_state state)
{
	if (deque_is_sorted(state.stack_a, ascending_order))
		return ;
	if (deque_len(state.stack_a) <= 5)
		return sort_and_output_solution_for_small_array(state);
	//radix_sort_and_output_solution(state);
}
