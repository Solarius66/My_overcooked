/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** strlen
*/

#include "../internal.h"

int my_strlen(char *str)
{
	int length = 0;

	if (str == NULL)
		return (-84);
	for (length = 0 ; str[length] ; ++length);
	return (length);
}
