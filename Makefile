# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/26 22:44:32 by jekim             #+#    #+#              #
#    Updated: 2021/06/04 17:25:49 by jekim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_NAME = client
SERVER_NAME = server
CC = gcc
CCFLAG = -Wall -Wextra -Werror -g3
RM = rm -rf

CLIENT_DIR = ../client/
SERVER_DIR = ../server/

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/
LIBFT_HEADERS = $(LIBFT_DIR)

CLIENT_FILE		= server.c
CLIENT_SOURCES	= $(addprefix $(CLIENT_DIR), $(CLIENT_FILE))

SERVER_FILE		= server.c
SERVER_SOURCES	= $(addprefix $(SERVER_DIR), $(SERVER_FILE))

CLIENT_OBJDIR = ./obj/client
CLIENT_OBJFILE = $(patsubst %.c, %.o, $(CLIENT_SOURCES))
CLIENT_OBJECTS	= $(addprefix $(CLIENT_OBJDIR), $(CLIENT_OBJFILE))

SERVER_OBJDIR = ./obj/server
SERVER_OBJFILE = $(patsubst %.c, %.o, $(SERVER_SOURCES))
SERVER_OBJECTS	= $(addprefix $(SERVER_OBJECTS), $(SERVER_OBJFILE))

.PHONY: all
all: $(OBJDIR) $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(LIBFT) $(CLIENT_OBJECTS)
	@$(CC) $(CCFLAGS) $(INCLUDES) $(CLIENT_OBJECTS) -o $(CLIENT_NAME)

$(SERVER_NAME): $(LIBFT) $(SERVER_OBJECTS)
	@$(CC) $(CCFLAGS) $(INCLUDES) $(SERVER_OBJECTS) -o $(SERVER_NAME)

$(OBJDIR):
	@mkdir -p $(CLIENT_OBJDIR) $(SERVER_OBJDIR) 

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

.PHONY: clean
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJDIR)

.PHONY: fclean
fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(CLIENT_NAME)
	@rm -f $(SERVER_NAME)

.PHONY: re
re:
	@$(MAKE) fclean
	@$(MAKE) all
