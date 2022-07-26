/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:45:13 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/26 21:17:50 by jaeyjeon         ###   ########.fr       */
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
	t_deque	*deq_b;
	t_node	*curr;

	atexit(ls);
	deq_a = make_deque();
	deq_b = make_deque();
	if (check_argv(argc, argv))
		return (0);
	if (push_in_deq(argc, argv, deq_a))
		return (free_all(deq_a, deq_b));
	pop_node_front(deq_a);
	pop_node_back(deq_a);
	do_sa(deq_a);
	curr = deq_a->first;
	while (curr)
	{
		ft_printf("%d\n", curr->num);
		curr = curr->next;
	}
	// start_sort(deq_a, deq_b);
	return (free_all(deq_a, deq_b));
}
