#include "../include/minishell.h"

void	free_two(char **str)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	if (!*str)
		return ;
	while (str[len])
		len++;
	while (++i < len)
		free(str[i]);
	free(str);
}

void	sp_list_clear(t_split *sp)
{
	t_split	*cp;

	while (1)
	{
		cp = sp;
		if (sp->next)
			sp = sp->next;
		free_two(cp->str);
		free(cp);
		if (!sp->next)
			break ;
	}
}

void	free_exit(t_split *sp, t_env *env, int code)
{
	free_two(env->envp);
	sp_list_clear(sp);
	exit(code);
}
