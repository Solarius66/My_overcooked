/*
** EPITECH PROJECT, 2018
** my_overcooked
** File description:
** a bottle of wine? from a space bar!
*/

#include "declaration.h"

void my_text_create(sfFont *font, char *sentence, sfVector2f pos,
			sfRenderWindow *window)
{
	sfText *text = sfText_create();

	sfText_setString(text, sentence);
	sfText_setFont(text, font);
	sfText_setCharacterSize(text, 14);
	sfText_setColor(text, sfWhite);
	sfText_setPosition(text, pos);
	sfRenderWindow_drawText(window, text, NULL);
	sfText_destroy(text);
}

void my_text_create1(sfFont *font, char *sentence, sfVector2f pos,
			sfRenderWindow *window)
{
	sfText *text = sfText_create();

	sfText_setString(text, sentence);
	sfText_setFont(text, font);
	sfText_setCharacterSize(text, 14);
	sfText_setColor(text, sfRed);
	sfText_setPosition(text, pos);
	sfRenderWindow_drawText(window, text, NULL);
	sfText_destroy(text);
}

void space_press(total_struct *s, int i, character_struct *c,
			sfRenderWindow *window)
{
	sfVector2f pos;

	pos.x = c->pos.x - 20;
	pos.y = c->pos.y + 70;
	if (i == -1 && c->look_tile > 5 && c->look_tile < 14) {
		my_text_create(s->text.font, "PRESS SPACE!", pos, window);
		pos.x -= 1;
		pos.y -= 1;
		my_text_create1(s->text.font, "PRESS SPACE!", pos, window);
	}
}
