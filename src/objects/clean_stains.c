/*
** EPITECH PROJECT, 2018
** clean stains
** File description:
** clean stains
*/

#include "declaration.h"

void destroy_dishes(dish **d)
{
	for (int x = 0; d[x] != NULL; x++) {
		sfRectangleShape_destroy(d[x]->rect);
		free(d[x]);
	}
	free(d);
}

int clean_stains(dish **d, total_struct *s, sfRenderWindow *window)
{
	sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
	sfVector2f pos;
	sfVector2f size = {100, 100};
	int left = 0;

	for (int x = 0; d[x] != NULL; x++) {
		pos = sfRectangleShape_getPosition(d[x]->rect);
		if (mouse_pos.x > pos.x && mouse_pos.x < pos.x + size.x &&
			mouse_pos.y > pos.y && mouse_pos.y < pos.y + size.y
			&& d[x]->alive == true) {
			sound_effect(s, 'c');
			sfRectangleShape_setTexture(d[x]->rect,
				s->text.food_00[0], sfTrue);
			d[x]->alive = false;
		}
	}
	for (int x = 0; d[x] != NULL; x++)
		if (d[x]->alive != false)
			left++;
	return (left);
}
