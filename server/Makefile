# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jekim <arabi1549@naver.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/11 19:25:28 by jekim             #+#    #+#              #
#    Updated: 2021/06/21 22:17:04 by jekim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	server
CC			=	gcc
CCFLAG		=	-Wall -Wextra -Werror
SNTZ		=	-g3 -fsanitize=address

SOURCES		=	server.c server_reqresolve.c

HEADERS		=	-I.
OBJECTS		=	$(SOURCES:.c=.o)

LIBPATH		=	../libft/
LIBFLAG		=	 -lft -L$(LIBPATH)

all			:	$(NAME)

$(NAME)		:	$(OBJECTS)
	$(CC) $(CCFLAG) $(LIBFLAG) $(HEADERS) $(OBJECTS) -o $(NAME)
	@echo "\033[0;92m* $(NAME) program file was created *\033[0m"

clean		:
	rm -rf $(OBJECTS)
	@echo "\033[0;91m* $(NAME) object files was deleted *\033[0m"

fclean		:	clean
	rm -rf $(NAME)
	@echo "\033[0;91m* $(NAME) was deleted* \033[0m"

re			:	fclean all

.PHONY		:	all clean fclean re
