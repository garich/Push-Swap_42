SRCS	=	main.c			\
			push_swap.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	push_swap

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

all:	$(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I ./libft

$(NAME):	$(OBJS)
	@make -C ./libft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) libft/libft.a

clean:
	@cd libft && make clean
	@$(RM) $(OBJS)

fclean: clean
	@cd libft && make fclean
	@$(RM) $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all clean fclean re