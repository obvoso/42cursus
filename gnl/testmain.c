/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songmin <autumninmoon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:25:00 by soo               #+#    #+#             */
/*   Updated: 2022/04/02 23:06:00 by songmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd;
	//	int i;
	int j;
	char *line = 0;

	j = 1;
	printf("\n==========================================\n");
	printf("========= TEST 2 : Empty Lines ===========\n");
	printf("==========================================\n\n");
	if (!(fd = open("testscript.txt", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((line = (get_next_line(fd))) != NULL)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	//if (line == 0)
	//	printf("|%s\n", line); free(line);
	close(fd);
}
