/*
** EPITECH PROJECT, 2018
** fridge texte
** File description:
** fridge text
*/

#include "declaration.h"

void display_text_fridge_page1(sfFont *font, sfRenderWindow *window)
{
	sfVector2f pos_00 = {300, 120};
	sfVector2f pos_10 = {600, 120};
	sfVector2f pos_20 = {900, 120};
	sfVector2f pos_01 = {300, 320};
	sfVector2f pos_11 = {600, 320};
	sfVector2f pos_21 = {900, 320};

	text_create(font, "Tomato", pos_00, window);
	text_create(font, "Lettuce", pos_10, window);
	text_create(font, "Pumpkin", pos_20, window);
	text_create(font, "Potato", pos_01, window);
	text_create(font, "Carot", pos_11, window);
	text_create(font, "Green Been", pos_21, window);
}

void display_text_fridge_page2(sfFont *font, sfRenderWindow *window)
{
	sfVector2f pos_00 = {300, 120};
	sfVector2f pos_20 = {900, 120};
	sfVector2f pos_01 = {300, 320};
	sfVector2f pos_21 = {900, 320};

	text_create(font, "Steak", pos_00, window);
	text_create(font, "Chicken", pos_20, window);
	text_create(font, "Ham", pos_01, window);
	text_create(font, "Fish", pos_21, window);
}

void display_text_fridge_page3(sfFont *font, sfRenderWindow *window)
{
	sfVector2f pos_00 = {300, 120};
	sfVector2f pos_20 = {900, 120};
	sfVector2f pos_11 = {600, 320};

	text_create(font, "Pizza Dough", pos_00, window);
	text_create(font, "Cheese", pos_20, window);
	text_create(font, "Burger Bread", pos_11, window);
}
