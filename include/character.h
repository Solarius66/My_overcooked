/*
** EPITECH PROJECT, 2018
** my_overcooked
** File description:
** hello again :D
*/

#include "declaration.h"

typedef struct food_struct
{
	char *name;
	int id;
	sfTexture *texture;
	bool burnable;
	bool sliceable;
} food_struct;

typedef struct furnace_struct
{
	char *name;
	int idX;
	int idY;
	float timer;
	sfClock *clock;
	food_struct food;
	struct furnace_struct *next;
} furnace;

typedef struct character
{
	sfSprite *sprite;
	sfTexture **texture;
	sfClock *clock;
	sfClock *cooldown;
	sfVector2f pos;
	side_char *side;
	food_struct food;
	char look;
	char look_tile;
	char *map;
	furnace *f;
	clients_full *clients;
	int score;
	int served;
	int plates;
} character_struct;
