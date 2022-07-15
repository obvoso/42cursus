#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include "pipex_bonus.h"
#include "libft.h"
#include "cd.h"
#include "env.h"
#include "quote.h"

//ctrl_c 시그널 핸들링
void	sig_handler(int signum)
{
	if (signum != SIGINT)
		return ;
	write(STDOUT_FILENO, "\n", 1);
	if (rl_on_new_line() == -1)
		exit(1);
	rl_replace_line("", 1);
	rl_redisplay();
}
void	dfl_handler(int sigquit)
{
	write(1,"111",3);
	if (sigquit != SIGQUIT)
		return ;
	write(STDOUT_FILENO, "^\\Quit: 3\n", 10);
	if (rl_on_new_line() == -1)
		exit(1);
	rl_replace_line("", 1);
	rl_redisplay();
}
//return : 입력한 명령어 한줄
//prompt 출력
char	*ft_prompt(void)
{
	char	*line;

	line = readline("ss_shell$ ");
	if (line == NULL)
	{
		printf("\033[1A");
		printf("\033[10C");
		printf("exit\n");
		exit(-1);
	}
	else
	{
		add_history(line);
		return (line);
	}
}

int	main(int ac, char **av, char **envp)
{
	char	*line;
	struct termios termios;
	int	exit_code;
	
	t_env *env;

	env = (t_env *)malloc(sizeof(t_env));
	ft_memset(env, 0, sizeof(t_env));
	init_env(env, envp);

	(void)ac;
	(void)av;
    tcgetattr(STDIN_FILENO, &termios);
    termios.c_lflag &= ~ECHOCTL;
    tcsetattr(STDIN_FILENO, TCSANOW, &termios);
    exit_code = 0;
	signal(SIGINT, sig_handler);
	while (1)
	{
		signal(SIGQUIT, SIG_IGN);
		line = ft_prompt();
		line = ft_add_space(line, '>');
		line = ft_add_space(line, '<');
		exit_code = ft_syntax_check(line);
		if (exit_code)
		{
			signal(SIGQUIT, SIG_DFL);
			signal(SIGINT, sig_handler);
			free(line);
			continue ;
		}
		if (ft_taptosp(line))
		{
			signal(SIGQUIT, SIG_DFL);
			signal(SIGINT, sig_handler);
			free(line);
			continue ;
		}
		//"", '', $처리
		if (exit_code)
		{
			printf("\n%d\n", exit_code);
			signal(SIGQUIT, SIG_DFL);
		}
		else
			exit_code = ft_pipe(line, envp, env);
		signal(SIGINT, sig_handler);
		free(line);
//		system("leaks minishell");
	}
}
