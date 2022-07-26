/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 02:57:14 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/27 03:09:55 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_deque *deq)
{
	int		num;
	t_node	*curr;

	if (deq->first == deq->last)
		return (0);
	num = deq->first->num;
	curr = deq->first;
	while (curr)
	{
		if (num > curr->num)
			return (1);
		num = curr->num;
		curr = curr->next;
	}
	ft_printf("good!\n");
	return (0);
}

int	print_deq(t_deque *deq)
{
	t_node	*curr;

	if (deq->first == NULL)
		return (1);
	curr = deq->first;
	while (curr)
	{
		ft_printf("%d\n", curr->num);
		curr = curr->next;
	}
	return (0);
}
