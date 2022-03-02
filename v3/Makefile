CC = gcc
CCFLAGS = -Wall -Wextra -g

NAME = get_next_line
SRC = get_next_line.c get_next_line_utils.c main.c
OBJ = $(SRC:.c=.o)
INCLUDE = get_next_line.h

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(CC) $(CCFLAGS) -o $(NAME) $(OBJ)

%.o: %.c $(INCLUDE)
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all