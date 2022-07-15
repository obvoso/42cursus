#include "pipex_bonus.h"

/*static int	ft_get_size(char c, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
	
		if (line[i] == c)
			return (i);
		i++;
	}
	return (0);
}*/

static char	*ft_re_trans_quot2(char *line)
{
	char	*temp;
	char	c;
	int		i;
	int		k;

	k = 0;
	i = 0;
	temp = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
	while (line[i])
	{
		if (line[i] == '\'' || line[i] == '\"')
		{
			c = line[i++];
			while (line[i] != c)
				temp[k++] = line[i++];
			i++;
			while (line[i] != '\'' && line[i] != '\"' && line[i] != '\0' && line[i] != ' ')
				temp[k++] = line[i++];
			if (line[i] == '\'' || line [i] == '\"')
				continue ;
			else if (line[i] == ' ' || line[i] == '\0')
				break ;
		}
		i++;
	}
	temp[k] = '\0';
	return (temp);
}

char	*ft_re_trans_quot(char *line, int index)
{
	int		count;
	int		i;
	int		k;

	k = 0;
	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == '\'' || line[i] == '\"')
		{
			k = i + 1;
			while (line[k] != line[i])
				k++;
			count--;
			if (index == count)
				return (ft_re_trans_quot2(&line[i]));
			i = k;
		}
		i++;
	}
	return (0);
}
char	*ft_trans_quot(char *line)
{
	int		i;
	int		count;
	char	*temp;
	char	c;
	int		k;

	temp = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
	count = -1;
	k = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\'' || line[i] == '\"')
		{
			temp[k] = '(';
			c = line[i++];
			while (line[i] != c)
				i++;
			temp[++k] = count--;	
		}
		else
			temp[k] = line[i];
		k++;
		i++;
	}
	temp[k] = line[i];
	return (temp);
}
