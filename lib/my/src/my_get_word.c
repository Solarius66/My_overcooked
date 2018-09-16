/*
** EPITECH PROJECT, 2018
** lib
** File description:
** get_words
*/

#include "../internal.h"

char *one_space(char *str, char space)
{
	char *sol = malloc(sizeof(char) * my_strlen(str));
	int i = 0;

	clear_malloc(sol, my_strlen(str));
	for (int j = 0 ; str[j] ; ++j) {
		if (str[j] == space && str[j] + 1 == space);
		else {
			sol[i] = str[j];
			++i;
		}
	}
	return (sol);
}

int replace_charac(char *str, char space)
{
	for (int i = 0 ; str[i] ; ++i)
		if ((str[i] < 31 && str[i] != '\n') || str[i] == 127)
			str[i] == space;
	return (0);
}

char **my_get_words(char *str, char space, int consider_special_as_space)
{
	char **sol;

	if (consider_special_as_space == 1)
		replace_charac(str, space);
	one_space(str, space);
}
