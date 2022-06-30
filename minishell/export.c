/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:26:02 by soo               #+#    #+#             */
/*   Updated: 2022/06/30 19:32:10 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "env.h"

static int	blank_check(t_env new)
{
	char	*str;

	str = new.key;
	while (*str)
	{
		if ((*str >= 9 && *str <= 13) || *str == 32)
			return (1);
		++str;
	}
	str = new.value;
	while (*str)
	{
		if ((*str >= 9 && *str <= 13) || *str == 32)
			return (1);
		++str;
	}
	return (0);
}

static int num_check(t_env new)
{
	char *str;
	str = new.key;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			return (1);
		++str;
	}
	return (0);
}

void key_format_check(t_env new)
{
	if (blank_check(new) || num_check(new))
	{
		printf("ERROR\n");
		exit(1);
	}
}

t_env	*add_env(t_env *head, t_env *new)
{
	t_env	*now;

	now = head;
	while (now->next)
	{
		if (!ft_strncmp(now->key, new->key, ft_strlen(now->key))) // 넘겨줄 len수정
		{
			free(now->value);
			now->value = ft_strdup(new->value);
			free(new->key);
			free(new->value);
			free(new);
			return (head);
		}
		if (!now->next->next)
			break;
		now = now->next;
	}
	new->next = now->next;
	now->next = new;
	return (head);
}

t_env	*export_env(t_env *head, char **new_env)
{
	t_env	*new;
	char	**split_equal;

	new = (t_env *)malloc(sizeof(t_env));
	if (!ft_strchr(new_env[1], (int)'='))
		printf("ERROR\n");
	split_equal = ft_split(new_env[1], '=');
	new->key = ft_strdup(split_equal[0]);
	new->value = ft_strdup(split_equal[1]);
	new->next = NULL;
	key_format_check(*new);
	add_env(head, new);
	return (head);
}
