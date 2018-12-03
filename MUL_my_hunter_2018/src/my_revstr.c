/*
** EPITECH PROJECT, 2018
** my rev str
** File description:
** reverses a string
*/

#include <stdio.h>
#include <unistd.h>
#include "include/my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i = i + 1;
    return (i);
}

char *my_revstr(char *str)
{
    int c = 0;
    int counter = my_strlen(str);
    int n = counter / 2;
    int i = 0;

    while (i < n) {
        c = str[i];
        str[i] = str[counter - 1];
        str[counter - 1] = c;
        i = i + 1;
        counter = counter - 1;
    }
    return (str);
}
