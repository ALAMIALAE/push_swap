CC = cc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -rf
NAME = push_swap
NAME_BONUS = checker

SRCS = push_swap.c ft_split.c push.c \
	rotate.c swap.c reverse_rotate.c sort.c sort_utils.c \
	algo.c algo_utils.c parse.c parsing_utils.c 

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
