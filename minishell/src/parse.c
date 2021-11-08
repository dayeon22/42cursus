#include "../include/minishell.h"

void	parse(char *line, t_cmd *cmd)
{
	cmd = NULL;
	replace_symbol(line); //replace_symbol에서 line을 조작했기 때문에 여기서 사용 불가
	//파이프, 세미콜론 단위로 끊어 링크드리스트에 넣기
}

void	handle_single_quotes(char **line, char **new_line)
{
	*line = *line + 1;
	while (**line != '\'')
	{
		if (**line == '\\')
			*line = *line + 1;
		**new_line = **line;
		*new_line = *new_line + 1;
		*line = *line + 1;
	}
	*line = *line + 1;
}

void	handle_double_quotes(char **line, char **new_line)
{
	*line = *line + 1;
	while (**line != '\"')
	{
		if (**line == '\\')
		{
			*line = *line + 1;
			**new_line = **line;
			*new_line = *new_line + 1;
			*line = *line + 1;
		}
		else if (**line == '$')
		{
			*line = *line + 1;
			**new_line = DOLLAR;
			*new_line = *new_line + 1;
		}
		else
		{
			**new_line = **line;
			*new_line = *new_line + 1;
			*line = *line + 1;
		}
	}
	*line = *line + 1;
}

void	handle_special_characters(char **line, char **new_line)
{
	if (**line == '|')
		**new_line = PIPE;
	else if (**line == '$')
		**new_line = DOLLAR;
	else if (**line == '>')
		**new_line = RIGHT;
	else if (**line == '<')
		**new_line = LEFT;
	else if (**line == ' ')
		**new_line = SPC;
	*line = *line + 1;
	*new_line = *new_line + 1;
}

//char	*replace_symbol(char *line)
void	replace_symbol(char *line)
{
	//int	new_size;
	char	*new_line; //사이즈 재면서 유효하지 않은 문자 들어가있는지 검사?
	char	*temp;
	char	*new_temp;

	new_line = (char *)malloc(sizeof(char) * (250 + 1));
	new_temp = new_line;
	temp = line;
	while (*line)
	{
		if (*line == '\\')
		{
			new_line++;
			*(new_line++) = *(line++);
		}
		else if (*line == '\'')
			handle_single_quotes(&line, &new_line);
		else if (*line == '\"')
			handle_double_quotes(&line, &new_line);
		else if (*line == '|' || *line == '$' || *line == '>' \
				|| *line == '<' || *line == ' ')
			handle_special_characters(&line, &new_line);
		else
			*new_line++ = *line++;
	}
	*new_line = '\0';

	int i = 0;
	while (new_temp[i] != 0)
	{
		if (new_temp[i] == PIPE)
			printf("[PIPE]");
		else if (new_temp[i] == DOLLAR)
			printf("[DOLLAR]");
		else if (new_temp[i] == RIGHT)
			printf("[RIGHT]");
		else if (new_temp[i] == LEFT)
			printf("[LEFT]");
		else if (new_temp[i] == SPC)
			printf("[SPC]");
		else
			printf("%c", new_temp[i]);
		i++;
	}
	printf("\n");
}
