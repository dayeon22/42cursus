#include "../include/minishell.h"

void env_pwd_input(t_env *env, char *path)
{
    int     i;
    int     index;
    char    *cp;

    i = -1;
    index = -1;
    while (env->envp[++i])
        if (!ft_strncmp(env->envp[i], "PWD=", ft_strlen("PWD=")))
            index = i;
    if (index == -1)
        printf("export code pwd\n");
    else
    {
        if (env->envp[index])
        {
            cp = env->envp[index]; 
            env->envp[index] = ft_strjoin("PWD=", path);        
            free(cp);
            cp = 0;
        }
    }
}


void env_oldpwd_input(t_env *env, char *path, char c)
{
    int     i;
    int     index;
    char    *cp;

    i = -1;
    index = -1;
    while (env->envp[++i])
        if (!ft_strncmp(env->envp[i], "OLDPWD=", ft_strlen("OLDPWD=")))
            index = i;
    if (index == -1)
    {
        if (c == '-')
            printf("minishell: cd: OLDPWD not set\n");
        else
            printf("export code old\n");
    }
    else
    {
        if (env->envp[index])
        {
            cp = env->envp[index]; 
            env->envp[index] = ft_strjoin("OLDPWD=", path);        
            free(cp);
            cp = 0;
        }
    }
}