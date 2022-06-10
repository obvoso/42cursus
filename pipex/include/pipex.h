/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:50:38 by soo               #+#    #+#             */
/*   Updated: 2022/06/10 23:00:54 by soo              ###   ########.fr       */
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
int		check_arg(int argc, char **argv);
int		check_slash_dot(char **av);

//path
char	**split_path(char **envp, char **argv, char ***cmd, int idx);
char	*check_path(char **path, char *cmd);

//main (process, cmd)
//void	umma_process(pid_t pid, char **argv, char **envp, int fd[]);
//void	ddal_process(char **argv, char **envp, int fd[]);
void	first_cmd(char **argv, char **envp, int pipe[]);
void	second_cmd(char **argv, char **envp, int pipe[]);

#endif