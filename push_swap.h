/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:45:19 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/22 03:46:54 by jaeyjeon         ###   ########.fr       */
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

char	*ft_strndup(const char *s, size_t n);
char	**ft_freeall(char **list);
char	**ft_split(char const *s, char c);
size_t	ft_wordcount(char const *s, char c);
int		check_argv(int argc, char **argv);
int		check_str_num(char *argv);
int		check_whitespace(const char *str);
int		ft_atoi(const char *str);
int		return_error(char *str);
int		add_node(t_deque *deq, int num);
int		add_node_list(t_deque *deq, char *argv);
int		add_in_deq(int argc, char **argv, t_deque *deq);
t_deque	*make_deque(void);
void	free_all(t_deque *deq);
void	free_list(char	**list);

#endif
