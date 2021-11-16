#include "../include/minishell.h"

static void double_cd_path(t_env *env, t_split *sp)
{
    char    buf[PWD_SIZE];

    getcwd(buf, PWD_SIZE);
    if (chdir(sp->str[1]) == -1)
        printf("minishell: cd: %s: No such file or directory\n", sp->str[1]);
    else
    {
        env_oldpwd_input(env, buf, 0);
        ft_bzero(buf, PWD_SIZE);
        getcwd(buf, PWD_SIZE);
        env_pwd_input(env, buf);
    }
}

static void double_cd_minus(t_env *env, t_split *sp)
{
    char    *path;
    char    buf[PWD_SIZE];

    getcwd(buf, PWD_SIZE);
    if (!select_path(env, "OLDPWD="))
        env_oldpwd_input(env, 0, sp->str[1][0]);
    else
    {
        path = ft_strdup(select_path(env, "OLDPWD="));
        if (chdir(path) == -1)
            printf("minishell: cd: %s: No such file or directory\n", path);
        else
        {
            env_pwd_input(env, path);
            env_oldpwd_input(env, buf, '-');
            printf("%s\n", path);
        }
        free(path);
    }
}

static int single_cd(t_env *env, t_split *sp)
{
    int     size;
    char    *path;
    char    buf[PWD_SIZE];

    size = sp_list_size(sp);
    if (size == 1)
    {
        path = ft_strdup(select_path(env, "HOME="));
        getcwd(buf, PWD_SIZE);
        if (chdir(path) == -1)
            printf("minishell: cd: %s: No such file or directory\n", path);
        else
        {
            env_pwd_input(env, path);
            env_oldpwd_input(env, buf, 0);
        }
        free(path);
    }
    else if (size > 2)
        return (0);
    return (0);
}

static int double_cd(t_env *env, t_split *sp)
{
    int     size;

    size = sp_list_size(sp);
    if (size == 1)
    {
        if (ft_strlen(sp->str[1]) > 1 && sp->str[1][0] == '-')
        {
            printf("minishell: cd: %s: invalid option\n", sp->str[1]);
            printf("cd: usage: cd [dir]\n");
        }
        else if (ft_strlen(sp->str[1]) == 1 && sp->str[1][0] == '-')
            double_cd_minus(env, sp);
        else if (ft_strlen(sp->str[1]) == 1 && sp->str[1][0] == '~')
            single_cd(env, sp);
        else
            double_cd_path(env, sp);
    }
    else if (size > 2)
        return (0);
    return (0);
}

void	ft_cd(t_env *env, t_split *sp)
{
    int sp_len;

    sp_len = -1;
    while (sp->str[++sp_len])
        ;
    if (sp_len == 1)
        single_cd(env, sp);
    else if (sp_len == 2)
        double_cd(env, sp);
    else
        printf("minishell: cd: too many arguments\n");
    free_all(env, sp, 0);
}
