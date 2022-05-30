/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:19:26 by soo               #+#    #+#             */
/*   Updated: 2022/05/29 20:10:36 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = size - 1;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i++] = tab[j];
		tab[j--] = tmp;
	}
}

void	quick_sort_swap(int *arr, int i, int j)
{
	int	tmp;

	tmp = arr[j];
	arr[j] = arr[i];
	arr[i] = tmp;
}

void	quick_sort(int *arr, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	if (start >= end)
		return ;
	pivot = start;
	i = start + 1;
	j = end;
	while (i <= j)
	{
		while (i <= end && arr[i] < arr[pivot])
			++i;
		while (j >= start && arr[j] > arr[pivot])
			--j;
		if (i > j)
			quick_sort_swap(arr, pivot, j);
		else
			quick_sort_swap(arr, i, j);
	}
	quick_sort(arr, start, j - 1);
	quick_sort(arr, j + 1, end);
}

int	is_sort(int	*tab, int length)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (i < length - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			flag = 2;
			break ;
		}
		++i;
	}
	i = 0;
	if (flag == 2)
	{
		while (i < length - 1)
		{
			if (tab[i] < tab[i + 1])
				return (0);
			++i;
		}
	}
	return (flag);
}

int	*sort_array(int size, t_node *deque)
{
	int	*arr;
	int	i;
	int	sort_flag;

	i = 0;
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	while (i < size)
	{
		arr[i++] = deque->value;
		deque = deque->prev;
	}
	sort_flag = is_sort(arr, size);
	if (!sort_flag)
		quick_sort(arr, 0, size - 1);
	else if (sort_flag == 2)
		ft_rev_int_tab(arr, size);
	if (sort_flag == 1)
		return (NULL);
	return (arr);
}
