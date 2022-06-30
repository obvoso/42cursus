/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:06:58 by soo               #+#    #+#             */
/*   Updated: 2022/06/30 19:47:58 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

#include "./libft/libft.h"

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;


void key_format_check(t_env new);
t_env	*add_env(t_env *head, t_env *new);
t_env	*export_env(t_env *head, char **new_env);

t_env	*unset_head(t_env **head);
t_env	*find_unset_env(t_env **env, char *del);
t_env	*unset_env(t_env **head, char **del);
#endif
