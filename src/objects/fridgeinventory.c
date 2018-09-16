/*
** EPITECH PROJECT, 2018
** fridge inventory
** File description:
** inventory
*/

#include "declaration.h"

void display_inventory_font(sfTexture *texture, sfRenderWindow *window)
{
	sfVector2f pos = {780, 520};
	sfVector2f size = {420, 100};
	sfRectangleShape *rect = sfRectangleShape_create();

	sfRectangleShape_setPosition(rect, pos);
	sfRectangleShape_setSize(rect, size);
	sfRectangleShape_setTexture(rect, texture, sfTrue);
	sfRenderWindow_drawRectangleShape(window, rect, NULL);
	sfRectangleShape_destroy(rect);
}

void display_food_inventory(sfTexture *texture, sfRenderWindow *window)
{
	sfVector2f pos = {1050, 532};
	sfVector2f size = {75, 75};
	sfRectangleShape *rect = sfRectangleShape_create();

	sfRectangleShape_setPosition(rect, pos);
	sfRectangleShape_setSize(rect, size);
	sfRectangleShape_setTexture(rect, texture, sfFalse);
	sfRenderWindow_drawRectangleShape(window, rect, NULL);
	sfRectangleShape_destroy(rect);
}

void display_fridge_inventory(character_struct *c, total_struct *s,
				sfRenderWindow *window)
{
	sfVector2f pos = {800, 550};
	display_inventory_font(s->text.button_longOFF[0], window);
	text_create(s->text.font, "Inventory :", pos, window);
	display_food_inventory(c->food.texture, window);
}
