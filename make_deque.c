/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_deque.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 04:00:41 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/08/04 00:19:46 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_deque	*make_deque(void)
{
	t_deque	*new_deque;

	new_deque = malloc(sizeof(t_deque));
	new_deque->first = NULL;
	new_deque->last = NULL;
	new_deque->size = 0;
	return (new_deque);
}

int	push_in_deq(int argc, char **argv, t_deque *deq)
{
	int		i;

	i = 1;
	while (i != argc)
	{
		if (check_str_num(argv[i]))
		{
			if (push_node_for_list(deq, argv[i]))
				return (1);
		}
		else
		{
			if (push_node_back_for_str(deq, ft_atoi(argv[i])))
				return (1);
		}
		i++;
	}
	return (0);
}

int	push_node_back_for_str(t_deque *deq, int num)
{
	t_node	*new_node;

	if (check_duplicate(deq, num))
		return (1);
	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return (1);
	new_node->num = num;
	new_node->next = NULL;
	new_node->prev = deq->last;
	if (deq->last == NULL && deq->first == NULL)
	{
		deq->last = new_node;
		deq->first = new_node;
	}
	else
	{
		if (deq->last != NULL)
			deq->last->next = new_node;
		deq->last = new_node;
	}
	deq->size++;
	return (0);
}
