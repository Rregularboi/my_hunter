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


int   my_strcounter(char const *str)
{
    int i = 0;

    for(i = 0;str[i] != '\0';i = i + 1) {
    }
    return (i);
}


char *my_strcop(char *dest, char *src, int offset, int n)
{
    int i = 0;
    int destcounter = my_strcounter(dest);
    int srccounter = my_strcounter(src);

    while(src[i+offset] != '\n' && i < n) {
        dest[i] = src[i+offset];
        i = i + 1;
    }
    dest[i] = '\0';
    return(dest);
}

void choose_bg_two(struct game_window *game_window,
                   struct parameters *parameters)
{
    if (parameters->background_nb == 6)
        game_window->game_texture = sfTexture_createFromFile
            ("bonus/sprites/bg6.png", NULL);
    if (parameters->background_nb == 7) {
        game_window->game_texture = sfTexture_createFromFile
            ("bonus/sprites/bg7.png", NULL);
    }
}

void choose_bg(struct game_window *game_window,
               struct parameters *parameters)
{
    if (parameters->background_nb == 0)
        game_window->game_texture = sfTexture_createFromFile
            ("bonus/sprites/bg", NULL);
    if (parameters->background_nb == 1)
        game_window->game_texture = sfTexture_createFromFile
            ("bonus/sprites/bg2.png", NULL);
    if (parameters->background_nb == 2)
        game_window->game_texture = sfTexture_createFromFile
            ("bonus/sprites/bg3.png", NULL);
    if (parameters->background_nb == 3)
        game_window->game_texture = sfTexture_createFromFile
            ("bonus/sprites/bg4.png", NULL);
    if (parameters->background_nb == 4)
        game_window->game_texture = sfTexture_createFromFile
            ("bonus/sprites/bg5.png", NULL);
    if (parameters->background_nb == 5)
        game_window->game_texture = sfTexture_createFromFile
            ("bonus/sprites/bg6.png", NULL);
    choose_bg_two(game_window, parameters);
}

void game_over(struct game_window *game_window,
               struct parameters *parameters)
{
    my_putstr("   _____                         ____                 \n");
    my_putstr("  / ____|                       / __ \\                \n");
    my_putstr(" | |  __  __ _ _ __ ___   ___  | |  | |_   _____ _ __ \n");
    my_putstr(" | | |_ |/ _\\` | '_ \\` _ \\ / _ \\ | |"
              "| \\ \\ / / _ \\ '__|\n");
    my_putstr(" | |__| | (_| | | | | | |  __/ | |__| |\\ V /  __/ |   \n");
    my_putstr("  \\_____|\\__,_|_| |_| |_|\\___|  \\____/  \\_/ \\___|_|   \n");
    my_putstr("                                                      \n");
    my_putstr("                                                      \n");
    my_printf("Your score is : %d\nHigh score is : %d", game_window->score,
              parameters->hiscore);

}

int check_nbrs(struct parameters *parameters, char **argv, int argc)
{
    char tmp[2];

    my_strcop(tmp, argv[1], 0, 1);
    parameters->music_nb = my_getnbr(tmp);
    my_strcop(tmp, argv[1], 1, 1);
    parameters->background_nb = my_getnbr(tmp);
    my_strcop(tmp, argv[1], 2, 1);
    parameters->cursor_nb = my_getnbr(tmp);
    return (2);
}
