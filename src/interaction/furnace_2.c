/*
** EPITECH PROJECT, 2018
** my_overcooked
** File description:
** buuuuuuurn baby buuuurn!!!!
*/

#include "declaration.h"

void kill_furnace(character_struct *c, furnace *f)
{
	c->food.id = f->food.id;
	c->food.name = f->food.name;
	c->food.texture = f->food.texture;
	c->food.sliceable = f->food.sliceable;
	c->food.burnable = f->food.burnable;
	sfClock_destroy(f->clock);
	free(f);
}

int if_forest(total_struct *s, character_struct *c, furnace *f)
{
	if ((c->f == NULL || f == NULL) && c->food.id == 0)
		return (1);
	if ((c->f == NULL|| f == NULL) && c->food.id != 0) {
		create_furnace(s, c);
		return (1);
	}
	if (f->idX == get_id_furnace(c, 'x') &&
		f->idY == get_id_furnace(c, 'y') && c->food.id == 0 &&
		f->food.id != 0) {
		destroy_furnace(c);
		return (1);
	}
	if (f->idX == get_id_furnace(c, 'x') && f->idY == get_id_furnace(c, 'y')
		&& c->food.id != 0)
		return (1);
	return (0);
}

int print_furnace_time(sfRenderWindow *window, total_struct *s, furnace *f)
{
	char *str = my_itoa((int)f->timer);
	sfVector2f pos;

	pos.x = f->idX + 20;
	pos.y = f->idY + 60;
	if (str == NULL)
		return (0);
	my_text_create(s->text.font, str, pos, window);
	pos.x -= 1;
	pos.y -= 1;
	my_text_create1(s->text.font, str, pos, window);
	free(str);
	return (0);
}

int furnace_update(sfRenderWindow *window, total_struct *s, furnace *f,
			bool print_timer)
{
	sfTime time;

	choose_music(s);
	if (f == NULL)
		return (0);
	time = sfClock_getElapsedTime(f->clock);
	if (time.microseconds >= 10000) {
		f->timer -= 0.01;
		sfClock_restart(f->clock);
	}
	if (f->timer <= 0 && f->food.burnable == false) {
		f->timer = 5.9;
		f->food.burnable = true;
	}
	if (f->timer <= 0 && f->food.burnable == true)
		f->food.id = 8192;
	if (print_timer == true && f->food.id != 8192)
		print_furnace_time(window, s, f);
	furnace_update(window, s, f->next, true);
	return (0);
}
