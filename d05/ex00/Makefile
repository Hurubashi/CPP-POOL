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

NAME = run

CC = clang++

CFLAGS = -Wall -Wextra -Werror

SRC = $(patsubst %.cpp,%.o,$(wildcard ./*.cpp))

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all