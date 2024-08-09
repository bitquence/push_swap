/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranked.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 00:19:21 by jamar             #+#    #+#             */
/*   Updated: 2024/08/09 00:19:23 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

static size_t	index_of(const t_deque *self, t_deque_data element)
{
	size_t	i;

	i = 0;
	while (i < deque_len(self))
	{
		if (*deque_get(self, i) == element)
			return (i);
	}
	return (0);
}

void	deque_make_ranked(t_deque *self, const t_deque *self_sorted)
{
	// is this needed?
	// assert (deque_is_unique(self_sorted));

	size_t			i;
	t_deque_data	*target_element;

	i = 0;
	while (i < deque_len(self))
	{
		target_element = *deque_get_mut(self, i);
		*target_element = deque_index_of(self_sorted, *target_element);
		i++;
	}
}
