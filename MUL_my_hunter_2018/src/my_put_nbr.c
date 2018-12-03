/*
** EPITECH PROJECT, 2018
** my put nbr
** File description:
** prints a number
*/

#include <stdio.h>
#include <unistd.h>
#include "include/my.h"

int my_put_nbr(int nb)
{
    int digits = 1;
    int print = 0;

    if(nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    while (nb/digits >= 10)
        digits = digits * 10;
    while (digits >= 1) {
        print = nb / digits;
        print = print + 48;
        my_putchar(print);
        nb = nb % digits;
        digits = digits / 10;
    }
}
