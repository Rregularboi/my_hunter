/*
** EPITECH PROJECT, 2018
** CSFML
** File description:
** new window
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System/Clock.h>
#include <SFML/Config.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "include/game.h"
#include "include/ycsfml.h"
#include "include/my.h"

long randomiser(long min, long max)
{
    srand(time(NULL));
    return((rand() % (max - min + 1)) + min);
}

long rando_cond(long min, long max, struct duck *duck)
{
    int a = sfSprite_getPosition(duck->duck).y;
    int b = sfSprite_getPosition(duck->duck).x;

    if (duck->duck_speed <= 5 || duck->difficulty <= 0) {
        duck->duck_speed = 5;
        duck->difficulty = 0;
    }
    if (duck->duck_speed >= 100)
        duck->duck_speed = 100;
    if (duck->difficulty >= 60)
        duck->difficulty = 60;
    if (b <= 0 || b >= 1200)
        return (0);
    if (a <= 10)
        return(randomiser(max, max));
    if (a >= 700)
        return(randomiser(min, min));
    return(randomiser(min, max));
}

struct game_window* clock_manager(struct game_window *game_window,
                                  struct duck *duck, struct gun *gun)
{
    game_window->game_time = sfClock_getElapsedTime(game_window->game_clock);
    duck->duck_anim = sfClock_getElapsedTime(duck->duck_clock);
    gun->gun_shoot_clock = sfClock_getElapsedTime(gun->gun_clock);
    game_window->game_seconds = game_window->game_time.microseconds / 1000000.0;
    duck->duck_seconds = duck->duck_anim.microseconds / 1000000.0;
    gun->gun_seconds = gun->gun_shoot_clock.microseconds / 1000000.0;
}

void game_start(struct game_window *game_window, struct duck *dk,
                struct gun *gun, struct parameters *parameters)
{
    game_window->game_texture = sfTexture_create(1280, 800);
    choose_bg(game_window, parameters);
    sfSprite_setTexture(game_window->game_background,
                        game_window->game_texture, sfFalse);
    sfRenderWindow_drawSprite(game_window->game_window,
                              game_window->game_background,NULL);
    game_window->game_texture = sfTexture_createFromFile(
        "bonus/sprites/duck.png", NULL);
    sfSprite_setTexture(dk->duck, game_window->game_texture, sfFalse);
    sfSprite_setTextureRect(dk->duck, dk->duck_rect);
    sfRenderWindow_drawSprite(game_window->game_window, dk->duck,NULL);
    hud_draw(game_window, gun, parameters);
    hud_score(game_window, gun);
    game_window->hp = 5;
    game_window->score = 0;
    choose_music(game_window, parameters);
}

int game_loop(struct game_window *game, struct duck *first_duck,
              struct gun *gun, struct parameters *parameters)
{
    game_create(game);
    game_start(game, first_duck, gun, parameters);
    sfRenderWindow_setMouseCursorVisible(game->game_window, sfFalse);
    sfRenderWindow_setFramerateLimit(game->game_window, 90);
    while (sfRenderWindow_isOpen(game->game_window)) {
        sfMusic_setLoop(game->music, sfTrue);
        cursor_handler(game, gun, first_duck);
        analyse_events(game, first_duck, gun, parameters);
        clock_manager(game, first_duck, gun);
        duck_out_of_screen(game,first_duck, parameters);
        check_score(&game->score, &game->hp, game);
        if (game->game_seconds >= 0.1)
            sfClock_restart(game->game_clock);
        duck_animate_loop(game, first_duck);
        draw_hud(game, gun);
        sfRenderWindow_display(game->game_window);
    }
    sfRenderWindow_destroy(game->game_window);
    return (0);
}
