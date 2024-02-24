NAME = pipex

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRCS =	mandatory/pipex.c			\
		mandatory/error.c			\
		fonctions/ft_putchar_fd.c	\
		fonctions/ft_putstr_fd.c	\
		fonctions/ft_strlen.c		\
		#gnl/get_next_line.c		\
		#gnl/get_next_line_utils.c	\

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

%.o:%.c includes/pipex.h Makefile
	cc $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re