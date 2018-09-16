/*
** EPITECH PROJECT, 2017
** game_object
** File description:
** game object bootstrap
*/

#include "declaration.h"
#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

struct game_object {
	sfTexture *texture;
	sfSprite *sprite;
	sfIntRect rect;
	sfVector2f pos;
};

struct game_object *create_object(sfTexture texture, sfVector2f pos,
	sfIntRect rect);

#endif /* !GAME_OBJECT_H_ */
