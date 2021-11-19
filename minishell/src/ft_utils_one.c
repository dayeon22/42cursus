#include "../include/minishell.h"

int sp_str_len(t_split *sp)
{
    int len;

    len = 0;
    while (sp->str[len])
        len++;
    return (len);
}

int ft_isspace(int sp)
{
	if ((sp >= 9 && sp <= 13) || sp == 32)
        return (1);
    return (0);
}

int ft_isquotes(char sp)
{
	if (sp == '\'' || sp == '\"' || sp == '$')
        return (1);
    return (0);
}


char    *select_path(t_env *env, char *str)
{
    int i;

    i = -1;
    while (env->envp[++i])
        if (!ft_strncmp(env->envp[i], str, ft_strlen(str)))
            return (env->envp[i] + ft_strlen(str));
    return (0);
}
