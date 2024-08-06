/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   properties.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:41:22 by jamar             #+#    #+#             */
/*   Updated: 2024/08/06 14:34:29 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

bool	deque_is_empty(const t_deque *self)
{
	return (self->len == 0);
}

bool	deque_is_full(const t_deque *self)
{
	return (self->len >= self->cap);
}

bool	deque_is_sorted(const t_deque *self, t_compare_function cmp)
{
	t_deque_data	first;
	t_deque_data	second;
	size_t			i;

	if (self->len <= 0)
		return (true);
	i = 0;
	while (i < (self->len - 1))
	{
		first = *deque_get(self, i);
		second = *deque_get(self, i + 1);
		if (cmp(first, second) <= 0)
			return (false);
		i++;
	}
	return (true);
}
