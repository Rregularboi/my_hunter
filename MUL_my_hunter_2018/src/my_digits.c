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

long long my_digits(int nb)
{
    long long i = 1;
    int z = nb;

    while (z != 0) {
        z /= 10;
        i++;
    }
    return (i);
}
