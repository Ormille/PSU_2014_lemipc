##
## Makefile for lemipc in /home/terran_j/rendu/PSU_2014_lemipc
##
## Made by Julie Terranova
## Login   <terran_j@epitech.net>
##
## Started on  Wed Mar  4 11:09:24 2015 Julie Terranova
## Last update Wed Mar  4 11:14:40 2015 Julie Terranova
##

NAME=   lemipc

DIR=    src/

SRC=    $(DIR)main.c \

OBJ=    $(SRC:.c=.o)

CFLAGS= -Wall -Wextra -Werror -I include/

LDFLAGS= -lSDLmain -lSDL -lX11 -lSDL_ttf

all:    $(NAME)

$(NAME):$(OBJ)
	cc -o $(NAME) $(LDFLAGS) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re
