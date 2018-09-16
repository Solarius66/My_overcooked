/*
** EPITECH PROJECT, 2018
** define char
** File description:
** define char
*/

#include "declaration.h"

void display_font_char(sfTexture *texture, sfRenderWindow *window)
{
	sfVector2f size = {1260, 840};
	sfVector2f pos = {0, 0};
	sfRectangleShape *rect = sfRectangleShape_create();

	sfRectangleShape_setPosition(rect, pos);
	sfRectangleShape_setSize(rect, size);
	sfRectangleShape_setTexture(rect, texture, sfTrue);
	sfRenderWindow_drawRectangleShape(window, rect, NULL);
	sfRectangleShape_destroy(rect);
}

void display_rect_char(total_struct *s, int posx, int posy,
			sfRenderWindow *window)
{
	sfVector2f pos = {60 + 300 * posx, 200 + 300 * posy};
	sfVector2f size = {240, 200};

	sfRectangleShape_destroy(create_rect(s, pos, size, window));
}

void display_char(sfTexture *texture, int posx, int posy,
			sfRenderWindow *window)
{
	sfVector2f pos = {145 + 300 * posx, 270 + 300 * posy};
	sfVector2f size = {64, 86};
	sfRectangleShape *rect = sfRectangleShape_create();

	sfRectangleShape_setPosition(rect, pos);
	sfRectangleShape_setSize(rect, size);
	sfRectangleShape_setTexture(rect, texture, sfTrue);
	sfRenderWindow_drawRectangleShape(window, rect, NULL);
	sfRectangleShape_destroy(rect);
}
void display_chars(total_struct *s, sfRenderWindow *window)
{
	display_rect_char(s, 0, 0, window);
	display_rect_char(s, 1, 0, window);
	display_rect_char(s, 2, 0, window);
	display_rect_char(s, 3, 0, window);
	display_rect_char(s, 0, 1, window);
	display_rect_char(s, 1, 1, window);
	display_rect_char(s, 2, 1, window);
	display_rect_char(s, 3, 1, window);
	display_char(s->text.char_1[1], 0, 0, window);
	display_char(s->text.char_2[1], 1, 0, window);
	display_char(s->text.char_3[1], 2, 0, window);
	display_char(s->text.char_4[1], 3, 0, window);
	display_char(s->text.char_5[1], 0, 1, window);
	display_char(s->text.char_6[1], 1, 1, window);
	display_char(s->text.char_7[1], 2, 1, window);
	display_char(s->text.char_8[1], 3, 1, window);
}

int define_char_used(total_struct *s, sfRenderWindow *window)
{
	int character = 0;
	sfClock *clock = sfClock_create();

	while (sfRenderWindow_isOpen(window) && character == 0) {
		sfRenderWindow_clear(window, sfBlack);
		display_font_char(s->text.backg[0], window);
		display_chars(s, window);
		sfRenderWindow_display(window);
		while (sfClock_getElapsedTime(clock).microseconds < 500000);
		character = define_char_used_click(window);
		event_close(window);
	}
	sfClock_destroy(clock);
	if (character == 0)
		return (1);
	return (character);
}
