/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:27:38 by jamar             #+#    #+#             */
/*   Updated: 2024/03/25 17:51:41 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H

# include <stdbool.h>
# include <stddef.h>

typedef int	t_deque_data;
typedef int	(*t_compare_function)(int, int);

typedef struct s_deque {
# if 0
	size_t			cap;
# endif
	size_t			len;
	size_t			head;
	t_deque_data	data[];
}	t_deque;

t_deque			*deque_new(size_t cap);

/*
bool				deque_is_sorted(const t_deque *self, t_compare_function cmp);
const t_deque_data	*deque_get(const t_deque *self, size_t index);
t_deque_data		*deque_get_mut(const t_deque *self, size_t index);

t_deque_data		deque_pop_back(t_deque *self, size_t index);
t_deque_data		deque_pop_front(t_deque *self, size_t index);

void				deque_push_back(t_deque *self, t_deque_data data);
void				deque_push_front(t_deque *self, t_deque_data data);

void				deque_make_contiguous(t_deque *self);
*/

void			deque_destroy(t_deque *self);

#endif // DEQUE_H
