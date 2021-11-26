#include "../include/minishell.h"

void	env_pwd_input(t_env *env, char *path)
{
	int		i;
	int		index;
	char	*cp;

	i = -1;
	index = -1;
	while (env->envp[++i])
		if (!ft_strncmp(env->envp[i], "PWD=", ft_strlen("PWD=")))
			index = i;
	if (index == -1)
	{
		cp = ft_strjoin("PWD=", path);
		add_env(env, cp);
		free_one(cp);
	}
	else
	{
		cp = env->envp[index];
		env->envp[index] = ft_strjoin("PWD=", path);
		free_one(cp);
	}
}

void	env_oldpwd_input(t_env *env, char *path)
{
	int		i;
	int		index;
	char	*cp;

	i = -1;
	index = -1;
	while (env->envp[++i])
		if (!ft_strncmp(env->envp[i], "OLDPWD=", ft_strlen("OLDPWD=")))
			index = i;
	if (index == -1)
	{
		cp = ft_strjoin("OLDPWD=", path);
		add_env(env, cp);
		free_one(cp);
	}
	else
	{
		cp = env->envp[index];
		env->envp[index] = ft_strjoin("OLDPWD=", path);
		free_one(cp);
	}
}

int	cd_mark_minus(t_env *env, t_split *sp, int len)
{
	char	buf[PWD_SIZE];
	char	*path;

	if (!getcwd(buf, PWD_SIZE))
		return (error_printf(env, "cd: No such file or directory", 1));
	if (len == 1 || (len == 2 && sp->str[1][1] == '-'))
	{
		if (!select_path(env, "OLDPWD="))
			return (error_printf(env, "cd: OLDPWD not set", 1));
		path = ft_strdup(select_path(env, "OLDPWD="));
		if (chdir(path) == -1)
		{
			free_one(path);
			return (error_printf(env, "cd: No such file or directory", 1));
		}
		env_pwd_input(env, path);
		env_oldpwd_input(env, buf);//과거 위치
		printf("%s\n", path);
		free_one(path);
	}
	else if (len > 1 && sp->str[1][1] != '-')
		return (error_printf(env, \
			"cd: invalid option\ncd: usage: cd [dir]", 1));
	return (1);
}

int	cd_mark_wave(t_env *env, t_split *sp, int len)
{
	char	buf[PWD_SIZE];
	char	*cp;

	if (!getcwd(buf, PWD_SIZE))
		return (error_printf(env, "cd: No such file or directory", 1));
	cp = sp->str[1];
	if (len == 1)
		sp->str[1] = ft_strdup(select_path(env, "HOME="));
	else if (len > 1)
		sp->str[1] = ft_strjoin(select_path(env, "HOME="), sp->str[1] + 1);
	if (chdir(sp->str[1]) == -1)
	{
		free_one(cp);
		return (error_printf(env, "cd: No such file or directory", 1));
	}
	env_oldpwd_input(env, buf);
	env_pwd_input(env, sp->str[1]);
	free_one(cp);
	return (1);
}
