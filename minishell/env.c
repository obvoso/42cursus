/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songmin <autumninmoon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:02:34 by soo               #+#    #+#             */
/*   Updated: 2022/06/30 00:25:44 by songmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "env.h"

//export
static int blank_check(t_env new)
{
	char *str;

	str = new.key;
	while (*str)
	{
		if ((*str >= 9 && *str <= 13) || *str == 32)
			return (1);
		*str++;
	}
	str = new.value;
	while (*str)
	{
		if ((*str >= 9 && *str <= 13) || *str == 32)
			return (1);
		*str++;
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
		*str++;
	}
	return (0);
}

static int key_format_check(t_env new)
{
	if (black_check(new))
		//error
		if (num_check(new))
	//error
}

t_env *add_env(t_env *head, t_env *new)
{
	t_env *now;

	now = head;
	while (now->next)
	{
		if (now->key == new->key)
		{
			free(now->value);
			now->value = ft_strdup(new->value);
			free(new->key);
			free(new->value);
			free(new);
		}
		if (!now->next->next)
			break;
		now = now->next;
	}
	new->next = now->next;
	now->next = new;
	return (head);
}

t_env *export_env(t_env *head, char *new_env)
{
	t_env *new;
	char **split_equal;

	new = (t_env *)malloc(sizeof(t_env));
	if (!ft_strchr(new_env, (int)'='))
		//error
		split_equal = ft_split(new_env, '=');
	new->key = ft_strdup(split_equal[0]);
	new->value = ft_strdup(split_equal[1]);
	new->next = NULL;
	key_format_check(*new);
	is_new_env(head, new);
}

//env
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
	t_env head;

	ft_memset(&head, 0, sizeof(t_env));
	split_env(&head, envp);

	t_env *tmp = &head;
	while (tmp)
	{
		printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}