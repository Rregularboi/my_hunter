/*
** EPITECH PROJECT, 2018
** my put nbr
** File description:
** prints a number
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"

char *my_putinstr(int nb, int digits)
{
    int digi = 1;
    int print = 0;
    char *result = malloc(sizeof(char) * digits);
    int count = 0;

    if(nb < 0) {
        result[print] = '-';
        print = print + 1;
    }
    while (nb/digi >= 10)
        digi = digi * 10;
    while (digi >= 1) {
        print = nb / digi + 48;
        result[count] = print;
        nb = nb % digi;
        digi = digi / 10;
        count++;
    }
    result[digits-1] = '\0';
    return (result);
}
