/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** 2 month later :D
*/

#include "../internal.h"

void switch_manage(va_list list, char c)
{
	switch (c) {
		case 'S':
		case 's':
			my_putstr(va_arg(list, char *));
			break;
		case 'i':
		case 'd':
			my_putnbr(va_arg(list, int));
			break;
		case 'F':
		case 'f':
			my_putfloat(va_arg(list, double));
			break;
		case '%':
			my_putstr("%");
			break;
		default:
			my_puterr("unknown flag\n");
	}
}

int my_printf(char *str, ...)
{
	va_list list;

	va_start(list, str);
	if (str == NULL) {
		my_putstr(NULL);
		return (0);
	}
	for (int i = 0 ; str[i] ; ++i) {
		if (str[i] == '%') {
			++i;
			switch_manage(list, str[i]);
		} else
			write(1, &str[i], 1);
	}
	va_end(list);
	return (0);
}
