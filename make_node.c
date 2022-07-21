/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 01:54:32 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/22 04:09:12 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_node(t_deque *deq, int num)
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
	return (0);
}

int	add_node_list(t_deque *deq, char *argv)
{
	char	**num_list;
	int		i;

	i = 0;
	num_list = ft_split(argv, ' ');
	if (num_list == NULL)
		return (1);
	while (num_list[i] != NULL)
	{
		if (add_node(deq, ft_atoi(num_list[i])))
		{
			free_list(num_list);
			return (1);
		}
		i++;
	}
	free_list(num_list);
	return (0);
}
