# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 15:23:29 by smiro             #+#    #+#              #
#    Updated: 2023/04/15 20:00:59 by smiro            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################

MAKE		= make --no-print-directory

NAME		= libft.a
INC			= ./inc/

SRC_DIR		= src/
OBJ_DIR		= obj/
DEP_DIR		= dep/

CFLAGS		= -I $(INC) -MMD -MP -MF $(DEP_DIR)$*.d -Wall -Werror -Wextra
RM			= rm -rf
CC			= gcc
AR			= ar rcs

################################################################################

SRC_LIST	:=	$(shell find $(SRC_DIR:/=) -type d)

SRC			:=	$(shell find $(SRC_DIR:/=) -name '*.c')
OBJ 		=	$(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(SRC:.c=.o))
DEP 		=	$(patsubst $(SRC_DIR)%, $(DEP_DIR)%, $(SRC:.c=.d))

################################################################################

all:
			@$(MAKE) $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c Makefile
			@printf "\rcompiling.. $(notdir $<)%20c"
			@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)::	$(OBJ_DIR) $(DEP_DIR) $(OBJ)
			@$(AR) $(NAME) $(OBJ)
			@printf "\r$(basename $@): done%20c\n"

$(OBJ_DIR):
			@mkdir $(patsubst $(SRC_DIR:/=)%, $(@:/=)%, $(SRC_LIST))
			@echo "creating.. $@"

$(DEP_DIR):
			@mkdir $(patsubst $(SRC_DIR:/=)%, $(@:/=)%, $(SRC_LIST))
			@echo "creating.. $@"

clean:
			@$(RM) $(OBJ_DIR) $(DEP_DIR)
			@echo "removing.. $(OBJ_DIR)"
			@echo "removing.. $(DEP_DIR)"

fclean:
			@$(MAKE) clean
			@$(RM) $(NAME)
			@echo "removing.. $(NAME)"

re:
			@$(MAKE) fclean
			@$(MAKE)

.PHONY: all clean fclean re
-include $(DEP)
