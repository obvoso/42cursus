/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:05:05 by soo               #+#    #+#             */
/*   Updated: 2022/07/15 21:34:05 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "env.h"
#include "cd.h"

int chdir_main(t_env *env, char *line)
{
	(void) env;
	(void) line;
	// char	**split_line;
	// char	*before;
	// char	*after;
	// char	*oldpwd;
	// char	*pwd;

	// before = getcwd(NULL, 0);

	// split_line = line_format(line, "cd");
	// chdir(split_line[1]);
	// after = getcwd(NULL, 0);

	// pwd = ft_strjoin("export PWD=", after);
	// oldpwd = ft_strjoin("export OLDPWD=", before);
	// free(before);

	// export(env, pwd);
	// export(env, oldpwd);
	
	// printf("before : %s\n", before);
	// printf("after : %s\n", after);

	// print_env(env);
	
	return (0);
}

