/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:44:42 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/04/26 18:30:02 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_print_bx(va_list **a)
{
	unsigned int	vatemp;
	int				i;
	ssize_t			print_size;
	char			*str;

	i = 0;
	print_size = 0;
	vatemp = (unsigned int)va_arg(**a, unsigned int);
	if (vatemp == 0)
		return (write(1, "0", 1));
	str = ft_change_hexa((long long)vatemp, 1);
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] -= 32;
		i++;
	}
	print_size = write(1, str, ft_strlen(str));
	free(str);
	return (print_size);
}
