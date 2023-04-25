#include "main.h"

/**
* adresse - adr
* @arg : list arg
* Return: c
*/

int	adresse(va_list arg)
{
	int c;
	unsigned long int adr;

	c = 0;
	adr = va_arg(arg, unsigned long int);
	if (adr)
	{
		c += ft_putstr("0x", 0) + ft_adresse(adr, "0123456789abcdef");
	}
	else
		c += ft_putstr("(nil)", 0);
	return (c);
}

/**
 * ft_format - function format
 * @arg : list arguments
 * @format : format
 * Return: c
 */

static int	ft_format(va_list arg, char format)
{
	int	c;

	c = 0;
	if (format == 'c')
		c += ft_putchar(va_arg(arg, int));
	else if (format == '%')
		c += ft_putchar('%');
	else if (format == 'u')
		c += ft_unsignedint(va_arg(arg, int));
	else if (format == 'x')
		c += ft_hexadecimal(va_arg(arg, int), "0123456789abcdef");
	else if (format == 'X')
		c += ft_hexadecimal(va_arg(arg, int), "0123456789ABCDEF");
	else if (format == 'S')
		c += ft_putstr(va_arg(arg, char *), 1);
	else if (format == 'p')
		c += adresse(arg);
	else if (format == 'b')
		c += ft_binary(va_arg(arg, unsigned int));
	else if (format == 'r')
		c += rev_str(va_arg(arg, char *));
	else if (format == 'o')
		c += ft_octal(va_arg(arg, unsigned int));
	else if (format == 'R')
		c += rot13(va_arg(arg, char *));
	else if (format == 'd' || format == 'i')
		c += ft_putnbr(va_arg(arg, int));
	else if (format == 's')
		c += ft_putstr(va_arg(arg, char *), 0);
	else
	{
		c += ft_putchar('%');
		c += ft_putchar(format);
	}
	return (c);
}

/**
 * _printf - printf
 * @format : last argument in varidic function
 * Return: c
 */

int	_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		c;

	i = 0;
	c = 0;
	va_start(arg, format);
	if (!format)
		return (-1);
	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && format[2] == '\0')
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			c += ft_format(arg, format[i]);
		}
		else
			c += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (c);
}
