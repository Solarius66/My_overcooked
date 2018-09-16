/*
** EPITECH PROJECT, 2018
** okay
** File description:
** RAAAAAAH
*/

#include "../internal.h"

char *fusion_str(char *str, char *str2)
{
	int j = 0;
	int size1 = my_strlen(str);
	int size2 = my_strlen(str2);
	int size = size1 + size2;
	char *sol = malloc(sizeof(char) * (size + 1));

	clear_malloc(sol, size);
	if (sol == NULL)
		return (NULL);
	for (int i = 0 ; str[i] ; ++i, ++j)
		sol[j] = str[i];
	for (int i = 0 ; str2[i] ; ++i, ++j)
		sol[j] = str2[i];
	sol[size] = 0;
	return (sol);
}
