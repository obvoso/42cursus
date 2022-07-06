/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:08:34 by soo               #+#    #+#             */
/*   Updated: 2022/07/06 21:52:14 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "env.h"

t_env	*unset_head(t_env **head)
{
	t_env	*del;

	del = (*head);
	*head = (*head)->next;
	free(del->key);
	free(del->value);
	free(del);
	return (*head);
}

int	split_del_key(t_env **env, char *del)
{
	int		i;
	int		flag;
	char	**split_key;

	split_key = ft_split(del, ' ');
	i = 0;
	flag = 0;
	while (split_key[i])
	{
		if (!format_check(split_key[i]))
		{
			ft_putstr_fd("export: '", 2);
			ft_putstr_fd(split_key[i], 2);
			ft_putstr_fd("' : not a valid identifier\n", 2);
			++flag;
			++i;
			continue ;
		}
		find_unset_env(env, split_key[i++]);
		printf("\n\n\n\n???\n\n\n\n");
	}
	str_free(split_key);
	return (flag);
}

t_env	*find_unset_env(t_env **env, char *del)
{
	t_env	*now;
	t_env	*prev;
	
	prev = *env;
	now = *env;
	if (!ft_strncmp((*env)->key, del, ft_strlen((*env)->key)) && \
		(ft_strlen(now->key) == ft_strlen(del))) // head	삭제
		return (unset_head(env));
	while (prev->next) // 중간노드삭제, 마지막 노드는 원래 삭제안됨
	{
		now = prev->next;
		if (ft_strlen(now->key) == ft_strlen(del) && \
			!ft_strncmp(now->key, del, ft_strlen(now->key)))
		{
			prev->next = now->next;
			free(now->key);
			if (now->value)
				free(now->value);
			free(now);
			return (*env);
		}
		prev = prev->next;
	}
	return (*env);
}

int	unset_env(t_env **head, char **del)
{
	if (split_del_key(head, del[1]) > 0)
	{
		str_free(del);
		return (1);
	}
	str_free(del);
	return (0);
}

int	unset(t_env **head, char *line)
{
	char	**str;

	str = line_format(line, "unset");
	return (unset_env(head, str));
}