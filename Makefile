


NAME		=	minitalk
LIBFTDIR	=	./libft/
CLIDIR		=	./client/
SRVDIR		=	./server/

all			:
		@$(MAKE) -C $(LIBFTDIR)
		@$(MAKE) -C	$(CLIDIR)
		@$(MAKE) -C	$(SRVDIR)
		@echo "\033[0;94m*----- $(NAME) was compiled -----*\033[0m"

clean		:
		@$(MAKE) -C $(LIBFTDIR) clean
		@$(MAKE) -C	$(CLIDIR) clean
		@$(MAKE) -C	$(SRVDIR) clean
		@echo "\033[0;91m*----- $(NAME)'s object files was deleted -----*\033[0m"

fclean		:
		@$(MAKE) -C $(LIBFTDIR) fclean
		@$(MAKE) -C	$(CLIDIR) fclean
		@$(MAKE) -C	$(SRVDIR) fclean
		@echo "\033[0;91m*----- $(NAME) was deleted -----*\033[0m"

re			:	fclean all

.PHONY		:	all clean fclean re
