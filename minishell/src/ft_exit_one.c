#include "../include/minishell.h"

static int	arguments_error(t_env *env, t_split *sp, int size, int index)
{
	int	num;

	num = numeric_error(sp->str[1]);
	env->exit_n = 1;
	if (size == 1)
		ft_putstr_fd("exit\n", 2);
	if (num)
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
	else
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(sp->str[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		env->exit_n = 2;
	}
	free_all(env, sp, index);
	if (!num && sp->num == 1 && size == 1)
		exit(env->exit_n);
	return (1);
}

static int	exit_sense(t_env *env, t_split *sp, int sp_len)
{
	int	index;
	int	size;

	size = sp_list_size(sp);
	index = env_len(env);
	env->exit_n = 0;
	if (sp_len > 2)
		return (arguments_error(env, sp, size, index));
	ft_putstr_fd("exit\n", 1);
	if (sp_len == 2)
		env->exit_n = (ft_atoi(sp->str[1]) % 256);
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
