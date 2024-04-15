/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:27:38 by jamar             #+#    #+#             */
/*   Updated: 2024/04/11 17:26:47 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H

# include <stdbool.h>
# include <stddef.h>

typedef int	t_deque_data;
typedef int	(*t_compare_function)(t_deque_data, t_deque_data);

typedef struct s_deque {
	size_t			cap;
	size_t			len;
	size_t			head;
	t_deque_data	data[];
}	t_deque;

t_deque				*deque_new(size_t cap);

bool				deque_is_empty(const t_deque *self);
bool				deque_is_full(const t_deque *self);
bool				deque_is_sorted(const t_deque *self, t_compare_function cmp);

const t_deque_data	*deque_get(const t_deque *self, size_t index);
t_deque_data		*deque_get_mut(const t_deque *self, size_t index);

t_deque_data		deque_pop_back(t_deque *self);
t_deque_data		deque_pop_front(t_deque *self);

void				deque_push_back(t_deque *self, t_deque_data data);
void				deque_push_front(t_deque *self, t_deque_data data);

void				deque_rotate_once_right(t_deque *self);
void				deque_rotate_once_left(t_deque *self);

/*
void				deque_make_contiguous(t_deque *self);
*/

void				deque_destroy(t_deque *self);

static inline size_t	deque_physical_index(const t_deque *self, size_t logical_index)
{
	return ((self->head + logical_index) % self->cap);
}

#endif // DEQUE_H
