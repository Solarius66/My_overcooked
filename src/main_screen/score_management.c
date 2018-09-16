/*
** EPITECH PROJECT, 2018
** score management
** File description:
** score management
*/

#include "declaration.h"

void display_score_star(sfRenderWindow *window, int score,
			sfTexture *texture)
{
	struct game_object *score_bar;
	sfVector2f pos;
	sfIntRect rect = set_rect(0, 213, 27);
	float posx = 10 * score - 142;


	pos.y = 197;
	pos.x = posx;
	score_bar = create_gameobject(texture, pos, rect);
	sfRenderWindow_drawSprite(window, score_bar->sprite, NULL);
	sfSprite_destroy(score_bar->sprite);
	free(score_bar);
}

void display_clients(sfRenderWindow *window, int score,
			total_struct *s)
{
	sfText *text = sfText_create();
	char *scoreT = my_itoa(score);
	sfVector2f pos = {80, 85};

	sfText_setString(text, scoreT);
	sfText_setFont(text, s->text.font);
	sfText_setCharacterSize(text, 34);
	sfText_setColor(text, sfWhite);
	sfText_setPosition(text, pos);
	sfRenderWindow_drawText(window, text, NULL);
	sfText_destroy(text);
	free(scoreT);
}
