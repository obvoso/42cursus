/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:08:34 by soo               #+#    #+#             */
/*   Updated: 2022/06/30 19:53:07 by soo              ###   ########.fr       */
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

t_env	*find_unset_env(t_env **env, char *del)
{
	t_env	*now;
	t_env	*prev;
	
	prev = *env;
	now = *env;
	if (!ft_strncmp((*env)->key, del, ft_strlen((*env)->key))) // head	삭제
		return (unset_head(env));
	while (prev->next) // 중간노드삭제, 마지막 노드는 원래 삭제안됨
	{
		now = prev->next;
		if (!ft_strncmp(now->key, del, ft_strlen(now->key))) // 넘겨줄 len수정
		{
			prev->next = now->next;
			free(now->value);
			free(now->key);
			free(now);
			return (*env);
		}
		prev = prev->next;
	}
	return (*env);
}

t_env	*unset_env(t_env **head, char **del)
{
	find_unset_env(head, del[1]);
	return (*head);
}