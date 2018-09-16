/*
** EPITECH PROJECT, 2018
** my_overcooked
** File description:
** error
*/

#include "declaration.h"

int error_main(void)
{
	int error_nb = 0;

	error_nb += error_func();
	if (error_nb < 0)
		return (84);
	error_nb += error_music();
	error_nb += error_graph("char_", ".png", 0, 1);
	if (error_nb > 0) {
		my_puterr("Error: ");
		my_putnbr_err(error_nb);
		my_puterr(" error detected\n");
		my_puterr("please check if some files or lib are missing.\n");
		return (84);
	}
	my_printf("%s\n", "all assets found!");
	my_printf("%s\n", "launching game...");
	return (0);
}
