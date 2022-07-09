/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:09:35 by soo               #+#    #+#             */
/*   Updated: 2022/07/09 17:30:13 by soo              ###   ########.fr       */
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

	line = ft_strdup("cd \"$HOME\" '$USER'");
	// line = ft_strdup("cd \"$USER\"\"HOME\" \"$PWD\"");
	env = (t_env *)malloc(sizeof(t_env));
	ft_memset(env, 0, sizeof(t_env));
	init_env(env, envp);
	ret = quote_line(line, 1, env);
	printf("main : %s\n", ret);
}