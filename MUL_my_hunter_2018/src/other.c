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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "include/game.h"
#include "include/ycsfml.h"
#include "include/my.h"


void rando_sound(struct game_window *game_window)
{
    sfMusic_play(game_window->duck_dies);
    if (randomiser(1,10) == 1 || randomiser(1,10) == 2) {
        sfMusic_play(game_window->headshot);
        game_window->score = game_window->score + 25;
    }
}

void high_score(struct game_window *game_window,
                struct parameters *parameters)
{
    int fd = 0;

    if (game_window->score > parameters->hiscore) {
        parameters->hiscore = game_window->score;
        my_putstr("NEW HIGH-SCORE !\n");
        fd = open("bonus/sprites/.stats", O_RDWR, O_CREAT);
        write(fd, my_putinstr(game_window->score, my_digits(game_window->score))
              , my_digits(game_window->score));
    }
}

void clean_all(struct game_window *game_window, struct parameters *parameters,
               struct duck *duck, struct gun *gun)
{
    sfSprite_destroy(duck->duck);
    sfSprite_destroy(gun->gun_shoot);
    sfSprite_destroy(gun->heart_hud);
    sfSprite_destroy(gun->score_hud);
    sfText_destroy(gun->score_text);
    sfSprite_destroy(gun->cursor);
    sfSprite_destroy(game_window->game_background);
    sfTexture_destroy(game_window->game_texture);
    sfText_destroy(game_window->lives);
    sfMusic_destroy(game_window->music);
    sfMusic_destroy(game_window->duck);
    sfMusic_destroy(game_window->duck_dies);
    sfMusic_destroy(game_window->headshot);
    sfMusic_destroy(game_window->shoot);
}
