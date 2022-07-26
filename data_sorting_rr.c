/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sorting_rr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 02:27:38 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/27 02:33:12 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_brr(t_deque *deq)
{
	int	save;

	if (deq->first == NULL)
		return (0);
	save = deq->last->num;
	pop_node_back(deq);
	push_node_front(deq, save);
	return (1);
}

int	do_rra(t_deque *deq_a)
{
	if (do_brr(deq_a))
		ft_printf("rra\n");
	else
		return (1);
	return (0);
}

int	do_rrb(t_deque *deq_b)
{
	if (do_brr(deq_b))
		ft_printf("rrb\n");
	else
		return (1);
	return (0);
}

int	do_rrr(t_deque *deq_a, t_deque *deq_b)
{
	int	check_num;

	check_num = 0;
	check_num += (do_brr(deq_a));
	check_num += (do_brr(deq_b));
	if (check_num == 0)
		return (1);
	else
		ft_printf("rrr\n");
	return (0);
}
