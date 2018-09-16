/*
** EPITECH PROJECT, 2018
** set textes
** File description:
** set textes
*/

#include "declaration.h"

void set_text(sfText *text, sfVector2f pos, char *sentence, sfFont *font)
{
	sfText_setString(text, sentence);
	sfText_setFont(text, font);
	sfText_setCharacterSize(text, 68);
	sfText_setColor(text, sfBlack);
	sfText_setPosition(text, pos);
}

struct main_textes *main_menu_textes(sfFont *font)
{
	struct main_textes *textes = malloc(sizeof(struct main_textes));
	sfText *play = sfText_create();
	sfText *opt = sfText_create();
	sfText *quit = sfText_create();
	sfVector2f pos_play = {830, 455};
	sfVector2f pos_opt = {170, 655};
	sfVector2f pos_quit = {835, 655};

	if (textes == NULL)
		return (NULL);
	set_text(play, pos_play, "PLAY", font);
	set_text(opt, pos_opt, "OPTIONS", font);
	set_text(quit, pos_quit, "QUIT", font);
	textes->play = play;
	textes->opt = opt;
	textes->quit = quit;
	return (textes);
}

struct opt_textes *opt_menu_textes(sfFont *font)
{
	struct opt_textes *textes = malloc(sizeof(struct opt_textes));
	sfText *fps = sfText_create();
	sfText *music = sfText_create();
	sfText *tuto = sfText_create();
	sfText *quit = sfText_create();
	sfVector2f pos_fps = {300, 435};
	sfVector2f pos_music = {275, 575};
	sfVector2f pos_tuto = {810, 435};
	sfVector2f pos_quit = {820, 575};

	set_text(fps, pos_fps, "FPS : 60", font);
	set_text(music, pos_music, "MUSIC : ON", font);
	set_text(tuto, pos_tuto, "KEYS", font);
	set_text(quit, pos_quit, "QUIT", font);
	textes->fps = fps;
	textes->music = music;
	textes->tuto = tuto;
	textes->quit = quit;
	return (textes);
}
