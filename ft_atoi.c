/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:33:58 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/08/04 00:30:26 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_whitespace(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
	{
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	num;
	int			pm;

	num = 0;
	pm = 1;
	i = check_whitespace(str);
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			pm *= -1;
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			num *= 10;
			num += (int)(str[i] - 48);
		}
		else
			break ;
		i++;
	}
	if (num > INT_MAX || num < INT_MIN)
		return_error(1);
	return (pm * num);
}
