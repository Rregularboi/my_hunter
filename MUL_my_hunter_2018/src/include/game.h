/*
** EPITECH PROJECT, 2018
** header
** File description:
** for the game
*/

#include "ycsfml.h"

#ifndef GAME_H
#define GAME_H

void move_sprite(sfSprite* sprite, float x, float y);
void hud_score(struct game_window *game_window, struct gun *gun);

#endif /*GAME_H*/
