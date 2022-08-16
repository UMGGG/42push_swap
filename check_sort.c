/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 02:57:14 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/08/15 16:43:49 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_deque *deq)
{
	int		num;
	t_node	*curr;

	if (deq->first == deq->last)
		return (1);
	num = deq->first->num;
	curr = deq->first;
	while (curr)
	{
		if (num > curr->num)
			return (0);
		num = curr->num;
		curr = curr->next;
	}
	return (1);
}

char	*print_command(int num)
{
	if (num == 1)
		return ("sa\n");
	else if (num == 2)
		return ("sb\n");
	else if (num == 3)
		return ("ss\n");
	else if (num == 4)
		return ("pa\n");
	else if (num == 5)
		return ("pb\n");
	else if (num == 6)
		return ("ra\n");
	else if (num == 7)
		return ("rb\n");
	else if (num == 8)
		return ("rr\n");
	else if (num == 9)
		return ("rra\n");
	else if (num == 10)
		return ("rrb\n");
	else if (num == 11)
		return ("rrr\n");
	else
		return (NULL);
}

int	print_deq(t_deque *deq)
{
	t_node	*curr;

	if (deq->first == NULL)
		return (1);
	curr = deq->first;
	while (curr)
	{
		ft_printf("%s", print_command(curr->num));
		curr = curr->next;
	}
	return (0);
}

int	find_mid(t_deque *deq)
{
	int		up;
	t_node	*curr1;
	t_node	*curr2;

	up = 0;
	curr1 = deq->first;
	while (curr1)
	{
		curr2 = deq->first;
		while (curr2)
		{
			if (curr1->num < curr2->num)
				up++;
			else if (curr1->num > curr2->num)
				up--;
			curr2 = curr2->next;
		}
		if (up == 0)
			return (curr1->num);
		up = 0;
		curr1 = curr1->next;
	}
	return (0);
}
