# Compiler and Linker
CC := cc

# Compiler flags
CFLAGS := -Wall -Wextra -Werror

# Directories
OBJDIR := obj
SRC_DIRS := ft_libft ft_printf ft_dlist ft_get_next_line

# Library name
NAME := libft.a

# Header files
HEADERS := ft_libft/libft.h ft_printf/ft_printf.h ft_dlist/ft_dlist.h ft_get_next_line/ft_get_next_line.h

# Source files structured by module
LIBFT_SRCS := ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
              ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
              ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
              ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
              ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
              ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
              ft_substr.c ft_tolower.c ft_toupper.c ft_striteri.c ft_dtoa.c \
              ft_strcspn.c ft_combine_numbers_fixed_width.c ft_strtod.c \
              ft_isspace.c ft_strcmp.c ft_is_str_digit.c ft_realloc.c ft_isnumber.c

PRINTF_SRCS := ft_printf.c ft_bools.c ft_handle_char.c ft_getters.c ft_dynamic_char_array.c \
               ft_estimate_size.c ft_handle_format.c ft_handle_string.c ft_handle_int.c \
               ft_handle_pointer.c ft_handle_hex.c ft_hex_helper.c ft_handle_percent.c \
               ft_int_helper.c

DLIST_SRCS := ft_dlist_edit.c ft_dlist_find.c ft_dlist_rotate.c ft_dlist_utils.c ft_dlist.c \
              ft_dlist_append_unique.c ft_dlist_sort.c ft_dlist_get.c

GNL_SRCS := ft_get_next_line.c

# Full list of source files
SRCS := $(LIBFT_SRCS) $(PRINTF_SRCS) $(DLIST_SRCS) $(GNL_SRCS)

# Define VPATH to locate source files
VPATH := ft_libft:ft_printf:ft_dlist:ft_get_next_line

# Object files
OBJS := $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

# Total number of objects (for progress bar)
TOTAL := $(words $(OBJS))
CURRENT := 0

# Colors
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[1;33m
NC := \033[0m # No Color

# Create obj directory and compile the library
all: start_build $(NAME)

start_build:
	@echo "$(YELLOW)Building library...$(NC)"

$(NAME): $(OBJS)
	@ar rcs $@ $^
	@echo "$(GREEN)Library built.$(NC)"

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@ >/dev/null 2>&1
	$(eval CURRENT=$(shell echo $$(($(CURRENT) + 1))))
	$(eval PERCENT=$(shell echo $$((100 * $(CURRENT) / $(TOTAL)))))
	$(eval HASHES=$(shell echo $$((50 * $(CURRENT) / $(TOTAL)))))
	$(eval SPACES=$(shell echo $$((50 - $(HASHES)))))
	@printf "\r$(YELLOW)Progress: [$(NC)%-50s$(YELLOW)] %2d%%$(NC)" $$(printf '%*s' $(HASHES) | tr ' ' '#')$$(printf '%*s' $(SPACES) ' ') $(PERCENT)
	@echo -n
	@if [ $(CURRENT) -eq $(TOTAL) ]; then echo ""; fi

# Clean rule
clean:
	@echo "$(RED)Cleaning objects...$(NC)"
	@rm -rf $(OBJDIR)
	@echo "$(RED)Objects cleaned.$(NC)"

# Clean and remove library rule
fclean: clean
	@echo "$(RED)Removing library...$(NC)"
	@rm -f $(NAME)
	@echo "$(RED)Library removed.$(NC)"

# Rebuild rule
re: fclean all

.PHONY: all clean fclean re start_build