/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:06:58 by soo               #+#    #+#             */
/*   Updated: 2022/07/17 16:28:05 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "../srcs/libft/libft.h"

typedef struct s_env
{
	int				value_flag;
	int				unset_flag;
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

//env
t_env	*init_env(t_env *head, char **envp);
t_env	*split_env(t_env *head, char **envp);

//call_env
void	print_env(t_env	*head);

//export
int	export(t_env *head, char **line, char ***env_arr);
int	export_env(t_env *head, char **line, char ***env_arr);
t_env	*dup_env(t_env **now, t_env **new);
t_env	*add_env(t_env *head, t_env *new);
int	make_new_env(t_env *head, char **split_blank);
t_env	*split_equal(char *line, t_env *new);
void	print_export(t_env *head);
char **add_env_arr(t_env *head, char ***env_arr);

//utils
char	**line_format(char *line, char *cmd);
int	format_check(char *line);
void str_free(char **str);

//unset
t_env	*unset_head(t_env **head);
t_env	*find_unset_env(t_env **env, char *del);
int		unset_env(t_env **head, char **del, char ***env_arr);
int		split_del_key(t_env **env, char **split_key);
int		unset(t_env **head, char **line, char ***env_arr);
char	**del_env_arr(t_env *head, char ***env_arr);

//env_arr
char **edit_env_arr(t_env *head, char ***env_arr);

#endif
