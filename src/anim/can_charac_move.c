/*
** EPITECH PROJECT, 2018
** my_overcooked
** File description:
** is pos good
*/

#include "declaration.h"

void set_charac_pos2(character_struct *c, int nb)
{
	static int save_nb = 1;

	if (nb == 6) {
		if (save_nb == 9) {
			c->pos.x += 1;
			save_nb = 0;
		} else {
			c->pos.x += 7;
			++save_nb;
		}
	}
	if (nb == 9) {
		if (save_nb == 9) {
			c->pos.y -= 5;
			save_nb	 = 0;
		} else {
			c->pos.y -= 9;
			++save_nb;
		}
	}
}

void set_charac_pos(character_struct *c, int nb)
{
	static int save_nb = 0;

	if (nb == 0) {
		if (save_nb == 9) {
			c->pos.y += 5;
			save_nb = 0;
		} else {
			c->pos.y += 9;
			++save_nb;
		}
	}
	if (nb == 3) {
		if (save_nb == 9) {
			c->pos.x -= 1;
			save_nb = 0;
		} else {
			c->pos.x -= 7;
			++save_nb;
		}
	}
}

void modify_look(int i, character_struct *c)
{
	if (i == 0)
		c->look = 'd';
	if (i == 3)
		c->look = 'l';
	if (i == 6)
		c->look = 'r';
	if (i == 9)
		c->look = 'u';
	if (i == -1) {
		c->side = define_side_char(c->pos, c->map);
		if (c->look == 'd' && c->side != NULL)
			c->look_tile = c->side->bot;
		if (c->look == 'l' && c->side != NULL)
			c->look_tile = c->side->left;
		if (c->look == 'r' && c->side != NULL)
			c->look_tile = c->side->right;
		if (c->look == 'u' && c->side != NULL)
			c->look_tile = c->side->top;
	} else
		c->look_tile = 0;
}

void can_charac_move(character_struct *c, int *i)
{
	if (*i == 0 && c->side->bot != 0) {
		*i = -1;
		sfSprite_setTexture(c->sprite, c->texture[1], sfTrue);
	}
	if (*i == 3 && c->side->left != 0) {
		*i = -1;
		sfSprite_setTexture(c->sprite, c->texture[4], sfTrue);
	}
	if (*i == 6 && c->side->right != 0) {
		*i = -1;
		sfSprite_setTexture(c->sprite, c->texture[7], sfTrue);
	}
	if (*i == 9 && c->side->top != 0) {
		*i = -1;
		sfSprite_setTexture(c->sprite, c->texture[10], sfTrue);
	}
}
