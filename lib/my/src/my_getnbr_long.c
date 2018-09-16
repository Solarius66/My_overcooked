/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** my_getnbr
*/

#include "../internal.h"

int ___neg_gest___(char c, int *is_neg)
{
	if (c == 45)
		*is_neg = *is_neg * (-1);
	else if (c == 43);
	else
		return (-1);
	return (1);
}

long long my_getnbr_long(char *str)
{
	int is_neg = 1;
	long long soluce = 0;

	for (int i = 0 ; 1 ; ++i) {
		if (str[i] < 48 || str[i] > 57 || str[i] == 0) {
			if (___neg_gest___(str[i], &is_neg) == -1) {
				soluce = soluce * is_neg;
				return (soluce);
			}
			++i;
		}
		soluce = soluce + str[i] - 48;
		if (soluce > 2147483647 || soluce < -2147483648) {
			my_puterr("error, int overflow\n");
			return (84000000000);
		}
		if (str[i + 1])
			soluce = soluce * 10;
	}
	return (0);
}
