/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_deque.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 04:00:41 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/25 17:23:09 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_deque	*make_deque(void)
{
	t_deque	*new_deque;

	new_deque = malloc(sizeof(t_deque));
	new_deque->first = NULL;
	new_deque->last = NULL;
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
			if (push_node_back(deq, ft_atoi(argv[i])))
				return (1);
		}
		i++;
	}
	return (0);
}
