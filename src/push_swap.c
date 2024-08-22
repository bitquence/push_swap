/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:10:15 by jamar             #+#    #+#             */
/*   Updated: 2024/08/19 22:01:02 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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

__attribute__((noreturn))
static void	push_swap_cleanup_and_die(t_deque *a, t_deque *b)
{
	deque_destroy(a);
	deque_destroy(b);
	push_swap_die();
}

t_state	init_state_from_arguments_or_die(int argc, char *argv[])
{
	t_deque	*stack_a;
	t_deque	*sorted_stack_a;
	t_deque	*stack_b;

	if (argc == 2)
		stack_a = parse_numbers_from_whitespace_seperated_string(argv[1]);
	else
		stack_a = parse_numbers_from_string_array(&argv[1], argc - 1);
	if (stack_a == NULL)
		push_swap_die();
	sorted_stack_a = deque_sorted_unstable(stack_a);
	if (sorted_stack_a == NULL)
		push_swap_cleanup_and_die(stack_a, NULL);
	if (!deque_all_elements_are_unique_sorted(sorted_stack_a))
		push_swap_cleanup_and_die(stack_a, sorted_stack_a);
	deque_make_ranked(stack_a, sorted_stack_a);
	stack_b = deque_new(deque_len(stack_a));
	if (stack_b == NULL)
		push_swap_cleanup_and_die(stack_a, sorted_stack_a);
	deque_destroy(sorted_stack_a);
	return ((t_state){stack_a, stack_b});
}

int	main(int argc, char *argv[])
{
	t_state	state;

	if (argc > 1)
	{
		state = init_state_from_arguments_or_die(argc, argv);
		sort_and_output_solution(state);
		destroy_state(state);
	}
	return (EXIT_SUCCESS);
}
