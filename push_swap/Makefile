RESET	=	\033[0m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
RED		=	\033[31m

NAME = push_swap

SRCS =  main.c rotate_swap_func.c rotate_rev_func.c push_func.c control_edit.c selection_sort.c three_five.c radix.c free.c ft_atoip.c
OBJS = $(SRCS:.c=.o)

CC = @gcc -ggdb
MFLAGS =  ./libft/libft.a
AFLAGS =  -Wall -Wextra -Werror ./libft 
CFLAGS =  -Wall -Wextra -Werror

RM = rm -rf


all :$(MFLAGS) $(NAME)

$(MFLAGS):
	@make -C ./libft

$(NAME): $(OBJS)
	@echo "$(YELLOW)>- 🦚Compiling...🦚 [$(NAME)] $(RESET)"
	@$(CC) $(OBJS) $(MFLAGS) $(CFLAGS) -o $(NAME)
	@echo "$(YELLOW)>-🦚🦚🦚🦚🦚🦚Finish..🦚🦚🦚🦚🦚🦚🦚 [$(NAME)] $(RESET)"

fclean : clean
	@echo "$(RED)>- 🦚🦚🦚🦚🦚Deleting...🦚🦚🦚🦚🦚 [$(NAME)] $(RESET)"
	@$(RM) ./libft/*.a
	@$(RM) ./*.a
	@$(RM) $(NAME)
	@echo "$(RED)>- 🦚🦚🦚finish🦚🦚 [$(NAME)] $(RESET)"

clean :
	@$(RM) ./libft/*.o
	@$(RM) ./*.o
	@$(RM) $(OBJS)

re : fclean all

.PHONY : all fclean clean re
