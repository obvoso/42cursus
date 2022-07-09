/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songmin <autumninmoon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:14:19 by soo               #+#    #+#             */
/*   Updated: 2022/07/08 21:10:09 by songmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUOTE_H
# define QUOTE_H

#include "./libft/libft.h"
#include "env.h"

//quote
int	del_quote_cnt(char *origin, char c);
char	*del_quote(char *origin, char c);
char	*s_line_handler(t_env *env, char **line, char *origin, int exit_code);
char	*d_line_handler(t_env *env, char **line, char **origin, int exit_code);
char	*quote_line(char *origin, int exit_code, t_env *env);

//quote_utils
char *find_env(t_env *env, char *str, int exit_code);
int	cnt_quote(char *line, char c);
int	find_first_charactor(char *line, char c);
int	find_last_charactor(char *line, char c);

//quote_str_utill
char	*arrange_str_cpy(char *ret, char *s1, char *s2, char *s3);
char	*arrange_str(char **sep_str, char *origin, char **line);
char	*substitution_env(t_env *env, char **line, char *origin, int exit_code);
char	*split_dup_quote(char *line, char c);

#endif