#include "../include/minishell.h"

static int	echo_other(t_env *env, t_split *sp)
{
	int	i;
	int	j;

	i = 0;
	while (sp->str[++i])
	{
		j = -1;
		while (sp->str[i][++j])
			printf("%c", sp->str[i][j]);
		if (sp->str[i + 1])
			printf(" ");
	}
	printf("\n");
	env->exit_n = 0;
	return (1);
}

static int	echo_option(t_env *env, t_split *sp)
{
	int	i;
	int	j;

	i = 1;
	while (sp->str[++i])
	{
		j = -1;
		while (sp->str[i][++j])
			printf("%c", sp->str[i][j]);
		if (sp->str[i + 1])
			printf(" ");
	}
	env->exit_n = 0;
	return (1);
}

static int	echo_sense(t_env *env, t_split *sp, int len)
{
	int		i;
	char	*cp;

	env->exit_n = 0;
	if (len == 1)
		printf("\n");
	else if (len > 1)
	{
		i = -1;
		sp->i->two = 0;
		while (sp->str[++i])
		{
			cp = sp->str[i];
			dollar_all_len(sp, sp->str[i]);
			sp->str[i] = dollar_change(sp, sp->str[i], 0);
			free_one(cp);
		}
		if (!ft_strcmp(sp->str[1], "-n") && len == 2)
			return (1);
		else if (!ft_strcmp(sp->str[1], "-n") && len > 2)
			return (echo_option(env, sp));
		else
			return (echo_other(env, sp));
	}
	env->exit_n = 0;
	return (1);
}

int	ft_echo(t_env *env, t_split *sp)
{
	int	len;

	len = sp_str_len(sp);
	echo_sense(env, sp, len);
	free_all(env, sp, 0);
	return (1);
}
