#include "libft.h"

static char	**free_words(char **words)
{
	int		i;

	i = 0;
	while (words[i])
		free(words[i++]);
	free(words);
	return (NULL);
}

int	count_words(char *s, char c)
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
	char	quote;

	len = 0;
	while (*s && *s != c)
	{
		if (*s == '\'' || *s == '\"')
		{
			quote = *s++;
			while (*s && *s++ != quote)
				len++;
		}
		if (*s && *s++ != c)
			len++;
	}
	return (len);
}

static int	fill_words_idx(char	**words_idx, char *s, char c)
{
	int		s_inc;
	char	quote;
	char	*w;

	s_inc = 0;
	w = *words_idx;
	while (*s && *s != c)
	{
		if (*s != '\'' && *s != '\"' && ++s_inc)
			*w++ = *s++;
		else
		{
			quote = *s++;
			while (*s && *s != quote && ++s_inc)
				*w++ = *s++;
			s++;
			s_inc += 2;
		}
	}
	*w = '\0';
	return (s_inc);
}

char	**ft_split(char *s, char c)
{
	char	**words;
	int		idx;
	int		len;

	idx = 0;
	words = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!s || !words)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = get_word_len(s, c);
			words[idx] = (char *)malloc(sizeof(char) * (len + 1));
			if (!words[idx])
				return (free_words(words));
			s += fill_words_idx(&words[idx], s, c);
			idx++;
		}
		else
			s++;
	}
	words[idx] = NULL;
	return (words);
}
