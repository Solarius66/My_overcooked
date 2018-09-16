/*
** EPITECH PROJECT, 2018
** set_button_obj
** File description:
** button obj
*/

#include "declaration.h"

sfRectangleShape *create_button(sfTexture *texture,
				sfVector2f pos, sfVector2f rect)
{
	sfRectangleShape *rectangle = sfRectangleShape_create();

	sfRectangleShape_setPosition(rectangle, pos);
	sfRectangleShape_setSize(rectangle, rect);
	sfRectangleShape_setTexture(rectangle, texture, sfTrue);
	return (rectangle);
}

struct main_buttons *main_menu_buttons(sfTexture *texture)
{
	struct main_buttons *main_buts = malloc(sizeof(struct main_buttons));
	sfVector2f pos_play = {700, 450};
	sfVector2f pos_quit = {700, 650};
	sfVector2f pos_opt = {100, 650};
	sfVector2f size = {480, 100};
	sfRectangleShape *play = create_button(texture, pos_play, size);
	sfRectangleShape *opt = create_button(texture, pos_opt, size);
	sfRectangleShape *quit = create_button(texture, pos_quit, size);

	if (main_buts == NULL)
		return (NULL);
	main_buts->play = play;
	main_buts->opt = opt;
	main_buts->quit = quit;
	return (main_buts);
}

struct opt_buttons *opt_menu_buttons(sfTexture *texture)
{
	struct opt_buttons *buttons = malloc(sizeof(struct opt_buttons));
	sfVector2f pos_win = {250, 430};
	sfVector2f pos_mus = {250, 570};
	sfVector2f pos_how = {800, 430};
	sfVector2f pos_quit = {800, 570};
	sfVector2f size_s = {240, 100};
	sfVector2f size_l = {500, 100};
	sfRectangleShape *win_size = create_button(texture, pos_win, size_l);
	sfRectangleShape *music = create_button(texture, pos_mus, size_l);
	sfRectangleShape *how2play = create_button(texture, pos_how, size_s);
	sfRectangleShape *quit = create_button(texture, pos_quit, size_s);

	if (buttons == NULL)
		return (NULL);
	buttons->window_size = win_size;
	buttons->music = music;
	buttons->how2play = how2play;
	buttons->quit = quit;
	return (buttons);
}

struct full_buttons *create_buttons(sfTexture *longt, sfTexture *shortt)
{
	struct full_buttons *full_butts = malloc(sizeof(struct full_buttons));

	full_butts->main = main_menu_buttons(longt);
	full_butts->opt = opt_menu_buttons(shortt);
	return (full_butts);
}
