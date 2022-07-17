/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:45:04 by soo               #+#    #+#             */
/*   Updated: 2022/07/17 15:29:27 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <stdio.h>

char **edit_env_arr(t_env *head, char ***env_arr)
{
	char	*tmp;
	int		size;
	t_env	*now;
	char	**new;

	size = 0;
	now = head;
	while (now)
	{
		now = now->next;
		++size;
	}
	new = (char **)malloc(sizeof(char *) * (size + 1));
	new[size] = NULL;
	size = 0;
	now = head;
	while (now)
	{
		tmp = ft_strjoin(now->key, "=");
		new[size++] = ft_strjoin(tmp, now->value);
		free(tmp);
		now = now->next;
	}
	//str_free(*env_arr);
	*env_arr = new;
	return (*env_arr);
}

