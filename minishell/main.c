/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:09:35 by soo               #+#    #+#             */
/*   Updated: 2022/07/14 21:40:03 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/env.h"
#include "include/quote.h"
#include "include/cd.h"

int main(int argc, char **argv, char **envp)
{
	t_env	*env;
	char	*line;
	//char	*ret;

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
	//  line = ft_strdup("echo \"$USER\"'$USER''$USER''$USER'\"$USER\""); // "" '' "" 공백 x 
	//line = ft_strdup("echo \"$HOME\"1 \"$HOME\"2\"$HOME\"333");
	// line = ft_strdup("echo \"$HOME\" \"$HOME\" \"$HOME\"");
	// line = ft_strdup("echo \"$USER\"     '$?'\" $ USER  $?       $HOME\"");
	// 로직상..시발안됨......
	// line = ft_strdup("cd ggkkgkgjdkfjaksdjflkasdflkdsjf11120e0kdfjk$HOME");
	// line = ft_strdup("cd \"'$HOME'\"");
	
	line = ft_strdup("cd ..");
	// line = ft_strdup("echo '$$ $HOME\'");
	env = (t_env *)malloc(sizeof(t_env));
	ft_memset(env, 0, sizeof(t_env));
	init_env(env, envp);
	chdir_main(env, line);
	// export(env, "export a=b c=d");
	//line = ft_strdup("\"$HOME\"");
	// print_env(env);
	// printf("??????????????\n");
	// unset(&env, "unset c");
	// export(env, "export");
	// quote_line(&line, 0, env);
	// printf("main : %s\n", line);
	// "dd "" dd""dd"
	// "" "" ""
	//system("leaks a.out");
}