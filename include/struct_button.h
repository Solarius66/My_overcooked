/*
** EPITECH PROJECT, 2018
** struct button
** File description:
** dtruct button
*/

#ifndef STRUCT_BUTTON_H_
#define STRUCT_BUTTON_H_

struct full_buttons {
	struct main_buttons *main;
	struct opt_buttons *opt;
};

struct main_buttons {
	sfRectangleShape *play;
	sfRectangleShape *opt;
	sfRectangleShape *quit;
};

struct opt_buttons {
	sfRectangleShape *window_size;
	sfRectangleShape *music;
	sfRectangleShape *how2play;
	sfRectangleShape *quit;
};

#endif /* ! STRUCT_BUTTON_H_ */
