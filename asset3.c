#include "main.h"

/**
 * asset_print_percent - Handles percent specifier (b)
 * @args: Argument list
 * Description: This function prints the percent sign
 * Return: Number of characters printed
 */

int asset_print_percent(va_list args)
{
	(void)args;
	_putchar('%');
	return (1);
}