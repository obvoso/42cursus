/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:06:10 by schoe             #+#    #+#             */
/*   Updated: 2022/06/20 14:42:40 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define P_W	1
# define P_R	0
# include <unistd.h>

typedef struct s_pipex
{
	char	**ev;
	char	***cmd;
	char	**exe_path;
	int		**fd;
	int		end;
}	t_pipex;

typedef struct s_input
{
	int		ac;
	char	**av;
	char	**ev;
}	t_input;

//ft_cmd
void	ft_cmd_end(int i, t_pipex *val, t_input *input);
void	ft_cmd_mid1(int i, t_pipex *val, t_input *input);
void	ft_cmd_start(int i, t_pipex *val, t_input *input);
//ft_error_check
void	ft_error_check(int i, t_input *input, t_pipex *val);
//ft_parsing
int		ft_access_check(char *cmd, t_pipex *val, int check);
void	ft_av_parsing(t_input *input, t_pipex *val);
char	**ft_ev_parsing(char **enpv);
//ft_pipex
void	ft_make_pipe(t_input *input, t_pipex *val);
void	ft_close_fd(pid_t pid, t_pipex *val, int i);
int		ft_pipex(int ac, t_input *input, t_pipex *val);
//main
void	ft_init(t_pipex *val, t_input *input);
#endif
