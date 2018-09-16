/*
** EPITECH PROJECT, 2018
** fridge food
** File description:
** frige food display
*/

#include "declaration.h"

void create_food_rect(sfTexture *texture, int pos_x, int pos_y,
			sfRenderWindow *window)
{
	sfRectangleShape *rect = sfRectangleShape_create();
	sfVector2f pos = {pos_x * 300 + 150, pos_y * 200 + 75};
	sfVector2f size = {150, 150};

	sfRectangleShape_setPosition(rect, pos);
	sfRectangleShape_setSize(rect, size);
	sfRectangleShape_setTexture(rect, texture, sfTrue);
	sfRenderWindow_drawRectangleShape(window, rect, NULL);
	sfRectangleShape_destroy(rect);
}

void display_page_one(total_struct *s, sfRenderWindow *window,
			character_struct *c)
{
	create_food_rect(s->text.food_01[0], 0, 0, window);
	create_food_rect(s->text.food_02[0], 1, 0, window);
	create_food_rect(s->text.food_03[0], 2, 0, window);
	create_food_rect(s->text.food_04[0], 0, 1, window);
	create_food_rect(s->text.food_05[0], 1, 1, window);
	create_food_rect(s->text.food_06[0], 2, 1, window);
	display_text_fridge_page1(s->text.font, window);
	define_buttons_page1(c, window, s);
	define_buttons_page1_bis(c, window, s);
}

void display_page_two(total_struct *s, sfRenderWindow *window,
			character_struct *c)
{
	create_food_rect(s->text.food_11[0], 0, 0, window);
	create_food_rect(s->text.food_12[0], 2, 0, window);
	create_food_rect(s->text.food_13[0], 0, 1, window);
	create_food_rect(s->text.food_14[0], 2, 1, window);
	display_text_fridge_page2(s->text.font, window);
	define_buttons_page2(c, window, s);
}

void display_page_three(total_struct *s, sfRenderWindow *window,
			character_struct *c)
{
	create_food_rect(s->text.food_21[0], 0, 0, window);
	create_food_rect(s->text.food_22[0], 1, 1, window);
	create_food_rect(s->text.food_23[0], 2, 0, window);
	display_text_fridge_page3(s->text.font, window);
	define_buttons_page3(c, window, s);
}

void display_food_fridge(total_struct *s, sfRenderWindow *window, int page,
				character_struct *c)
{
	if (page == 1)
		display_page_one(s, window, c);
	if (page == 2)
		display_page_two(s, window, c);
	if (page == 3)
		display_page_three(s, window, c);
}
