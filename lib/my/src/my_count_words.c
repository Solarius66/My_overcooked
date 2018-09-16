/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** my count words
*/

#include "../internal.h"

int my_count_words(char *str, char space)
{
	int word_nb = 0;

	if (str[0] != space && str[0] != 0)
		++word_nb;
	for (int i = 0 ; str[i] ; ++i) {
		if (str[i] == space && str[i + 1] != space &&
			str[i + 1])
			++word_nb;
	}
	return (word_nb);
}
