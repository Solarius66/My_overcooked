/*
** EPITECH PROJECT, 2018
** my_overcooked
** File description:
** does texture exist
*/

#include "declaration.h"
#define TEXTURE_PATH "./textures/"

int deadly_error_sins3(void)
{
	int error_count = 0;

	if (open("./textures/button_longON.png", O_RDONLY) == -1) {
		my_puterr("error: button_longON.png is missing.\n");
		++error_count;
	}
	if (open("./textures/button_shortON.png", O_RDONLY) == -1) {
		my_puterr("error: button_shortON.png is missing.\n");
		++error_count;
	}
	if (open("./textures/button_shortOFF.png", O_RDONLY) == -1) {
		my_puterr("error: button_shortOFF.png is missing.\n");
		++error_count;
	}
	if (open("./textures/tuto.png", O_RDONLY) == -1) {
		my_puterr("error: tuto.png is missing.\n");
		++error_count;
	}
	return (error_count);
}

int deadly_error_sins2(void)
{
	int error_count = 0;

	if (open("./textures/map_tiles.png", O_RDONLY) == -1) {
		my_puterr("error: map_tiles.png is missing.\n");
		++error_count;
	}
	if (open("./textures/pause.png", O_RDONLY) == -1) {
		my_puterr("error: pause.png is missing.\n");
		++error_count;
	}
	if (open("./textures/start.png", O_RDONLY) == -1) {
		my_puterr("error: start.png is missing.\n");
		++error_count;
	}
	if (open("./textures/load.png", O_RDONLY) == -1) {
		my_puterr("error: load.png is missing.\n");
		++error_count;
	}
	return (error_count + deadly_error_sins3());
}

int deadly_error_sins(void)
{
	int error_count = 0;

	if (open("./textures/backg.png", O_RDONLY) == -1) {
		my_puterr("error: backg.png is missing.\n");
		++error_count;
	}
	if (open("./textures/button_longOFF.png", O_RDONLY) == -1) {
		my_puterr("error: button_longOFF.png is missing.\n");
		++error_count;
	}
	if (open("./textures/dish_dirty.png", O_RDONLY) == -1) {
		my_puterr("error: dish_dirty.png is missing.\n");
		++error_count;
	}
	if (open("./textures/dish_empty.png", O_RDONLY) == -1) {
		my_puterr("error: dish_empty.png is missing.\n");
		++error_count;
	}
	return (error_count + deadly_error_sins2());
}

int is_openable(char *str, char *str2, int i)
{
	char *nbr = my_itoa(i);
	char *sol = fusion_str(str, nbr);
	char *save = sol;

	sol = fusion_str(sol, str2);
	free(save);
	save = sol;
	sol = fusion_str(TEXTURE_PATH, sol);
	if (open(sol, O_RDONLY) < 3) {
		my_puterr("error: ");
		my_puterr(save);
		my_puterr(" is missing.\n");
		free(save);
		free(sol);
		return (1);
	}
	free(save);
	free(sol);
	free(nbr);
	return (0);
}

int error_graph(char *str, char *str2, int error_count, int i)
{
	error_count += is_openable(str, str2, i);
	if (my_compare_str(str, "char_") == 1 && i == 8)
		return (error_graph("dish_", ".png", error_count, 1));
	if (my_compare_str(str, "dish_") == 1 && i == 7)
		return (error_graph("food_0", ".png", error_count, 1));
	if (my_compare_str(str, "food_0") == 1 && i == 6)
		return (error_graph("food_", ".png", error_count, 11));
	if (my_compare_str(str, "food_") == 1 && i == 14)
		return (error_graph("food_", ".png", error_count, 21));
	if (my_compare_str(str, "food_") == 1 && i == 23)
		return (error_count += deadly_error_sins());
	error_count = error_graph(str, str2, error_count, i + 1);
	return (error_count);
}
