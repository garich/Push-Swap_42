SRCS =	

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I ./libft

$(NAME) : $(OBJS)
	@make -C ./libft
	@cp ./libft/libft.a $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(NAME) created"
	@ranlib $(NAME)
	@echo "$(NAME) indexed"

clean :
	@cd libft && make clean
	@$(RM) $(OBJS)

fclean :
	@cd libft && make fclean
	@$(RM) $(OBJS)
	@$(RM) $(NAME)
	@echo "$(NAME) deleted"

re : fclean all

.PHONY: all clean fclean re