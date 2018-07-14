#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/04 09:40:40 by tlutsyk           #+#    #+#              #
#    Updated: 2018/04/04 09:40:42 by tlutsyk          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SWITCH =		\033[
ST_NORM =		$(SWITCH)0m
COLOR_GREEN = 	$(SWITCH)32m
COLOR_RED =		$(SWITCH)31m
COLOR_SGREEN =	$(SWITCH)33m

NAME = sed_for_loosers

CC = clang++
FLAGS = -Wall -Wextra -Werror

SOURCES = main.cpp

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