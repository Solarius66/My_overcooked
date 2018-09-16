/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include "declaration.h"

int main(void)
{
	total_struct *s;
	sfRenderWindow *window;
	int seed;

	read(open("/dev/urandom", O_RDONLY), &seed, sizeof seed);
	srand(seed);
	if (error_main() == 84)
		return (84);
	window = create_window();
	sfRenderWindow_clear(window, sfBlack);
	display_loading_screen(window);
	if ((s = texture_main(window)) == NULL)
		return (84);
	game_menu(window, s);
	destroy_all(s);
	sfRenderWindow_destroy(window);
}
