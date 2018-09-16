/*
** EPITECH PROJECT, 2018
** game_menu
** File description:
** game_menu
*/

#include "declaration.h"

void display_text(struct main_textes *textes, struct main_buttons *buttons,
			sfRenderWindow *window)
{
	sfRenderWindow_drawRectangleShape(window, buttons->play, NULL);
	sfRenderWindow_drawRectangleShape(window, buttons->opt, NULL);
	sfRenderWindow_drawRectangleShape(window, buttons->quit, NULL);
	sfRenderWindow_drawText(window, textes->play, NULL);
	sfRenderWindow_drawText(window, textes->opt, NULL);
	sfRenderWindow_drawText(window, textes->quit, NULL);
}

void define_color_buttons_long(sfRenderWindow *window,
				sfRectangleShape *buttons, total_struct *s)
{
	sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
	sfVector2f rect_pos = sfRectangleShape_getPosition(buttons);
	sfVector2f rect_size = sfRectangleShape_getSize(buttons);

	if (mouse_pos.x > rect_pos.x && mouse_pos.y > rect_pos.y &&
		mouse_pos.x < rect_pos.x + rect_size.x &&
		mouse_pos.y < rect_pos.y + rect_size.y)
		sfRectangleShape_setTexture(buttons,
						s->text.button_longON[0],
						sfTrue);
	else
		sfRectangleShape_setTexture(buttons,
						s->text.button_longOFF[0],
						sfTrue);
}

void display_things(sfRenderWindow *window, struct main_textes *textes,
			struct main_buttons *buttons)
{
	display_text(textes, buttons, window);
	sfRenderWindow_display(window);
}

void free_that_shit(struct main_textes *textes, struct full_buttons *buttons,
			struct game_object *title)
{
	sfText_destroy(textes->play);
	sfText_destroy(textes->opt);
	sfText_destroy(textes->quit);
	sfRectangleShape_destroy(buttons->main->play);
	sfRectangleShape_destroy(buttons->main->opt);
	sfRectangleShape_destroy(buttons->main->quit);
	sfRectangleShape_destroy(buttons->opt->window_size);
	sfRectangleShape_destroy(buttons->opt->music);
	sfRectangleShape_destroy(buttons->opt->how2play);
	sfRectangleShape_destroy(buttons->opt->quit);
	free(textes);
	free(buttons->main);
	free(buttons->opt);
	free(buttons);
	sfSprite_destroy(title->sprite);
	free(title);
}

void game_menu(sfRenderWindow *window, total_struct *s)
{
	sfVector2f pos_bg = {0, 0};
	sfIntRect rect_bg = set_rect(0, 1260, 840);
	struct game_object *title = create_gameobject(s->text.backg[0],
							pos_bg, rect_bg);
	struct full_buttons *buttons =
		create_buttons(s->text.button_longOFF[0],
				s->text.button_shortOFF[0]);
	struct main_textes *textes = main_menu_textes(s->text.font);

	while (sfRenderWindow_isOpen(window)) {
		s->first_client = 0;
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawSprite(window, title->sprite, NULL);
		define_color_buttons_long(window, buttons->main->play, s);
		define_color_buttons_long(window, buttons->main->opt, s);
		define_color_buttons_long(window, buttons->main->quit, s);
		display_things(window, textes, buttons->main);
		event_manage_home(window, buttons, s);
	}
	free_that_shit(textes, buttons, title);
}
