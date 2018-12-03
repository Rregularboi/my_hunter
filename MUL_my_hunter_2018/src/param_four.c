/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** param four
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


void create_sounds(struct game_window *game_window)
{
    game_window->duck = sfMusic_createFromFile
        ("bonus/sprites/duck.ogg");
    game_window->duck_dies = sfMusic_createFromFile
        ("bonus/sprites/duck_dies.ogg");
    game_window->shoot = sfMusic_createFromFile
        ("bonus/sprites/poum.ogg");
    game_window->headshot = sfMusic_createFromFile
        ("bonus/sprites/headshot.ogg");
}

void choose_music(struct game_window *game_window,
                  struct parameters *parameters)
{
    if (parameters->music_nb == 0)
        game_window->music = sfMusic_createFromFile
            ("bonus/sprites/duckhunt.ogg");
    if (parameters->music_nb == 1)
        game_window->music = sfMusic_createFromFile("bonus/sprites/fox.ogg");
    if (parameters->music_nb == 2)
        game_window->music = sfMusic_createFromFile("bonus/sprites/sonic.ogg");
    if (parameters->music_nb == 3)
        game_window->music = sfMusic_createFromFile
            ("bonus/sprites/phoenix.ogg");
    if (parameters->music_nb == 7)
        game_window->music = sfMusic_createFromFile
            ("bonus/sprites/koba.ogg");
    create_sounds(game_window);
    sfMusic_play(game_window->music);
}

void choose_cursor(struct game_window *game_window,
                   struct parameters *parameters)
{
    if (parameters->cursor_nb == 0)
        game_window->game_texture = sfTexture_createFromFile
            ("bonus/sprites/cursors/cursor1.png", NULL);
    if (parameters->cursor_nb == 1)
        game_window->game_texture = sfTexture_createFromFile
            ("bonus/sprites/cursors/cursor2.png", NULL);
    if (parameters->cursor_nb == 2)
        game_window->game_texture = sfTexture_createFromFile
            ("bonus/sprites/cursors/cursor3.png", NULL);
    if (parameters->cursor_nb == 3)
        game_window->game_texture = sfTexture_createFromFile
            ("bonus/sprites/cursors/cursor4.png", NULL);
    if (parameters->cursor_nb == 4)
        game_window->game_texture = sfTexture_createFromFile
            ("bonus/sprites/cursors/cursor5.png", NULL);
    if (parameters->cursor_nb == 5)
        game_window->game_texture = sfTexture_createFromFile
            ("bonus/sprites/cursors/cursor6.png", NULL);
}

void check_unlocked_two(struct parameters *parameters)
{
    if (parameters->total_points >= 500 && parameters->total_points <= 999)
        parameters->backgrounds = 1;
    if (parameters->total_points >= 1000 && parameters->total_points <= 1499)
        parameters->backgrounds = 2;
    if (parameters->total_points >= 1500 && parameters->total_points <= 2499)
        parameters->backgrounds = 3;
    if (parameters->total_points >= 2500 && parameters->total_points <= 4999)
        parameters->backgrounds = 4;
    if (parameters->total_points >= 5000)
        parameters->backgrounds = 6;
}

void check_unlocked(struct parameters *parameters)
{
    if (parameters->ducks_hit < 29)
        parameters->cursors = 0;
    if (parameters->ducks_hit >= 30 && parameters->ducks_hit <= 59)
        parameters->cursors = 1;
    if (parameters->ducks_hit >= 60 && parameters->ducks_hit <= 99)
        parameters->cursors = 2;
    if (parameters->ducks_hit >= 100)
        parameters->cursors = 3;
    if (parameters->games_played < 4)
        parameters->games_played = 0;
    if (parameters->games_played >= 5 && parameters->games_played <= 14)
        parameters->games_played = 1;
    if (parameters->games_played >= 15 && parameters->games_played <= 29)
        parameters->games_played = 2;
    if (parameters->games_played >= 30)
        parameters->games_played = 3;
    if (parameters->total_points < 499)
        parameters->backgrounds = 0;
    check_unlocked_two(parameters);
}
