#include "../include/minishell.h"

static int	cd_pathway(t_env *env, t_split *sp)
{
	char	buf[PWD_SIZE];

	if (!getcwd(buf, PWD_SIZE))
		return (error_printf(env, "cd: No such file or directory", 1));
	if (chdir(sp->str[1]) == -1)
		return (error_printf(env, "cd: No such file or directory", 1));
	env_oldpwd_input(env, buf);
	env_pwd_input(env, sp->str[1]);
	return (1);
}

static int	cd_solo(t_env *env)
{
	char	buf[PWD_SIZE];
	char	*cp;

	if (!getcwd(buf, PWD_SIZE))
		return (error_printf(env, "cd: No such file or directory", 1));
	cp = ft_strdup(select_path(env, "HOME="));
	if (chdir(cp) == -1)
		return (error_printf(env, "cd: No such file or directory", 1));
	env_oldpwd_input(env, buf);
	env_pwd_input(env, cp);
	free_one(cp);
	return (1);
}

static int	cd_mark(t_env *env, t_split *sp)
{
	int	len;

	len = ft_strlen(sp->str[1]);
	if (sp->str[1][0] == '-')
		if (!cd_mark_minus(env, sp, len))
			return (0);
	if (sp->str[1][0] == '~')
		if (!cd_mark_wave(env, sp, len))
			return (0);
	return (1);
}

static int	cd_sense(t_env *env, t_split *sp, int sp_len)
{
	char	*cp;
	int		i;

	if (sp_len > 1 && sp->str[1])
	{
		i = -1;
		while (sp->str[++i])
		{
			cp = sp->str[i];
			dollar_all_len(sp, sp->str[i]);
			sp->str[i] = dollar_change(sp, sp->str[i], 0);
			free_one(cp);
		}
		if (!ft_strncmp(sp->str[1], "-", 1) || !ft_strncmp(sp->str[1], "~", 1))
			return (cd_mark(env, sp));
		else
			return (cd_pathway(env, sp));
	}
	else
		if (!cd_solo(env))
			return (0);
	return (1);
}

void	ft_cd(t_env *env, t_split *sp)
{
	int	sp_len;

	sp_len = sp_str_len(sp);
	cd_sense(env, sp, sp_len);
	free_all(env, sp, 0);
}
