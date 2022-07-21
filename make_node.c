/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 01:54:32 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/22 03:46:44 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_node(t_deque *deq, int num)
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

t_deque	*make_deque(void)
{
	t_deque	*new_deque;

	new_deque = malloc(sizeof(t_deque));
	new_deque->first = NULL;
	new_deque->last = NULL;
	return (new_deque);
}

int	add_in_deq(int argc, char **argv, t_deque *deq)
{
	int		i;

	i = 1;
	while (i != argc)
	{
		if (check_str_num(argv[i]))
		{
			if (add_node_list(deq, argv[i]))
				return (1);
		}
		else
		{
			if (add_node(deq, ft_atoi(argv[i])))
				return (1);
		}
		i++;
	}
	return (0);
}
