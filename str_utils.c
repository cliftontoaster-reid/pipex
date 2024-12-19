/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:51:01 by lfiorell          #+#    #+#             */
/*   Updated: 2024/12/13 10:14:53 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/export/libft.h"
#include <stddef.h>

int	ft_strfreq(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

static char	*get_next_word(const char **s, char c)
{
	const char	*start = *s;

	while (**s && **s == c)
		(*s)++;
	start = *s;
	while (**s && **s != c)
		(*s)++;
	return (ft_strndup(start, *s - start));
}

int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

void	free_strs(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**ft_splitpath(char const *s, char c)
{
	int			word_count;
	const char	*current = s;
	char		**result;
	int			i;

	if (!s || !ft_strchr(s, c))
		return (NULL);
	word_count = ft_strfreq((char *)s, c);
	result = malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		result[i] = get_next_word(&current, c);
		if (!result[i])
		{
			free_strs(result);
			return (NULL);
		}
		i++;
	}
	result[word_count] = NULL;
	return (result);
}
