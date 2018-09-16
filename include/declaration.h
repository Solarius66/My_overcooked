/*
** EPITECH PROJECT, 2018
** my_overcooked
** File description:
** THE declaration file
*/

#ifndef DECLARATION_H
#define DECLARATION_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include "epilib.h"
#include "game_object.h"
#include "struct_button.h"
#include "enum.h"
#include "struct_char.h"
#include "character.h"
#include "struct_textes.h"
#include "global_struct.h"
#include "machine.h"
#include "dish.h"

int error_main(void);
int error_map(void);
sfRenderWindow *create_window(void);
void event_close(sfRenderWindow *);
char *read_map_file(sfRenderWindow *, total_struct *);
void create_map(char *, sfRenderWindow *, sfTexture *);
sfIntRect set_rect(int, int, int);
struct game_object *create_gameobject(sfTexture *, sfVector2f, sfIntRect);
void display_ath(sfRenderWindow *, sfTexture *);
int my_getnbr(char *);
void display_score_star(sfRenderWindow *, int, sfTexture *);
void display_clients(sfRenderWindow *, int, total_struct *);
void display_loading_screen(sfRenderWindow *);
int error_func(void);
int error_music(void);
int error_graph(char *, char *, int, int);
struct main_buttons *main_menu_buttons(sfTexture *);
sfTexture **create_texture(char *, int, sfIntRect *);
total_struct *texture_main(sfRenderWindow *);
int destroy_all(total_struct *);
void can_charac_move(character_struct *, int *);
void set_charac_pos(character_struct *, int);
void set_charac_pos2(character_struct *, int);
character_struct *character_init(total_struct *, int, char *);
void charac_main(character_struct *, total_struct *, sfRenderWindow *);
void modify_look(int, character_struct *);
void use_space_bar(character_struct *, total_struct *, sfRenderWindow *,
			machine_struct *);
void event_manage_home(sfRenderWindow *, struct full_buttons *,
			total_struct *);
struct main_textes *main_menu_textes(sfFont *);
void really_quit(sfRenderWindow *, total_struct *);
void options_manager(sfRenderWindow *, total_struct *, struct full_buttons *);
struct opt_buttons *opt_menu_buttons(sfTexture *);
int button_is_clicked_quit(sfRenderWindow *);
sfVector2f get_click_pos(sfRenderWindow *, sfEvent);
int button_isClicked(sfRectangleShape *, sfVector2f);
int event_click_opt(total_struct *, struct full_buttons *, sfEvent,
			struct opt_textes *);
int event_manage_opt(sfRenderWindow *, struct full_buttons *,
			struct opt_textes *, total_struct *);
void event_click_menu(sfRenderWindow *, total_struct *,
			struct full_buttons *, sfEvent);
void game_menu(sfRenderWindow *, total_struct *);
int game_main(sfRenderWindow *, total_struct *, int);
struct full_buttons *create_buttons(sfTexture *, sfTexture *);
struct opt_textes *opt_menu_textes(sfFont *);
void define_color_buttons_short(sfRenderWindow *, sfRectangleShape *,
				total_struct *);
void define_color_buttons_long(sfRenderWindow *, sfRectangleShape *,
				total_struct *);
void define_color_buttons_long(sfRenderWindow *, sfRectangleShape *,
				total_struct *);
struct side_char *define_side_char(sfVector2f, char *);
void display_food_fridge(total_struct *, sfRenderWindow *, int,
				character_struct *);
sfRectangleShape *create_rect(total_struct *, sfVector2f, sfVector2f,
				sfRenderWindow *);
void text_create(sfFont *, char *, sfVector2f, sfRenderWindow *);
void fridge_management(character_struct *, total_struct *, sfRenderWindow *);
void display_text_fridge_page1(sfFont *, sfRenderWindow *);
void display_text_fridge_page2(sfFont *, sfRenderWindow *);
void display_text_fridge_page3(sfFont *, sfRenderWindow *);
void define_buttons_page1(character_struct *, sfRenderWindow *,
				total_struct *);
