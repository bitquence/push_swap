/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:15:31 by jamar             #+#    #+#             */
/*   Updated: 2024/04/11 19:41:46 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	deque_rotate_once_right(t_deque *self)
{
	t_deque_data	back_element;

	if (self->len > 1)
	{
		back_element = deque_pop_back(self);
		deque_push_front(self, back_element);
	}
}

void	deque_rotate_once_left(t_deque *self)
{
	t_deque_data	front_element;

	if (self->len > 1)
	{
		front_element = deque_pop_front(self);
		deque_push_back(self, front_element);
	}
}
