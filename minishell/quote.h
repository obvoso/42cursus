/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:14:19 by soo               #+#    #+#             */
/*   Updated: 2022/07/07 21:12:28 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUOTE_H
# define QUOTE_H

#include "./libft/libft.h"
#include "env.h"

//quote
char	*del_quote(char *line, char *str, char c);
char	*s_line_handler(t_env *env, char **line, char *origin, int exit_code);
char	*d_line_handler(t_env *env, char **line, char *origin, int exit_code);
char	*quote_line(char *origin, int exit_code, t_env *env);

//quote_utils
char *find_env(t_env *env, char *str, int exit_code);
int	cnt_quote(char *line, char c);
int	find_first_charactor(char *line, char c);
int	find_last_charactor(char *line, char c);

//quote_str_utill
char	*arrange_str_cpy(char *ret, char *s1, char *s2, char *s3);
char	*arrange_str(char **sep_str, char *line, int front, int back);
char	*substitution_env(t_env *env, char *str, char *origin, int exit_code);
char	*split_dup_quote(char *line, char c);

#endif