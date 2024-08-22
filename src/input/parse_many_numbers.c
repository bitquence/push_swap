/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_many_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:01:12 by jamar             #+#    #+#             */
/*   Updated: 2024/08/22 13:15:12 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "input.h"

t_deque	*parse_numbers_from_string_array(char *words[], size_t count)
{
	t_deque	*numbers;
	size_t	i;
	int		number;

	i = 0;
	numbers = deque_new(count);
	if (numbers == NULL)
		return (NULL);
	while (i < count)
	{
		if (!word_is_valid_number(words[i]) || \
			parse_number(words[i], &number) != 0)
		{
			deque_destroy(numbers);
			return (NULL);
		}
		deque_push_back(numbers, number);
		i++;
	}
	return (numbers);
}

static size_t	null_terminated_string_array_len(char **array)
{
	size_t	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

t_deque	*parse_numbers_from_whitespace_seperated_string(char *words)
{
	char	**word_array;
	size_t	word_count;
	t_deque	*numbers;

	word_array = split_in_place(words, " ");
	if (!word_array)
		return (NULL);
	word_count = null_terminated_string_array_len(word_array);
	numbers = parse_numbers_from_string_array(word_array, word_count);
	free(word_array);
	return (numbers);
}
