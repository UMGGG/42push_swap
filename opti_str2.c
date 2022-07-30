/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_str2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 09:14:54 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/30 09:15:14 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	change_command(t_deque *deq, int num)
{
	pop_node_front(deq);
	pop_node_front(deq);
	push_node_front(deq, num);
	return (1);
}

int	delete_command(t_deque *deq)
{
	int	save;

	pop_node_front(deq);
	pop_node_front(deq);
	save = pop_node_back(deq);
	if (save == 99)
		push_node_back(deq, 99);
	else
		push_node_front(deq, save);
	return (1);
}

void	next_command(t_deque *deq)
{
	int	save;

	save = deq->first->num;
	pop_node_front(deq);
	push_node_back(deq, save);
}
