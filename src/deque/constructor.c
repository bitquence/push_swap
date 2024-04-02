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

/*
static void	write_bytes(void *s, unsigned char ch, size_t n)
{
	size_t			i;
	unsigned char	*bytes;

	i = 0;
	bytes = (unsigned char *)s;
	while (i < n)
	{
		bytes[i] = ch;
		i++;
	}
}
*/

t_deque	*deque_new(size_t cap)
{
	t_deque	*this;
	size_t	size_in_bytes;

	size_in_bytes = sizeof(t_deque) + (cap * sizeof(t_deque_data));
	this = malloc(size_in_bytes);
	/* write_bytes(this, '\0', size_in_bytes); */
	return (this);
}
