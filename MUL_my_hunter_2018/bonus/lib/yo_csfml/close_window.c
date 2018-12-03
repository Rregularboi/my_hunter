/*
** EPITECH PROJECT, 2018
** CSFML
** File description:
** close window
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ycsfml.h"

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}
