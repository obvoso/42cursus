/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 21:02:21 by soo               #+#    #+#             */
/*   Updated: 2022/06/16 13:40:55 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include "../srcs/libft/libft.h"
# include "pipex.h"

typedef struct s_px
{
	char		**cmd;
	char		*path;
	char		*infile;
	char		*outfile;
	int			pipe[2];
	int			num;
	pid_t		pid;
	struct s_px	*prev;
	struct s_px	*next;
}	t_px;

//utils
t_px	*px_last(t_px *head);
void	exe_first_cmd(t_px *node, char **envp);
void	exe_last_cmd(t_px *node, char **envp);

//main
t_px	*here_doc(int argc, char **argv, t_px **head);
t_px	*px_node_init(t_px **head, char **av, char **ep, int num);
void	make_process(t_px *node, int argc, char **argv, char **envp);
void	exe_cmd(t_px *node, int argc, char **argv, char **envp);

#endif