/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 22:37:40 by jamar             #+#    #+#             */
/*   Updated: 2024/04/15 22:46:53 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include <stddef.h> // size_t
# include <stdbool.h> // bool
# include "deque.h"

char	**split_in_place(char *str, const char *charset);
size_t	string_length(const char *str);
int		parse_number(const char *number, int *result);
bool	word_is_valid_number(const char *word);

t_deque	*parse_numbers_from_string_array(char *words[], size_t count);
t_deque	*parse_numbers_from_whitespace_seperated_string(char *words);

#endif // INPUT_H
