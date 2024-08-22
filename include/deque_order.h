/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_order.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 00:45:47 by jamar             #+#    #+#             */
/*   Updated: 2024/08/22 14:06:15 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_ORDER_H
# define DEQUE_ORDER_H

# include "deque.h"

static inline int	ascending_order(t_deque_data lhs, t_deque_data rhs)
{
	return (lhs - rhs);
}

#endif // DEQUE_ORDER_H
