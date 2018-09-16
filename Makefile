##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

NAME	= my_cook

CC	= gcc

RM	= rm -f

SRC_DIR	= ./src

FUNC_DIR = ./functions

SRCS	=	$(SRC_DIR)/main.c \
		$(SRC_DIR)/error_gest/error_main.c\
		$(SRC_DIR)/error_gest/error_music.c\
		$(SRC_DIR)/error_gest/error_texture.c\
		$(SRC_DIR)/error_gest/error_function.c\
		$(SRC_DIR)/error_gest/error_map.c \
		$(SRC_DIR)/sources/window_manager.c\
		$(SRC_DIR)/sources/set_game_object.c\
		$(SRC_DIR)/sources/set_buttonobj.c\
		$(SRC_DIR)/sources/event_click_menu.c\
		$(SRC_DIR)/sources/set_textes.c\
		$(SRC_DIR)/sources/event_click_opt.c\
		$(SRC_DIR)/sources/define_char_used.c\
		$(SRC_DIR)/sources/define_char_used_click.c\
		$(SRC_DIR)/main_screen/create_map.c\
		$(SRC_DIR)/main_screen/display_ath.c\
		$(SRC_DIR)/main_screen/read_map_file.c\
		$(SRC_DIR)/main_screen/score_management.c\
		$(SRC_DIR)/main_screen/client_display.c\
		$(SRC_DIR)/main_screen/client_filling.c\
		$(SRC_DIR)/main_screen/define_map_used.c\
		$(SRC_DIR)/anim/create_texture.c \
		$(SRC_DIR)/anim/destroy_texture.c \
		$(SRC_DIR)/anim/texture_main.c \
		$(SRC_DIR)/menus/game_main.c\
		$(SRC_DIR)/menus/game_menu.c\
		$(SRC_DIR)/menus/quit.c\
		$(SRC_DIR)/menus/loading_screen.c\
		$(SRC_DIR)/menus/options.c\
		$(SRC_DIR)/menus/pause.c\
		$(SRC_DIR)/menus/end.c\
		$(SRC_DIR)/anim/char_anim.c\
		$(SRC_DIR)/anim/can_charac_move.c\
		$(SRC_DIR)/objects/fridge.c\
		$(SRC_DIR)/objects/fridgefood.c\
		$(SRC_DIR)/objects/fridgetext.c\
		$(SRC_DIR)/objects/fridgebutton.c\
		$(SRC_DIR)/objects/fridgefood_file.c\
		$(SRC_DIR)/objects/fridgeinventory.c\
		$(SRC_DIR)/objects/inventory.c\
		$(SRC_DIR)/objects/machine.c\
		$(SRC_DIR)/objects/machinebutton.c\
		$(SRC_DIR)/objects/machinefood.c\
		$(SRC_DIR)/objects/machinelaunch.c\
		$(SRC_DIR)/objects/rollingcarpet.c\
		$(SRC_DIR)/objects/slice.c\
		$(SRC_DIR)/objects/clean.c\
		$(SRC_DIR)/objects/clean_stains.c\
		$(SRC_DIR)/interaction/space_bar.c\
		$(SRC_DIR)/interaction/furnace.c\
		$(SRC_DIR)/interaction/furnace_2.c\
		$(SRC_DIR)/anim/press_space.c\
		$(SRC_DIR)/interaction/discharge.c\
		$(SRC_DIR)/music/music_alloc.c\
		$(SRC_DIR)/music/sound_effect.c\
		$(SRC_DIR)/anim/place_character.c\
		lib/my_getnbr.c


OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include
CFLAGS += -W -Wall -Wextra -pedantic

LDFLAGS	= -L./lib/my/ -lepi -l c_graph_prog

all: $(NAME)

library:
	 (cd lib/my/ && make re)

lib_fclean:
	(cd lib/my/ && make fclean)

lib_clean:
	(cd lib/my/ && make clean)

$(NAME): library $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean: lib_clean
	$(RM) $(OBJS)

fclean: clean lib_fclean
	$(RM) $(NAME)

re: fclean all
