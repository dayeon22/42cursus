#include "../include/minishell.h"

static void	invalid_error(t_env *env, t_split *sp)
{
	ft_putstr_fd("minishell: pwd: ", 2);
	ft_putchar_fd(sp->str[1][0], 2);
	ft_putchar_fd(sp->str[1][1], 2);
	ft_putstr_fd(" invalid option\n", 2);
	ft_putstr_fd("pwd: usage: pwd no option\n", 2);
	free_all(env, sp, 0);
}

static void	single_pwd(t_env *env, t_split *sp)
{
	int		size;
	char	buf[PWD_SIZE];

	size = sp_list_size(sp);
	if (size == 1)
	{
		getcwd(buf, PWD_SIZE);
		ft_putstr_fd(buf, 1);
		write(1, "\n", 1);
		free_all(env, sp, 0);
	}
	else if (size > 2)
		return ;
}

static void	double_pwd(t_env *env, t_split *sp)
{
	int		size;
	char	buf[PWD_SIZE];

	size = sp_list_size(sp);
	if (size == 1)
	{
		if (ft_strlen(sp->str[1]) >= 2 && sp->str[1][0] == '-')
			invalid_error(env, sp);
		else
		{
			getcwd(buf, PWD_SIZE);
			ft_putstr_fd(buf, 1);
			write(1, "\n", 1);
			free_all(env, sp, 0);
		}
	}
	else if (size > 2)
		return ;
}

void	ft_pwd(t_env *env, t_split *sp)
{
	int	sp_len;

	sp_len = -1;
	while (sp->str[++sp_len])
		;
	if (sp_len == 1)
		single_pwd(env, sp);
	else if (sp_len >= 2)
		double_pwd(env, sp);
}
