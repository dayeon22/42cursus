#include "../include/minishell.h"

void	double_free(char **words)
{
	int	i;

	i = 0;
	while (words[i])
		free(words[i++]);
	free(words);
}
