/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_unstable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:11:55 by jamar             #+#    #+#             */
/*   Updated: 2024/08/22 13:12:38 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include "deque_order.h"
#include <assert.h> // forbidden function!

static void	deque_swap_elements(t_deque *self, size_t i, size_t j)
{
	t_deque_data	ith_value;
	t_deque_data	jth_value;

	ith_value = *deque_get(self, i);
	jth_value = *deque_get(self, j);
	*deque_get_mut(self, i) = jth_value;
	*deque_get_mut(self, j) = ith_value;
}

// Partitions the deque from [start,end) (left inclusive, right exclusive)
static size_t	deque_partition(t_deque *self, size_t start, size_t end)
{
	t_deque_data	pivot;
	size_t			i;
	size_t			j;

	pivot = *deque_get(self, end - 1);
	i = start;
	j = start;
	while (i < end - 1)
	{
		if (*deque_get(self, i) <= pivot)
		{
			deque_swap_elements(self, i, j);
			j++;
		}
		i++;
	}
	deque_swap_elements(self, end - 1, j);
	return (j);
}

static void	deque_quick_sort(t_deque *self, size_t start, size_t end)
{
	size_t	pivot_index;

	if (start < end)
	{
		pivot_index = deque_partition(self, start, end);
		deque_quick_sort(self, start, pivot_index);
		deque_quick_sort(self, pivot_index + 1, end);
	}
}

void	deque_sort_unstable(t_deque *self)
{
	assert (deque_len(self) > 0); // forbidden function!
	deque_quick_sort(self, 0, deque_len(self));
	assert (deque_is_sorted(self, ascending_order)); // forbidden function!
}

t_deque	*deque_sorted_unstable(const t_deque *self)
{
	t_deque	*clone;

	clone = deque_clone(self);
	deque_sort_unstable(clone);
	return (clone);
}
