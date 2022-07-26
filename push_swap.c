/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:45:13 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/27 02:49:00 by jaeyjeon         ###   ########.fr       */
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
	t_node	*curr2;

	deq_a = make_deque();
	deq_b = make_deque();
	if (check_argv(argc, argv))
		return (0);
	if (push_in_deq(argc, argv, deq_a))
		return (free_all(deq_a, deq_b));
	do_sa(deq_a);
	do_pb(deq_a, deq_b);
	do_pb(deq_a, deq_b);
	do_pb(deq_a, deq_b);
	do_ra(deq_a);
	do_rb(deq_b);
	do_rra(deq_a);
	do_rrb(deq_b);
	do_sa(deq_a);
	do_pa(deq_a, deq_b);
	do_pa(deq_a, deq_b);
	do_pa(deq_a, deq_b);
	curr = deq_a->first;
	while (curr)
	{
		ft_printf("%d\n", curr->num);
		curr = curr->next;
	}
	ft_printf("-b-\n");
	curr2 = deq_b->first;
	while (curr2)
	{
		ft_printf("%d\n", curr2->num);
		curr2 = curr2->next;
	}
	// start_sort(deq_a, deq_b);
	return (free_all(deq_a, deq_b));
}
