#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdarg.h>


int _printf(const char *format, ...);

int	ft_putstr(char *str, int cheack);
int	ft_putnbr(long int n);
int	ft_unsignedint(unsigned int n);
int	ft_hexadecimal(unsigned int n, char *base);
int	ft_adresse(unsigned long int n, char *base);
int ft_octal(unsigned int n);
int	ft_putchar(char c);
int ft_binary(unsigned int n);
int rev_str(char *str);
int rot13(char *str);

#endif

