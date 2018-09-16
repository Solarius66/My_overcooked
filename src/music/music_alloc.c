/*
** EPITECH PROJECT, 2018
** my_overcooked
** File description:
** alloc musics
*/

#include "declaration.h"

void music_alloc(total_struct *s)
{
	s->sound.menu = sfMusic_createFromFile("./musics/ageage.ogg");
	s->sound.in_game1 = sfMusic_createFromFile("./musics/party.ogg");
	s->sound.in_game2 = sfMusic_createFromFile("./musics/boop.ogg");
	s->sound.actual = s->sound.in_game1;
	sfMusic_setVolume(s->sound.menu, 30);
	sfMusic_setVolume(s->sound.in_game1, 10);
	sfMusic_setVolume(s->sound.in_game2, 30);
	sfMusic_setLoop(s->sound.menu, sfTrue);
	sfMusic_play(s->sound.menu);
	create_sound(&s->sound);
}

void destroy_music(music *s)
{
	sfMusic_destroy(s->menu);
	sfMusic_destroy(s->in_game1);
	sfMusic_destroy(s->in_game2);
	destroy_sound(s);
}

void choose_music(total_struct *s)
{
	int random = rand() % 2 + 1;

	if (sfMusic_getStatus(s->sound.menu) == sfPlaying)
		sfMusic_stop(s->sound.menu);
	if (sfMusic_getStatus(s->sound.actual) != sfPlaying) {
		if (sfMusic_getStatus(s->sound.actual) == sfPaused)
			sfMusic_stop(s->sound.actual);
		if (random == 1)
			s->sound.actual = s->sound.in_game2;
		else
			s->sound.actual = s->sound.in_game1;
		sfMusic_play(s->sound.actual);
	}
}

void mute_unmute(total_struct *s, int is_mute)
{
	if (is_mute == 1) {
		sfMusic_setVolume(s->sound.menu, 30);
		sfMusic_setVolume(s->sound.in_game1, 10);
		sfMusic_setVolume(s->sound.in_game2, 20);
	} else {
		sfMusic_setVolume(s->sound.menu, 0);
		sfMusic_setVolume(s->sound.in_game1, 0);
		sfMusic_setVolume(s->sound.in_game2, 0);
	}
}
