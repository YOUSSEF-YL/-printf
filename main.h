#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>


int _printf(const char *format, ...);

int ft_octal(unsigned int n);
int ft_binary(unsigned int n);
int	ft_putnbr(long int n);
int	ft_putchar(char c);
int	ft_putstr(char *str, int cheack);
int	ft_unsignedint(unsigned int n);
int	ft_hexadecimal(unsigned int n, char *base);
int	ft_adresse(long int n, char *base);

#endif
