/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:12:48 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/17 14:12:50 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	space_clear(char *rl, int *i)
{
	while (ft_isspace(rl[*i]))
		(*i)++;
	return (*i);
}

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_isquotes(char c)
{
	if (c == '\'' || c == '\"' || c == '$' || c == '/'
		|| c == '~' || c == '!' || c == '@' || c == '#'
		|| c == '%' || c == '^' || c == '&' || c == '*'
		|| c == '(' || c == ')' || c == '-' || c == '='
		|| c == '+' || c == '[' || c == ']' || c == '{'
		|| c == '}' || c == ',' || c == '.' || c == ':')
		return (1);
	return (0);
}

int	ft_special(char c)
{
	if (c == '~' || c == '!' || c == '@' || c == '#' || c == '$'
		|| c == '%' || c == '^' || c == '&' || c == '*'
		|| c == '(' || c == ')' || c == '-' || c == '='
		|| c == '+' || c == '[' || c == ']' || c == '{'
		|| c == '}' || c == ',' || c == '.' || c == ':')
		return (1);
	if (c == '?')
		return (2);
	if (c == '_')
		return (3);
	if (c == '\'' || c == '\"')
		return (4);
	return (0);
}
