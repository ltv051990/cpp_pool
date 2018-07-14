#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/10 10:26:32 by tlutsyk           #+#    #+#              #
#    Updated: 2018/04/11 16:15:04 by tlutsyk          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra

NAME = DONT_BE_A_DICK

SRC = main.cpp Cast.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
