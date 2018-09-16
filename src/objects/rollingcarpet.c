/*
** EPITECH PROJECT, 2018
** rollingcarpet
** File description:
** rolligncarpet
*/

#include "declaration.h"

void rolling_carpet_management(character_struct *c, total_struct *s)
{
	int x = 0;

	while (x != 6) {
		if (c->food.id == c->clients->client[x].id) {
			c->score--;
			c->served++;
			sfClock_destroy(c->clients->client[x].clock);
			create_client(c->clients, x, s);
			sound_effect(s, 'b');
			destroy_food(c, s);
			c->plates--;
			break;
		} else
			x++;
	}
	if (x == 6 && c->food.id != 0) {
		c->score--;
		c->plates--;
		sound_effect(s, 'e');
		destroy_food(c, s);
	}
}
