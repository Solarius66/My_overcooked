/*
** EPITECH PROJECT, 2018
** end.c
** File description:
** end
*/

#include "declaration.h"

void display_end_menu(total_struct *s, sfRenderWindow *window)
{
	sfRectangleShape *rect = sfRectangleShape_create();
	sfVector2f rect_pos = {200, 500};
	sfVector2f rect_size = {500, 250};
	sfVector2f pos_home = {840, 500};
	sfVector2f pos_quit = {840, 650};
	sfVector2f pos_homeT = {915, 525};
	sfVector2f pos_quitT = {915, 675};
	sfVector2f size = {240, 100};

	sfRectangleShape_destroy(create_rect(s, pos_home, size, window));
	sfRectangleShape_destroy(create_rect(s, pos_quit, size, window));
	text_create(s->text.font, "HOME", pos_homeT, window);
	text_create(s->text.font, "QUIT", pos_quitT, window);
	sfRectangleShape_setPosition(rect, rect_pos);
	sfRectangleShape_setSize(rect, rect_size);
	sfRectangleShape_setTexture(rect, s->text.button_shortOFF[0], sfTrue);
	sfRenderWindow_drawRectangleShape(window, rect, NULL);
	sfRectangleShape_destroy(rect);
}

int mouse_management_end(sfRenderWindow *window)
{
	sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

	if (mouse_pos.x > 840 && mouse_pos.x < 1080 &&
		mouse_pos.y > 500 && mouse_pos.y < 600 &&
		sfMouse_isButtonPressed(sfMouseLeft) == 1)
		return (1);
	else if (mouse_pos.x > 840 && mouse_pos.x < 1080 &&
			mouse_pos.y > 650 && mouse_pos.y < 750 &&
			sfMouse_isButtonPressed(sfMouseLeft) == 1)
		sfRenderWindow_close(window);
	return (0);
}

void display_score_end(character_struct *c, total_struct *s,
			sfRenderWindow *window)
{
	sfVector2f text_pos = {230, 575};
	sfVector2f score_pos = {530, 575};
	sfVector2f served_pos = {530, 625};
	char *score = my_itoa(c->served);
	char *served = my_itoa(20 - c->served);
	char *text = "Clients served :          /20\nClients missed :";

	text_create(s->text.font, text,	text_pos, window);
	text_create(s->text.font, score, score_pos, window);
	text_create(s->text.font, served, served_pos, window);
	free(score);
	free(served);
}

int end_dis(character_struct *c, sfRenderWindow *window, total_struct *s)
{
	if (c->score >= 0)
		return (0);
	create_pause_font(s->text.start[0], window);
	while (sfRenderWindow_isOpen(window)) {
		display_end_menu(s, window);
		display_score_end(c, s, window);
		sfRenderWindow_display(window);
		if (mouse_management_end(window) == 1)
			return (1);
		event_close(window);
	}
	return (1);
}
