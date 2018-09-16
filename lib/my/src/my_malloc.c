/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** malloc into clean into cool.
*/

#include "../internal.h"

char *my_malloc(int size)
{
	char *str = malloc(sizeof(char) * (size + 1));

	clear_malloc(str, size);
	str[size] = 0;
	return (str);
}
