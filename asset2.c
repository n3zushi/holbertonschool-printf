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
 * asset_print_adress - Handles address specifier (p)
 * @args: Argument list
 * Description: This function prints the address of a pointer
 * Return: Number of characters printed
 */

int asset_print_adress(va_list args)
{
	unsigned long int n = va_arg(args, unsigned long int);
	int count = 0;
	char buffer[20];
	char *ptr = &buffer[19];

	*ptr = '\0';
	do {
		unsigned long int digit = n % 16;

		if (digit < 10)
			*--ptr = digit + '0';
		else
			*--ptr = digit + 'a' - 10;
		n /= 16;
	} while (n != 0);

	write(1, "0x", 2);
	count += 2;
	while (*ptr)
	{
		write(1, ptr++, 1);
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
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;
	char buffer[20];
	char *ptr = &buffer[19];

	*ptr = '\0';
	do {
		*--ptr = (n % 10) + '0';
		n /= 10;
	} while (n != 0);

	while (*ptr)
	{
		write(1, ptr++, 1);
		count++;
	}
	return (count);
}