/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sorting_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:49:23 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/29 03:59:29 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_s(t_deque *deq)
{
	int	save1;
	int	save2;

	if (deq->first == deq->last)
		return (0);
	save1 = deq->first->num;
	save2 = deq->first->next->num;
	pop_node_front(deq);
	pop_node_front(deq);
	push_node_front(deq, save1);
	push_node_front(deq, save2);
	return (1);
}

int	do_sa(t_deque *deq, t_deque *deq_str)
{
	if (do_s(deq))
		push_node_back(deq_str, 1);
	else
		return (1);
	return (0);
}

int	do_sb(t_deque *deq, t_deque *deq_str)
{
	if (do_s(deq))
		push_node_back(deq_str, 2);
	else
		return (1);
	return (0);
}

int	do_ss(t_deque *deq_a, t_deque *deq_b, t_deque *deq_str)
{
	int	check_num;

	check_num = 0;
	check_num += (do_s(deq_a));
	check_num += (do_s(deq_b));
	if (check_num == 0)
		return (1);
	else
		push_node_back(deq_str, 3);
	return (0);
}
