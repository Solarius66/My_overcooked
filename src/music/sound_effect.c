/*
** EPITECH PROJECT, 2018
** my_overcooked
** File description:
** creating sound effect
*/

#include "declaration.h"

void create_sound(music *s)
{
	s->sound = sfSound_create();
	s->nope = sfSoundBuffer_createFromFile("./musics/nope.ogg");
	s->bip = sfSoundBuffer_createFromFile("./musics/ding.ogg");
	s->cut = sfSoundBuffer_createFromFile("./musics/cut.ogg");
	s->clean = sfSoundBuffer_createFromFile("./musics/clean.ogg");
}

void destroy_sound(music *s)
{
	sfSound_destroy(s->sound);
	sfSoundBuffer_destroy(s->nope);
	sfSoundBuffer_destroy(s->bip);
	sfSoundBuffer_destroy(s->cut);
	sfSoundBuffer_destroy(s->clean);
}

int sound_effect(total_struct *s, char c)
{
	if (sfSound_getStatus(s->sound.sound) == sfPlaying && c != 's' &&
				c != 'S')
		return (0);
	if (c == 'e' || c == 'E')
		sfSound_setBuffer(s->sound.sound, s->sound.nope);
	if (c == 'b' || c == 'B')
		sfSound_setBuffer(s->sound.sound, s->sound.bip);
	if (c == 's' || c == 'S')
		sfSound_setBuffer(s->sound.sound, s->sound.cut);
	if (c == 'c' || c == 'C')
		sfSound_setBuffer(s->sound.sound, s->sound.clean);
	if (c != 'e' && c != 'E' && c != 'b' && c != 'B' && c != 's' &&
		c != 'S' && c != 'c' && c != 'C') {
			my_printf("error, %s is not a good char\n", &c);
			return (0);
		}
	sfSound_play(s->sound.sound);
	return (0);
}
