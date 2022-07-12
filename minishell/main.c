/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:09:35 by soo               #+#    #+#             */
/*   Updated: 2022/07/12 22:19:14 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "env.h"
#include "quote.h"

int main(int argc, char **argv, char **envp)
{
	t_env	*env;
	char	*line;
	char	*ret;

	(void)argc;
	(void)argv;

	// line = ft_strdup("echo \"$USER\" '$USER' '$USER' '$USER' \"$USER\""); // "" '' "" 공백 o
	// line = ft_strdup("echo '$USER' '$USER' '$USER'"); // "" "" ""공백 o
	// line = ft_strdup("echo '$USER''$USER''$USER'"); // "" "" ""공백 x
	// line = ft_strdup("echo aaa \"$USER\"b \"$USER\"ccc \"$USER\""); //문자열""문자열 "" 문자열"" 공백 o
	// line = ft_strdup("echo aaa \"$USER\"\"$USER\"\"$USER\""); //문자열 "" "" "" 공백 x
	// line = ft_strdup("echo \"$USER\" '$USER'\"$USER\"");
	// line = ft_strdup("cd \"$USER\" '$HOME' \"$PW\" \"$HOME\""); 
	// line = ft_strdup("echo \"$USER\" '$USER' \"$USER\" '$USER' \"$USER\" '$USER'"); // "" '' "" ''  공백 o
	// line = ft_strdup("echo \"$USER\"'$USER'\"$USER\"'$USER'\"$USER\"'$USER'"); // "" '' "" '' 공백x
	// line = ft_strdup("echo \"$USER\"'$USER''$USER''$USER'\"$USER\""); // "" '' "" 공백 x 
	// line = ft_strdup("echo \"$USER\" '$?'\" $ USER  $? $HOME\"");
	line = ft_strdup("echo \"$HOME $HOME\"");
	// 로직상..시발안됨......
	// line = ft_strdup("cd '\"$HOME\"'");
	env = (t_env *)malloc(sizeof(t_env));
	ft_memset(env, 0, sizeof(t_env));
	init_env(env, envp);
	unset(&env, "unset HOME");
	// print_env(env);
	// printf("\n-----------\n");
	// print_export(env);
	// printf("\n-----------\n");
	ret = quote_line(line, 0, env);
	printf("main : %s\n", ret);
	// "dd "" dd""dd"
	// "" "" ""
}