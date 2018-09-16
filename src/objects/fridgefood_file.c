/*
** EPITECH PROJECT, 2018
** fridge food file
** File description:
** ada
*/

#include "declaration.h"

void define_food_inventory1(character_struct *c, char *name, int id,
				sfTexture *texture)
{
	c->food.name = name;
	c->food.id = id;
	c->food.texture = texture;
}

void define_food_inventory2(character_struct *c, bool burn, bool slice)
{
	c->food.burnable = burn;
	c->food.sliceable = slice;
}
