#include "../include/minishell.h"
// export, unset등 할때 추가 삭제 부분 (수정필요)
int	extend_envp(t_env *env)
{
	char	**new_envp;
	int		i;

	i = 0;
	while (env->envp[i])
		i++;
	new_envp = (char **)malloc(sizeof(char *) * (i + 2));
	if (!new_envp)
		return (1);
	i = -1;
	while (env->envp[++i])
	{
		new_envp[i] = ft_strdup(env->envp[i]);
		if (!new_envp[i])
			return (1);
	}
	new_envp[i] = NULL;
	new_envp[i + 1] = NULL;
	i = 0;
	while (env->envp[i])
		free(env->envp[i++]);
	free(env->envp);
	env->envp = new_envp;
	return (0);
}

// 쉘 속에서 쉘을 여는거니까 shell_level이 1 증가해야 한다.
// 환경변수에서 SHLVL을 찾아 해당 값을 1 올려준다.
void	set_shlvl(t_env *env, int index, int i)
{
	int		level;
	char	*str;

	if (index == -1)
	{
		env->envp[i] = ft_strdup("SHLVL=1");
		env->envp[i + 1] = NULL;
	}
	else
	{
		level = ft_atoi(env->envp[index] + 6) + 1;
		str = env->envp[index];
		env->envp[index] = ft_strjoin("SHLVL=", ft_itoa(level));
		free(str);
	}
}

int	copy_envp(t_env *env, char **envp)
{
	int		i;
	int		index;

	i = -1;
	index = -1;
	while (envp[++i])
		if (!ft_strncmp(envp[i], "SHLVL=", 6))
			index = i;
	if (index == -1)
		++i;
	env->env_len = i;
	env->envp = (char **)malloc(sizeof(char *) * i + 1);
	if (!env->envp)
		return (0);
	i = -1;
	while (envp[++i])
	{
		env->envp[i] = ft_strdup(envp[i]);
		if (!env->envp[i])
			return (0);
	}
	env->envp[i] = NULL;
	set_shlvl(env, index, i);
	return (1);
}
