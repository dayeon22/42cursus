/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:12:58 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/18 17:42:06 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	**free_words(char **words)
{
	int		i;

	i = 0;
	while (words[i])
		free(words[i++]);
	free(words);
	return (NULL);
}

static int	count_words(char *s, char c)
{
	int	cnt;
	int	flag;
	int	quote;

	cnt = 0;
	flag = 0;
	while (*s)
	{
		if (*s == '\'' || *s == '\"')
		{
			quote = *s++;
			while (*s != quote)
				s++;
		}
		if (*s != c && flag == 0)
		{
			flag = 1;
			cnt++;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (cnt);
}

static int	get_word_len(char *s, char c)
{
	int		len;
	int		i;
	char	quote;

	len = 0;
	i = -1;
	while (s[++i])
	{
		if (ft_special(s[i]) == 4)
		{
			quote = s[i];
			while (s[++i] != quote)
				++len;
		}
		if (s[i] == c)
			break ;
		++len;
	}
	return (len);
}

static int	fill_words_idx(char	**words_idx, char *s, char c)
{
	int		s_inc;
	int		i;
	int		j;
	char	quote;

	i = -1;
	j = 0;
	s_inc = 0;
	while (s && s[++i] != c && s[i] != 0)
	{
		if (s[i] != '\'' && s[i] != '\"' && ++s_inc)
			(*words_idx)[j++] = s[i];
		else
		{
			quote = s[i++];
			while (s[i] && s[i] != quote && ++s_inc)
				(*words_idx)[j++] = s[i++];
			s_inc += 2;
		}
	}
	(*words_idx)[j] = 0;
	return (s_inc);
}

char	**ft_split_mini(char *s, char c)
{
	char	**words;
	int		idx;

	idx = -1;
	words = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!s || !words)
		return (NULL);
	while (++idx <= count_words(s, c))
		words[idx] = 0;
	idx = -1;
	while (*s)
	{
		if (*s != c && ++idx > -1)
		{
			words[idx] = (char *)malloc(sizeof(char) * \
					(get_word_len(s, c) + 1));
			if (!words[idx])
				return (free_words(words));
			one_point_null_fill(&words[idx], get_word_len(s, c));
			s += fill_words_idx(&words[idx], s, c);
		}
		else
			s++;
	}
	return (words);
}
