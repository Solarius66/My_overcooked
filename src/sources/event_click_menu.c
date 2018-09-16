/*
** EPITECH PROJECT, 2018
** event click
** File description:
** event click
*/

#include "declaration.h"

sfVector2f get_click_pos(sfRenderWindow *window, sfEvent event)
{
	sfVector2i mouse_pos;
	sfVector2f pos= {0, 0};

	if (event.type == sfEvtMouseButtonPressed) {
		mouse_pos = sfMouse_getPositionRenderWindow(window);
		pos.x = mouse_pos.x;
		pos.y = mouse_pos.y;
	}
	return (pos);
}

int button_isClicked(sfRectangleShape *button, sfVector2f pos)
{
	sfVector2f posRect = sfRectangleShape_getPosition(button);
	sfVector2f size = sfRectangleShape_getSize(button);

	if (pos.x < posRect.x + size.x && pos.x > posRect.x &&
		pos.y < posRect.y + size.y && pos.y > posRect.y)
		return (1);
	else
		return (0);
}

void event_click_menu(sfRenderWindow *window, total_struct *s,
			struct full_buttons *buttons, sfEvent event)
{
	sfVector2f click_pos = get_click_pos(window, event);

	if (button_isClicked(buttons->main->play, click_pos) == 1)
		game_main(window, s, define_char_used(s, window));
	if (button_isClicked(buttons->main->opt, click_pos) == 1)
		options_manager(window, s, buttons);
	if ( button_isClicked(buttons->main->quit, click_pos) == 1)
		really_quit(window, s);
}

int button_is_clicked_quit(sfRenderWindow *window)
{
	sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

	if (mouse_pos.x > 500 && mouse_pos.x < 600 &&
		mouse_pos.y > 420 && mouse_pos.y < 470 &&
		sfMouse_isButtonPressed(sfMouseLeft))
		return (1);
	if (mouse_pos.x > 650 && mouse_pos.x < 750 &&
		mouse_pos.y > 420 && mouse_pos.y < 470 &&
		sfMouse_isButtonPressed(sfMouseLeft)) {
		sfRenderWindow_close(window);
		return (1);
	}
	return (0);
}
