NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

PROGRAMME = test_printf
LIBFT_DIR = libft

AR = ar
ARFLAGS = rcs
SRC = ft_printf.c ft_i_or_d.c ft_letter.c ft_lowercase_hexadecimal.c ft_pointer.c ft_sentence.c ft_unsigned_int.c ft_uppercase_hexadecimal.c
OBJ = $(SRC:.c=.o)

LIBFT_SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
ft_substr.c ft_tolower.c ft_toupper.c

LIBFT_OBJ = $(LIBFT_SRC:%.c=$(LIBFT_DIR)/%.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ) $(LIBFT_OBJ)

test: $(NAME)
	$(CC) $(CFLAGS) $(OBJ) libftprintf.a -o $(PROGRAMME)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(PROGRAMME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re test