/*
** EPITECH PROJECT, 2018
** clean_dishes
** File description:
** clean dishes
*/

#include "declaration.h"

void display_plate(sfTexture *texture, sfRenderWindow *window)
{
	sfRectangleShape *rect = sfRectangleShape_create();
	sfVector2f pos = {0, 0};
	sfVector2f size = {1260, 840};

	sfRectangleShape_setPosition(rect, pos);
	sfRectangleShape_setSize(rect, size);
	sfRectangleShape_setTexture(rect, texture, sfTrue);
	sfRenderWindow_drawRectangleShape(window, rect, NULL);
	sfRectangleShape_destroy(rect);
}

dish *create_stain(sfTexture *texture, dish *d)
{
	float pos_x = rand() % 400 + 400;
	float pos_y = rand() % 400 + 200;
	sfVector2f pos = {pos_x, pos_y};
	sfVector2f size = {100, 100};

	d = malloc(sizeof(dish));
	d->rect = sfRectangleShape_create();
	sfRectangleShape_setPosition(d->rect, pos);
	sfRectangleShape_setSize(d->rect, size);
	sfRectangleShape_setTexture(d->rect, texture, sfTrue);
	d->alive = true;
	return (d);
}

dish **create_stains(total_struct *s)
{
	int nb = rand() % 5 + 4;
	dish **d = malloc(sizeof(dish *) * (nb + 1));

	for (int x = 0; x < nb; ++x)
		d[x] = create_stain(s->text.dish_dirty[0], d[x]);
	d[nb] = NULL;
	return (d);
}

void display_stains(dish **d, sfRenderWindow *window)
{
	for(int x = 0; d[x] != NULL; ++x)
		sfRenderWindow_drawRectangleShape(window, d[x]->rect, NULL);
}

void clean_dishes(character_struct *c, total_struct *s, sfRenderWindow *window)
{
	dish **d;
	int stains_left = 1;

	while (c->plates != 5) {
		stains_left = 1;
		d = create_stains(s);
		while (sfRenderWindow_isOpen(window) && stains_left != 0) {
			furnace_update(window, s, c->f, true);
			choose_music(s);
			display_ath(window, s->text.ATH[0]);
			client_management(c, s, window);
			display_plate(s->text.dish_empty[0], window);
			display_stains(d, window);
			stains_left = clean_stains(d, s, window);
			sfRenderWindow_display(window);
			event_close(window);
		}
		destroy_dishes(d);
		c->plates++;
	}
}
