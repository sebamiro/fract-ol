# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seba <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/17 16:37:30 by seba              #+#    #+#              #
#    Updated: 2022/11/10 10:07:47 by smiro            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

MKFL	=	Makefile

SRCS	=	ft_printf.c ft_puthexnbr.c ft_putptr.c handletype.c ft_putchar.c ft_putnbr.c \
			ft_putctype.c ft_itoa.c

OBJS	= $(SRCS:.c=.o)

RM	= rm -f
CFLAGS	= -Wall -Wextra -Werror -I.

%.o: %.c ft_printf.h $(MKFL)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\r                                                                           "
	@printf "\r ${CC} ${CFLAGS} -I./ -c $< -o $@"

all:
	@$(MAKE) $(NAME)

$(NAME):	$(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "\nCompiled"

clean:
	$(RM) $(NAME) $(OBJS)

fclean:	
	$(MAKE) clean
	$(RM) $(NAME)

re:	
	$(MAKE) fclean
	$(MAKE)

.PHONY: all clean fclean re
