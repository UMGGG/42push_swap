/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:45:13 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/08/16 02:38:31 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_deque	*deq_a;
	t_deque	*deq_b;
	t_deque	*deq_str;

	deq_a = make_deque();
	deq_b = make_deque();
	deq_str = make_deque();
	check_argv(argc, argv);
	if (push_in_deq(argc, argv, deq_a))
		return (free_all(deq_a, deq_b, deq_str));
	start_sort(deq_a, deq_b, deq_str);
	opt_str(deq_str);
	print_deq(deq_str);
	return (free_all(deq_a, deq_b, deq_str));
}
