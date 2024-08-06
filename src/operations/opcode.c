/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:46:38 by jamar             #+#    #+#             */
/*   Updated: 2024/08/06 13:46:40 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

const char	*operation_code_of(t_operation operation)
{
	const char	*opcodes[] = {
		"sa", "sb", "ss",
		"pa", "pb",
		"ra", "rb", "rr",
		"rra", "rrb", "rrr"
	};

	return (opcodes[operation]);
}
