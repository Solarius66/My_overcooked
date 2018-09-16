/*
** EPITECH PROJECT, 2018
** machien main
** File description:
** machine main
*/

#include "declaration.h"

void display_machine2(sfVector2f size, total_struct *s, sfRenderWindow *window)
{
	sfVector2f pos1 = {125, 350};
	sfVector2f pos1T = {190, 380};
	sfVector2f pos2 = {380, 350};
	sfVector2f pos2T = {445, 380};
	sfVector2f pos3 = {635, 350};
	sfVector2f pos3T = {700, 380};
	sfVector2f pos4 = {890, 350};
	sfVector2f pos4T = {965, 380};

	sfRectangleShape_destroy(create_rect(s, pos1, size, window));
	sfRectangleShape_destroy(create_rect(s, pos2, size, window));
	sfRectangleShape_destroy(create_rect(s, pos3, size, window));
	sfRectangleShape_destroy(create_rect(s, pos4, size, window));
	text_create(s->text.font, "TAKE", pos1T, window);
	text_create(s->text.font, "TAKE", pos2T, window);
	text_create(s->text.font, "TAKE", pos3T, window);
	text_create(s->text.font, "TAKE", pos4T, window);
}

void display_machine(total_struct *s, sfRenderWindow *window)
{
	sfVector2f pos_clear = {60, 520};
	sfVector2f pos_clearT = {120, 550};
	sfVector2f pos_launch = {300, 520};
	sfVector2f pos_launchT = {355, 550};
	sfVector2f pos_put = {540, 520};
	sfVector2f pos_putT = {620, 550};
	sfVector2f size = {240, 100};
	sfVector2f pos_plates = {110 ,30};

	create_font(s->text.button_shortOFF[0], window);
	sfRectangleShape_destroy(create_rect(s, pos_clear, size, window));
	sfRectangleShape_destroy(create_rect(s, pos_launch, size, window));
	sfRectangleShape_destroy(create_rect(s, pos_put, size, window));
	text_create(s->text.font, "CLEAR", pos_clearT, window);
	text_create(s->text.font, "LAUNCH", pos_launchT, window);
	text_create(s->text.font, "PUT", pos_putT, window);
	text_create(s->text.font, "Plates available :", pos_plates, window);
	display_machine2(size, s, window);
}

void define_food_machine(machine_struct *m, int nbr_food, sfTexture *texture)
{
	m->food[nbr_food].name = "Empty";
	m->food[nbr_food].id = 0;
	m->food[nbr_food].texture = texture;
	m->food[nbr_food].burnable = true;
	m->food[nbr_food].sliceable = true;
}

machine_struct *define_machine_struct(total_struct *s)
{
	machine_struct *m = malloc(sizeof(machine_struct));

	define_food_machine(m, 0, s->text.food_00[0]);
	define_food_machine(m, 1, s->text.food_00[0]);
	define_food_machine(m, 2, s->text.food_00[0]);
	define_food_machine(m, 3, s->text.food_00[0]);
	return (m);
}

void machine_management(character_struct *c, total_struct *s,
			sfRenderWindow *window, machine_struct *m)
{
	char *plates = my_itoa(c->plates);
	sfVector2f pos = {400, 30};

	while (sfRenderWindow_isOpen(window)) {
		display_ath(window, s->text.ATH[0]);
		client_management(c, s, window);
		furnace_update(window, s, c->f, true);
		display_machine(s, window);
		display_fridge_inventory(c, s, window);
		text_create(s->text.font, plates, pos, window);
		button_management_machine(c, s, window, m);
		display_food_machine(m, window);
		if (display_quit_game(s->text.font, window) == 1)
			break;
		sfRenderWindow_display(window);
		event_close(window);
	}
	free(plates);
}
