/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:02:34 by soo               #+#    #+#             */
/*   Updated: 2022/07/06 16:48:07 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "env.h"

static t_env *get_last(t_env *head)
{
	while (head->next)
		head = head->next;
	return (head);
}

t_env *split_env(t_env *head, char **envp)
{
	t_env *new;
	char **split_equal;
	int i;

	i = 0;
	while (envp[i])
	{
		new = (t_env *)malloc(sizeof(t_env));
		ft_memset(new, 0, sizeof(t_env));
		split_equal = ft_split(envp[i++], '=');
		new->key = ft_strdup(split_equal[0]);
		new->value = ft_strdup(split_equal[1]);
		if (!head->key)
		{
			head->key = new->key;
			head->value = new->value;
			head->next = NULL;
			free(new);
		}
		else
		{
			get_last(head)->next = new;
			new->next = NULL;
		}
		str_free(split_equal);
	}
	return (head);
}

t_env	*init_env(t_env *head, char **envp)
{
	// split_env(head, envp);
	return (split_env(head, envp));
}
