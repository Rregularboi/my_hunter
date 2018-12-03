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

void fetch_stats(struct parameters *parameters)
{
    int fd = 0;
    char buffer[100];
    char tmp_buf[12];
    int tmp = 0;
    int offset = 0;

    fd = open("bonus/sprites/.stats", O_RDWR, O_CREAT);
    fd = read(fd, buffer, 100);
    parameters->hiscore = my_getnbr(buffer);
    close(fd);
}

int cmp_str(char *str1, char *str2)
{
    int i = my_strlen(str1);
    int x = my_strlen(str2);

    if (i != x )
        return (-1);
    for (int z = 0;str1[z] != '\0' && str2[z] != '\0';z++) {
        if (str1[z] != str2[z])
            return (-1);
    }
    return (1);
}

int check_params(int argc, char **argv,
                 struct parameters *parameters)
{
    if (argc == 1) {
        parameters->background_nb = 0;
        parameters->cursor_nb = 0;
        parameters->music_nb = 0;
        return (2);
    }
    if (argc == 2 && cmp_str("-h", argv[1]) == 1) {
        disp_help();
        return (0);
    }
    else
        return (check_nbrs(parameters, argv, argc));
}
