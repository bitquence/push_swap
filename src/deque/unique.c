/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unique.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:56:13 by jamar             #+#    #+#             */
/*   Updated: 2024/08/07 19:11:09 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include <stdbool.h>
#include <stddef.h>

bool	deque_all_elements_are_unique(const t_deque *deque)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (deque_len(deque) <= 1)
		return (true);
	while (i < deque_len(deque) - 1)
	{
		j = i + 1;
		while (j < deque_len(deque))
		{
			if (*deque_get(deque, i) == *deque_get(deque, j))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
