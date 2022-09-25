# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkeklik <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 13:41:11 by bkeklik           #+#    #+#              #
#    Updated: 2022/07/05 07:14:54 by bkeklik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all :  ${NAME}

$(NAME) : ${OBJS}
	ar rc $(NAME) $(OBJS)

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all
.PHONY:		all clean fclean re