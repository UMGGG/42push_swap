/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_deq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:24:02 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/08/03 03:31:14 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_param
{
	int		pivot;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		i;
	t_node	*curr;
}	t_param;

void	set_param(t_param	*param)
{
	param->pivot = 0;
	param->pa = 0;
	param->pb = 0;
	param->ra = 0;
	param->rb = 0;
	param->i = -1;
	param->curr = NULL;
}

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
	t_param	param;

	set_param(&param);
	if (r == 1)
		do_pa(deq_a, deq_b, deq_str);
	else if (r == 2)
		btoa_2(deq_a, deq_b, deq_str);
	else
	{
		param.pivot = get_pivot(deq_b, r);
		while (++param.i < r)
		{
			param.curr = deq_b->first;
			if (param.curr->num >= param.pivot)
				param.rb += do_rb(deq_b, deq_str);
			else
				param.pa += do_pa(deq_a, deq_b, deq_str);
		}
		param.i = -1;
		while (++param.i != param.rb)
			do_rrb(deq_b, deq_str);
		atob(deq_a, deq_b, deq_str, param.pa, 0);
		btoa(deq_a, deq_b, deq_str, param.rb);
	}
}

void	atob_2(t_deque *deq_a, t_deque *deq_str)
{
	if (deq_a->first->num > deq_a->first->next->num)
		do_sa(deq_a, deq_str);
	do_ra(deq_a, deq_str);
	do_ra(deq_a, deq_str);
}

void	atob(t_deque *deq_a, t_deque *deq_b, t_deque *deq_str, int r, int f)
{
	int		pivot;
	int		pb;
	int		ra;
	int		i;
	t_node	*curr;

	i = -1;
	if (r == 1)
		do_ra(deq_a, deq_str);
	else if (r == 2)
		atob_2(deq_a, deq_str);
	else
	{
		pb = 0;
		ra = 0;
		pivot = get_pivot(deq_a, r);
		while (++i < r)
		{
			curr = deq_a->first;
			if (curr->num < pivot)
				ra += do_ra(deq_a, deq_str);
			else
				pb += do_pb(deq_a, deq_b, deq_str);
		}
		i = -1;
		while (++i != ra && f != 1)
			do_rra(deq_a, deq_str);
		atob(deq_a, deq_b, deq_str, ra, 0);
		btoa(deq_a, deq_b, deq_str, pb);
	}
}
