/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_deq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:24:02 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/30 09:16:28 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	btoa_2(t_deque *deq_a, t_deque *deq_b, t_deque *deq_str)
{
	if (deq_b->first->num > deq_b->first->next->num)
		do_sb(deq_b, deq_str);
	do_pa(deq_a, deq_b, deq_str);
	do_ra(deq_a, deq_str);
	do_pa(deq_a, deq_b, deq_str);
	do_ra(deq_a, deq_str);
}

void	btoa(t_deque *deq_a, t_deque *deq_b, t_deque *deq_str, int r)
{
	int		pivot;
	int		pa;
	int		rb;
	int		i;
	t_node	*curr;

	i = 0;
	if (r == 1)
		do_pa(deq_a, deq_b, deq_str);
	else if (r == 2)
		btoa_2(deq_a, deq_b, deq_str);
	else
	{
		pa = 0;
		rb = 0;
		pivot = get_pivot(deq_b, r);
		while (i < r)
		{
			curr = deq_b->first;
			if (curr->num >= pivot)
			{
				do_rb(deq_b, deq_str);
				rb++;
			}
			else
			{
				do_pa(deq_a, deq_b, deq_str);
				pa++;
			}
			i++;
		}
		i = 0;
		while (i != rb)
		{
			do_rrb(deq_b, deq_str);
			i++;
		}
		atob(deq_a, deq_b, deq_str, pa);
		btoa(deq_a, deq_b, deq_str, rb);
	}
}

void	atob_2(t_deque *deq_a, t_deque *deq_str)
{
	if (deq_a->first->num > deq_a->first->next->num)
		do_sa(deq_a, deq_str);
	do_ra(deq_a, deq_str);
	do_ra(deq_a, deq_str);
}

void	atob(t_deque *deq_a, t_deque *deq_b, t_deque *deq_str, int r)
{
	int		pivot;
	int		pb;
	int		ra;
	int		i;
	t_node	*curr;

	i = 0;
	if (r == 1)
		do_ra(deq_a, deq_str);
	else if (r == 2)
		atob_2(deq_a, deq_str);
	else
	{
		pb = 0;
		ra = 0;
		pivot = get_pivot(deq_a, r);
		while (i < r)
		{
			curr = deq_a->first;
			if (curr->num < pivot)
			{
				do_ra(deq_a, deq_str);
				ra++;
			}
			else
			{
				do_pb(deq_a, deq_b, deq_str);
				pb++;
			}
			i++;
		}
		i = 0;
		while (i != ra)
		{
			do_rra(deq_a, deq_str);
			i++;
		}
		atob(deq_a, deq_b, deq_str, ra);
		btoa(deq_a, deq_b, deq_str, pb);
	}
}
