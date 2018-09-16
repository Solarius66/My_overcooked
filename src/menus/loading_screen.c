/*
** EPITECH PROJECT, 2018
** loading screen
** File description:
** load screen
*/

#include "declaration.h"

void display_loading_screen(sfRenderWindow *window)
{
	sfTexture *texture = sfTexture_createFromFile("./textures/load.png",
							NULL);
	sfVector2f pos = {0, 0};
	sfIntRect rect = set_rect(0, 1260, 840);
	struct game_object *loading = create_gameobject(texture, pos, rect);

	sfRenderWindow_clear(window, sfWhite);
	sfRenderWindow_drawSprite(window, loading->sprite, NULL);
	sfRenderWindow_display(window);
	sfSprite_destroy(loading->sprite);
	free(loading);
	sfTexture_destroy(texture);
}
