NAME = pipex

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRCS =	mandatory/pipex.c				\
		mandatory/error.c				\
		mandatory/pipex_utils.c			\
		fonctions/ft_putstr_fd.c		\
		fonctions/ft_strlen.c			\
		fonctions/ft_split.c			\
		fonctions/ft_strjoin.c			\
		fonctions/ft_strncmp.c			\
		fonctions/ft_split_up.c			\
		gnl/get_next_line.c				\
		gnl/get_next_line_utils.c		\

BSRCS =	bonus/pipex_bonus.c				\
		bonus/pipex_utils_bonus.c		\
		gnl/get_next_line.c				\
		gnl/get_next_line_utils.c		\
		mandatory/error.c				\
		mandatory/pipex_utils.c			\
		fonctions/ft_putstr_fd.c		\
		fonctions/ft_strlen.c			\
		fonctions/ft_split.c			\
		fonctions/ft_strjoin.c			\
		fonctions/ft_strncmp.c			\
		fonctions/ft_split_up.c			\

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

%.o:%.c includes/pipex.h Makefile includes/pipex_bonus.h gnl/get_next_line.h
	cc $(CFLAGS) -c $< -o $@

bonus: $(BOBJS)
	cc $(CFLAGS) $(BOBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re