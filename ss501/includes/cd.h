/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:06:21 by soo               #+#    #+#             */
/*   Updated: 2022/07/14 22:04:47 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CD_H
# define CD_H

# include <unistd.h>
# include "../srcs/libft/libft.h"

int chdir_main(t_env *env, char *line);

#endif