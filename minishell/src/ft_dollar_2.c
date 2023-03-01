/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollar_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:09:32 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/18 16:58:10 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	str_dollar_len(t_split *sp, char *str, int idx)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (str && str[++i])
	{
		if (str[i] == '$' && sp->quotes[idx] != '\'')
		{
			if (sp->c_vlaue)
			{
				if (!sp->c_vlaue[idx])
					len += 1;
				else
					len += ft_strlen(sp->c_vlaue[idx]);
			}
			if (sp->dollar)
				i += ft_strlen(sp->dollar[idx]);
		}
		else
			len++;
	}
	return (len);
}

static void	fill_dollar(t_split *sp, char **new_str, char *str, int *idx)
{
	int	i[3];

	i[0] = -1;
	i[2] = 0;
	while (str && str[++i[0]])
	{
		if (str[i[0]] == '$' && str[i[0] + 1] && sp->quotes[*idx] != '\'')
		{
			i[1] = 0;
			while (sp->c_vlaue && sp->c_vlaue[*idx] && sp->c_vlaue[*idx][i[1]])
				(*new_str)[i[2]++] = sp->c_vlaue[*idx][i[1]++];
			i[0] += ft_strlen(sp->dollar[*idx]);
			(*idx)++;
		}
		else if (str[i[0]] == '$' && str[i[0] + 1] && sp->quotes[*idx] == '\'')
		{
			(*new_str)[i[2]++] = str[i[0]];
			(*idx)++;
		}
		else
			(*new_str)[i[2]++] = str[i[0]];
	}
	(*new_str)[i[2]] = 0;
}

char	**apply_dollar(t_split *sp)
{
	char	**new_str;
	int		i;
	int		dollar_idx;

	i = -1;
	new_str = (char **)malloc(sizeof(char *) * (two_point_size(sp->str) + 1));
	if (!new_str)
		return (NULL);
	while (++i <= two_point_size(sp->str))
		new_str[i] = 0;
	dollar_idx = 0;
	i = -1;
	while (sp->str[++i])
	{
		new_str[i] = (char *)malloc(sizeof(char) * \
			(str_dollar_len(sp, sp->str[i], dollar_idx) + 1));
		if (!new_str[i] && !free_two_point(new_str))
			return (NULL);
		one_point_null_fill(&new_str[i], \
				str_dollar_len(sp, sp->str[i], dollar_idx));
		fill_dollar(sp, &new_str[i], sp->str[i], &dollar_idx);
	}
	return (new_str);
}
