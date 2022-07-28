/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 02:57:14 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/28 01:06:07 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_deque *deq)
{
	int		num;
	int		nodecounter;
	int		sortchecker;
	t_node	*curr;

	nodecounter = 0;
	sortchecker = 0;
	if (deq->first == deq->last)
		return (0);
	num = deq->first->num;
	curr = deq->first;
	while (curr)
	{
		if (num > curr->num)
			sortchecker = 1;
		num = curr->num;
		curr = curr->next;
		nodecounter++;
	}
	if (sortchecker == 0)
		return (1);
	return (nodecounter);
}

int	print_deq(t_deque *deq)
{
	t_node	*curr;

	if (deq->first == NULL)
		return (1);
	curr = deq->first;
	while (curr)
	{
		ft_printf("%d\n", curr->num);
		curr = curr->next;
	}
	return (0);
}

int	find_mid(t_deque *deq)
{
	int		up;
	t_node	*curr1;
	t_node	*curr2;

	up = 0;
	curr1 = deq->first;
	while (curr1)
	{
		curr2 = deq->first;
		while (curr2)
		{
			if (curr1->num < curr2->num)
				up++;
			else if (curr1->num > curr2->num)
				up--;
			curr2 = curr2->next;
		}
		if (up == 0)
			return (curr1->num);
		up = 0;
		curr1 = curr1->next;
	}
	return (0);
}
