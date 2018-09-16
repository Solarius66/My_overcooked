/*
** EPITECH PROJECT, 2018
** mysh
** File description:
** compare str
*/

#include "../internal.h"
#define ___true___ 1
#define ___false___ 0


int my_compare_str(char *str, char *str2)
{
	int i = 0;
	int j = 0;

	while (str[i]) {
		if (str[i] != str2[i])
			return (___false___);
		if (str2[i] == 0)
			return (___false___);
		++i;
	}
	return (___true___);
}
