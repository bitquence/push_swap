/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:56:59 by jamar             #+#    #+#             */
/*   Updated: 2024/04/07 02:57:15 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include <stdio.h>

const t_deque_data	*deque_get(const t_deque *self, size_t index)
{
	size_t	physical_index;

	if (index > self->len)
		return (NULL);
	physical_index = deque_physical_index(self, index);
	return (&self->data[physical_index]);
}

t_deque_data	*deque_get_mut(const t_deque *self, size_t index)
{
	const t_deque_data	*data;

	data = deque_get(self, index);
	return ((t_deque_data *)data);
}
