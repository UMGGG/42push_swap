/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sorting_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:49:23 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/26 21:17:47 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_sa(t_deque *deq)
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
	ft_printf("sa\n");
	return (0);
}
