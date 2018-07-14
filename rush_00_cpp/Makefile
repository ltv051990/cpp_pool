#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/07 12:34:30 by tlutsyk           #+#    #+#              #
#    Updated: 2018/04/07 12:34:32 by tlutsyk          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SWITCH =		\033[
ST_NORM =		$(SWITCH)0m
COLOR_GREEN = 	$(SWITCH)32m
COLOR_RED =		$(SWITCH)31m
COLOR_SGREEN =	$(SWITCH)33m

NAME = ft_retro

CC = clang++
FLAGS = -Wall -Wextra -Werror -lncurses

SOURCES = Ncurse.cpp main.cpp Player.class.cpp Bullet.class.cpp Enemy.class.cpp \
		Asteroid.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(FLAGS) -o $@ $^
	@echo "$(STYLE_BOLD)$(COLOR_GREEN)OK!!!$(COLOR_RED)ft_retro is ready"
clean:
	@rm -rf $(OBJECTS)

fclean:
	@rm -rf $(OBJECTS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
