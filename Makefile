# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 14:34:27 by danpalac          #+#    #+#              #
#    Updated: 2024/10/17 12:24:29 by danpalac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==========COLOURS=============================================================#

# Basic Colors

BLACK       = \033[0;30m
RED         = \033[0;31m
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
BLUE        = \033[0;34m
MAGENTA     = \033[0;35m
CYAN        = \033[0;36m
WHITE       = \033[0;37m

# Bright Colors

BOLD_BLACK  = \033[1;30m
BOLD_RED    = \033[1;31m
BOLD_GREEN  = \033[1;32m
BOLD_YELLOW = \033[1;33m
BOLD_BLUE   = \033[1;34m
BOLD_MAGENTA= \033[1;35m
BOLD_CYAN   = \033[1;36m
BOLD_WHITE  = \033[1;37m

# Extended Colors (256 colors)
ORANGE      = \033[38;5;208m
WINE        = \033[38;5;88m
LIME        = \033[38;5;190m
TURQUOISE   = \033[38;5;38m
LIGHT_PINK  = \033[38;5;13m
DARK_GRAY   = \033[38;5;235m
LIGHT_RED   = \033[38;5;203m
LIGHT_BLUE  = \033[38;5;75m


# Reseteo de color
NO_COLOR    = \033[0m
DEF_COLOR   = \033[0;39m
CLEAR_LINE  = \033[2K
MOVE_UP     = \033[1A

#==========NAMES===============================================================#

NAME		:= minishell
LIBFT		:= $(LIBFT_DIR)libft.a

#==========DIRECTORIES=======================================================#

INC 			:= inc/
SRC_DIR 		:= src/
OBJ_DIR 		:= obj/
LIBFT_DIR		:= libft/
LIBFT_INC		:= $(LIBFT_DIR)inc/

#==========COMMANDS============================================================#

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -g3 -fsanitize=address
RM			:= rm -rf
AR			:= ar rcs
LIB			:= ranlib
MKDIR 		:= mkdir -p
LDFLAGS		:= -L$(LIBFT_DIR) -lft -lm -fsanitize=address
IFLAGS		:= -I$(INC) -I$(LIBFT_INC)


#==========SOURCES============================================================#


SHELL_FILES := shell main signals commands

#==========FILES###===========================================================#

SRC_FILES+=$(SHELL_FILES)

SRCS := $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS := $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS := $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))

#==========RULES==============================================================#



all: $(NAME)
bonus: $(BONUS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c Makefile
	@$(MKDIR) $(dir $@)	
	@$(CC) $(CFLAGS) $(IFLAGS) -MP -MMD -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "$(BOLD_CYAN)[$(BOLD_PURPLE)$(NAME)$(DEF_COLOR)$(BOLD_CYAN)] compiled!$(DEF_COLOR)"
	@echo "$(BOLD_CYAN)------------\n| Done! 👌 |\n------------$(DEF_COLOR)"

$(LIBFT):
	@make -sC $(LIBFT_DIR)

clean:
	@$(RM) -rf $(OBJ_DIR)
	@make clean -sC $(LIBFT_DIR)
	@echo "$(CYAN)[$(NAME)]:\tobject files $(GREEN) => Cleaned!$(DEF_COLOR)"

fclean: clean
	@$(RM) -rf $(NAME)
	@make fclean -sC $(LIBFT_DIR)
	@echo "$(CYAN)[$(NAME)]:\texec. files $(GREEN) => Cleaned!$(DEF_COLOR)"

re: fclean all

-include $(DEPS)

.SILENT: all clean fclean
.PHONY: all clean fclean re bonus
