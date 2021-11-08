#include "../include/minishell.h"

/*
int	run_command(char **words, t_env *env)
{
	int		pid;
	int		stat_loc;

	pid = fork();
	if (pid < 0)
		return (1); //error 출력
	else if (pid == 0)
	{
		//parse()
		//run_builtins(words, env);
		exit(0);
	}
	else
	{
		wait(&stat_loc);
		if (stat_loc < 0)
			return (0); //error 출력
	}
	return (0);
}

int	run_builtins(char **words, t_env *env)
{
	char	**argv;

	argv = (char **)malloc(sizeof(char *) * 2);
	argv[1] = NULL;
	if (!ft_strcmp(words[0], "echo"))
	{
		argv[0] = ft_strdup("echo");
		execve("/bin/echo", argv, env->envp);
	}
//	else if (!ft_strcmp(words[0], "cd"))
//		ft_cd(words);
	else if (!ft_strcmp(words[0], "pwd"))
	{
		argv[0] = ft_strdup("pwd");
		execve("/bin/pwd", argv, env->envp);
	}
//		ft_pwd(words);
//	else if (!ft_strcmp(words[0], "export"))
//		ft_export(words);
//	else if (!ft_strcmp(words[0], "unset"))
//		ft_unset(words);
//	else if (!ft_strcmp(words[0], "env"))
//		ft_env(words);
//	else if (!ft_strcmp(words[0], "exit"))
//		ft_exit(words);
	return (0);
}
*/
