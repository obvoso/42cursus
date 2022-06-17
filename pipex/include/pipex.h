/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:50:38 by soo               #+#    #+#             */
/*   Updated: 2022/06/16 21:30:45 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include "../srcs/libft/libft.h"

//error
int		check_argv(char **argv, int ac);
int		check_slash_dot(char **av);
int		check_char(char **av);

//path
char	**split_path(char **envp, char **argv, char ***cmd, int idx);
char	*check_path(char **path, char *cmd);

#endif