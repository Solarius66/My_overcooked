/*
** EPITECH PROJECT, 2018
** define map used
** File description:
** define map used
*/

#include "declaration.h"

char **define_names_maps_2(FILE *stream, char **maps)
{
	size_t len = 1;
	ssize_t read = 0;
	char *lines = NULL;
	int x = 0;

	while (read != -1) {
		read = getline(&lines, &len, stream);
		maps[x] = my_malloc(read + 1);
		for (int y = 0; y < read - 1; y++)
			maps[x][y] = lines[y];
		x++;
	}
	x--;
	while (x != 8) {
		maps[x] = fusion_str("Empty", " ");
		x++;
	}
	free(lines);
	return(maps);
}

char **define_names_maps(void)
{
	FILE *stream = fopen("./maps/maps_names.txt", "r");
	char **maps = malloc(sizeof(char *) * 8);

	if (stream == NULL) {
		my_puterr("FILE NOT FOUND\n");
		return (NULL);
	}
	maps = define_names_maps_2(stream, maps);
	return (maps);
}

sfVector2f define_pos_map(int x, int y)
{
	sfVector2f pos = {x * 305 + 110, 270 + 300 * y};

	return(pos);
}

void create_buttons_map(sfRenderWindow *window, total_struct *s, char **maps)
{
	display_font_char(s->text.backg[0], window);
	display_rect_char(s, 0, 0, window);
	display_rect_char(s, 1, 0, window);
	display_rect_char(s, 2, 0, window);
	display_rect_char(s, 3, 0, window);
	display_rect_char(s, 0, 1, window);
	display_rect_char(s, 1, 1, window);
	display_rect_char(s, 2, 1, window);
	display_rect_char(s, 3, 1, window);
	text_create(s->text.font, maps[0], define_pos_map(0, 0), window);
	text_create(s->text.font, maps[1], define_pos_map(1, 0), window);
	text_create(s->text.font, maps[2], define_pos_map(2, 0), window);
	text_create(s->text.font, maps[3], define_pos_map(3, 0), window);
	text_create(s->text.font, maps[4], define_pos_map(0, 1), window);
	text_create(s->text.font, maps[5], define_pos_map(1, 1), window);
	text_create(s->text.font, maps[6], define_pos_map(2, 1), window);
	text_create(s->text.font, maps[7], define_pos_map(3, 1), window);
}
