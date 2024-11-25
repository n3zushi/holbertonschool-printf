#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>


/**
 * print_number - prints a number
 * @n: number to print
 * Return: number of characters printed
 */

int print_number(int n)
{
	int count = 0;
	char buffer[12];
	char *ptr = buffer + sizeof(buffer) - 1;
	unsigned int num = n;

	*ptr = '\0';
	if (n < 0)
		num = -n;

	do {
		*--ptr = (num % 10) + '0';
		num /= 10;
		count++;
	} while (num);

	if (n < 0)
	{
		*--ptr = '-';
		count++;
	}

	count += write(1, ptr, buffer + sizeof(buffer) - 1 - ptr);
	return (count);
}

/**
 * _printf - prints anything
 * @format: list of types of arguments passed to the function
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	char *str;

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				count += write(1, &(char){(char)va_arg(args, int)}, 1);
			else if (format[i] == 's')
			{
				str = va_arg(args, char *);
				if (!str)
					str = "(null)";
				while (*str)
					count += write(1, str++, 1);
			}
			else if (format[i] == 'd' || format[i] == 'i')
				count += print_number(va_arg(args, int));
			else if (format[i] == '%')
				count += write(1, "%", 1);
			else
			{
				count += write(1, "%", 1);
				count += write(1, &format[i], 1);
			}
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
