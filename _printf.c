#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>


void handle_format_specifier(const char *format, unsigned int *i, va_list args,
							print_t *print_arr, unsigned int *count);

/**
 * _printf - Produces output according to a format
 * @format: A string containing the characters and the specifiers
 * @...: The arguments to be printed
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	unsigned int i = 0, count = 0;

	print_t print_arr[] = {
		{"c", asset_print_char},
		{"s", asset_print_string},
		{"d", asset_print_int},
		{"i", asset_print_int},
		{"b", asset_print_binary},
		{"u", asset_print_unsigned},
		{"o", asset_print_octal},
		{"x", asset_print_hex},
		{"X", asset_print_hex_upper},
		{"p", asset_print_adress},
		{"r", asset_print_reverse},
		{NULL, NULL},
	};

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			handle_format_specifier(format, &i, args, print_arr, &count);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}

	va_end(args);
	return (count);
}

/**
 * handle_format_specifier - Handles the format specifier part of the _printf
 * @format: The format string
 * @i: Pointer to the current position in format string
 * @args: The list of arguments
 * @print_arr: Array of specifiers and corresponding functions
 * @count: Pointer to the count of characters printed
 */

void handle_format_specifier(const char *format, unsigned int *i, va_list args,
							 print_t *print_arr, unsigned int *count)
{
	(*i)++;
	if (format[*i] == '%')
	{
		write(1, &format[*i], 1);
		(*count)++;
	}
	else
	{
		unsigned int j = 0;

		while (print_arr[j].specifier)
		{
			if (format[*i] == *print_arr[j].specifier)
			{
				*count += print_arr[j].f(args);
				break;
			}
			j++;
		}
	}
}
