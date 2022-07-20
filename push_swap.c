/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:45:13 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/21 02:41:18 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_deque	*deq_a;
	t_deque	*deq_b;
	t_node	*currnode;

	if (check_argv(argc, argv))
		return (0);
	deq_a = make_deque();
	deq_b = make_deque();
	printf("%s  %s  %s  \n", argv[1], argv[2], argv[3]);
	add_node(deq_a, ft_atoi(argv[1]));
	add_node(deq_b, 0);
	currnode = deq_a->first;
	add_node(deq_a, ft_atoi(argv[2]));
	add_node(deq_a, ft_atoi(argv[3]));
	ft_printf("%d\n", currnode->num);
	currnode = currnode->next;
	ft_printf("%d\n", currnode->num);
	currnode = currnode->next;
	ft_printf("%d\n", currnode->num);
	currnode = currnode->next;
}
