/*
** EPITECH PROJECT, 2018
** flags_1
** File description:
** functions for each flags
*/

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "include/my.h"

int flag_one(const char *string, va_list *list, int counter)
{
    if (string[counter+1] == 'c')
        my_putchar(va_arg(*list, int));
    if (string[counter+1] == 'd' || string[counter+1] == 'i')
        my_put_nbr(va_arg(*list, int));
    return (0);
}

int flag_two(const char *string, va_list *list, int counter)
{
    if (string[counter+1] == 's')
        my_putstr(va_arg(*list, char*));
    if (string[counter+1] == '%')
        my_putchar('%');
    return (0);
}

int flag_three(const char *string, va_list *list, int counter)
{
    if (string[counter+1] == 'u')
        my_putbase(va_arg(*list, unsigned int),"0123456789");
    if (string[counter+1] == 'o')
        my_putbase(va_arg(*list, unsigned int),"01234567");
    return (0);
}

int flag_four(const char *string, va_list *list, int counter)
{
    if (string[counter+1] == 'x')
        my_putbase(va_arg(*list, unsigned int),"0123456789abcdef");
    if (string[counter+1] == 'X')
        my_putbase(va_arg(*list, unsigned int),"0123456789ABCDEF");
    return (0);
}

int flag_five(const char *string, va_list *list, int counter)
{
    if (string[counter+1] == 'p') {
        my_putstr("0x");
        my_long_putbase((long)va_arg(*list,void*),"0123456789abcdef");
    }
    if (string[counter+1] == 'b')
        my_putbase(va_arg(*list, unsigned int), "01");
}
