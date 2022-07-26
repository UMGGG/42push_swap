/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sorting_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 02:16:28 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/27 02:48:10 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_pa(t_deque *deq_a, t_deque *deq_b)
{
	int	save;

	if (deq_b->first == NULL)
		return (0);
	save = deq_b->first->num;
	pop_node_front(deq_b);
	push_node_front(deq_a, save);
	ft_printf("pa\n");
	return (0);
}

int	do_pb(t_deque *deq_a, t_deque *deq_b)
{
	int	save;

	if (deq_a->first == NULL)
		return (0);
	save = deq_a->first->num;
	pop_node_front(deq_a);
	push_node_front(deq_b, save);
	ft_printf("pb\n");
	return (0);
}
