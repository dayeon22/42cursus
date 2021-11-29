#include "../include/minishell.h"

/* 
 * str과 name이 같은 환경변수가 t_env의 몇번째 인덱스에 있는지 찾는 함수.
 * 환경변수가 존재한다면 인덱스를, 존재하지 않는다면 -1을 리턴한다.
 */
int	find_env(t_env *env, char *str)
{
	int		i;
	char	*env_equal_pos;
	char	*str_equal_pos;
	int		compare_len;

	i = -1;
//	if (env_name_check(str))
//		return (-1); //print_err("%s : not a valid identifier", str);
	while (env->envp[++i])
	{
		env_equal_pos = ft_strchr(env->envp[i], '=');
		if (!env_equal_pos)
			env_equal_pos = ft_strchr(env->envp[i], '\0');
		str_equal_pos = ft_strchr(env->envp[i], '=');
		if (!str_equal_pos)
			str_equal_pos = ft_strchr(env->envp[i], '\0');
		compare_len = str_equal_pos - str;
		if (env_equal_pos - env->envp[i] > compare_len)
			compare_len = env_equal_pos - env->envp[i];
		if (!ft_strncmp(env->envp[i], str, compare_len))
			return (i);
	}
	return (-1);
}

void	remove_env(t_env *env, int i)
{
	if (i < 0)
		return ;
	free(env->envp[i]);
	while (env->envp[i])
	{
		env->envp[i] = env->envp[i + 1];
		i++;
	}
}

void	ft_unset(t_env *env, t_split *sp)
{
	int	i;

	i = 0;
	while (sp->str[++i])
		remove_env(env, find_env(env, sp->str[i]));
}
