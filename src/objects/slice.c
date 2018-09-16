/*
** EPITECH PROJECT, 2018
** slice.c
** File description:
** slice.c
*/

#include "declaration.h"

void display_text_slice(sfRenderWindow *window, total_struct *s)
{
	sfVector2f pos = {480, 100};
	sfVector2f pos_button = {390, 220};
	sfVector2f size = {480, 200};

	text_create(s->text.font, "CLICK LEFT/RIGHT!", pos, window);
	sfRectangleShape_destroy(create_rect(s, pos_button, size, window));
}

void display_click_slice(int counter, total_struct *s, sfRenderWindow *window)
{
	char *text = my_itoa(counter);
	sfVector2f pos = {620, 300};

	text_create(s->text.font, text, pos, window);
	free(text);
}

int input_management_slice(total_struct *s, sfRenderWindow *window, int counter)
{
	static int left = 0;
	sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

	if (mouse_pos.x > 390 && mouse_pos.x < 870 && mouse_pos.y > 220 &&
		mouse_pos.y < 420 && sfMouse_isButtonPressed(sfMouseLeft) == 1
		&& sfMouse_isButtonPressed(sfMouseRight) == 0 && left == 0) {
		counter--;
		sound_effect(s, 's');
		left = 1;
	} else if (mouse_pos.x > 390 && mouse_pos.x < 870 && mouse_pos.y > 220
			&& mouse_pos.y < 420 && left == 1 &&
			sfMouse_isButtonPressed(sfMouseLeft) == 0 &&
			sfMouse_isButtonPressed(sfMouseRight) == 1) {
		counter--;
		sound_effect(s, 's');
		left = 0;
	}
	return (counter);
}

void slice_management(character_struct *c, sfRenderWindow *window,
			total_struct *s)
{
	int counter = 20;

	while (sfRenderWindow_isOpen(window)) {
		furnace_update(window, s, c->f, true);
		client_scrolling_main(c, window, s);
		if (c->food.sliceable == true)
			break;
		create_font(s->text.button_shortOFF[0], window);
		display_text_slice(window, s);
		counter = input_management_slice(s, window, counter);
		display_click_slice(counter, s, window);
		if (counter <= 0) {
			c->food.sliceable = true;
			break;
		}
		if (display_quit_game(s->text.font, window) == 1)
			break;
		sfRenderWindow_display(window);
		event_close(window);
	}
}
