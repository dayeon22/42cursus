#include "../include/minishell.h"

int	str_dollar_len(t_split *sp, char *str, int dollar_idx)
{
	int	len;

	len = 0;
	while (*str)
	{
		if (*str == '$')
		{
			if (!sp->c_vlaue[dollar_idx])
			{
				str += (ft_strlen(sp->dollar[dollar_idx]) + 1);
				continue ;
			}
			if (sp->quotes[dollar_idx] == '\'')
				len += ft_strlen(sp->dollar[dollar_idx]);
			else
				len += ft_strlen(sp->c_vlaue[dollar_idx]);
			str += 1 + ft_strlen(sp->dollar[dollar_idx++]);
		}
		else
		{
			len++;
			str++;
		}
	}
	return (len);
}

void	fill_dollar(char **new_str, char **str, t_split *sp, int *dollar_idx)
{
	char	*temp;

	if (**str == '$')
	{
		if (!sp->c_vlaue[*dollar_idx])
		{
			*str += ft_strlen(sp->dollar[(*dollar_idx)++]) + 1;
			return ;
		}
		temp = *new_str;
		if (sp->quotes[*dollar_idx] == '\'')
		{
			(*new_str)[ft_strlen(*new_str)] = '$';
			(*new_str) = ft_strjoin(*new_str, sp->dollar[*dollar_idx]);
		}
		else
			*new_str = ft_strjoin(*new_str, sp->c_vlaue[*dollar_idx]);
		free(temp);
		temp = NULL;
		*str += ft_strlen(sp->dollar[(*dollar_idx)++]) + 1;
	}
	else
		(*new_str)[ft_strlen(*new_str)] = *(*str)++;
}

char	*malloc_zero(int size)
{
	int		i;
	char	*ret;

	ret = (char *)malloc(sizeof(char) * size);
	if (!ret)
		return (NULL);
	i = 0;
	while (ret[i])
		ret[i++] = '\0';
	return (ret);
}

char	**apply_dollar(t_split *sp)
{
	char	**new_str;
	char	*str;
	int		i;
	int		dollar_idx;

	i = 0;
	while (sp->str[i])
		i++;
	new_str = (char **)malloc(sizeof(char *) * (i + 1));
	if (!new_str)
		return (NULL);
	dollar_idx = 0;
	i = -1;
	while (sp->str[++i])
	{
		str = sp->str[i];
		new_str[i] = malloc_zero(str_dollar_len(sp, str, dollar_idx) + 1);
		if (!new_str[i])
			free_two(new_str); //return(free_two(new_str[i]))
		while (*str)
			fill_dollar(&new_str[i], &str, sp, &dollar_idx);
	}
	new_str[i] = NULL;
	return (new_str);
}
