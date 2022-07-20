/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:45:19 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/21 02:46:47 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <fcntl.h>
# include "inc/ft_printf/ft_printf.h"

typedef struct s_node
{
	int				num;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_deque
{
	t_node	*first;
	t_node	*last;
}	t_deque;

int		check_argv(int argc, char **argv);
int		check_whitespace(const char *str);
int		ft_atoi(const char *str);
int		return_error(char *str);
t_node	*add_node(t_deque *deq, int num);
t_deque	*make_deque(void);

#endif
