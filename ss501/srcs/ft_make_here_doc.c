#include "pipex_bonus.h"

static char	*ft_doc_prompt(void)
{
	char	*line;

	line = readline("> ");
	if (line == NULL)
		return (line);
	else
		return (line);
}

static void	ft_make_here_doc2(char *indirec, int index, int count)
{
	int		fd;
	char	*line;
	char	*temp;
	char	*name;

	temp = ft_strjoin_free(ft_itoa(index), ft_itoa(count));
	name = ft_strjoin("...", temp);
	free(temp);
	fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	while (1)
	{
		line = ft_doc_prompt();
		if (line == NULL)
			break ;
		temp = line;
		line = ft_strjoin(temp, "\n");
		if (!ft_strncmp(temp, indirec, ft_strlen(temp) + 1))
			break ;
		free(temp);
		write(fd, line, ft_strlen(line));
		free(line);
	}
	free(line);
	free(temp);
	close(fd);
}

void	ft_make_here_doc(char ***indirec)
{
	int	i;
	int	count;
	int	k;

	k = 0;
	while (indirec[k])
	{
		count = 0;
		i = 0;
		while (indirec[k][i])
		{
			if (!ft_strncmp(indirec[k][i], "<", 2))
				i++;
			else
			{
				i++;
				ft_make_here_doc2(indirec[k][i], k, count);
				count++;
			}
			i++;
		}
		k++;
	}
}
