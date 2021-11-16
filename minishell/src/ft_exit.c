#include "../include/minishell.h"

static int	env_len(t_env *env)
{
	int	i;
	int	index;

	i = -1;
	index = -1;
	while (env->envp[++i])
		if (!ft_strncmp(env->envp[i], "SHLVL=", 6))
			index = ft_atoi(env->envp[i] + 6);
	return (index);
}

static void	arguments_error(t_env *env, t_split *sp)
{
	int	size;

	size = sp_list_size(sp);
	if (size == 1)
	{
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		free_all(env, sp, 0);
	}
	else if (size > 2)
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
	env->exit_n = 1;
}

static void	single_exit(t_env *env, t_split *sp)
{
	int	index;
	int	size;

	size = sp_list_size(sp);
	index = env_len(env);
	if (size > 1)
		env->exit_n = 0;
	else
	{
		ft_putstr_fd("exit\n", 2);
		if (index > 2)
			env->exit_n = 0;
		tcsetattr(STDIN_FILENO, TCSANOW, &env->old_term);
		free_all(env, sp, index);
		exit(0);
	}
}

static void	double_exit(t_env *env, t_split *sp)
{
	int	index;
	int	size;

	size = sp_list_size(sp);
	index = env_len(env);
	if (size > 1)
		env->exit_n = 0;
	else
	{
		ft_putstr_fd("exit\n", 2);
		if (index > 2)
			env->exit_n = (ft_atoi(sp->str[1]) % 256);
		tcsetattr(STDIN_FILENO, TCSANOW, &env->old_term);
		free_all(env, sp, index);
		if (index > 2)
			exit(env->exit_n);
		else
			exit(0);
	}
}

void	ft_exit(t_env *env, t_split *sp)
{
	int	sp_len;

	sp_len = -1;
	while (sp->str[++sp_len])
		;
	if (sp_len > 2)
		arguments_error(env, sp);
	else if (sp_len == 1)
		single_exit(env, sp);
	else if (sp_len == 2)
		double_exit(env, sp);
}
