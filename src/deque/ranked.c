/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranked.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 00:19:21 by jamar             #+#    #+#             */
/*   Updated: 2024/08/09 17:03:33 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include <assert.h>

static size_t	index_of(const t_deque *self_sorted, t_deque_data element)
{
	size_t	start;
	size_t	midpoint;
	size_t	end;

	start = 0;
	end = deque_len(self_sorted) - 1;
	while (start <= end)
	{
		midpoint = start + (end - start) / 2;
		if (*deque_get(self_sorted, midpoint) == element)
			return (midpoint);
		if (*deque_get(self_sorted, midpoint) < element)
			start = midpoint + 1;
		else
			end = midpoint - 1;
	}
	return (0);
}

void	deque_make_ranked(t_deque *self, const t_deque *self_sorted)
{
	size_t			i;
	t_deque_data	*target_element;

	assert (deque_len(self) == deque_len(self_sorted));
	i = 0;
	while (i < deque_len(self))
	{
		target_element = deque_get_mut(self, i);
		*target_element = index_of(self_sorted, *target_element);
		i++;
	}
}
