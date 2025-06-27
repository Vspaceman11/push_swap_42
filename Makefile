# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/26 18:09:59 by vpushkar          #+#    #+#              #
#    Updated: 2025/06/27 14:39:03 by vpushkar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==== Project Name ====
NAME = push_swap
BONUS = checker

# ==== Compiler Settings ====
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# ==== Directories ====
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

# ==== Libft ====
LIBFT_DIR = libft_extended
LIBFT_REPO = https://github.com/Vspaceman11/libft_extended.git
LIBFT_A = $(LIBFT_DIR)/libft_extended.a

# ==== Source and Object Files ====

SRCS = $(filter-out $(SRC_DIR)/checker.c, $(wildcard $(SRC_DIR)/*.c))
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# ==== Bonus only checker ====
BONUS_OBJ = $(OBJ_DIR)/checker.o

# ==== Tools ====
RM = rm -f
MKDIR = mkdir -p

# ==== Colored Messages ====
YELLOW = \033[1;33m
GREEN  = \033[1;32m
RED    = \033[1;31m
BLUE   = \033[1;34m
RESET  = \033[0m

# ==== Targets ====

all: $(LIBFT_A) $(NAME)
	@echo "$(GREEN)✓ Build complete: $(NAME)$(RESET)"

bonus: $(LIBFT_A) $(BONUS)
	@echo "$(GREEN)✓ Build complete: $(BONUS) (bonus)$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)→ Compiling $<$(RESET)"
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR)/inc -c $< -o $@

$(OBJ_DIR):
	@$(MKDIR) $(OBJ_DIR)

$(NAME): $(OBJS)
	@echo "$(YELLOW)→ Linking $(NAME)$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft_extended -o $@

# ==== Bonus ====
BONUS_DEPS = $(filter-out $(OBJ_DIR)/push_swap.o, $(OBJS))

$(BONUS): $(BONUS_OBJ) $(BONUS_DEPS)
	@echo "$(YELLOW)→ Linking $(BONUS)$(RESET)"
	@$(CC) $(CFLAGS) $^ -L$(LIBFT_DIR) -lft_extended -o $(BONUS)
# ==== Libft ====
$(LIBFT_A):
	@echo "$(BLUE)→ Checking libft...$(RESET)"
	@test -d $(LIBFT_DIR) || git clone --depth=1 $(LIBFT_REPO) $(LIBFT_DIR)
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null
	@echo "$(GREEN)✓ libft ready$(RESET)"

# ==== Cleanup ====
clean:
	@echo "$(RED)✗ Cleaning object files...$(RESET)"
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null || true

fclean: clean
	@echo "$(RED)✗ Removing binaries: $(NAME) and $(BONUS)$(RESET)"
	@$(RM) $(NAME) $(BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null || true
	@if [ "$(REMOVE_LIBFT)" = "1" ]; then rm -rf $(LIBFT_DIR); fi

re: fclean all

.PHONY: all clean fclean re bonus
