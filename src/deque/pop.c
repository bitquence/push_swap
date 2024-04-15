/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 23:54:51 by jamar             #+#    #+#             */
/*   Updated: 2024/04/15 16:12:19 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h> // forbidden function
#include "deque.h"

t_deque_data	deque_pop_back(t_deque *self)
{
	assert (!deque_is_empty(self)); // forbidden function
	self->len -= 1;
	return (self->data[deque_physical_index(self, self->len)]);
}

t_deque_data	deque_pop_front(t_deque *self)
{
	size_t	old_head;

	assert (!deque_is_empty(self)); // forbidden function
	old_head = self->head;
	self->head = deque_physical_index(self, 1);
	self->len -= 1;
	return (self->data[old_head]);
}
