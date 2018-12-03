/*
** EPITECH PROJECT, 2018
** my print f
** File description:
** printf copycat
*/

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "include/my.h"

void my_printf(const char *str, ...)
{
    va_list ap;

    va_start(ap, str);
    for (int i = 0 ; str[i] != '\0' ; i = i + 1) {
        if (str[i] == '%')
            i = flag_caller(str, &ap, i);
        else
            my_putchar(str[i]);
    }
    va_end(ap);
}
