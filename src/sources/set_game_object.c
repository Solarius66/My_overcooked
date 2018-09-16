/*
** EPITECH PROJECT, 2017
** set_game object
** File description:
** set Rect, Pos of a gameobject
*/

#include "declaration.h"

sfIntRect set_rect(int left, int width, int height)
{
	sfIntRect rect;
	rect.left = left;
	rect.top = 0;
	rect.width = width;
	rect.height = height;
	return (rect);
}

struct game_object *create_gameobject(sfTexture *texture, sfVector2f pos,
					sfIntRect rect)
{
	struct game_object *object = malloc(sizeof(struct game_object));
	sfSprite *sprite = sfSprite_create();

	sfSprite_setTexture(sprite, texture, sfTrue);
	object->sprite = sprite;
	object->texture = texture;
	object->rect = rect;
	object->pos = pos;
	sfSprite_setPosition(object->sprite, object->pos);
	sfSprite_setTextureRect(object->sprite, object->rect);
	return (object);
}
