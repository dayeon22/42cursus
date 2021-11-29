#include "../include/minishell.h"
/*
int	run_child_process(t_split *sp, t_env *env, int *fd)
{
	int	check;

	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);

	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);

	check = 0;
	check = check_builtin(env, sp);
	if (check == 1)
	{
		printf("here!\n");
		exec_bin_path(sp, env);
	}

	return (check);
}

int	make_child_process(t_split *sp, t_env *env, int *left)
{
	int		fd[2];
	pid_t	pid;
	int		status;

	pipe(fd); //실패처리
	pid = fork();
	if (pid < 0)
	{
		close(fd[0]);
		close(fd[1]);
		close(*left);
		return (-1);
	}
	if (pid == 0)
		run_child_process(sp, env, fd);
	close(fd[0]);

	//close(fd[1]);

	waitpid(pid, &status, 0);
	return (fd[0]);
}
*/

int	run_child_process(t_split *sp, t_env *env, int *fd, int left)
{
	printf("222\n");
	close(fd[0]);
	if (left)
	{
		printf("333\n");
		dup2(left, STDIN_FILENO);
		close(left);
	}
	printf("444\n");
	if (dup2(fd[1], STDOUT_FILENO) < 0) //현 상황: dup2를 하면 아래코드가 실행안됨
		write(2, "error occoured in dup2()\n", 25);
	close(fd[1]);

	int ret = check_builtin(env, sp);
	if (ret == 0)
		exit(0);
	if (ret == 1)
	{
		single_list_cmd(sp, env);
		exit(0);
	}
	return (0);
}

int	make_child_process(t_split *sp, t_env *env, int *left)
{
	int		fd[2];
	pid_t	pid;
	int		status;

	printf("111\n");
	pipe(fd); //실패처리
	pid = fork();
	if (pid < 0)
	{
		close(fd[0]);
		close(fd[1]);
		close(*left);
		return (-1);
	}
	if (pid == 0)
		run_child_process(sp, env, fd, *left);
	if (*left != 0) //here
		close(*left); //here
	close(fd[1]);
	*left = fd[0];
	

	status = 0;
	return (0);
}

void	last_pipe(t_split *sp, t_env *env, int *left)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(*left, 0);
		close(*left);
		int ret = check_builtin(env, sp);
		if (ret == 0)
			exit (0);
		else
		{
			single_list_cmd(sp, env);
			exit(0);
		}
	}
	close(*left);
}

int	run_pipe(t_split *sp, t_env *env)
{
	int		i;
	int		left;
//	int		status;

	i = 1;
	left = 0;
	while (sp->next)
	{
		if (sp->type == CHAR_WORD) //if (sp->type == CHAR_WORD) 가 안돼서 만든 임시코드
			make_child_process(sp, env, &left);
		sp = sp->next;
		i++;
	}
	last_pipe(sp, env, &left);

	(void)env;
	return (0);
}
