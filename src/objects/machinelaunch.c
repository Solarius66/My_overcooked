/*
** EPITECH PROJECT, 2018
** machine launch
** File description:
** machine launch
*/

#include "declaration.h"

void compiled_food(character_struct *c, sfTexture *texture, int id, char *name)
{
	c->food.name = name;
	c->food.id = id;
	c->food.texture = texture;
	c->food.burnable = true;
	c->food.sliceable = true;
}

void launch_machine(character_struct *c, machine_struct *m, total_struct *s)
{
	int dish_id = m->food[0].id + m->food[1].id + m->food[2].id +
			m->food[3].id;

	if (dish_id == 21)
		compiled_food(c, s->text.dish_3[0], dish_id, "Orange Soup");
	if (dish_id == 40)
		compiled_food(c, s->text.dish_4[0], dish_id, "Green Soup");
	if (dish_id == 136)
		compiled_food(c, s->text.dish_6[0], dish_id, "Chick'n Chips");
	if (dish_id == 522)
		compiled_food(c, s->text.dish_5[0], dish_id, "fish'n Chips");
	if (dish_id == 2115)
		compiled_food(c, s->text.dish_1[0], dish_id, "Burger");
	if (dish_id == 5377)
		compiled_food(c, s->text.dish_2[0], dish_id, "Pizza");
	if (dish_id != 21 && dish_id != 40 && dish_id != 136 && dish_id != 0 &&
		dish_id != 522 && dish_id != 2115 && dish_id != 5377)
		compiled_food(c, s->text.dish_7[0], -1, "Censored");
	redefine_machine_struct(s, m);
}
