/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:26:55 by jamar             #+#    #+#             */
/*   Updated: 2024/03/25 17:35:19 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "deque.h"

t_deque	*deque_new(size_t cap)
{
	t_deque	*this;
	size_t	size_in_bytes;

	size_in_bytes = sizeof(t_deque) + (cap * sizeof(t_deque_data));
	this = malloc(size_in_bytes);
	if (this != NULL)
		*this = (t_deque){
			.cap = cap,
			.len = 0,
			.head = 0,
		};
	return (this);
}
