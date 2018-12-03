/*
** EPITECH PROJECT, 2018
** my_window
** File description:
** makes a new window
*/

#include <SFML/Graphics/RenderWindow.h>
#include <unistd.h>
#include "ycsfml.h"

sfRenderWindow *my_window(char *window_name,
                          unsigned int width,
                          unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, window_name,
                                   sfDefaultStyle, NULL);
    return window;
}
