/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** my_putstr
*/

#include "../internal.h"

int my_putstr(char *str)
{
	if (str == NULL) {
		write(1, "(NULL)\n", 7);
		return (84);
	}
	write(1, str, my_strlen(str));
	return (0);
}
