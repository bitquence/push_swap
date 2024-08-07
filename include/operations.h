/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:15:19 by jamar             #+#    #+#             */
/*   Updated: 2024/08/07 17:02:43 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "deque.h"

/**
 * Swap the first 2 elements at the top of stack `deque`.
 *
 * Does nothing if there is only one or no elements.
 */
void	op_swap(t_deque *deque);

/**
 * Take the first element at the top of `from` and put it at the top of `into`.
 *
 * Does nothing if `a` is empty.
 */
void	op_push(t_deque *from, t_deque *into);

/**
 * Shift up all elements of stack `deque` by 1, meaning the first element
 * becomes the last one.
 *
 * [Does nothing if there are only one or no elements.]
 */
void	op_rotate(t_deque *deque);

/**
 * Shift down all elements of stack `deque` by 1, meaning the last element
 * becomes the first one.
 *
 * [Does nothing if there are only one or no elements.]
 */
void	op_reverse_rotate(t_deque *deque);

static inline void	op_swap_both(t_deque *a, t_deque *b)
{
	op_swap(a);
	op_swap(b);
}

static inline void	op_rotate_both(t_deque *a, t_deque *b)
{
	op_rotate(a);
	op_rotate(b);
}

static inline void	op_reverse_rotate_both(t_deque *a, t_deque *b)
{
	op_reverse_rotate(a);
	op_reverse_rotate(b);
}

#endif // OPERATIONS_H
