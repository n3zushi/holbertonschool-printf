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
	if (write(1, "%", 1) == -1)
		return (-1);
	return (1);
}

/**
 * asset_print_rot - Handles rot13 specifier (R)
 * @args: Argument list
 * Description: This function prints a string in rot13
 * Return: Number of characters printed
 */

int asset_print_rot(va_list args)
{
	int count = 0;
	int i;
	char *str = va_arg(args, char *);
	char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *rot13 = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *null_str = "(null)";

	if (str == NULL)
		str = null_str;

	for (i = 0; str[i]; i++)
	{
		int j;
		char c = str[i];
		int found = 0;

		for (j = 0; j < 52; j++)
		{
			if (c == alpha[j])
			{
				if (write(1, &rot13[j], 1) == -1)
					return (-1);
				count++;
				found = 1;
				break;
			}
		}
		if (!found)
		{
			if (write(1, &c, 1) == -1)
				return (-1);
			count++;
		}
	}

	return (count);
}
