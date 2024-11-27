#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * asset_print_char - Handles character and string specifiers
 * @args: Argument list
 *
 * Return: Number of characters printed
 */
int asset_print_char(va_list args)
{
	char c = (char)va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

/**
 * asset_print_string - Handles string specifier (s)
 * @args: Argument list
 *
 * Return: Number of characters printed
 */

int asset_print_string(va_list args)
{
	int count = 0;
	char *str = va_arg(args, char *);
	char *null_str = "(null)";

	if (str == NULL)
		str = null_str;

	while (str[count])
	{
		write(1, &str[count], 1);
		count++;
	}

	return (count);
}

/**
 * asset_print_int - Handles integer specifiers (d and i)
 * @args: Argument list
 *
 * Return: Number of characters printed
 */
int asset_print_int(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	char buffer[20];
	char *ptr = &buffer[19];
	unsigned int num;
	char *start_ptr;

	*ptr = '\0';
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		num = (unsigned int)(-n);
	}
	else
	{
		num = (unsigned int)n;
	}

	do {
		*--ptr = (num % 10) + '0';
		num /= 10;
	} while (num != 0);

	start_ptr = ptr;

	while (*start_ptr)
	{
		write(1, start_ptr, 1);
		start_ptr++;
		count++;
	}

	return (count);
}

/**
 * asset_print_binary - Handles binary specifier (b)
 * @args: Argument list
 *
 * Return: Number of characters printed
 */
int asset_print_binary(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;
	char buffer[33];
	char *ptr = &buffer[32];

	*ptr = '\0';
	do {
		*--ptr = (n % 2) + '0';
		n /= 2;
	} while (n != 0);

	while (*ptr)
	{
		write(1, ptr++, 1);
		count++;
	}

	return (count);
}

/**
 * asset_print_unsigned - Handles unsigned integer specifier (u)
 * @args: Argument list
 *
 * Return: Number of characters printed
 */
int asset_print_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;
	char buffer[20];
	char *ptr = &buffer[19];
	char *start_ptr;

	*ptr = '\0';
	do {
		*--ptr = (n % 10) + '0';
		n /= 10;
	} while (n != 0);

	start_ptr = ptr;
	while (*start_ptr)
	{
		write(1, start_ptr, 1);
		start_ptr++;
		count++;
	}

	return (count);
}
