NAME = pipex.a

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRCS =	mandatory/pipex.c	\
		gnl/get_next_line.c	\
		gnl/get_next_line_utils.c	\

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o:%.c includes/pipex.h Makefile
	cc $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re