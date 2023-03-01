/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dless_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:09:15 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/17 14:09:17 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*dless_file_name(t_env *env)
{
	char	*cp_s;
	char	*n;

	n = ft_itoa(env->d_len);
	cp_s = ft_strjoin(".temp_dless_", n);
	free_one_point(n);
	return (cp_s);
}

static int	read_filename(int fd, char **filename)
{
	close(fd);
	fd = open(*filename, O_RDONLY, 0444);
	if (fd < 0 && !free_one_point(*filename))
		return (-42);
	free_one_point(*filename);
	return (fd);
}

static int	dless_d_exit(t_env *env)
{
	char	*s1;
	char	*s2;

	++env->d_count;
	s1 = ft_itoa(env->d_count * 2);
	s2 = ft_strjoin_other("\033[", s1, "C");
	free_one_point(s1);
	s1 = 0;
	ft_putstr_fd("\x1b[1A", 1);
	ft_putstr_fd(s2, 1);
	free_one_point(s2);
	s2 = 0;
	env->exit_n = 0;
	return (1);
}

static int	dless_readline(t_env *env, char *rl, int fd, char *eof)
{
	redir_signal_handlers();
	while (1)
	{
		rl = readline("> ");
		if (!rl && dless_d_exit(env) && !close(fd) && !free_one_point(rl))
			return (env->exit_n);
		else if (rl)
			env->d_count = 0;
		if (rl && ft_strcmp(eof, rl) == 0)
		{
			free_one_point(rl);
			close(fd);
			return (0);
		}
		write(fd, rl, ft_strlen(rl));
		write(fd, "\n", 1);
		free_one_point(rl);
	}
	env->exit_n = 0;
	return (env->exit_n);
}

int	get_here_document(t_env *env, char *eof, char *rl)
{
	int		fd;
	int		status;
	pid_t	pid;
	char	*filename;

	filename = dless_file_name(env);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (++env->d_len > 0 && fd < 0)
		return (-42);
	signal_ign();
	pid = fork();
	if (pid == 0)
	{
		dless_readline(env, rl, fd, eof);
		exit(0);
	}
	waitpid(pid, &status, 0);
	fd = read_filename(fd, &filename);
	env->exit_n = command_exit(status);
	if (env->exit_n > 0 && !close(fd) && !file_delet(env))
		get_readline(env, 0);
	return (fd);
}
