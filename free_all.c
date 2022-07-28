/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 03:34:18 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/29 03:03:33 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_all(t_deque *deq_a, t_deque *deq_b, t_deque *deq_str)
{
	free_deq(deq_a);
	free_deq(deq_b);
	free_deq(deq_str);
	exit(0);
	return (0);
}

int	free_deq(t_deque *deq)
{
	t_node	*curr;
	t_node	*save;

	curr = deq->last;
	while (curr != deq->first)
	{
		save = curr->prev;
		free(curr);
		curr = save;
	}
	free (curr);
	free (deq);
	return (0);
}

void	free_list(char	**list)
{
	int	i;

	i = 0;
	while (list[i] != NULL)
	{
		free (list[i]);
		i++;
	}
	free (list[i]);
	free (list);
}
