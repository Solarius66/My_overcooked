/*
** EPITECH PROJECT, 2018
** create map
** File description:
** create the map on the screen
*/

#include "declaration.h"

int define_block_type(char c)
{
	int x = 48;

	while (x < c)
		x++;
	if (x > 65)
		return (0);
	x = x - 48;
	return (x);
}

sfSprite *create_tile(int x, int y, int spr_type, sfTexture *texture)
{
	sfVector2f pos = {x * 64 + 300, y * 86};
	sfIntRect rect = set_rect(64 * spr_type, 64, 86);
	struct game_object *block = create_gameobject(texture, pos, rect);
	sfSprite *sprite = block->sprite;

	free(block);
	return (sprite);
}

side_char *define_side_char(sfVector2f pos, char *map_string)
{
	int pos_x = (pos.x - 256) / 64;
	int pos_y = pos.y / 86;
	side_char *s_char = malloc(sizeof(struct side_char));
	int pos_char = pos_y * 16 + pos_x;

	s_char->top = map_string[pos_char - 16] - 48;
	if (s_char->top < 0 || s_char->top > 14)
		s_char->top = 1;
	s_char->bot = map_string[pos_char + 16] - 48;
	if (s_char->bot < 0 || s_char->bot > 14)
		s_char->bot = 1;
	s_char->right = map_string[pos_char + 1] - 48;
	if (s_char->right < 0 || s_char->right > 14)
		s_char->right = 1;
	s_char->left = map_string[pos_char - 1] - 48;
	if (s_char->left < 0 || s_char->left > 14)
		s_char->left = 1;
	return (s_char);
}

void create_map(char *map_string, sfRenderWindow *window,
		sfTexture *texture)
{
	int i = 0;
	int x = 0;
	int y = 0;
	int spr_type;
	sfSprite *sprite;

	while (map_string[i] != '\0') {
		if (map_string[i] != '\n') {
			spr_type = define_block_type(map_string[i]);
			sprite = create_tile(x, y, spr_type, texture);
			sfRenderWindow_drawSprite(window, sprite, NULL);
			sfSprite_destroy(sprite);
			x++;
		} else {
			y++;
			x = 0;
		}
		i++;
	}
}
