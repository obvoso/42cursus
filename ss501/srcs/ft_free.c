#include "pipex_bonus.h"

void	ft_free3(void ***temp)
{
	int	i;

	i = 0;
	if (temp)
	{
		while (temp[i])
		{
			ft_free2(temp[i]);
			i++;
		}
		free(temp);
	}
}

void	ft_free2(void **temp)
{
	int	i;

	i = 0;
	if (temp)
	{
		while (temp[i])
		{
			free(temp[i]);
			i++;
		}
		free(temp);
	}
}

void	ft_pipe_clear(t_pipex *val, t_input *input)
{
	ft_free2((void **)val->exe_path);
	ft_free2((void **)val->ev);
	ft_free2((void **)val->fd);
	ft_free3((void ***)val->cmd);
	ft_free3((void ***)val->indirec);
	ft_free3((void ***)val->outdirec);
	ft_free2((void **)input->av);
	free(val->line);
//	ft_free3((void ***)val->temp);
}
