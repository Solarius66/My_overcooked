/*
** EPITECH PROJECT, 2018
** my graphical lib
** File description:
** destroying texture
*/

#include "declaration.h"

int destroy_textures(sfTexture **tab)
{
	for (int i = 0 ; tab[i] != NULL ; ++i)
		sfTexture_destroy(tab[i]);
	free(tab);
	return (0);
}

void destroy_text_third(texture *s)
{
	destroy_textures(s->food_01);
	destroy_textures(s->food_02);
	destroy_textures(s->food_03);
	destroy_textures(s->food_04);
	destroy_textures(s->food_05);
	destroy_textures(s->food_06);
	destroy_textures(s->recipe);
}

void destroy_text_sec(texture *s)
{
	destroy_textures(s->food_00);
	destroy_textures(s->food_13);
	destroy_textures(s->food_14);
	destroy_textures(s->food_21);
	destroy_textures(s->food_22);
	destroy_textures(s->food_23);
	destroy_textures(s->map_tiles);
	destroy_textures(s->pause);
	destroy_textures(s->start);
	destroy_textures(s->score);
	destroy_textures(s->dish_1);
	destroy_textures(s->dish_2);
	destroy_textures(s->dish_3);
	destroy_textures(s->dish_4);
	destroy_textures(s->dish_5);
	destroy_textures(s->dish_6);
	destroy_textures(s->dish_7);
	destroy_textures(s->dish_empty);
	destroy_textures(s->dish_dirty);
	destroy_text_third(s);
}

void destroy_text_main(texture *s)
{
	destroy_textures(s->ATH);
	destroy_textures(s->backg);
	destroy_textures(s->button_longOFF);
	destroy_textures(s->button_longON);
	destroy_textures(s->button_shortOFF);
	destroy_textures(s->button_shortON);
	destroy_textures(s->char_1);
	destroy_textures(s->char_2);
	destroy_textures(s->char_3);
	destroy_textures(s->char_4);
	destroy_textures(s->char_5);
	destroy_textures(s->char_6);
	destroy_textures(s->char_7);
	destroy_textures(s->char_8);
	destroy_textures(s->food_11);
	destroy_textures(s->food_12);
	sfFont_destroy(s->font);
	destroy_text_sec(s);
}

int destroy_all(total_struct *s)
{
	destroy_text_main(&s->text);
	destroy_music(&s->sound);
	free(s);
	return (0);
}
