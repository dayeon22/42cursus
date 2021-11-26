#include "../include/minishell.h"

char	**envp_lookup(char **envp, char *find)
{
	int		i;
	char	**path;

	i = -1;
	while (envp[++i])
		if (!ft_strncmp(envp[i], find, 5))
			break ;
	if (!envp[i])
		return (0);
	path = ft_split(envp[i] + 5, ':');
	if (!path)
		return (0);
	return (path);
}

int	lookup_bin_path(char *order, char **path, char **envp)
{
	char	**bin_path;
	int		check;

	if (ft_strchr(order, '/'))
	{
		*path = ft_strdup(order);
		if (!(*path))
			return (-1);
		return (1);
	}
	bin_path = envp_lookup(envp, "PATH=");
	if (!bin_path)
		return (-1);
	check = bin_complete(order, bin_path, path);
	free_two(bin_path);
	return (check);
}

void	exec_bin_path(t_split *sp, t_env *env)
{
	int		check;
	char	*path;

	check = lookup_bin_path(sp->str[0], &path, env->envp);
	if (check == -1)
		free_exit(sp, env, -1);
	else if (check == 0)
		free_exit(sp, env, 127);
	execve(path, sp->str, env->envp);
	free(path);
}

int	single_list_cmd(t_split *sp, t_env *env)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		exec_bin_path(sp, env);
	wait(&status);
	return (command_exit(status));
}

int	cmd_start(t_env *env, t_split *sp)
{
	int	cmd_count;
	int	check;

	cmd_count = sp_list_size(sp);
	(void)env;
	if (!cmd_count)
		return (1);
	check = check_builtin(env, sp);
	if (cmd_count == 1 && check == 1)
		check = single_list_cmd(sp, env);
	else
		check = 0;
	return (check);
}
