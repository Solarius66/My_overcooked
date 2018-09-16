/*
** EPITECH PROJECT, 2018
** main test
** File description:
** mais test
*/

#include "declaration.h"

void game_main_bis(character_struct *c, total_struct *s,
			sfRenderWindow *window, char *map)
{
	sfRenderWindow_clear(window, sfBlack);
	display_score_star(window, c->served, s->text.score[0]);
	display_ath(window, s->text.ATH[0]);
	display_clients(window, c->score, s);
	client_management(c, s, window);
	create_map(map, window, s->text.map_tiles[0]);
	charac_main(c, s, window);
}

int game_main(sfRenderWindow *window, total_struct *s, int char_nb)
{
	char *map_string = read_map_file(window, s);
	character_struct *c = character_init(s, char_nb, map_string);
	machine_struct *m = define_machine_struct(s);

	while (sfRenderWindow_isOpen(window)) {
		game_main_bis(c, s, window, map_string);
		sfRenderWindow_drawSprite(window, c->sprite, NULL);
		use_space_bar(c, s, window, m);
		furnace_update(window, s, c->f, true);
		inventory_display(c, window, s);
		display_recipe(window, s->text.recipe[0]);
		if (pause_main(s, window) == 1 || end_dis(c, window, s) == 1)
			break;
		sfRenderWindow_display(window);
		event_close(window);
	}
	discharge_main(s, c, m);
	return (0);
}
