/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 20:00:58 by daypark           #+#    #+#             */
/*   Updated: 2021/05/29 19:40:45 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int		w_num;
	int		flag;

	w_num = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			flag = 1;
			w_num++;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (w_num);
}

static char	**free_words(char **words)
{
	int		i;

	i = 0;
	while (words[i])
		free(words[i++]);
	free(words);
	return (NULL);
}

static char	**malloc_words(char ***words, int size)
{
	return (*words = (char **)malloc(sizeof(char *) * size));
}

static char	*malloc_words_idx(char **words, int size)
{
	return (*words = (char *)malloc(sizeof(char) * size));
}

char		**ft_split(char const *s, char c)
{
	char		**words;
	char const	*temp;
	size_t		idx;
	size_t		len;

	idx = 0;
	if (!s || !(malloc_words(&words, count_words(s, c) + 1)))
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			temp = s;
			len = 0;
			while (*s && *s++ != c)
				len++;
			if (!(malloc_words_idx(&words[idx], len + 1)))
				return (free_words(words));
			ft_strlcpy(*(words + idx++), temp, len + 1);
		}
		else
			s++;
	}
	words[idx] = NULL;
	return (words);
}