void define_buttons_page1_bis(character_struct *, sfRenderWindow *,
				total_struct *);
void define_buttons_page2(character_struct *, sfRenderWindow *,
				total_struct *);
void define_buttons_page3(character_struct *, sfRenderWindow *,
				total_struct *);
void define_food_inventory1(character_struct *, char *, int, sfTexture *);
void define_food_inventory2(character_struct *, bool, bool);
void display_fridge_inventory(character_struct *, total_struct *,
				sfRenderWindow *);
int inventory_display(character_struct *, sfRenderWindow *, total_struct *);
int pause_main(total_struct *, sfRenderWindow *);
sfRectangleShape *create_button(sfTexture *, sfVector2f, sfVector2f);
int display_quit_game(sfFont *, sfRenderWindow *);
void create_font(sfTexture *, sfRenderWindow *);
int furnace_action(total_struct *, character_struct *);
void kill_furnace(character_struct *, furnace *);
int if_forest(total_struct *, character_struct *, furnace *);
void create_furnace(total_struct *, character_struct *);
int get_id_furnace(character_struct *, char);
int destroy_furnace(character_struct *);
void space_press(total_struct *, int, character_struct *, sfRenderWindow *);
void my_text_create1(sfFont *, char *, sfVector2f, sfRenderWindow *);
void my_text_create(sfFont *, char *, sfVector2f, sfRenderWindow *);
int furnace_update(sfRenderWindow *, total_struct *s, furnace *, bool);
void machine_management(character_struct *, total_struct *, sfRenderWindow *,
			machine_struct *);
void display_food_machine(machine_struct *, sfRenderWindow *);
void define_food_machine(machine_struct *, int, sfTexture *);
void launch_machine(character_struct *, machine_struct *, total_struct *);
void take_machine(character_struct *, machine_struct *, sfVector2i,
			total_struct *);
void button_management_machine(character_struct *, total_struct *,
				sfRenderWindow *, machine_struct *);
machine_struct *define_machine_struct(total_struct *);
void redefine_machine_struct(total_struct *, machine_struct *);
void client_filling(clients_full *, int, total_struct *);
void client_scrolling_main(character_struct *, sfRenderWindow *,
				total_struct *);
void create_client(clients_full *, int, total_struct *);
void client_management(character_struct *, total_struct *, sfRenderWindow *);
clients_full *create_client_struct(total_struct *);
void discharge_main(total_struct *, character_struct *, machine_struct *);
int destroy_food(character_struct *, total_struct *);
void rolling_carpet_management(character_struct *, total_struct *);
void slice_management(character_struct *, sfRenderWindow *, total_struct *);
int end_dis(character_struct *, sfRenderWindow *, total_struct *);
void create_pause_font(sfTexture *, sfRenderWindow *);
void destroy_music(music *);
void music_alloc(total_struct *);
void choose_music(total_struct *s);
void mute_unmute(total_struct *, int);
void display_recipe(sfRenderWindow *, sfTexture *);
void create_sound(music *);
void destroy_sound(music *);
int sound_effect(total_struct *, char);
void display_recipe(sfRenderWindow *, sfTexture *);
void clean_dishes(character_struct *, total_struct *, sfRenderWindow *);
int clean_stains(dish **, total_struct *, sfRenderWindow *);
int define_char_used(total_struct *, sfRenderWindow *);
void destroy_dishes(dish **);
int define_char_used_click(sfRenderWindow *);
bool no_seg(character_struct *, char *);
void place_charac(character_struct *, char *);
void create_buttons_map(sfRenderWindow *, total_struct *, char **);
void display_font_char(sfTexture *, sfRenderWindow *);
void display_rect_char(total_struct *, int, int, sfRenderWindow *);
char **define_names_maps(void);

#endif /*DECLARATION_H*/
