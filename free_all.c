/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 03:34:18 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/22 03:46:23 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_deque *deq)
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
