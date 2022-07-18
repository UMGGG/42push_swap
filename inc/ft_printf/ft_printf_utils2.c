/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:57:08 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/04/22 15:09:50 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_change_hexa(long long num, int i)
{
	char			*hexalist;
	char			*str;
	long long		leftnum;
	int				size;

	leftnum = ft_givenum(num, i);
	size = 0;
	hexalist = "0123456789abcdef";
	while (leftnum != 0)
	{
		leftnum = leftnum / 16;
		size++;
	}
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	str[size--] = '\0';
	leftnum = ft_givenum(num, i);
	while (size > 0)
	{
		str[size--] = hexalist[(leftnum % 16)];
		leftnum = leftnum / 16;
	}
	str[size] = hexalist[leftnum];
	return (str);
}

char	*ft_change_hexa_address(unsigned long num)
{
	char			*hexalist;
	char			*str;
	unsigned long	leftnum;
	int				size;

	leftnum = ft_givenum_address(num);
	size = 0;
	hexalist = "0123456789abcdef";
	while (leftnum != 0)
	{
		leftnum = leftnum / 16;
		size++;
	}
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	str[size--] = '\0';
	leftnum = ft_givenum_address(num);
	while (size > 0)
	{
		str[size--] = hexalist[(leftnum % 16)];
		leftnum = leftnum / 16;
	}
	str[size] = hexalist[leftnum];
	return (str);
}

long long	ft_givenum(long long num, int i)
{
	unsigned int	finalnum;

	if (num < 0 && i == 1)
		return (finalnum = UINT_MAX + 1 + num);
	else
		return (num);
}

unsigned long	ft_givenum_address(unsigned long num)
{
	unsigned long	finalnumaddress;

	if (num < 0)
		return (finalnumaddress = ULONG_MAX + 1 + num);
	else
		return (num);
}
