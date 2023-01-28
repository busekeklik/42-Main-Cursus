NAME = minitalk
SRCLIENT =   client.c
OBJSCLIENT = $(SRCLIENT:.c=.o)

SRCSERVER = server.c
OBJSERVER = $(SRCSERVER:.c=.o)

SRCBONUSSERVER = server_bonus.c
OBJBONUSSERVER = $(SRCBONUSSERVER:.c=.o)

SRCBONUSCLIENT = client_bonus.c
OBJBONUSCLIENT = $(SRCBONUSCLIENT:.c=.o)

CFLAGS = -Wall -Wextra -Werror
LIB = ./ft_printf/libftprintf.a 

all: $(NAME)

$(NAME): $(OBJSERVER) $(OBJSCLIENT)
	@make -C ./ft_printf
	@gcc -o server $(SRCSERVER) $(CFLAGS) $(LIB)
	@gcc -o client $(SRCLIENT) $(CFLAGS) $(LIB)

bonus: $(OBJBONUSSERVER) $(OBJBONUSCLIENT)
	@make -C ./ft_printf
	@gcc -o client_bonus $(SRCBONUSCLIENT) $(CFLAGS) $(LIB)
	@gcc -o server_bonus $(SRCBONUSSERVER) $(CFLAGS) $(LIB)

clean:
	rm -f $(OBJSERVER) $(OBJSCLIENT) $(OBJBONUSSERVER) $(OBJBONUSCLIENT)
	rm -f ./ft_printf/*.o

fclean: clean
	rm -f server client server_bonus client_bonus
	rm -f ./ft_printf/*.o ./ft_printf/*.a

re: fclean all

.PHONY: all clean fclean re bonus