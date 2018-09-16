/*
** EPITECH PROJECT, 2018
** options .c
** File description:
** otps
*/

#include "declaration.h"

void define_color_buttons_short(sfRenderWindow *window,
				sfRectangleShape *buttons, total_struct *s)
{
	sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
	sfVector2f rect_pos = sfRectangleShape_getPosition(buttons);
	sfVector2f rect_size = sfRectangleShape_getSize(buttons);
	if (mouse_pos.x > rect_pos.x && mouse_pos.y > rect_pos.y &&
		mouse_pos.x < rect_pos.x + rect_size.x &&
		mouse_pos.y < rect_pos.y + rect_size.y)
		sfRectangleShape_setTexture(buttons,
						s->text.button_shortON[0],
						sfTrue);
	else
		sfRectangleShape_setTexture(buttons,
						s->text.button_shortOFF[0],
						sfTrue);
}

void display_opt_buttons(struct opt_buttons *buttons, sfRenderWindow *window,
				struct opt_textes *textes, total_struct *s)
{
	define_color_buttons_long(window, buttons->window_size, s);
	define_color_buttons_long(window, buttons->music, s);
	define_color_buttons_short(window, buttons->how2play, s);
	define_color_buttons_short(window, buttons->quit, s);
	sfRenderWindow_drawRectangleShape(window, buttons->window_size, NULL);
	sfRenderWindow_drawRectangleShape(window, buttons->music, NULL);
	sfRenderWindow_drawRectangleShape(window, buttons->how2play, NULL);
	sfRenderWindow_drawRectangleShape(window, buttons->quit, NULL);
	sfRenderWindow_drawText(window, textes->fps, NULL);
	sfRenderWindow_drawText(window, textes->music, NULL);
	sfRenderWindow_drawText(window, textes->tuto, NULL);
	sfRenderWindow_drawText(window, textes->quit, NULL);
}

void options_manager(sfRenderWindow *window, total_struct *s,
			struct full_buttons *buttons)
{
	sfVector2f pos = {0, 0};
	struct game_object *font = create_gameobject(s->text.backg[0], pos,
							set_rect(0, 1260,
									840));
	struct opt_textes *textes = opt_menu_textes(s->text.font);

	for (int open = 0 ; sfRenderWindow_isOpen(window) && open == 0 ;) {
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawSprite(window, font->sprite, NULL);
		display_opt_buttons(buttons->opt, window, textes, s);
		open = event_manage_opt(window, buttons, textes, s);
		sfRenderWindow_display(window);
	}
	sfSprite_destroy(font->sprite);
	sfText_destroy(textes->fps);
	sfText_destroy(textes->music);
	sfText_destroy(textes->tuto);
	sfText_destroy(textes->quit);
	free(font);
	free(textes);
}
