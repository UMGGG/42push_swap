/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:32:22 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/30 07:34:46 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*getarr(t_deque *deq, int r)
{
	int		*arr;
	int		i;
	t_node	*curr;

	arr = malloc(sizeof(int) * r);
	if (arr == NULL)
		return (0);
	curr = deq->first;
	i = 0;
	while (i != r)
	{
		arr[i] = curr->num;
		curr = curr->next;
		i++;
	}
	return (arr);
}

int	partition(int arr[], int l, int r)
{
	int	pivot;
	int	i;
	int	save;

	pivot = arr[r];
	i = (l - 1);
	while (l <= r - 1)
	{
		if (arr[l] <= pivot)
		{
			i++;
			save = arr[i];
			arr[i] = arr[l];
			arr[l] = save;
		}
		l++;
	}
	save = arr[i + 1];
	arr[i + 1] = arr[r];
	arr[r] = save;
	return (i + 1);
}

void	quicksort(int arr[], int l, int r)
{
	int	p;

	if (l < r)
	{
		p = partition(arr, l, r);
		quicksort(arr, l, p - 1);
		quicksort(arr, p + 1, r);
	}
}

int	get_pivot(t_deque *deq, int r)
{
	int	*arr;
	int	pivot;

	arr = getarr(deq, r);
	quicksort(arr, 0, r - 1);
	pivot = arr[r / 2];
	free (arr);
	return (pivot);
}
