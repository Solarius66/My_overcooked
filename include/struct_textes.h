/*
** EPITECH PROJECT, 2018
** textes struct
** File description:
** struct textes
*/

#include "declaration.h"
#ifndef STRUCT_TEXTES_H_
#define STRUCT_TEXTES_H_

struct main_textes {
	sfText *play;
	sfText *opt;
	sfText *quit;
};

struct opt_textes {
	sfText *fps;
	sfText *music;
	sfText *tuto;
	sfText *quit;
};

#endif /* !STRUCT_TEXTES_H_ */
