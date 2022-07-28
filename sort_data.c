/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 04:22:47 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/28 17:07:21 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_3(t_deque *deq)
{
	t_node	*curr;

	curr = deq->first->next;
	if (deq->first->num > curr->num)
	{
		curr = curr->next;
		if (deq->first->num > curr->num)
			do_ra(deq);
		curr = deq->first->next;
		if (deq->first->num > curr->num)
			do_sa(deq);
	}
	else
	{
		if (curr->num < curr->next->num)
			do_sa(deq);
		else if (curr->num > curr->next->num)
		{
			do_rra(deq);
			if (deq->first->num > deq->first->next->num)
				do_sa(deq);
		}
	}
	return (0);
}

int	sort_4(t_deque *deq_a, t_deque *deq_b)
{
	int		min;
	t_node	*curr;

	min = deq_a->first->num;
	curr = deq_a->first;
	while (curr)
	{
		if (min > curr->num)
			min = curr->num;
		curr = curr->next;
	}
	while (deq_a->first->num != min)
		do_ra(deq_a);
	if (is_sorted(deq_a) != 1)
	{
		do_pb(deq_a, deq_b);
		sort_3(deq_a);
		do_pa(deq_a, deq_b);
	}
	return (0);
}

int	sort_5(t_deque *deq_a, t_deque *deq_b)
{
	int		mid;
	int		countpb;

	countpb = 0;
	mid = find_mid(deq_a);
	while (countpb != 2)
	{
		if (deq_a->first->num >= mid)
			do_ra(deq_a);
		else
		{
			do_pb(deq_a, deq_b);
			countpb++;
		}
	}
	if (is_sorted(deq_a) != 1)
		sort_3(deq_a);
	if (deq_b->first->num < deq_b->last->num)
		do_sb(deq_b);
	do_pa(deq_a, deq_b);
	do_pa(deq_a, deq_b);
	return (0);
}

int	start_sort(t_deque *deq_a, t_deque *deq_b)
{
	int	node;

	if (deq_a->first == deq_a->last)
		return (0);
	node = is_sorted(deq_a);
	if (node == 1)
		return (0);
	else if (node == 2)
		do_sa(deq_a);
	else if (node == 3)
		sort_3(deq_a);
	else if (node == 4)
		sort_4(deq_a, deq_b);
	else if (node == 5)
		sort_5(deq_a, deq_b);
	return (0);
}
