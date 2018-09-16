/*
** EPITECH PROJECT, 2018
** my_overcooked
** File description:
** tomska le alien
*/

#include "declaration.h"

int destroy_food(character_struct *c, total_struct *s)
{
	c->food.name = "Empty";
	c->food.id = 0;
	c->food.burnable = true;
	c->food.sliceable = true;
	c->food.texture = s->text.food_00[0];
	return (0);
}

void use_space_bar(character_struct *c, total_struct *s,
			sfRenderWindow *window, machine_struct *m)
{
	if (c->look_tile == 6 && sfKeyboard_isKeyPressed(sfKeySpace))
		slice_management(c, window, s);
	if (c->look_tile == 7 && sfKeyboard_isKeyPressed(sfKeySpace))
		clean_dishes(c, s, window);
	if ((c->look_tile == 8 || c->look_tile == 9) &&
		sfKeyboard_isKeyPressed(sfKeySpace))
		furnace_action(s, c);
	if (c->look_tile == 10 && sfKeyboard_isKeyPressed(sfKeySpace))
		destroy_food(c, s);
	if (c->look_tile == 11 && sfKeyboard_isKeyPressed(sfKeySpace))
		rolling_carpet_management(c, s);
	if (c->look_tile == 12 && sfKeyboard_isKeyPressed(sfKeySpace))
		fridge_management(c, s, window);
	if (c->look_tile == 13 && sfKeyboard_isKeyPressed(sfKeySpace))
		machine_management(c, s, window, m);
}
