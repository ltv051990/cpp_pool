# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/03 15:52:32 by pgritsen          #+#    #+#              #
#    Updated: 2018/04/15 19:21:19 by pgritsen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	clang++

CFLAGS		=	-Wextra -Werror -Wall -O3 -Os -flto=thin

NAME		=	ft_gkrellm

SRC			=	main.cpp AMonitorModule.cpp DisplayContainer.cpp ProcessesModule.cpp	\
				ClockModule.cpp HardMemModule.cpp RAMMemModule.cpp Cor.cpp				\
				NetworkModule.cpp UserDataModule.cpp CpuLoadModule.cpp OSInfoModule.cpp	\
				VirtMemModule.cpp Ncurses.cpp UnicornModule.cpp

HDRS		=	AMonitorModule.hpp DisplayContainer.hpp ProcessesModule.hpp				\
				ClockModule.hpp HardMemModule.hpp RAMMemModule.hpp Cor.hpp				\
				NetworkModule.hpp UserDataModule.hpp CpuLoadModule.hpp OSInfoModule.hpp	\
				VirtMemModule.hpp Ncurses.hpp UnicornModule.hpp

OBJ			=	$(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

OBJDIR		=	obj

LIBR		=	-lncurses -framework OpenGL -framework AppKit -framework SDL2	\
				-framework SDL2_ttf -framework SDL2_image -rpath ./frameworks

INCLUDES	=	-I./frameworks/SDL2.framework/Headers
INCLUDES	+=	-I./frameworks/SDL2_ttf.framework/Headers
INCLUDES	+=	-I./frameworks/SDL2_image.framework/Headers
INCLUDES	+=	-I./frameworks/SDL2_mixer.framework/Headers
INCLUDES	+=	-F./frameworks

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ)
	@echo "Creating" $(NAME) "..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INCLUDES) $(LIBR)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJ): $(OBJDIR)/%.o : %.cpp $(HDRS)
	@echo "Compiling" $< "..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "Obj clean"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "Full clean"
	@rm -rf $(NAME)

re: fclean all
