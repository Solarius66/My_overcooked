/*
** EPITECH PROJECT, 2018
** button machine
** File description:
** button machine
*/

#include "declaration.h"

void fill_food_machine(character_struct *c, machine_struct *m, total_struct *s)
{
	int x = 0;

	while (x <= 3) {
		if (m->food[x].id == 0) {
			m->food[x].name = c->food.name;
			c->food.name = "Empty";
			m->food[x].id = c->food.id;
			c->food.id = 0;
			m->food[x].texture = c->food.texture;
			c->food.texture = s->text.food_00[0];
			m->food[x].burnable = c->food.burnable;
			c->food.burnable = true;
			m->food[x].sliceable = c->food.sliceable;
			c->food.sliceable = true;
			break;
		} else
			x++;
	}
}

void put_machine(character_struct *c, total_struct *s, machine_struct *m)
{
	if (c->food.id <= 4096 && c->food.id > 0 && c->food.burnable == true
		&& c->food.sliceable == true)
		fill_food_machine(c, m, s);
	else if ((c->food.id == 0 && m->food[0].id == 0 && m->food[1].id == 0 &&
			m->food[2].id == 0 && m->food[3].id == 0) ||
			(c->food.id != 0 && (c->food.burnable == false ||
			c->food.sliceable == false)))
		sound_effect(s, 'e');
}

void redefine_machine_struct(total_struct *s, machine_struct *m)
{
	define_food_machine(m, 0, s->text.food_00[0]);
	define_food_machine(m, 1, s->text.food_00[0]);
	define_food_machine(m, 2, s->text.food_00[0]);
	define_food_machine(m, 3, s->text.food_00[0]);
}

void button_management_machine(character_struct *c, total_struct *s,
				sfRenderWindow *window, machine_struct *m)
{
	sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

	if (mouse_pos.x > 540 && mouse_pos.x < 780 &&
		mouse_pos.y > 520 && mouse_pos.y < 620 &&
		sfMouse_isButtonPressed(sfMouseLeft) == 1)
		put_machine(c, s, m);
	if (mouse_pos.x > 60 && mouse_pos.x < 300 &&
		mouse_pos.y > 520 && mouse_pos.y < 620 &&
		sfMouse_isButtonPressed(sfMouseLeft) == 1)
		redefine_machine_struct(s, m);
	if (mouse_pos.x > 300 && mouse_pos.x < 540 &&
		mouse_pos.y > 520 && mouse_pos.y < 620 &&
		sfMouse_isButtonPressed(sfMouseLeft) == 1)
		launch_machine(c, m, s);
	if (mouse_pos.y > 350 && mouse_pos.y < 450 &&
		sfMouse_isButtonPressed(sfMouseLeft) == 1)
		take_machine(c, m, mouse_pos, s);
}
