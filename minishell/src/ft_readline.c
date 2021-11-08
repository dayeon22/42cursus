#include "../include/minishell.h"

void	get_readline(t_env *env)
{
	char	*rl;
	t_cmd	cmd;

	while (1)
	{
		rl = readline("minishell$ ");
		if (!rl)
		{
			free_env(env);
			ft_putstr_fd("\x1b[1A", 1);
			ft_putstr_fd("\033[11C", 1);
			write(1, "exit\n", 5);
			tcsetattr(STDIN_FILENO, TCSANOW, &env->old_term);
			exit(0);
		}
		if (*rl)
		{
			add_history(rl);
			parse(rl, &cmd);

//			while (cmd.next)
//			{
//				printf("%s\n", command);
//				cmd = cmd.next;
//			}
			//run_command(words, env);
		}
		free(rl);
	}
}
