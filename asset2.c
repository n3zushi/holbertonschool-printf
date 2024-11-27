#include "main.h"

/**
 * asset_print_octal - Handles octal specifier (o)
 * @args: Argument list
 *
 * Return: Number of characters printed
 */
int asset_print_octal(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;
	char buffer[20];
	char *ptr = &buffer[19];

	*ptr = '\0';
	do {
		*--ptr = (n % 8) + '0';
		n /= 8;
	} while (n != 0);

	while (*ptr)
	{
		write(1, ptr++, 1);
		count++;
	}

	return (count);
}

/**
 * asset_print_hex - Handles hexadecimal specifiers (x and X)
 * @args: Argument list
 *
 * Return: Number of characters printed
 */

int asset_print_hex(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;
	char buffer[20];
	char *ptr = &buffer[19];

	*ptr = '\0';

	do {
		unsigned int digit = n % 16;

		if (digit < 10)
			*--ptr = digit + '0';
		else
			*--ptr = digit + 'a' - 10;
		n /= 16;
	} while (n != 0);

	while (*ptr)
	{
		write(1, ptr++, 1);
		count++;
	}

	return (count);
}

/**
 * asset_print_hex_upper - Handles uppercase hexadecimal specifier (X)
 * @args: Argument list
 * Description: This function prints an uppercase hexadecimal number
 * Return: Number of characters printed
 */

int asset_print_hex_upper(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;
	char buffer[20];
	char *ptr = &buffer[19];

	*ptr = '\0';
	do {
		unsigned int digit = n % 16;

		if (digit < 10)
			*--ptr = digit + '0';
		else
			*--ptr = digit + 'A' - 10;
		n /= 16;
	} while (n != 0);

	while (*ptr)
	{
		write(1, ptr++, 1);
		count++;
	}

	return (count);
}

/**
 * asset_print_address - Handles address specifier (p)
 * @args: Argument list
 * Description: This function prints the address of a pointer
 * Return: Number of characters printed
 */

int asset_print_address(va_list args)
{
	void *addr = va_arg(args, void *);
	unsigned long int n = (unsigned long int)addr;
	int count = 0;
	char buffer[20];
	char *ptr = &buffer[19];
	char *start_ptr;

	*ptr = '\0';
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}

	do {
		unsigned long int digit = n % 16;

		if (digit < 10)
			*--ptr = digit + '0';
		else
			*--ptr = digit - 10 + 'a';
		n /= 16;
	} while (n != 0);

	write(1, "0x", 2);
	count += 2;

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
 * asset_print_reverse - Prints an unsigned integer in reverse
 * @args: Argument list
 * Description: This function prints an unsigned integer in reverse
 * Return: Number of characters printed
 */

int asset_print_reverse(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;
	int len = 0;

	if (!str)
		str = "(null)";

	while (str[len])
		len++;

	for (len = len - 1; len >= 0; len--)
	{
		write(1, &str[len], 1);
		count++;
	}
	return (count);
}
