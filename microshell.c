#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

int ft_putstr(char *argv, char *str)
{
	while (*argv)
		write(2, argv++, 1);
	if (str)
		while (*str)
			write(2, str++, 1);
	write(2, "\n", 1);
	return (1);
}

int ft_execute(char **argv, int i, int tmp_fd, char **env)
{
	argv[i] = NULL;
	dup2(tmp_fd, 0);
	close(tmp_fd);
	execve(argv[0], argv, env);
	return (ft_putstr("cannot execute ", argv[0]));
}

int main(int argc, char **argv, char **env)
{
	int i = 0;
	int fd[2];
	int tmp_fd;
	(void) argc;

	tmp_fd = dup(0);
	while (argv[i] && argv[ i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
			++i;
		if (!strcmp(argv[0], "cd"))
		{
			if (i != 2)
				ft_putstr("cd bad", NULL);
			else if (chdir(argv[1]))
				ft_putstr("cannot chdir", argv[1]);
		}
		else if (i && (!argv[i] || !strcmp(argv[i], ";")))
		{
			if (!fork())
			{
				if (ft_execute(argv, i, tmp_fd, env))
					return (1);
			}
			else
			{
				close(tmp_fd);
				while (waitpid(-1, NULL, 0) != -1)
					;
				tmp_fd = dup(0);
			}
		}
		else if (i && !strcmp(argv[i], "|"))
		{
			pipe(fd);
			if (!fork())
			{
				dup2(fd[1], 1);
				close(fd[0]);
				close(fd[1]);
				if (ft_execute(argv, i, tmp_fd, env))
					return (1);
			}
			else
			{
				close(tmp_fd);
				close(fd[1]);
				tmp_fd = fd[0];
			}
		}
	}
	close (tmp_fd);
	return (0);
}