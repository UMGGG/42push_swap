/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sorting_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 02:20:40 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/29 03:59:03 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_r(t_deque *deq)
{
	int	save;

	if (deq->first == NULL)
		return (0);
	save = deq->first->num;
	pop_node_front(deq);
	push_node_back(deq, save);
	return (1);
}

int	do_ra(t_deque *deq_a, t_deque *deq_str)
{
	if (do_r(deq_a))
		push_node_back(deq_str, 6);
	else
		return (1);
	return (0);
}

int	do_rb(t_deque *deq_b, t_deque *deq_str)
{
	if (do_r(deq_b))
		push_node_back(deq_str, 7);
	else
		return (1);
	return (0);
}

int	do_rr(t_deque *deq_a, t_deque *deq_b, t_deque *deq_str)
{
	int	check_num;

	check_num = 0;
	check_num += (do_r(deq_a));
	check_num += (do_r(deq_b));
	if (check_num == 0)
		return (1);
	else
		push_node_back(deq_str, 8);
	return (0);
}
