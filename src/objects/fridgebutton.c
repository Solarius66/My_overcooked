/*
** EPITECH PROJECT, 2018
** fridge button
** File description:
** fridge button
*/

#include "declaration.h"

void define_buttons_page1_bis(character_struct *f,sfRenderWindow *window,
				total_struct *s)
{
	sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

	if (mouse_pos.x > 150 && mouse_pos.x < 420 &&
		mouse_pos.y > 275 && mouse_pos.y < 425 &&
		sfMouse_isButtonPressed(sfMouseLeft)) {
		define_food_inventory1(f, "Potato", 8, s->text.food_04[0]);
		define_food_inventory2(f, false, false);
	}
	if (mouse_pos.x > 450 && mouse_pos.x < 720 &&
		mouse_pos.y > 275 && mouse_pos.y < 425 &&
		sfMouse_isButtonPressed(sfMouseLeft)) {
		define_food_inventory1(f, "Carot", 16, s->text.food_05[0]);
		define_food_inventory2(f, true, false);
	}
	if (mouse_pos.x > 750 && mouse_pos.x < 1020 &&
		mouse_pos.y > 275 && mouse_pos.y < 425 &&
		sfMouse_isButtonPressed(sfMouseLeft)) {
		define_food_inventory1(f, "Been", 32, s->text.food_06[0]);
		define_food_inventory2(f, false, true);
	}
}

void define_buttons_page1(character_struct *f, sfRenderWindow *window,
				total_struct *s)
{
	sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

	if (mouse_pos.x > 150 && mouse_pos.x < 420 &&
		mouse_pos.y > 75 && mouse_pos.y < 225 &&
		sfMouse_isButtonPressed(sfMouseLeft)) {
		define_food_inventory1(f, "Tomato", 1, s->text.food_01[0]);
		define_food_inventory2(f, true, false);
	}
	if (mouse_pos.x > 450 && mouse_pos.x < 720 &&
		mouse_pos.y > 75 && mouse_pos.y < 225 &&
		sfMouse_isButtonPressed(sfMouseLeft)) {
		define_food_inventory1(f, "Lettuce", 2, s->text.food_02[0]);
		define_food_inventory2(f, true, false);
	}
	if (mouse_pos.x > 750 && mouse_pos.x < 1020 &&
		mouse_pos.y > 75 && mouse_pos.y < 225 &&
		sfMouse_isButtonPressed(sfMouseLeft)) {
		define_food_inventory1(f, "Pumpkin", 4, s->text.food_03[0]);
		define_food_inventory2(f, true, false);
	}
}

void define_buttons_page2bis(character_struct *f, total_struct *s,
				sfVector2i mouse_pos)
{
	if (mouse_pos.x > 150 && mouse_pos.x < 420 &&
		mouse_pos.y > 275 && mouse_pos.y < 425 &&
		sfMouse_isButtonPressed(sfMouseLeft)) {
		define_food_inventory1(f, "Ham", 256, s->text.food_13[0]);
		define_food_inventory2(f, false, true);
	}
	if (mouse_pos.x > 750 && mouse_pos.x < 1020 &&
		mouse_pos.y > 275 && mouse_pos.y < 425 &&
		sfMouse_isButtonPressed(sfMouseLeft)) {
		define_food_inventory1(f, "Fish", 512, s->text.food_14[0]);
		define_food_inventory2(f, false, false);
	}
}

void define_buttons_page2(character_struct *f, sfRenderWindow *window,
				total_struct *s)
{
	sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

	if (mouse_pos.x > 150 && mouse_pos.x < 420 &&
		mouse_pos.y > 75 && mouse_pos.y < 225 &&
		sfMouse_isButtonPressed(sfMouseLeft)) {
		define_food_inventory1(f, "Steak", 64, s->text.food_11[0]);
		define_food_inventory2(f, false, true);
	}
	if (mouse_pos.x > 750 && mouse_pos.x < 1020 &&
		mouse_pos.y > 75 && mouse_pos.y < 225 &&
		sfMouse_isButtonPressed(sfMouseLeft)) {
		define_food_inventory1(f, "Chicken", 128, s->text.food_12[0]);
		define_food_inventory2(f, false, true);
	}
	define_buttons_page2bis(f, s, mouse_pos);
}

void define_buttons_page3(character_struct *f, sfRenderWindow *window,
				total_struct *s)
{
	sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

	if (mouse_pos.x > 150 && mouse_pos.x < 420 &&
		mouse_pos.y > 75 && mouse_pos.y < 225 &&
		sfMouse_isButtonPressed(sfMouseLeft)) {
		define_food_inventory1(f, "Pizza", 1024, s->text.food_21[0]);
		define_food_inventory2(f, true, true);
	}
	if (mouse_pos.x > 450 && mouse_pos.x < 720 &&
		mouse_pos.y > 275 && mouse_pos.y < 425 &&
		sfMouse_isButtonPressed(sfMouseLeft)) {
		define_food_inventory1(f, "Burger", 2048, s->text.food_22[0]);
		define_food_inventory2(f, true, true);
	}
	if (mouse_pos.x > 750 && mouse_pos.x < 1020 &&
		mouse_pos.y > 75 && mouse_pos.y < 225 &&
		sfMouse_isButtonPressed(sfMouseLeft)) {
		define_food_inventory1(f, "Cheese", 4096, s->text.food_23[0]);
		define_food_inventory2(f, true, true);
	}
}
