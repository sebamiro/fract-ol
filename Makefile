# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 15:23:29 by smiro             #+#    #+#              #
#    Updated: 2023/03/20 17:16:23 by smiro            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
################################################################################

NAME		= fractol
INC			= ./includes/
INC_HEADERS	= $(INC)fractol.h $(INC)defines.h

Lib_DIR		= $(INC)libft/
Lib_INC		= $(Lib_DIR)libft.h
FT_LNK		= -L$(Lib_DIR) -lft
Lib			= $(Lib_DIR)libft.a
MLX_DIR		= ./mlx/

SRC_DIR		= src/
OBJ_DIR		= obj/

COMFLAGS	= -I/Users/$(USER)/.brew/opt/readline/include
LINKFLAGS	= -L/Users/$(USER)/.brew/opt/readline/lib -lreadline
CFLAGS		= -I $(INC) -MMD -Wall -Werror -Wextra -O3
RM			= rm -f

COMFLAGS	= -Imlx
LINKFLAGS	= -lmlx -Lmlx -lpthread

################################################################################
### COLORS
################################################################################

DEL_LINE =		\033[2K
ITALIC =		\033[3m
BOLD =			\033[1m
DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m
BLACK =			\033[0;99m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;2;184;143;29m
DARK_GRAY =		\033[38;5;234m
MID_GRAY =		\033[38;5;245m
DARK_GREEN =	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m

################################################################################
################################################################################

SRC_FILES	=	fractol.c \
				utils.c \
				keyboard_hook.c \
				init.c \
				hooks.c \
				draw.c \
				mouse_hook.c \
				draw_controls.c \
				color.c \
				fractals/mandelbrot.c \
				/fractals/julia.c \
				/fractals/burning_ship.c \
				/fractals/mandelbar.c \
				/fractals/perpendicular_mandelbrot.c \
				/fractals/celtic_mandelbrot.c \
				/fractals/celtic_mandelbar.c \
				/fractals/perpendicular_celtic.c \
				/fractals/heart.c \
				/fractals/buffalo.c \
				sierpinsky.c

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ 		=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))
DEP			= 	$(addsuffix .d, $(basename $(OBJ)))
B_OBJ		=	$(OBJ)

################################################################################
################################################################################

all:
			@$(MAKE) -sC $(Lib_DIR)
			@$(MAKE) -sC $(MLX_DIR)
			@cp $(MLX_DIR)libmlx.dylib ./libmlx.dylib
			@$(MAKE) $(NAME)

$(OBJ_DIR)%.o: %.c Makefile
			@mkdir -p $(dir $@)
			@printf "\r${ORANGE} | $(BROWN)COMPILING ${ORANGE}|  $(BLUE)< ${MAGENTA}$(notdir $(basename $<)) $(BLUE)> $(DEF_COLOR)%20c"
			@$(CC) $(CFLAGS) $(COMFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
			@$(CC) $(CFLAGS) $(OBJ) $(FT_LNK) $(LINKFLAGS) -o $(NAME)
			@echo "\n\n$(BLUE)[$(ORANGE)============$(BLUE)<|$(ORANGE)DONE$(BLUE)|>$(ORANGE)============$(BLUE)] $(DEF_COLOR)"

-include $(DEP)

clean:
			@$(RM) -r $(OBJ_DIR)
			@$(MAKE) clean -sC $(Lib_DIR)
			@echo "\n${RED}[$(MAGENTA)Objects removed successfully${RED}]$(DEF_COLOR)\n"

fclean:
			@$(MAKE) clean
			@$(RM) $(NAME)
			@$(RM) libmlx.dylib
			@$(MAKE) fclean -sC $(Lib_DIR)
			@echo "\n${RED}[$(MAGENTA)Everything removed successfully${RED}]$(DEF_COLOR)\n"

re:
			@$(MAKE) fclean
			@$(MAKE)

.PHONY: all clean fclean re
