#include "../include/minishell.h"

/*
 * 환경변수 형식 "name=value" 에서 name을 체크하는 함수.
 * name의 첫글자는 '_'나 알파벳으로만 시작해야 하며
 * 나머지 글자에는 '-'나 알파벳이나 숫자만 들어갈 수 있다.
 */
int	env_name_check(char *str)
{
	if (*str != '_' && !ft_isalpha(*str))
		return (1);
	str++;
	while (*str && *str != '=')
	{
		if (*str != '_' && !ft_isalnum(*str))
			return (1);
		str++;
	}
	return (0);
}

void	add_env(t_env *env, char *str)
{
	int		i;
	char	**new_envp;

	i = 0;
	if (env_name_check(str))
	{
		ft_putstr_fd("not valid identifier\n", 2); //문구 나중에 수정하기
		return ;
	}
	while (env->envp[i])
		i++;
	new_envp = (char **)malloc(sizeof(char *) * (i + 2)); //실패처리
	i = -1;
	while (env->envp[++i])
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

/* 
 * export만 입력했다면 환경변수를 출력하고,
 * export [존재하지 않는 환경변수] 형식으로 입력했다면 환경변수를 추가하고,
 * export [이미 존재하는 환경변수] 형식으로 입력했다면 환경변수를 수정한다.
 */
void	ft_export(t_env *env, t_split *sp)
{
	int	i;
	int	env_idx;

	i = 0;
	if (!sp->str[i + 1])
		print_sorted_env(env);
	while (sp->str[++i])
	{
		env_idx = find_env(env, sp->str[i]);
		if (env_idx < 0)
			add_env(env, sp->str[i]);
		else if (ft_strchr(sp->str[i], '='))
			change_env(env, sp->str[i], env_idx);
	}
	return ;
}