/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** param 2
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System/Clock.h>
#include <SFML/Config.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "include/game.h"
#include "include/ycsfml.h"
#include "include/my.h"

void disp_musics(void)
{
    my_putstr("0 : Duck Hunt Medley\n");
    my_putstr("1 : Starfox NES Theme\n");
    my_putstr("2 : Sonic Mania OST: Studiopolis Zone Act 1\n");
    my_putstr("3 : Cornered - Phoenix Wright\n");
}

void disp_backgrounds(void)
{
    my_putstr("0 : Duck Hunt 1\n");
    my_putstr("1 : Duck Hunt 2\n");
    my_putstr("2 : Duck Hunt 3\n");
    my_putstr("3 : Super Mario World\n");
    my_putstr("4 : Green Hill\n5 : Battlefied\n6 : Final Destination\n");
}

void disp_cursors(void)
{
    my_putstr("0 : White cursor\n");
    my_putstr("1 : Black cursor\n");
    my_putstr("2 : Yellow cursor\n");
    my_putstr("3 : Purple cursor\n");
    my_putstr("4 : Kirby cursor\n");
    my_putstr("5 : Innovation cursor\n");
}

void disp_help(void)
{
    my_putstr("   __  ___       __ __          __\n");
    my_putstr("  /  |/  /_ __  / // /_ _____  / /____ ____\n");
    my_putstr(" / /|_/ / // / / _  / // / _ \\/ __/ -_) __/\n");
    my_putstr("/_/  /_/\\_, / /_//_/\\_,_/_//_/\\__/\\__/_/\n");
    my_putstr("       /___/\n");
    my_putstr("------------------------------------\n");
    my_putstr("Use Leftclick to shoot ducks\n");
    my_putstr("Missing makes you loose points :p\n");
    my_putstr("Use Escape or close button to quit\n");
    my_putstr("Use ./my_hunter with 3 numbers to change\n");
    my_putstr("The music | The background | The cursor\n");
    my_putstr("Example : ./my_hunter 241 \n");
    my_putstr("--------------Your musics-----------\n");
    disp_musics();
    my_putstr("------------Your backgrounds--------\n");
    disp_backgrounds();
    my_putstr("-------------Your cursors-----------\n");
    disp_cursors();
}
