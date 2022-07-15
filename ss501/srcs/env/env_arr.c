/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:45:04 by soo               #+#    #+#             */
/*   Updated: 2022/07/15 21:26:59 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char **init_env_arr(t_env *head)
{
	char	*tmp;
	int		size;
	t_env	*now;
	char	**env_arr;

	size = 0;
	now = head;
	while (head)
	{
		head = head->next;
		++size;
	}
	env_arr = (char **)malloc(sizeof(char *) * size + 1);
	env_arr[size] = NULL;
	now = head;
	while (head)
	{
		tmp = ft_strjoin(head->key, "=");
		env_arr[size++] = ft_strjoin(tmp, head->value);
		free(tmp);
		head = head->next;
	}
	return (env_arr);
}

char **edit_env_arr(t_env *head, char ***env_arr)
{
	char	*tmp;
	int		size;
	t_env	*now;
	char	**new;

	size = 0;
	now = head;
	while (head)
	{
		head = head->next;
		++size;
	}
	new = (char **)malloc(sizeof(char *) * size + 1);
	new[size] = NULL;
	now = head;
	while (head)
	{
		tmp = ft_strjoin(head->key, "=");
		new[size++] = ft_strjoin(tmp, head->value);
		free(tmp);
		head = head->next;
	}
	//str_free(*env_arr);
	*env_arr = new;
	return (*env_arr);
}

