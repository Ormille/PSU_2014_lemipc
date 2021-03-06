##
## Makefile for lemipc in /home/terran_j/rendu/PSU_2014_lemipc
##
## Made by Julie Terranova
## Login   <terran_j@epitech.net>
##
## Started on  Wed Mar  4 11:09:24 2015 Julie Terranova
## Last update Sun Mar  8 19:08:38 2015 moran-_d
##

NAME1=	lemipc

NAME2=	show

DIR1=   team/src/

DIR2=   SDL/src/

SRC1=	$(DIR1)main.c \
	$(DIR1)maths.c \
	$(DIR1)team.c \
	$(DIR1)player.c \
	$(DIR1)get_shared.c \
	$(DIR1)msg.c \
	$(DIR1)action_scout.c \
	$(DIR1)ia.c \
	$(DIR1)ia_commoner.c \
	$(DIR1)ia_flag.c \
	$(DIR1)move.c \
	$(DIR1)move_consequence.c \
	$(DIR1)formation_pattern.c \

SRC2=    $(DIR2)main_sdl.c \
	 $(DIR2)draw.c \
	 $(DIR2)sdl_base.c \
	 $(DIR2)move.c \
	 $(DIR2)show_map.c \
	 $(DIR2)get_shared.c \

OBJ1=   $(SRC1:.c=.o)

OBJ2=   $(SRC2:.c=.o)

CFLAGS= -Wall -Wextra -Werror -I team/include/ -I SDL/include/ -g # a virer!!

LDFLAGS1= -lX11 -lm

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
