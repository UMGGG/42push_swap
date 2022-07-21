/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:45:13 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/22 03:59:12 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ls(void)
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	t_deque	*deq_a;
	t_node	*curr;

	if (check_argv(argc, argv))
		return (0);
	deq_a = make_deque();
	if (add_in_deq(argc, argv, deq_a))
	{
		free_all(deq_a);
		return (0);
	}
	curr = deq_a->first;
	while (curr)
	{
		ft_printf("%d\n", curr->num);
		curr = curr->next;
	}
	free_all(deq_a);
	return (0);
}
