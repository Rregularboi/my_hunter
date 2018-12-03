/*
** EPITECH PROJECT, 2018
** my_long_putbase
** File description:
** prints a number in base (long)
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"

long my_long_putbase(long nb, char *base)
{
    char *str = malloc(sizeof(char) * 25);
    int i = 0;

    while (nb != 0) {
        str[i] = base[nb % my_strlen(base)];
        nb = nb / my_strlen(base);
        i = i + 1;
    }
    str = my_revstr(str);
    str[25] = '\0';
    my_putstr(str);
    return (0);
}
