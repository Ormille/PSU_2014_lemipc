##
## Makefile for lemipc in /home/terran_j/rendu/PSU_2014_lemipc
##
## Made by Julie Terranova
## Login   <terran_j@epitech.net>
##
## Started on  Wed Mar  4 11:09:24 2015 Julie Terranova
## Last update Wed Mar  4 15:46:15 2015 Julie Terranova
##

NAME1=	 lemipc

NAME2=	 show

DIR1=    team/src/

DIR2=    SDL/src/

SRC1=    $(DIR1)main_team.c \

SRC2=    $(DIR2)main_sdl.c \
	 $(DIR2)draw.c \
	 $(DIR2)move.c \

OBJ1=    $(SRC1:.c=.o)

OBJ2=    $(SRC2:.c=.o)

CFLAGS= -Wall -Wextra -Werror -I team/include/ -I SDL/include/

LDFLAGS1= -lX11

LDFLAGS2= -lSDLmain -lSDL -lX11 -lSDL_ttf

all:	$(NAME1) $(NAME2)

$(NAME1):$(OBJ1)
	cc -o $(NAME1) $(LDFLAGS1) $(OBJ1)

$(NAME2):$(OBJ2)
	cc -o $(NAME2) $(LDFLAGS2) $(OBJ2)

clean:
	rm -f $(OBJ1) rm -f $(OBJ2)

fclean: clean
	rm -f $(NAME1) rm -f $(NAME2)

re:     fclean all

.PHONY: all clean fclean re
