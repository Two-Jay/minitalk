# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jekim <arabi1549@naver.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/11 19:21:52 by jekim             #+#    #+#              #
#    Updated: 2021/06/24 20:48:42 by jekim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	client
CC			=	gcc
CCFLAG		=	-Wall -Wextra -Werror
SNTZ		=	-g3 -fsanitize=address

SOURCES		=	client.c client_reqsend.c client_init.c

HEADERS		=	-I.
OBJ			=	$(SOURCES:.c=.o)

BONUSPATH	=	./client_bonus/
BONUSHDR	=	-I$(BONUSPATH)
BONUSSRC	=	$(BONUSPATH)client_bonus.c	\
				$(BONUSPATH)client_init_bonus.c	\
				$(BONUSPATH)client_reqsend_bonus.c
BOBJ		=	$(BONUSSRC:.c=.o)

LIBPATH		=	../libft/
LIBFLAG		=	 -lft -L$(LIBPATH)

ifdef WITH_BONUS
	OBJECTS = $(BOBJ)
else
	OBJECTS = $(OBJ)
endif

all			:	$(NAME)

$(NAME)		:	$(OBJECTS)
		$(CC) $(CCFLAG) $(LIBFLAG) $(HEADERS) $(OBJECTS) -o $(NAME)
		@echo "\033[0;92m* $(NAME) program file was created *\033[0m"

bonus		:
		@make WITH_BONUS=1 all

clean		:
		rm -rf $(OBJ) $(BOBJ)
		@echo "\033[0;91m* $(NAME) object files was deleted *\033[0m"

fclean		:	clean
		rm -rf $(NAME)
		@echo "\033[0;91m* $(NAME) was deleted *\033[0m"

re			:	fclean all

.PHONY		:	all clean fclean re
