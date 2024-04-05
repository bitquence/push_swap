/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 03:25:42 by jamar             #+#    #+#             */
/*   Updated: 2024/03/31 03:25:44 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> // size_t
#include <stdint.h> // int64_t
#include <stdbool.h> // bool, true, false
#include <limits.h> // INT_MAX, INT_MIN
#include <errno.h> // errno, ERANGE, EINVAL

#define RADIX 10
#define NEGATIVE_SIGN '-'
#define POSITIVE_SIGN '+'

static inline bool	char_is_valid_digit(char ch)
{
	return (ch >= '0' && ch <= '9');
}

static inline bool	can_shift_and_add_in_int(int num, int addend, int radix)
{
	int64_t	result;

	result = (num * radix) + addend;
	return (result > INT_MIN && result < INT_MAX);
	/*
	if (addition >= 0)
		return (num <= (INT_MAX - addition) / radix);
	else
		return (num > (INT_MIN - addition) / radix);
	*/
}

static inline int	parse_digit(char ch)
{
	return (ch - '0');
}

bool	word_is_valid_number(const char *word)
{
	size_t	i;

	i = 0;
	if (word[i] == NEGATIVE_SIGN || word[i] == POSITIVE_SIGN)
		i++;
	if (word[i] == '\0')
		return (false);
	while (char_is_valid_digit(word[i]))
		i++;
	if (word[i] != '\0')
		return (false);
	return (true);
}

int	parse_number(const char *number, int *result)
{
	size_t	i;
	int		sign;

	*result = 0;
	i = 0;
	sign = 1;
	if (number[i] == NEGATIVE_SIGN || number[i] == POSITIVE_SIGN)
	{
		if (number[i] == NEGATIVE_SIGN)
			sign = -1;
		i++;
	}
	while (char_is_valid_digit(number[i]))
	{
		if (!can_shift_and_add_in_int(*result, sign * parse_digit(number[i]), RADIX))
		{
			errno = ERANGE;
			return (sign);
		}
		*result *= RADIX;
		*result += sign * parse_digit(number[i]);
		i++;
	}
	return (0);
}
