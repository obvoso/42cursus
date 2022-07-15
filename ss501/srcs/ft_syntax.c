#include "pipex_bonus.h"
static int	ft_print_syntax(char *str, int exit_code)
{
	printf("ss_shell: syntax error: near unexpected token '%s'\n", str);
	return (exit_code);
}

int	ft_pass_quot(char *line, int i)
{
	if (line[i] == '\'')
		while (line[i])
		{
			i++;
			if (line[i] == '\'')
				return (i);
		}
	else
		while (line[i])
		{
			i++;
			if (line[i] == '\"')
				return (i);
		}
	return (-1);
}

static int	ft_quot_check(char *line)
{
	int		i;
	char	c;
	int		single_quot;
	int		double_quot;

	single_quot = 0;
	double_quot = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\'' || line[i] == '\"')
		{
			c = line[i++];
			while (line[i] != c)
				if (line[i++] == '\0')
					return (ft_print_syntax("newline", 258));
			if (c == '\'')
				single_quot++;
			else
				double_quot++;
		}
		i++;
	}
	if (single_quot > 125 || double_quot > 125)
		return (ft_print_syntax("newline", 258));
	else
		return (0);
}

static int	ft_bracket_check(char *line)
{
	int	i;
	int	check;

	check = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\'' || line[i] == '\"')
			i = ft_pass_quot(line, i);
		if (line[i] == '|' || line[i] == ' ')
		{
			if (line[i++] == '|')
				check = 1;
			continue ;
		}
		check = 0;
		if (line[i] == '(')
			return (ft_print_syntax("(", 258));
		else if (line[i] == ')')
			return (ft_print_syntax(")", 258));
		i++;
	}
	if (check)
		return (ft_print_syntax("newline", 258));
	return (0);
}

static int ft_blank_check(char *line, char *c)
{
	char	**str;
	int		i;

	i = 0;
	str = ft_split(line, ' ');
	while (str[i])
	{
		if (str[i][0] == c[0] && str[i + 1] == NULL)
			return (ft_print_syntax("newline", 258));
		if (str[i][0] == c[0] && str[i + 1][0] == c[0])
			return (ft_print_syntax(c, 258));
		i++;
	}
	ft_free2((void *)str);
	return (0);
}

int	ft_indirec_syntax_check(char *line)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\'' || line[i] == '\"')
			i = ft_pass_quot(line, i);
		if (line[i] == '<')
		{
			count++;
			if (line[i + 1] == '>')
				return (ft_print_syntax(">", 258));
		}
		else
			count = 0;
		if (count == 3)
			return (ft_print_syntax("<", 258));
		if (line[i] != '<' && line[i] != ' ' && line[i + 1] == '<')
			return (ft_print_syntax("<", 258));
		i++;
	}
	return (ft_blank_check(line, "<"));
}

int	ft_outdirec_syntax_check(char *line)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\'' || line[i] == '\"')
			i = ft_pass_quot(line, i);
		if (line[i] == '>')
		{
			count++;
			if (line[i + 1] == '<')
				return (ft_print_syntax("<", 258));
		}
		else
			count = 0;
		if (count == 3)
			return (ft_print_syntax(">", 258));
		if (line[i] != '>' && line[i] != ' ' && line[i + 1] == '>')
			return (ft_print_syntax(">", 258));
		i++;
	}
	return (ft_blank_check(line, ">"));
}

int	ft_syntax_check(char *line)
{
	int	i;

	i = ft_quot_check(line);
	if (i)
		return (i);
	i = ft_bracket_check(line);
	if (i)
		return (i);
	i = ft_indirec_syntax_check(line);
	if (i)
		return (i);
	i = ft_outdirec_syntax_check(line);
	if (i)
		return (i);
	return (0);
}
