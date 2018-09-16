/*
** EPITECH PROJECT, 2018
** my_overcooked
** File description:
** I burn!!! can't hold me now!!!
*/

#include "declaration.h"

int get_id_furnace(character_struct *c, char cbis)
{
	sfVector2f pos;

	if (c->look == 'u'){
		pos.x = c->pos.x;
		pos.y = c->pos.y - 86;
	}
	if (c->look == 'd') {
		pos.x = c->pos.x;
		pos.y = c->pos.y + 86;
	}
	if (c->look == 'l') {
		pos.x = c->pos.x - 64;
		pos.y = c->pos.y;
	} else if (c->look == 'r') {
		pos.x = pos.x + 64;
		pos.y = c->pos.y;
	}
	if (cbis == 'x')
		return (pos.x);
	return (pos.y);
}

void fill_furnace(total_struct *s, character_struct *c, furnace *f)
{
	f->food.texture = c->food.texture;
	f->food.name = c->food.name;
	f->food.id = c->food.id;
	f->food.sliceable = c->food.sliceable;
	f->food.burnable = c->food.burnable;
	c->food.texture = s->text.food_00[0];
	c->food.name = "Empty";
	c->food.id = 0;
	c->food.sliceable = true;
	c->food.burnable = true;
	f->clock = sfClock_create();
	f->idX = get_id_furnace(c, 'x');
	f->idY = get_id_furnace(c, 'y');
	f->timer = 15;
	f->next = NULL;
}

void create_furnace(total_struct *s, character_struct *c)
{
	furnace *f;

	f = c->f;
	while (true) {
		if (c->f == NULL) {
			c->f = malloc(sizeof(furnace));
			f = c->f;
			break;
		}
		if (f->next == NULL) {
			f->next = malloc(sizeof(furnace));
			f = f->next;
			break;
		}
		f = f->next;
	}
	fill_furnace(s, c, f);
}

int destroy_furnace(character_struct *c)
{
	furnace *backup = NULL;

	if (c->f->idX == get_id_furnace(c, 'x') &&
		c->f->idY == get_id_furnace(c, 'y')) {
		backup = c->f->next;
		kill_furnace(c, c->f);
		c->f = backup;
		return (0);
	}
	for (furnace *f = c->f ; true ; f = f->next) {
		if (f->next->idX == get_id_furnace(c, 'x') &&
			f->next->idY == get_id_furnace(c, 'y')) {
			backup = f->next->next;
			kill_furnace(c, f->next);
			f->next = backup;
			break;
		}
	}
	return (0);
}

int furnace_action(total_struct *s, character_struct *c)
{
	sfTime cooldown_time = sfClock_getElapsedTime(c->cooldown);

	if (cooldown_time.microseconds <= 1500000)
		return (0);
	if ((c->food.burnable == true || c->food.sliceable == false) &&
		c->food.id != 0) {
		sound_effect(s, 'e');
		return (0);
	}
	sfClock_restart(c->cooldown);
	for (furnace *f = c->f ; true ; f = f->next) {
		if (if_forest(s, c, f) == 1)
			return (0);
	}
	return (0);
}
