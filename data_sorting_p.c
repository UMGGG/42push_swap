/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sorting_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 02:16:28 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/08/03 03:03:25 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_pa(t_deque *deq_a, t_deque *deq_b, t_deque *deq_str)
{
	int	save;

	if (deq_b->first == NULL)
		return (0);
	save = deq_b->first->num;
	pop_node_front(deq_b);
	push_node_front(deq_a, save);
	push_node_back(deq_str, 4);
	return (1);
}

int	do_pb(t_deque *deq_a, t_deque *deq_b, t_deque *deq_str)
{
	int	save;

	if (deq_a->first == NULL)
		return (0);
	save = deq_a->first->num;
	pop_node_front(deq_a);
	push_node_front(deq_b, save);
	push_node_back(deq_str, 5);
	return (1);
}
