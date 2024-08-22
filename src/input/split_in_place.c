/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_in_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamar <jamar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:13:44 by jamar             #+#    #+#             */
/*   Updated: 2024/08/22 13:05:25 by jamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h> // bool
#include <stdlib.h> // malloc
#include <stddef.h> // size_t

static char	*ft_strchr(const char *str, char ch)
{
	size_t	i;

	i = 0;
	while (str[i] != ch)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)&str[i]);
}

static bool	char_is_in(char ch, const char *charset)
{
	return (ft_strchr(charset, ch) != NULL);
}

static char	*find_char_or_nul(const char *str, const char *charset)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && !char_is_in(str[i], charset))
		i++;
	return ((char *)&str[i]);
}

static size_t	word_count(char *str, const char *charset)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && char_is_in(str[i], charset))
			i++;
		if (str[i] != '\0')
			count += 1;
		while (str[i] != '\0' && !char_is_in(str[i], charset))
			i++;
	}
	return (count);
}

char	**split_in_place(char *str, const char *charset)
{
	size_t	i;
	size_t	wc;
	char	**slices;
	char	*next;

	i = 0;
	wc = word_count(str, charset);
	slices = malloc(sizeof(char *) * (wc + 1));
	if (!slices)
		return (NULL);
	slices[wc] = NULL;
	while (i < wc)
	{
		while (*str != '\0' && char_is_in(*str, charset))
			str++;
		next = find_char_or_nul(str, charset);
		if (*str != '\0')
		{
			*next = '\0';
			slices[i] = str;
			i++;
			str = next + 1;
		}
	}
	return (slices);
}
