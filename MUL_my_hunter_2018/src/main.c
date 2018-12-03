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


void check_score(int *a, int *b, struct game_window *game_window)
{
    if (*a <= 0)
        *a = 0;
    if (*b <= 0) {
        *b = 0;
        sfRenderWindow_destroy(game_window->game_window);
    }
}

void draw_hud(struct game_window *game, struct gun *gun)
{
    sfText_setString(game->lives, my_putinstr(game->hp, my_digits(game->hp)));
    sfText_setString(gun->score_text, my_putinstr(game->score,
                                                  my_digits(game->score)));
    sfRenderWindow_drawText(game->game_window, game->lives, NULL);
    sfRenderWindow_drawSprite(game->game_window, gun->heart_hud, NULL);
    sfRenderWindow_drawSprite(game->game_window, gun->gun_shoot, NULL);
    sfRenderWindow_drawSprite(game->game_window, gun->score_hud, NULL);
    sfRenderWindow_drawText(game->game_window, gun->score_text, NULL);
}

void draw_all(struct game_window *game, struct gun *gun, struct duck *duck)
{
    sfRenderWindow_clear(game->game_window, sfCyan);
    sfRenderWindow_drawSprite(game->game_window, game->game_background,NULL);
    sfRenderWindow_drawSprite(game->game_window,duck->duck,NULL);
    draw_hud(game, gun);
    sfRenderWindow_display(game->game_window);
}

void duck_animate_loop(struct game_window *game, struct duck *duck)
{
    if (duck->duck_seconds >= 0.06) {
        sfRenderWindow_clear(game->game_window, sfCyan);
        sfRenderWindow_drawSprite(game->game_window,
                                  game->game_background,NULL);
        move_rect(&duck->duck_rect, 110, 330);
        sfSprite_setTextureRect(duck->duck, duck->duck_rect);
        move_sprite(duck->duck, duck->duck_speed, rando_cond
                    (duck->difficulty*-1, duck->difficulty, duck));
        sfRenderWindow_drawSprite(game->game_window,duck->duck,NULL);
        sfClock_restart(duck->duck_clock);
    }
}

int main(int argc, char **argv)
{
    struct duck first_duck = {sfSprite_create(),{0,0,110,110},
                              0,0,sfClock_create(),5,1};
    struct game_window game;
    struct parameters parameters;
    struct gun gun = {sfSprite_create(),{0,0,83,107},0,
                      sfClock_create(),0,sfSprite_create(),
                      sfSprite_create(), sfText_create(),sfSprite_create()};

    fetch_stats(&parameters);
    if (check_params(argc, argv, &parameters) == 0 ||
        check_params(argc, argv, &parameters) == -1 )
        return (0);
    parameters.games_played = parameters.games_played + 1;
    game_loop(&game, &first_duck, &gun, &parameters);
    high_score(&game, &parameters);
    game_over(&game, &parameters);
    clean_all(&game, &parameters, &first_duck, &gun);
    return (0);
}
