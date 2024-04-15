/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:48:35 by jamar             #+#    #+#             */
/*   Updated: 2024/04/15 15:50:02 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

static size_t	size_t_wrapping_sub(size_t a, size_t b)
{
	size_t	result;

	result = a - b;
	if (result > a)
		return (0);
	return (result);
}

// TODO: add bounds checks if used outside of `42cursus-push_swap`
void	deque_push_back(t_deque *self, t_deque_data data)
{
	self->data[deque_physical_index(self, self->len)] = data;
	self->len += 1;
}

void	deque_push_front(t_deque *self, t_deque_data data)
{
	if (self->head == 0)
		self->head = size_t_wrapping_sub(self->cap, 1);
	else
		self->head -= 1;
	self->len += 1;
	self->data[self->head] = data;
}
