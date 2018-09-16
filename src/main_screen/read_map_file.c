/*
** EPITECH PROJECT, 2017
** read file map
** File description:
** read a txt file and create a string
*/

#include "declaration.h"

int define_map_size(char *file)
{
	struct stat map_stat;

	stat(file, &map_stat);
	return(map_stat.st_size);
}

char *define_map_string(char *file, int size, char *map_string)
{
	FILE *stream = fopen(file, "r");
	size_t len = 1;
	ssize_t read = 0;
	char *line = NULL;

	if (stream == NULL)
		stream = fopen("./maps/.lvl0", "r");
	for (int y = 0 ; y < size ;) {
		read = getline(&line, &len, stream);
		if (read == -1)
			return (NULL);
		for (int x = 0 ; x < read ; x++, ++y)
			map_string[y] = line[x];
	}
	free(line);
	fclose(stream);
	free(file);
	return (map_string);
}

char *define_map_used(sfRenderWindow *window, total_struct *s)
{
	char **maps = define_names_maps();
	int x = -1;
	sfClock *clock = sfClock_create();
	char *map;

	while (sfRenderWindow_isOpen(window) && x < 0) {
		create_buttons_map(window, s, maps);
		while(sfClock_getElapsedTime(clock).microseconds < 500000);
		x = define_char_used_click(window) - 1;
		sfRenderWindow_display(window);
		event_close(window);
	}
	sfClock_destroy(clock);
	map = fusion_str("./maps/", maps[x]);
	for (int y = 0; y < 8; y++)
		free(maps[y]);
	free(maps);
	return (map);
}

char *read_map_file(sfRenderWindow *window, total_struct *s)
{
	char *map_string;
	int size;
	char *file = define_map_used(window, s);

	size = define_map_size(file);
	map_string = malloc(sizeof(char) * size + 1);
	if (map_string == NULL)
		return (NULL);
	map_string[size] = 0;
	define_map_string(file, size, map_string);
	return (map_string);
}
