/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:09:35 by soo               #+#    #+#             */
/*   Updated: 2022/07/06 21:08:52 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "env.h"

int main(int argc, char **argv, char **envp)
{
	t_env	*env;
	char	*line;

	(void)argc;
	(void)argv;


	line = "export TERM_PROGRAM=111111222 bb=cc dd";
	env = (t_env *)malloc(sizeof(t_env));
	ft_memset(env, 0, sizeof(t_env));
	init_env(env, envp);
	print_env(env);
	printf("\nenv\n");

	printf("\nexport\n");
	export(env, line);
	line = "export";
	export(env, line);
	printf("\nprint_env\n");
	print_env(env);

	printf("\nunset\n");
	line = "unset bb dd";
	unset(&env, line);
	printf("\nprint_env\n");
	print_env(env);
	line = "export";
	printf("\nprint export\n");
	export(env, line);
	
	while (1)
	{}
}