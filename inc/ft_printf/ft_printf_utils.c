/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 01:14:22 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/04/22 01:59:27 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_countnum(long n)
{
	long	num;
	int		i;

	num = n;
	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		num *= -1;
	}
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_ltoa(unsigned int n)
{
	char			*str;
	unsigned int	num;
	int				i;

	num = n;
	i = ft_countnum(n) - 1;
	str = (char *)malloc(sizeof(char) * (ft_countnum(n) + 1));
	if (str == 0)
		return (0);
	str[ft_countnum(n)] = '\0';
	while (i >= 0)
	{
		str[i] = (num % 10) + 48;
		num = num / 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		i;

	num = (long)n;
	i = ft_countnum(num) - 1;
	str = (char *)malloc(sizeof(char) * (ft_countnum(num) + 1));
	if (str == 0)
		return (NULL);
	if (n == -2147483648)
		num = 2147483648;
	else if (num < 0)
		num *= -1;
	str[ft_countnum(n)] = '\0';
	while (i >= 0)
	{
		str[i] = (num % 10) + 48;
		num = num / 10;
		i--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
