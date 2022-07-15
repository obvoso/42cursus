#include "pipex_bonus.h"

void	ft_print_echo(t_pipex *val, int i, int k, int check)
{
	while (val->cmd[i][k])
	{
		if (val->cmd[i][k][0] != 0)
			write(1, val->cmd[i][k], ft_strlen(val->cmd[i][k]));
		k++;
		if (val->cmd[i][k] != NULL)
			write(1, " ", 1);
	}
	if (check != 1)
		write(1, "\n", 1);
}

void	*ft_echo(t_pipex *val, int i)
{
	int	check;
	int	k;

	k = 1;
	check = 0;
	while (val->cmd[i][k])
	{
		if (!ft_strncmp(val->cmd[i][k], "-n", 3))
		{
			check = 1;
			k++;
			continue ;
		}
		ft_print_echo(val, i, k, check);
		break ;
	}
	return (0);
}

void	*ft_pwd(void)
{
	char	buf[1024];
	getcwd(buf, 1024);
	printf("%s\n", buf);
	return (0);
}
