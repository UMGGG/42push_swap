/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 07:45:25 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/08/15 16:35:41 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check12345(t_deque *deq)
{
	if (deq->first->num == 1)
	{
		if (deq->first->next->num == 1)
			return (delete_command(deq));
		else if (deq->first->next->num == 2)
			return (change_command(deq, 3));
	}
	else if (deq->first->num == 2)
	{
		if (deq->first->next->num == 2)
			return (delete_command(deq));
		else if (deq->first->next->num == 1)
			return (change_command(deq, 3));
	}
	else if (deq->first->num == 3 && deq->first->next->num == 3)
		return (delete_command(deq));
	else if (deq->first->num == 4 && deq->first->next->num == 5)
		return (delete_command(deq));
	else if (deq->first->num == 5 && deq->first->next->num == 4)
		return (delete_command(deq));
	return (0);
}

int	check6789(t_deque *deq)
{
	if (deq->first->num == 6)
	{
		if (deq->first->next->num == 9)
			return (delete_command(deq));
		else if (deq->first->next->num == 7)
			return (change_command(deq, 8));
	}
	else if (deq->first->num == 7)
	{
		if (deq->first->next->num == 10)
			return (delete_command(deq));
		else if (deq->first->next->num == 6)
			return (change_command(deq, 8));
	}
	else if (deq->first->num == 8 && deq->first->next->num == 11)
		return (delete_command(deq));
	else if (deq->first->num == 9)
	{
		if (deq->first->next->num == 6)
			return (delete_command(deq));
		else if (deq->first->next->num == 10)
			return (change_command(deq, 11));
	}
	return (0);
}

int	check1011(t_deque *deq)
{
	if (deq->first->num == 10)
	{
		if (deq->first->next->num == 7)
			return (delete_command(deq));
		else if (deq->first->next->num == 9)
			return (change_command(deq, 11));
	}
	else if (deq->first->num == 11 && deq->first->next->num == 8)
		return (delete_command(deq));
	return (0);
}

void	opt_str(t_deque *deq)
{
	int	is_changed;

	is_changed = 0;
	push_node_back(deq, 99);
	while (deq->first->num != 99)
	{
		if (deq->first->num == 1 || deq->first->num == 2 || \
		deq->first->num == 3 || deq->first->num == 4 || deq->first->num == 5)
			is_changed = check12345(deq);
		else if (deq->first->num == 6 || deq->first->num == 7 || \
		deq->first->num == 8 || deq->first->num == 9)
			is_changed = check6789(deq);
		else if (deq->first->num == 10 || deq->first->num == 11)
			is_changed = check1011(deq);
		if (is_changed == 0)
			next_command(deq);
		is_changed = 0;
	}
	pop_node_front(deq);
}
