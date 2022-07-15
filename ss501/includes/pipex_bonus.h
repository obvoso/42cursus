/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:09:13 by schoe             #+#    #+#             */
/*   Updated: 2022/07/15 21:28:42 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# define P_W	1
# define P_R	0
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <termios.h>
#include <stdlib.h>
#include <signal.h>
# include <sys/stat.h>
# include <string.h>
#include <fcntl.h>
# include "libft.h"
#include "env.h"

typedef struct s_pipex
{
	char	**ev;
	char	***indirec;
	char	***outdirec;
	char	***temp;
	char	***cmd;
	char	**exe_path;
	char	*line;
	char	***trans;
	pid_t	pid;//
	int		**fd;
	int		end;
	int		check;
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
int		ft_cmd_parent(int i, t_pipex *val, t_input *input,  t_env *env);
//ft_error_check
void	ft_error_check(int i, t_input *input, t_pipex *val);
//ft_parsing
int		ft_access_check(char *cmd, t_pipex *val, int check);
void	ft_av_parsing(t_input *input, t_pipex *val);
char	**ft_ev_parsing(char **enpv);
//ft_pipex
void	ft_make_pipe(t_input *input, t_pipex *val);
void	ft_close_fd(pid_t pid, t_pipex *val, int i);
int		ft_pipex(int ac, t_input *input, t_pipex *val, t_env *env);
//main
void	ft_init(t_pipex *val, t_input *input);
int		ft_pipe(char *line, char **envp, t_env *env);
void	dfl_handler(int sigquit);
//etc
int		ft_dire_in(char **indirec, int index);
int		ft_dire_out(char **outdirec);
void	ft_error_print(char *str, int no);
char	*ft_add_space(char *src, char c);
int		ft_direc_count(char **str, char *c);
void	ft_tolower_str(char *str);
int		ft_built_check(char *str);
int		ft_taptosp(char *line);
int		ft_in_built(t_pipex *val, t_input *input, int i,  t_env *env);
//syntax
int		ft_pass_quot(char *line, int i);
int		ft_syntax_check(char *line);
//free
void	ft_free2(void **temp);
void	ft_free3(void ***temp);
void	ft_pipe_clear(t_pipex *val, t_input *input);
//echo,pwd
void	ft_print_echo(t_pipex *val, int i, int k, int check);
void	*ft_echo(t_pipex *val, int i);
void	*ft_pwd(void);
//trans_quot
char	*ft_trans_quot(char *line);
char	*ft_re_trans_quot(char *line, int index);
//here_doc
void	ft_make_here_doc(char ***indirec);
#endif
