/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:22:22 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/22 04:08:49 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	return_error(char *str)
{
	ft_printf("%s\n", str);
	return (1);
}

int	check_argv(int argc, char **argv)
{
	int		i;
	char	*str;

	i = 1;
	if (argc == 1)
		return (return_error("nothing turned in"));
	else if (argc == 2)
		return (1);
	while (i != argc)
	{
		str = argv[i];
		while (*str)
		{
			if (*str != ' ' && (*str < '0' || *str > '9'))
				return (return_error("not allowed data"));
			str++;
		}
		i++;
	}
	return (0);
}

int	check_str_num(char *argv)
{
	char	*str;

	str = argv;
	while (*str)
	{
		if (*str == ' ')
			return (1);
		str++;
	}
	return (0);
}

int	check_duplicate(t_deque	*deq, int num)
{
	t_node	*curr;

	curr = deq->first;
	while (curr != NULL)
	{
		if (curr->num == num)
			return (return_error("Duplicated numbers"));
		curr = curr->next;
	}
	return (0);
}
