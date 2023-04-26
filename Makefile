# **************************************************************************** #
#    Makefile                                                                  #
# **************************************************************************** #

MAKE		=	make --no-print-directory

NAME		= fract-ol
INC			= ./inc/

Lib_DIR		= $(INC)libft/
FT_LNK		= -L$(Lib_DIR) -lft
MLX_DIR		= ./mlx/

SRC_DIR		= src/
BIN_DIR		= bin/
OBJ_DIR		= obj/
DEP_DIR		= dep/

CFLAGS		= -Wall -Werror -Wextra
CFLAGS		+= -MMD -MP -MF $(DEP_DIR)$*.d
RM			= rm -rf

COMFLAGS	= -Imlx -I $(INC) -I $(Lib_DIR)inc/
LINKFLAGS	= -lmlx -Lmlx -lpthread $(FT_LNK)

################################################################################

SRC_LIST	:=	$(shell find $(SRC_DIR:/=) -type d)

SRC			:=	$(shell find $(SRC_DIR:/=) -name '*.c')
OBJ 		=	$(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(SRC:.c=.o))
DEP 		=	$(patsubst $(SRC_DIR)%, $(DEP_DIR)%, $(SRC:.c=.d))
BIN			=	$(addprefix $(BIN_DIR), $(NAME))

################################################################################

all:
			@$(MAKE) -sC $(Lib_DIR)
			@$(MAKE) -sC $(MLX_DIR)
			@cp $(MLX_DIR)libmlx.dylib ./libmlx.dylib
			@$(MAKE) $(BIN)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c Makefile
			@echo "compiling.. $(notdir $<)"
			@$(CC) $(CFLAGS) $(COMFLAGS) -c $< -o $@

$(BIN):	$(OBJ_DIR) $(DEP_DIR) $(BIN_DIR) $(OBJ)
			@$(CC) $(CFLAGS) $(LINKFLAGS) $(OBJ) -o $(BIN)
			@echo "$(NAME): done"

$(BIN_DIR):
			@mkdir -p $@
			@echo "creating.. $@"

$(OBJ_DIR):
			@mkdir $(patsubst $(SRC_DIR:/=)%, $(@:/=)%, $(SRC_LIST))
			@echo "creating.. $@"

$(DEP_DIR):
			@mkdir $(patsubst $(SRC_DIR:/=)%, $(@:/=)%, $(SRC_LIST))
			@echo "creating.. $@"

clean:
			@$(MAKE) clean -sC $(Lib_DIR)
			@$(RM) $(OBJ_DIR) $(DEP_DIR)
			@echo "removing.. $(OBJ_DIR)"
			@echo "removing.. $(DEP_DIR)"

fclean:
			@$(MAKE) fclean -sC $(Lib_DIR)
			@$(MAKE) clean
			@$(RM) $(BIN_DIR)
			@$(RM) libmlx.dylib
			@echo "removing.. $(BIN_DIR)"

re:
			@$(MAKE) fclean
			@$(MAKE)

.PHONY: all clean fclean re
-include $(DEP)
