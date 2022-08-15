# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 21:48:48 by jaeyjeon          #+#    #+#              #
#    Updated: 2022/08/12 15:37:37 by jaeyjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
BONUS_NAME	= checker

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
ar			= ar rcs

RM			= rm -rf

INC_DIR		= ./inc/ft_printf

SRCS		= push_swap.c ft_atoi.c check_num.c make_node.c ft_split.c free_all.c\
			make_deque.c data_sorting_s.c data_sorting_p.c data_sorting_r.c\
			data_sorting_rr.c check_sort.c sort_data.c quicksort.c sort_deq.c\
			opti_str.c opti_str2.c

SRCS_BONUS	= checker.c ft_atoi.c check_num.c make_node.c ft_split.c free_all.c\
			make_deque.c data_sorting_s.c data_sorting_p.c data_sorting_r.c\
			data_sorting_rr.c check_sort.c sort_data.c quicksort.c sort_deq.c\

OBJS		=	$(SRCS:.c=.o)

OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

%.o : %.c
		${CC} ${CFLAGS} -c -o $@ $<

$(NAME):	$(OBJS)
			make -C $(INC_DIR)
			$(CC) -o $(NAME) $(OBJS) -L $(INC_DIR) -lftprintf

all: 		$(NAME)

bonus:		$(OBJS_BONUS)
			make -C $(INC_DIR)
			$(CC) -o $(BONUS_NAME) $(OBJS_BONUS) -L $(INC_DIR) -lftprintf

clean:
			make -C $(INC_DIR) clean
			$(RM) $(OBJS)
			$(RM) $(OBJS_BONUS)

fclean:		clean
			make -C $(INC_DIR) fclean
			$(RM) $(NAME)
			$(RM) $(BONUS_NAME)

re:			clean all

PHONY:		all clean fclean re bonus
