SRCS	=	main.c				\
			arguments.c			\
			push_swap.c			\
			list_utils.c		\
			list_utils_more.c	\
			array_utils.c		\
			ps_rules.c			\
			push_swap_utils.c

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

py2: all
	python3 pythonvisualizer.py `ruby -e "puts (-1..0).to_a.shuffle.join(' ')"`

py3: all
	python3 pythonvisualizer.py `ruby -e "puts (-1..1).to_a.shuffle.join(' ')"`

py5: all
	python3 pythonvisualizer.py `ruby -e "puts (-2..2).to_a.shuffle.join(' ')"`

py100: all
	python3 pythonvisualizer.py `ruby -e "puts (-50..50).to_a.shuffle.join(' ')"`

py200: all
	python3 pythonvisualizer.py `ruby -e "puts (-100..100).to_a.shuffle.join(' ')"`

py500: all
	python3 pythonvisualizer.py `ruby -e "puts (-250..250).to_a.shuffle.join(' ')"`

.PHONY: all clean fclean re