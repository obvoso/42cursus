/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:59:16 by soo               #+#    #+#             */
/*   Updated: 2022/07/12 21:47:56 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	print_env(t_env	*head)
{
	t_env	*now;
	
	now = head;
	while (now)
	{
		if(now->value && !now->unset_flag)
			ft_printf("%s=%s\n", now->key, now->value);
		now = now->next;
	}
}