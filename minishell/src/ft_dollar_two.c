#include "../include/minishell.h"

int	dollar_all_len(t_split *sp, char *str)
{
	int	s_size;
	int	d_size;
	int	i;
	int	num;

	i = -1;
	d_size = 0;
	s_size = ft_strlen(str);
	num = dollar_count(str);
	while (++i < num)
	{
		if (sp->quotes[i] == '\'')
		{
			d_size += (ft_strlen(sp->dollar[i]) + 1);
			s_size -= (ft_strlen(sp->dollar[i]) + 1);
		}
		else
		{
			d_size += ft_strlen(sp->c_vlaue[i]);
			s_size -= (ft_strlen(sp->dollar[i]) + 1);
		}
	}
	sp->i->a_len = s_size + d_size;
	return (1);
}

void	dollar_while(t_split *sp, char *s, char *cp)
{
	if (sp->c_vlaue[sp->i->two] && sp->quotes[sp->i->two] != '\'')
	{
		while (sp->c_vlaue[sp->i->two][++sp->i->a_len])
			cp[sp->i->tree++] = sp->c_vlaue[sp->i->two][sp->i->a_len];
		sp->i->one += ft_strlen(sp->dollar[sp->i->two]);
	}
	else if (sp->c_vlaue[sp->i->two] && sp->quotes[sp->i->two] == '\'')
	{
		while (++sp->i->a_len < (int)(ft_strlen(sp->dollar[sp->i->two]) + 1))
			cp[sp->i->tree++] = s[sp->i->one++];
		--sp->i->one;
	}
	else if (!sp->c_vlaue[sp->i->two] && sp->quotes[sp->i->two] != '\'')
		sp->i->one += ft_strlen(sp->dollar[sp->i->two]);
}

char	*dollar_change(t_split *sp, char *s, char *cp)
{
	sp->i->one = -1;
	sp->i->tree = 0;
	cp = (char *)ft_calloc(sizeof(char), sp->i->a_len + 1);
	if (!cp)
		return (0);
	while (s[++sp->i->one])
	{
		if (s[sp->i->one] == '$' && !ft_strncmp((s + sp->i->one + 1), \
			sp->dollar[sp->i->two], ft_strlen(sp->dollar[sp->i->two])))
		{
			sp->i->a_len = -1;
			dollar_while(sp, s, cp);
			sp->i->two++;
		}
		else
			cp[sp->i->tree++] = s[sp->i->one];
	}
	cp[sp->i->tree] = 0;
	return (cp);
}
