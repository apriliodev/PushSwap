SRC = ft_printf.c
SRC_ARG = $(addprefix arguments/, printf_c.c printf_d.c printf_p.c printf_s.c printf_u.c printf_x.c)

OBJS := $(SRC:%.c=%.o)
OBJS_ARG := $(SRC_ARG:%.c=%.o)

NAME = libftprintf.a
CC = gcc
CCFLAGS = -Werror -Wall -Wextra
INC_DIR = .

%.o: %.c
	$(CC) -I$(INC_DIR) $(CCFLAGS) -o $@ -c $?

all: $(NAME)

$(NAME): $(OBJS)  $(OBJS_ARG)
	ar rcs $(NAME) $(OBJS)  $(OBJS_ARG)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)  $(OBJS_ARG)

fclean: clean
	rm -f $(NAME)

re: fclean all

clear: fclean 
	clear

test: all
	gcc $(CCFLAGS) -I. -L. -lftprintf test.c