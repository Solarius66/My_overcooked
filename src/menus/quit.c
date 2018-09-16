/*
** EPITECH PROJECT, 2018
** quit.c
** File description:
** quit
*/

#include "declaration.h"

void text_create(sfFont *font, char *sentence, sfVector2f pos,
			sfRenderWindow *window)
{
	sfText *text = sfText_create();

	sfText_setString(text, sentence);
	sfText_setFont(text, font);
	sfText_setCharacterSize(text, 30);
	sfText_setColor(text, sfBlack);
	sfText_setPosition(text, pos);
	sfRenderWindow_drawText(window, text, NULL);
	sfText_destroy(text);
}

void text_display_quit(sfFont *font, sfRenderWindow *window)
{
	sfVector2f pos_ask = {530, 350};
	sfVector2f pos_noT = {525, 430};
	sfVector2f pos_yesT = {665, 430};

	text_create(font, "Are you sure?", pos_ask, window);
	text_create(font, "YES", pos_yesT, window);
	text_create(font, "NO", pos_noT, window);
}

sfRectangleShape *create_rect(total_struct *s, sfVector2f pos,
				sfVector2f size, sfRenderWindow *window)
{
	sfRectangleShape *rectangle = sfRectangleShape_create();

	sfRectangleShape_setPosition(rectangle, pos);
	sfRectangleShape_setSize(rectangle, size);
	define_color_buttons_short(window, rectangle, s);
	sfRenderWindow_drawRectangleShape(window, rectangle, NULL);
	return (rectangle);
}

int define_click_quit(sfRenderWindow *window)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed) {
			sfRenderWindow_close(window);
			return (1);
		}
		return (button_is_clicked_quit(window));
	}
	return (0);
}

void really_quit(sfRenderWindow *window, total_struct *s)
{
	sfVector2f pos_no = {500, 420};
	sfVector2f pos_yes = {650, 420};
	sfVector2f pos_rect = {430, 320};
	sfVector2f size_rect = {400, 200};
	sfVector2f size_button = {100, 50};
	int bool = 0;
	sfRectangleShape *rect = create_rect(s, pos_rect, size_rect, window);

	while (bool == 0) {
		sfRectangleShape_destroy(create_rect(s, pos_no,
			size_button, window));
		sfRectangleShape_destroy(create_rect(s, pos_yes,
			size_button, window));
		text_display_quit(s->text.font, window);
		sfRenderWindow_display(window);
		bool = define_click_quit(window);
	}
	sfRectangleShape_destroy(rect);
}
