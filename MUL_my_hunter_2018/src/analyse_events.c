/*
** EPITECH PROJECT, 2018
** CSFML
** File description:
** sf render window
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "include/ycsfml.h"

long randomiser(long min, long max);

void destroy_duck(struct game_window* window, struct duck* duck,
                  struct parameters *parameters)
{
    sfVector2f sprite_pos;
    sfVector2f mouse_pos;

    sprite_pos.x = sfSprite_getPosition(duck->duck).x;
    sprite_pos.y = sfSprite_getPosition(duck->duck).y;
    mouse_pos.x = sfMouse_getPositionRenderWindow(window->game_window).x;
    mouse_pos.y = sfMouse_getPositionRenderWindow(window->game_window).y;
    if ((mouse_pos.x >= sprite_pos.x  && mouse_pos.x <= sprite_pos.x + 110) &&
        (mouse_pos.y <= sprite_pos.y + 110 && mouse_pos.y >= sprite_pos.y)) {
        sfSprite_setPosition(duck->duck, (sfVector2f){randomiser(-1500,-200),
                    randomiser(0,-600)});
        duck->duck_speed = duck->duck_speed + randomiser(1,7);
        duck->difficulty = duck->difficulty + randomiser(1,5);
        window->score = window->score + 50;
        parameters->ducks_hit = parameters->ducks_hit + 1;
        rando_sound(window);
    } else {
        window->score = window->score - 10;
        sfMusic_play(window->duck);
    }
}

void duck_out_of_screen(struct game_window* window, struct duck* duck,
                        struct parameters *parameters)
{
    sfVector2f sprite_pos;
    sfVector2f mouse_pos;

    sprite_pos.x = sfSprite_getPosition(duck->duck).x;
    sprite_pos.y = sfSprite_getPosition(duck->duck).y;
    if (sprite_pos.x >= 1300) {
        sfSprite_setPosition(duck->duck, (sfVector2f){randomiser(-1500,-200),
                    randomiser(0,-600)});
        duck->duck_speed = duck->duck_speed - 10;
        duck->difficulty = duck->difficulty - 15;
        window->hp = window->hp - 1;
        parameters->ducks_missed = parameters->ducks_missed + 1;
    }
}

void gun_shoot(struct gun *gun, struct game_window *window, struct duck *duck)
{
    int i = 0;

    move_rect(&(gun->gun_rect), 166, 249);
    sfSprite_setTextureRect(gun->gun_shoot, gun->gun_rect);
    draw_all(window, gun, duck);
    if (gun->gun_seconds >= 0.5) {
        move_rect(&(gun->gun_rect), 83, 249);
        sfSprite_setTextureRect(gun->gun_shoot, gun->gun_rect);
        draw_all(window, gun, duck);
    }
}

void analyse_events(struct game_window* window,struct duck* duck,
                    struct gun *gun, struct parameters *parameters)
{
    while(sfRenderWindow_pollEvent(window->game_window, &window->game_events)) {
        if (window->game_events.type == sfEvtClosed ||
            sfKeyboard_isKeyPressed(sfKeyEscape)) {
            clean_all(window, parameters, duck, gun);
            close_window(window->game_window);
        }
        if (sfMouse_isButtonPressed(sfMouseLeft) &&
            window->game_events.type == sfEvtMouseButtonPressed) {
            sfMusic_play(window->shoot);
            gun_shoot(gun, window, duck);
            parameters->shots = parameters->shots + 1;
            destroy_duck(window, duck, parameters);
        }
    }
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left = rect->left + offset;
    if (rect->left >= max_value)
        rect->left = 0;
}

void move_sprite(sfSprite* sprite, float x, float y)
{
    sfVector2f pos;

    pos.x = x;
    pos.y = y;
    sfSprite_move(sprite, pos);
}
