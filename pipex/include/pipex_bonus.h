/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 21:02:21 by soo               #+#    #+#             */
/*   Updated: 2022/06/12 21:11:07 by soo              ###   ########.fr       */
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

typedef struct s_pipex
{
	char	**cmd;
	char	*c_path;
	int		pipe[2];
}t_pipex;

#endif