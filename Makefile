##
## EPITECH PROJECT, 2020
## CPE_lemin_2019
## File description:
## Makefile
##

SRC_DIR		=	src/

INC_DIR		=	include/

LIB_DIR		=	lib/my/

SRC			=	$(SRC_DIR)main.c								\
				$(SRC_DIR)display_info.c						\
				$(SRC_DIR)tools/word_array.c					\
				$(SRC_DIR)tools/allowed_char.c					\
				$(SRC_DIR)tools/3d_array.c						\
				$(SRC_DIR)parsing/get_nb_ants.c					\
				$(SRC_DIR)parsing/get_rooms.c					\
				$(SRC_DIR)parsing/get_script.c					\
				$(SRC_DIR)parsing/del_comments.c				\
				$(SRC_DIR)parsing/get_tunnels.c					\
				$(SRC_DIR)parsing/interprate_commands.c			\
				$(SRC_DIR)chained_list/create_room.c			\
				$(SRC_DIR)chained_list/connect_rooms.c			\
				$(SRC_DIR)chained_list/realloc_room_t_array.c	\

OBJ			=	$(SRC:.c=.o)

NAME		=	lem_in

CFLAGS		+=	-Wall -Wextra -I./include

LDLFLAGS	+= -L $(LIB_DIR) -lmy

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C $(LIB_DIR)
		gcc -o $(NAME) $(OBJ) $(LDLFLAGS)

clean:
			@make clean -C $(LIB_DIR) --no-print-directory
			@rm -f $(OBJ)

fclean:		clean
			@make clean -C $(LIB_DIR) --no-print-directory
			@rm -f $(NAME)

re:	fclean all

run:	all
	./$(NAME)

debugs: CFLAGS += -g
debugs: re

.PHONY: all clean fclean re run debugs
