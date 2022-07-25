/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 03:34:18 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/25 17:05:07 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_all(t_deque *deq_a, t_deque *deq_b)
{
	t_node	*curr;
	t_node	*save;

	curr = deq_a->last;
	while (curr != deq_a->first)
	{
		save = curr->prev;
		free(curr);
		curr = save;
	}
	free (curr);
	curr = deq_b->last;
	while (curr != deq_b->first)
	{
		save = curr->prev;
		free(curr);
		curr = save;
	}
	free (curr);
	free (deq_a);
	free (deq_b);
	exit(0);
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
