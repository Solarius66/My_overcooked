/*
** EPITECH PROJECT, 2018
** my_overcooked
** File description:
** checking map
*/

#include "declaration.h"

int is_good(char c)
{
	if ((c < 48 && c != '\n')|| c > 64) {
		my_puterr("invalid map tile.");
		return (-1);
	}
	if (c == '6')
		return (2);
	if (c == '7')
		return (3);
	if (c == '8')
		return (5);
	if (c == '9')
		return (7);
	if (c == ':')
		return (11);
	if (c == ';')
		return (13);
	if (c == '<')
		return (17);
	return (1);
}

bool is_good_map(int check)
{
	if (check % 2 == 0 && check % 3 == 0 && check % 5 == 0 &&
		check % 7 == 0 && check % 11 == 0 && check % 13 == 0 &&
		check % 17 == 0)
		return (true);
	if (check % 2 != 0)
		my_puterr("missing cutting board on map.\n");
	if (check % 3 != 0)
		my_puterr("missing sink on map.\n");
	if (check % 5 != 0)
		my_puterr("missing gas cooker and frying pan on map.\n");
	if (check % 7 != 0)
		my_puterr("missing gas cooker and pan on map.\n");
	if (check % 11 != 0)
		my_puterr("missing bin on map.\n");
	if (check % 13 != 0)
		my_puterr("missing service zone on map.\n");
	if (check % 17 != 0)
		my_puterr("missing fridge on map.\n");
	return (false);
}

int error_map(void)
{
	int fd = open("./maps/map.txt", O_RDONLY);
	int check = 1;
	char *str = malloc(sizeof(char) * 33);

	clear_malloc(str, 33);
	if (fd == -1)
		return (1);
	while (true) {
		if (read(fd, str, 32) <= 0)
			break;
		for (int i = 0 ; str[i] ; ++i)
			check *= is_good(str[i]);
		if (check < 0)
			return (1);
	}
	if (is_good_map(check) == true)
		return (0);
	my_puterr("map is not good.\n");
	return (1);
}
