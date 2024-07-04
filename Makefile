# Compiler and Linker
CC := cc

# Compiler flags
CFLAGS := -Wall -Wextra -Werror

# Base source directory
BASE_SRC_DIR := src

# Directories
OBJDIR := obj
SRC_DIRS := $(BASE_SRC_DIR)/ft_libft $(BASE_SRC_DIR)/ft_printf $(BASE_SRC_DIR)/ft_dlist $(BASE_SRC_DIR)/ft_get_next_line $(BASE_SRC_DIR)/ft_vector/2d

# Library name
NAME := libft.a

# Header files
HEADERS := $(BASE_SRC_DIR)/ft_libft/libft.h $(BASE_SRC_DIR)/ft_printf/ft_printf.h $(BASE_SRC_DIR)/ft_dlist/ft_dlist.h $(BASE_SRC_DIR)/ft_get_next_line/ft_get_next_line.h include/lib.h $(BASE_SRC_DIR)/ft_vector/2d/ft_vector_2d.h

# Source files structured by module
LIBFT_SRCS := ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
              ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
              ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
              ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
              ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
              ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
              ft_substr.c ft_tolower.c ft_toupper.c ft_striteri.c ft_dtoa.c \
              ft_strcspn.c ft_combine_numbers_fixed_width.c ft_strtod.c \
              ft_isspace.c ft_strcmp.c ft_is_str_digit.c ft_realloc.c ft_isnumber.c \
              ft_contains_only.c ft_contains.c ft_strjoin_in_place.c ft_strjoin_better.c \
              ft_strrncmp.c ft_strtrim_in_place.c ft_free_arr.c ft_strdup_2d.c \

PRINTF_SRCS := ft_printf.c ft_bools.c ft_handle_char.c ft_getters.c ft_dynamic_char_array.c \
               ft_estimate_size.c ft_handle_format.c ft_handle_string.c ft_handle_int.c \
               ft_handle_pointer.c ft_handle_hex.c ft_hex_helper.c ft_handle_percent.c \
               ft_int_helper.c

DLIST_SRCS := ft_dlist_edit.c ft_dlist_find.c ft_dlist_rotate.c ft_dlist_utils.c ft_dlist.c \
              ft_dlist_append_unique.c ft_dlist_sort.c ft_dlist_get.c

VECT_SRCS := ft_vector_2d_utils.c ft_vector_2d.c

GNL_SRCS := ft_get_next_line.c

# Full list of source files
SRCS := $(LIBFT_SRCS) $(PRINTF_SRCS) $(DLIST_SRCS) $(GNL_SRCS) $(VECT_SRCS)

# Define vpath to locate source files
vpath %.c $(SRC_DIRS)

# Object files
OBJS := $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

# Total number of objects (for progress bar)
TOTAL := $(words $(OBJS))
CURRENT := 0

# Colors
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
NC := \033[0m # No Color

# Create obj directory and compile the library
all: start_build $(NAME)

start_build:
	@if [ -n "`find $(SRC_DIRS) -name '*.c' -newer $(NAME) 2>/dev/null`" ] || [ ! -f "$(NAME)" ]; then \
		printf "$(YELLOW)Building library...$(NC)\n"; \
	else \
		printf "$(GREEN)Library is up to date. Nothing to build.$(NC)\n"; \
	fi

$(NAME): $(OBJS)
	@ar rcs $@ $^
	@printf "$(GREEN)Library built.$(NC)\n"

$(OBJDIR)/%.o: %.c $(HEADERS)
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
	@printf "$(RED)Cleaning objects...$(NC)\n"
	@rm -rf $(OBJDIR)
	@printf "$(RED)Objects cleaned.$(NC)\n"

# Clean and remove library rule
fclean: clean
	@printf "$(RED)Removing library...$(NC)\n"
	@rm -f $(NAME)
	@printf "$(RED)Library removed.$(NC)\n"

# Rebuild rule
re: fclean all

.PHONY: all clean fclean re start_build
