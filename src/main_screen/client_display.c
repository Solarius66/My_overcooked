/*
** EPITECH PROJECT, 2018
** client display
** File description:
** client display
*/

#include "declaration.h"

void create_client(clients_full *clients, int nbr_client, total_struct *s)
{
	sfVector2f pos = {0, 0};

	clients->client[nbr_client].id = -42;
	clients->client[nbr_client].pos = pos;
	clients->client[nbr_client].texture = s->text.food_00[0];
	clients->client[nbr_client].clock = NULL;
	clients->client[nbr_client].clock = sfClock_create();
}

clients_full *create_client_struct(total_struct *s)
{
	clients_full *clients = malloc(sizeof(clients_full));

	create_client(clients, 0, s);
	create_client(clients, 1, s);
	create_client(clients, 2, s);
	create_client(clients, 3, s);
	create_client(clients, 4, s);
	create_client(clients, 5, s);
	clients->clock = sfClock_create();
	return (clients);
}

void client_fill(clients_full *clients, int nbr_client, total_struct *s)
{
	clients->client[nbr_client].id = rand() % 6;
	client_filling(clients, nbr_client, s);
}

void generate_client(clients_full *clients, total_struct *s)
{
	int x = 0;

	while (x != 6) {
		if (clients->client[x].id == -42) {
			client_fill(clients, x, s);
			break;
		} else
			x++;
	}
}

void client_management(character_struct *c, total_struct *s,
			sfRenderWindow *window)
{
	sfInt64 time = sfClock_getElapsedTime(c->clients->clock).microseconds;

	if (s->first_client != 1) {
		generate_client(c->clients, s);
		s->first_client = 1;
	}
	if (time >= 50000000) {
		generate_client(c->clients, s);
		sfClock_restart(c->clients->clock);
	}
	client_scrolling_main(c, window, s);
}
