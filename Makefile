NAME = push_swap

CC = cc

FLAGS = -Wall -Werror -Wextra -fsanitize=address

SRC = srcs/operations/*.c\
		   srcs/sorting/*.c \
		   srcs/utils/*.c \
		   srcs/main.c

$(NAME): $(SRC)
		$(CC) $(FLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean: 
		@rm -rf srcs/*.o
		@rm -rf srcs/operations/*.o
		@rm -rf srcs/sorting/*.o
		@rm -rf srcs/utils/*.o

fclean : clean
			@rm -rf $(NAME)

re: fclean all