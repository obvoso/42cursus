/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:25:00 by soo               #+#    #+#             */
/*   Updated: 2022/04/06 22:32:19 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd[2];
	int j;
	char *line = 0;

	j = 1;
	printf("\n==========================================\n");
	printf("========= TEST 2 : Empty Lines ===========\n");
	printf("==========================================\n\n");
	if ((fd[0] = open("t1.txt", O_RDONLY)))
	{
		while ((line = (get_next_line(fd[0]))) != NULL)
		{
			printf("|%s\n", line);
			free(line);
			j++;
		}
		line = get_next_line(fd[0]);
		printf("|%s\n", line);
		line = get_next_line(fd[0]);
		printf("|%s\n", line);
		free(line);
		close(fd[0]);
	}
	// if ((fd[1] = open("t2.txt", O_RDONLY)))
	// 	{
	// 	while ((line = (get_next_line(fd[1]))) != NULL)
	// 	{
	// 		printf("|%s\n", line);
	// 		free(line);
	// 		j++;
	// 	}
	// 	printf("|%s\n", line);
	// 	free(line);
	// 	close(fd[1]);
	// }
	/*
	if ((fd[2] = open("testscript3.txt", O_RDONLY)))
	{
		while ((line = (get_next_line(fd[2]))) != NULL)
		{
			printf("|%s\n", line);
			free(line);
			j++;
		}
		free(line);
		close(fd[2]);
	}
	if ((fd[3] = open("testscript4.txt", O_RDONLY)))
	{
		while ((line = (get_next_line(fd[3]))) != NULL)
		{
			printf("|%s\n", line);
			free(line);
			j++;
		}
		free(line);
		close(fd[3]);
	}
	*/
}
