/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 01:54:32 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/30 08:51:47 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_node_back(t_deque *deq, int num)
{
	t_node	*new_node;

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

int	push_node_front(t_deque *deq, int num)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return (1);
	new_node->num = num;
	new_node->prev = NULL;
	if (deq->first == NULL)
	{
		deq->first = new_node;
		deq->last = new_node;
		new_node->next = NULL;
	}
	else
	{
		deq->first->prev = new_node;
		new_node->next = deq->first;
		deq->first = new_node;
	}
	deq->size++;
	return (0);
}

int	pop_node_front(t_deque *deq)
{
	t_node	*save;
	int		savenum;

	if (deq->first == NULL)
		return (0);
	savenum = deq->first->num;
	save = deq->first->next;
	free(deq->first);
	if (save == NULL)
	{
		deq->first = save;
		deq->last = save;
		deq->size--;
		return (savenum);
	}
	deq->first = save;
	save->prev = NULL;
	deq->size--;
	return (savenum);
}

int	pop_node_back(t_deque *deq)
{
	t_node	*save;
	int		savenum;

	if (deq->last == NULL)
		return (0);
	savenum = deq->last->num;
	save = deq->last->prev;
	free(deq->last);
	if (save == NULL)
	{
		deq->first = save;
		deq->last = save;
		deq->size--;
		return (savenum);
	}
	deq->last = save;
	save->next = NULL;
	deq->size--;
	return (savenum);
}

int	push_node_for_list(t_deque *deq, char *argv)
{
	char	**num_list;
	int		i;

	i = 0;
	num_list = ft_split(argv, ' ');
	if (num_list == NULL)
		return (1);
	while (num_list[i] != NULL)
	{
		if (push_node_back_for_str(deq, ft_atoi(num_list[i])))
		{
			free_list(num_list);
			return (1);
		}
		i++;
	}
	free_list(num_list);
	return (0);
}
