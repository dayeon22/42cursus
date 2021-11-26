#include "../include/minishell.h"

/* 환경변수 정렬 */
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

/*
 * 환경변수 출력.
 * 환경변수 내부에 등호가 있다면 name="value" 형식으로 출력하지만,
 * 등호가 없다면 name만 출력해야 한다.
 */
void	print_env(char **envp)
{
	int		i;
	char	*equ_pos;

	i = -1;
	while (envp[++i])
	{
		ft_putstr_fd("declare -x ", 1);
		equ_pos = ft_strchr(envp[i], '=');
		if (!equ_pos)
			printf("%s\n", envp[i]);
		else
		{
			write(1, envp[i], equ_pos - envp[i] + 1);
			printf("\"%s\"\n", equ_pos + 1);
		}
	}
}

/* 환경변수를 정렬하고 출력 */
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
	print_env(new_envp);
	double_free(new_envp);
}
