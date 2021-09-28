# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jekim <arabi1549@naver.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/11 19:25:28 by jekim             #+#    #+#              #
#    Updated: 2021/09/28 16:43:36 by jekim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	server
CC			=	gcc
CCFLAG		=	-Wall -Wextra -Werror
SNTZ		=	-g3 -fsanitize=address

SOURCES		=	server.c server_reqresolve.c

HEADERS		=	-I.
OBJ			=	$(SOURCES:.c=.o)

BONUSPATH	=	./server_bonus/
BONUSHDR	=	-I$(BONUSPATH)
BONUSSRC	=	$(BONUSPATH)server_bonus.c	\
				$(BONUSPATH)server_reqresolve_bonus.c	
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
		@$(CC) $(CCFLAG) $(LIBFLAG) $(HEADERS) $(OBJECTS) -o $(NAME)
		@echo "\033[0;92m* $(NAME) program file was created *\033[0m"

%.o : %.c
		@$(CC) $(CCFLAG) $(INCLUDE) $< -c -o $@

bonus		:
		@make WITH_BONUS=1 all

clean		:
		@rm -rf $(OBJ) $(BOBJ)
		@echo "\033[0;91m* $(NAME) object files was deleted *\033[0m"

fclean		:	clean
		@rm -rf $(NAME)
		@echo "\033[0;91m* $(NAME) was deleted* \033[0m"

re			:	fclean all

.PHONY		:	all clean fclean re
