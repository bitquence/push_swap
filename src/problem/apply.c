/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:46:27 by jamar             #+#    #+#             */
/*   Updated: 2024/08/13 18:13:22 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "operations.h"
#include "problem.h"
#include <stddef.h>
#include <unistd.h>

static void	register_operation(t_state state, t_operation operation)
{
	(void)state;
	const char	*mnemonic;

	mnemonic = operation_code_of(operation);
	write(STDOUT_FILENO, mnemonic, string_length(mnemonic));
	write(STDOUT_FILENO, "\n", 1);
}

void	apply_operation(t_state state, t_operation operation)
{
	register_operation(state, operation);
	if (operation == OP_SWAP_A)
		op_swap(state.stack_a);
	if (operation == OP_SWAP_B)
		op_swap(state.stack_b);
	if (operation == OP_SWAP_BOTH)
		op_swap_both(state.stack_a, state.stack_b);
	if (operation == OP_PUSH_A)
		op_push(state.stack_b, state.stack_a);
	if (operation == OP_PUSH_B)
		op_push(state.stack_a, state.stack_b);
	if (operation == OP_ROTATE_A)
		op_rotate(state.stack_a);
	if (operation == OP_ROTATE_B)
		op_rotate(state.stack_b);
	if (operation == OP_ROTATE_BOTH)
		op_rotate_both(state.stack_a, state.stack_b);
	if (operation == OP_REVERSE_ROTATE_A)
		op_reverse_rotate(state.stack_a);
	if (operation == OP_REVERSE_ROTATE_B)
		op_reverse_rotate(state.stack_b);
	if (operation == OP_REVERSE_ROTATE_BOTH)
		op_reverse_rotate_both(state.stack_a, state.stack_b);
}
