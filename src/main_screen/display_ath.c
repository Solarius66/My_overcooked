/*
** EPITECH PROJECT, 2018
** display ath
** File description:
** display ath
*/

#include "declaration.h"

void display_ath(sfRenderWindow *window, sfTexture *texture)
{
	sfVector2f pos = {0, 0};
	sfIntRect rect = {0, 0, 300, 840};
	struct game_object *ath = create_gameobject(texture, pos, rect);

	sfRenderWindow_drawSprite(window, ath->sprite, NULL);
	sfSprite_destroy(ath->sprite);
	free(ath);
}

void display_recipe(sfRenderWindow *window, sfTexture *texture)
{
	sfRectangleShape *rect = sfRectangleShape_create();
	sfVector2f pos = {0, 0};
	sfVector2f size = {1260, 840};

	if (sfKeyboard_isKeyPressed(sfKeyTab) == 1) {
		sfRectangleShape_setPosition(rect, pos);
		sfRectangleShape_setSize(rect, size);
		sfRectangleShape_setTexture(rect, texture, sfTrue);
		sfRenderWindow_drawRectangleShape(window, rect, NULL);
	}
	sfRectangleShape_destroy(rect);
}
