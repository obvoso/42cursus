/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:25:00 by soo               #+#    #+#             */
/*   Updated: 2022/03/31 22:03:17 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int main() { 
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
	printf("열리긴 열림\n");
	while ((line = (get_next_line(fd))) > 0) 
	{
		printf("|%s\n", line); 
		free(line);
		j++; 
	}
	//if (line == 0)
//	printf("|%s\n", line); free(line); 
close(fd); 
}
