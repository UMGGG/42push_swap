/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:45:19 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/07/30 09:16:05 by jaeyjeon         ###   ########.fr       */
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
	int		size;
}	t_deque;

/*atoi&split*/
char	*ft_strndup(const char *s, size_t n);
char	**ft_freeall(char **list);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
int		check_whitespace(const char *str);
size_t	ft_wordcount(char const *s, char c);
/*print*/
char	*print_command(int num);
int		print_deq(t_deque *deq);
int		return_error(int i);
/*checknum*/
int		is_sorted(t_deque *deq);
int		check_str_num(char *argv);
int		check_duplicate(t_deque	*deq, int num);
int		check_1_str(char *str);
void	check_argv(int argc, char **argv);
/*push&pop*/
int		push_node_back(t_deque *deq, int num);
int		push_node_front(t_deque *deq, int num);
int		push_node_for_list(t_deque *deq, char *argv);
int		push_node_back_for_str(t_deque *deq, int num);
int		push_in_deq(int argc, char **argv, t_deque *deq);
int		pop_node_front(t_deque *deq);
int		pop_node_back(t_deque *deq);
t_deque	*make_deque(void);
/* sorting func*/
int		do_s(t_deque *deq);
int		do_sa(t_deque *deq, t_deque *deq_str);
int		do_sb(t_deque *deq, t_deque *deq_str);
int		do_ss(t_deque *deq_a, t_deque *deq_b, t_deque *deq_str);
int		do_pa(t_deque *deq_a, t_deque *deq_b, t_deque *deq_str);
int		do_pb(t_deque *deq_a, t_deque *deq_b, t_deque *deq_str);
int		do_r(t_deque *deq);
int		do_ra(t_deque *deq_a, t_deque *deq_str);
int		do_rb(t_deque *deq_b, t_deque *deq_str);
int		do_rr(t_deque *deq_a, t_deque *deq_b, t_deque *deq_str);
int		do_brr(t_deque *deq);
int		do_rra(t_deque *deq_a, t_deque *deq_str);
int		do_rrb(t_deque *deq_b, t_deque *deq_str);
int		do_rrr(t_deque *deq_a, t_deque *deq_b, t_deque *deq_str);
/*sort*/
int		start_sort(t_deque *deq_a, t_deque *deq_b, t_deque *deq_str);
int		sort_3(t_deque *deq, t_deque *deq_str);
int		sort_4(t_deque *deq_a, t_deque *deq_b, t_deque *deq_str);
int		sort_5(t_deque *deq_a, t_deque *deq_b, t_deque *deq_str);
int		find_mid(t_deque *deq);
/*free data*/
int		free_all(t_deque *deq_a, t_deque *deq_b, t_deque *deq_str);
int		free_deq(t_deque *deq);
void	free_list(char	**list);
/*qucik sort*/
void	quicksort(int arr[], int l, int r);
int		partition(int arr[], int l, int r);
int		*getarr(t_deque *deq, int r);
int		get_pivot(t_deque *deq, int r);
/*sort deque*/
void	atob(t_deque *deq_a, t_deque *deq_b, t_deque *deq_str, int r);
void	btoa(t_deque *deq_a, t_deque *deq_b, t_deque *deq_str, int r);
void	opt_str(t_deque *deq);
/*optimized*/
void	next_command(t_deque *deq);
int		delete_command(t_deque *deq);
int		change_command(t_deque *deq, int num);

#endif
