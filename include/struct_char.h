/*
** EPITECH PROJECT, 2018
** struct char
** File description:
** struct char
*/

#include "declaration.h"
#ifndef STRUCT_CHAR_H_
#define STRUCT_CHAR_H_

typedef struct side_char {
	int top;
	int bot;
	int right;
	int left;
}side_char;

typedef struct client_struct {
	int id;
	sfVector2f pos;
	sfTexture *texture;
	sfClock *clock;
}client_struct;

typedef struct clients_full {
	client_struct client[6];
	sfClock *clock;
}clients_full;

#endif /* ! STRUCT_CHAR_H_ */
