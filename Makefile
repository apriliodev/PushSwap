SRC =	push_swap.c \
		helper/parsing.c \
		helper/stack.c \
		algorithms/disorder.c \
		algorithms/utils.c \
		algorithms/bubblesort.c \
		algorithms/chunkbased.c \
		algorithms/radix.c \
		algorithms/three.c \
		operations/swap.c \
		operations/push.c \
		operations/rotate.c \
		operations/rrotate.c

OBJS := $(SRC:%.c=%.o)

NAME = push_swap
CC = gcc
CCFLAGS = -Werror -Wall -Wextra
INC_DIR = .
LIBFT_DIR = libft
PRINTF_DIR = printf

%.o: %.c
	$(CC) -I$(INC_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR) $(CCFLAGS) -o $@ -c $<

all: libs $(NAME)

libs:
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all

clear: fclean
	clear

.PHONY: all clean fclean re clear libs