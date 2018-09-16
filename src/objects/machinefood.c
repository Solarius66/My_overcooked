/*
** EPITECH PROJECT, 2018
** machine food
** File description:
** machine food
*/

#include "declaration.h"

void create_food_machine(sfVector2f size, sfVector2f pos, sfTexture *texture,
				sfRenderWindow *window)
{
	sfRectangleShape *rect = sfRectangleShape_create();

	sfRectangleShape_setPosition(rect, pos);
	sfRectangleShape_setSize(rect, size);
	sfRectangleShape_setTexture(rect, texture, sfTrue);
	sfRenderWindow_drawRectangleShape(window, rect, NULL);
	sfRectangleShape_destroy(rect);
}

void display_food_machine(machine_struct *m, sfRenderWindow *window)
{
	sfVector2f size = {256, 256};
	sfVector2f pos0 = {120, 100};
	sfVector2f pos1 = {375, 100};
	sfVector2f pos2 = {630, 100};
	sfVector2f pos3 = {885, 100};

	create_food_machine(size, pos0, m->food[0].texture, window);
	create_food_machine(size, pos1, m->food[1].texture, window);
	create_food_machine(size, pos2, m->food[2].texture, window);
	create_food_machine(size, pos3, m->food[3].texture, window);
}

void take_food_machine(machine_struct *m, character_struct *c, int food_nbr,
			total_struct *s)
{
	if (c->food.id == 0) {
		c->food.name = m->food[food_nbr].name;
		m->food[food_nbr].name = "Empty";
		c->food.id = m->food[food_nbr].id;
		m->food[food_nbr].id = 0;
		c->food.texture = m->food[food_nbr].texture;
		m->food[food_nbr].texture = s->text.food_00[0];
		c->food.burnable = m->food[food_nbr].burnable;
		m->food[food_nbr].burnable = true;
		c->food.sliceable = m->food[food_nbr].sliceable;
		m->food[food_nbr].sliceable = true;
	}
}

void take_machine(character_struct *c, machine_struct *m, sfVector2i mouse_pos,
			total_struct *s)
{
	if (mouse_pos.x > 125 && mouse_pos.x < 365)
		take_food_machine(m, c, 0, s);
	if (mouse_pos.x > 380 && mouse_pos.x < 620)
		take_food_machine(m, c, 1, s);
	if (mouse_pos.x > 635 && mouse_pos.x < 855)
		take_food_machine(m, c, 2, s);
	if (mouse_pos.x > 890 && mouse_pos.x < 1130)
		take_food_machine(m, c, 3, s);
}
