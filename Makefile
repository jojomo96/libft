# Compiler
CC := cc

# Compiler flags
CFLAGS := -Wall -Wextra -Werror

# Directories
OBJDIR := obj

# Library name
NAME := libft.a

HEADERS := libft.h ft_printf/ft_printf.h ft_dlist/ft_dlist.h

# Source files
SRCS := ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_striteri.c \
		ft_dtoa.c \
		ft_strcspn.c \
		ft_combine_numbers_fixed_width.c \
		ft_strtod.c \
		ft_isspace.c \
		ft_strcmp.c \
		ft_is_str_digit.c \
		ft_realloc.c \
		ft_printf/ft_printf.c \
		ft_printf/ft_bools.c \
		ft_printf/ft_handle_char.c \
		ft_printf/ft_getters.c \
		ft_printf/ft_dynamic_char_array.c \
		ft_printf/ft_estimate_size.c \
		ft_printf/ft_handle_format.c \
		ft_printf/ft_handle_string.c \
		ft_printf/ft_handle_int.c \
		ft_printf/ft_handle_pointer.c \
		ft_printf/ft_handle_hex.c \
		ft_printf/ft_hex_helper.c \
		ft_printf/ft_handle_percent.c \
		ft_printf/ft_int_helper.c \
		ft_dlist/ft_dlist_edit.c \
		ft_dlist/ft_dlist_find.c \
		ft_dlist/ft_dlist_rotate.c \
		ft_dlist/ft_dlist_utils.c \
		ft_dlist/ft_dlist.c \
		ft_dlist/ft_dlist_test.c



# Object files (adjusted for obj directory)
OBJS := $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

# Create obj directory and compile the library
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

$(OBJDIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule (adjusted for obj directory)
clean:
	rm -rf $(OBJDIR)

# Clean and remove library rule
fclean: clean
	rm -f $(NAME)

# Rebuild rule
re: fclean all

.PHONY: all clean fclean re bonus
