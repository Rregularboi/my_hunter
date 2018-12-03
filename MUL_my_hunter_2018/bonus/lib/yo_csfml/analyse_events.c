/*
** EPITECH PROJECT, 2018
** CSFML
** File description:
** sf render window
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ycsfml.h"

void analyse_events(sfRenderWindow *window, sfEvent event)
{
    while(sfRenderWindow_pollEvent(window,&event)) {
        if (event.type == sfEvtMouseLeft)
            printf("left\n");
        if (event.type == sfEvtMouseEntered)
            printf("entered\n");
        if (event.type == sfEvtClosed) {
            close_window(window);
            printf("window closed\n");
        }
        if (event.type == sfEvtMouseButtonPressed) {
            printf("Mouse x=%d y=%d\n",
                   sfMouse_getPositionRenderWindow(window).x,
                   sfMouse_getPositionRenderWindow(window).y);
        }
    }
}
