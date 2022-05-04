NAME := so_long

SRCS =  ./sources/so_long.c \
		./sources/get_next_line.c	\
		./sources/get_next_line_utils.c	\
		./sources/init_map.c \
		./sources/moves.c \
		./sources/drawing.c \
		./sources/checker.c

OBJS = ${SRCS:.c=.o}

INC_DIR := ./headers/
EXE_DIR = ./

CC := cc
CFLAGS := -Wall -Werror -Wextra
MV := mv -f
RM := rm -f

$(NAME): $(OBJS)
	$(CC) -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)

%.o: %.c
	$(CC)  $(CFLAGS) -c $< -I $(INC_DIR) -o $@ 

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
