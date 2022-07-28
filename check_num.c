/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:22:22 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/29 03:51:11 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	return_error(int i)
{
	write(2, "Error\n", 6);
	if (i == 1)
		exit(0);
	return (1);
}

void	check_argv(int argc, char **argv)
{
	int		i;
	char	*str;

	i = 0;
	if (argc == 1)
		return_error(1);
	while (++i != argc)
	{
		str = argv[i];
		while (*str)
		{
			if (str[0] == ' ' && str[1] == '\0')
				return_error(1);
			if (*str == '-' || *str == '+' )
			{
				str++;
				if (*str < '0' || *str > '9')
					return_error(1);
			}
			else if (*str != ' ' && (*str < '0' || *str > '9'))
				return_error(1);
			if (*str)
				str++;
		}
	}
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
			return (return_error(0));
		curr = curr->next;
	}
	return (0);
}
