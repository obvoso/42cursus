#include "pipex_bonus.h"

char	*ft_add_space(char *src, char c)
{
	int	k;
	int	i;
	char	*str;
	char	temp;

	i = 0;
	k = 0;
	while (src[i])
	{
		if (src[i] == c)
			k++;
		i++;
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(src) + k + 1));
	i = 0;
	k = 0;
	while (src[i])
	{
		if (src[i] == '\'' || src[i] == '\"')
		{
			str[k++] = src[i];
			temp = src[i++];
			while (src[i] != temp)
				str[k++] = src[i++];
		}
		str[k] = src[i];
		if (src[i] == c && src[i+1] != c)
			str[++k] = ' ';
		k++;
		i++;
	}
	str[k] = '\0';
	free(src);
	return (str);
}

int	ft_direc_count(char **str, char *c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!ft_strncmp(str[i], c, ft_strlen(c)))
			count++;
		i++;
	}
	return (count);
}

void	ft_tolower_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
}

int	ft_built_check(char *str)
{
	if (ft_strncmp(str, "cd", 3) && \
			ft_strncmp(str, "echo", 5) && \
			ft_strncmp(str, "pwd", 4) && \
			ft_strncmp(str, "export", 7) && \
			ft_strncmp(str, "unset", 6) && \
			ft_strncmp(str, "env", 4) && \
			ft_strncmp(str, "exit", 5))
		return (0);
	return (1);
}

int ft_taptosp(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			i = ft_pass_quot(str, i);
		if (str[i] == 9 || str[i] == 11)
			str[i] = 32;
		i++;
	}
	i = 0;
	while (str[i])
		if (str[i++] != 32)
			return (0);
	return (1);
}

int	ft_in_built(t_pipex *val, t_input *input, int i, t_env *env)
{
	(void)input;
//	if (!ft_strncmp(str, "cd", 3))
//		chdir_main( ,&(input->ev), val->cmd[i][1]);
	if (!ft_strncmp(val->cmd[i][0], "echo", 5))
		return ((int)ft_echo(val, i));
	else if (!ft_strncmp(val->cmd[i][0], "pwd", 4))
		ft_pwd();
	else if (!ft_strncmp(val->cmd[i][0], "export", 7))
		return (export(env, val->cmd[i], &(input->ev)));
	else if (!ft_strncmp(val->cmd[i][0], "unset", 6))
		return (unset(&env, val->cmd[i], &(input->ev)));
	else if (!ft_strncmp(val->cmd[i][0], "env", 4))
		print_env(env);
	return (0);
//	else if (!ft_strncmp(str, "exit", 5))
}
