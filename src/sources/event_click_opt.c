/*
** EPITECH PROJECT, 2018
** event click opt
** File description:
** event click opt
*/

#include "declaration.h"

void define_fps(sfRenderWindow *window, sfText *text)
{
	static int fps = 60;

	if (fps == 60) {
		fps = 120;
		sfText_setString(text, "FPS : 120");
	} else if (fps == 120) {
		fps = 30;
		sfText_setString(text, "FPS : 30");
	} else {
		fps = 60;
		sfText_setString(text, "FPS : 60");
	}
	sfRenderWindow_setFramerateLimit(window, fps);
}

void display_tuto(sfRenderWindow *window)
{
	sfTexture *tuto_t = sfTexture_createFromFile("./textures/tuto.png",
							NULL);
	sfVector2f pos = {0, 0};
	struct game_object *tuto = create_gameobject(tuto_t, pos,
							set_rect(0, 1260, 840));
	sfVector2i mouse_pos;

	sfRenderWindow_drawSprite(window, tuto->sprite, NULL);
	sfRenderWindow_display(window);
	for (int x = 0 ; x == 0 ;) {
		mouse_pos = sfMouse_getPositionRenderWindow(window);
		if (sfKeyboard_isKeyPressed(sfKeyEscape) == 1 ||
			(mouse_pos.x > 10 && mouse_pos.x < 70 &&
			mouse_pos.y > 10 && mouse_pos.y < 70 &&
			sfMouse_isButtonPressed(sfMouseLeft)))
			x = 1;
		}
	sfTexture_destroy(tuto_t);
	sfSprite_destroy(tuto->sprite);
	free(tuto);
}

int event_click_opt(total_struct *s, struct full_buttons *buttons,
			sfEvent event, struct opt_textes *textes)
{
	sfVector2f mouse_pos = get_click_pos(s->window, event);
	static int music = 1;

	if (button_isClicked(buttons->opt->window_size, mouse_pos) == 1)
		define_fps(s->window, textes->fps);
	if (button_isClicked(buttons->opt->music, mouse_pos) == 1) {
		if (music == 1) {
			sfText_setString(textes->music, "MUSIC : OFF");
			music = 0;
		} else {
			sfText_setString(textes->music, "MUSIC : ON");
			music = 1;
		}
		mute_unmute(s, music);
	}
	if (button_isClicked(buttons->opt->how2play, mouse_pos) == 1)
		display_tuto(s->window);
	if (button_isClicked(buttons->opt->quit, mouse_pos) == 1)
		return (1);
	return (0);
}
