/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:45:13 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/27 03:10:59 by jaeyjeon         ###   ########.fr       */
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

	deq_a = make_deque();
	deq_b = make_deque();
	if (check_argv(argc, argv))
		return (0);
	if (push_in_deq(argc, argv, deq_a))
		return (free_all(deq_a, deq_b));
	do_sa(deq_a);
	do_pb(deq_a, deq_b);
	do_pb(deq_a, deq_b);
	do_ra(deq_a);
	do_rb(deq_b);
	do_rra(deq_a);
	do_sa(deq_a);
	do_pa(deq_a, deq_b);
	do_pa(deq_a, deq_b);
	print_deq(deq_a);
	ft_printf("-b-\n");
	print_deq(deq_b);
	is_sorted(deq_a);
	// start_sort(deq_a, deq_b);
	return (free_all(deq_a, deq_b));
}
