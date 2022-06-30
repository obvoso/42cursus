/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:02:34 by soo               #+#    #+#             */
/*   Updated: 2022/06/30 19:47:35 by soo              ###   ########.fr       */
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

void str_free(char **str)
{
	int i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
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
			get_last(head)->next = new;
		new->next = NULL;
		str_free(split_equal);
	}
	return (head);
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	t_env *head;
	char	**str;

	head = (t_env *)malloc(sizeof(t_env));
	str = (char **)malloc(sizeof(char *) * 2);
	str[0] = "export";
	str[1] = "SECURITYSESSIONID=186a6AAAAAA";

	ft_memset(head, 0, sizeof(t_env));
	split_env(head, envp);
	t_env *tmp = head;
	while (tmp)
	{
		printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
	printf("\n------------\n\n");
	export_env(head, str);
	tmp = head;
	while (tmp)
	{
		printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
		printf("\n------------\n\n");
	str[1] = "SECURITYSESSIONID";
	unset_env(&head, str);
	tmp = head;
	while (tmp)
	{
		printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
	//return (&head);
}