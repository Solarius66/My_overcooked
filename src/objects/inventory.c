/*
** EPITECH PROJECT, 2018
** inventory
** File description:
** inventory
*/

#include "declaration.h"

void display_inv_text(character_struct *c, sfRenderWindow *window)
{
	sfRectangleShape *rect = sfRectangleShape_create();
	sfVector2f pos = {700, 150};
	sfVector2f size = {256, 256};

	sfRectangleShape_setPosition(rect, pos);
	sfRectangleShape_setSize(rect, size);
	sfRectangleShape_setTexture(rect, c->food.texture, sfTrue);
	sfRenderWindow_drawRectangleShape(window, rect, NULL);
	sfRectangleShape_destroy(rect);
}

int display_quit_game(sfFont *font, sfRenderWindow *window)
{
	sfVector2f pos = {1050, 70};
	sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

	text_create(font, "quit", pos, window);
	if (mouse_pos.x > pos.x && mouse_pos.x < pos.x + 100 &&
		mouse_pos.y > pos.y && mouse_pos.y < pos.y + 30 &&
		sfMouse_isButtonPressed(sfMouseLeft) == 1)
		return (1);
	else
		return (0);
}

void define_bool_inv(character_struct *c, sfRenderWindow *window, sfFont *font)
{
	sfVector2f pos_BURN = {300, 250};
	sfVector2f pos_SLICE = {300, 300};

	if (c->food.burnable == true)
		text_create(font, "NO", pos_BURN, window);
	else
		text_create(font, "YES", pos_BURN, window);
	if (c->food.sliceable == true)
		text_create(font, "NO", pos_SLICE, window);
	else
		text_create(font, "YES", pos_SLICE, window);
}

void display_text_inven(character_struct *c, sfRenderWindow *window,
			total_struct *s)
{
	sfVector2f pos_title = {550, 70};
	sfVector2f pos_name = {130, 200};
	sfVector2f pos_NAME = {300, 200};
	sfVector2f pos_burn = {130, 250};
	sfVector2f pos_slice = {130, 300};

	text_create(s->text.font, "INVENTORY", pos_title, window);
	text_create(s->text.font, "name :", pos_name, window);
	text_create(s->text.font, c->food.name, pos_NAME, window);
	text_create(s->text.font, "burnable :", pos_burn, window);
	text_create(s->text.font, "sliceable :", pos_slice, window);
	display_inv_text(c, window);
	define_bool_inv(c, window, s->text.font);
}

int inventory_display(character_struct *c, sfRenderWindow *window,
			total_struct *s)
{
	if (sfKeyboard_isKeyPressed(sfKeyE) == sfFalse)
		return (0);
	while (true && sfRenderWindow_isOpen(window)) {
		display_ath(window, s->text.ATH[0]);
		client_management(c, s, window);
		furnace_update(window, s, c->f, true);
		create_font(s->text.button_shortOFF[0], window);
		display_text_inven(c, window, s);
		if (display_quit_game(s->text.font, window) == 1)
			break;
		sfRenderWindow_display(window);
		event_close(window);
	}
	return (0);
}
