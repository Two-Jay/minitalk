# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/11 19:21:52 by jekim             #+#    #+#              #
#    Updated: 2021/06/13 00:04:19 by jekim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	client
CC			=	gcc
CCFLAG		=	-Wall -Wextra -Werror

SOURCES		=	client.c client1.c

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
		@echo "\033[0;91m* $(NAME) was deleted *\033[0m"

re			:	fclean all

.PHONY		:	all clean fclean re
