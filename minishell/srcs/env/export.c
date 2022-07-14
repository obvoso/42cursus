/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:26:02 by soo               #+#    #+#             */
/*   Updated: 2022/07/14 20:38:14 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "env.h"

void	print_export(t_env *head)
{
	t_env	*now;
	
	now = head;
	while (now->next)
	{
		if (!now->unset_flag)
		{
			if (now->value_flag == 1)
				ft_printf("declare -x %s\n", now->key);
			else if(!ft_strncmp(now->value, "", 1))
				ft_printf("declare -x %s=\"\"\n", now->key);
			else 
				ft_printf("declare -x %s=\"%s\"\n", now->key, now->value);
		}
		now = now->next;
	}
}

static int	find_equal(char *line)
{
	while(*line)
	{
		if (*line == '=')
			return (1);
		++line;
	}
	return (0);
}

t_env	*split_equal(char *line, t_env *new)
{
	char	**split_equal;

	split_equal = ft_split(line, '=');
	new->key = ft_strdup(split_equal[0]);
	if (find_equal(line) && !split_equal[1])
		new->value = ft_strdup("");
	else if (!split_equal[1])
		new->value_flag = 1;
	else
		new->value = ft_strdup(split_equal[1]);
	str_free(split_equal);
	return (new);
}

t_env	*add_env(t_env *head, t_env *new)
{
	t_env	*now;

	if (!ft_strncmp(new->key, "_", 2))
	{
		free(new->key);
		free(new->value);
		free(new);
		return (head);
	}
	now = head;
	while (now->next && ft_strncmp(now->next->key, "_", 2))
	{
		if (!ft_strncmp(now->key, new->key, ft_strlen(now->key) + 1))
		{
			free(now->value);
			now->value = ft_strdup(new->value);
			free(new->key);
			free(new->value);
			free(new);
			return (head);
		}
		now = now->next;
	}
	new->next = now->next;
	now->next = new;
	return (head);
}

int	make_new_env(t_env *head, char *line)
{
	t_env	*new;
	char	**split_blank;
	int		i;
	int		flag;

	split_blank = ft_split(line, ' ');
	i = 0;
	flag = 0;
	while (split_blank[i])
	{
		new = (t_env *)malloc(sizeof(t_env));
		if (!new)
			return (0); //수정
		ft_memset(new, 0, sizeof(t_env));
		if (!format_check(split_blank[i]))
		{
			ft_putstr_fd("export: '", 2);
			ft_putstr_fd(split_blank[i], 2);
			ft_putstr_fd("' : not a valid identifier\n", 2);
			++flag;
			++i;
			free(new);
			continue ;
		}
		add_env(head, split_equal(split_blank[i++], new));
	}
	str_free(split_blank);
	return (flag);
}

int	export_env(t_env *head, char **line)
{
	if (line[1][0] == '\0') // cmd가 인자없이 export만 들어왔을 경우
	{
		str_free(line);
		print_export(head);
		return (0);
	}
	if (make_new_env(head, line[1]) > 0)
	{
		str_free(line);
		return (1);
	}
	str_free(line);
	return (0);
}

int	export(t_env *head, char *line)
{
	char	**str;

	str = line_format(line, "export");
	if (!str)
	{
		ft_putstr_fd("command not found\n", 2);
		return (1);
	}
	return (export_env(head, str));
}
