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

void game_create(struct game_window *game_window)
{
    game_window->game_window = my_window("Yoan's Hunter",1280,800);
    game_window->game_background = sfSprite_create();
    game_window->game_clock = sfClock_create();
    game_window->duck_hunt_font = sfFont_createFromFile
        ("bonus/sprites/duckhunt.ttf");
    game_window->lives = sfText_create();
    sfText_setString(game_window->lives, "5");
    sfText_setFont(game_window->lives, game_window->duck_hunt_font);
    sfText_setCharacterSize(game_window->lives, 40);
    sfText_setOrigin(game_window->lives, (sfVector2f){0,0});
    sfRenderWindow_drawText(game_window->game_window, game_window->lives, NULL);
}
