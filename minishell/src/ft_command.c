#include "../include/minishell.h"

int	run_command(char *line)
{
	char	**words;
	int		pid;

	// builtin 제작을 위한 임시 코드
	words = ft_split(line, ' ');
	
	int i = 0;
	while (words[i])
		printf("%s", words[i++]);

	pid = fork();
	if (pid == -1)
		return (1); //error 출력
	else if (pid == 0)
	{
		printf("This is child process\n");
		run_builtins(words);
	}
	else
	{
		sleep(3);
		// 부모 프로세스
		return (0);
	}
	return (0);
}

int	run_builtins(char **words)
{
	if (!ft_strcmp(words[0], "echo"))
		printf("echo()\n");
		//ft_echo(words);
//	else if (!ft_strcmp(words[0], "cd"))
//		ft_cd(words);
//	else if (!ft_strcmp(words[0], "pwd"))
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
