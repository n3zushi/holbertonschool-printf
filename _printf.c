#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

void process_format(const char *format, unsigned int *i,
va_list args, int *count);
int find_specifier_handler(const char *format, unsigned int *i,
va_list args, int *count);

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
	unsigned int i = 0;
	int count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				va_end(args);
				return (-1);
			}
			process_format(format, &i, args, &count);
			if (count == -1)
			{
				va_end(args);
				return (-1);
			}
		}
		else
		{
			if (write(1, &format[i], 1) == -1)
			{
				va_end(args);
				return (-1);
			}
			count++;
		}
		i++;
	}

	va_end(args);
	return (count);
}

/**
 * process_format - Handles the processing of format specifiers
 * @format: The format string
 * @i: Pointer to the current position in format string
 * @args: The list of arguments
 * @count: Pointer to the count of characters printed
 */
void process_format(const char *format, unsigned int *i,
va_list args, int *count)
{
	(*i)++;
	if (find_specifier_handler(format, i, args, count) == -1)
	{
		*count = -1;
		return;
	}
}

/**
 * find_specifier_handler - Finds and executes the correct specifier handler
 * @format: The format string
 * @i: Pointer to the current position in format string
 * @args: The list of arguments
 * @count: Pointer to the count of characters printed
 *
 * Return: 0 if successful, -1 if an error occurs
 */
int find_specifier_handler(const char *format, unsigned int *i,
va_list args, int *count)
{
	unsigned int j;
	int found = 0, result;

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
		{"p", asset_print_address},
		{"r", asset_print_reverse},
		{"%", asset_print_percent},
		{NULL, NULL},
	};

	for (j = 0; print_arr[j].specifier != NULL; j++)
	{
		if (format[*i] == *(print_arr[j].specifier))
		{
			result = print_arr[j].f(args);
			if (result == -1)
				return (-1);
			*count += result;
			found = 1;
			break;
		}
	}

	if (!found)
	{
		if (write(1, "%", 1) == -1 || write(1, &format[*i], 1) == -1)
			return (-1);
		*count += 2;
	}

	return (0);
}
