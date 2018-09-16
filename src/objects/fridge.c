/*
** EPITECH PROJECT, 2018
** fridge
** File description:
** fridge
*/

#include "declaration.h"

void create_font(sfTexture *texture, sfRenderWindow *window)
{
	sfVector2f pos = {60, 20};
	sfVector2f size = {1140, 500};
	sfRectangleShape *rectangle = sfRectangleShape_create();

	sfRectangleShape_setPosition(rectangle, pos);
	sfRectangleShape_setSize(rectangle, size);
	sfRectangleShape_setTexture(rectangle, texture, sfTrue);
	sfRenderWindow_drawRectangleShape(window, rectangle, NULL);
	sfRectangleShape_destroy(rectangle);
}

void create_buttons_page(sfRenderWindow *window, total_struct *s)
{
	sfVector2f pos_1 = {60, 520};
	sfVector2f pos_1t = {120, 550};
	sfVector2f pos_2 = {300, 520};
	sfVector2f pos_2t = {365, 550};
	sfVector2f pos_3 = {540, 520};
	sfVector2f pos_3t = {600, 550};
	sfVector2f size = {240, 100};
	sfRectangleShape *one = create_rect(s, pos_1, size, window);
	sfRectangleShape *two = create_rect(s, pos_2, size, window);
	sfRectangleShape *three = create_rect(s, pos_3, size, window);

	sfRectangleShape_destroy(one);
	sfRectangleShape_destroy(two);
	sfRectangleShape_destroy(three);
	text_create(s->text.font, "Veggies", pos_1t , window);
	text_create(s->text.font, "Meets", pos_2t, window);
	text_create(s->text.font, "Others", pos_3t, window);
}

int define_button_click_fridge(sfRenderWindow *window, int page)
{
	sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

	if (mouse_pos.x > 60 && mouse_pos.x < 300 &&
		mouse_pos.y > 520 && mouse_pos.y < 620 &&
		sfMouse_isButtonPressed(sfMouseLeft) == 1)
		return (1);
	if (mouse_pos.x > 300 && mouse_pos.x < 540 &&
		mouse_pos.y > 520 && mouse_pos.y < 620 &&
		sfMouse_isButtonPressed(sfMouseLeft) == 1)
		return (2);
	if (mouse_pos.x > 540 && mouse_pos.x < 780 &&
		mouse_pos.y > 520 && mouse_pos.y < 620 &&
		sfMouse_isButtonPressed(sfMouseLeft) == 1)
		return (3);
	return (page);

}

void fridge_management(character_struct *c, total_struct *s,
			sfRenderWindow *window)
{
	static int page = 1;

	while (true && sfRenderWindow_isOpen(window)) {
		display_ath(window, s->text.ATH[0]);
		client_management(c, s, window);
		furnace_update(window, s, c->f, true);
		create_font(s->text.button_shortOFF[0], window);
		create_buttons_page(window, s);
		page = define_button_click_fridge(window, page);
		display_food_fridge(s, window, page, c);
		display_fridge_inventory(c, s, window);
		if (display_quit_game(s->text.font, window) == 1)
			break;
		sfRenderWindow_display(window);
		event_close(window);

	}
}
