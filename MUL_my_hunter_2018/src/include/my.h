/*
** EPITECH PROJECT, 2018
** my h header
** File description:
** prototypes all libmy functions
*/

#include <stdarg.h>

#ifndef MY_H_
    #define MY_H_

int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_isneg(int n);
int my_is_prime(int nb);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putrepeat(char c,int n);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *tab, int size);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char *src, int *offset);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
int my_putbase(int nb, char *base);
long my_long_putbase(long nb, char *base);
void my_printf(const char *str, ...);
int flag_caller(const char *string, va_list *list, int counter);
int flag_one(const char *string, va_list *list, int counter);
int flag_two(const char *string, va_list *list, int counter);
int flag_three(const char *string, va_list *list, int counter);
int flag_four(const char *string, va_list *list, int counter);
int flag_five(const char *string, va_list *list, int counter);
char *my_putinstr(int nb, int digits);
long long my_digits(int nb);

#endif /*MY_H_*/
