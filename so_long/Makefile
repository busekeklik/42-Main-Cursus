# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkeklik <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/11 14:57:55 by bkeklik           #+#    #+#              #
#    Updated: 2022/09/11 14:57:58 by bkeklik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = main.c map.c valid_path.c free.c key_event.c

OBJS = $(SRCS:.c=.o)

CC = gcc

MFLAGS =  ./libft/libft.a ./mlx/libmlx.a ./ft_printf/libftprintf.a ./get_next_line/get_next_line.a

AFLAGS =  -Wall -Wextra -Werror -I ./mlx -I ./libft -I ./ft_printf -I ./get_next_line

RM = rm -rf

NAME = so_long

all :$(MFLAGS) $(NAME)

$(MFLAGS):
	make -C ./get_next_line
	make -C ./libft
	make -C ./ft_printf
	make -C ./mlx

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MFLAGS) $(CFLAGS) -framework OpenGL -framework AppKit -o $(NAME)

fclean : clean
	$(RM) ./libft/*.a
	$(RM) ./*.a
	$(RM) ./ft_printf/*.a
	$(RM) ./get_next_line/*.a
	$(RM) ./mlx/*.a
	$(RM) $(NAME)

clean :
	$(RM) ./libft/*.o
	$(RM) ./*.o
	$(RM) ./ft_printf/*.o
	$(RM) ./get_next_line/*.o
	$(RM) ./mlx/*.o
	$(RM) $(OBJS)

re : fclean all

.PHONY : all fclean clean re
