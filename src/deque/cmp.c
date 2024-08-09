/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:29:01 by jamar             #+#    #+#             */
/*   Updated: 2024/08/09 10:29:01 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include <stdbool.h>

bool	deque_eq(const t_deque *a, const t_deque *b)
{
	size_t	len;
	size_t	i;

	if (deque_len(a) != deque_len(b))
		return (false);
	i = 0;
	len = deque_len(a);
	while (i < len)
	{
		if (*deque_get(a, i) != *deque_get(b, i))
			return (false);
		i++;
	}
	return (true);
}
