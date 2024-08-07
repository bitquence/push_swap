/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:46:27 by jamar             #+#    #+#             */
/*   Updated: 2024/08/07 15:35:17 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "push_swap.h"

void	apply_operation(t_set_pair set_pair, t_operation operation)
{
	if (operation == OP_SWAP_A)
		op_swap(set_pair.set_a);
	if (operation == OP_SWAP_B)
		op_swap(set_pair.set_b);
	if (operation == OP_SWAP_BOTH)
		op_swap_both(set_pair.set_a, set_pair.set_b);
	if (operation == OP_PUSH_A)
		op_push(set_pair.set_b, set_pair.set_a);
	if (operation == OP_PUSH_B)
		op_push(set_pair.set_a, set_pair.set_b);
	if (operation == OP_ROTATE_A)
		op_rotate(set_pair.set_a);
	if (operation == OP_ROTATE_B)
		op_rotate(set_pair.set_b);
	if (operation == OP_ROTATE_BOTH)
		op_rotate_both(set_pair.set_a, set_pair.set_b);
	if (operation == OP_REVERSE_ROTATE_A)
		op_reverse_rotate(set_pair.set_a);
	if (operation == OP_REVERSE_ROTATE_B)
		op_reverse_rotate(set_pair.set_b);
	if (operation == OP_REVERSE_ROTATE_BOTH)
		op_reverse_rotate_both(set_pair.set_a, set_pair.set_b);
}
