/*
** EPITECH PROJECT, 2018
** my_overcooked
** File description:
** animation character
*/

#include "declaration.h"

character_struct *character_pos(character_struct *c, char *map, total_struct *s)
{
	if (no_seg(c, map) == true)
		place_charac(c, map);
	c->side = define_side_char(c->pos, map);
	c->map = map;
	c->clock = sfClock_create();
	c->cooldown = sfClock_create();
	sfSprite_setTexture(c->sprite, c->texture[1], sfTrue);
	c->look = 'd';
	c->food.id = 0;
	c->food.name = "Empty";
	c->food.burnable = true;
	c->food.sliceable = true;
	c->food.texture = s->text.food_00[0];
	c->f = NULL;
	c->clients = create_client_struct(s);
	c->score = 20;
	c->served = 0;
	c->plates = 5;
	return (c);
}

character_struct *character_init(total_struct *s, int charac_nb, char *map)
{
	character_struct *c = malloc(sizeof(character_struct));

	c->sprite = sfSprite_create();
	if (charac_nb == 1)
		c->texture = s->text.char_1;
	if (charac_nb == 2)
		c->texture = s->text.char_2;
	if (charac_nb == 3)
		c->texture = s->text.char_3;
	if (charac_nb == 4)
		c->texture = s->text.char_4;
	if (charac_nb == 5)
		c->texture = s->text.char_5;
	if (charac_nb == 6)
		c->texture = s->text.char_6;
	if (charac_nb == 7)
		c->texture = s->text.char_7;
	if (charac_nb == 8)
		c->texture = s->text.char_8;
	return (character_pos(c, map, s));
}

bool charac_move(character_struct *c, int nb)
{
	static int i = 0;
	static int loop = 0;

	if (nb < 0)
		return (false);
	sfSprite_setTexture(c->sprite, c->texture[i + nb], sfTrue);
	set_charac_pos(c, nb);
	set_charac_pos2(c, nb);
	++i;
	if (i == 2 && loop == 2) {
		i = 0;
		loop = 0;
		sfSprite_setTexture(c->sprite, c->texture[1 + nb], sfTrue);
		return (true);
	} else if (i == 4) {
		i = 0;
		sfSprite_setTexture(c->sprite, c->texture[1 + nb], sfTrue);
		++loop;
	}
	return (false);
}

int modify_i(int i, character_struct *c)
{
	if (i == -1 && c->side != NULL) {
		free(c->side);
		c->side = NULL;
	}
	if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue && i == -1) {
		i = 9;
		c->side = define_side_char(c->pos, c->map);
	}
	if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue && i == -1) {
		i = 6;
		c->side = define_side_char(c->pos, c->map);
	}
	if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue && i == -1) {
		i = 3;
		c->side = define_side_char(c->pos, c->map);
	} else if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue && i == -1) {
		i = 0;
		c->side = define_side_char(c->pos, c->map);
	}
	return (i);
}

void charac_main(character_struct *c, total_struct *s, sfRenderWindow *window)
{
	static int i = -1;
	sfTime time = sfClock_getElapsedTime(c->clock);
	sfVector2f tempo;

	i = modify_i(i, c);
	modify_look(i, c);
	space_press(s, i, c, window);
	if (time.microseconds >= 25000) {
		tempo.x = c->pos.x;
		tempo.y = c->pos.y;
		sfSprite_setPosition(c->sprite, tempo);
		sfClock_restart(c->clock);
		can_charac_move(c, &i);
		if (charac_move(c, i) == true)
			i = -1;
	}
	if (c->side != NULL && i == -1) {
		free(c->side);
		c->side = NULL;
	}
}
