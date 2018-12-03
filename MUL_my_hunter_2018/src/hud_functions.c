/*
** EPITECH PROJECT, 2018
** hud functions
** File description:
** file one
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

void draw_man(struct game_window *game, struct gun *gun, struct duck *duck)
{
    sfRenderWindow_clear(game->game_window, sfCyan);
    sfRenderWindow_drawSprite(game->game_window, game->game_background,NULL);
    sfRenderWindow_drawSprite(game->game_window,duck->duck,NULL);
    draw_hud(game, gun);
}

void cursor_handler(struct game_window *game_window,
                    struct gun *gun, struct duck *duck)
{
    draw_man(game_window, gun, duck);
    sfRenderWindow_drawSprite(game_window->game_window, gun->cursor, NULL);
    sfSprite_setPosition(gun->cursor, (sfVector2f){
            sfMouse_getPositionRenderWindow(game_window->game_window).x-32,
                sfMouse_getPositionRenderWindow(game_window->game_window).y-30});
    sfRenderWindow_display(game_window->game_window);
}

void hud_draw_two(struct game_window *game_window, struct gun *gun,
                  struct parameters *parameters)
{
    choose_cursor(game_window, parameters);
    sfSprite_setTexture(gun->cursor, game_window->game_texture, sfFalse);
}

void hud_draw(struct game_window *game_window, struct gun *gun,
              struct parameters *parameters)
{
    game_window->game_texture = sfTexture_createFromFile
        ("bonus/sprites/gun.png",NULL);
    sfSprite_setTexture(gun->gun_shoot, game_window->game_texture, sfFalse);
    sfSprite_setTextureRect(gun->gun_shoot, gun->gun_rect);
    sfRenderWindow_drawSprite(game_window->game_window, gun->gun_shoot, NULL);
    sfSprite_setPosition(gun->gun_shoot,(sfVector2f){625,710});
    game_window->game_texture = sfTexture_createFromFile
        ("bonus/sprites/coeur.png",NULL);
    sfSprite_setTexture(gun->heart_hud, game_window->game_texture, sfFalse);
    sfRenderWindow_drawSprite(game_window->game_window, gun->heart_hud, NULL);
    sfSprite_setPosition(gun->heart_hud, (sfVector2f){59,735});
    sfText_setPosition(game_window->lives, (sfVector2f){135,740});
    game_window->game_texture = sfTexture_createFromFile
        ("bonus/sprites/dead_ducks.png", NULL);
    sfSprite_setTexture(gun->score_hud, game_window->game_texture, sfFalse);
    sfSprite_setScale(gun->score_hud, (sfVector2f){2,2});
    sfRenderWindow_drawSprite(game_window->game_window, gun->score_hud, NULL);
    sfSprite_setPosition(gun->score_hud, (sfVector2f){1090, 728});
    sfRenderWindow_display(game_window->game_window);
    hud_draw_two(game_window, gun, parameters);
}

void hud_score(struct game_window *game_window, struct gun *gun)
{
    sfText_setFont(gun->score_text, game_window->duck_hunt_font);
    sfText_setString(gun->score_text, "0");
    sfText_setCharacterSize(gun->score_text, 40);
    sfText_setPosition(gun->score_text, (sfVector2f){1160,744});
    sfRenderWindow_drawText(game_window->game_window, gun->score_text, NULL);
}
