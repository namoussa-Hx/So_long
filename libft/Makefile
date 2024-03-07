SRC = ft_bzero.c\
	  	ft_strchr.c ft_strlen.c ft_strcmp.c  ft_strdup.c \
		ft_putstr_fd.c  ft_putnbr_fd.c ft_itoa.c ft_putchar_fd.c
 
OBJ =$(SRC:.c=.o)
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)


$(NAME): $(OBJ)
		ar -rc $(NAME) $(OBJ)

.o: .c
	$(CC) $(CFLAGS) -c $@

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f  $(NAME)

re : fclean all

.PHONY : all clean fclean re NAME
