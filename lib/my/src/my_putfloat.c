/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** putfloat
*/

#include "../internal.h"

int my_pow(int nb, int pw)
{
	int save = nb;

	for (int i = 0 ; i < pw ; ++i)
		nb = nb * save;
	return (nb);
}

char *my_dtoa(double i)
{
	int length = length_nb(i);
	char *str = my_malloc((length + 7));
	int save = 0;

	if (i == 0)
		return ("0.0");
	str = my_malloc((length + 7));
	if (str == NULL)
		return (NULL);
	if (i < 0)
		str[0] = '-';
	for (int j = 6 ; j > 0 ; --j)
		str[length + j] = ((int)(i * my_pow(10, j - 1)) % 10) + 48;
	str[length] = '.';
	for (int j = 1 ; i >= 1 ; ++j) {
		save = (int)i % 10;
		i = i / 10.0;
		str[length - j] = (save + 48);
	}
	return (str);
}

int my_putfloat_err(double i)
{
	char *str = my_dtoa(i);

	my_puterr(str);
	if (str != NULL && i != 0.0)
		free(str);
	return (0);
}

int my_putfloat(double i)
{
	char *str = my_dtoa(i);

	my_putstr(str);
	if (str != NULL && i != 0.0)
		free(str);
	return (0);
}
