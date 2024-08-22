/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsequence_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:53:00 by jamar             #+#    #+#             */
/*   Updated: 2024/08/21 18:53:01 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "deque.h"

size_t	max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

size_t	longest_continuously_increasing_subsequence_len(const t_deque *stack)
{
	size_t	i;
	size_t	max_sequence_len;
	size_t	sequence_len;

	i = 0;
	max_sequence_len = 1;
	sequence_len = 1;
	while (i < deque_len(stack) - 1)
	{
		if ((*deque_get(stack, i + 1) - *deque_get(stack, i)) == 1)
			sequence_len += 1;
		else
			sequence_len = max(sequence_len, max_sequence_len);
		i++;
	}
	return (sequence_len);
}
