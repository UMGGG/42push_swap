# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 16:22:09 by jaeyjeon          #+#    #+#              #
#    Updated: 2022/04/22 02:40:31 by jaeyjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= gcc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror

SRCS		= ft_printf.c ft_printf_utils.c  ft_printf_utils2.c ft_print_c.c \
			ft_print_d.c ft_print_i.c ft_print_p.c ft_print_s.c \
			ft_print_u.c ft_print_bx.c ft_print_sx.c

OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

%.o : %.c
		${CC} ${CFLAGS} -c -o $@ $<

$(NAME):	$(OBJS)
				ar crs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)
				$(RM) ft_printf.h.gch

re:			fclean $(NAME)

.PHONY:		all clean fclean re
