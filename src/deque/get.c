/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:56:59 by jamar             #+#    #+#             */
/*   Updated: 2024/08/06 15:31:06 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

const t_deque_data	*deque_get(const t_deque *self, size_t index)
{
	size_t	physical_index;

	if (index >= self->len)
		return (NULL);
	physical_index = deque_physical_index(self, index);
	return (&self->data[physical_index]);
}

t_deque_data	*deque_get_mut(t_deque *self, size_t index)
{
	size_t	physical_index;

	if (index >= self->len)
		return (NULL);
	physical_index = deque_physical_index(self, index);
	return (&self->data[physical_index]);
}
