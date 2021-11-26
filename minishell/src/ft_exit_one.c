#include "../include/minishell.h"

static int	arguments_error(t_env *env, t_split *sp, int size, int index)
{
	int		num;
	char	*cp;

	num = numeric_error(sp->str[1]);
	sp->i->two = 0;
	cp = sp->str[1];
	dollar_all_len(sp, sp->str[1]);
	sp->str[1] = dollar_change(sp, sp->str[1], 0);
	free_one(cp);
	env->exit_n = 1;
	if (size == 1)
		ft_putstr_fd("exit\n", 2);
	exit_error_collect(env, sp, num);
	free_all(env, sp, index);
	if (!num)
		exit(env->exit_n);
	return (1);
}

static int	exit_sense(t_env *env, t_split *sp, int sp_len)
{
	int		index;
	int		size;
	char	*cp;

	size = sp_list_size(sp);
	index = env_len(env);
	env->exit_n = 0;
	if (sp_len > 2)
		return (arguments_error(env, sp, size, index));
	ft_putstr_fd("exit\n", 1);
	if (sp_len == 2 && dollar_all_len(sp, sp->str[1]))
	{
		sp->i->two = 0;
		cp = sp->str[1];
		sp->str[1] = dollar_change(sp, sp->str[1], 0);
		free_one(cp);
		if (numeric_error(sp->str[1]))
			env->exit_n = (ft_atoi(sp->str[1]) % 256);
		else
			exit_error_collect(env, sp, 0);
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &env->old_term);
	free_all(env, sp, index);
	exit(env->exit_n);
}

void	ft_exit(t_env *env, t_split *sp)
{
	int	sp_len;

	sp_len = sp_str_len(sp);
	if (sp_len > 0)
		exit_sense(env, sp, sp_len);
}
