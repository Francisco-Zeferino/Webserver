RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
WHITE	= \033[1;37m
RESET 	= \033[0m

NAME = WebServer

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address -g

SRCS = srcs/

all: $(NAME)

$(NAME): $(SRCS)
	@clear
	@echo "\n$(BLUE) [Compiling] $(NAME)$(RESET)\n"
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)
	@echo "$(GREEN) [Success] ./$(NAME) created.$(RESET)\n\n"

clean:
	@clear
	@echo "\n$(RED) [Deleting] .o files ... (deleted)$(RESET)\n\n"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(GREEN) [Success] $(NAME) files ... (deleted)$(RESET)\n\n"

re: fclean all

.PHONY: all clean fclean re
