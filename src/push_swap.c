/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:10:15 by jamar             #+#    #+#             */
/*   Updated: 2024/08/07 18:18:52 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "deque.h"
#include "input.h"
#include "problem.h"

#define ERROR_MESSAGE "Error\n"

__attribute__((noreturn))
static void	push_swap_die(void)
{
	write(STDERR_FILENO, ERROR_MESSAGE, string_length(ERROR_MESSAGE));
	exit(EXIT_FAILURE);
}

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

t_state	init_state_from_arguments_or_die(int argc, char *argv[])
{
	t_state	state;

	if (argc <= 1)
		push_swap_die();
	state.stack_a = parse_numbers_from_string_array(&argv[1], argc - 1);
	state.stack_b = deque_new(deque_len(state.stack_a));
	if (state.stack_a == NULL || state.stack_b == NULL)
	{
		destroy_state(state);
		push_swap_die();
	}
	return (state);
}

int	main(int argc, char *argv[])
{
	t_state	state;

	state = init_state_from_arguments_or_die(argc, argv);
	if (!deque_all_elements_are_unique(state.stack_a))
	{
		destroy_state(state);
		push_swap_die();
	}
	sort_and_output_solution(state);
	destroy_state(state);
}
