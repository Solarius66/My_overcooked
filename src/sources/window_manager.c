/*
** EPITECH PROJECT, 2018
** window_manager
** File description:
** window manager
*/

#include "declaration.h"

sfRenderWindow *create_window(void)
{
	sfVideoMode mode = {1260, 840, 32};

	sfRenderWindow *window = sfRenderWindow_create(mode, "My_overCook",
							sfDefaultStyle, NULL);
	sfRenderWindow_setFramerateLimit(window, 60);
	return (window);
}

void event_manage_home(sfRenderWindow *window, struct full_buttons *buttons,
			total_struct *s)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
		event_click_menu(window, s, buttons, event);
	}
}

int event_manage_opt(sfRenderWindow *window, struct full_buttons *buttons,
			struct opt_textes *textes, total_struct *s)
{
	sfEvent event;
	int x = 0;

	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
		x = event_click_opt(s, buttons, event, textes);
	}
	return (x);
}

void event_close(sfRenderWindow *window)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
	}
}
