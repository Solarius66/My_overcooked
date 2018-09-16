/*
** EPITECH PROJECT, 2018
** my_overcooked
** File description:
** texture main
*/

# include "declaration.h"

int check_texture_integrity(texture *s)
{
	if (s->char_1 == NULL || s->char_2 == NULL || s->char_3 == NULL ||
		s->char_4 == NULL || s->char_5 == NULL || s->char_6 == NULL ||
		s->char_7 == NULL || s->char_8 == NULL || s->dish_1 == NULL ||
		s->dish_2 == NULL || s->dish_3 == NULL || s->dish_4 == NULL ||
		s->dish_5 == NULL || s->dish_6 == NULL || s->dish_7 == NULL ||
		s->food_01 == NULL || s->food_02 == NULL || s->food_03 == NULL
		|| s->food_04 == NULL || s->food_05 == NULL ||
		s->food_06 == NULL || s->food_11 == NULL || s->food_12 == NULL
		|| s->food_13 == NULL || s->food_14 == NULL ||
		s->food_21 == NULL || s->food_22 == NULL || s->food_23 == NULL
		|| s->map_tiles == NULL || s->pause == NULL || s->start == NULL
		|| s->dish_dirty == NULL || s->dish_empty == NULL ||
		s->ATH == NULL || s->button_longON == NULL ||
		s->button_longOFF == NULL || s->button_shortON == NULL ||
		s->button_shortOFF == NULL || s->score == NULL) {
		my_puterr("error: failed to load an asset.\n");
		return (84);
	}
	return (0);
}

void texture_alloc_3(texture *s)
{
	s->button_longOFF = create_texture("./textures/button_longOFF.png", 1,
						NULL);
	s->button_longON = create_texture("./textures/button_longON.png", 1,
						NULL);
	s->button_shortON = create_texture("./textures/button_shortON.png", 1,
						NULL);
	s->button_shortOFF = create_texture("./textures/button_shortOFF.png", 1
						, NULL);
	s->backg = create_texture("./textures/backg.png", 1, NULL);
	s->food_23 = create_texture("./textures/food_23.png", 1, NULL);
	s->score = create_texture("./textures/score.png", 1, NULL);
	s->recipe = create_texture("./textures/recipe.png", 1, NULL);
	s->font = sfFont_createFromFile("./textures/font.ttf");
}

void texture_alloc_2(texture *s)
{
	s->food_00 = create_texture("./textures/food_00.png", 1, NULL);
	s->food_01 = create_texture("./textures/food_01.png", 1, NULL);
	s->food_02 = create_texture("./textures/food_02.png", 1, NULL);
	s->food_03 = create_texture("./textures/food_03.png", 1, NULL);
	s->food_04 = create_texture("./textures/food_04.png", 1, NULL);
	s->food_05 = create_texture("./textures/food_05.png", 1, NULL);
	s->food_06 = create_texture("./textures/food_06.png", 1, NULL);
	s->food_11 = create_texture("./textures/food_11.png", 1, NULL);
	s->food_12 = create_texture("./textures/food_12.png", 1, NULL);
	s->food_13 = create_texture("./textures/food_13.png", 1, NULL);
	s->food_14 = create_texture("./textures/food_14.png", 1, NULL);
	s->food_21 = create_texture("./textures/food_21.png", 1, NULL);
	s->food_22 = create_texture("./textures/food_22.png", 1, NULL);
	s->map_tiles = create_texture("./textures/map_tiles.png", 1, NULL);
	s->pause = create_texture("./textures/pause.png", 1, NULL);
	s->start = create_texture("./textures/start.png", 1, NULL);
	s->dish_dirty = create_texture("./textures/dish_dirty.png", 1, NULL);
	s->dish_empty = create_texture("./textures/dish_empty.png", 1, NULL);
	s->ATH = create_texture("./textures/ATH.png", 1, NULL);
	texture_alloc_3(s);
}

void texture_alloc(texture *s, sfIntRect *area)
{
	s->char_1 = create_texture("./textures/char_1.png", 12, area);
	s->char_2 = create_texture("./textures/char_2.png", 12, area);
	s->char_3 = create_texture("./textures/char_3.png", 12, area);
	s->char_4 = create_texture("./textures/char_4.png", 12, area);
	s->char_5 = create_texture("./textures/char_5.png", 12, area);
	s->char_6 = create_texture("./textures/char_6.png", 12, area);
	s->char_7 = create_texture("./textures/char_7.png", 12, area);
	s->char_8 = create_texture("./textures/char_8.png", 12, area);
	s->dish_1 = create_texture("./textures/dish_1.png", 1, NULL);
	s->dish_2 = create_texture("./textures/dish_2.png", 1, NULL);
	s->dish_3 = create_texture("./textures/dish_3.png", 1, NULL);
	s->dish_4 = create_texture("./textures/dish_4.png", 1, NULL);
	s->dish_5 = create_texture("./textures/dish_5.png", 1, NULL);
	s->dish_6 = create_texture("./textures/dish_6.png", 1, NULL);
	s->dish_7 = create_texture("./textures/dish_7.png", 1, NULL);
	texture_alloc_2(s);
}

total_struct *texture_main(sfRenderWindow *window)
{
	total_struct *s = malloc(sizeof(total_struct));
	sfIntRect *area = malloc(sizeof(sfIntRect));
	sfClock *timer = sfClock_create();
	int seed;

	read(open("/dev/urandom", O_RDONLY), &seed, sizeof seed);
	srand(seed);
	area->top = 0;
	area->left = 0;
	area->height = 86;
	area->width = 64;
	texture_alloc(&s->text, area);
	music_alloc(s);
	if (check_texture_integrity(&s->text) == 84)
		return (NULL);
	free(area);
	while (sfClock_getElapsedTime(timer).microseconds < 3000000);
	sfClock_destroy(timer);
	s->window = window;
	return (s);
}
