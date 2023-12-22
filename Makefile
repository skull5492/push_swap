NAME = push_swap

CC = cc

FLAGS = -Wall -Werror -Wextra -fsanitize=address

SRC = srcs/operations/*.c\
		   srcs/sorting/*.c \
		   srcs/utils/*.c \
		   srcs/main.c

$(NAME):
		$(CC) $(FLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean: 
		@rm -rf sources/*.o
		@rm -rf sources/operations/*.o
		@rm -rf sources/sorting/*.o
		@rm -rf sources/utils/*.o

fclean : clean
			@rm -rf $(NAME)

re: fclean all