/*
** EPITECH PROJECT, 2018
** my_overcooked
** File description:
** hellow
*/

#include "declaration.h"

typedef struct texture_struct
{
	sfTexture **ATH;
	sfTexture **backg;
	sfTexture **char_1;
	sfTexture **char_2;
	sfTexture **char_3;
	sfTexture **char_4;
	sfTexture **char_5;
	sfTexture **char_6;
	sfTexture **char_7;
	sfTexture **char_8;
	sfTexture **dish_1;
	sfTexture **dish_2;
	sfTexture **dish_3;
	sfTexture **dish_4;
	sfTexture **dish_5;
	sfTexture **dish_6;
	sfTexture **dish_7;
	sfTexture **dish_dirty;
	sfTexture **dish_empty;
	sfTexture **food_00;
	sfTexture **food_01;
	sfTexture **food_02;
	sfTexture **food_03;
	sfTexture **food_04;
	sfTexture **food_05;
	sfTexture **food_06;
	sfTexture **food_11;
	sfTexture **food_12;
	sfTexture **food_13;
	sfTexture **food_14;
	sfTexture **food_15;
	sfTexture **food_21;
	sfTexture **food_22;
	sfTexture **food_23;
	sfTexture **map_tiles;
	sfTexture **pause;
	sfTexture **score;
	sfTexture **start;
	sfTexture **button_longOFF;
	sfTexture **button_longON;
	sfTexture **button_shortOFF;
	sfTexture **button_shortON;
	sfTexture **recipe;
	sfFont *font;
} texture;

typedef struct music_struct
{
	sfMusic *menu;
	sfMusic *in_game1;
	sfMusic *in_game2;
	sfMusic *actual;
	sfSound *sound;
	sfSoundBuffer *nope;
	sfSoundBuffer *bip;
	sfSoundBuffer *cut;
	sfSoundBuffer *clean;
} music;

typedef struct global_struct
{
	texture text;
	music sound;
	sfRenderWindow *window;
	int first_client;
} total_struct;
