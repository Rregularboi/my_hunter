/*
** EPITECH PROJECT, 2018
** flags_2.c
** File description:
** second part of the flags
*/

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "include/my.h"

void transformator(int nb)
{
    char *str = malloc(sizeof(char) * 25);
    char base[] = "01234567";
    int a = 0;

    for (int i = 0 ; nb != 0 ; i = i + 1) {
        str[i] = base[nb % my_strlen(base)];
        nb = nb / my_strlen(base);
    }
    str = my_revstr(str);
    str[25] = '\0';
    a = my_getnbr(str);
    if (a <= 9)
        my_putstr("00");
    if (a >= 10 && a <= 99)
        my_putchar('0');
    my_put_nbr(a);
}

void capital_flag(va_list *list)
{
    char *string = va_arg(*list, char*);
    int nb_to_print;
    int digits = 1;

    for (int i = 0; string[i] != '\0' ; i = i + 1) {
        if (string[i] <= 31 || string[i] >= 127) {
            my_putchar(92);
            transformator((int)string[i]);
        }
        else
            my_putchar(string[i]);
    }
}

int flag_six(const char *string, va_list *list, int counter)
{
    if (string[counter+1] == 'S')
        capital_flag(list);
    return (0);
}

int flag_caller(const char *string, va_list *list, int counter)
{
    flag_one(string, list, counter);
    flag_two(string, list, counter);
    flag_three(string, list, counter);
    flag_four(string, list, counter);
    flag_five(string, list, counter);
    flag_six(string, list, counter);
    return (counter+1);
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
