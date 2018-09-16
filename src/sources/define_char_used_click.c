/*
** EPITECH PROJECT, 2018
** char used click
** File description:
** char used click
*/

#include "declaration.h"

int define_char_used2(sfRenderWindow *window)
{
	sfVector2i pos = sfMouse_getPositionRenderWindow(window);

	if (pos.x > 60 && pos.x < 300 && pos.y > 500 && pos.y < 700 &&
		sfMouse_isButtonPressed(sfMouseLeft) == 1)
		return (5);
	if (pos.x > 360 && pos.x < 600 && pos.y > 500 && pos.y < 700 &&
		sfMouse_isButtonPressed(sfMouseLeft) == 1)
		return (6);
	if (pos.x > 660 && pos.x < 900 && pos.y > 500 && pos.y < 700 &&
		sfMouse_isButtonPressed(sfMouseLeft) == 1)
		return (7);
	if (pos.x > 960 && pos.x < 1200 && pos.y > 500 && pos.y < 700 &&
		sfMouse_isButtonPressed(sfMouseLeft) == 1)
		return (8);
	return (0);
}

int define_char_used_click(sfRenderWindow *window)
{
	sfVector2i pos = sfMouse_getPositionRenderWindow(window);

	if (pos.x > 60 && pos.x < 300 && pos.y > 200 && pos.y < 400 &&
		sfMouse_isButtonPressed(sfMouseLeft) == 1)
		return (1);
	if (pos.x > 360 && pos.x < 600 && pos.y > 200 && pos.y < 400 &&
		sfMouse_isButtonPressed(sfMouseLeft) == 1)
		return (2);
	if (pos.x > 660 && pos.x < 900 && pos.y > 200 && pos.y < 400 &&
		sfMouse_isButtonPressed(sfMouseLeft) == 1)
		return (3);
	if (pos.x > 960 && pos.x < 1200 && pos.y > 200 && pos.y < 400 &&
		sfMouse_isButtonPressed(sfMouseLeft) == 1)
		return (4);
	return (define_char_used2(window));
}
