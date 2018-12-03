/*
** EPITECH PROJECT, 2018
** my get nbr
** File description:
** gets number from string
*/

#include <stdio.h>
#include <unistd.h>

int my_putchar(char c);
int my_put_nbr(int nb);

int my_getnbr(char const *str)
{
    int i = 0;
    int digits_found = 0;
    int is_number_neg = 0;
    int number_has_been_found = 0;

    while (str[i] != '\0') {
        if (str[i] == '-' && str[i+1] >= '0' && str[i+1] <= '9')
            is_number_neg = 1;
        if (str[i] > '/' && str[i] < ':' && number_has_been_found == 0)
            digits_found = (digits_found * 10) + str[i] - 48;
        else if (number_has_been_found == 1)
            return (digits_found);
        if (digits_found != 0 && !(str[i] > '/' && str[i] < ':'))
            number_has_been_found = 1;
        i++;
    }
    if (is_number_neg == 1)
        digits_found = digits_found * -1;
    return (digits_found);
}
