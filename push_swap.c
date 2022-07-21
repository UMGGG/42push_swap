/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:45:13 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/22 04:22:24 by jaeyjeon         ###   ########.fr       */
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

	if (check_argv(argc, argv))
		return (0);
	deq_a = make_deque();
	deq_b = make_deque();
	if (add_in_deq(argc, argv, deq_a))
	{
		free_all(deq_a);
		return (0);
	}
	free_all(deq_b);
	free_all(deq_a);
	return (0);
}
