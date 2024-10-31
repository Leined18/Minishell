# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 14:34:27 by danpalac          #+#    #+#              #
#    Updated: 2024/10/31 11:19:21 by danpalac         ###   ########.fr        #
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

BUILTINS_DIR	:= builtins/
COMMANDS_DIR	:= cmd/
ENV_DIR			:= env/
ERRORS_DIR		:= errors/
INPUT_DIR		:= input/
INTERPRETER_DIR	:= interpreter/
MEMORY_DIR		:= memory/
SHELL_DIR		:= shell/
SIGNALS 		:= signals/

INC_BUILINS		:= $(SRC_DIR)$(BUILTINS_DIR)
INC_COMMANDS	:= $(SRC_DIR)$(COMMANDS_DIR)
INC_ENV			:= $(SRC_DIR)$(ENV_DIR)
INC_ERRORS		:= $(SRC_DIR)$(ERRORS_DIR)
INC_INPUT		:= $(SRC_DIR)$(INPUT_DIR)
INC_INTERPRETER	:= $(SRC_DIR)$(INTERPRETER_DIR)
INC_MEMORY		:= $(SRC_DIR)$(MEMORY_DIR)
INC_SHELL		:= $(SRC_DIR)$(SHELL_DIR)
INC_SIGNALS		:= $(SRC_DIR)$(SIGNALS)

#==========COMMANDS============================================================#

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -g3 -fsanitize=address
RM			:= rm -rf
AR			:= ar rcs
LIB			:= ranlib
MKDIR 		:= mkdir -p
LDFLAGS		:= -L$(LIBFT_DIR) -lft -lm -fsanitize=address
IFLAGS		:= -I$(INC) -I$(LIBFT_INC) -I$(INC_BUILINS) -I$(INC_COMMANDS) -I$(INC_ENV) -I$(INC_ERRORS) -I$(INC_INPUT) -I$(INC_INTERPRETER) -I$(INC_MEMORY) -I$(INC_SHELL) -I$(INC_SIGNALS)


#==========SOURCES============================================================#


BUILTINS_FILES :=
COMMANDS_FILES := ft_create_child ft_create_cmd ft_execmd ft_handle_parent ft_pipe_cmd ft_redirect_input ft_redirect_output\
			ft_get_cmd_path ft_parse_cmd ft_free_command
ENV_FILES :=
ERRORS_FILES :=
INPUT_FILES :=
INTERPRETER_FILES :=
MEMORY_FILES :=
SHELL_FILES := main shell cleanup init
SIGNALS_FILES := signal_handler signal_utils

#==========FILES###===========================================================#

#SRC_FILES+=$(addprefix $(BUILTINS_DIR), $(BUILTINS_FILES))
SRC_FILES+=$(addprefix $(COMMANDS_DIR), $(COMMANDS_FILES))
#SRC_FILES+=$(addprefix $(ENV_DIR), $(ENV_FILES))
#SRC_FILES+=$(addprefix $(ERRORS_DIR), $(ERRORS_FILES))
#SRC_FILES+=$(addprefix $(INPUT_DIR), $(INPUT_FILES))
#SRC_FILES+=$(addprefix $(INTERPRETER_DIR), $(INTERPRETER_FILES))
#SRC_FILES+=$(addprefix $(MEMORY_DIR), $(MEMORY_FILES))
SRC_FILES+=$(addprefix $(SHELL_DIR), $(SHELL_FILES))
SRC_FILES+=$(addprefix $(SIGNALS), $(SIGNALS_FILES))

SRCS := $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS := $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS := $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))

#==========RULES==============================================================#

-include $(DEPS)

all: $(NAME)
bonus: $(BONUS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c Makefile
	@$(MKDIR) $(dir $@)	
	@$(CC) $(CFLAGS) $(IFLAGS) -MP -MMD -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "$(BOLD_CYAN)[$(BOLD_MAGENTA)$(NAME)$(BOLD_CYAN)] compiled!$(DEF_COLOR)"
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

.SILENT: all clean fclean
.PHONY: all clean fclean re bonus
