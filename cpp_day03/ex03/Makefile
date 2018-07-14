#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/05 11:22:31 by tlutsyk           #+#    #+#              #
#    Updated: 2018/04/05 11:22:33 by tlutsyk          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SWITCH =		\033[
ST_NORM =		$(SWITCH)0m
COLOR_GREEN = 	$(SWITCH)32m
COLOR_RED =		$(SWITCH)31m
COLOR_SGREEN =	$(SWITCH)33m

NAME = ninja

CC = clang++
FLAGS = -Wall -Wextra -Werror

SOURCES = FragTrap.cpp main.cpp SravTrap.cpp ClapTrap.cpp NinjaTrap.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(FLAGS) -o $@ $^
	@echo "$(STYLE_BOLD)$(COLOR_GREEN)OK!!!"

clean:
	@rm -rf $(OBJECTS)

fclean:
	@rm -rf $(OBJECTS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
