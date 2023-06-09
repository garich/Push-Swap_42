SRCS	=	main.c				\
			arguments.c			\
			list_node.c			\
			list_utils.c		\
			list_utils_more.c	\
			array_utils.c		\
			push_swap.c			\
			ps_rules.c			\
			ps_rules_more.c		\
			ps_utils.c			\
			ps_utils_more.c		\
			ps_algorithms.c		\
			ps_algorithms_more.c

OBJS	=	$(SRCS:.c=.o)

# BONUS_SRCS = checker.c		\
# 			 checker_utils.c	\
# 			 checker_rules.c

# BONUS_OBJS = $(BONUS_SRCS:.c=.o)

NAME	=	push_swap

# B_NAME	=	checker

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

all:	$(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I ./libft

$(NAME):	$(OBJS)
	@make -C ./libft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) libft/libft.a

# bonus: $(BONUS_OBJS)
# 	@make -C ./libft
# 	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(B_NAME) libft/libft.a

clean:
	@cd libft && make clean
	@$(RM) $(OBJS)

fclean: clean
	@cd libft && make fclean
	@$(RM) $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all clean fclean re