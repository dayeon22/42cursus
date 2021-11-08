#include "../include/minishell.h"

void	parse(char *line, t_cmd *cmd)
{
	cmd = NULL;
	replace_symbol(line);
	//파이프, 세미콜론 단위로 끊어 링크드리스트에 넣기
}

void	handle_single_quotes(char *line, char *new_line, int *i, int *j)
{
	while (line[*i] != '\'')
	{
		if (line[*i] == '\\')
		{
			*i = *i + 1;
			new_line[*j++] = line[*i++];
		}
		else
			new_line[*j++] = line[*i++];
	}
}

void	handle_double_quotes(char *line, char *new_line, int *i, int *j)
{
	while (line[*i] != '\"')
	{
		if (line[*i] == '\\')
		{
			*i = *i + 1;
			new_line[*j++] = line[*i++];
		}
		else if (line[*i] == '$')
		{
			*i = *i + 1;
			new_line[*j++] = DOLLAR;
		}
		else
			new_line[*j++] = line[*i++];
	}
}

void	handle_special_characters(char *line, char *new_line, int *i, int *j)
{
	if (line[*i] == '|')
		new_line[*j++] = PIPE;
	else if (line[*i] == '$')
		new_line[*j++] = DOLLAR;
	else if (line[*i] == '>')
		new_line[*j++] = RIGHT;
	else if (line[*i] == '<')
		new_line[*j++] = LEFT;
	else if (line[*i] == ' ')
		new_line[*j++] = SPC;
	*i = *i + 1;
}

//char	*replace_symbol(char *line)
void	replace_symbol(char *line)
{
	//int	new_size;
	char	new_line[250]; //사이즈 재면서 유효하지 않은 문자 들어가있는지 검사?
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == '\\')
		{
			i++;
			new_line[j++] = line[i++];
		}
		else if (line[i] == '\'')
			handle_single_quotes(line, new_line, &i, &j);
		else if (line[i] == '\"')
			handle_double_quotes(line, new_line, &i, &j);
		else if (line[i] == '|' || line[i] == '$' || line[i] == '>' \
				|| line[i] == '<' || line[i] == ' ')
			handle_special_characters(line, new_line, &i, &j);
		else
			new_line[j++] = line[i++];
	}


	new_line[j] = '\0';
	j = 0;
	while (new_line[j] != 0)
	{
		//if (new_line[j] < 0)
			printf("%d ", new_line[j]);
		//else
		//	printf("%c", new_line[j]);
		j++;
	}
	printf("\n");
}
