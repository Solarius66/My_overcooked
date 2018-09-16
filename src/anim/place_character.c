/*
** EPITECH PROJECT, 2018
** my_overcooked
** File description:
** placing character
*/

#include "declaration.h"

bool no_seg(character_struct *c, char *map)
{
	int count_percent = 0;

	for (int i = 0 ; map[i] ; ++i)
		if (map[i] == '%')
			++count_percent;
	if (count_percent == 3)
		return (true);
	c->pos.x = (64 * 7) + 300;
	c->pos.y = (86 * 5);
	return (false);
}

int is_correct(int i, char x_or_y)
{
	if (i > 14 && x_or_y == 'x')
		return (14);
	if (i > 9 && x_or_y == 'y')
		return (9);
	if (i < 0)
		return (0);
	return (i);
}

void place_charac(character_struct *c, char *map)
{
	int i;
	int save = 0;
	char *str;

	for (i = 0; map[i] != '%' ; ++i, save = i + 1);
	for (; map[save] != '%' ; ++save);
	str = my_malloc(save - i);
	++i;
	for (save = 0 ; map[i] != '%' ; ++save, ++i)
		str[save] = map[i];
	c->pos.x = (64 * is_correct(my_getnbr_long(str), 'x')) + 300;
	free(str);
	for (save = i + 1 ; map[save] != '%' ; ++save);
	str = my_malloc(save - i);
	++i;
	for (save = 0 ; map[i] != '%' ; ++i, ++save)
		str[save] = map[i];
	c->pos.y = (86 * is_correct(my_getnbr_long(str), 'y'));
	free(str);
}
