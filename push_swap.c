/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:45:13 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/28 16:35:18 by jaeyjeon         ###   ########.fr       */
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
	start_sort(deq_a, deq_b);
	if (is_sorted(deq_a) == 1)
		ft_printf("GOOD!\n");
	return (free_all(deq_a, deq_b));
}
