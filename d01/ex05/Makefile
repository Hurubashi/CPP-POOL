# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrybak <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/12 11:56:48 by mrybak            #+#    #+#              #
#    Updated: 2018/06/12 11:56:50 by mrybak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = brain

CC		= clang++
FLAGS	= -Wall -Wextra -Werror
SRC		= $(patsubst %.cpp,%.o,$(wildcard ./*.cpp))
OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all