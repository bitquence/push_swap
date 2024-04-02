/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 22:37:40 by jamar             #+#    #+#             */
/*   Updated: 2024/03/31 22:37:42 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

#include <stddef.h> // size_t
#include <stdbool.h> // bool

size_t	string_length(const char *str);
int		parse_number(const char *number, int *result);
bool	word_is_valid_number(const char *word);

#endif // INPUT_H
