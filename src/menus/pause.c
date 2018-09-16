/*
** EPITECH PROJECT, 2018
** pause
** File description:
** pause
*/

#include "declaration.h"

void create_pause_font(sfTexture *texture, sfRenderWindow *window)
{
	sfRectangleShape *rect = sfRectangleShape_create();
	sfVector2f pos = {0, 0};
	sfVector2f size = {1260, 840};

	sfRectangleShape_setPosition(rect, pos);
	sfRectangleShape_setSize(rect, size);
	sfRectangleShape_setTexture(rect, texture, sfTrue);
	sfRenderWindow_drawRectangleShape(window, rect, NULL);
	sfRectangleShape_destroy(rect);
}

void create_button_pause(total_struct *s, sfRenderWindow *window)
{
	sfVector2f pos_resume = {380, 370};
	sfVector2f pos_home = {380, 500};
	sfVector2f pos_quit = {640, 500};
	sfVector2f size_s = {240, 100};
	sfVector2f size_l = {500, 100};
	sfVector2f pos_resumeT = {550, 400};
	sfVector2f pos_homeT = {450, 525};
	sfVector2f pos_quitT = {715, 525};
	sfRectangleShape *resume = create_button(s->text.button_longOFF[0],
							pos_resume, size_l);

	define_color_buttons_long(window, resume, s);
	sfRenderWindow_drawRectangleShape(window, resume, NULL);
	sfRectangleShape_destroy(create_rect(s, pos_home, size_s, window));
	sfRectangleShape_destroy(create_rect(s, pos_quit, size_s, window));
	text_create(s->text.font, "RESUME", pos_resumeT, window);
	text_create(s->text.font, "HOME", pos_homeT, window);
	text_create(s->text.font, "QUIT", pos_quitT, window);
	sfRectangleShape_destroy(resume);
}

void display_pause_menu(total_struct *s, sfRenderWindow *window)
{
	create_button_pause(s, window);
}

int mouse_management_pause(sfRenderWindow *window)
{
	sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

	if (mouse_pos.x > 380 && mouse_pos.x < 880 &&
		mouse_pos.y > 370 && mouse_pos.y < 470 &&
		sfMouse_isButtonPressed(sfMouseLeft) == 1)
		return (2);
	else if (mouse_pos.x > 380 && mouse_pos.x < 620 &&
			mouse_pos.y > 500 && mouse_pos.y < 600 &&
			sfMouse_isButtonPressed(sfMouseLeft) == 1)
		return (1);
	else if (mouse_pos.x > 640 && mouse_pos.x < 880 &&
			mouse_pos.y > 500 && mouse_pos.y < 600 &&
			sfMouse_isButtonPressed(sfMouseLeft) == 1)
		sfRenderWindow_close(window);
	return (0);
}

int pause_main(total_struct *s, sfRenderWindow *window)
{
	if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfFalse)
		return (0);
	create_pause_font(s->text.pause[0], window);
	while (sfRenderWindow_isOpen(window) && true) {
		choose_music(s);
		display_pause_menu(s, window);
		sfRenderWindow_display(window);
		if (mouse_management_pause(window) == 1)
			return (1);
		else if (mouse_management_pause(window) == 2)
			return (2);
		event_close(window);
	}
	return (0);
}
