/*
** EPITECH PROJECT, 2018
** client filling
** File description:
** client filling
*/

#include "declaration.h"

void client_set(clients_full *clients, int nbr_client, sfTexture *texture,
		int id)
{
	sfVector2f pos = {200, nbr_client * 100 + 240};

	clients->client[nbr_client].id = id;
	clients->client[nbr_client].pos = pos;
	clients->client[nbr_client].texture = texture;
	sfClock_restart(clients->client[nbr_client].clock);
}

void client_filling(clients_full *clients, int nbr_client, total_struct *s)
{
	if (clients->client[nbr_client].id == 0)
		client_set(clients, nbr_client, s->text.dish_3[0], 21);
	if (clients->client[nbr_client].id == 1)
		client_set(clients, nbr_client, s->text.dish_4[0], 40);
	if (clients->client[nbr_client].id == 2)
		client_set(clients, nbr_client, s->text.dish_6[0], 136);
	if (clients->client[nbr_client].id == 3)
		client_set(clients, nbr_client, s->text.dish_5[0], 522);
	if (clients->client[nbr_client].id == 4)
		client_set(clients, nbr_client, s->text.dish_1[0], 2115);
	if (clients->client[nbr_client].id == 5)
		client_set(clients, nbr_client, s->text.dish_2[0], 5377);
}

void client_scrollbis(character_struct *c, int nb)
{
	sfInt64 time = sfClock_getElapsedTime(
			c->clients->client[nb].clock).microseconds;

	if (time > 500000) {
		c->clients->client[nb].pos.x =
			c->clients->client[nb].pos.x - 1;
		sfClock_restart(c->clients->client[nb].clock);
	}
}

void client_scroll(character_struct *c, int nb, sfRenderWindow *window,
			total_struct *s)
{
	sfRectangleShape *rect = sfRectangleShape_create();
	sfVector2f size = {100, 100};

	client_scrollbis(c, nb);
	sfRectangleShape_setPosition(rect, c->clients->client[nb].pos);
	sfRectangleShape_setSize(rect, size);
	sfRectangleShape_setTexture(rect, c->clients->client[nb].texture,
					sfTrue);
	sfRenderWindow_drawRectangleShape(window, rect, NULL);
	sfRectangleShape_destroy(rect);
	if (c->clients->client[nb].pos.x <= -100 &&
		c->clients->client[nb].id != -42) {
		sfClock_destroy(c->clients->client[nb].clock);
		create_client(c->clients, nb, s);
		c->score--;
	}
}

void client_scrolling_main(character_struct *c, sfRenderWindow *window,
				total_struct *s)
{
	client_scroll(c, 0, window, s);
	client_scroll(c, 1, window, s);
	client_scroll(c, 2, window, s);
	client_scroll(c, 3, window, s);
	client_scroll(c, 4, window, s);
	client_scroll(c, 5, window, s);
}
