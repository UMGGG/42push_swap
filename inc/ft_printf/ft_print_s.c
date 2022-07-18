/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:34:38 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/04/22 02:56:19 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_print_s(va_list **a)
{
	char	*vatemp;
	ssize_t	print_size;

	print_size = 0;
	vatemp = (char *)va_arg(**a, char *);
	if (vatemp == NULL)
		vatemp = "(null)";
	print_size = write (1, vatemp, ft_strlen(vatemp));
	return (print_size);
}
