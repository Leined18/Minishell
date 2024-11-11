# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 14:34:27 by danpalac          #+#    #+#              #
#    Updated: 2024/11/11 14:32:25 by danpalac         ###   ########.fr        #
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
PARSE_LIB	:= parse.a
EXE_LIB		:= exe.a
LIBFT_LIB	:= libft.a

LIBFT		:= $(LIBFT_DIR)$(LIBFT_LIB)
EXE 		:= $(EXE_DIR)$(EXE_LIB)
PARSE		:= $(PARSE_DIR)$(PARSE_LIB)

#==========DIRECTORIES=======================================================#

SUBMODULES		:= submodules/
INC 			:= inc/
SRC_DIR 		:= src/
OBJ_DIR 		:= obj/


LIBFT_DIR		:= $(SUBMODULES)libft/
EXE_DIR			:= $(SUBMODULES)exe/
PARSE_DIR		:= $(SUBMODULES)parse/
MEMTRACK_DIR	:= $(SUBMODULES)memtrack/
SHELL_DIR		:= shell/


INC_PARSE		:= $(PARSE_DIR)$(OBJ_DIR)$(INC)
INC_EXE			:= $(EXE_DIR)$(OBJ_DIR)$(INC)
INC_MEMTRACK	:= $(MEMTRACK_DIR)$(OBJ_DIR)$(INC)
INC_SHELL		:= $(SRC_DIR)$(SHELL_DIR)
LIBFT_INC		:= $(LIBFT_DIR)$(INC)

#==========COMMANDS============================================================#

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -g3 -fsanitize=address
RM			:= rm -rf
AR			:= ar rcs
LIB			:= ranlib
MKDIR 		:= mkdir -p
LDFLAGS		:= -L$(LIBFT_DIR) -L$(EXE_DIR) -L$(PARSE_DIR) -lft -lm -fsanitize=address
IFLAGS		:= -I$(INC) -I$(LIBFT_INC) -I$(INC_PARSE) -I$(INC_EXE) -I$(INC_MEMTRACK) -I$(INC_SHELL)
RDLFLAG		:= -lreadline

#==========SOURCES============================================================#


SHELL_FILES		:= cleanup init #shell utils
MAIN_FILES		:= main

#==========FILES###===========================================================#

SRC_FILES+=$(addprefix $(SHELL_DIR), $(SHELL_FILES))
SRC_FILES+=$(MAIN_FILES)

SRCS := $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS := $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS := $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))

#==========RULES==============================================================#

all: $(NAME)

-include $(DEPS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c Makefile
	@$(MKDIR) $(dir $@)	
	@$(CC) $(CFLAGS) $(IFLAGS) -MP -MMD -c $< -o $@

$(NAME): $(LIBFT) $(EXE) $(PARSE) $(OBJS) 
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME) $(RDLFLAG)
	@echo "$(BOLD_CYAN)[$(BOLD_MAGENTA)$(NAME)$(BOLD_CYAN)] compiled!$(DEF_COLOR)"
	@echo "$(BOLD_CYAN)------------\n| Done! 👌 |\n------------$(DEF_COLOR)"

$(EXE): 
	@make -sC $(EXE_DIR)

$(PARSE): 
	@make -sC $(PARSE_DIR)

$(LIBFT):
	@make -sC $(LIBFT_DIR)

clean:
	@$(RM) -rf $(OBJ_DIR)
	@make clean -sC $(LIBFT_DIR)
	@echo "$(CYAN)[$(NAME)]:\tobject files $(GREEN) => Cleaned!$(DEF_COLOR)"

fclean: clean
	@$(RM) -rf $(NAME) 
	@make fclean -sC $(EXE_DIR)
	@make fclean -sC $(PARSE_DIR)
	@make fclean -sC $(MEMTRACK_DIR)
	@make fclean -sC $(LIBFT_DIR)
	@echo "$(CYAN)[$(NAME)]:\texec. files $(GREEN) => Cleaned!$(DEF_COLOR)"

re: fclean all

.SILENT: all clean fclean
.PHONY: all clean fclean re bonus
