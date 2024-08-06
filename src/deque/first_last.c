/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:38:57 by jamar             #+#    #+#             */
/*   Updated: 2024/08/06 15:36:20 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

const t_deque_data	*deque_first(const t_deque *self)
{
	return (deque_get(self, 0));
}

// if the subtraction by 1 underflows then the bounds check inside of
// `deque_get` will return NULL
const t_deque_data	*deque_last(const t_deque *self)
{
	return (deque_get(self, self->len - 1));
}

t_deque_data	*deque_first_mut(t_deque *self)
{
	return (deque_get_mut(self, 0));
}

// if the subtraction by 1 underflows then the bounds check inside of
// `deque_get` will return NULL
t_deque_data	*deque_last_mut(t_deque *self)
{
	return (deque_get_mut(self, self->len - 1));
}
