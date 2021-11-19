#include "../include/minishell.h"

int	get_dollar_env(t_split *sp, char *str, int size)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(str);
	while (sp->t_env->envp[++i])
	{
		if (!ft_strncmp(sp->t_env->envp[i], str, len) &&
			sp->t_env->envp[i][len] == '=' && sp->t_env->envp[i][len + 1] != 0)
			{
				sp->c_vlaue[size] = ft_strdup(sp->t_env->envp[i] + (len + 1));
				if (!sp->c_vlaue[size])
					return (0);
				return (1);
			}
		else
			sp->c_vlaue[size] = 0;
	}
	return (1);
}

int	sp_dollar_count(t_split *sp, char *s, int i, int size)
{
	int	be;
	int	j;

	be = i;
	while (s[i] && !ft_isquotes(s[i]) && !ft_isspace(s[i]))
		++i;
	sp->dollar[size] = (char *)ft_calloc(sizeof(char), i + 1);
	if (!sp->dollar[size])
		return (0);
	j = 0;
	while (be < i)
	{
		sp->dollar[size][j] = s[be];
		j++;
		be++;
	}
	if (!get_dollar_env(sp, sp->dollar[size], size))
		return (0);
	if (!sp->dollar[size])
		return (0);
	return (1);
}

int	dollar_count(char *rl)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (rl[++i])
	{
		if (i > 0 && rl[i - 1] == '$' && !ft_isspace(rl[i])
			&& !ft_isquotes(rl[i]))
			++len;
	}
	return (len);
}

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

char	**apply_dollar(t_split *sp)
{
	char	**new_str;
	int		i;
	int		dollar_idx;
	char	*str;
	char	*temp;

	i = 0;
	dollar_idx = 0;
	while (sp->str[i])
		i++;
	new_str = (char **)malloc(sizeof(char *) * (i + 1)); //실패처리
	i = -1;
	while (sp->str[++i])
	{
		str = sp->str[i];
		// printf("str %d\n", str_dollar_len(sp, str, dollar_idx);
	//	new_str[i] = (char *)ft_calloc(str_dollar_len(sp, str, dollar_idx) + 1, sizeof(char)); //실패처리
		new_str[i] = (char *)malloc(sizeof(char) * (str_dollar_len(sp, str, dollar_idx) + 1));
		int j = -1;
		while (new_str[i][++j])
			new_str[i][j] = '\0';
		while (*str)
		{
			if (*str == '$')
			{
				if (!sp->c_vlaue[dollar_idx])
				{
					str += ft_strlen(sp->dollar[dollar_idx++]) + 1;
					continue ;
				}
				temp = new_str[i];
				if (sp->quotes[dollar_idx] == '\'')
				{
					new_str[i][ft_strlen(new_str[i])] = '$';
					new_str[i] = ft_strjoin(new_str[i], sp->dollar[dollar_idx]);
				}
				else
				{
					new_str[i] = ft_strjoin(new_str[i], sp->c_vlaue[dollar_idx]);
				}
				free(temp);
				temp = 0;
				str += ft_strlen(sp->dollar[dollar_idx++]) + 1;
			}
			else
			{
				new_str[i][ft_strlen(new_str[i])] = *str++;
			}
		}
	}
	new_str[i] = NULL;

	i = -1;
	while (new_str[++i])
		printf("%s|\n", new_str[i]);

	return (new_str);
}
