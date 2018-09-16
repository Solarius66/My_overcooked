/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** my_puterr
*/

#include "../internal.h"

int my_puterr(char *str)
{
	write(2, str, my_strlen(str));
	return (0);
}
