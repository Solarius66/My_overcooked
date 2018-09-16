/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** declaration file
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdarg.h>
#ifndef __INTERNAL_EPILIB_H__
#define __INTERNAL_EPILIB_H__

long long my_getnbr_long(char *);
int my_putstr(char *);
int my_puterr(char *);
int my_strlen(char *);
char *fusion_str(char *, char *);
int my_compare_str(char *, char *);
char **my_get_words(char *, char, int);
int clear_malloc(char *, int);
int count_words();
int my_putnbr(int);
int my_putnbr_err(int);
int my_putfloat(double);
int my_putfloat_err(double);
int length_nb(int);
char *my_itoa(int);
char *my_dtoa(double);
int my_printf(char *, ...);
char *my_malloc(int);
int create_chained(void *, int);
int destroy_chained(void *);
sfTexture **my_create_array(int);
int nmatch(char *, char *);

#endif
