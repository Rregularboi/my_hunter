/*
** EPITECH PROJECT, 2018
** yo csfml header
** File description:
** yo csfml header
*/

#ifndef YCSFML_H
#define YCSFML_H

void analyse_events(sfRenderWindow *window, sfEvent event);
void close_window(sfRenderWindow *window);
sfRenderWindow *my_window(char *window_name,
                          unsigned int width,
                          unsigned int height);
#endif /*YCSFML_H*/
