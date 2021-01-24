/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:34:34 by daypark           #+#    #+#             */
/*   Updated: 2021/01/24 05:46:03 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**free_words(char **words)
{
	int		i;

	i = 0;
	while (words[i])
		free(words[i++]);
	free(words);
	return (0);
}

static size_t	word_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		if (!s)
			s++;
	}
	return (count);
}

char			**ft_split(char const *s, char c)
{
	char		**words;
	char const	*pos;
	size_t		idx;
	size_t		len;

	idx = 0;
	if (!s || !(words = malloc(sizeof(char *) * (word_count(s, c) + 1))))
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			pos = s;
			len = 0;
			while (*s && *s++ != c)
				++len;
			if (!(words[idx] = malloc(sizeof(char) * (len + 1))))
				return (free_words(words));
			ft_strlcpy(*(words + idx++), pos, len + 1);
		}
		else
			s++;
	}
	words[idx] = 0;
	return (words);
}
