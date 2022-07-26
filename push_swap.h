/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:45:19 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/27 02:33:07 by jaeyjeon         ###   ########.fr       */
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
int		check_duplicate(t_deque	*deq, int num);
int		ft_atoi(const char *str);
int		return_error(char *str);
int		push_node_back(t_deque *deq, int num);
int		push_node_front(t_deque *deq, int num);
int		push_node_for_list(t_deque *deq, char *argv);
int		push_in_deq(int argc, char **argv, t_deque *deq);
int		pop_node_front(t_deque *deq);
int		pop_node_back(t_deque *deq);
int		do_s(t_deque *deq);
int		do_sa(t_deque *deq);
int		do_sb(t_deque *deq);
int		do_ss(t_deque *deq_a, t_deque *deq_b);
int		do_pa(t_deque *deq_a, t_deque *deq_b);
int		do_pb(t_deque *deq_a, t_deque *deq_b);
int		do_r(t_deque *deq);
int		do_ra(t_deque *deq_a);
int		do_rb(t_deque *deq_b);
int		do_rr(t_deque *deq_a, t_deque *deq_b);
int		do_brr(t_deque *deq);
int		do_rra(t_deque *deq_a);
int		do_rrb(t_deque *deq_b);
int		do_rrr(t_deque *deq_a, t_deque *deq_b);
int		start_sort(t_deque *deq_a, t_deque *deq_b);
int		free_all(t_deque *deq_a, t_deque *deq_b);
void	free_list(char	**list);
t_deque	*make_deque(void);

#endif
