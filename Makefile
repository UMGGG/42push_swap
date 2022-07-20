# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 21:48:48 by jaeyjeon          #+#    #+#              #
#    Updated: 2022/07/21 02:34:56 by jaeyjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
ar			= ar rcs

RM			= rm -rf

INC_DIR		= ./inc/ft_printf

SRCS		= push_swap.c ft_atoi.c check_num.c make_node.c

OBJS		=	$(SRCS:.c=.o)

%.o : %.c
		${CC} ${CFLAGS} -c -o $@ $<

$(NAME):	$(OBJS)
			make -C $(INC_DIR)
			$(CC) -o $(NAME) $(OBJS) -L $(INC_DIR) -lftprintf

all: 		$(NAME)

clean:
			make -C $(INC_DIR) clean
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			clean all

PHONY:		all clean fclean re
