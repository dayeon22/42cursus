#include "../include/minishell.h"

void	sort_env(char **envp, int envp_len)
{
	int		i;
	int		j;
	char	*temp;

	i = -1;
	while (++i < envp_len - 1)
	{
		j = -1;
		while (++j < envp_len - i - 1)
		{
			if (ft_strcmp(envp[j], envp[j + 1]) == 1)
			{
				temp = envp[j];
				envp[j] = envp[j + 1];
				envp[j + 1] = temp;
			}
		}
	}
}

void	print_sorted_env(t_env *env)
{
	char	**new_envp;
	int		i;

	i = 0;
	while (env->envp[i])
		i++;
	new_envp = (char **)malloc(sizeof(char *) * (i + 1)); //실패처리
	i = -1;
	while (env->envp[++i])
		new_envp[i] = ft_strdup(env->envp[i]); //실패처리
	new_envp[i] = NULL;
	sort_env(new_envp, i);
	i = 0;
	while (new_envp[i])
		printf("declare -x %s\n", new_envp[i++]); //"" 붙여야함
	double_free(new_envp);
}

void	add_env(t_env *env, char *str)
{
	int		i;
	char	**new_envp;

	i = 0;
	while (env->envp[i])
		i++;
	new_envp = (char **)malloc(sizeof(char *) * (i + 2)); //실패처리
	i = -1;
	while (env->envp[++i]) //name이 숫자, 특수문자로 시작하면 안됨
		new_envp[i] = ft_strdup(env->envp[i]); //실패처리
	new_envp[i++] = ft_strdup(str);
	new_envp[i] = NULL;
	double_free(env->envp);
	env->envp = new_envp;
}

void	change_env(t_env *env, char *str, int env_idx)
{
	free(env->envp[env_idx]);
	env->envp[env_idx] = ft_strdup(str);
}

void	ft_export(t_env *env, t_split *sp)
{
	int	i;
	int	env_idx;

	i = 0;
	if (!sp->str[i + 1])
		print_sorted_env(env);
	while (sp->str[++i])
	{
		env_idx = find_env(env, sp->str[i]); //=으로 찾으면 안됨(다시짜기)
		if (env_idx < 0)
			add_env(env, sp->str[i]);
		else
			change_env(env, sp->str[i], env_idx);
	}
	return ;
}
