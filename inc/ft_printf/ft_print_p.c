/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:45:25 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/04/25 19:47:48 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_print_p(va_list **a)
{
	size_t	vatemp;
	ssize_t	print_size;
	char	*str;

	print_size = 0;
	vatemp = (size_t)va_arg(**a, size_t);
	if (vatemp == 0)
		return (write(1, "0x0", 3));
	str = ft_change_hexa_address((size_t)vatemp);
	print_size = write(1, "0x", 2);
	if (print_size == -1)
		return (print_size);
	print_size = write(1, str, ft_strlen(str));
	if (print_size == -1)
		return (print_size);
	free(str);
	return (print_size + 2);
}
