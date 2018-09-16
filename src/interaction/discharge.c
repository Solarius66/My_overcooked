/*
** EPITECH PROJECT, 2018
** my_overcooked
** File description:
** discharge EVERYTHING in game_loop
*/

#include "declaration.h"

void discharge_furnace(character_struct *c)
{
	for (furnace *f = c->f ; c->f != NULL ;) {
		if (c->f->next == NULL) {
			sfClock_destroy(f->clock);
			free(c->f);
			c->f = NULL;
		} else if (f->next->next == NULL) {
			sfClock_destroy(f->next->clock);
			free(f->next);
			f->next = NULL;
			f = c->f;
		} else
			f = f->next;
	}
}

void discharge_character(character_struct *c)
{
	discharge_furnace(c);
	sfSprite_destroy(c->sprite);
	sfClock_destroy(c->clock);
	sfClock_destroy(c->cooldown);
	sfClock_destroy(c->clients->clock);
	for (int i = 0 ; i < 6 ; ++i)
		sfClock_destroy(c->clients->client[i].clock);
	free(c->clients);
	free(c->map);
	free(c);
}

void discharge_main(total_struct *s, character_struct *c, machine_struct *m)
{
	free(m);
	discharge_character(c);
	sfMusic_pause(s->sound.actual);
	sfMusic_play(s->sound.menu);
}
