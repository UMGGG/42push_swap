/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:45:13 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/18 22:13:49 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_argv(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9' )
			return (1);
		str++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
	{
		ft_printf("nothing turned in!!\n");
		return (0);
	}
	while (i != argc)
	{
		ft_printf("check %s\n", argv[i]);
		if (check_argv(argv[i]))
			return (0);
		i++;
	}
	ft_printf("good\n");
}
